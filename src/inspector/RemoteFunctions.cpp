//////////////////////////////////////////////////////////////////////////
// File: RemoteFunctions.cpp                                            //
// Date: 2010-07-01                                                     //
// Desc: Defines functions that are injected into a remote thread       //
//   in a process to run code or collect data that can only be          //
//   obtained from that remote process.                                 //
//   Note that functions to be injected MUST NOT make any calls to      //
//   code in this process.                                              //
//                                                                      //
//   Any methods in this project that, either directly or indirectly,   //
//   run code or allocate memory in the remote process will have the    //
//   marker <<REMOTE>> in their header comment.                         //
//////////////////////////////////////////////////////////////////////////

/********************************************************************
  Window Detective
  Copyright (C) 2010-2017 XTAL256

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
********************************************************************/

#define STRICT
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <malloc.h>
#include "RemoteFunctions.h"
#include "hook/Hook.h"
#include "hook/resource.h"


#define INJECT_PRIVELIDGE (PROCESS_CREATE_THREAD     | \
                           PROCESS_QUERY_INFORMATION | \
                           PROCESS_VM_OPERATION      | \
                           PROCESS_VM_READ           | \
                           PROCESS_VM_WRITE)

/*--------------------------------------------------------------------------+
| Injects a thread into the given process.                                  |
|                                                                           |
| func     - address of function to inject.                                 |
| funcSize - size in bytes of the function.                                 |
| data     - address of a user-defined structure to be passed to            |
|            the injected thread.                                           |
| dataSize - size in bytes of the structure.                                |
|                                                                           |
| The user-defined structure is also injected into the target process'      |
| address space. When the thread terminates, the structure is read back     |
| from the process.                                                         |
+--------------------------------------------------------------------------*/
DWORD InjectRemoteThread(DWORD processId,
                         LPTHREAD_START_ROUTINE func, DWORD funcSize,
                         LPVOID data, DWORD dataSize) {
    HANDLE hProcess = 0;        // Handle to the remote process
    HANDLE hRemoteThread = 0;   // Handle to the injected thread
    DWORD remoteThreadId = 0;   // ID of the injected thread
    SIZE_T bytesWritten = 0, bytesRead = 0;
    DWORD returnValue = 0;
    DWORD* remoteAddress = 0;
    void* remoteData = 0;

    if (funcSize == 0 || dataSize == 0) {
        returnValue = ERROR_INVALID_PARAMETER;
        goto cleanup;
    }

    // Total size of all memory copied into remote process
    const DWORD totalSize = funcSize + dataSize + 3;

    // Open the remote process so we can allocate some memory in it
    hProcess = OpenProcess(INJECT_PRIVELIDGE, FALSE, processId);
    if(hProcess == 0) {
        returnValue = GetLastError();
        goto cleanup;
    }

    // Allocate enough memory in the remote process's address space to hold the
    // binary image of our injection thread, and a copy of the data structure
    remoteAddress = (DWORD*)VirtualAllocEx(hProcess, 0, totalSize,
                        MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    if (!remoteAddress) {
        returnValue = GetLastError();
        goto cleanup;
    }

    // Write a copy of our injection thread into the remote process
    if (!WriteProcessMemory(hProcess, remoteAddress, func, funcSize, &bytesWritten)) {
        returnValue = GetLastError();
        goto cleanup;
    }

    // Write a copy of the data to the remote process.
    // This structure MUST start on a 32bit boundary
    remoteData = (void*)((BYTE*)remoteAddress + ((funcSize + 4) & ~ 3));
    if (!WriteProcessMemory(hProcess, remoteData, data, dataSize, &bytesWritten)) {
        returnValue = GetLastError();
        goto cleanup;
    }

    // Create the remote thread
    hRemoteThread = CreateRemoteThread(hProcess, NULL, 0,
                        (LPTHREAD_START_ROUTINE)remoteAddress,
                        remoteData, 0, &remoteThreadId);
    if (!hRemoteThread) {
        returnValue = GetLastError();
        goto cleanup;
    }

    // Wait for the thread to terminate
    WaitForSingleObject(hRemoteThread, INFINITE);

    // Read the user data structure back again
    if(!ReadProcessMemory(hProcess, remoteData, data, dataSize, &bytesRead)) {
        returnValue = GetLastError();
        goto cleanup;
    }

    // TODO: This doesn't seem to return 0. What is the correct value this should return?
    //GetExitCodeThread(hRemoteThread, &returnValue);
    returnValue = S_OK;

    cleanup:
    if (hRemoteThread) CloseHandle(hRemoteThread);
    if (remoteAddress) VirtualFreeEx(hProcess, remoteAddress, 0, MEM_RELEASE);
    if (hProcess) CloseHandle(hProcess);

    return returnValue;
}


/*--------------------------------------------------------------------------+
| This function is injected into a remote process and is responsible for    |
| calling the desired function in the hook dll.                             |
| Assumes that the hook dll is already loaded in the remote process         |
+--------------------------------------------------------------------------*/
#pragma check_stack(off)
#pragma optimize("", off)
static DWORD WINAPI RemoteFunctionDelegate(InjectionData* inj) {
    HMODULE dll = inj->fnGetModuleHandle(inj->moduleName);
    if (!dll) {
        inj->result = inj->fnGetLastError();
        // Not sure if the return value can be retrieved from the remote
        // thread, so just store it in the struct and return 0 here
        return 0;
    }

    // Get the address of the function to call
    RemoteProc func = (RemoteProc)inj->fnGetProcAddress(dll, inj->funcName);
    if (!func) {
        inj->result = inj->fnGetLastError();
        return 0;
    }

    // Call the function passing the data (which is at the end of the
    // injection struct) and the size of the data
    void* dataAddr = (void*)((char*)inj + sizeof(InjectionData));
    inj->result = func(dataAddr, inj->dataSize);
    return 0;

/*__asm {
    push        ebp
    mov         ebp,esp
    sub         esp,0Ch
    //HMODULE dll = inj->fnGetModuleHandle(inj->moduleName);
    mov         eax,dword ptr [inj]
    add         eax,0Ch
    push        eax
    mov         ecx,dword ptr [inj]
    mov         edx,dword ptr [ecx]
    call        edx
    mov         dword ptr [dll],eax
    //if (!dll) {
    cmp         dword ptr [dll],0
    jne         RemoteFunctionDelegate+2Fh
    //    inj->result = inj->fnGetLastError();
    mov         eax,dword ptr [inj]
    mov         ecx,dword ptr [eax+8]
    call        ecx
    mov         edx,dword ptr [inj]
    mov         dword ptr [edx+4Ch],eax
        // Not sure if the return value can be retrieved from the remote
        // thread, so just store it in the struct and return 0 here
    //    return 0;
    xor         eax,eax
    jmp         RemoteFunctionDelegate+7Ch
    //}

    // Get the address of the function to call
    //RemoteProc func = (RemoteProc)inj->fnGetProcAddress(dll, inj->funcName);
    mov         eax,dword ptr [inj]
    add         eax,2Ch
    push        eax
    mov         ecx,dword ptr [dll]
    push        ecx
    mov         edx,dword ptr [inj]
    mov         eax,dword ptr [edx+4]
    call        eax
    mov         dword ptr [func],eax
    //if (!func) {
    cmp         dword ptr [func],0
    jne         RemoteFunctionDelegate+5Dh
    //    inj->result = inj->fnGetLastError();
    mov         ecx,dword ptr [inj]
    mov         edx,dword ptr [ecx+8]
    call        edx
    mov         ecx,dword ptr [inj]
    mov         dword ptr [ecx+4Ch],eax
    //    return 0;
    xor         eax,eax
    jmp         RemoteFunctionDelegate+7Ch
    //}

    // Call the function passing the data (which is at the end of the
    // injection struct) and the size of the data
    //void* dataAddr = (void*)((char*)inj + sizeof(InjectionData));
    mov         edx,dword ptr [inj]
    add         edx,54h
    mov         dword ptr [dataAddr],edx
    //inj->result = func(dataAddr, inj->dataSize);
    mov         eax,dword ptr [inj]
    mov         ecx,dword ptr [eax+50h]
    push        ecx
    mov         edx,dword ptr [dataAddr]
    push        edx
    call        dword ptr [func]
    mov         ecx,dword ptr [inj]
    mov         dword ptr [ecx+4Ch],eax
    //return 0;
    xor         eax,eax
    //}
    mov         esp,ebp
    pop         ebp
    ret         4
}*/
}
#pragma optimize("", on)
#pragma check_stack(on)

// Size calculated by looking at assembly, rounded to power-of-two
#ifdef _DEBUG
  #define RemoteFunctionDelegateSize 256
#else
  // Just use same size here. It's likely that the size will be larger
  // in debug. Allocating *more* space than needed can't hurt.
  #define RemoteFunctionDelegateSize 256
#endif

/*--------------------------------------------------------------------------+
| Calls the function of the given name in the WD_Hook DLL.                  |
| It uses a delegate function which it injects into the remote process.     |
| That function then calls the DLL function.                                |
+--------------------------------------------------------------------------*/
DWORD CallRemoteFunction(HWND windowHandle, char* funcName, LPVOID data, DWORD dataSize) {
    InjectionData* injData = NULL;
    void* dataAddr = NULL;
    DWORD returnValue;
    errno_t result;
    HMODULE hKernel32 = GetModuleHandle(L"Kernel32");

    DWORD pid = -1;
    GetWindowThreadProcessId(windowHandle, &pid);

    // Make sure we are not injecting into our own process
    if (pid == GetCurrentProcessId()) {
        return ERROR_INVALID_PARAMETER;
    }

    // Calculate how many bytes the injected code and data takes
    DWORD codeSize = RemoteFunctionDelegateSize;
    DWORD totalDataSize = sizeof(InjectionData) + dataSize;

    // Set up injection struct
    injData = (InjectionData*)malloc(totalDataSize);
    ZeroMemory(injData, totalDataSize);
    injData->dataSize = dataSize;

    // Copy additional data to the end of the injection struct.
    // This data will be accessed by the remote function
    dataAddr = (void*)((char*)injData + sizeof(InjectionData));
    result = memcpy_s(dataAddr, dataSize, data, dataSize);
    if (result != 0) {
        returnValue = ERROR_INVALID_PARAMETER;
        goto cleanup;
    }

    // Get pointers to the API calls we will be using in the remote thread
    injData->fnGetModuleHandle = (GetModuleHandleProc)GetProcAddress(hKernel32, "GetModuleHandleA");
    if (!injData->fnGetModuleHandle) {
        returnValue = GetLastError();
        goto cleanup;
    }
    injData->fnGetProcAddress = (GetProcAddressProc)GetProcAddress(hKernel32, "GetProcAddress");
    if (!injData->fnGetProcAddress) {
        returnValue = GetLastError();
        goto cleanup;
    }
    injData->fnGetLastError = (GetLastErrorProc)GetProcAddress(hKernel32, "GetLastError");
    if (!injData->fnGetLastError) {
        returnValue = GetLastError();
        goto cleanup;
    }

    // Set strings to be passed
    result = strncpy_s(injData->moduleName, MAX_FUNC_NAME, DLL_NAME, MAX_FUNC_NAME);
    if (result != 0) {
        returnValue = ERROR_INVALID_PARAMETER;
        goto cleanup;
    }
    result = strncpy_s(injData->funcName, MAX_FUNC_NAME, funcName, MAX_FUNC_NAME);
    if (result != 0) {
        returnValue = ERROR_INVALID_PARAMETER;
        goto cleanup;
    }

    StartGetInfo(windowHandle); // Make sure the hook DLL does not monitor messages send from itself
    returnValue = InjectRemoteThread(pid, (LPTHREAD_START_ROUTINE)RemoteFunctionDelegate,
                                     codeSize, injData, totalDataSize);
    StopGetInfo(windowHandle);
    if (returnValue != S_OK) goto cleanup;

    // Copy the data back from the injection struct.
    result = memcpy_s(data, dataSize, dataAddr, dataSize);
    if (result != 0) {
        returnValue = ERROR_INVALID_PARAMETER;
        goto cleanup;
    }
    returnValue = injData->result;  // Get return value from remote function

    cleanup:
    if (injData) free(injData);
    return returnValue;
}

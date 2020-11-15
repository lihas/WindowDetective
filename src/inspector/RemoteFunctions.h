//////////////////////////////////////////////////////////////////////////
// File: RemoteFunctions.h                                              //
// Date: 2010-07-01                                                     //
// Desc: Defines functions that are injected into a remote thread       //
//   in a process to run code or collect data that can only be          //
//   obtained from that remote process.                                 //
//   Note that functions to be injected MUST NOT make any calls to      //
//   code in this process. For more information, see:                   //
//   http://www.codeproject.com/KB/threads/winspy.aspx#section_3        //
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

#ifndef REMOTE_FUNCTIONS_H
#define REMOTE_FUNCTIONS_H

/* Notes:
    * #pragma check_stack supposedly turns off the "stack probe", but that
      is only necessary if you have more than 4k of local vars.
    * Make sure function to inject is static so it's not inrementally linked
    * Don't reference any string literals in the injected function.
    * Don't use any switch-case statements (use if-else instead).
    * Make sure /GZ is turned off (in debug). See if there is a #pragma or
      something for it and to control any other debug options.
*/

extern "C" {

// Annotations for parameter of functions or members of structs
#define in
#define out
#define in_out

#define MAX_FUNC_NAME  32

// Typedefs of function pointers
typedef HMODULE (WINAPI *GetModuleHandleProc)(LPCSTR);
typedef FARPROC (WINAPI *GetProcAddressProc)(HMODULE, LPCSTR);
typedef DWORD (WINAPI *GetLastErrorProc)(void);
typedef DWORD (WINAPI *RemoteProc)(LPVOID, DWORD);  // Remote function definition

struct InjectionData {
    GetModuleHandleProc fnGetModuleHandle;
    GetProcAddressProc fnGetProcAddress;
    GetLastErrorProc fnGetLastError;

    char moduleName[MAX_FUNC_NAME];
    char funcName[MAX_FUNC_NAME];
    DWORD result;
    DWORD dataSize;
    // Data block is at end of this struct
};

DWORD InjectRemoteThread(
   in     DWORD processId,
   in     LPTHREAD_START_ROUTINE func,
   in     DWORD funcSize,
   in_out LPVOID data,
   in     DWORD dataSize
);

DWORD CallRemoteFunction(
   in     HWND windowHandle,
   in     char* funcName,
   in_out LPVOID data,
   in     DWORD dataSize
);

}

#endif   // REMOTE_FUNCTIONS_H
//////////////////////////////////////////////////////////////////////////
// File: Process.cpp                                                    //
// Date: 2010-03-05                                                     //
// Desc: Represents a process. Each process has a number of windows it  //
//   owns. Non-windowed processes are kept in case they ever create a   //
//   window, but they are not shown in the GUI.                         //
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

#include "inspector.h"
#include "window_detective/Logger.h"
#include "window_detective/main.h"
#include "window_detective/QtHelpers.h"


// Function prototypes for DLLs
typedef DWORD (WINAPI *GetModuleFileNameExProc)(HANDLE, HMODULE, LPTSTR, DWORD);
typedef BOOL (WINAPI *QueryFullProcessImageNameProc)(HANDLE, DWORD, LPTSTR, PDWORD);

/*--------------------------------------------------------------------------+
| Constructor.                                                              |
+--------------------------------------------------------------------------*/
Process::Process(DWORD pid) :
    id((uint)pid), icon(), windows() {
    HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
                                  PROCESS_VM_READ, FALSE, id );
    // Ignore process 0 and 4 (the system processes)
    if (hProcess != NULL && id != 0 && id != 4) {
        WCHAR* szFile = new WCHAR[MAX_PATH];

        // Get file path and name
        if (queryModuleFileName(hProcess, szFile, MAX_PATH)) {
            filePath = wCharToString(szFile);
            int indexOfSlash = filePath.lastIndexOf('\\');
            if (indexOfSlash != -1)
                name = filePath.right(filePath.size()-indexOfSlash-1);

            // Get executable file icon
            SHFILEINFO fileInfo;
            SHGetFileInfo(szFile, 0, &fileInfo, sizeof(fileInfo), SHGFI_ICON | SHGFI_SMALLICON);
            if (fileInfo.hIcon) {
                icon = QIcon(QPixmapFromHICON(fileInfo.hIcon));
                if (icon.isNull()) {
                    loadGenericIcon();
                }
                DestroyIcon(fileInfo.hIcon);
            }
            else {
                loadGenericIcon();
            }
        }
        delete[] szFile;
    }
    else {
        name = TR("<unknown>");
        loadGenericIcon();
    }
    CloseHandle(hProcess);
}

/*--------------------------------------------------------------------------+
| Copy Constructor.                                                         |
+--------------------------------------------------------------------------*/
Process::Process(const Process& other) :
    id(other.id),
    name(other.name),
    filePath(other.filePath),
    icon(other.icon),
    windows(other.windows) {
}

void Process::addWindow(Window* wnd) {
    if (wnd) windows.append(wnd);
}

void Process::removeWindow(Window* wnd) {
    if (wnd && !windows.isEmpty()) {
        windows.removeOne(wnd);
    }
}
/*--------------------------------------------------------------------------+
| Sets the icon to be the generic exe icon (i.e. for executables that have  |
| not set their own icon).                                                  |
+--------------------------------------------------------------------------*/
void Process::loadGenericIcon() {
    SHFILEINFO fileInfo;
    SHGetFileInfo(L".exe", FILE_ATTRIBUTE_NORMAL, &fileInfo, sizeof(fileInfo),
            SHGFI_ICON | SHGFI_SMALLICON | SHGFI_USEFILEATTRIBUTES);
    if (fileInfo.hIcon) {
        icon = QIcon(QPixmapFromHICON(fileInfo.hIcon));
        if (icon.isNull()) {
            Logger::warning(TR("Unable to load generic exe icon for process %1").arg(id));
        }
        DestroyIcon(fileInfo.hIcon);
    }
    else {
        Logger::warning(TR("Unable to load generic exe icon for process %1").arg(id));
    }
}

/*--------------------------------------------------------------------------+
| Gets the file path of the process and returns it in the szFile parameter. |
| On XP systems, the GetModuleFileNameEx function in PsApi.dll is used.     |
| But Vista and higher can use the QueryFullProcessImageName function,      |
| which is more likely to succeed.                                          |
+--------------------------------------------------------------------------*/
bool Process::queryModuleFileName(HANDLE hProcess, WCHAR* szFile, uint size) {
    if (!KernelLibrary || !PsApiLibrary)
        return false;

    DWORD result = 0;
    if (getOSVersion() >= 600) {
        QueryFullProcessImageNameProc fileNameFunction;
        fileNameFunction = (QueryFullProcessImageNameProc)GetProcAddress(
                                    KernelLibrary, "QueryFullProcessImageNameW");
        if (!fileNameFunction)
            return false;
        DWORD sizeIn = size;
        result = (DWORD)fileNameFunction(hProcess, NULL, szFile, (PDWORD)&sizeIn);
    }
    else {
        GetModuleFileNameExProc fileNameFunction;
        fileNameFunction = (GetModuleFileNameExProc)GetProcAddress(
                                    PsApiLibrary, "GetModuleFileNameExW");
        if (!fileNameFunction)
            return false;
        result = (DWORD)fileNameFunction(hProcess, NULL, szFile, (DWORD)size);
    }
    if (!result) {
        Logger::osWarning(TR("Failed to get name of process %1").arg(id));
        return false;
    }
    return true;
}
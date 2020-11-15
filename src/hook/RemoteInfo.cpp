//////////////////////////////////////////////////////////////////////////
// File: RemoteInfo.cpp                                                 //
// Date: 2011-06-14                                                     //
// Desc: Functions which are called by a delegate function which        //
//   is injected in the remote process by Window Detective.             //
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

#include "stdafx.h"
#include "Hook.h"


// Typedefs of function pointers
typedef int (WINAPI *GetObjectProc)(HGDIOBJ, int, PVOID);

/*--------------------------------------------------------------------------+
| Gets information on a window class.                                       |
+--------------------------------------------------------------------------*/
DWORD GetWindowInfoRemote(PVOID data, DWORD dataSize) {
    // First, a sanity check
    if (dataSize != sizeof(WindowInfoStruct)) return -1;
    WindowInfoStruct* info = (WindowInfoStruct*)data;
    DWORD statusCode = S_OK;
    HINSTANCE hInst = (HINSTANCE)GetWindowLongPtrW(info->windowHandle, GWLP_HINSTANCE);

    // Get class info
    info->wndClassInfo.cbSize = sizeof(WNDCLASSEX);
    if (!GetClassInfoExW(hInst, (LPWSTR)info->className, &info->wndClassInfo)) {
        return GetLastError();
    }

    // Load the Gdi32 library, since it may not be loaded in the remote process
    HMODULE hGdi32 = LoadLibraryW(L"Gdi32");
    if (!hGdi32) return GetLastError();

    GetObjectProc fnGetObject = (GetObjectProc)GetProcAddress(hGdi32, "GetObjectW");
    if (!fnGetObject) {
        statusCode = GetLastError();
        goto cleanup;
    }
    if (info->wndClassInfo.hbrBackground) {   // Check if the class actually has a background brush
        if (!fnGetObject(info->wndClassInfo.hbrBackground, sizeof(LOGBRUSH), (PVOID)&(info->logBrush))) {
            info->logBrushResult = GetLastError();
        }
    }

    cleanup:
    // Free the Gdi32 library
    if (!FreeLibrary(hGdi32)) return GetLastError();
    return statusCode;
}

/*--------------------------------------------------------------------------+
| Gets the item data from a ListView.                                       |
+--------------------------------------------------------------------------*/
DWORD GetListViewItemsRemote(PVOID data, DWORD dataSize) {
    // First, a sanity check
    if (dataSize != sizeof(ListViewItemsStruct)) return -1;
    ListViewItemsStruct* info = (ListViewItemsStruct*)data;

    int numberLeftToGet = info->totalNumber - info->startIndex;
    info->numberRetrieved = min(numberLeftToGet, MAX_LVITEM_COUNT);

    for (unsigned int i = 0; i < info->numberRetrieved; i++) {
        LVITEMW lvItem = { 0 };

        // From MSDN: Applications should not assume that the text will necessarily be placed
        // in the specified buffer. The control may instead change the pszText member
        // of the structure to point to the new text, rather than place it in the buffer.
        // For that reason, we can't point it straight at ListViewItemStruct's one
        const UINT bufferSize = arraysize(info->items[i].text);
        WCHAR* buffer = (WCHAR*)malloc(bufferSize * sizeof(WCHAR));
        if (!buffer) return ERROR_OUTOFMEMORY;

        int itemNumber = info->startIndex + i;
        info->items[i].index = itemNumber;
        lvItem.iItem = itemNumber;
        lvItem.iSubItem = 0;
        lvItem.mask = LVIF_TEXT | LVIF_STATE;  //Indicate what data we want to be returned
        lvItem.stateMask = LVIS_SELECTED;
        lvItem.pszText = buffer;
        lvItem.cchTextMax = bufferSize;

        // The struct will be filled with the requested data
        DWORD_PTR msgReturnValue;
        LRESULT result = SendMessageTimeoutW(info->handle, LVM_GETITEMW, 0,
                                (LPARAM)&lvItem, SMTO_ABORTIFHUNG,
                                REMOTE_INFO_TIMEOUT, &msgReturnValue);
        if (result && msgReturnValue == TRUE) {
            wcsncpy_s(info->items[i].text, bufferSize, lvItem.pszText, _TRUNCATE);
            info->items[i].isSelected = (lvItem.state & LVIS_SELECTED) != 0;
            free(buffer);
        }
        else {
            free(buffer);
            return GetLastError();
        }
    }

    return S_OK;
}

/*--------------------------------------------------------------------------+
| Gets the item data from a Tab.                                            |
+--------------------------------------------------------------------------*/
DWORD GetTabItemsRemote(PVOID data, DWORD dataSize) {
    // First, a sanity check
    if (dataSize != sizeof(TabItemsStruct)) return -1;
    TabItemsStruct* info = (TabItemsStruct*)data;

    info->numberRetrieved = min(info->totalNumber, MAX_TABITEM_COUNT);

    for (unsigned int i = 0; i < info->numberRetrieved; i++) {
        TCITEMW tabItem = { 0 };

        // From MSDN: The control may change the pszText member of the structure to point to
        // the new text instead of filling the buffer with the requested text. The control may
        // set the pszText member to NULL to indicate that no text is associated with the item.
        // For that reason, we can't point it straight at TabItemStruct's one
        const UINT bufferSize = arraysize(info->items[i].text);
        WCHAR* buffer = (WCHAR*)malloc(bufferSize * sizeof(WCHAR));;
        if (!buffer) return ERROR_OUTOFMEMORY;

        tabItem.mask = TCIF_TEXT | TCIF_IMAGE | TCIF_PARAM;  //Indicate what data we want to be returned
        tabItem.pszText = buffer;
        tabItem.cchTextMax = bufferSize;

        // The struct will be filled with the requested data
        DWORD_PTR msgReturnValue;
        LRESULT result = SendMessageTimeoutW(info->handle, TCM_GETITEMW, i,
                                (LPARAM)&tabItem, SMTO_ABORTIFHUNG,
                                REMOTE_INFO_TIMEOUT, &msgReturnValue);
        if (result && msgReturnValue == TRUE) {
            if (tabItem.pszText) {
                wcsncpy_s(info->items[i].text, bufferSize, tabItem.pszText, _TRUNCATE);
            }
            info->items[i].imageIndex = tabItem.iImage;
            info->items[i].lParam = tabItem.lParam;
            free(buffer);
        }
        else {
            free(buffer);
            return GetLastError();
        }
    }

    return S_OK;
}

/*--------------------------------------------------------------------------+
| Gets info from a Date/Time picker control.                                |
+--------------------------------------------------------------------------*/
DWORD GetDateTimeInfoRemote(PVOID data, DWORD dataSize) {
    // First, a sanity check
    if (dataSize != sizeof(DateTimeInfoStruct)) return -1;
    DateTimeInfoStruct* info = (DateTimeInfoStruct*)data;

    DWORD_PTR msgReturnValue = 0;
    LRESULT result = 0;

    // Get the currently selected date/time
    result = SendMessageTimeoutW(info->handle, DTM_GETSYSTEMTIME, 0,
                      (LPARAM)&info->selectedTime, SMTO_ABORTIFHUNG,
                      REMOTE_INFO_TIMEOUT, &msgReturnValue);
    if (result) {
        info->selectedTimeStatus = msgReturnValue;
    }
    else {
        return GetLastError();
    }

    // Get the min/max range
    SYSTEMTIME times[2];
    ZeroMemory(times, sizeof(times));

    result = SendMessageTimeoutW(info->handle, DTM_GETRANGE, 0,
                      (LPARAM)&times, SMTO_ABORTIFHUNG,
                      REMOTE_INFO_TIMEOUT, &msgReturnValue);
    if (result) {
        info->range = msgReturnValue;
        if ((info->range & GDTR_MIN) == GDTR_MIN) {
            if (memcpy_s(&info->minTime, sizeof(SYSTEMTIME), &times[0], sizeof(SYSTEMTIME)) != 0) {
                return ERROR_INVALID_PARAMETER;
            }
        }
        if ((info->range & GDTR_MAX) == GDTR_MAX) {
            if (memcpy_s(&info->maxTime, sizeof(SYSTEMTIME), &times[1], sizeof(SYSTEMTIME)) != 0) {
                return ERROR_INVALID_PARAMETER;
            }
        }
    }
    else {
        return GetLastError();
    }

    return S_OK;
}

/*--------------------------------------------------------------------------+
| Gets the text and bounding rectangle for each part in a StatusBar.        |
+--------------------------------------------------------------------------*/
DWORD GetStatusBarInfoRemote(PVOID data, DWORD dataSize) {
    // First, a sanity check
    if (dataSize != sizeof(StatusBarInfoStruct)) return -1;
    StatusBarInfoStruct* info = (StatusBarInfoStruct*)data;

    DWORD statusCode = S_OK;
    DWORD_PTR msgReturnValue = 0;
    LRESULT result = 0;

    UINT textLength = 0;
    WCHAR* buffer = NULL;     // Buffer for each item's text.
    UINT maxLength = 0;       // Used to determine size of buffer

    info->numberRetrieved = min(info->totalNumber, MAX_SBPART_COUNT);

    for (unsigned int i = 0; i < info->numberRetrieved; i++) {
        // Get text length
        result = SendMessageTimeoutW(info->handle, SB_GETTEXTLENGTH, i, 0,
                                     SMTO_ABORTIFHUNG, REMOTE_INFO_TIMEOUT, &msgReturnValue);
        if (result) {
            textLength = LOWORD(msgReturnValue) + 1; // +1 for null terminator (not sure if it's necessary)
        }
        else {
            statusCode = GetLastError();
            goto cleanup;
        }

        if (buffer) free(buffer);    // Free memory from last iteration
        const UINT destSize = arraysize(info->items[i].text);
        buffer = (WCHAR*)malloc(textLength * sizeof(WCHAR));
        if (!buffer) {
            statusCode = ERROR_OUTOFMEMORY;
            goto cleanup;
        }

        // Get text and copy into our struct
        result = SendMessageTimeoutW(info->handle, SB_GETTEXT, i,
                            (LPARAM)buffer, SMTO_ABORTIFHUNG,
                            REMOTE_INFO_TIMEOUT, &msgReturnValue);
        if (result) {
            if (LOWORD(msgReturnValue) > 0) {
                wcsncpy_s(info->items[i].text, destSize, buffer, _TRUNCATE);
            }
        }
        else {
            statusCode = GetLastError();
            goto cleanup;
        }

        // Get bounding rect for each item
        result = SendMessageTimeoutW(info->handle, SB_GETRECT, i,
                            (LPARAM)&(info->items[i].rect), SMTO_ABORTIFHUNG,
                            REMOTE_INFO_TIMEOUT, &msgReturnValue);
        if (!result || msgReturnValue != TRUE) {
            statusCode = GetLastError();
            goto cleanup;
        }

    }

    // Get the border around the window, and padding between parts
    int elements[3];
    result = SendMessageTimeoutW(info->handle, SB_GETBORDERS, 0,
                        (LPARAM)&elements, SMTO_ABORTIFHUNG,
                        REMOTE_INFO_TIMEOUT, &msgReturnValue);
    if (result && msgReturnValue == TRUE) {
        info->horzBorder = elements[0];
        info->vertBorder = elements[1];
        info->padding = elements[2];
    }
    else {
        statusCode = GetLastError();
        goto cleanup;
    }

    cleanup:
    if (buffer) free(buffer);
    return statusCode;
}
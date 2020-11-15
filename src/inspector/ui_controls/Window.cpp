//////////////////////////////////////////////////////////////////////////
// File: Window.cpp                                                     //
// Date: 2010-02-20                                                     //
// Desc: Creates window objects from a real Windows handle (HWND)       //
//   as well as other window related objects such as window             //
//   classes, styles and messages.                                      //
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

#include "inspector/inspector.h"
#include "inspector/WindowManager.h"
#include "inspector/RemoteFunctions.h"
#include "hook/Hook.h"
#include "ui/HighlightPane.h"
#include "ui/property_pages/GenericPropertyPage.h"
#include "window_detective/StringFormatter.h"
#include "window_detective/QtHelpers.h"


HighlightPane Window::flashHighlighter;  // This needs to be done better. It doesn't belong in Window

/*--------------------------------------------------------------------------+
| Constructor                                                               |
| Creates a Window object from the real window handle                       |
+--------------------------------------------------------------------------*/
Window::Window(HWND handle, WindowClass* theClass) :
    handle(handle),
    windowClass(theClass),
    text(), parent(NULL),
    windowRect(), clientRect(),
    styles(), exStyles(),
    styleBits(0), exStyleBits(0),
    hScrollInfo(NULL), vScrollInfo(NULL),
    icon(), font(NULL),
    process(NULL), threadId(0) {
}

/*--------------------------------------------------------------------------+
| Copy Constructor                                                          |
+--------------------------------------------------------------------------*/
Window::Window(const Window& other) :
    handle(other.handle),
    windowClass(other.windowClass),
    parent(other.parent),
    text(other.text),
    styleBits(other.styleBits),
    exStyleBits(other.exStyleBits),
    styles(other.styles),
    exStyles(other.exStyles),
    icon(other.icon),
    process(other.process),
    threadId(other.threadId),
    hScrollInfo(NULL),
    vScrollInfo(NULL),
    font(NULL) {
    if (other.font) font = new WinFont(*other.font);
    if (other.hScrollInfo) hScrollInfo = new WinScrollInfo(*other.hScrollInfo);
    if (other.vScrollInfo) vScrollInfo = new WinScrollInfo(*other.vScrollInfo);
}

/*--------------------------------------------------------------------------+
| Destructor                                                                |
+--------------------------------------------------------------------------*/
Window::~Window() {
    windowClass = NULL;
    parent = NULL;
    if (font) {
        delete font;
        font = NULL;
    }
    if (hScrollInfo) {
        delete hScrollInfo;
        hScrollInfo = NULL;
    }
    if (vScrollInfo) {
        delete vScrollInfo;
        vScrollInfo = NULL;
    }
    process = NULL;
}


/**********************/
/*** Getter methods ***/
/**********************/

/*--------------------------------------------------------------------------+
| Returns the window's class. It returns the cached data if it exists, if   |
| not it looks it up in the WindowManager's list of known classes.          |
| If it does not exist there, it adds it.                                   |
+--------------------------------------------------------------------------*/
WindowClass* Window::getWindowClass() {
    if (!windowClass) {
        windowClass = WindowManager::current().getWindowClassFor(handle);
    }
    return windowClass;
}

/*--------------------------------------------------------------------------+
| The window's text/title. It returns the cached data if it exists,         |
| otherwise it retrieve it from the OS by sending the WM_GETTEXT            |
| message to the window.                                                    |
+--------------------------------------------------------------------------*/
String Window::getText() {
    if (text.isNull()) {
        WCHAR* charData = NULL;
        UINT length = sendMessage<UINT>(WM_GETTEXTLENGTH);
        if (length > 0) {
            charData = new WCHAR[length+1];   // Text length + null terminator
            LRESULT result = sendMessage<LRESULT,UINT,WCHAR*>(WM_GETTEXT, length+1, charData);
            if (result) {
                text = wCharToString(charData, length);
            }
            else {
                text = "";
            }
        }
        else {
            text = "";
        }
        if (charData) delete[] charData;
    }
    return text;
}

/*--------------------------------------------------------------------------+
| Returns the window's owner. An overlapped or pop-up window can be         |
| owned by another overlapped or pop-up window.                             |
+--------------------------------------------------------------------------*/
Window* Window::getOwner() {
    HWND ownerHandle = GetWindow(getHandle(), GW_OWNER);
    return WindowManager::current().find(ownerHandle);
}

/*--------------------------------------------------------------------------+
| Returns all windows who's parent is this. Note that although this         |
| window has a reference to it's parent, the list of children is built      |
| each time this function is called (i.e. it's not cached).                 |
| TODO: Would it be more efficient to store them here?                      |
+--------------------------------------------------------------------------*/
WindowList Window::getChildren() {
    return WindowManager::current().findChildren(this);
}

/*--------------------------------------------------------------------------+
| Returns all windows who's ancestor is this.                               |
+--------------------------------------------------------------------------*/
WindowList Window::getDescendants() {
    WindowList allChildren;
    WindowList children = getChildren();
    WindowList::const_iterator i;

    for (i = children.begin(); i != children.end(); ++i) {
        allChildren.append(*i);
        allChildren.append((*i)->getDescendants());
    }
    return allChildren;
}

/*--------------------------------------------------------------------------+
| Returns the position and size of the window. This area contains           |
| the entire window including title bar and borders (if any).               |
+--------------------------------------------------------------------------*/
QRect Window::getDimensions() {
    if (windowRect.isNull() || clientRect.isNull()) {
        // Update both at once, more efficient
        WINDOWINFO info;
        info.cbSize = sizeof(WINDOWINFO);

        GetWindowInfo(handle, &info);
        windowRect = QRectFromRECT(info.rcWindow);
        clientRect = QRectFromRECT(info.rcClient);
    }
    return windowRect;
}

/*--------------------------------------------------------------------------+
| Returns the position and size of the window's client area. This           |
| is the area that the owner application has control over, and does         |
| not include the title bar and borders (if any).                           |
+--------------------------------------------------------------------------*/
QRect Window::getClientDimensions() {
    if (clientRect.isNull() || windowRect.isNull()) {
        // Update both at once, more efficient
        WINDOWINFO info;
        info.cbSize = sizeof(WINDOWINFO);

        GetWindowInfo(handle, &info);
        windowRect = QRectFromRECT(info.rcWindow);
        clientRect = QRectFromRECT(info.rcClient);
    }
    return clientRect;
}

/*--------------------------------------------------------------------------+
| If this is a child window, then it's coords are relative to it's          |
| parent. If not then they are the same as it's absolute coords.            |
+--------------------------------------------------------------------------*/
QRect Window::getRelativeDimensions() {
    if (isChild()) {
        RECT rect = RECTFromQRect(getDimensions());
        MapWindowPoints(NULL, GetParent(handle), (POINT*)&rect, 2);
        return QRectFromRECT(rect);
    }
    else {
        return windowRect;
    }
}

QPoint Window::getRelativePosition() {
    return getRelativeDimensions().topLeft();
}

/*--------------------------------------------------------------------------+
| Returns the standard window styles in a LONG value. Each bit              |
| represents a different style.                                             |
+--------------------------------------------------------------------------*/
uint Window::getStyleBits() {
    if (!styleBits) {
        // Note: Window style (and ex) bits can legitamately be 0, in that case
        // we will just be fetching it all the time - no biggie :)
        styleBits = GetWindowLong(handle, GWL_STYLE);
    }
    return styleBits;
}

/*--------------------------------------------------------------------------+
| Returns the extended window styles in a LONG value. Each bit              |
| represents a different style.                                             |
+--------------------------------------------------------------------------*/
uint Window::getExStyleBits() {
    if (!exStyleBits) {
        exStyleBits = GetWindowLong(handle, GWL_EXSTYLE);
    }
    return exStyleBits;
}

/*--------------------------------------------------------------------------+
| Returns a list of standard window styles.                                 |
+--------------------------------------------------------------------------*/
WindowStyleList Window::getStandardStyles() {
    if (styles.isEmpty()) {
        styles = WindowManager::current().parseStyle(this, getStyleBits(), false);
    }
    return styles;
}

/*--------------------------------------------------------------------------+
| Returns a list of extended window styles.                                 |
+--------------------------------------------------------------------------*/
WindowStyleList Window::getExtendedStyles() {
    if (exStyles.isEmpty()) {
        exStyles = WindowManager::current().parseStyle(this, getExStyleBits(), true, GenericOnly);
    }
    return exStyles;
}

/*--------------------------------------------------------------------------+
| Returns the name suitable for display in UI.                              |
+--------------------------------------------------------------------------*/
String Window::getDisplayName() {
    return getWindowClass()->getName()+" ("+hexString((uint)handle)+")";
}

/*--------------------------------------------------------------------------+
| Returns the window's class name for display in UI.                        |
+--------------------------------------------------------------------------*/
String Window::getClassDisplayName() {
    return getWindowClass()->getDisplayName();
}

/*--------------------------------------------------------------------------+
| Returns the window's small and large icon. If no small or large           |
| icon has been set, the icon that represents this class is used.           |
+--------------------------------------------------------------------------*/
const QIcon Window::getIcon() {
    if (icon.isNull()) {
        HICON smallIconHandle = NULL;
        HICON largeIconHandle = NULL;
        ICONINFO iconInfo;

        // Add small and large icons
        smallIconHandle = sendMessage<HICON,uint,uint>(WM_GETICON, ICON_SMALL, NULL);
        largeIconHandle = sendMessage<HICON,uint,uint>(WM_GETICON, ICON_BIG, NULL);

        // QPixmap::fromWinHICON calls GetIconInfo internally, but call it here
        // first so we can show an appropriate error message if it fails.
        if (smallIconHandle) {
            bool result = GetIconInfo(smallIconHandle, &iconInfo);
            if (result) {
                icon.addPixmap(QPixmapFromHICON(smallIconHandle, &iconInfo));
            }
            else {
                Logger::osWarning(TR("Failed to get small icon for window %1")
                                    .arg(getDisplayName()));
            }
        }
        if (largeIconHandle) {
            bool result = GetIconInfo(largeIconHandle, &iconInfo);
            if (result) {
                icon.addPixmap(QPixmapFromHICON(largeIconHandle, &iconInfo));
            }
            else {
                Logger::osWarning(TR("Failed to get large icon for window %1")
                                    .arg(getDisplayName()));
            }
        }
        if (!smallIconHandle && !largeIconHandle)
            icon = getWindowClass()->getIcon();
    }
    return icon;
}

/*--------------------------------------------------------------------------+
| Returns information about the scroll bar/s, or NULL if none.              |
+--------------------------------------------------------------------------*/
WinScrollInfo* Window::getScrollInfo(bool isHorizontal) {
    bool hasScrollBar;
    uint whichBar;
    
    if (getWindowClass()->getName().compare("scrollbar", Qt::CaseInsensitive) == 0) {
        hasScrollBar = hasStyleBits(SBS_VERT) ? !isHorizontal : isHorizontal;
        whichBar = SB_CTL;
    }
    else {
        hasScrollBar = hasStyleBits(isHorizontal ? WS_HSCROLL : WS_VSCROLL);
        whichBar = (isHorizontal ? SB_HORZ : SB_VERT);
    }
    if (hasScrollBar) {
        SCROLLINFO infoStruct;
        infoStruct.cbSize = sizeof(SCROLLINFO);
        infoStruct.fMask = SIF_PAGE | SIF_POS | SIF_RANGE;
        if (GetScrollInfo(handle, whichBar, &infoStruct)) {
            return new WinScrollInfo(infoStruct);
        }
        else {
            Logger::osWarning(TR("Failed to get scroll bar info for window %1").arg(getDisplayName()));
        }
    }
    return NULL;

}

WinScrollInfo* Window::getHorzScrollInfo() {
    if (!hScrollInfo) {
        hScrollInfo = getScrollInfo(true);
    }
    return hScrollInfo;
}

WinScrollInfo* Window::getVertScrollInfo() {
    if (!vScrollInfo) {
        vScrollInfo = getScrollInfo(false);
    }
    return vScrollInfo;
}

/*--------------------------------------------------------------------------+
| Returns the list of user-set properties. These properties are set         |
| by calling the SetProc API function. This data is not cached, it          |
| is retrieved every time this function is called.                          |
+--------------------------------------------------------------------------*/
WindowPropList Window::getProps() {
    WindowPropList props;
    EnumPropsEx(handle, Window::enumProps, reinterpret_cast<ULONG_PTR>(&props));
    return props;
}


/**********************/
/*** Setter methods ***/
/**********************/

void Window::setText(String newText) {
    const ushort* charData = newText.utf16();
    LRESULT result = sendMessage<LRESULT,int,const ushort*>(WM_SETTEXT, NULL, charData);
    if (!result && !GetLastError()) {
        Logger::osError(TR("Unable to set window text: %1").arg(newText));
    }
}

void Window::setDimensions(QRect rect) {
    SetWindowPos(handle, NULL, rect.x(), rect.y(), rect.width(), rect.height(),
            SWP_ASYNCWINDOWPOS | SWP_NOACTIVATE | SWP_NOZORDER);
}

void Window::setPosition(QPoint pos) {
    SetWindowPos(handle, NULL, pos.x(), pos.y(), 0, 0,
            SWP_ASYNCWINDOWPOS | SWP_NOACTIVATE | SWP_NOZORDER | SWP_NOSIZE);
}

void Window::setSize(QSize size) {
    SetWindowPos(handle, NULL, 0, 0, size.width(), size.height(),
            SWP_ASYNCWINDOWPOS | SWP_NOACTIVATE | SWP_NOZORDER | SWP_NOMOVE);
}

void Window::setStyleBits(uint styleBits, uint exStyleBits) {
    if (!SetWindowLongPtr(handle, GWL_STYLE, styleBits)) {
        Logger::osError(TR("Unable to set window style"));
    }
    if (!SetWindowLongPtr(handle, GWL_EXSTYLE, exStyleBits)) {
        Logger::osError(TR("Unable to set window extended style"));
    }

    // MSDN: If you have changed certain window data using SetWindowLong,
    //   you must call SetWindowPos for the changes to take effect.
    SetWindowPos(handle, NULL, 0, 0, 0, 0,
            SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER |
            SWP_NOACTIVATE | SWP_FRAMECHANGED);
}

void Window::setOnTop(bool isOnTop) {
    HWND insertAfter = (isOnTop ? HWND_TOPMOST : HWND_NOTOPMOST);
    SetWindowPos(handle, insertAfter, 0, 0, 0, 0,
            SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOSIZE);

}


/**********************/
/*** Update methods ***/
/**********************/

/*--------------------------------------------------------------------------+
| Invalidates cached data. This forces it to be retrieved the next          |
| time the respective getter is called.                                     |
+--------------------------------------------------------------------------*/
void Window::invalidate() {
    invalidateText();
    invalidateIcon();
    invalidateDimensions();
    invalidateStyles();
}

/*--------------------------------------------------------------------------+
| Clears window and client rects for this window only.                      |
+--------------------------------------------------------------------------*/
void Window::invalidateDimensions() {
    windowRect = QRect();
    clientRect = QRect();
    if (hScrollInfo) {
        delete hScrollInfo;
        hScrollInfo = NULL;
    }
    if (vScrollInfo) {
        delete vScrollInfo;
        vScrollInfo = NULL;
    }
}

/*--------------------------------------------------------------------------+
| Recursively clears dimensions for this window and it's children.          |
+--------------------------------------------------------------------------*/
void Window::invalidateAllDimensions() {
    invalidateDimensions();
    WindowList children = getChildren();
    WindowList::const_iterator i;
    for (i = children.begin(); i != children.end(); ++i) {
        (*i)->invalidateAllDimensions();
    }
}

void Window::invalidateStyles() {
    styleBits = 0;
    exStyleBits = 0;
    styles = WindowStyleList();
    exStyles = WindowStyleList();
}

/*--------------------------------------------------------------------------+
| Emits a signal to let other objects know that this window has updated.    |
+--------------------------------------------------------------------------*/
void Window::fireUpdateEvent(UpdateReason reason) {
    emit updated(reason);
}

/*--------------------------------------------------------------------------+
| This function is called when a message has been received by the window.   |
| It updates the internal data or state depending on the message.           |
+--------------------------------------------------------------------------*/
void Window::messageReceived(WindowMessage* message) {
    WPARAM wParam = message->getParam1();
    LPARAM lParam = message->getParam2();
    switch (message->getId()) {
        case WM_MOVE:
        case WM_SIZE: {
            invalidateAllDimensions();
            break;
        }
        case WM_STYLECHANGED: {
            invalidateStyles();
            // TODO: Pass the STYLESTRUCT and get the new styles from it
            break;
        }
        case WM_HSCROLL: {
            if (hScrollInfo && (LOWORD(wParam) != SB_ENDSCROLL)) {
                hScrollInfo->currentPos = HIWORD(wParam);
            }
            break;
        }
        case WM_VSCROLL: {
            if (vScrollInfo && (LOWORD(wParam) != SB_ENDSCROLL)) {
                vScrollInfo->currentPos = HIWORD(wParam);
            }
            break;
        }
        default: {
            return;   // Nothing to do (don't fire update event)
        }
    }
    fireUpdateEvent(WindowChanged);
}

/*--------------------------------------------------------------------------+
| Updates other properties of this window and it's class.                   |
| <<REMOTE>> Some API functions used here need to be executed in            |
| the remote process.                                                       |
+--------------------------------------------------------------------------*/
bool Window::updateExtraInfo() {
    // It appears that obtaining font object does not need to be done
    // in the remote process, it can just be done here
    LOGFONT logFont;
    HFONT hFont = sendMessage<HFONT,int,int>(WM_GETFONT, NULL, NULL);
    if (hFont) {
        GetObjectW(hFont, sizeof(LOGFONTW), (LPVOID)&logFont);
        if (font) delete font;
        font = new WinFont(hFont, logFont);
    }
    
    // Make sure we have the window class
    getWindowClass();

    DWORD atom = GetClassLongW(handle, GCW_ATOM);
    if (atom) {
        windowClass->setId((ATOM)atom);
    }
    else {
        Logger::osWarning(atom, TR("Could not get class atom for %1").arg(getDisplayName()));
    }

    // Set up info struct
    WindowInfoStruct info;
    info.windowHandle = handle;
    info.logBrushResult = S_OK;
    WCHAR* className = (WCHAR*)windowClass->getName().utf16();
    if (wcsncpy_s(info.className, MAX_WINDOW_CLASS_NAME, className, MAX_WINDOW_CLASS_NAME) != 0) {
        Logger::error("Window::updateExtraInfo - unable to copy string");
        return false;
    }

    // Call the remote function in our hook DLL. When it returns, the struct will contain the info we need.
    DWORD result = CallRemoteFunction(handle, "GetWindowInfoRemote", &info, sizeof(WindowInfoStruct));

    if (result != S_OK) {
        String errorStr = TR("Could not get extended info for %1").arg(getDisplayName());
        if (result == -1) {   // unknown error occurred
            Logger::warning(errorStr);
        }
        else {
            Logger::osWarning(result, errorStr);
        }
        return false;
    }

    windowClass->setStyleBits(info.wndClassInfo.style);
    windowClass->setClassExtraBytes(info.wndClassInfo.cbClsExtra);
    windowClass->setWindowExtraBytes(info.wndClassInfo.cbWndExtra);
    if (info.logBrushResult == S_OK) {
        windowClass->setBackgroundBrush(new WinBrush(info.wndClassInfo.hbrBackground, info.logBrush));
    }
    else {
        Logger::osWarning(info.logBrushResult, TR("Could not get background brush for %1").arg(getDisplayName()));
    }

    return true;
}


/***********************/
/*** Command methods ***/
/***********************/

/*--------------------------------------------------------------------------+
| Shows the window in front of all others. If 'activate' is true,           |
| the window will become the active one. If 'stay' is true, the window      |
| will stay on top always.                                                  |
+--------------------------------------------------------------------------*/
void Window::show(bool activate, bool stay) {
    HWND insertPos = stay ? HWND_TOPMOST : HWND_TOP;
    if (activate) {
        BOOL result = SetWindowPos(handle, insertPos, 0, 0, 0, 0,
                        SWP_SHOWWINDOW | SWP_NOMOVE | SWP_NOSIZE);
        if (!result) {
            Logger::osError(TR("Unable to show window %1").arg(getDisplayName()));
        }
    }
    else {
        ShowWindow(handle, SW_SHOWNA); // Show not active (possibly maximized)
    }
}

/*--------------------------------------------------------------------------+
| Hides the window. This will clear it's WS_VISIBLE flag.                   |
+--------------------------------------------------------------------------*/
void Window::hide() {
    ShowWindow(handle, SW_HIDE);
}

void Window::maximise() {
    ShowWindow(handle, SW_SHOWMAXIMIZED);
}

void Window::minimise() {
    ShowWindow(handle, SW_FORCEMINIMIZE);
}

/*--------------------------------------------------------------------------+
| Closes the window by sending it a WM_CLOSE message. The owner             |
| application may do other processing, such as prompting the user           |
| for confirmation, prior to destroying the window.                         |
| If an application processes this message, it should return zero.          |
+--------------------------------------------------------------------------*/
void Window::close() {
    LRESULT result = sendMessage<LRESULT,int,int>(WM_CLOSE, NULL, NULL);
    if (result != 0) {
        Logger::info(TR("Window (%1) returned from WM_CLOSE with value %2")
                     .arg(getDisplayName(), String::number(result)));
    }
}

void Window::destroy() {
    // TODO: Use DestroyWindow. Must be called from remote thread
}

/*--------------------------------------------------------------------------+
| Flashes the highlighter on the window.                                    |
+--------------------------------------------------------------------------*/
void Window::flash() {
    Window::flashHighlighter.flash(this);
}

/*--------------------------------------------------------------------------+
| The callback function to enumerate all user-set properties.               |
| The Window object that called EnumPropsEx must be passed as the           |
| third parameter (lParam).                                                 |
+--------------------------------------------------------------------------*/
BOOL CALLBACK Window::enumProps(HWND /*unused*/, LPWSTR string, HANDLE hData, ULONG_PTR userData) {
    WindowPropList* list = reinterpret_cast<WindowPropList*>(userData);

    // Name can be either a string or an ATOM (int)
    String name = IS_INTRESOURCE(string) ?
                     hexString((uint)string) + " (Atom)" :
                     wCharToString(string);
    list->append(WindowProp(name, hData));

    // Return TRUE to continue enumeration, FALSE to stop.
    return TRUE;
}

/*--------------------------------------------------------------------------+
| Creates and returns a list of property pages for this object.             |
| Subclasses can override to provide their own specific pages.              |
| Note: The UI window takes ownership of these wigdets.                     |
+--------------------------------------------------------------------------*/
QList<AbstractPropertyPage*> Window::makePropertyPages() {
    return QList<AbstractPropertyPage*>() << new GenericPropertyPage(this);
}

/*--------------------------------------------------------------------------+
| Writes an XML representation of this object to the given stream.          |
+--------------------------------------------------------------------------*/
void Window::toXmlStream(QXmlStreamWriter& stream) {
    stream.writeStartElement("window");
    writeContents(stream);
    stream.writeEndElement();
}

void Window::writeContents(QXmlStreamWriter& stream) {
    getWindowClass()->toXmlStream(stream);

    stream.writeTextElement("handle", stringLabel(getHandle()));
    stream.writeTextElement("parentHandle", stringLabel(getParentHandle()));
    stream.writeTextElement("windowText", stringLabel(getText()));

    stream.writeStartElement("dimensions");
     writeElement(stream, getDimensions());
    stream.writeEndElement();

    stream.writeStartElement("clientDimensions");
     writeElement(stream, getClientDimensions());
    stream.writeEndElement();

    stream.writeTextElement("styleBits", hexString(getStyleBits()));
    stream.writeTextElement("extendedStyleBits", hexString(getExStyleBits()));

    if (getFont()) getFont()->toXmlStream(stream);

    stream.writeStartElement("windowPropsList");
     WindowPropList props = this->getProps();
     WindowPropList::const_iterator i;
     for (i = props.begin(); i != props.end(); ++i) {
         (*i).toXmlStream(stream);
     }
    stream.writeEndElement();

    stream.writeTextElement("ownerProcessPath", stringLabel(getProcess()->getFilePath()));
    stream.writeTextElement("ownerProcessId", stringLabel(getProcessId()));
    stream.writeTextElement("ownerThreadId", stringLabel(getThreadId()));
}

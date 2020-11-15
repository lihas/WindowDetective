//////////////////////////////////////////////////////////////////////////
// File: Window.h                                                     //
// Date: 2010-03-05                                                     //
// Desc: Object that represents a real window or control                //
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

#ifndef WINDOW_H
#define WINDOW_H

#include "inspector/inspector.h"
#include "window_detective/Settings.h"
#include "window_detective/Logger.h"
#include "hook/Hook.h"
#include "ui/property_pages/AbstractPropertyPage.h"


class HighlightPane;  // Forward declaration

enum UpdateReason {
    NoReason,        // 'cos i feel like it :)
    WindowChanged,   // One of the window's properties has changed
    WindowCreated,   // The window was just created
    WindowDestroyed, // The window has been destroyed
    MinorChange      // A minor change has occurred, no need for full update
};


class Window : public QObject {
    Q_OBJECT
public:
    static HighlightPane flashHighlighter;
protected:
    HWND handle;
    WindowClass* windowClass;   // The type of control this is.
    Window* parent;
    String text;                // Window's title or control's text.
    QRect windowRect;           // Coordinates of the window.
    QRect clientRect;           // Coordinates of the client area.
    DWORD styleBits;            // The combined bit-flags of each style.
    DWORD exStyleBits;          // Bit-flags of each extended style.
    WindowStyleList styles;     // List of styles applied to this window.
    WindowStyleList exStyles;   // Extended styles applied to this window.
    QIcon icon;                 // The window's icon (small and large).
    WinFont* font;              // Font with which the control is currently drawing its text.
    WinScrollInfo* hScrollInfo; // Horizontal scroll bar information. Can be NULL.
    WinScrollInfo* vScrollInfo; // Vertical scroll bar information. Can be NULL.
    Process* process;           // Application that created this window.
    DWORD threadId;             // The thread in which it was created.
public:
    Window() : handle(0) {}
    Window(HWND handle, WindowClass* windowClass = NULL);
    Window(const Window& other);
    ~Window();

    // Getter methods. Parent and child variables, as well as process and
    // thread, are set by the WindowManager. Some variables are retrieved directly
    // from the Operating System (by calling the appropriate API function).
    // Other things are cached and lazy initialized.
    HWND getHandle() const { return handle; }
    bool isValid() const { return handle != NULL; }
    WindowClass* getWindowClass();
    String getDisplayName();
    virtual String getClassDisplayName();
    const virtual QIcon getIcon();
    String getText();
    Window* getParent() const { return parent; }
    HWND getParentHandle() const { return parent ? parent->getHandle() : (HWND)0; }
    Window* getOwner();
    WindowList getChildren();
    WindowList getDescendants();
    QRect getDimensions();
    QRect getClientDimensions();
    QPoint getPosition() { return getDimensions().topLeft(); }
    QSize getSize() { return getDimensions().size(); }
    QRect getRelativeDimensions();
    QPoint getRelativePosition();
    uint getStyleBits();
    uint getExStyleBits();
    bool hasStyleBits(uint mask) { return testBits(getStyleBits(), mask); }
    bool hasExStyleBits(uint mask) { return testBits(getExStyleBits(), mask); }
    WindowStyleList getStandardStyles();
    WindowStyleList getExtendedStyles();
    WindowStyleList getStyles() { return getStandardStyles() + getExtendedStyles(); }
    WinScrollInfo* getHorzScrollInfo();
    WinScrollInfo* getVertScrollInfo();
    WindowPropList getProps();
    WinFont* getFont() const { return font; }
    Process* getProcess() const { return process; }
    uint getProcessId() const { return process->getId(); }
    uint getThreadId() const { return threadId; }
    bool isVisible() const { return IsWindowVisible(handle); }
    bool isEnabled() const { return IsWindowEnabled(handle); }
    bool isUnicode() const { return IsWindowUnicode(handle); }
    bool isOnTop() { return hasStyleBits(WS_EX_TOPMOST); }
    bool isChild() { return hasStyleBits(WS_CHILD); }

    // Setter methods. Updates the object's variable and call the appropriate
    // Win32 function to update the real window
    void setParent(Window* p) { parent = p; }
    void setText(String text);
    void setStyleBits(uint styleBits, uint exStyleBits);
    void setPosition(QPoint pos);
    void setPosition(int x, int y) { setPosition(QPoint(x, y)); }
    void setSize(QSize size);
    void setSize(int width, int height) { setSize(QSize(width, height)); }
    void setDimensions(QRect rect);
    void setDimensions(int x, int y, int w, int h) { setDimensions(QRect(x, y, w, h)); }
    void setVisible(bool isVisible) { isVisible ? show() : hide(); }
    void setEnabled(bool isEnabled) { EnableWindow(handle, isEnabled); }
    void setOnTop(bool isOnTop);
    void setProcess(Process* p) { process = p; }
    void setThreadId(DWORD id) { threadId = id; }

    void addStyle(WindowStyle* style) { styles.append(style); }
    void removeStyle(WindowStyle* style) { styles.removeOne(style); }

    void invalidate();
    void invalidateText() { text = String(); }
    void invalidateIcon() { icon = QIcon(); }
    void invalidateDimensions();
    void invalidateAllDimensions();
    void invalidateStyles();
    //virtual void invalidate???Info  - ListView, etc can update their stuff
    //  /\ property page will call this when it is closed, since most extra data isn't
    //     needed outside of it
    bool updateExtraInfo();  // perhaps call this (update|get)RemoteInfo

    // Event methods
    virtual void messageReceived(WindowMessage* message);
    void fireUpdateEvent(UpdateReason reason = NoReason);

    // Command methods. These perform a command on the window.
    void show(bool activate = false, bool stay = false);
    void hide();
    void maximise();
    void minimise();
    void close();
    void destroy();
    void flash();

    //virtual QList<QAction> getMenuActions();
    virtual QList<AbstractPropertyPage*> makePropertyPages();
    void toXmlStream(QXmlStreamWriter& stream);
    void writeStartElement(QXmlStreamWriter& stream);
    virtual void writeContents(QXmlStreamWriter& stream);
    void writeEndElement(QXmlStreamWriter& stream);

    template <typename ReturnType, typename FirstType, typename SecondType>
    ReturnType sendMessage(UINT msgId, FirstType wParam, SecondType lParam);

    template <typename ReturnType>
    ReturnType sendMessage(UINT msgId);

signals:
    void updated(UpdateReason reason = NoReason);

private:
    WinScrollInfo* getScrollInfo(bool isHorizontal);
    static BOOL CALLBACK enumProps(HWND hwnd, LPWSTR string, HANDLE hData, ULONG_PTR userData);
};

// Stupid template definitons, have to be in header file :(
/*--------------------------------------------------------------------------+
| Send a message to the window with the given parameters                    |
+--------------------------------------------------------------------------*/
template <class ReturnType, class FirstType, class SecondType>
inline ReturnType Window::sendMessage(UINT msgId, FirstType wParam, SecondType lParam) {
    DWORD_PTR result;
    LRESULT returnValue;

    StartGetInfo(handle);  // Make sure the hook DLL does not monitor these messages
    returnValue = SendMessageTimeoutW(handle, msgId,
                        (WPARAM)wParam, (LPARAM)lParam, SMTO_ABORTIFHUNG,
                        Settings::messageTimeoutPeriod, &result);
    StopGetInfo(handle);
    if (!returnValue) {
        DWORD error = GetLastError();
        if (error == ERROR_TIMEOUT) {
            String str;
            QTextStream stream(&str);
            stream << "The message " << String::number(msgId)
                   << " sent to window " << getDisplayName()
                   << " has timed-out.\n wParam = " << String::number((uint)wParam)
                   << ", lParam = " << String::number((uint)lParam);
            Logger::warning(str);
            return (ReturnType)0;
        }
    }
    return (ReturnType)result;
}

/*--------------------------------------------------------------------------+
| Send a message to the window with no parameters. Mostly used for getting  |
| a value from the window or for sending an action message (e.g. WM_CLOSE). |
+--------------------------------------------------------------------------*/
template <class ReturnType>
inline ReturnType Window::sendMessage(UINT msgId) {
    return sendMessage<ReturnType,int,int>(msgId, NULL, NULL);
}


/* Specialized classes of Window */
// I don't like to #include them here, but they need the Window class to be defined
// and this way avoids cyclic dependencies.
#include "Button.h"
#include "Edit.h"
#include "ComboBox.h"
#include "ListBox.h"
#include "ListView.h"
#include "DateTimePicker.h"
#include "Tab.h"
#include "StatusBar.h"
#include "ProgressBar.h"



#endif   // WINDOW_H
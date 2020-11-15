//////////////////////////////////////////////////////////////////////////
// File: WindowManager.cpp                                              //
// Date: 2010-02-20                                                     //
// Desc: Maintains a list of all windows and provides                   //
//   functionality to search for a window and other things.             //
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

#include "window_detective/include.h"
#include "window_detective/main.h"
#include "WindowManager.h"
#include "MessageHandler.h"
#include "window_detective/Settings.h"
#include "window_detective/Logger.h"
#include "window_detective/QtHelpers.h"
#include "window_detective/StringFormatter.h"
#include "ui/HighlightPane.h"


/*--------------------------------------------------------------------------+
| Creates window flash highlighter.                                         |
+--------------------------------------------------------------------------*/
void WindowManager::initialize() {
    Window::flashHighlighter.create();
}

/*--------------------------------------------------------------------------+
| Return the singleton instance, instantiating on first use.                |
+--------------------------------------------------------------------------*/
WindowManager& WindowManager::current() {
    static WindowManager* instance = new WindowManager();
    return *instance;
}

/*--------------------------------------------------------------------------+
| Constructor                                                               |
+--------------------------------------------------------------------------*/
WindowManager::WindowManager() :
    allWindows(), allProcesses() {
}

/*--------------------------------------------------------------------------+
| Rebuild the window list by enumerating over all child windows             |
| of the desktop window. Also refreshes processes and threads.              |
+--------------------------------------------------------------------------*/
void WindowManager::refreshAllWindows() {
    WindowList::iterator each;

    // Disconnect any message monitors first
    MessageHandler::current().removeAllListeners();

    // Delete old windows
    foreach (Window* each, allWindows) { delete each; }
    foreach (Process* each, allProcesses) { delete each; }
    allWindows.clear();
    allProcesses.clear();

    // Enumerate desktop window and all it's children
    allWindows.append(new Window(GetDesktopWindow()));
    EnumChildWindows(GetDesktopWindow(), WindowManager::enumChildWindows, reinterpret_cast<LPARAM>(this));

    // Built parent links.
    foreach (Window* each, allWindows) {
        each->setParent(findParent(each));
    }

    // Set each window's owner process and add it to the list.
    DWORD threadId, processId = -1;
    Process* process;
    foreach (Window* each, allWindows) {
        threadId = GetWindowThreadProcessId(each->getHandle(), &processId);
        process = findProcess(processId);
        if (!process) {
            process = new Process(processId);
            allProcesses.append(process);
        }
        process->addWindow(each);
        each->setProcess(process);
        each->setThreadId(threadId);
    }
}

/*--------------------------------------------------------------------------+
| Creates a new window object from the given handle. The type of            |
| window or control is based on it's class and possibly styles              |
| (e.g. CheckBox  is a Button with a special style)                         |
+--------------------------------------------------------------------------*/
Window* WindowManager::createWindow(HWND handle) {
    WindowClass* windowClass = getWindowClassFor(handle);

    String className = windowClass->getName().toLower();
    if (className == "button") {
        LONG typeStyle = GetWindowLong(handle, GWL_STYLE) & BS_TYPEMASK;
        switch (typeStyle) {
          case BS_CHECKBOX:
          case BS_AUTOCHECKBOX:
          case BS_3STATE:
          case BS_AUTO3STATE: {
              return new CheckBox(handle, windowClass);
          }
          case BS_RADIOBUTTON:
          case BS_AUTORADIOBUTTON: {
              return new RadioButton(handle, windowClass);
          }
          case BS_GROUPBOX: {
              return new GroupBox(handle, windowClass);
          }
          default: {
              // If none of the above is true, then the control is just a Button
              return new Button(handle, windowClass);
          }
        }
    }
    else if (className == "edit") {
        return new Edit(handle, windowClass);
    }
    else if (className == "combobox") {
        return new ComboBox(handle, windowClass);
    }
    else if (className == "listbox") {
        return new ListBox(handle, windowClass);
    }
    else if (className == "syslistview32") {
        return new ListView(handle, windowClass);
    }
    else if (className == "sysdatetimepick32") {
        return new DateTimePicker(handle, windowClass);
    }
    else if (className == "systabcontrol32") {
        return new Tab(handle, windowClass);
    }
    else if (className == "msctls_statusbar32") {
        return new StatusBar(handle, windowClass);
    }
    else if (className == "msctls_progress32") {
        return new ProgressBar(handle, windowClass);
    }

    // If none of the above checks are true, then the control is just an ordinary window
    return new Window(handle, windowClass);
}

/*--------------------------------------------------------------------------+
| Creates a new Window object from the given handle, adds it to             |
| the list of all windows and notifies anyone interested.                   |
+--------------------------------------------------------------------------*/
Window* WindowManager::addWindow(HWND handle) {
    // Filter out own windows if necessary
    if (!handle || (!Settings::allowInspectOwnWindows && isOwnWindow(handle)))
        return NULL;

    Window* newWindow = createWindow(handle);
    allWindows.append(newWindow);

    // Set parent
    Window* parent = findParent(newWindow);
    newWindow->setParent(parent);
    if (!parent) {  // Unless it is the desktop window, it should have a parent
        Logger::warning("WindowManager::addWindow - Cannot find parent for window: " +
                        newWindow->getDisplayName());
    }

    // Update owner process
    DWORD threadId, processId = -1;
    threadId = GetWindowThreadProcessId(handle, &processId);
    Process* process = findProcess(processId);
    if (!process) {
        process = addProcess(processId);
    }
    process->addWindow(newWindow);
    newWindow->setProcess(process);
    newWindow->setThreadId(threadId);

    // Notify anyone interested
    emit windowAdded(newWindow);
    Logger::info(TR("Window %1 created.").arg(newWindow->getDisplayName()));
    return newWindow;
}

/*--------------------------------------------------------------------------+
| Removes the given Window object from the list (assuming it                |
| already exists) and notifies anyone interested.                           |
+--------------------------------------------------------------------------*/
void WindowManager::removeWindow(Window* window) {
    // Make sure it exists in the list
    if (!window || !find(window->getHandle())) {
        Logger::warning("Attemped to remove non-existant window: " +
                          hexString(window ? (uint)window->getHandle() : 0));
        return;
    }

    // Notify others that the window is being removed, then remove it.
    // Note: I don't have to worry about removing child windows, as they will each be
    // destroyed individually (See MSDN on DestroyWindow and WM_DESTROY).
    emit windowRemoved(window);
    allWindows.removeOne(window);

    Logger::info(TR("Window %1 destroyed.").arg(window->getDisplayName()));

    Process* ownerProcess = window->getProcess();
    if (ownerProcess) {
        ownerProcess->removeWindow(window);
        // If last in process, remove process
        if (ownerProcess->numWindows() == 0) {
            removeProcess(ownerProcess);
        }
    }
    else {
        Logger::warning("WindowManager::removeWindow - "
                        "Could not find process that owns the window " +
                        window->getDisplayName());
    }
    delete window;
}

void WindowManager::removeWindow(HWND handle) {
    removeWindow(find(handle));
}

/*--------------------------------------------------------------------------+
| Finds an existing class with the given name, or creates a new one         |
| if it isn't in the list.                                                  |
+--------------------------------------------------------------------------*/
WindowClass* WindowManager::getWindowClassNamed(String name) {
    String classKey = name.toLower();
    WindowClass* theClass = Resources::windowClasses.value(classKey, NULL);
    if (!theClass) {
        theClass = new WindowClass(name);
        Resources::windowClasses.insert(classKey, theClass);
    }
    return theClass;
}

/*--------------------------------------------------------------------------+
| Returns the given window's class. First, the class's name is obtained,    |
| then the WindowClass object is looked up.                                 |
+--------------------------------------------------------------------------*/
WindowClass* WindowManager::getWindowClassFor(HWND handle) {
    WCHAR* charData = new WCHAR[256];
    String className;

    if (!GetClassName(handle, charData, 256)) {
        Logger::osWarning(TR("Could not get class name for window %1").arg(hexString((uint)handle)));
        className = TR("<unknown>");
    }
    else {
        className = wCharToString(charData);
    }
    delete[] charData;

    return getWindowClassNamed(className);
}

/*--------------------------------------------------------------------------+
| Creates a new Process object from the given id, adds it to the            |
| list of all processes and notifies anyone interested.                     |
+--------------------------------------------------------------------------*/
Process* WindowManager::addProcess(uint processId) {
    Process* process = new Process(processId);
    allProcesses.append(process);

    // Notify anyone interested
    emit processAdded(process);
    return process;
}

/*--------------------------------------------------------------------------+
| Removes the given Process object from the list (assuming it               |
| already exists) and notifies anyone interested.                           |
+--------------------------------------------------------------------------*/
void WindowManager::removeProcess(Process* process) {
    // Make sure it exists in the list
    if (!process || !findProcess(process->getId())) {
        Logger::warning("WindowManager::removeProcess - "
                        "Attemped to remove non-existant process: " +
                        String::number(process ? process->getId() : 0));
        return;
    }

    // Emit signal first before we actually remove it
    emit processRemoved(process);
    allProcesses.removeOne(process);

    delete process;
}

/*--------------------------------------------------------------------------+
| Returns a window with the given handle, or NULL if none exist.            |
+--------------------------------------------------------------------------*/
Window* WindowManager::find(HWND handle) {
    if (!handle) return NULL;

    WindowList::const_iterator i;
    for (i = allWindows.begin(); i != allWindows.end(); ++i) {
        if ((*i)->getHandle() == handle)
            return *i;
    }
    return NULL;
}

/*--------------------------------------------------------------------------+
| Gets the parent handle for the given window and returns the window which  |
| that handle belongs to. Returns NULL if window does not have a parent.    |
+--------------------------------------------------------------------------*/
Window* WindowManager::findParent(Window* window) {
    HWND parentHandle = GetAncestor(window->getHandle(), GA_PARENT);

    // If a window is top-level, GA_PARENT returns 0 but GA_ROOT
    // returns the desktop window!?!?
    if (!parentHandle)
        parentHandle = GetAncestor(window->getHandle(), GA_ROOT);
    return find(parentHandle);
}

/*--------------------------------------------------------------------------+
| Searches the list of all windows and returns a list of all                |
| windows whos parent is the given window.                                  |
+--------------------------------------------------------------------------*/
WindowList WindowManager::findChildren(Window* window) {
    WindowList children;
    WindowList::const_iterator i;

    for (i = allWindows.begin(); i != allWindows.end(); ++i) {
        if ((*i)->getParent() == window)
            children.append(*i);
    }
    return children;
}

/*--------------------------------------------------------------------------+
| Returns the process with the given PID.                                   |
+--------------------------------------------------------------------------*/
Process* WindowManager::findProcess(uint pid) {
    ProcessList::const_iterator i;
    for (i = allProcesses.begin(); i != allProcesses.end(); ++i) {
        if ((*i)->getId() == pid)
            return *i;
    }
    return NULL;
}

/*--------------------------------------------------------------------------+
| Finds the window/s that match the given criteria.                         |
+--------------------------------------------------------------------------*/
WindowList WindowManager::find(const SearchCriteria& criteria) {
    WindowList list;
    WindowList::const_iterator i;

    for (i = allWindows.begin(); i != allWindows.end(); ++i) {
        if (criteria.matches(*i))
            list.append(*i);
    }
    return list;
}

/*--------------------------------------------------------------------------+
| Returns the window which represents the desktop and is the                |
| parent of all other windows.                                              |
+--------------------------------------------------------------------------*/
Window* WindowManager::getDesktopWindow() {
    Window* desktopWindow = find(GetDesktopWindow());
    Q_ASSERT(desktopWindow != NULL);
    return desktopWindow;
}

/*--------------------------------------------------------------------------+
| Returns the top-most window directly under the given position.            |
| Also updates the window object's position just in case it has             |
| moved and we failed to get notified.                                      |
+--------------------------------------------------------------------------*/
Window* WindowManager::getWindowAt(const QPoint& p) {
    HWND handle = WindowFromPoint(POINTFromQPoint(p));
    if (!handle) return NULL;

    Window* window = find(handle);
    if (!window) return NULL;
    window->invalidateDimensions();
    window->fireUpdateEvent(MinorChange);
    return window;
}

/*--------------------------------------------------------------------------+
| Returns a list of WindowStyles for the given window from the              |
| style bits in the given DWORD.                                            |
| The list of all known window styles is searched for styles whos value     |
| matches the bits set. Usually, a style will only use one bit, although    |
| some are a combination of other style bits. In this case, both that       |
| style, and any others which match the individual bits, will be added.     |
+--------------------------------------------------------------------------*/
WindowStyleList WindowManager::parseStyle(Window* window, DWORD styleBits, bool isExtended, StyleSearchOption searchOption) {
    WindowStyleList list;
    if ((searchOption & GenericOnly) == GenericOnly) {
        // Check general styles
        foreach (WindowStyle* style, Resources::generalWindowStyles) {
            uint value = style->getValue();
            if (style->isExtended() == isExtended) {
                if (testBits(styleBits, value)) {
                    list.append(style);
                }
            }
        }
    }
    if ((searchOption & ClassSpecificOnly) == ClassSpecificOnly) {
        // Check the styles specific to the window's class
        foreach (WindowStyle* style, window->getWindowClass()->getApplicableStyles()) {
            uint value = style->getValue();
            if (style->isExtended() == isExtended) {
                if (testBits(styleBits, value)) {
                    list.append(style);
                }
            }
        }
    }
    return list;
}

/*--------------------------------------------------------------------------+
| Returns a list of window class styles (their String names) from the style |
| bits in the given DWORD.                                                  |
+--------------------------------------------------------------------------*/
QStringList WindowManager::parseClassStyle(DWORD styleBits) {
    QStringList list;
    QHash<uint,String>* styleMap = Resources::constants.value("WindowClassStyles");

    QHash<uint,String>::const_iterator i = styleMap->constBegin();
    while (i != styleMap->constEnd()) {
        if (testBits(styleBits, i.key())) {
            list.append(i.value());
        }
        ++i;
    }
    return list;
}

/*--------------------------------------------------------------------------+
| Returns a DWORD containing the bit set based on the given list.           |
+--------------------------------------------------------------------------*/
uint WindowManager::styleBits(WindowStyleList stylesList) {
    uint styleBits = 0;

    foreach (WindowStyle* style, stylesList) {
        styleBits |= style->getValue();
    }
    return styleBits;
}

/*--------------------------------------------------------------------------+
| Returns a list of all valid standard styles for the given window.         |
+--------------------------------------------------------------------------*/
WindowStyleList WindowManager::getValidStandardStylesFor(Window* window) {
    WindowStyleList list;

    foreach (WindowStyle* style, Resources::generalWindowStyles) {
        if (!style->isExtended())
            list.append(style);
    }
    foreach (WindowStyle* style, window->getWindowClass()->getApplicableStyles()) {
        if (!style->isExtended())
            list.append(style);
    }
    return list;
}

/*--------------------------------------------------------------------------+
| Returns a list of all valid extended styles for the given window.         |
| Note that extended styles which apply to "common control" classes         |
| (such as ListView or TreeView) are not part of these styles.              |
+--------------------------------------------------------------------------*/
WindowStyleList WindowManager::getValidExtendedStylesFor(Window* window) {
    WindowStyleList list;

    foreach (WindowStyle* style, Resources::generalWindowStyles) {
        if (style->isExtended())
            list.append(style);
    }
    return list;
}

/*--------------------------------------------------------------------------+
| Returns the style with the given name, NULL if there aren't any.          |
+--------------------------------------------------------------------------*/
WindowStyle* WindowManager::getStyleNamed(const String& name) {
    foreach (WindowStyle* style, Resources::allWindowStyles) {
        if (style->getName() == name)
            return style;
    }
    return NULL;
}

/*--------------------------------------------------------------------------+
| Returns true if the given window belongs to Window Detective.             |
+--------------------------------------------------------------------------*/
bool WindowManager::isOwnWindow(HWND handle) {
    DWORD processId = -1;
    GetWindowThreadProcessId(handle, &processId);
    return processId == GetCurrentProcessId();
}

/*--------------------------------------------------------------------------+
| The callback function to enumerate all child windows.                     |
| The WindowManager object that called EnumChildWindows must be             |
| passed as the second parameter (lParam).                                  |
+--------------------------------------------------------------------------*/
BOOL CALLBACK WindowManager::enumChildWindows(HWND hwnd, LPARAM lParam) {
    WindowManager* manager = reinterpret_cast<WindowManager*>(lParam);

    // Filter out own windows if necessary
    if (Settings::allowInspectOwnWindows || !isOwnWindow(hwnd)) {
        manager->allWindows.append(manager->createWindow(hwnd));
    }

    // Return TRUE to continue enumeration, FALSE to stop.
    return TRUE;
}


//////////////////////////////////////////////////////////////////////////
// File: WindowManager.h                                              //
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

#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include "inspector.h"
#include "SearchCriteria.h"


enum StyleSearchOption {
    GenericOnly = 1,
    ClassSpecificOnly = 2,
    GenericAndClass = GenericOnly | ClassSpecificOnly
};

class WindowManager : public QObject {
    Q_OBJECT
public:
    static void initialize();
    static WindowManager& current();  // Singleton instance
    static bool isOwnWindow(HWND handle);

    WindowList allWindows;
    ProcessList allProcesses;

    WindowManager();

    void refreshAllWindows();
    Window* createWindow(HWND handle);
    Window* addWindow(HWND handle);
    void removeWindow(HWND handle);
    void removeWindow(Window* window);
    WindowClass* getWindowClassNamed(String name);
    WindowClass* getWindowClassFor(HWND handle);
    Process* addProcess(uint pid);
    void removeProcess(Process* process);
    Window* find(HWND handle);
    Window* findParent(Window* window);
    WindowList findChildren(Window* window);
    Process* findProcess(uint pid);
    WindowList find(const SearchCriteria& criteria);
    Window* getDesktopWindow();
    Window* getWindowAt(const QPoint& p);
    WindowStyleList parseStyle(Window* window, DWORD styleBits, bool isExtended,
                               StyleSearchOption searchOption=GenericAndClass);
    QStringList parseClassStyle(DWORD styleBits);
    uint styleBits(WindowStyleList stylesList);
    WindowStyleList getValidStandardStylesFor(Window*);
    WindowStyleList getValidExtendedStylesFor(Window*);
    WindowStyle* getStyleNamed(const String& name);
signals:
    void windowAdded(Window* window);
    void windowRemoved(Window* window);
    void processAdded(Process* process);
    void processRemoved(Process* process);
private:
    // The callback function to enumerate all child windows
    static BOOL CALLBACK enumChildWindows(HWND hwndChild, LPARAM lParam);
};


#endif   // WINDOW_MANAGER_H

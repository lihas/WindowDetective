/////////////////////////////////////////////////////////////////////
// File: ActionManager.h                                           //
// Date: 2010-06-21                                                //
// Desc: Creates actions for menu items and toolbar buttons.       //
/////////////////////////////////////////////////////////////////////

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

#ifndef ACTION_MANAGER_H
#define ACTION_MANAGER_H

#include <QtWidgets>
#include "window_detective/include.h"
#include "inspector/inspector.h"


/* TODO: Still needs work. If the WindowTree is making and displaying the
    menu, then what happens when SearchResultsDialog wants to display it's
    own menu? Perhaps this should be responsible for carrying out the
    actions, but it needs an object to operate on. That could be a Window,
    a tree item, or the main window.
    Also, window's context menu can have "More Actions >" item which will
    have a submenu of the additional actions returned by getMenuActions()

    See if QSignalMapper can do what i need.
     Use map of QActions again, no need for variables
     We know the MainWindow, so no need to pass that around
     Can use a mapping of triggered() to perhaps a specific function for each action
     Actions that operate on a particular object can dynamic_cast to it
*/

class Action : public QAction {
public:
    uint id;
    Action(uint id) : QAction(NULL), id(id) {}
};


/* Action types, used as the id of an Action */
enum ActionType {
    Separator,
    ActionViewProperties,
    ActionEditProperties,
    ActionViewMessages,
    ActionEditStyles,
    ActionFlashWindow,
    ActionShowWindow,
    ActionHideWindow,
    ActionCloseWindow,
    ActionShowInTree,
    ActionExpandAll
};


class ActionManager {
private:
    static QMap<ActionType,Action*> actions;

public:
    static void addAction(ActionType id, String name,
            char* shortcut = NULL, char* iconFileName = NULL);
    static void initialize();
    static void fillMenu(QMenu& menu, QList<ActionType> actionIds);
};


#endif   // ACTION_MANAGER_H
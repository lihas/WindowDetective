/////////////////////////////////////////////////////////////////////
// File: WindowTree.h                                            //
// Date: 2010-04-28                                                //
// Desc: Subclass of QTreeWidget to provide a custom widget for    //
//   displaying the window hierarchy.                              //
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

#ifndef WINDOW_TREE_H
#define WINDOW_TREE_H

#include <QtWidgets>
#include "window_detective/include.h"
#include "TreeItem.h"
#include "ui/ActionManager.h"
#include "inspector/inspector.h"


class MainWindow;  // Forward declaration

enum TreeType {
    WindowTreeType,
    ProcessTreeType
};


class WindowTree : public QTreeWidget {
    Q_OBJECT
private:
    TreeType type;
    bool columnResizeDisabled; // Optimisation: disable when expanding all items
    QMenu windowMenu;          // Context menu for window items
    QMenu processMenu;         // Context menu for process items
public:
    WindowTree(QWidget* parent = 0);
    ~WindowTree() {}

    void setType(TreeType type) {this->type = type;}
    TreeType getType() {return this->type;}
    void buildHeader();
    void rebuild();
    void rebuild(TreeType type) {setType(type); rebuild();}
    void addWindowChildren(WindowItem*);
    void addProcessChildren(ProcessItem*, const WindowList&);
    WindowItem* findWindowItem(Window* window);
    ProcessItem* findProcessItem(Process* process);
    bool hasItem(TreeItem* item);
    WindowList getSelectedWindows();
    ProcessList getSelectedProcesses();
    void expandAll();
    void expandSelected();
    void resizeAllColumns();
    void beginExpanding() {columnResizeDisabled=true;}
    void endExpanding() {columnResizeDisabled=false;resizeAllColumns();}
protected slots:
    void insertNewWindow(Window* window);
    void removeWindow(Window* window);
    void insertNewProcess(Process* process);
    void removeProcess(Process* process);
    void treeItemExpanded(QTreeWidgetItem* item);
};


#endif   // WINDOW_TREE_H
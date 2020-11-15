/////////////////////////////////////////////////////////////////////
// File: WindowTree.cpp                                            //
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


#include "WindowTree.h"
#include "ui/MainWindow.h"
#include "inspector/WindowManager.h"


/******************/
/*** WindowTree ***/
/******************/

WindowTree::WindowTree(QWidget *parent) :
    QTreeWidget(parent),
    type(WindowTreeType),
    columnResizeDisabled(false),
    windowMenu(), processMenu() {
    setSelectionMode(QAbstractItemView::ExtendedSelection);

    WindowManager* manager = &WindowManager::current();
    connect(manager, SIGNAL(windowAdded(Window*)), this, SLOT(insertNewWindow(Window*)));
    connect(manager, SIGNAL(windowRemoved(Window*)), this, SLOT(removeWindow(Window*)));
    connect(manager, SIGNAL(processAdded(Process*)), this, SLOT(insertNewProcess(Process*)));
    connect(manager, SIGNAL(processRemoved(Process*)), this, SLOT(removeProcess(Process*)));
    connect(this, SIGNAL(itemExpanded(QTreeWidgetItem*)), this, SLOT(treeItemExpanded(QTreeWidgetItem*)));
}

void WindowTree::buildHeader() {
    QStringList labels;
    if (type == WindowTreeType) {
        labels << tr("Window");
    }
    else if (type == ProcessTreeType) {
        labels << tr("Window/Process");
    }
    labels << tr("Handle") << tr("Text") << tr("Dimensions");
    setColumnCount(4);
    setHeaderLabels(labels);
}

/*--------------------------------------------------------------------------+
| Rebuilds the tree according to the set type. Note: window data            |
| should be refreshed before this methods is called.                        |
+--------------------------------------------------------------------------*/
void WindowTree::rebuild() {
    WindowManager& manager = WindowManager::current();
    ProcessItem* processItem;

    clear();
    buildHeader();
    if (type == WindowTreeType) {
        WindowItem* top = new WindowItem(manager.getDesktopWindow(), this);
        top->setExpanded(true);
        addWindowChildren(top);
    }
    else if (type == ProcessTreeType) {
        WindowList topWindows = manager.getDesktopWindow()->getChildren();
        for (int i = 0; i < manager.allProcesses.size(); ++i) {
            processItem = new ProcessItem(manager.allProcesses[i], this);
            addProcessChildren(processItem, topWindows);
        }
    }
    resizeAllColumns();
}

/*--------------------------------------------------------------------------+
| Recursively adds window children to the tree.                             |
+--------------------------------------------------------------------------*/
void WindowTree::addWindowChildren(WindowItem* item) {
    WindowList children = item->getWindow()->getChildren();

    WindowList::const_iterator i;
    for (i = children.begin(); i != children.end(); ++i) {
        // Note: Parent item takes ownership of new item (see Qt docs)
        addWindowChildren(new WindowItem(*i, item));
    }
}
/*--------------------------------------------------------------------------+
| Recursively adds a process's top-level windows and their                  |
| children to the tree.                                                     |
+--------------------------------------------------------------------------*/
void WindowTree::addProcessChildren(ProcessItem* item,
                        const WindowList& allTopWindows) {
    WindowList topWindows;
    WindowList::const_iterator i;

    // Find all top-level windows owned by the process
    for (i = allTopWindows.begin(); i != allTopWindows.end(); ++i) {
        if ((*i)->getProcess() == item->getProcess()) {
            // Note: Parent item takes ownership of new item (see Qt docs)
            addWindowChildren(new WindowItem(*i, item));
        }
    }
}

/*--------------------------------------------------------------------------+
| Recursively searches all tree items to find one with the given            |
| window. Returns NULL if it can't find one.                                |
+--------------------------------------------------------------------------*/
WindowItem* findWindowItemRecursive(QTreeWidgetItem* item, Window* window) {
    WindowItem* windowItem = dynamic_cast<WindowItem*>(item);

    // Check if this item is the one we're looking for
    if (windowItem && (windowItem->getWindow() == window))
        return windowItem;

    // Now recursively check all children
    WindowItem* result = NULL;
    for (int i = 0; i < item->childCount(); ++i) {
        result = findWindowItemRecursive(item->child(i), window);
        if (result) return result;
    }
    return NULL;
}
WindowItem* WindowTree::findWindowItem(Window* window) {
    if (!window) return NULL;
    QTreeWidgetItem* root = invisibleRootItem();
    return findWindowItemRecursive(root, window);
}

/*--------------------------------------------------------------------------+
| Recursively searches all tree items to find one with the given            |
| process. Returns NULL if it can't find one.                               |
+--------------------------------------------------------------------------*/
ProcessItem* findProcessItemRecursive(QTreeWidgetItem* item, Process* process) {
    ProcessItem* processItem = dynamic_cast<ProcessItem*>(item);

    // Check if this item is the one we're looking for
    if (processItem && processItem->getProcess() == process)
        return processItem;

    // Now recursively check all children
    ProcessItem* result = NULL;
    for (int i = 0; i < item->childCount(); ++i) {
        result = findProcessItemRecursive(item->child(i), process);
        if (result) return result;
    }
    return NULL;
}
ProcessItem* WindowTree::findProcessItem(Process* process) {
    if (!process) return NULL;
    QTreeWidgetItem* root = invisibleRootItem();
    return findProcessItemRecursive(root, process);
}

/*--------------------------------------------------------------------------+
| Recursively searches all tree items to find the one given.                |
| Returns true if it is found, false if not.                                |
+--------------------------------------------------------------------------*/
bool hasItemRecursive(QTreeWidgetItem* currentItem, TreeItem* itemToFind) {
    // Check if this item is the one we're looking for
    if (currentItem == itemToFind)
        return true;

    // Now recursively check all children
    bool result = false;
    for (int i = 0; i < currentItem->childCount(); ++i) {
        result = hasItemRecursive(currentItem->child(i), itemToFind);
        if (result) return result;
    }
    return false;
}
bool WindowTree::hasItem(TreeItem* item) {
    QTreeWidgetItem* root = invisibleRootItem();
    return hasItemRecursive(root, item);
}

/*--------------------------------------------------------------------------+
| Returns the window objects of the currently selected items. If no         |
| item is selected, or it is not a window item, NULL is returned.           |
+--------------------------------------------------------------------------*/
WindowList WindowTree::getSelectedWindows() {
    WindowList windows;
    WindowItem* windowItem = NULL;
    Window* window;

    foreach (QTreeWidgetItem* item, selectedItems()) {
        windowItem = dynamic_cast<WindowItem*>(item);
        if (windowItem) {
            window = windowItem->getWindow();
            if (window) windows.append(window);
        }
    }
    return windows;
}

/*--------------------------------------------------------------------------+
| Returns the process objects of the currently selected items. If no        |
| item is selected, or it is not a process item, NULL is returned.          |
+--------------------------------------------------------------------------*/
ProcessList WindowTree::getSelectedProcesses() {
    ProcessList processes;
    ProcessItem* processItem = NULL;
    Process* process;

    foreach (QTreeWidgetItem* item, selectedItems()) {
        processItem = dynamic_cast<ProcessItem*>(item);
        if (processItem) {
            process = processItem->getProcess();
            if (process) processes.append(process);
        }
    }
    return processes;
}

void WindowTree::insertNewWindow(Window* window) {
    TreeItem* parentItem = NULL;
    WindowManager& manager = WindowManager::current();

    if (type == WindowTreeType) {
        parentItem = findWindowItem(window->getParent());
        if (!parentItem) return;
    }
    else if (type == ProcessTreeType) {
        // Check if it's a top-level window
        if (window->getParent() == manager.getDesktopWindow()) {
            parentItem = findProcessItem(window->getProcess());
        }
        else {
            parentItem = findWindowItem(window->getParent());
        }
        if (!parentItem) return;

    }
    // Note: parentItem takes ownership of new item (see Qt docs)
    WindowItem* item = new WindowItem(window, parentItem);
    item->update(WindowCreated);
}

void WindowTree::removeWindow(Window* window) {
    WindowItem* item = findWindowItem(window);
    if (!item) return;

    item->update(WindowDestroyed);
}

void WindowTree::insertNewProcess(Process* process) {
    if (type != ProcessTreeType) return;

    // Note: This tree takes ownership of new item (see Qt docs)
    new ProcessItem(process, this);
}

void WindowTree::removeProcess(Process* process) {
    if (type != ProcessTreeType) return;

    ProcessItem* item = findProcessItem(process);
    if (!item) return;

    item->update(WindowDestroyed);
}

/*--------------------------------------------------------------------------+
| Expand all items and their children.                                      |
+--------------------------------------------------------------------------*/
void WindowTree::expandAll() {
    TreeItem* item = dynamic_cast<TreeItem*>(invisibleRootItem());
    if (item) item->expandAllChildren();
}

/*--------------------------------------------------------------------------+
| Expand the selected items and their children.                             |
+--------------------------------------------------------------------------*/
void WindowTree::expandSelected() {
    foreach (QTreeWidgetItem* qItem, selectedItems()) {
      TreeItem* item = dynamic_cast<TreeItem*>(qItem);
      item->expandAllChildren();
    }
}

/*--------------------------------------------------------------------------+
| Resize all columns to fit their contents. Temporarily limit the           |
| maximum width of each column to 300 so that we don't end up with          |
| extremely wide columns (user is free to make them bigger though).         |
+--------------------------------------------------------------------------*/
void WindowTree::resizeAllColumns() {
    for (int i = 0; i < columnCount(); ++i) {
        resizeColumnToContents(i);
        if (columnWidth(i) > 300) {
            setColumnWidth(i, 300);
        }
    }
}

/*--------------------------------------------------------------------------+
| When an item is expanded, resize the first column to fit it's             |
| children in view.                                                         |
+--------------------------------------------------------------------------*/
void WindowTree::treeItemExpanded(QTreeWidgetItem*) {
    // If all items are expanding, we don't want to resize *every* time
    if (!columnResizeDisabled)
        resizeAllColumns();
}

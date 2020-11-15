/////////////////////////////////////////////////////////////////////
// File: TreeItem.cpp                                              //
// Date: 2010-03-12                                                //
// Desc: Represents an item in the window hierarchy tree.          //
//   Two subclasses are defined: ProcessItem for process objects   //
//   and WindowItem for window objects. Each display their own     //
//   info and have their own context menu.                         //
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

#include "TreeItem.h"
#include "WindowTree.h"
#include "window_detective/Settings.h"
#include "window_detective/Logger.h"
#include "window_detective/StringFormatter.h"


// Remember the default foreground and background colours of tree
// items so that we can restore them after highlighting
QBrush* TreeHighlight::defaultForeground = NULL;
QBrush* TreeHighlight::defaultBackground = NULL;


/*********************/
/*** TreeHighlight ***/
/*********************/

TreeHighlight::TreeHighlight(TreeItem* item, UpdateReason reason) :
    item(item),
    reason(reason),
    timer() {
    timer.setSingleShot(true);
    connect(&timer, SIGNAL(timeout()), this, SLOT(unhighlight()));

    // Remember old values if we haven't already
    if (!TreeHighlight::defaultForeground)
        TreeHighlight::defaultForeground = new QBrush(item->foreground(0));
    if (!TreeHighlight::defaultBackground)
        TreeHighlight::defaultBackground = new QBrush(item->background(0));
}

void TreeHighlight::highlight(bool isImmediate) {
    switch (reason) {
      case WindowChanged: {
          QFont highlightFont = item->font(0);
          highlightFont.setBold(true);
          item->setFont(0, highlightFont);
          item->setForeground(0, QBrush(isImmediate ?
                        Settings::itemChangedColourImmediate :
                        Settings::itemChangedColourUnexpanded));
          break;
      }
      case WindowCreated: {
          item->setBackground(0, QBrush(isImmediate ?
                        Settings::itemCreatedColourImmediate :
                        Settings::itemCreatedColourUnexpanded));
          break;
      }
      case WindowDestroyed: {
          item->setBackground(0, QBrush(isImmediate ?
                        Settings::itemDestroyedColourImmediate :
                        Settings::itemDestroyedColourUnexpanded));
          break;
      }
      default: {
          Logger::debug(TR("Invalid highlight reason: %1").arg(reason));
      }
    }
    timer.start(Settings::treeChangeDuration);
}

TreeHighlight::~TreeHighlight() {
    unhighlight();
}

/*--------------------------------------------------------------------------+
| Restore the item's style to what it previously was. It tries to           |
| only restore what is changed (i.e. font), since there may still           |
| be other highlights on the item.                                          |
+--------------------------------------------------------------------------*/
void TreeHighlight::unhighlight() {
    // TODO: For some reason, items sometimes are not unhighlighted when
    //   they should be. Perhaps the tree needs to be notified/updated?
    switch (reason) {
      case WindowChanged: {
          QFont highlightFont = item->font(0);
          highlightFont.setBold(false);
          item->setFont(0, highlightFont);
          item->setForeground(0, *defaultForeground);
          break;
      }
      case WindowCreated:
      case WindowDestroyed: {
          item->setBackground(0, *defaultBackground);
          break;
      }
      default: {
          Logger::debug(TR("Invalid highlight reason: %1").arg(reason));
      }
    }
}


/****************/
/*** TreeItem ***/
/****************/

/*--------------------------------------------------------------------------+
| Destructor.                                                               |
+--------------------------------------------------------------------------*/
TreeItem::~TreeItem() {
    if (updateHighlighter) {
        delete updateHighlighter;
        updateHighlighter = NULL;
    }
    if (createHighlighter) {
        delete createHighlighter;
        createHighlighter = NULL;
    }
    if (destroyHighlighter) {
        delete destroyHighlighter;
        destroyHighlighter = NULL;
    }
    if (deletionTimer) {
        delete deletionTimer;
        deletionTimer = NULL;
    }
}

/*--------------------------------------------------------------------------+
| Sets up common properties for all subclasses.                             |
+--------------------------------------------------------------------------*/
void TreeItem::initialize() {
    updateHighlighter = NULL;
    createHighlighter = NULL;
    destroyHighlighter = NULL;
    deletionTimer = NULL;
    //setSizeHint(0, QSize(-1, 17)); // These seems to break auto-column-expand
    setupData();
}

// TODO: Optimisation. Only update data if item is visible. If not visible,
// set a flag then update next time it's shown
void TreeItem::update(UpdateReason reason) {
    if (reason == WindowDestroyed) {
        // We can't delete this object when it is unhighlighted since it may be
        // the parent which gets highlighted. So we need this separate timer.
        deletionTimer = new QTimer();
        deletionTimer->setSingleShot(true);
        connect(deletionTimer, SIGNAL(timeout()), this, SLOT(deleteLater()));
        deletionTimer->start(Settings::treeChangeDuration);
    }
    else {
        setupData();
    }

    if (reason != MinorChange)
        highlightVisible(reason);
}

/*--------------------------------------------------------------------------+
| Returns this item's ancestor, that is, it's top-level parent.             |
+--------------------------------------------------------------------------*/
TreeItem* TreeItem::ancestor() {
    TreeItem* parent = (TreeItem*)(((QTreeWidgetItem*)this)->parent());
    return parent ? parent->ancestor() : this;
}

/*--------------------------------------------------------------------------+
| Recursively expands all children of this item.                            |
+--------------------------------------------------------------------------*/
void recursivelyExpandItem(QTreeWidgetItem* item, int level) {
    if (level > MAX_EXPAND_LEVEL) return;
    item->setExpanded(true);
    for (int i = 0; i < item->childCount(); ++i) {
        recursivelyExpandItem(item->child(i), level+1);
    }
}
void TreeItem::expandAllChildren() {
    WindowTree* tree = dynamic_cast<WindowTree*>(treeWidget());
    if (tree) tree->beginExpanding();
    recursivelyExpandItem(this, 0);
    if (tree) tree->endExpanding();
}

/*--------------------------------------------------------------------------+
| Recursively expands each ancestor of this item.                           |
| Used to locate this item in the tree.                                     |
+--------------------------------------------------------------------------*/
void recursivelyExpandAncestor(QTreeWidgetItem* child) {
    QTreeWidgetItem* parent = child->parent();
    if (parent) {
        parent->setExpanded(true);
        recursivelyExpandAncestor(parent);
    }
}
void TreeItem::expandAncestors() {
    WindowTree* tree = dynamic_cast<WindowTree*>(treeWidget());
    if (tree) tree->beginExpanding();
    recursivelyExpandAncestor(this);
    if (tree) tree->endExpanding();
}

/*--------------------------------------------------------------------------+
| Highlights this item using a style based on the given reason              |
| and whether it is the immeditae item or an ancestor of it.                |
| The style is removed after a short period.                                |
+--------------------------------------------------------------------------*/
void TreeItem::highlight(UpdateReason reason, bool isImmediate) {
    switch (reason) {
      case WindowChanged: {
          if (!updateHighlighter)
              updateHighlighter = new TreeHighlight(this, reason);
          updateHighlighter->highlight(isImmediate);
          break;
      }
      case WindowCreated: {
          if (!createHighlighter)
              createHighlighter = new TreeHighlight(this, reason);
          createHighlighter->highlight(isImmediate);
          break;
      }
      case WindowDestroyed: {
          if (!destroyHighlighter)
              destroyHighlighter = new TreeHighlight(this, reason);
          destroyHighlighter->highlight(isImmediate);
          break;
      }
      default: {
          Logger::debug(TR("Invalid highlight reason: %1").arg(reason));
      }
    }
}

/*--------------------------------------------------------------------------+
| Walks up the tree until it reaches the top-level item then                |
| highlights either this item if it's visible (i.e. all ancestors           |
| are expanded) or the closest visible ancestor of this.                    |
+--------------------------------------------------------------------------*/
int recusriveHighlightVisible(TreeItem* baseItem,
                              TreeItem* currentItem,
                              UpdateReason reason) {
    TreeItem* parent = (TreeItem*)(((QTreeWidgetItem*)currentItem)->parent());

    int result = parent ? recusriveHighlightVisible(baseItem,parent,reason) : 1;
    if (result == -1) {
        return -1;      // -1 means we're done, just continue up the stack
    }
    else if (result) {
        if (currentItem == baseItem) {
            currentItem->highlight(reason, true);
            return -1;
        }
        else {
            return (int)currentItem->isExpanded();
        }
    }
    else {
        parent->highlight(reason, false);
        return -1;
    }
}
void TreeItem::highlightVisible(UpdateReason reason) {
    recusriveHighlightVisible(this, this, reason);
}


/*******************/
/*** ProcessItem ***/
/*******************/

/*--------------------------------------------------------------------------+
| ProcessItem constructors                                                  |
+--------------------------------------------------------------------------*/
ProcessItem::ProcessItem() :
    TreeItem(ProcessItemType) {
}
ProcessItem::ProcessItem(Process* process, QTreeWidget* parent) :
    TreeItem(parent, ProcessItemType),
    process(process) {
    initialize();
}
ProcessItem::ProcessItem(Process* process, QTreeWidgetItem* parent) :
    TreeItem(parent, ProcessItemType),
    process(process) {
    initialize();
}

void ProcessItem::setupData() {
    // First column: process name and icon
    setText(0, process->getName());
    setIcon(0, process->getIcon());
    setToolTip(0, tooltipText());

    // Second column: process id
    setText(1, String::number(process->getId()));

    // Everything else is blank as it is not relevant
}

String ProcessItem::tooltipText() {
    return process->getFilePath();
}


/******************/
/*** WindowItem ***/
/******************/

/*--------------------------------------------------------------------------+
| WindowItem constructors                                                   |
+--------------------------------------------------------------------------*/
WindowItem::WindowItem() :
    TreeItem(WindowItemType) {
}
WindowItem::WindowItem(Window* window, QTreeWidget* parent) :
    TreeItem(parent, WindowItemType),
    window(window) {
    initialize();
}
WindowItem::WindowItem(Window* window, QTreeWidgetItem* parent) :
    TreeItem(parent, WindowItemType),
    window(window) {
    initialize();
}

void WindowItem::initialize() {
    TreeItem::initialize();
    connect(window, SIGNAL(updated(UpdateReason)), this, SLOT(update(UpdateReason)));
}

/*--------------------------------------------------------------------------+
| Sets the item's properties from the window model.                         |
+--------------------------------------------------------------------------*/
void WindowItem::setupData() {
    // First column: window class name and icon
    setText(0, window->getClassDisplayName());
    setIcon(0, window->getIcon());
    setToolTip(0, tooltipText());

    if (Settings::greyHiddenWindows && !window->isVisible()) {
        setForeground(0, QBrush(HIDDEN_WINDOW_COLOUR));
        setIcon(0, QIcon(window->getIcon().pixmap(16, QIcon::Disabled)));
    }

    // TODO: Make it possible to control what columns are shown, so different tree views
    // in the UI can shown different columns.
    /*Process* process = window->getProcess();
    if (process) {
        setText(1, process->getName());
        setIcon(1, process->getIcon());
    }
    else {
        setText(1, "<unknown>");
    }*/

    // Second column: window handle
    setText(1, stringLabel(window->getHandle()));

    // Third column: window title/text
    String text = window->getText();
    if (text.length() > 200) {
        text = text.left(200) + "...";
    }
    setText(2, text.simplified());

    // Forth column: window dimensions
    setText(3, stringLabel(window->getDimensions()));
}

/*--------------------------------------------------------------------------+
| Constructs a HTML string for use as the item's tooltip.                   |
+--------------------------------------------------------------------------*/
String WindowItem::tooltipText() {
    String tooltipString;
    QTextStream stream(&tooltipString);

    stream << "<html><table><tr><td><b>Class:</b></td><td>"
           << window->getWindowClass()->getDisplayName()
           << "<td><tr><td><b>Handle:</b></td><td>"
           << hexString((uint)window->getHandle())
           << "</td>";
    if (!window->getText().isEmpty()) {
        String text = window->getText();
        if (text.length() > 200) {
            text = text.left(200) + "...";
        }
        stream << "<tr><td><b>Text:</b></td><td>"
               << htmlLabel(text.simplified()) << "<td>";
    }
    stream << "</tr></table>";
    if (!window->isVisible()) {
        stream << "<br/>Window is not visible";
    }
    if (window->getChildren().size() > 0) {
        stream << "<br/>Has " << String::number(window->getChildren().size())
               << " immediate children";
    }
    stream << "<br/>Window is " << String(window->isUnicode() ? "Unicode" : "ANSI")
           << "</html>";

    return tooltipString;
}

/////////////////////////////////////////////////////////////////////
// File: SearchResultsDialog.cpp                                   //
// Date: 2010-06-22                                                //
// Desc: A window to display the results of a search. The results  //
//   are shown in a list with columns similar to that in the       //
//   hierarchy tree. A summary of the search criteria is also      //
//   displayed.                                                    //
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

#include "SearchResultsDialog.h"
#include "inspector/inspector.h"
#include "inspector/WindowManager.h"
#include "inspector/SearchCriteria.h"
#include "ui/MainWindow.h"


SearchResultsDialog::SearchResultsDialog(MainWindow* mainWindow, QWidget* parent) :
    QDialog(parent), mainWindow(mainWindow) {
    setupUi(this);

    windowList->setContextMenuPolicy(Qt::CustomContextMenu);

    // TODO: Make some sort of "column manager" which allows users to customise
    //  the columns here and in the trees (either separately or as one).
    QStringList columnLabels;
    columnLabels << "Window" << "Handle" << "Text" << "Dimensions";
    windowList->setColumnCount(4);
    windowList->setHeaderLabels(columnLabels);

    connect(windowList, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(showMenu(const QPoint&)));
    connect(repeatButton, SIGNAL(clicked()), this, SLOT(repeatButtonClicked()));
    connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
    buildMenu();
}

void SearchResultsDialog::openOn(WindowList windows, SearchCriteria searchCriteria) {
    this->searchCriteria = searchCriteria;
    populateResultsList(windows);
    show();
}

void SearchResultsDialog::buildMenu() {
    QList<ActionType> actions;
    actions
        << ActionShowInTree
        << Separator
        << ActionViewProperties
        << ActionEditProperties
        << ActionViewMessages
        << Separator
        << ActionEditStyles
        << Separator
        << ActionFlashWindow
        << ActionShowWindow
        << ActionHideWindow
        << Separator
        << ActionCloseWindow;
    ActionManager::fillMenu(contextMenu, actions);
}

void SearchResultsDialog::populateResultsList(WindowList& windows) {
    // "Abuse" the QTreeWidget by only using top-level items to make it
    // look like a list view with columns.
    windowList->clear();

    WindowList::const_iterator i;
    for (i = windows.begin(); i != windows.end(); ++i) {
        // Note: Tree widget takes ownership of new item (see Qt docs)
        new WindowItem(*i, windowList);
    }
    windowList->resizeAllColumns();

    setWindowTitle(String(APP_NAME) + " - Found " + String::number(windows.size()) + " windows");
    String criteriaString;
    QTextStream stream(&criteriaString);
    stream << "Search Criteria:\n" << searchCriteria;
    criteriaLabel->setText(criteriaString);
}

/*--------------------------------------------------------------------------+
| Displays the context menu and executes the action on the selected         |
| window/s. This is mostly duplicated from MainWindow (yuk!).               |
+--------------------------------------------------------------------------*/
void SearchResultsDialog::showMenu(const QPoint& /*unused*/) {
    if (!mainWindow) return;

    Action* action = dynamic_cast<Action*>(contextMenu.exec(QCursor::pos()));
    if (!action) return;      // User cancelled

    WindowList selectedWindows = windowList->getSelectedWindows();
    if (selectedWindows.isEmpty()) return; // Nothing selected

    switch (action->id) {
      case ActionShowInTree: {
          if (selectedWindows.isEmpty()) return;
          mainWindow->locateWindowInTree(selectedWindows.first());
          break;
      }
      case ActionViewProperties: {
          mainWindow->viewWindowProperties(selectedWindows);
          break;
      }
      case ActionEditProperties: {
          if (selectedWindows.isEmpty()) return;
          mainWindow->editWindowProperties(selectedWindows.first());
          break;
      }
      case ActionViewMessages: {
          mainWindow->viewWindowMessages(selectedWindows);
          break;
      }
      case ActionEditStyles: {
          if (selectedWindows.isEmpty()) return;
          mainWindow->editWindowStyles(selectedWindows.first());
          break;
      }
      case ActionFlashWindow: {
          if (selectedWindows.isEmpty()) return;
          selectedWindows.first()->flash();
          break;
      }
      case ActionShowWindow: {
          WindowList::const_iterator i;
          for (i = selectedWindows.begin(); i != selectedWindows.end(); ++i) {
              (*i)->show();
          }
          break;
      }
      case ActionHideWindow: {
          WindowList::const_iterator i;
          for (i = selectedWindows.begin(); i != selectedWindows.end(); ++i) {
              (*i)->hide();
          }
          break;
      }
      case ActionCloseWindow: {
          WindowList::const_iterator i;
          for (i = selectedWindows.begin(); i != selectedWindows.end(); ++i) {
              (*i)->close();
          }
          break;
      }
    }
}

/*--------------------------------------------------------------------------+
| Runs the search again and re-populates the list with the results.         |
+--------------------------------------------------------------------------*/
void SearchResultsDialog::repeatButtonClicked() {
    WindowList foundWindows = WindowManager::current().find(searchCriteria);
    populateResultsList(foundWindows);
}
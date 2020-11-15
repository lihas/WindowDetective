/////////////////////////////////////////////////////////////////////
// File: SearchResultsDialog.h                                     //
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

#ifndef SEARCH_RESULTS_PANE_H
#define SEARCH_RESULTS_PANE_H

#include <QtWidgets>
#include "window_detective/include.h"
#include "ui/forms/ui_SearchResultsDialog.h"
#include "inspector/inspector.h"
#include "inspector/SearchCriteria.h"
#include "ui/custom_widgets/TreeItem.h"


class MainWindow;  // Forward declaration

class SearchResultsDialog : public QDialog, private Ui::SearchResultsDialog {
    Q_OBJECT
private:
    MainWindow* mainWindow;
    QMenu contextMenu;
    SearchCriteria searchCriteria;
public:
    SearchResultsDialog(MainWindow* mainWindow, QWidget* parent = 0);
    ~SearchResultsDialog() {}

    void openOn(WindowList windows, SearchCriteria searchCriteria);
private:
    void buildMenu();
    void populateResultsList(WindowList& windows);
private slots:
    void showMenu(const QPoint& pos);
    void repeatButtonClicked();
};


#endif   // SEARCH_RESULTS_PANE_H
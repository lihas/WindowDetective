/////////////////////////////////////////////////////////////////////
// File: ListViewPropertyPage.h                                  //
// Date: 2011-03-13                                                //
// Desc: The property page for ListView controls. Displays         //
//   properties of the control itself as well as properties of     //
//   each item.                                                    //
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

#ifndef LIST_VIEW_PROPERTY_PAGE_H
#define LIST_VIEW_PROPERTY_PAGE_H

#include <QtWidgets>
#include "window_detective/include.h"
#include "inspector/inspector.h"
#include "AbstractPropertyPage.h"


class ListViewPropertyPage : public AbstractPropertyPage {
    Q_OBJECT
private:
    ListView* model;
    QLabel* exLvStyleBitsWidget;
    QLabel* exLvStylesWidget;
    QLabel* numberOfItemsWidget;
    QLabel* numberOfItemsPerPageWidget;
    QLabel* numberOfSelectedItemsWidget;
    QTableWidget* listWidget;

public:
    ListViewPropertyPage(ListView* model, QWidget* parent = 0);
    ~ListViewPropertyPage() {}

    void setupUi();
    void addListItem(int index, const ListViewItem& item);
    void addTableColumn(int row, int column, String data);
    void resizeTable();
    void updateProperties();
};


#endif   // LIST_VIEW_PROPERTY_PAGE_H
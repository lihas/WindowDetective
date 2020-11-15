/////////////////////////////////////////////////////////////////////
// File: ListBoxPropertyPage.h                                   //
// Date: 2011-01-28                                                //
// Desc: The property page for ListBox controls. Displays specific //
//   properties and lists all items of the list box.               //
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

#ifndef LIST_BOX_PROPERTY_PAGE_H
#define LIST_BOX_PROPERTY_PAGE_H

#include <QtWidgets>
#include "window_detective/include.h"
#include "inspector/inspector.h"
#include "AbstractPropertyPage.h"


class ListBoxPropertyPage : public AbstractPropertyPage {
    Q_OBJECT
private:
    ListBox* model;
    QLabel* numberOfItemsWidget;
    QLabel* numberOfSelectedItemsWidget;
    QLabel* isOwnerDrawnWidget;
    QTableWidget* listWidget;

public:
    ListBoxPropertyPage(ListBox* model, QWidget* parent = 0);
    ~ListBoxPropertyPage() {}

    void setupUi();
    void addListItem(int index, const ListBoxItem& item);
    void addTableColumn(int row, int column, String data);
    void resizeTable();
    void updateProperties();
};


#endif   // LIST_BOX_PROPERTY_PAGE_H
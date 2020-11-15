/////////////////////////////////////////////////////////////////////
// File: TabPropertyPage.h                                       //
// Date: 2011-08-02                                                //
// Desc: The property page for Tab controls.                       //
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

#ifndef TAB_PROPERTY_PAGE_H
#define TAB_PROPERTY_PAGE_H

#include <QtWidgets>
#include "window_detective/include.h"
#include "inspector/inspector.h"
#include "AbstractPropertyPage.h"


class TabPropertyPage : public AbstractPropertyPage {
    Q_OBJECT
private:
    Tab* model;
    QLabel* numberOfItemsWidget;
    QLabel* selectedIndexWidget;
    QLabel* focusIndexWidget;
    QTableWidget* listWidget;

public:
    TabPropertyPage(Tab* model, QWidget* parent = 0);
    ~TabPropertyPage() {}

    void setupUi();
    void addListItem(int index, const TabItem& item);
    void addTableColumn(int row, int column, String data);
    void resizeTable();
    void updateProperties();
};


#endif   // TAB_PROPERTY_PAGE_H
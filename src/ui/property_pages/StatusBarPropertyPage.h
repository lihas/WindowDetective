/////////////////////////////////////////////////////////////////////
// File: StatusBarPropertyPage.h                                 //
// Date: 2011-08-04                                                //
// Desc: The property page for StatusBar controls.                 //
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

#ifndef STATUS_BAR_PROPERTY_PAGE_H
#define STATUS_BAR_PROPERTY_PAGE_H

#include <QtWidgets>
#include "window_detective/include.h"
#include "inspector/inspector.h"
#include "AbstractPropertyPage.h"


class StatusBarPropertyPage : public AbstractPropertyPage {
    Q_OBJECT
private:
    StatusBar* model;
    QLabel* numberOfPartsWidget;
    QLabel* horzBorderWidget;
    QLabel* vertBorderWidget;
    QLabel* paddingWidget;
    QTableWidget* listWidget;

public:
    StatusBarPropertyPage(StatusBar* model, QWidget* parent = 0);
    ~StatusBarPropertyPage() {}

    void setupUi();
    void addListItem(int index, const StatusBarPart& item);
    void addTableColumn(int row, int column, String data);
    void resizeTable();
    void updateProperties();
};


#endif   // STATUS_BAR_PROPERTY_PAGE_H
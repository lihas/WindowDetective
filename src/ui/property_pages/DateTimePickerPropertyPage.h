/////////////////////////////////////////////////////////////////////
// File: DateTimePickerPropertyPage.h                            //
// Date: 2011-06-10                                                //
// Desc: The property page for DateTimePicker controls.            //
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

#ifndef DATE_TIME_PICKER_PROPERTY_PAGE_H
#define DATE_TIME_PICKER_PROPERTY_PAGE_H

#include <QtWidgets>
#include "window_detective/include.h"
#include "inspector/inspector.h"
#include "AbstractPropertyPage.h"


class DateTimePickerPropertyPage : public AbstractPropertyPage {
    Q_OBJECT
private:
    DateTimePicker* model;
    QLabel* selectedTimeWidget;
    QLabel* minimumTimeWidget;
    QLabel* maximumTimeWidget;
    QLabel* idealSizeWidget;

public:
    DateTimePickerPropertyPage(DateTimePicker* model, QWidget* parent = 0);
    ~DateTimePickerPropertyPage() {}

    void setupUi();
    void updateProperties();
};


#endif   // DATE_TIME_PICKER_PROPERTY_PAGE_H
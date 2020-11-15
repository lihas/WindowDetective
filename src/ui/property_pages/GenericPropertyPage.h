/////////////////////////////////////////////////////////////////////
// File: GenericPropertyPage.h                                   //
// Date: 2011-01-25                                                //
// Desc: The property page for Window objects. Displays properties //
//    common to all windows.                                       //
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

#ifndef GENERIC_PROPERTY_PAGE_H
#define GENERIC_PROPERTY_PAGE_H

#include <QtWidgets>
#include "window_detective/include.h"
#include "inspector/inspector.h"
#include "AbstractPropertyPage.h"
#include "ui/custom_widgets/ScrollPropertyWidget.h"
#include "ui/custom_widgets/FontPropertyWidget.h"
#include "ui/custom_widgets/WindowPropWidget.h"


class GenericPropertyPage : public AbstractPropertyPage {
    Q_OBJECT
private:
    Window* model;
    QLabel* windowTextWidget;
    QLabel* handleWidget;
    QLabel* parentWidget;
    QLabel* ownerWidget;
    QLabel* dimensionsWidget;
    QLabel* positionWidget;
    QLabel* sizeWidget;
    QLabel* clientDimensionsWidget;
    QLabel* relativeDimensionsWidget;
    QLabel* styleBitsWidget;
    QLabel* stylesWidget;
    QLabel* exStyleBitsWidget;
    QLabel* exStylesWidget;
    ScrollPropertyWidget* hScrollWidget;
    ScrollPropertyWidget* vScrollWidget;
    FontPropertyWidget* fontWidget;
    WindowPropWidget* windowPropsWidget;
    QLabel* ownerProcessWidget;
    QLabel* ownerProcessIDWidget;
    QLabel* ownerThreadIDWidget;

public:
    GenericPropertyPage(Window* model, QWidget* parent = 0);
    ~GenericPropertyPage() {}

    void setupUi();
    void updateProperties();
};


#endif   // GENERIC_PROPERTY_PAGE_H
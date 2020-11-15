/////////////////////////////////////////////////////////////////////
// File: ScrollPropertyWidget.h                                  //
// Date: 2012-06-15                                                //
// Desc: Displays scroll bar properties for a window. If the model //
//   is NULL, this will just be a label.                           //
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

#ifndef SCROLL_PROPERTY_WIDGET_H
#define SCROLL_PROPERTY_WIDGET_H

#include <QtWidgets>
#include "window_detective/include.h"
#include "inspector/inspector.h"


class ScrollPropertyWidget : public QWidget {
    Q_OBJECT
private:
    WinScrollInfo* model;
    QFormLayout* formLayout;
    QLabel* basicWidget;
    QLabel* minWidget;
    QLabel* maxWidget;
    QLabel* posWidget;
    QLabel* pageWidget;

public:
    ScrollPropertyWidget(QWidget* parent = 0);

    WinScrollInfo* getModel() { return model; }
    void setModel(WinScrollInfo* info) { model = info; update(); }
    void destroyWidgets();
    void buildBasicUI();
    void buildFullUI();
    void update();
    void updateBasicUI();
    void updateFullUI();

    QLabel* makeValueLabel();
};


#endif   // SCROLL_PROPERTY_WIDGET_H
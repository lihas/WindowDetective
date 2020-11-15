/////////////////////////////////////////////////////////////////////
// File: BrushPropertyWidget.h                                   //
// Date: 2011-02-14                                                //
// Desc: Displays properties of a brush object. If that object is  //
//   NULL or the system brush, a simple line edit will display     //
//   that. Otherwise, a form layout will show the properties of    //
//   the object.                                                   //
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

#ifndef BRUSH_PROPERTY_WIDGET_H
#define BRUSH_PROPERTY_WIDGET_H

#include <QtWidgets>
#include "window_detective/include.h"
#include "inspector/inspector.h"

class BrushPropertyWidget : public QWidget {
    Q_OBJECT
private:
    WinBrush* model;
    QFormLayout* formLayout;
    QLabel* basicWidget;
    QLabel* handleWidget;
    QLabel* styleWidget;
    QLabel* colourWidget;
    QLabel* hatchWidget;

public:
    BrushPropertyWidget(QWidget* parent = 0);

    WinBrush* getModel() { return model; }
    void setModel(WinBrush* brush) { model = brush; update(); }
    void destroyWidgets();
    void buildBasicUI();
    void buildFullUI();
    void update();

    QLabel* makeValueLabel();
};

#endif   // BRUSH_PROPERTY_WIDGET_H
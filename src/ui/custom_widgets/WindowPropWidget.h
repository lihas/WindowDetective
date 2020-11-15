/////////////////////////////////////////////////////////////////////
// File: WindowPropWidget.h                                      //
// Date: 2011-02-17                                                //
// Desc: Displays a list of window user-set properties. These      //
//   properties are set by calling the SetProc API function.       //
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

#ifndef WINDOW_PROP_WIDGET_H
#define WINDOW_PROP_WIDGET_H

#include <QtWidgets>
#include "window_detective/include.h"
#include "inspector/inspector.h"


class WindowPropWidget : public QWidget {
    Q_OBJECT
private:
    WindowPropList model;
    QWidget* container;
    QVBoxLayout* containerLayout;

public:
    WindowPropWidget(QWidget* parent = 0);

    WindowPropList getModel() { return model; }
    void setModel(WindowPropList list) { model = list; update(); }
    void update();
};


#endif   // WINDOW_PROP_WIDGET_H
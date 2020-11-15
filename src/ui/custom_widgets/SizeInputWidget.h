/////////////////////////////////////////////////////////////////////
// File: SizeInputWidget.h                                         //
// Date: 2017-07-13                                                //
// Desc: Widget with two spin boxes to enter width and height      //
//   values. The value is stored and retrieved as a QSize.         //
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

#ifndef SIZE_INPUT_WIDGET_H
#define SIZE_INPUT_WIDGET_H

#include <QtWidgets>


class SizeInputWidget : public QWidget {
    Q_OBJECT
private:
    QSpinBox* xSpinBox;
    QSpinBox* ySpinBox;
    QLabel* middleLabel;

public:
    SizeInputWidget(QWidget* parent = 0);

    QSize value();
    void setValue(QSize size);
};


#endif   // SIZE_INPUT_WIDGET_H
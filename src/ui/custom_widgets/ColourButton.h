/////////////////////////////////////////////////////////////////////
// File: ColourButton.h                                          //
// Date: 2010-03-26                                                //
// Desc: A button which allows the user to pick a colour.          //
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

#ifndef COLOUR_BUTTON_H
#define COLOUR_BUTTON_H

#include <QtWidgets>
#include "window_detective/include.h"

class ColourButton : public QPushButton {
    Q_OBJECT
private:
    const static int PaddingHor;
    const static int PaddingVert;
    QColor colour;

public:
    ColourButton(QWidget* parent = 0);
    ~ColourButton() {}

    QColor getColour() { return colour; }
    void setColour(const QColor& c) { colour = c; }
protected:
    void paintEvent(QPaintEvent* e);
private slots:
    void showColourChooser();
};

#endif   // COLOUR_BUTTON_H
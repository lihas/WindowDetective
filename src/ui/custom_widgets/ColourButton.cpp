/////////////////////////////////////////////////////////////////////
// File: ColourButton.cpp                                          //
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


#include "ColourButton.h"

const int ColourButton::PaddingHor   = 10;
const int ColourButton::PaddingVert  = 5;

ColourButton::ColourButton(QWidget* parent) :
    QPushButton(parent),
    colour() {

    // Not sure if there is a better way of doing this (event maybe)
    connect(this, SIGNAL(clicked()), this, SLOT(showColourChooser()));
}

void ColourButton::showColourChooser() {
    QColor chosen = QColorDialog::getColor(colour, this, tr("Select colour"));
    if (chosen.isValid())
        colour = chosen;
}

void ColourButton::paintEvent(QPaintEvent* e) {
    // Paint the standard button first
    QPushButton::paintEvent(e);

    // Then paint a coloured rectangle
    if (colour.isValid()) {
        QPainter painter(this);
        QColor fillColour = colour;
        fillColour.setAlpha(255);    // We want full alpha when drawing
        painter.fillRect(PaddingHor, PaddingVert,
                width()-(PaddingHor*2), height()-(PaddingVert*2), fillColour);
    }
}

/////////////////////////////////////////////////////////////////////
// File: HexSpinBox.h                                            //
// Date: 2010-03-30                                                //
// Desc: Subclass of QSpinBox that handles the input of            //
//   hexadecimal (base 16) numbers as well as decimal.             //
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

#ifndef HEX_SPIN_BOX_H
#define HEX_SPIN_BOX_H

#include <QtWidgets>
#include "window_detective/include.h"

class HexSpinBox : public QSpinBox {
    Q_OBJECT
private:
    QValidator* validator;
    bool shouldDisplayAsHex;

public:
    HexSpinBox(QWidget *parent = 0);
    ~HexSpinBox();

    void displayAsHex(bool b) { shouldDisplayAsHex = b; }
protected:
    bool isHexString(const String& text) const;
    QValidator::State validate(String& text, int& pos) const;
    int valueFromText(const String& text) const;
    String textFromValue(int value) const;
};

#endif   // HEX_SPIN_BOX_H
/////////////////////////////////////////////////////////////////////
// File: WindowPicker.h                                          //
// Date: 2010-02-17                                                //
// Desc: A subclass of QWidget which is used for "picking" a       //
//   window to inspect. It captures mouse input when it is pressed //
//   and changes the cursor to a target. When the mouse button is  //
//   released, it releases mouse capture and gets the window under //
//   the cursor.                                                   //
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

#ifndef WINDOW_PICKER_H
#define WINDOW_PICKER_H

#include <QtWidgets>
#include "window_detective/include.h"
#include "inspector/inspector.h"
#include "ui/HighlightPane.h"


class WindowPicker : public QWidget {
    Q_OBJECT
private:
    static const int padding = 2; // Padding on each side
    QWidget* owner;               // Main window this belongs to
    QPixmap image;                // Image or "picker" cursor
    String pickerText;            // Text to display beside image
    bool isPressed;
public:
    HighlightPane highlighter;

public:
    WindowPicker(QWidget* parent = 0, QWidget* owner = 0);

    QSize minimumSizeHint() const;
signals:
    void windowPicked(Window*);
protected:
    void mousePressed();
    void mouseReleased();
    bool nativeEvent(const QByteArray &eventType, void* message, long* result);
    void paintEvent(QPaintEvent*);
};


#endif   // WINDOW_PICKER_H
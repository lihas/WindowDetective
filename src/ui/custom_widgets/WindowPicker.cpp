/////////////////////////////////////////////////////////////////////
// File: WindowPicker.cpp                                          //
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

#include "window_detective/main.h"
#include "inspector/WindowManager.h"
#include "window_detective/Settings.h"
#include "WindowPicker.h"


WindowPicker::WindowPicker(QWidget* parent, QWidget* owner) :
    QWidget(parent),
    owner(owner),
    highlighter(true),
    isPressed(false) {
    setAttribute(Qt::WA_NativeWindow);
    pickerText = tr("Pick window");
    image.load(":/img/picker.png");
    highlighter.create();
}

QSize WindowPicker::minimumSizeHint() const {
    QRect textRect = fontMetrics().boundingRect(pickerText);

    // Width: padding both sides, image and text with 2x padding in between
    // Height: 24, unless text hight is bigger
    return QSize(image.width() + (padding * 4) + textRect.width(),
                 qMax(textRect.height(), 24));
}

Window* windowUnderCursor() {
    QPoint p = QCursor::pos();
    return WindowManager::current().getWindowAt(p);
}


/**********************/
/*** Event handlers ***/
/**********************/

void WindowPicker::mousePressed() {
    isPressed = true;
    update();
    showPickerCursor();
    if (owner && Settings::hideWhilePicking)
        owner->hide();
    SetCapture((HWND)this->winId());
}

void WindowPicker::mouseReleased() {
    isPressed = false;
    ReleaseCapture();
    restoreCursor();
    highlighter.hide();
    if (owner && Settings::hideWhilePicking)
        owner->show();
    update();
}

/*--------------------------------------------------------------------------+
| Handling native Windows messages gives us more control,                   |
| especially with capturing the mouse, somthing that Qt does                |
| automatically in it's own events.                                         |
+--------------------------------------------------------------------------*/
bool WindowPicker::nativeEvent(const QByteArray &eventType, void* msg, long* result) {
    MSG* winMsg = (MSG*)msg;
    switch (winMsg->message) {
      case WM_LBUTTONDOWN: {
          mousePressed();
          *result = 0;
          return true;
      }
      case WM_LBUTTONUP: {
          if (GetCapture() == (HWND)winId()) {
              // Get window before showing main window, incase it's under it
              Window* wnd = windowUnderCursor();
              mouseReleased();
              if (wnd) emit windowPicked(wnd);
              *result = 0;
              return true;
          }
      }
      case WM_MOUSEMOVE: {
          if (isPressed && GetCapture() == (HWND)winId()) {
              Window* wnd = windowUnderCursor();
              if (wnd) highlighter.highlight(wnd);
              *result = 0;
              return true;
          }
      }
      /* TODO: Get this working. This message doesn't even seem to be sent to us
          Also try WM_CAPTURECHANGED, it's supposed to be better
      case WM_CANCELMODE: {
          // User cancelled mouse capture (usually by pressing Esc)
          if (GetCapture() == (HWND)winId()) {
              mouseReleased();
              *result = 0;
              return true;
          }
      }*/
    }
    return false;
}

void WindowPicker::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    QRect textRect = painter.fontMetrics().boundingRect(pickerText);

    if (!isPressed) {
        int imgTop = (this->height() - image.height())/2;
        painter.drawPixmap(2, imgTop, image);
    }
    const int textLeft = image.width() + (padding * 3);
    painter.drawText(textLeft, 0, textRect.width(), this->height(),
                     Qt::AlignVCenter, pickerText);
}
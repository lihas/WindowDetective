///////////////////////////////////////////////////////////////////////////////
// File: Button.h                                                            //
// Date: 2011-01-18                                                          //
// Desc: Object that represents a Button control. Also includes objects for  //
//   other types such as radio buttons and check boxes. These types are      //
//   determined by the style of the button.                                  //
///////////////////////////////////////////////////////////////////////////////

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

#ifndef BUTTON_H
#define BUTTON_H


// TODO: Possible actions
//   * click

class Button : public Window {
public:
    Button(HWND handle, WindowClass* wndClass) :
        Window(handle, wndClass) {}
};


// TODO: Possible actions
//   * check/uncheck  (will be the same as Button click, but may want different text in UI menu)

class CheckBox : public Window {
public:
    CheckBox(HWND handle, WindowClass* wndClass) :
        Window(handle, wndClass) {}

    String getClassDisplayName();
    const QIcon getIcon();
};


class RadioButton : public Window {
public:
    RadioButton(HWND handle, WindowClass* wndClass) :
        Window(handle, wndClass) {}

    String getClassDisplayName();
    const QIcon getIcon();
};


class GroupBox : public Window {
public:
    GroupBox(HWND handle, WindowClass* wndClass) :
        Window(handle, wndClass) {}

    String getClassDisplayName();
    const QIcon getIcon();
};


#endif  // BUTTON_H
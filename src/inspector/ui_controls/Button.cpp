///////////////////////////////////////////////////////////////////////////////
// File: Button.cpp                                                          //
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

#include "inspector/inspector.h"
#include "inspector/WindowManager.h"
#include "window_detective/Logger.h"


/**********************/
/*** CheckBox class ***/
/**********************/

String CheckBox::getClassDisplayName() {
    return getWindowClass()->getName()+" (Check Box)";
}

const QIcon CheckBox::getIcon() {
    return Resources::getWindowClassIcon("CheckBox");
}


/*************************/
/*** RadioButton class ***/
/*************************/

String RadioButton::getClassDisplayName() {
    return getWindowClass()->getName()+" (Radio Button)";
}

const QIcon RadioButton::getIcon() {
    return Resources::getWindowClassIcon("RadioButton");
}


/**********************/
/*** GroupBox class ***/
/**********************/

String GroupBox::getClassDisplayName() {
    return getWindowClass()->getName()+" (Group Box)";
}

const QIcon GroupBox::getIcon() {
    return Resources::getWindowClassIcon("GroupBox");
}

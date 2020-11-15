//////////////////////////////////////////////////////////////////////////
// File: StringFormatter.h                                              //
// Date: 2010-03-25                                                     //
// Desc: Provides functions for converting various data types and       //
//   objects to a string representation for display.                    //
//////////////////////////////////////////////////////////////////////////

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

#ifndef STRING_FORMATTER_H
#define STRING_FORMATTER_H

#include "window_detective/include.h"
#include "inspector/inspector.h"


/*** These functions return a plain string representation ***/

// Primitive and built-in types
template <class T>
String stringLabel(T value) { return QVariant::fromValue(value).toString();}
inline String stringLabel(String value) { return value; }
String stringLabel(int value);
String stringLabel(uint value);
String stringLabel(byte value);
String stringLabel(bool value);

// Objects and typedefs
String stringLabel(HWND value);
String stringLabel(const QRect& value);
String stringLabel(const QPoint& value);
String stringLabel(const QSize& value);
String stringLabel(COLORREF value);
String stringLabel(const QColor& value);
String stringLabel(const QDateTime& value);
String stringLabel(Window* value);
String stringLabel(WindowClass* value);
String stringLabel(const WindowStyleList& value);
String stringLabel(const QStringList& value);


/*** These functions return a string in HTML format ***/

String htmlLabel(String value);
inline String htmlLabel(int value) { return stringLabel(value); }
inline String htmlLabel(uint value) { return stringLabel(value); }
inline String htmlLabel(bool value) { return stringLabel(value); }
inline String htmlLabel(HWND value) { return stringLabel(value); }
inline String htmlLabel(const QRect& value) { return stringLabel(value); }
inline String htmlLabel(const QPoint& value) { return stringLabel(value); }
inline String htmlLabel(const QSize& value) { return stringLabel(value); }
inline String htmlLabel(WindowClass* value) { return stringLabel(value); }
String htmlLabel(const WindowStyleList& value);
String htmlLabel(const WindowPropList& value);


/*** Functions for creating a url link in HTML format ***/

String linkLabel(Window* value);


#endif   // STRING_FORMATTER_H
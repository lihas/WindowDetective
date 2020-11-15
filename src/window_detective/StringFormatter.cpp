//////////////////////////////////////////////////////////////////////////
// File: StringFormatter.cpp                                            //
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

#include "StringFormatter.h"
#include "window_detective/QtHelpers.h"


/*** These functions return a plain string representation ***/

String stringLabel(int value) {
    return String::number(value);
}

String stringLabel(uint value) {
    return String::number(value);
}

String stringLabel(byte value) {
    return String::number((uint)value);
}

String stringLabel(bool value) {
    return value ? "true" : "false";
}

String stringLabel(HWND hwnd) {
    return hexString((uint)hwnd);
}

String stringLabel(const QRect& rect) {
    return "(" + String::number(rect.left()) + ", " +
                 String::number(rect.top()) + ", " +
                 String::number(rect.right()) + ", " +
                 String::number(rect.bottom()) + ")";
}

String stringLabel(const QPoint& pos) {
    return "(" + String::number(pos.x()) + ", " +
                 String::number(pos.y()) + ")";
}

String stringLabel(const QSize& size) {
    return "(" + String::number(size.width()) + ", " +
                 String::number(size.height()) + ")";
}

String stringLabel(COLORREF value) {
    return stringLabel(QColorFromCOLORREF(value));
}

String stringLabel(const QColor& value) {
    // TODO: Use setting to choose between r,g,b and hex
    String str;
    QTextStream stream(&str);
    stream << String::number(value.red()) << ", "
           << String::number(value.green()) << ", "
           << String::number(value.blue());
    return str;
}

String stringLabel(const QDateTime& value) {
    return value.isNull() ? "none" : value.toString(Qt::SystemLocaleShortDate);
}

String stringLabel(Window* window) {
    return window ? window->getDisplayName() : "";
}

String stringLabel(WindowClass* windowClass) {
    return windowClass ? windowClass->getDisplayName() : "";
}

String stringLabel(const WindowStyleList& list) {
    String value;
    QTextStream stream(&value);
    WindowStyleList::const_iterator i;

    for (i = list.begin(); i != list.end(); ++i) {
        if (i != list.begin()) {
            stream  << '\n';
        }
        stream << (*i)->getName();
    }
    return value;
}

String stringLabel(const QStringList& list) {
    String value;
    QTextStream stream(&value);
    QStringList::const_iterator i;

    for (i = list.begin(); i != list.end(); ++i) {
        if (i != list.begin()) {
            stream  << '\n';
        }
        stream << *i;
    }
    return value;
}


/*** These functions return a string in HTML format ***/

String htmlLabel(String str) {
    return str.toHtmlEscaped();
}

String htmlLabel(const WindowStyleList& list) {
    String value;
    QTextStream stream(&value);
    WindowStyleList::const_iterator i;

    for (i = list.begin(); i != list.end(); ++i) {
        stream << "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px;"
                  "margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"
               << (*i)->getName() << "</p>";
    }
    return value;
}

String htmlLabel(const WindowPropList& list) {
    String value;
    QTextStream stream(&value);
    WindowPropList::const_iterator i;

    stream << "<table><tr>"
           << "<th class=\"sub\">Name</th><th class=\"sub\">Data</th>"
           << "</tr>";
    for (i = list.begin(); i != list.end(); ++i) {
        stream << "<tr><td>" << (*i).name
               << "</td><td>" << hexString((uint)(*i).data)
               << "</td></tr>";
    }
    stream << "</table>";
    return value;
}


/*** Functions for creating a url link in HTML format ***/

String linkLabel(Window* window) {
    String value;
    QTextStream stream(&value);

    stream << "<a href=\"hwnd:" << hexString((uint)window->getHandle())
           << "\">" << stringLabel(window) << "</a>";
    return value;
}
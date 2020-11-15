//////////////////////////////////////////////////////////////////////////
// File: QtHelpers.h                                                    //
// Date: 2011-06-15                                                     //
// Desc: Provides helper functions for working with basic Qt types      //
//   These functions:                                                   //
//    - convert Windows types to Qt types, and vice versa               //
//    - write a Qt object to an XML stream                              //
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

#ifndef QT_HELPERS_H
#define QT_HELPERS_H

#include "window_detective/include.h"


/*--------------------------------------------------------------------------+
| Conversion functions                                                      |
+--------------------------------------------------------------------------*/

String wCharToString(const WCHAR* wstr, uint length = -1);

QColor stringToColour(String string);
String colourToString(QColor colour);

QPoint QPointFromPOINT(const POINT& p);
POINT POINTFromQPoint(const QPoint& p);

QRect QRectFromRECT(const RECT& rect);
RECT RECTFromQRect(const QRect& rect);

QColor QColorFromCOLORREF(COLORREF rgb);
COLORREF COLORREFFromQColor(const QColor& colour);

QDateTime QDateTimeFromSYSTEMTIME(const SYSTEMTIME& st, bool isLocalTime = true);
SYSTEMTIME SYSTEMTIMEFromQDateTime(const QDateTime& dateTime);

QImage QImageFromHBITMAP(HDC hdc, HBITMAP bitmap, int w, int h);
QPixmap QPixmapFromHICON(HICON icon, ICONINFO* info = nullptr);


/*--------------------------------------------------------------------------+
| XML functions                                                             |
+--------------------------------------------------------------------------*/

void writeElement(QXmlStreamWriter& stream, const QPoint& point);
void writeElement(QXmlStreamWriter& stream, const QSize& size);
void writeElement(QXmlStreamWriter& stream, const QRect& rect);
void writeElement(QXmlStreamWriter& stream, const QDateTime& dateTime);


#endif   // QT_HELPERS_H
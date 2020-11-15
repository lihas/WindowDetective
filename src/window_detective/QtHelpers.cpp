//////////////////////////////////////////////////////////////////////////
// File: QtHelpers.cpp                                                  //
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

#include "QtHelpers.h"
#include "StringFormatter.h"
#include "window_detective/Logger.h"


/****************************/
/*** Conversion functions ***/
/****************************/

/*--------------------------------------------------------------------------+
| Convert a wchar array to a Qt String.                                     |
+--------------------------------------------------------------------------*/
String wCharToString(const WCHAR* wstr, uint length) {
    return String::fromUtf16(reinterpret_cast<const ushort *>(wstr), length);
}

/*--------------------------------------------------------------------------+
| Parse the given string to a colour in the form                            |
| "red,green,blue[,alpha]". If alpha is omitted, it's set to 255.           |
| Returns the default colour red on error.                                  |
+--------------------------------------------------------------------------*/
QColor stringToColour(String string) {
    QColor colour;
    QStringList rgbList = string.split(",");
    if (rgbList.size() != 3 && rgbList.size() != 4)
        goto error;
    bool isOk;
    colour.setRed(rgbList[0].toInt(&isOk));
    if (!isOk) goto error;
    colour.setGreen(rgbList[1].toInt(&isOk));
    if (!isOk) goto error;
    colour.setBlue(rgbList[2].toInt(&isOk));
    if (!isOk) goto error;
    if (rgbList.size() == 4) {
        colour.setAlpha(rgbList[3].toInt(&isOk));
        if (!isOk) goto error;
    }
    else {
        colour.setAlpha(255);
    }
    return colour;          // If everything went ok

    error:
    return QColor();  // Return invalid colour on error
}

/*--------------------------------------------------------------------------+
| Return a string representation of the colour in the form                  |
| "red,green,blue[,alpha]". If alpha is 255, it is omitted.                 |
+--------------------------------------------------------------------------*/
String colourToString(QColor colour) {
    String s = String::number(colour.red()) + "," +
               String::number(colour.green()) + "," +
               String::number(colour.blue());
    if (colour.alpha() != 255)
        s += "," + String::number(colour.alpha());
    return s;
}


QPoint QPointFromPOINT(const POINT& p) {
    return QPoint(static_cast<int>(p.x), static_cast<int>(p.y));
}

POINT POINTFromQPoint(const QPoint& p) {
    POINT winPoint;
    winPoint.x = static_cast<LONG>(p.x());
    winPoint.y = static_cast<LONG>(p.y());
    return winPoint;
}

QRect QRectFromRECT(const RECT& rect) {
    // MSDN: By convention, the right and bottom edges of the rectangle are
    // normally considered exclusive. In other words, the pixel whose coordinates
    // are ( right, bottom ) lies immediately outside of the the rectangle.
    return QRect(QPoint(static_cast<int>(rect.left),
                        static_cast<int>(rect.top)),
                 QPoint(static_cast<int>(rect.right-1),
                        static_cast<int>(rect.bottom-1)));
}

RECT RECTFromQRect(const QRect& rect) {
    RECT winRect;
    winRect.left = static_cast<LONG>(rect.left());
    winRect.top = static_cast<LONG>(rect.top());
    winRect.right = static_cast<LONG>(rect.right()+1);
    winRect.bottom = static_cast<LONG>(rect.bottom()+1);
    return winRect;
}

QColor QColorFromCOLORREF(COLORREF rgb) {
    return QColor(GetRValue(rgb), GetGValue(rgb), GetBValue(rgb));
}

COLORREF COLORREFFromQColor(const QColor& colour) {
    return RGB(colour.red(), colour.green(), colour.blue());
}

QDateTime QDateTimeFromSYSTEMTIME(const SYSTEMTIME& st, bool isLocalTime) {
    QDate date(st.wYear, st.wMonth, st.wDay);
    QTime time(st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
    return QDateTime(date, time, isLocalTime ? Qt::LocalTime : Qt::UTC);
}

SYSTEMTIME SYSTEMTIMEFromQDateTime(const QDateTime& dateTime) {
    SYSTEMTIME st;
    QDate date = dateTime.date();
    QTime time = dateTime.time();
    st.wYear = date.year();
    st.wMonth = date.month();
    st.wDay = date.day();
    st.wDayOfWeek = date.dayOfWeek() - 1;  // QDate's week is 1 - 7
    st.wHour = time.hour();
    st.wMinute = time.minute();
    st.wSecond = time.second();
    st.wMilliseconds = time.msec();
    return st;
}

/* Taken from the Qt 4.x source (it was removed as an API function
   in Qt 5 because it's platform specific). */
QImage QImageFromHBITMAP(HDC hdc, HBITMAP bitmap, int w, int h) {
    BITMAPINFO bmi;
    memset(&bmi, 0, sizeof(bmi));
    bmi.bmiHeader.biSize        = sizeof(BITMAPINFOHEADER);
    bmi.bmiHeader.biWidth       = w;
    bmi.bmiHeader.biHeight      = -h;
    bmi.bmiHeader.biPlanes      = 1;
    bmi.bmiHeader.biBitCount    = 32;
    bmi.bmiHeader.biCompression = BI_RGB;
    bmi.bmiHeader.biSizeImage   = w * h * 4;

    QImage image(w, h, QImage::Format_ARGB32_Premultiplied);
    if (image.isNull())
        return image;

    // Get bitmap bits
    QScopedArrayPointer<uchar> data(new uchar [bmi.bmiHeader.biSizeImage]);
    if (!GetDIBits(hdc, bitmap, 0, h, data.data(), &bmi, DIB_RGB_COLORS)) {
        Logger::osWarning("Failed to get bitmap bits.");
        return QImage();
    }
    // Create image and copy data into image.
    for (int y = 0; y < h; ++y) {
        void *dest = (void *) image.scanLine(y);
        void *src = data.data() + y * image.bytesPerLine();
        memcpy(dest, src, image.bytesPerLine());
    }
    return image;
}

/* Taken from the Qt 4.x source, slightly modified. */
QPixmap QPixmapFromHICON(HICON icon, ICONINFO* givenInfo) {

    bool foundAlpha = false;
    HDC screenDevice = GetDC(0);
    HDC hdc = CreateCompatibleDC(screenDevice);
    ReleaseDC(0, screenDevice);

    ICONINFO newInfo;
    ICONINFO* info = givenInfo; 
    if (!info) {               // Don't fetch info if we already have it
        info = &newInfo;
        const bool result = GetIconInfo(icon, info);
        if (!result) {
            Logger::osWarning("Failed to get icon info.");
            return QPixmap();
        }
    }

    const int w = info->xHotspot * 2;
    const int h = info->yHotspot * 2;

    BITMAPINFOHEADER bitmapInfo;
    bitmapInfo.biSize        = sizeof(BITMAPINFOHEADER);
    bitmapInfo.biWidth       = w;
    bitmapInfo.biHeight      = h;
    bitmapInfo.biPlanes      = 1;
    bitmapInfo.biBitCount    = 32;
    bitmapInfo.biCompression = BI_RGB;
    bitmapInfo.biSizeImage   = 0;
    bitmapInfo.biXPelsPerMeter = 0;
    bitmapInfo.biYPelsPerMeter = 0;
    bitmapInfo.biClrUsed       = 0;
    bitmapInfo.biClrImportant  = 0;
    DWORD* bits;

    HBITMAP winBitmap = CreateDIBSection(hdc, (BITMAPINFO*)&bitmapInfo, DIB_RGB_COLORS, (VOID**)&bits, NULL, 0);
    HGDIOBJ oldhdc = (HBITMAP)SelectObject(hdc, winBitmap);
    DrawIconEx(hdc, 0, 0, icon, info->xHotspot * 2, info->yHotspot * 2, 0, 0, DI_NORMAL);
    QImage image = QImageFromHBITMAP(hdc, winBitmap, w, h);

    for (int y = 0 ; y < h && !foundAlpha ; y++) {
        const QRgb *scanLine= reinterpret_cast<const QRgb *>(image.scanLine(y));
        for (int x = 0; x < w ; x++) {
            if (qAlpha(scanLine[x]) != 0) {
                foundAlpha = true;
                break;
            }
        }
    }
    if (!foundAlpha) {
        // If no alpha was found, we use the mask to set alpha values
        DrawIconEx( hdc, 0, 0, icon, w, h, 0, 0, DI_MASK);
        const QImage mask = QImageFromHBITMAP(hdc, winBitmap, w, h);

        for (int y = 0 ; y < h ; y++){
            QRgb *scanlineImage = reinterpret_cast<QRgb *>(image.scanLine(y));
            const QRgb *scanlineMask = mask.isNull() ? 0 : reinterpret_cast<const QRgb *>(mask.scanLine(y));
            for (int x = 0; x < w ; x++){
                if (scanlineMask && qRed(scanlineMask[x]) != 0)
                    scanlineImage[x] = 0; // Mask out this pixel
                else
                    scanlineImage[x] |= 0xff000000; // Set the alpha channel to 255
            }
        }
    }
    // Dispose resources created by GetIconInfo call
    DeleteObject(info->hbmMask);
    DeleteObject(info->hbmColor);

    SelectObject(hdc, oldhdc); // Restore state
    DeleteObject(winBitmap);
    DeleteDC(hdc);
    return QPixmap::fromImage(image);
}


/*********************/
/*** XML functions ***/
/*********************/

void writeElement(QXmlStreamWriter& stream, const QPoint& point) {
    stream.writeStartElement("point");
    stream.writeAttribute("x", stringLabel(point.x()));
    stream.writeAttribute("y", stringLabel(point.y()));
    stream.writeEndElement();
}

void writeElement(QXmlStreamWriter& stream, const QSize& size) {
    stream.writeStartElement("size");
    stream.writeAttribute("width", stringLabel(size.width()));
    stream.writeAttribute("height", stringLabel(size.height()));
    stream.writeEndElement();
}

void writeElement(QXmlStreamWriter& stream, const QRect& rect) {
    stream.writeStartElement("rect");
    stream.writeAttribute("x", stringLabel(rect.x()));
    stream.writeAttribute("y", stringLabel(rect.y()));
    stream.writeAttribute("width", stringLabel(rect.width()));
    stream.writeAttribute("height", stringLabel(rect.height()));
    stream.writeEndElement();
}

void writeElement(QXmlStreamWriter& stream, const QDateTime& dateTime) {
    const QDate date = dateTime.date();
    const QTime time = dateTime.time();
    stream.writeAttribute("year", stringLabel(date.year()));
    stream.writeAttribute("month", stringLabel(date.month()));
    stream.writeAttribute("day", stringLabel(date.day()));
    stream.writeAttribute("hour", stringLabel(time.hour()));
    stream.writeAttribute("minute", stringLabel(time.minute()));
    stream.writeAttribute("second", stringLabel(time.second()));
    stream.writeAttribute("millisecond", stringLabel(time.msec()));
}

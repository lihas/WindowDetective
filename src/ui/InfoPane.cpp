/////////////////////////////////////////////////////////////////////
// File: InfoPane.cpp                                              //
// Date: 2010-03-02                                                //
// Desc: This window is shown in the top left corner of a window   //
//   which is being highlighted. It's purpose is to display quick  //
//   info on the window such as it's title, window class and       //
//   position.                                                     //
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


#include "InfoPane.h"
#include "window_detective/Settings.h"
#include "window_detective/main.h"
#include "window_detective/StringFormatter.h"


#define MAX_TEXT_LENGTH 50
QMap<String,String> InfoPane::infoLabelMap;

/*--------------------------------------------------------------------------+
| Creates the map of window variable names to their display labels          |
+--------------------------------------------------------------------------*/
void InfoPane::buildInfoLabels() {
    infoLabelMap.insert("windowClass", "Class");
    infoLabelMap.insert("text", "Text");
    infoLabelMap.insert("handle", "HWND");
    infoLabelMap.insert("dimensions", "Rect");
    infoLabelMap.insert("position", "Pos");
    infoLabelMap.insert("size", "Size");
    infoLabelMap.insert("parentHandle", "Parent HWND");
}

/*--------------------------------------------------------------------------+
| Constructor                                                               |
+--------------------------------------------------------------------------*/
InfoPane::InfoPane(QWidget* parent) : QLabel(parent) {
    // We want this fully opaque but still transparent to mouse
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::WindowTransparentForInput);
}

/*--------------------------------------------------------------------------+
| Moves this window to the top-left corner of the given window,             |
| ensuring there is enough room for it, and fills the table with            |
| info for the given window.                                                |
+--------------------------------------------------------------------------*/
void InfoPane::moveTo(Window* window) {
    this->client = window;
    setInfo();    
    setGeometry(calcBestDimensions());
}

/*--------------------------------------------------------------------------+
| Sets the info text for this window from the client window.                |
+--------------------------------------------------------------------------*/
void InfoPane::setInfo() {
    String htmlString;
    QTextStream stream(&htmlString);

    stream << "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" "
              "\"http://www.w3.org/TR/REC-html40/strict.dtd\"><html><head>";
    stream << "<style type=\"text/css\">";
    loadCssStyle("InfoWindow", stream);
    stream << "</style></head><body><table width=\"100%\" height=\"100%\">";

    // Set table data (this bit's kinda messy)
    for (int i = 0; i < Settings::infoLabels.size(); ++i) {
        String dataString, label = Settings::infoLabels[i];

        if (label == "windowClass") {
            dataString = htmlLabel(client->getClassDisplayName());
        }
        else if (label == "text") {
            String text = client->getText();
            if (text.size() > MAX_TEXT_LENGTH) {
                text.truncate(MAX_TEXT_LENGTH);
                text = text + "...";
            }
            dataString = htmlLabel(text);
        }
        else if (label == "handle") {
            dataString = htmlLabel(client->getHandle());
        }
        else if (label == "parentHandle") {
            Window* parent = client->getParent();
            dataString = htmlLabel(parent ? parent->getHandle() : 0);
        }
        else if (label == "dimensions") {
            dataString = htmlLabel(client->getDimensions());
        }
        else if (label == "position") {
            dataString = htmlLabel(client->getPosition());
        }
        else if (label == "size") {
            dataString = htmlLabel(client->getSize());
        }

        String row = (i % 2 == 0) ? "even" : "odd";
        stream << "<tr class=\"" << row << "\"><td class=\"name\"><p>"
               << infoLabelMap[label] << "</p></td><td class=\"data\"><p>"
               << dataString << "</p></td></tr>";
    }

    stream << "</table></body></html>";
    this->setText(htmlString);
}

/*--------------------------------------------------------------------------+
| Calculates the position to place this window such that it fits            |
| on screen and does not overlap too much of the client window.             |
+--------------------------------------------------------------------------*/
QRect InfoPane::calcBestDimensions() {
    QSize size = this->sizeHint();

    // Up to 10px inset for border style, 2px otherwise
    const int inset = testBits(Settings::highlighterStyle, Border) ?
                      qMin(Settings::highlighterBorderThickness, 10) : 2;
    QRect windowRect = client->getDimensions();
    QRect desktopRect = QApplication::desktop()->screenGeometry(windowRect.topLeft());
    QPoint bestPos;

    if (windowRect.x() + size.width() > desktopRect.right()) {
        bestPos.setX(windowRect.x() - size.width());
    }
    else {
        if (size.width() > windowRect.width() - 100) {
            if (windowRect.x() - size.width() < desktopRect.left()) {
                bestPos.setX(windowRect.x() + windowRect.width());
            }
            else {
                bestPos.setX(windowRect.x() - size.width());
            }
        }
        else {
            bestPos.setX(windowRect.x() + inset);
        }
    }

    if (windowRect.y() + size.height() > desktopRect.bottom()) {
        bestPos.setY(windowRect.y() - size.height());
    }
    else {
        if (size.height() > windowRect.height() - 100) {
            if (windowRect.y() - size.height() < desktopRect.top()) {
                bestPos.setY(windowRect.y() + windowRect.height());
            }
            else {
                bestPos.setY(windowRect.y() - size.height());
            }
        }
        else {
            bestPos.setY(windowRect.y() + inset);
        }
    }

    return QRect(bestPos, size);
}

//////////////////////////////////////////////////////////////////////////
// File: StatusBar.h                                                    //
// Date: 2011-08-04                                                     //
// Desc: Object that represents a Status Bar control.                   //
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

#ifndef STATUS_BAR_H
#define STATUS_BAR_H


class StatusBarPart {
public:
    String text;
    QRect boundingRect;

    StatusBarPart(const StatusBarPartStruct& itemStruct);
};

class StatusBar : public Window {
private:
    QList<StatusBarPart> parts;
    int horzBorder, vertBorder;    // Padding around window
    int padding;                   // Padding between parts
    bool getRemoteInfoFlag;        // True if we need to fetch remote info (maybe this could be in super-class)

public:
    StatusBar(HWND handle, WindowClass* wndClass);
    ~StatusBar() {}

    bool isOwnerDrawn();
    int getHorzBorderWidth() { return horzBorder; }
    int getVertBorderWidth() { return vertBorder; }
    int getPaddingWidth() { return padding; }
    uint getNumberOfParts();
    const QList<StatusBarPart>& getParts() { return parts; }
    void getRemoteInfo();

    QList<AbstractPropertyPage*> makePropertyPages();
    void writeContents(QXmlStreamWriter& stream);
};


#endif  // STATUS_BAR_H
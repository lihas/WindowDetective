//////////////////////////////////////////////////////////////////////////
// File: Tab.h                                                          //
// Date: 2011-08-02                                                     //
// Desc: Object that represents a tab control.                          //
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

#ifndef TAB_H
#define TAB_H


class TabItem {
public:
    String text;
    int imageIndex;
    LPARAM lParam;

    TabItem(const TabItemStruct& itemStruct);
};


class Tab : public Window {
private:
    QList<TabItem> items;

public:
    Tab(HWND handle, WindowClass* wndClass);
    ~Tab() {}

    uint getNumberOfItems();
    uint getFocusIndex();
    uint getSelectedIndex();
    const QList<TabItem>& getItems();

    QList<AbstractPropertyPage*> makePropertyPages();
    void writeContents(QXmlStreamWriter& stream);
};


#endif  // TAB_H
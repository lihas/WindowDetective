//////////////////////////////////////////////////////////////////////////
// File: ListView.h                                                     //
// Date: 2011-01-12                                                     //
// Desc: Object that represents a list view control (SysListView32)     //
//    and it's associated items (LVITEM).                               //
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

#ifndef LIST_VIEW_H
#define LIST_VIEW_H


class ListViewItem {
public:
    int index;
    bool isSelected;
    String text;
    QIcon image;

    ListViewItem(const ListViewItemStruct& itemStruct);
};


class ListView : public Window {
private:
    DWORD exLvStyleBits;          // Bit-flags of each extended list view style.
    WindowStyleList exLvStyles;   // Extended list view styles applied to this window.
    QList<ListViewItem> items;

public:
    ListView(HWND handle, WindowClass* wndClass);
    
    uint getExLvStyleBits();
    bool hasExLvStyleBits(uint mask) { return testBits(getExLvStyleBits(), mask); }
    WindowStyleList getExtendedLvStyles();
    uint getNumberOfItems();
    uint getNumberOfItemsPerPage();
    uint getNumberOfSelectedItems();
    uint addItemBatch(uint start);
    const QList<ListViewItem>& getItems();

    QList<AbstractPropertyPage*> makePropertyPages();
    void writeContents(QXmlStreamWriter& stream);
};


#endif  // LIST_VIEW_H
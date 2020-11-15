//////////////////////////////////////////////////////////////////////////
// File: ListBox.h                                                      //
// Date: 2011-01-18                                                     //
// Desc: Object that represents a list box control.                     //
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

#ifndef LIST_BOX_H
#define LIST_BOX_H


// TODO: Possible actions
//   * add item (string)
//   * remove item

class ListBoxItem {
public:
    bool isSelected;
    String text;

    ListBoxItem() {}
    ListBoxItem(String text, bool isSelected) :
        text(text), isSelected(isSelected) {}
};


class ListBox : public Window {
private:
    QList<ListBoxItem> items;

public:
    ListBox(HWND handle, WindowClass* wndClass);
    ~ListBox() {}

    bool isOwnerDrawn();
    bool hasStrings();
    uint getNumberOfItems();
    uint getNumberOfSelectedItems();
    const QList<ListBoxItem>& getItems();

    //virtual QList<QAction> getMenuActions();
    QList<AbstractPropertyPage*> makePropertyPages();
    void writeContents(QXmlStreamWriter& stream);
};


#endif  // LIST_BOX_H
//////////////////////////////////////////////////////////////////////////
// File: ComboBox.h                                                     //
// Date: 2011-01-18                                                     //
// Desc: Object that represents a combo box control.                    //
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

#ifndef COMBOBOX_H
#define COMBOBOX_H


class ComboBox : public Window {
private:
    QList<String> items;

public:
    ComboBox(HWND handle, WindowClass* wndClass) :
        Window(handle, wndClass) {}

    bool isOwnerDrawn();
    bool hasStrings();
    uint getNumberOfItems();
    QList<String> getItems();
    uint getSelectedIndex();

    // Menu and other UI methods
    //QList<QAction> getMenuActions();
    QList<AbstractPropertyPage*> makePropertyPages();
    void writeContents(QXmlStreamWriter& stream);
};


#endif  // COMBOBOX_H
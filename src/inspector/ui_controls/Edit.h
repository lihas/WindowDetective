//////////////////////////////////////////////////////////////////////////
// File: Edit.h                                                         //
// Date: 2011-01-18                                                     //
// Desc: Object that represents a text edit control.                    //
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

#ifndef EDIT_H
#define EDIT_H


// TODO: Possible actions
//   * undo
//   * clear
//   * set modified flag
//   * save text to file  (and/or some way of viewing large amount of text)

// TODO: RichEdit can inherit from this. Many of the Edit messages can
//  also be used for RichEdit controls.
class Edit : public Window {
public:
    Edit(HWND handle, WindowClass* wndClass) :
        Window(handle, wndClass) {}

    bool canUndo();
    bool isModified();
    bool isMultiLine();
    QPoint getSelectionRange();
    uint getNumberOfLines();
    uint getMaximumCharacters();

    //virtual QList<QAction> getMenuActions();
    QList<AbstractPropertyPage*> makePropertyPages();
    void writeContents(QXmlStreamWriter& stream);
};


#endif  // EDIT_H
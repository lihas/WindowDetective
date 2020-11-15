/////////////////////////////////////////////////////////////////////
// File: EditPropertyPage.h                                      //
// Date: 2011-01-31                                                //
// Desc: The property page for Edit controls.                      //
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

#ifndef EDIT_PROPERTY_PAGE_H
#define EDIT_PROPERTY_PAGE_H

#include <QtWidgets>
#include "window_detective/include.h"
#include "inspector/inspector.h"
#include "AbstractPropertyPage.h"


class EditPropertyPage : public AbstractPropertyPage {
    Q_OBJECT
private:
    Edit* model;
    QLabel* canUndoWidget;
    QLabel* isModifiedWidget;
    QLabel* selectionWidget;
    QLabel* numCharsWidget;
    QLabel* maxLengthWidget;
    QLabel* isMultiLineWidget;
    QLabel* numLinesWidget;
    QPlainTextEdit* textEdit;
public:
    EditPropertyPage(Edit* model, QWidget* parent = 0);
    ~EditPropertyPage() {}

    void setupUi();
    void updateProperties();
};


#endif   // EDIT_PROPERTY_PAGE_H
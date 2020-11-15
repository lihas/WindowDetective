//////////////////////////////////////////////////////////////////////////
// File: SearchInputPane.cpp                                            //
// Date: 2012-03-06                                                     //
// Desc: Custom text edit pane used for entering search text. It has a  //
//   small 'cancel' button to clear the text, and when blank displays   //
//   the word "Search" lightly in the background.                       //
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

#ifndef SEARCH_INPUT_PANE_H
#define SEARCH_INPUT_PANE_H

#include <QtWidgets>
#include "window_detective/include.h"

class SearchInputPane : public QLineEdit {
    Q_OBJECT
private:
    static const int padding = 5;   // Padding for placeholder text
    QToolButton* clearButton;       // A button to clear the search text
    String placeholderText;         // Default is "Search"

public:
    SearchInputPane(QWidget* parent = 0);
    ~SearchInputPane() {}

    String getPlaceholderText() const { return placeholderText; }
    void setPlaceholderText(const String& s) { placeholderText = s; }
private slots:
    void updateButton();
protected:
    void resizeEvent(QResizeEvent *);
    void paintEvent(QPaintEvent* e);
};

#endif   // SEARCH_INPUT_PANE_H
/////////////////////////////////////////////////////////////////////
// File: AbstractPropertyPage.h                                  //
// Date: 2011-01-27                                                //
// Desc: The superclass for all property pages. Mainly handles     //
//   things common to all subclasses.                              //
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

#ifndef ABSTRACT_PROPERTY_PAGE_H
#define ABSTRACT_PROPERTY_PAGE_H

#include <QtWidgets>
#include "window_detective/include.h"

class PropertiesPane;

class AbstractPropertyPage : public QWidget {
    Q_OBJECT
    Q_PROPERTY(QColor evenRowColour READ getEvenRowColour WRITE setEvenRowColour);
    Q_PROPERTY(QColor oddRowColour READ getOddRowColour WRITE setOddRowColour);
protected:
    PropertiesPane* owner;
    QFormLayout* formLayout;
    QColor evenRowColourProperty, oddRowColourProperty;
    const static int margin = 10, spacing = 12;

public:
    AbstractPropertyPage(QWidget* parent = 0);

    void setOwner(PropertiesPane* w) { owner = w; }
    virtual void setupUi() = 0;
    virtual void updateProperties() = 0;
    void addRow(String labelText, QWidget* widget);
    void addSpan(String labelText, QWidget* widget);
    const QColor getEvenRowColour() { return evenRowColourProperty; }
    const QColor getOddRowColour() { return oddRowColourProperty; }
    void setEvenRowColour(QColor c) { evenRowColourProperty = c; }
    void setOddRowColour(QColor c) { oddRowColourProperty = c; }
protected:
    QLabel* makeValueLabel();
    void paintEvent(QPaintEvent*);
};

#endif   // ABSTRACT_PROPERTY_PAGE_H
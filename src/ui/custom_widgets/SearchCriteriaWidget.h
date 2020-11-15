/////////////////////////////////////////////////////////////////////
// File: SearchCriteriaWidget.h                                  //
// Date: 2010-11-03                                                //
// Desc: Widget for a search criteria item. It contains a combo    //
//   box for selecting the property to search for, a combo box for //
//   the operator, and a changable widget for entering the value.  //
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

#ifndef SEARCH_CRITERIA_WIDGET_H
#define SEARCH_CRITERIA_WIDGET_H

#include <QtWidgets>
#include "window_detective/include.h"
#include "inspector/inspector.h"
#include "inspector/SearchCriteria.h"


class FindDialog;

class SearchCriteriaWidget : public QWidget {
    Q_OBJECT
private:
    QComboBox* cbProperties;
    QComboBox* cbOperators;
    QWidget* morphableWidgetContainer;   // Container to hold the morphable widget
    QWidget* morphableWidget;            // Pointer to a QWidget subclass
    QHBoxLayout* morphableWidgetLayout;
    QPushButton *btnAdd, *btnRemove;

public:
    SearchCriteriaWidget(QWidget *parent = 0);
    ~SearchCriteriaWidget() {}

private:
    void setupUi();
    void setPropertyList();
    void changeMorphableWidget(PropertyEnum prop);
public:
    PropertyEnum getSelectedProperty();
    OperatorEnum getSelectedOperator();
    QVariant getValue();
    SearchCriteriaItem getCriteriaItem();
signals:
    void addButtonClicked();
    void removeButtonClicked();
private slots:
    void changeType();
};


#endif   // SEARCH_CRITERIA_WIDGET_H
/////////////////////////////////////////////////////////////////////
// File: ComboBoxPropertyPage.cpp                                  //
// Date: 2011-01-31                                                //
// Desc: The property page for ComboBox controls.                  //
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

#include "PropertiesPane.h"
#include "ComboBoxPropertyPage.h"
#include "window_detective/StringFormatter.h"
#include "window_detective/main.h"


ComboBoxPropertyPage::ComboBoxPropertyPage(ComboBox* model, QWidget* parent) :
    AbstractPropertyPage(parent), model(model) {
    setWindowTitle("ComboBox");
}

void ComboBoxPropertyPage::setupUi() {
    addRow(tr("Number of Items"), numItemsWidget = makeValueLabel());
    addRow(tr("Selected Index"), selectedIndexWidget = makeValueLabel());
    addRow(tr("Is Owner Drawn"), isOwnerDrawnWidget = makeValueLabel());
    addSpan(tr("Items"), listWidget = new QListWidget(this));
}

/*--------------------------------------------------------------------------+
| Updates the data in each property widget.                                 |
+--------------------------------------------------------------------------*/
void ComboBoxPropertyPage::updateProperties() {
    numItemsWidget->setText(stringLabel(model->getNumberOfItems()));
    selectedIndexWidget->setText(stringLabel(model->getSelectedIndex()));
    isOwnerDrawnWidget->setText(stringLabel(model->isOwnerDrawn()));

    listWidget->clear();
    QList<String> list = model->getItems();
    QList<String>::const_iterator i;
    for (i = list.begin(); i != list.end(); ++i) {
        new QListWidgetItem(*i, listWidget);
    }
}

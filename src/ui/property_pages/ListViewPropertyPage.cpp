/////////////////////////////////////////////////////////////////////
// File: ListViewPropertyPage.cpp                                  //
// Date: 2011-03-13                                                //
// Desc: The property page for ListView controls. Displays         //
//   properties of the control itself as well as properties of     //
//   each item.                                                    //
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
#include "ListViewPropertyPage.h"
#include "window_detective/StringFormatter.h"
#include "window_detective/main.h"


ListViewPropertyPage::ListViewPropertyPage(ListView* model, QWidget* parent) :
    AbstractPropertyPage(parent), model(model) {
    setWindowTitle("ListView");
}

void ListViewPropertyPage::setupUi() {
    listWidget = new QTableWidget(this);
    listWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    listWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    listWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    listWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
    listWidget->setWordWrap(false);
    listWidget->setCornerButtonEnabled(false);
    listWidget->horizontalHeader()->setHighlightSections(false);
    listWidget->verticalHeader()->setHighlightSections(false);
    
    addRow(tr("List View Style bits"), exLvStyleBitsWidget = makeValueLabel());
    addRow(tr("List View Styles"), exLvStylesWidget = makeValueLabel());
    addRow(tr("Number of Items"), numberOfItemsWidget = makeValueLabel());
    addRow(tr("Number of Items Per Page"), numberOfItemsPerPageWidget = makeValueLabel());
    addRow(tr("Number of Selected Items"), numberOfSelectedItemsWidget = makeValueLabel());
    addSpan(tr("Items"), listWidget);
}

/*--------------------------------------------------------------------------+
| Helper functions to work with the table widget.                           |
+--------------------------------------------------------------------------*/
void ListViewPropertyPage::addListItem(int index, const ListViewItem& item) {
    addTableColumn(index, 0, stringLabel(item.text));
    addTableColumn(index, 1, stringLabel(item.isSelected));
}
void ListViewPropertyPage::addTableColumn(int row, int column, String data) {
    QTableWidgetItem* item = new QTableWidgetItem(data);
    item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    listWidget->setItem(row, column, item);
}
void ListViewPropertyPage::resizeTable() {
    // First column is total width minus second column width minus extra width (hack)
    int desiredWidth = listWidget->width() - listWidget->columnWidth(1) - 25;
    listWidget->setColumnWidth(0, desiredWidth);
    listWidget->resizeRowsToContents();
}

/*--------------------------------------------------------------------------+
| Updates the data in each property widget.                                 |
+--------------------------------------------------------------------------*/
void ListViewPropertyPage::updateProperties() {
    exLvStyleBitsWidget->setText(hexString(model->getExLvStyleBits()));
    exLvStylesWidget->setText(stringLabel(model->getExtendedLvStyles()));
    numberOfItemsWidget->setText(stringLabel(model->getNumberOfItems()));
    numberOfItemsPerPageWidget->setText(stringLabel(model->getNumberOfItemsPerPage()));
    numberOfSelectedItemsWidget->setText(stringLabel(model->getNumberOfSelectedItems()));

    QList<ListViewItem> items = model->getItems();
    listWidget->clear();
    listWidget->setRowCount(model->getNumberOfItems());
    listWidget->setColumnCount(2);

    QStringList headerLabels;
    // TODO: Redesign this UI so that it displays "sub-items" too.
    //for (int i = 0; i < model->numSubItems; ++i) {
    //    headerLabels << "Subitem <i>";
    //}
    headerLabels << tr("Text") << tr("Is Selected?");
    listWidget->setHorizontalHeaderLabels(headerLabels);
    for (int i = 0; i < items.size(); ++i) {
        addListItem(i, items.at(i));
    }
    resizeTable();
}

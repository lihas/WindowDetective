/////////////////////////////////////////////////////////////////////
// File: TabPropertyPage.cpp                                       //
// Date: 2011-08-02                                                //
// Desc: The property page for Tab controls.                       //
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
#include "TabPropertyPage.h"
#include "window_detective/StringFormatter.h"


TabPropertyPage::TabPropertyPage(Tab* model, QWidget* parent) :
    AbstractPropertyPage(parent), model(model) {
    setWindowTitle("Tab");
}

void TabPropertyPage::setupUi() {
    listWidget = new QTableWidget(this);
    listWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    listWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    listWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    listWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
    listWidget->setWordWrap(false);
    listWidget->setCornerButtonEnabled(false);
    listWidget->horizontalHeader()->setHighlightSections(false);
    listWidget->verticalHeader()->setHighlightSections(false);

    addRow(tr("Number of Items"), numberOfItemsWidget = makeValueLabel());
    addRow(tr("Selected Index"), selectedIndexWidget = makeValueLabel());
    addRow(tr("Focus Index"), focusIndexWidget = makeValueLabel());
    addSpan(tr("Items"), listWidget);
}

/*--------------------------------------------------------------------------+
| Helper functions to work with the table widget.                           |
+--------------------------------------------------------------------------*/
void TabPropertyPage::addListItem(int index, const TabItem& item) {
    addTableColumn(index, 0, stringLabel(item.text));
    addTableColumn(index, 1, item.imageIndex == -1 ? tr("none") : stringLabel(item.imageIndex));
    addTableColumn(index, 2, stringLabel(item.lParam));
}
void TabPropertyPage::addTableColumn(int row, int column, String data) {
    QTableWidgetItem* item = new QTableWidgetItem(data);
    item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    listWidget->setItem(row, column, item);
}
void TabPropertyPage::resizeTable() {
    // First column is total width minus the other column widths
    int desiredWidth = listWidget->width() - listWidget->columnWidth(1) - listWidget->columnWidth(2) - 25;
    listWidget->setColumnWidth(0, desiredWidth);
    listWidget->resizeRowsToContents();
}

/*--------------------------------------------------------------------------+
| Updates the data in each property widget.                                 |
+--------------------------------------------------------------------------*/
void TabPropertyPage::updateProperties() {
    numberOfItemsWidget->setText(stringLabel(model->getNumberOfItems()));
    uint sel = model->getSelectedIndex();
    selectedIndexWidget->setText(sel == -1 ? tr("none") : stringLabel(sel));
    focusIndexWidget->setText(stringLabel(model->getFocusIndex()));

    QList<TabItem> items = model->getItems();
    listWidget->clear();
    listWidget->setRowCount(model->getNumberOfItems());
    listWidget->setColumnCount(3);

    QStringList headerLabels;
    headerLabels << tr("Text") << tr("Image Index") << tr("lParam");
    listWidget->setHorizontalHeaderLabels(headerLabels);

    for (int i = 0; i < items.size(); ++i) {
        addListItem(i, items.at(i));
    }
    resizeTable();
}

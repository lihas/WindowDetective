/////////////////////////////////////////////////////////////////////
// File: StatusBarPropertyPage.cpp                                 //
// Date: 2011-08-04                                                //
// Desc: The property page for StatusBar controls.                 //
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
#include "StatusBarPropertyPage.h"
#include "window_detective/StringFormatter.h"


StatusBarPropertyPage::StatusBarPropertyPage(StatusBar* model, QWidget* parent) :
    AbstractPropertyPage(parent), model(model) {
    setWindowTitle("StatusBar");
}

void StatusBarPropertyPage::setupUi() {
    listWidget = new QTableWidget(this);
    listWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    listWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    listWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    listWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
    listWidget->setWordWrap(false);
    listWidget->setCornerButtonEnabled(false);
    listWidget->horizontalHeader()->setHighlightSections(false);
    listWidget->verticalHeader()->setHighlightSections(false);

    addRow(tr("Number of Parts"), numberOfPartsWidget = makeValueLabel());
    addRow(tr("Horizontal Border"), horzBorderWidget = makeValueLabel());
    addRow(tr("Vertical Border"), vertBorderWidget = makeValueLabel());
    addRow(tr("Padding"), paddingWidget = makeValueLabel());
    addSpan(tr("Parts"), listWidget);
}

/*--------------------------------------------------------------------------+
| Helper functions to work with the table widget.                           |
+--------------------------------------------------------------------------*/
void StatusBarPropertyPage::addListItem(int index, const StatusBarPart& item) {
    addTableColumn(index, 0, stringLabel(item.text));
    addTableColumn(index, 1, stringLabel(item.boundingRect));
}
void StatusBarPropertyPage::addTableColumn(int row, int column, String data) {
    QTableWidgetItem* item = new QTableWidgetItem(data);
    item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    listWidget->setItem(row, column, item);
}
void StatusBarPropertyPage::resizeTable() {
    // First column is total width minus second column width minus extra width (hack)
    int desiredWidth = listWidget->width() - listWidget->columnWidth(1) - 25;
    listWidget->setColumnWidth(0, desiredWidth);
    listWidget->resizeRowsToContents();
}

/*--------------------------------------------------------------------------+
| Updates the data in each property widget.                                 |
+--------------------------------------------------------------------------*/
void StatusBarPropertyPage::updateProperties() {
    model->getRemoteInfo();

    numberOfPartsWidget->setText(stringLabel(model->getNumberOfParts()));
    horzBorderWidget->setText(stringLabel(model->getHorzBorderWidth()));
    vertBorderWidget->setText(stringLabel(model->getVertBorderWidth()));
    paddingWidget->setText(stringLabel(model->getPaddingWidth()));

    QList<StatusBarPart> items = model->getParts();
    listWidget->clear();
    listWidget->setRowCount(model->getNumberOfParts());
    listWidget->setColumnCount(2);

    QStringList headerLabels;
    headerLabels << tr("Text") << tr("Bounding Rect");
    listWidget->setHorizontalHeaderLabels(headerLabels);

    for (int i = 0; i < items.size(); ++i) {
        addListItem(i, items.at(i));
    }
    resizeTable();
}

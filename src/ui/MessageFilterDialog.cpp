/////////////////////////////////////////////////////////////////////
// File: MessageFilterDialog.cpp                                   //
// Date: 2011-06-23                                                //
// Desc: Dialog window used to manage message filters for a        //
//   messages window. The filters can be inclusions/exclusions or  //
//   highlighting of particular messages.                          //
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

#include "MessageFilterDialog.h"
#include "window_detective/Logger.h"


MessageFilterDialog::MessageFilterDialog(QWidget* parent) :
    QDialog(parent),
    filterModel(),
    proxyModel(),
    nameModel() {
    setupUi(this);

    findPane->setPlaceholderText(tr("Find"));
    proxyModel.setFilterCaseSensitivity(Qt::CaseInsensitive);

    highlightsTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    highlightsTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    highlightsTable->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    highlightsTable->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    connect(includeAllButton, SIGNAL(clicked()), this, SLOT(includeAll()));
    connect(excludeAllButton, SIGNAL(clicked()), this, SLOT(excludeAll()));
    connect(includeSelectedButton, SIGNAL(clicked()), this, SLOT(includeSelected()));
    connect(excludeSelectedButton, SIGNAL(clicked()), this, SLOT(excludeSelected()));
    connect(addHighlightButton, SIGNAL(clicked()), this, SLOT(addNewHighlight()));
    connect(removeHighlightButton, SIGNAL(clicked()), this, SLOT(removeSelectedHighlights()));
    connect(highlightsTable, SIGNAL(cellDoubleClicked(int,int)), this, SLOT(highlightCellDoubleClicked(int,int)));
    connect(highlightsTable, SIGNAL(itemSelectionChanged()), this, SLOT(highlightItemSelectionChanged()));

    removeHighlightButton->setEnabled(false);   // Nothing selected initially
    tabWidget->setCurrentIndex(0);
}


/*--------------------------------------------------------------------------+
| Sets the list of messages, and creates a proxy model for filtering the    |
| list of messages to filter. (Yo Dawg, I heard you like filtering...)      |
+--------------------------------------------------------------------------*/
void MessageFilterDialog::setMessageFilters(QList<MessageFilter> list) {
    filterModel.setList(list);

    // Unfortunately, we cannot use the same model for the combo boxes, as they
    // would also show the Qt::CheckStateRole. So copy the names into a stringlist model
    QStringList names;
    QList<MessageFilter>::const_iterator i;
    for (i = list.begin(); i != list.end(); ++i) {
        names.append(i->name);
    }
    nameModel.setStringList(names);
    nameModel.sort(0);

    proxyModel.setSourceModel(&filterModel);
    proxyModel.sort(0);
    filterListView->setModel(&proxyModel);

    connect(findPane, SIGNAL(textChanged(const QString&)), &proxyModel, SLOT(setFilterFixedString(const QString&)));
}

/*--------------------------------------------------------------------------+
| Returns the list of messages, and their filter state.                     |
+--------------------------------------------------------------------------*/
QList<MessageFilter> MessageFilterDialog::getMessageFilters() {
    return filterModel.getList();
}

/*--------------------------------------------------------------------------+
| Sets whether unknown messages should be included.                         |
+--------------------------------------------------------------------------*/
void MessageFilterDialog::setIncludeOthers(bool b) {
    otherMessagesCheckBox->setChecked(b);
}

/*--------------------------------------------------------------------------+
| Returns true if unknown messages should be included.                      |
+--------------------------------------------------------------------------*/
bool MessageFilterDialog::shouldIncludeOthers() {
    return otherMessagesCheckBox->isChecked();
}

/*--------------------------------------------------------------------------+
| Ticks all the check boxes (all messages are to be included).              |
+--------------------------------------------------------------------------*/
void MessageFilterDialog::includeAll() {
    filterModel.setAllCheckStates(true);
    setIncludeOthers(true);
}

/*--------------------------------------------------------------------------+
| Unticks all the check boxes (all messages are to be excluded).            |
+--------------------------------------------------------------------------*/
void MessageFilterDialog::excludeAll() {
    filterModel.setAllCheckStates(false);
    setIncludeOthers(false);
}

/*--------------------------------------------------------------------------+
| Ticks the check boxes of all selected items in the list.                  |
+--------------------------------------------------------------------------*/
void MessageFilterDialog::includeSelected() {
    QItemSelection proxySel = filterListView->selectionModel()->selection();
    QItemSelection realSel = proxyModel.mapSelectionToSource(proxySel);
    filterModel.setCheckStates(realSel.indexes(), true);
}

/*--------------------------------------------------------------------------+
| Unticks the check boxes of all selected items in the list.                |
+--------------------------------------------------------------------------*/
void MessageFilterDialog::excludeSelected() {
    QItemSelection proxySel = filterListView->selectionModel()->selection();
    QItemSelection realSel = proxyModel.mapSelectionToSource(proxySel);
    filterModel.setCheckStates(realSel.indexes(), false);
}


/*--------------------------------------------------------------------------+
| Sets the list of highlighted messages, and builds the UI.                 |
+--------------------------------------------------------------------------*/
void MessageFilterDialog::setHighlightedMessages(QList<MessageHighlight> highlights) {
    QList<MessageHighlight>::const_iterator i;
    for (i = highlights.begin(); i != highlights.end(); ++i) {
        addHighlight(i->name, i->foregroundColour, i->backgroundColour);
    }
}

/*--------------------------------------------------------------------------+
| Gets the highlighted messages from the UI table and returns them          |
| as a list of MessageHighlight objects.                                    |
+--------------------------------------------------------------------------*/
QList<MessageHighlight> MessageFilterDialog::getHighlightedMessages() {
    QList<MessageHighlight> list;

    for (int i = 0; i < highlightsTable->rowCount(); ++i) {
        MessageHighlight m;
        QComboBox* comboBox = dynamic_cast<QComboBox*>(highlightsTable->cellWidget(i, 0));
        if (!comboBox) {
            Logger::debug("MessageFilterDialog::getHighlightedMessages - Unable to get combo box from first column");
            return QList<MessageHighlight>();
        }
        m.name = comboBox->currentText();
        m.foregroundColour = highlightsTable->item(i, 1)->background().color();
        m.backgroundColour = highlightsTable->item(i, 2)->background().color();
        list.append(m);
    }

    return list;
}

/*--------------------------------------------------------------------------+
| Adds a new row in the highlights table.                                   |
+--------------------------------------------------------------------------*/
void MessageFilterDialog::addHighlight(String msgName, QColor foreColour, QColor backColour) {
    const int lastRow = highlightsTable->rowCount();
    highlightsTable->setRowCount(lastRow+1);

    QComboBox* comboBox = new QComboBox();
    comboBox->view()->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    comboBox->setModel(&nameModel);
    int nameIndex = comboBox->findData(msgName, Qt::DisplayRole);
    if (nameIndex != -1) {
        comboBox->setCurrentIndex(nameIndex);
    }
    highlightsTable->setCellWidget(lastRow, 0, comboBox);

    QTableWidgetItem* foregroundColourItem = new QTableWidgetItem();
    foregroundColourItem->setBackgroundColor(foreColour);
    highlightsTable->setItem(lastRow, 1, foregroundColourItem);

    QTableWidgetItem* backgroundColourItem = new QTableWidgetItem();
    backgroundColourItem->setBackgroundColor(backColour);
    highlightsTable->setItem(lastRow, 2, backgroundColourItem);
}

/*--------------------------------------------------------------------------+
| Add a new row in the highlights table.                                    |
+--------------------------------------------------------------------------*/
void MessageFilterDialog::addNewHighlight() {
    QPalette palette = QApplication::palette();
    addHighlight("WM_NULL", palette.text().color(), palette.base().color());
}

/*--------------------------------------------------------------------------+
| Remove the selected rows (if any) in the highlights table.                |
+--------------------------------------------------------------------------*/
void MessageFilterDialog::removeSelectedHighlights() {
    QModelIndexList selectedIndexes = highlightsTable->selectionModel()->selectedRows();
    qSort(selectedIndexes.begin(), selectedIndexes.end());

    for (int i = selectedIndexes.size(); i > 0; --i) {
        highlightsTable->removeRow(selectedIndexes.at(i - 1).row());
    }
}

/*--------------------------------------------------------------------------+
| Open the colour chooser to change the value of the cell that was          |
| double-clicked. This cell must be in the foreground or background         |
| colour columns.                                                           |
+--------------------------------------------------------------------------*/
void MessageFilterDialog::highlightCellDoubleClicked(int row, int column) {
    if (column == 0) return;     // Colour cells are in the 2nd and 3nd column

    QTableWidgetItem* colourItem = highlightsTable->item(row, column);
    QColor chosen = QColorDialog::getColor(colourItem->backgroundColor(), this, tr("Select colour"));
    if (chosen.isValid()) {
        colourItem->setBackgroundColor(chosen);
    }
}

/*--------------------------------------------------------------------------+
| Disables the "Remove" button if no items are selected.                    |
+--------------------------------------------------------------------------*/
void MessageFilterDialog::highlightItemSelectionChanged() {
    removeHighlightButton->setEnabled(!highlightsTable->selectedItems().isEmpty());
}

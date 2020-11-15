/////////////////////////////////////////////////////////////////////
// File: EditPropertyPage.cpp                                      //
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

#include "PropertiesPane.h"
#include "EditPropertyPage.h"
#include "window_detective/StringFormatter.h"
#include "window_detective/main.h"


EditPropertyPage::EditPropertyPage(Edit* model, QWidget* parent) :
    AbstractPropertyPage(parent), model(model) {
    setWindowTitle("Edit");
}

void EditPropertyPage::setupUi() {
    addRow(tr("Can Undo"), canUndoWidget = makeValueLabel());
    addRow(tr("Is Modified"), isModifiedWidget = makeValueLabel());
    addRow(tr("Selection"), selectionWidget = makeValueLabel());
    addRow(tr("Number of Characters"), numCharsWidget = makeValueLabel());
    addRow(tr("Maximum Length"), maxLengthWidget = makeValueLabel());
    addRow(tr("Is Multi-line"), isMultiLineWidget = makeValueLabel());
    if (model->isMultiLine()) {
        addRow(tr("Number of Lines"), numLinesWidget = makeValueLabel());
    }
    else {
        numLinesWidget = NULL;
    }
    textEdit = new QPlainTextEdit(this);
    textEdit->setReadOnly(true);
    textEdit->setUndoRedoEnabled(false);
    textEdit->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    // TODO: Have widgets for toggling word wrap and selecting font
    textEdit->setWordWrapMode(QTextOption::NoWrap);
    textEdit->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
    addSpan(tr("Text"), textEdit);
}

/*--------------------------------------------------------------------------+
| Updates the data in each property widget.                                 |
+--------------------------------------------------------------------------*/
void EditPropertyPage::updateProperties() {
    canUndoWidget->setText(stringLabel(model->canUndo()));
    isModifiedWidget->setText(stringLabel(model->isModified()));
    selectionWidget->setText(stringLabel(model->getSelectionRange()));
    numCharsWidget->setText(stringLabel(model->getText().size()));
    maxLengthWidget->setText(stringLabel(model->getMaximumCharacters()));
    isMultiLineWidget->setText(stringLabel(model->isMultiLine()));
    if (numLinesWidget) {
        numLinesWidget->setText(stringLabel(model->getNumberOfLines()));
    }
    textEdit->setPlainText(model->getText());
}

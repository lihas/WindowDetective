/////////////////////////////////////////////////////////////////////
// File: GenericPropertyPage.cpp                                   //
// Date: 2011-01-25                                                //
// Desc: The property page for Window objects. Displays properties //
//    common to all windows.                                       //
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
#include "GenericPropertyPage.h"
#include "window_detective/StringFormatter.h"
#include "window_detective/main.h"


GenericPropertyPage::GenericPropertyPage(Window* model, QWidget* parent) :
    AbstractPropertyPage(parent), model(model) {
    setWindowTitle("Window");
}

void GenericPropertyPage::setupUi() {
    addRow(tr("Window Text"), windowTextWidget = makeValueLabel());
    addRow(tr("Handle"), handleWidget = makeValueLabel());
    if (model->getParent()) {
        addRow(tr("Parent"), parentWidget = makeValueLabel());
        parentWidget->setTextFormat(Qt::RichText);
        connect(parentWidget, SIGNAL(linkActivated(const QString&)), owner, SLOT(linkClicked(const QString&)));
    }
    else {
        parentWidget = NULL;
    }
    if (model->getOwner()) {
        addRow(tr("Owner"), ownerWidget = makeValueLabel());
        ownerWidget->setTextFormat(Qt::RichText);
        connect(ownerWidget, SIGNAL(linkActivated(const QString&)), owner, SLOT(linkClicked(const QString&)));
    }
    else {
        ownerWidget = NULL;
    }
    addRow(tr("Dimensions"), dimensionsWidget = makeValueLabel());
    addRow(tr("Position"), positionWidget = makeValueLabel());
    addRow(tr("Size"), sizeWidget = makeValueLabel());
    addRow(tr("Client Dimensions"), clientDimensionsWidget = makeValueLabel());
    if (model->isChild()) {
        addRow(tr("Relative Dimensions"), relativeDimensionsWidget = makeValueLabel());
    }
    else {
        relativeDimensionsWidget = NULL;
    }
    addRow(tr("Style bits"), styleBitsWidget = makeValueLabel());
    addRow(tr("Styles"), stylesWidget = makeValueLabel());
    addRow(tr("Extended Style bits"), exStyleBitsWidget = makeValueLabel());
    addRow(tr("Extended Styles"), exStylesWidget = makeValueLabel());
    addRow(tr("Horizontal Scroll"), hScrollWidget = new ScrollPropertyWidget(this));
    addRow(tr("Vertical Scroll"), vScrollWidget = new ScrollPropertyWidget(this));
    addRow(tr("Font"), fontWidget = new FontPropertyWidget(this));
    addRow(tr("Properties"), windowPropsWidget = new WindowPropWidget(this));
    addRow(tr("Owner Process"), ownerProcessWidget = makeValueLabel());
    addRow(tr("Owner Process ID"), ownerProcessIDWidget = makeValueLabel());
    addRow(tr("Owner Thread ID"), ownerThreadIDWidget = makeValueLabel());
}

/*--------------------------------------------------------------------------+
| Updates the data in each property widget.                                 |
+--------------------------------------------------------------------------*/
void GenericPropertyPage::updateProperties() {
    if (!model->getHandle()) return;

    model->updateExtraInfo();
    model->invalidateDimensions();

    windowTextWidget->setText(stringLabel(model->getText()));
    handleWidget->setText(stringLabel(model->getHandle()));
    if (parentWidget) {
        parentWidget->setText(linkLabel(model->getParent()));
    }
    if (ownerWidget) {
        ownerWidget->setText(linkLabel(model->getOwner()));
    }
    dimensionsWidget->setText(stringLabel(model->getDimensions()));
    positionWidget->setText(stringLabel(model->getPosition()));
    sizeWidget->setText(stringLabel(model->getSize()));
    clientDimensionsWidget->setText(stringLabel(model->getClientDimensions()));
    if (relativeDimensionsWidget) {
        relativeDimensionsWidget->setText(stringLabel(model->getRelativeDimensions()));
    }
    styleBitsWidget->setText(hexString(model->getStyleBits()));
    stylesWidget->setText(stringLabel(model->getStandardStyles()));
    exStyleBitsWidget->setText(hexString(model->getExStyleBits()));
    exStylesWidget->setText(stringLabel(model->getExtendedStyles()));
    hScrollWidget->setModel(model->getHorzScrollInfo());
    vScrollWidget->setModel(model->getVertScrollInfo());
    fontWidget->setModel(model->getFont());
    windowPropsWidget->setModel(model->getProps());
    ownerProcessWidget->setText(stringLabel(model->getProcess()->getFilePath()));
    ownerProcessIDWidget->setText(stringLabel(model->getProcessId()));
    ownerThreadIDWidget->setText(stringLabel(model->getThreadId()));
}

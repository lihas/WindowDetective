/////////////////////////////////////////////////////////////////////
// File: SetPropertiesDialog.cpp                                   //
// Date: 2010-03-24                                                //
// Desc: Used to set the properties of a window. It has a number   //
//   of tabs to group the different properties and a "Set" button  //
//   to apply any changes to the real window.                      //
//   This dialog is modal, since there can only be one per window  //
//   and we also don't want the user changing anything else while  //
//   this is open, otherwise it might disrupt the window's state.  //
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

#include "SetPropertiesDialog.h"
#include "window_detective/StringFormatter.h"
#include "inspector/WindowManager.h"

SetPropertiesDialog::SetPropertiesDialog(Window* window, QWidget* parent) :
    QDialog(parent),
    client(window),
    isModifyingList(false) {
    setupUi(this);
    Q_ASSERT(window != NULL);

    const QRegExp fourDigit("\\(?\\s*-?[0-9]+\\s*(,\\s*-?[0-9]+\\s*){3}\\)?");
    const QRegExp twoDigit("\\(?\\s*-?[0-9]+\\s*,\\s*-?[0-9]+\\s*\\)?");
    txtDimensions->setValidator(new QRegExpValidator(fourDigit, this));
    txtPos->setValidator(new QRegExpValidator(twoDigit, this));
    txtSize->setValidator(new QRegExpValidator(twoDigit, this));

    // Connect any change events
    connect(txtWindowText, SIGNAL(textChanged(QString)), this, SLOT(propertyChanged()));
    connect(txtDimensions, SIGNAL(textChanged(QString)), this, SLOT(propertyChanged()));
    connect(txtPos, SIGNAL(textChanged(QString)), this, SLOT(propertyChanged()));
    connect(txtSize, SIGNAL(textChanged(QString)), this, SLOT(propertyChanged()));
    connect(chVisible, SIGNAL(clicked()), this, SLOT(propertyChanged()));
    connect(chEnabled, SIGNAL(clicked()), this, SLOT(propertyChanged()));
    connect(chAlwaysOnTop, SIGNAL(clicked()), this, SLOT(propertyChanged()));
    connect(spnStyleBits, SIGNAL(textChanged(QString)), this, SLOT(propertyChanged()));
    connect(spnExStyleBits, SIGNAL(textChanged(QString)), this, SLOT(propertyChanged()));
    connect(stylesList, SIGNAL(itemChanged(QListWidgetItem*)), this, SLOT(propertyChanged()));

    connect(txtDimensions, SIGNAL(editingFinished()), this, SLOT(dimensionTextChanged()));
    connect(txtPos, SIGNAL(editingFinished()), this, SLOT(posOrSizeTextChanged()));
    connect(txtSize, SIGNAL(editingFinished()), this, SLOT(posOrSizeTextChanged()));
    connect(spnStyleBits, SIGNAL(editingFinished()), this, SLOT(updateStylesList()));
    connect(spnExStyleBits, SIGNAL(editingFinished()), this, SLOT(updateStylesList()));
    connect(stylesList, SIGNAL(itemChanged(QListWidgetItem*)), this, SLOT(styleItemChanged(QListWidgetItem*)));
    connect(stylesList, SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)), this, SLOT(styleItemSelectionChanged(QListWidgetItem*)));
    connect(setButton, SIGNAL(clicked()), this, SLOT(setButtonClicked()));

    copyModelToWindow();
    this->setWindowModified(false);
}

void SetPropertiesDialog::readSmartSettings() {
    // If the settings don't exist, don't try to read them.
    // It will only mess up the window positions by defaulting to 0
    if (!Settings::isAppInstalled() || !SmartSettings::subKeyExist("setPropertiesDialog")) {
        return;
    }

    SmartSettings settings;
    int x, y, width, height;

    settings.setSubKey("setPropertiesDialog");
    bool shouldMaximize = settings.read<int>("isMaximized");
    x = settings.read<int>("x");
    y = settings.read<int>("y");
    width = settings.read<int>("width");
    height = settings.read<int>("height");
    move(x, y);
    resize(width, height);
    if (shouldMaximize) {
        showMaximized();
    }
}

void SetPropertiesDialog::writeSmartSettings() {
    if (!Settings::isAppInstalled()) {
        return;
    }
    SmartSettings settings;
    
    settings.setSubKey("setPropertiesDialog");
    settings.write<bool>("isMaximized", isMaximized());
    if (!isMaximized()) {   // Only remember un-maximised pos
        settings.writeWindowPos("x", x());
        settings.writeWindowPos("y", y());
        settings.writeWindowPos("width", width());
        settings.writeWindowPos("height", height());
    }
}

void SetPropertiesDialog::showEvent(QShowEvent*) {
    readSmartSettings();
}

void SetPropertiesDialog::hideEvent(QHideEvent*) {
    writeSmartSettings();
}

void SetPropertiesDialog::copyModelToWindow() {
    // General tab
    txtWindowText->setText(client->getText());
    txtDimensions->setText(stringLabel(client->getRelativeDimensions()));
    txtPos->setText(stringLabel(client->getRelativePosition()));
    txtSize->setText(stringLabel(client->getSize()));
    chVisible->setChecked(client->isVisible());
    chAlwaysOnTop->setChecked(client->isOnTop());
    chEnabled->setChecked(client->isEnabled());

    // Styles tab
    spnStyleBits->setValue(client->getStyleBits());
    spnExStyleBits->setValue(client->getExStyleBits());
    buildStylesList();
    updateStylesList();
}

void SetPropertiesDialog::copyWindowToModel() {
    // General tab
    client->setText(txtWindowText->text());
    QList<int> values = parseValueString(txtDimensions->text());
    QPoint topLeft(values.at(0), values.at(1));
    QPoint bottomRight(values.at(2), values.at(3));
    client->setDimensions(QRect(topLeft, bottomRight));
    client->setVisible(chVisible->isChecked());
    client->setOnTop(chAlwaysOnTop->isChecked());
    client->setEnabled(chEnabled->isChecked());

    // Styles tab
    uint styleBits = (uint)spnStyleBits->value();
    uint exStyleBits = (uint)spnExStyleBits->value();
    client->setStyleBits(styleBits, exStyleBits);
}

/*--------------------------------------------------------------------------+
| Helper function to create a special list item used for group              |
| headers (i.e. standard or extended styles).                               |
+--------------------------------------------------------------------------*/
QListWidgetItem* makeGroupHeaderItem(String name) {
    QListWidgetItem* item;
    item = new QListWidgetItem(name);
    item->setFlags(Qt::NoItemFlags);
    item->setForeground(QBrush(HEADER_COLOUR));
    item->setSizeHint(QSize(-1, 20));
    return item;
}

QListWidgetItem* makeStyleItem(WindowStyle* style) {
    QListWidgetItem* item;
    item = new QListWidgetItem(style->getName());
    item->setFlags(Qt::ItemIsEnabled |
                   Qt::ItemIsSelectable |
                   Qt::ItemIsUserCheckable);
    item->setSizeHint(QSize(-1, 15));
    return item;
}

/*--------------------------------------------------------------------------+
| Constructs list items for the standard and extended styles.               |
+--------------------------------------------------------------------------*/
void SetPropertiesDialog::buildStylesList() {
    WindowManager& manager = WindowManager::current();

    stylesList->addItem(makeGroupHeaderItem(STANDARD_STYLE_HEADER));
    foreach (WindowStyle* style, manager.getValidStandardStylesFor(client)) {
        stylesList->addItem(makeStyleItem(style));
    }

    stylesList->addItem(makeGroupHeaderItem(EXTENDED_STYLE_HEADER));
    foreach (WindowStyle* style, manager.getValidExtendedStylesFor(client)) {
        stylesList->addItem(makeStyleItem(style));
    }
}

/*--------------------------------------------------------------------------+
| Updates the checked/unchecked state of each item.                         |
+--------------------------------------------------------------------------*/
void SetPropertiesDialog::updateStylesList() {
    WindowManager& manager = WindowManager::current();
    QListWidgetItem* item = NULL;
    WindowStyle* style = NULL;
    bool isSet = false;

    uint styleBits = (uint)spnStyleBits->value();
    uint exStyleBits = (uint)spnExStyleBits->value();
    WindowStyleList newStyles = manager.parseStyle(client, styleBits, false);
    newStyles += manager.parseStyle(client, exStyleBits, true, GenericOnly);

    isModifyingList = true;
    for (int i = 0; i < stylesList->count(); ++i) {
        item = stylesList->item(i);
        if (item->text() != STANDARD_STYLE_HEADER && item->text() != EXTENDED_STYLE_HEADER) {
            style = manager.getStyleNamed(item->text());
            isSet = newStyles.contains(style);
            item->setCheckState(isSet ? Qt::Checked : Qt::Unchecked);
        }
    }
    isModifyingList = false;
}

/*--------------------------------------------------------------------------+
| Parses a string containing a comma separated list of values.              |
+--------------------------------------------------------------------------*/
QList<int> SetPropertiesDialog::parseValueString(const String& valueStr) {
    String str = valueStr;
    QList<int> valueList;

    // Strip any enclosing parenthesis
    if (str.startsWith("(")) str = str.right(str.size()-1);
    if (str.endsWith(")")) str = str.left(str.size()-1);

    QStringList stringList = str.split(',');
    bool ok;
    foreach (QString each, stringList) {
        valueList << each.trimmed().toInt(&ok);
    }
    return valueList;
}

/*--------------------------------------------------------------------------+
| Opens this window and sets the tab at 'index' to be the current.          |
+--------------------------------------------------------------------------*/
void SetPropertiesDialog::showAtTab(int index) {
    tabWidget->setCurrentIndex(index);
    show();
}

/*--------------------------------------------------------------------------+
| A property has been changed, set 'modified' flag.                         |
+--------------------------------------------------------------------------*/
void SetPropertiesDialog::propertyChanged() {
    this->setWindowModified(true);
}

void SetPropertiesDialog::dimensionTextChanged() {
    QList<int> values = parseValueString(txtDimensions->text());
    QRect rect = QRect(QPoint(values.at(0), values.at(1)),
                       QPoint(values.at(2), values.at(3)));

    txtPos->setText(stringLabel(rect.topLeft()));
    txtSize->setText(stringLabel(rect.size()));
}

void SetPropertiesDialog::posOrSizeTextChanged() {
    QList<int> values = parseValueString(txtPos->text());
    QPoint pos = QPoint(values.at(0), values.at(1));

    values = parseValueString(txtSize->text());
    QSize size = QSize(values.at(0), values.at(1));

    txtDimensions->setText(stringLabel(QRect(pos, size)));
}

/*--------------------------------------------------------------------------+
| The list item has been checked/unchecked, update the style bits.          |
+--------------------------------------------------------------------------*/
void SetPropertiesDialog::styleItemChanged(QListWidgetItem* item) {
    // Ignore header items
    if (item->text() == STANDARD_STYLE_HEADER ||
        item->text() == EXTENDED_STYLE_HEADER)
        return;

    // If we are in the middle of modifying the list, it will fire a
    // signal for each item. We should ignore them until the end.
    if (isModifyingList)
        return;

    WindowStyle* style = WindowManager::current().getStyleNamed(item->text());
    bool isSet = (item->checkState() == Qt::Checked);
    QSpinBox* control = (style->isExtended() ? spnExStyleBits : spnStyleBits);

    uint styleBits = (uint)control->value();
    if (isSet) {
        styleBits |= style->getValue();
    }
    else {
        styleBits &= ~(style->getValue());
    }
    control->setValue(styleBits);
}

/*--------------------------------------------------------------------------+
| The list selection has changed, update the description text.              |
+--------------------------------------------------------------------------*/
void SetPropertiesDialog::styleItemSelectionChanged(QListWidgetItem* item) {
    String text;
    QTextStream stream(&text);

    WindowStyle* style = WindowManager::current().getStyleNamed(item->text());
    stream << style->getName() << "\n"
           << hexString(style->getValue()) << "\n\n"
           << style->getDescription();
    txtStyleDesc->setPlainText(text);
}

void SetPropertiesDialog::setButtonClicked() {
    // TODO: Only set properties that have been modified
    copyWindowToModel();
    this->setWindowModified(false);
}

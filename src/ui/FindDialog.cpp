/////////////////////////////////////////////////////////////////////
// File: FindDialog.cpp                                            //
// Date: 2010-03-15                                                //
// Desc: The find window. Allows users to search for a window by a //
//   number of different criteria, including name, handle, style.  //
//   If only one window is found, it is selected in the window     //
//   tree. If multiple windows are found, they are displayed in a  //
//   separate list window.                                         //
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

#include "FindDialog.h"
#include "inspector/inspector.h"
#include "inspector/WindowManager.h"
#include "inspector/SearchCriteria.h"
#include "window_detective/Settings.h"
#include "window_detective/Logger.h"
#include "SearchResultsDialog.h"


FindDialog::FindDialog(MainWindow* mainWindow, QWidget* parent) :
    QDialog(parent), mainWindow(mainWindow),
    addButtonSignalMapper(this), removeButtonSignalMapper(this),
    numCriteriaItems(0) {
    if (Settings::stayOnTop) {
        setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    }
    setupUi(this);

    QPushButton* findButton = dialogButtons->addButton(tr("&Find"), QDialogButtonBox::AcceptRole);

    connect(qApp, SIGNAL(focusChanged(QWidget*, QWidget*)), this, SLOT(focusChanged(QWidget*, QWidget*)));
    connect(findButton, SIGNAL(clicked()), this, SLOT(findButtonClicked()));
    connect(&addButtonSignalMapper, SIGNAL(mapped(QWidget*)), this, SLOT(addCriteriaItem(QWidget*)));
    connect(&removeButtonSignalMapper, SIGNAL(mapped(QWidget*)), this, SLOT(removeCriteriaItem(QWidget*)));

    tabWidget->setCurrentIndex(0);
    rbWindowText->click();
}

void FindDialog::readSmartSettings() {
    // If the settings don't exist, don't try to read them.
    // It will only mess up the window positions by defaulting to 0
    if (!Settings::isAppInstalled() || !SmartSettings::subKeyExist("findDialog")) {
        return;
    }

    SmartSettings settings;
    settings.setSubKey("findDialog");

    // Window geometry
    bool shouldMaximize = settings.read<int>("isMaximized");
    int x = settings.read<int>("x");
    int y = settings.read<int>("y");
    int width = settings.read<int>("width");
    int height = settings.read<int>("height");
    move(x, y);
    resize(width, height);
    if (shouldMaximize) {
        showMaximized();
    }

    // Tab index
    tabWidget->setCurrentIndex(settings.read<int>("tabIndex"));

    // Basic tab
    int index = settings.read<int>("selection");
    switch (index) {
        case 0: rbWindowText->setChecked(true); break;
        case 1: rbHandle->setChecked(true); break;
        case 2: rbWindowClass->setChecked(true); break;
    }
    chCaseSensitive->setChecked(settings.read<bool>("isCaseSensitive"));
    chUseRegex->setChecked(settings.read<bool>("useRegex"));

    // Advanced tab
    // when i get it done
}

void FindDialog::writeSmartSettings() {
    if (!Settings::isAppInstalled()) {
        return;
    }
    SmartSettings settings;
    settings.setSubKey("findDialog");

    // Window geometry
    settings.write<bool>("isMaximized", isMaximized());
    if (!isMaximized()) {   // Only remember un-maximised pos
        settings.writeWindowPos("x", x());
        settings.writeWindowPos("y", y());
        settings.writeWindowPos("width", width());
        settings.writeWindowPos("height", height());
    }

    // Tab index
    settings.write<int>("tabIndex", tabWidget->currentIndex());

    // Basic tab
    int index = 0;
    if (rbWindowText->isChecked())       index = 0;
    else if (rbHandle->isChecked())      index = 1;
    else if (rbWindowClass->isChecked()) index = 2;
    settings.write<int>("selection", index);
    settings.write<bool>("isCaseSensitive", chCaseSensitive->isChecked());
    settings.write<bool>("useRegex", chUseRegex->isChecked());
}

QComboBox* FindDialog::makeBooleanRelationComboBox() {
    QComboBox* comboBox = new QComboBox();
    comboBox->addItems(QStringList()<<"and"<<"or");
    return comboBox;
}

/*--------------------------------------------------------------------------+
| Creates a new SearchResultsDialog and opens it on the list of             |
| found windows. The search criteria is also given so that the user         |
| can repeat the search if they want.                                       |
+--------------------------------------------------------------------------*/
void FindDialog::openResultsWindow(WindowList windows,
                                   SearchCriteria searchCriteria) {
    SearchResultsDialog* resultsWindow = new SearchResultsDialog(mainWindow);
    resultsWindow->setAttribute(Qt::WA_DeleteOnClose);
    resultsWindow->openOn(windows, searchCriteria);
}

/*--------------------------------------------------------------------------+
| Clears the values in the text, handle and class fields This is            |
| done when the user selects a different field.                             |
+--------------------------------------------------------------------------*/
void FindDialog::resetFields() {
    txtWindowText->setText("");
    spnHandle->setValue(0);
    cbWindowClass->clearEditText();
}

/*--------------------------------------------------------------------------+
| Removes all criteria item widgets and add a new one.                      |
+--------------------------------------------------------------------------*/
void FindDialog::resetCriteriaWidgets() {
    for (int i = 0; i < numCriteriaItems; ++i) {
        // TODO: Not sure why the following works, but it does. I should only have to delete
        //  the QLayoutItem returned from takeAt (that's what Qt's removeItem function does,
        //  with an invalidate() at the end).
        QLayoutItem* itm = itemsPanelLayout->takeAt(0);  // Remove first each time
        if (itm->widget()) delete itm->widget();
        delete itm;
        if (i != 0) {      // Index 0 of the boolean layout is padding
            itm = booleanRelationPanelLayout->takeAt(1);
            if (itm->widget()) delete itm->widget();
            delete itm;
        }
    }
    itemsPanelLayout->invalidate();
    booleanRelationPanelLayout->invalidate();
    numCriteriaItems = 0;
    addCriteriaItem(0);    // Must have at least one search criteria
}

/*--------------------------------------------------------------------------+
| This event is called whenever the dialog is opened. Here we do            |
| stuff like resetting widgets and search criteria.                         |
+--------------------------------------------------------------------------*/
void FindDialog::showEvent(QShowEvent*) {
    readSmartSettings();
    cbWindowClass->setList(Resources::windowClasses.values());
    cbWindowClass->clearEditText();
    resetCriteriaWidgets();
}

/*--------------------------------------------------------------------------+
| This event is called whenever the dialog is hidden/closed.                |
| It mainly just writes the smart settings. Note that when the find         |
| button is clicked, this event seems to happen *before* the find           |
| button's. So this can't delete anything that it will need.                |
+--------------------------------------------------------------------------*/
void FindDialog::hideEvent(QHideEvent*) {
    writeSmartSettings();
}

/*--------------------------------------------------------------------------+
| Since Qt does not provide a signal for a widget getting focus,            |
| we have to use QApplication::focusChanged and check the widgets           |
| to see if they are the ones we want.                                      |
+--------------------------------------------------------------------------*/
void FindDialog::focusChanged(QWidget* old, QWidget* now) {
    // Check the corresponding check box and reset the fields
    // if we are changing focus from one input field to another
    if (now == txtWindowText || now == rbWindowText) {
        rbWindowText->setChecked(true);
        if (old == spnHandle || old == cbWindowClass) {
            resetFields();
        }
    }
    else if (now == spnHandle || now == rbHandle) {
        rbHandle->setChecked(true);
        if (old == txtWindowText || old == cbWindowClass) {
            resetFields();
        }
    }
    else if (now == cbWindowClass || now == rbWindowClass) {
        rbWindowClass->setChecked(true);
        if (old == txtWindowText || old == spnHandle) {
            resetFields();
        }
    }
}

/*--------------------------------------------------------------------------+
| The add button was clicked on an item widget. Create a new item.          |
| If the list is empty, the new item is added. It will not have an          |
| associated boolean relation widget.                                       |
| Otherwise, the new item will be added after the sender.                   |
+--------------------------------------------------------------------------*/
void FindDialog::addCriteriaItem(QWidget* sender) {
    int index = 0;

    // Create the new widget to be added
    SearchCriteriaWidget* item = new SearchCriteriaWidget(itemsPanel);
    item->setObjectName("criteria"+String::number(numCriteriaItems));

    if (!sender) {
        itemsPanelLayout->insertWidget(0, item);
    }
    else {
        SearchCriteriaWidget* senderItem = dynamic_cast<SearchCriteriaWidget*>(sender);
        if (!senderItem) {
            Logger::debug("FindDialog::addCriteriaItem - invalid sender");
            delete item;
            return;
        }
        index = itemsPanelLayout->indexOf(senderItem);
        if (index == -1) {
            Logger::debug("FindDialog::addCriteriaItem - item not in list");
            delete item;
            return;
        }

        itemsPanelLayout->insertWidget(index+1, item); // insert after index

        // Add "and/or" widget
        QComboBox* cbBooleanRelation = makeBooleanRelationComboBox();
        int paddingHeight = senderItem->height() / 2;
        padding->setMinimumHeight(paddingHeight);
        padding->setMaximumHeight(paddingHeight);
        booleanRelationPanelLayout->insertWidget(index+1, cbBooleanRelation);
    }
    
    ++numCriteriaItems;
    connect(item, SIGNAL(addButtonClicked()), &addButtonSignalMapper, SLOT(map()));
    connect(item, SIGNAL(removeButtonClicked()), &removeButtonSignalMapper, SLOT(map()));
    addButtonSignalMapper.setMapping(item, item);
    removeButtonSignalMapper.setMapping(item, item);
}

/*--------------------------------------------------------------------------+
| The remove button was clicked on an item widget. Remove that item         |
| and schedule it for deletion.                                             |
+--------------------------------------------------------------------------*/
void FindDialog::removeCriteriaItem(QWidget* sender) {
    if (numCriteriaItems <= 1) return; // Cannot remove if there's only one

    SearchCriteriaWidget* item = dynamic_cast<SearchCriteriaWidget*>(sender);
    if (!item) {
        Logger::debug("FindDialog::removeCriteriaItem - invalid sender");
        return;
    }
    int index = itemsPanelLayout->indexOf(item);
    if (index == -1) {
        Logger::debug("FindDialog::removeCriteriaItem - item not in list");
        return;
    }

    // Remove the boolean relation between this item and the next.
    // Notes:
    //  - Index 0 is the first criteria item, but it is padding in the boolean layout.
    //  - If the first item is removed, the boolean relation between it and the
    //    next is removed. Otherwise it's the one between it and the previous item
    QLayoutItem* itm = booleanRelationPanelLayout->takeAt(index == 0 ? index + 1 : index);
    // TODO: Not sure why the following works, but it does. I should only have to delete
    //  the QLayoutItem returned from takeAt (that's what Qt's removeItem function does,
    //  with an invalidate() at the end).
    if (itm->widget()) delete itm->widget();
    delete itm;

    itemsPanelLayout->takeAt(index);
    item->deleteLater();
    numCriteriaItems--;
}

void FindDialog::findButtonClicked() {
    WindowList windows;
    SearchCriteria criteria;

    if (tabWidget->currentIndex() == 0) {
        SearchCriteriaItem item;
        if (rbWindowText->isChecked()) {
            if (chUseRegex->isChecked())
                item.op = StringMatchesRegex;
            else if (chCaseSensitive->isChecked())
                item.op = StringEqualCaseSensitive;
            else
                item.op = StringEqual;
            item.prop = TextProp;
            item.value = QVariant(txtWindowText->text());
        }
        else if (rbHandle->isChecked()) {
            item.prop = HandleProp;
            item.op = IntegerEqual;
            item.value = QVariant(spnHandle->value());
        }
        else if (rbWindowClass->isChecked()) {
            item.prop = WindowClassProp;
            item.op = GenericEqual;
            item.value = qVariantFromValue<WindowClass*>(cbWindowClass->currentValue());
        }
        criteria.setCriteria(item);
    }
    else {
        for (int i = 0; i < numCriteriaItems; ++i) {
            SearchCriteriaWidget* criteriaWidget = NULL;
            QComboBox* booleanRelationComboBox = NULL;
            QLayoutItem* layoutItem = NULL;

            // Get the criteria widget from the layout (very messy!)
            layoutItem = itemsPanelLayout->itemAt(i);
            if (layoutItem) {
                criteriaWidget = dynamic_cast<SearchCriteriaWidget*>(layoutItem->widget());
            }
            if (!criteriaWidget) {
                Logger::debug("FindDialog::findButtonClicked - could not get SearchCriteriaWidget");
                return;
            }

            if (i == 0) {   // Add the first item (should always exist)
                criteria.setCriteria(criteriaWidget->getCriteriaItem());
            }
            else {          // Add any others with their boolean relation
                layoutItem = booleanRelationPanelLayout->itemAt(i);
                if (layoutItem) {
                    booleanRelationComboBox = dynamic_cast<QComboBox*>(layoutItem->widget());
                }
                if (!booleanRelationComboBox) {
                    Logger::debug("FindDialog::findButtonClicked - could not get boolean relation");
                    return;
                }
                criteria.addCriteria(criteriaWidget->getCriteriaItem(),
                                     (BooleanRelation)booleanRelationComboBox->currentIndex());
            }
        }
    }

    windows = WindowManager::current().find(criteria);
    openResultsWindow(windows, criteria);
}

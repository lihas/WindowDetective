/////////////////////////////////////////////////////////////////////
// File: SystemColoursPane.cpp                                     //
// Date: 2017-06-30                                                //
// Desc: Part of the SystemInfoDialog. Lists all system UI colours //
//   obtained by the GetSysColor WinAPI function.                  //
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

#include "SystemColoursPane.h"
#include "window_detective/Logger.h"
#include "window_detective/Resources.h"
#include "window_detective/StringFormatter.h"
#include "window_detective/QtHelpers.h"


// TODO: Similarly to the window hyperlinks I will do in property windows,
//   system colour names should also have a hyperlink which opens this dialog

SystemColoursModel::SystemColoursModel(QObject* parent) :
    QAbstractTableModel(parent),
    constants(), defaultColours() {

    QHash<uint,String> colourMap = Resources::getConstants("SystemColour");
    QHash<uint,String>::const_iterator i;

    // Remember initial system colours, so the user can revert back to them
    for (i = colourMap.begin(); i != colourMap.end(); ++i) {
        COLORREF rgbValue = GetSysColor(i.key());
        defaultColours.insert(i.key(), rgbValue);
    }

    // Build the list of constants. The map isn't used directly, since
    // we want a specific ordering (by id).
    for (i = colourMap.begin(); i != colourMap.end(); ++i) {
        constants.append(SystemConstant(i.key(), i.value()));
    }
    qSort(constants.begin(), constants.end());
}

/*--------------------------------------------------------------------------+
| Restores the system colours to their initial values, which were obtained  |
| when this object is first created.                                        |
| As far as i know, there is no Win API to do this.                         |
+--------------------------------------------------------------------------*/
void SystemColoursModel::reset() {
    const uint numColours = defaultColours.size();
    INT* idArray = new INT[numColours];
    COLORREF* valueArray = new COLORREF[numColours];

    uint index = 0;
    QHash<uint,COLORREF>::const_iterator i;
    for (i = defaultColours.begin(); i != defaultColours.end(); ++i) {
        idArray[index] = i.key();
        valueArray[index] = i.value();
        ++index;
    }
    SetSysColors(numColours, idArray, valueArray);
    delete[] idArray;
    delete[] valueArray;

    // Update all data in second and third columns
    emit dataChanged(createIndex(0, 1), createIndex(constants.size(), 2));
}

QVariant SystemColoursModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() >= constants.size() || index.row() < 0) {
        return QVariant();
    }

    SystemConstant constant = constants.at(index.row());
    if (index.column() == 0 && role == Qt::DisplayRole) {
        return constant.name;
    }

    QColor colour = QColorFromCOLORREF(GetSysColor(constant.id));
    if (index.column() == 1 && role == Qt::DisplayRole) {
        return stringLabel(colour);
    }
    else if (index.column() == 2 && role == Qt::BackgroundRole) {
        return colour;
    }

    if (index.column() == 1 && role == Qt::TextAlignmentRole) {
        return Qt::AlignHCenter;
    }

    return QVariant();
}

QVariant SystemColoursModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();
    
    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0:  return tr("Name");
            case 1:  return tr("RGB");
            case 2:  return tr("Colour");
        }
    }
    return QVariant();
}

Qt::ItemFlags SystemColoursModel::flags(const QModelIndex&) const {
    return Qt::ItemIsEnabled;
}

bool SystemColoursModel::setData(const QModelIndex& index, const QVariant& value, int role) {
    SystemConstant constant = constants.at(index.row());
    if (index.column() == 2 && role == Qt::BackgroundRole) { // Colour value was set
        const INT colourId = constant.id;
        COLORREF rgbValue = COLORREFFromQColor(value.value<QColor>());
        if (!SetSysColors(1, &colourId, &rgbValue)) {
            Logger::osError("Could not set system colour "+constant.name);
        }
        emit dataChanged(index, index);
        return true;
    }
    else {
        return false;
    }
}


SystemColoursPane::SystemColoursPane(QWidget* parent):
    QWidget(parent) {
    setupUi(this);

    SystemColoursModel* model = new SystemColoursModel();
    table->setModel(model);

    connect(resetColoursButton, SIGNAL(clicked()), model, SLOT(reset()));
    connect(table, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(colourTableDoubleClicked(const QModelIndex&)));

    // Workaround to get columns to resize correctly - http://bugreports.qt.nokia.com/browse/QTBUG-9352
    table->setVisible(false);
    table->resizeColumnsToContents();
    table->resizeRowsToContents();
    table->setVisible(true);
}

/*--------------------------------------------------------------------------+
| A cell in the colours table was double-clicked.                           |
| If it is the 3rd column, show the colour picker dialog to let the user    |
| choose and set a new colour.                                              |
+--------------------------------------------------------------------------*/
void SystemColoursPane::colourTableDoubleClicked(const QModelIndex& index) {
    if (index.column() != 2) return;     // Colour cells are in the 3nd column

    QAbstractItemModel* model = table->model();
    QColor currentColour = model->data(index, Qt::BackgroundRole).value<QColor>();
    QColor chosen = QColorDialog::getColor(currentColour, this, tr("Select colour"));
    if (chosen.isValid()) {
        model->setData(index, chosen, Qt::BackgroundRole);
    }
}
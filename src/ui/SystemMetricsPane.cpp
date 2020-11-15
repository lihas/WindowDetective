/////////////////////////////////////////////////////////////////////
// File: SystemMetricsPane.cpp                                     //
// Date: 2017-06-30                                                //
// Desc: Part of the SystemInfoDialog. Lists all system            //
//   information obtained by the GetSystemMetrics WinAPI function. //
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

#include "SystemMetricsPane.h"
#include "window_detective/StringFormatter.h"

SystemMetricsModel::SystemMetricsModel(QObject* parent) :
    QAbstractTableModel(parent) {

    // Build the list of constants. The map isn't used directly, since
    // we want a specific ordering (by id).
    QHash<uint,String> metricMap = Resources::getConstants("SystemMetric");
    QHash<uint,String>::const_iterator i;
    for (i = metricMap.begin(); i != metricMap.end(); ++i) {
        constants.append(SystemConstant(i.key(), i.value()));
    }
    qSort(constants.begin(), constants.end());
}

QVariant SystemMetricsModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() >= constants.size() || index.row() < 0) {
        return QVariant();
    }

    SystemConstant constant = constants.at(index.row());
    if (role == Qt::DisplayRole) {
        switch (index.column()) {
            case 0:  return constant.name;
            case 1:  return stringLabel(GetSystemMetrics(constant.id));
        }
    }

    return QVariant();
}

QVariant SystemMetricsModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();
    
    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0:  return tr("Name");
            case 1:  return tr("Value");
        }
    }
    return QVariant();
}

Qt::ItemFlags SystemMetricsModel::flags(const QModelIndex&) const {
    return Qt::ItemIsEnabled;
}


SystemMetricsPane::SystemMetricsPane(QWidget* parent):
    QWidget(parent) {
    setupUi(this);

    SystemMetricsModel* model = new SystemMetricsModel();
    table->setModel(model);

    // Workaround to get columns to resize correctly - http://bugreports.qt.nokia.com/browse/QTBUG-9352
    table->setVisible(false);  
    table->resizeColumnsToContents();
    table->resizeRowsToContents();
    table->setVisible(true);
}
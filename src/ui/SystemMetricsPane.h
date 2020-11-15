/////////////////////////////////////////////////////////////////////
// File: SystemMetricsPane.h                                       //
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

#ifndef SYSTEM_METRICS_PANE_H
#define SYSTEM_METRICS_PANE_H

#include <QtWidgets>
#include "window_detective/include.h"
#include "ui/forms/ui_SystemMetricsPane.h"
#include "inspector/SystemConstant.h"


class SystemMetricsModel : public QAbstractTableModel {
    Q_OBJECT
private:
    QList<SystemConstant> constants;

public:
    SystemMetricsModel(QObject* parent = 0);
    ~SystemMetricsModel() {}

    int rowCount(const QModelIndex&) const { return constants.size(); }
    int columnCount(const QModelIndex&) const { return 2; }   // Name, value
    QVariant data(const QModelIndex& index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
};


class SystemMetricsPane : public QWidget, private Ui::SystemMetricsPane {
    Q_OBJECT
public:
    SystemMetricsPane(QWidget* parent = 0);
};

#endif // SYSTEM_METRICS_PANE_H
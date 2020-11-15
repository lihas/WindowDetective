/////////////////////////////////////////////////////////////////////
// File: SystemColoursPane.h                                       //
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

#ifndef SYSTEM_COLOURS_PANE_H
#define SYSTEM_COLOURS_PANE_H

#include <QtWidgets>
#include "window_detective/include.h"
#include "ui/forms/ui_SystemColoursPane.h"
#include "inspector/SystemConstant.h"


class SystemColoursModel : public QAbstractTableModel {
    Q_OBJECT
private:
    QList<SystemConstant> constants;
    QHash<uint,COLORREF> defaultColours;

public:
    SystemColoursModel(QObject* parent = 0);
    ~SystemColoursModel() {}

    int rowCount(const QModelIndex&) const { return constants.size(); }
    int columnCount(const QModelIndex&) const { return 3; }   // Name, RGB string, actual colour
    QVariant data(const QModelIndex& index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::DisplayRole);
public slots:
    void reset();
};


class SystemColoursPane : public QWidget, private Ui::SystemColoursPane {
    Q_OBJECT
public:
    SystemColoursPane(QWidget* parent = 0);

public slots:
    void colourTableDoubleClicked(const QModelIndex& index);
};

#endif // SYSTEM_COLOURS_PANE_H
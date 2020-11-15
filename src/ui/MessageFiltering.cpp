//////////////////////////////////////////////////////////////////////////
// File: MessageFiltering.cpp                                           //
// Date: 2012-03-08                                                     //
// Desc: Contains model and struct definitions for filtering (including //
//   or excluding) monitored messages in the MessagesPane.            //
//////////////////////////////////////////////////////////////////////////

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

#include "MessageFiltering.h"


MessageFilterModel::MessageFilterModel(QObject* parent) :
    QAbstractListModel(parent) {
}

QVariant MessageFilterModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() >= list.size() || index.row() < 0) {
        return QVariant();
    }

    if (role == Qt::DisplayRole) {
        return list.at(index.row()).name;
    }
    else if (role == Qt::CheckStateRole) {
        return list.at(index.row()).include ? Qt::Checked : Qt::Unchecked;
    }

    return QVariant();
}

QVariant MessageFilterModel::headerData(int section, Qt::Orientation orientation, int role) const {
    return QVariant();
}

Qt::ItemFlags MessageFilterModel::flags(const QModelIndex& index) const {
    return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled;
}

bool MessageFilterModel::setData(const QModelIndex& index, const QVariant& value, int role) {
    if (role == Qt::CheckStateRole) {
        list[index.row()].include = value.value<bool>();
        emit dataChanged(index, index);
        return true;
    }
    else {
        return false;
    }
}

void MessageFilterModel::setAllCheckStates(bool checked) {
    QList<MessageFilter>::iterator i;
    for (i = list.begin(); i != list.end(); ++i) {
        i->include = checked;
    }
    emit dataChanged(createIndex(0, 0), createIndex(list.size(), 0));
}

void MessageFilterModel::setCheckStates(QModelIndexList indices, bool checked) {
    if (!indices.isEmpty()) {
        qSort(indices.begin(), indices.end());
        foreach (QModelIndex index, indices) {
            list[index.row()].include = checked;
        }
        emit dataChanged(indices.first(), indices.last());
    }
}

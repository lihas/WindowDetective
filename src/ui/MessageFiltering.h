//////////////////////////////////////////////////////////////////////////
// File: MessageFiltering.h                                           //
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

#ifndef MESSAGE_FILTERING_H
#define MESSAGE_FILTERING_H

#include <QtWidgets>
#include "window_detective/include.h"


struct MessageHighlight {
    String name;
    QColor foregroundColour;
    QColor backgroundColour;
};


struct MessageFilter {
    String name;
    bool include;

    MessageFilter(String name, bool include) : 
        name(name), include(include) {}
    bool operator<(const MessageFilter& other) const { return this->name < other.name; }
};


class MessageFilterModel : public QAbstractListModel {
    Q_OBJECT
private:
    QList<MessageFilter> list;

public:
    MessageFilterModel(QObject* parent = 0);
    ~MessageFilterModel() {}

    void setList(QList<MessageFilter> l) { list = l; }
    QList<MessageFilter> getList() const { return list; }
    int rowCount(const QModelIndex&) const { return list.size(); }
    int columnCount(const QModelIndex&) const { return 1; }
    QVariant data(const QModelIndex& index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::DisplayRole);
    void setAllCheckStates(bool checked);
    void setCheckStates(QModelIndexList indices, bool checked);
};


#endif   // MESSAGE_FILTERING_H
/////////////////////////////////////////////////////////////////////
// File: MessageFilterDialog.h                                   //
// Date: 2011-06-23                                                //
// Desc: Dialog window used to manage message filters for a        //
//   messages window. The filters can be inclusions/exclusions or  //
//   highlighting of particular messages.                          //
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

#ifndef MESSAGE_FILTER_DIALOG_H
#define MESSAGE_FILTER_DIALOG_H

#include <QtWidgets>
#include "window_detective/include.h"
#include "ui/forms/ui_MessageFilterDialog.h"
#include "ui/MessageFiltering.h"


class MessageFilterDialog : public QDialog, private Ui::MessageFilterDialog {
    Q_OBJECT
private:
    MessageFilterModel filterModel;
    QSortFilterProxyModel proxyModel;
    QStringListModel nameModel;       // For combo box, only shows name

public:
    MessageFilterDialog(QWidget* parent = 0);
    ~MessageFilterDialog() {}

    void setTabIndex(int i) { tabWidget->setCurrentIndex(i); }
    void setMessageFilters(QList<MessageFilter> list);
    QList<MessageFilter> getMessageFilters();
    void setIncludeOthers(bool b);
    bool shouldIncludeOthers();
    void setHighlightedMessages(QList<MessageHighlight> highlights);
    QList<MessageHighlight> getHighlightedMessages();
    void addHighlight(String messageName, QColor foreColour, QColor backColour);
public slots:
    void includeAll();
    void excludeAll();
    void includeSelected();
    void excludeSelected();
    void addNewHighlight();
    void removeSelectedHighlights();
    void highlightCellDoubleClicked(int row, int column);
    void highlightItemSelectionChanged();
};

#endif   // MESSAGE_FILTER_DIALOG_H
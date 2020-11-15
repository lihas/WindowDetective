/////////////////////////////////////////////////////////////////////
// File: SystemInfoDialog.h                                        //
// Date: 2011-06-01                                                //
// Desc: Dialog to list various system information.                //
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

#ifndef SYSTEM_INFO_VIEWER_H
#define SYSTEM_INFO_VIEWER_H

#include <QtWidgets>
#include "window_detective/include.h"
#include "ui/forms/ui_SystemInfoDialog.h"


class SystemInfoDialog : public QDialog, private Ui::SystemInfoDialog {
    Q_OBJECT
public:
    SystemInfoDialog(QWidget* parent = 0);

protected:
    void readSmartSettings();
    void writeSmartSettings();
    void showEvent(QShowEvent* e);
    void hideEvent(QHideEvent* e);
};

#endif // SYSTEM_INFO_VIEWER_H

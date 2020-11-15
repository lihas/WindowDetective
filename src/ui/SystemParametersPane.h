/////////////////////////////////////////////////////////////////////
// File: SystemParametersPane.h                                    //
// Date: 2017-06-30                                                //
// Desc: Part of the SystemInfoDialog. Lists all system parameters //
//   obtained by the SystemParametersInfo WinAPI function.         //
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

#ifndef SYSTEM_PARAMETERS_PANE_H
#define SYSTEM_PARAMETERS_PANE_H

#include <QtWidgets>
#include "window_detective/include.h"
#include "ui/forms/ui_SystemParametersPane.h"


class SystemParametersPane : public QWidget, private Ui::SystemParametersPane {
    Q_OBJECT
public:
    SystemParametersPane(QWidget* parent = 0);

    void populate();
    void save();
private slots:
    void valueChanged();
    void buttonClicked(QAbstractButton* button);
private:
    void markAllUnmodified();
    void getSystemParameter(uint key, uint param1, PVOID param2);
    void setSystemParameter(uint key, uint param1, PVOID param2);
    template<typename T> T getParameter(uint key);
    template<typename T> void setParameter1(uint key, T value);
    template<typename T> void setParameter2(uint key, T value);
    template<typename T> void setParameter3(uint key, T value);
    template<> bool getParameter<bool>(uint key);
    template<> void setParameter1<bool>(uint key, bool value);
    template<> void setParameter2<bool>(uint key, bool value);
};


#endif // SYSTEM_PARAMETERS_PANE_H
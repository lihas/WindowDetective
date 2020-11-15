/////////////////////////////////////////////////////////////////////
// File: SetPropertiesDialog.h                                   //
// Date: 2010-03-24                                                //
// Desc: Used to set the properties of a window. It has a number   //
//   of tabs to group the different properties and a "Set" button  //
//   to apply any changes to the real window.                      //
//   This dialog is modal, since there can only be one per window  //
//   and we also don't want the user changing anything else while  //
//   this is open, otherwise it might disrupt the window's state.  //
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

#ifndef SET_PROPERTIES_DIALOG_H
#define SET_PROPERTIES_DIALOG_H

#include <QtWidgets>
#include "window_detective/include.h"
#include "inspector/inspector.h"
#include "ui/forms/ui_SetPropertiesDialog.h"


#define STANDARD_STYLE_HEADER  " --- Standard Styles --------------------"
#define EXTENDED_STYLE_HEADER  " --- Extended Styles --------------------"
#define HEADER_COLOUR          (QColor(100, 100, 150))


class SetPropertiesDialog : public QDialog, private Ui::SetPropertiesDialog {
    Q_OBJECT
private:
    Window* client;
    QMap<QWidget*, QVariant> lastValues;
    bool isModifyingList;
public:
    SetPropertiesDialog(Window* window, QWidget* parent = 0);
    ~SetPropertiesDialog() {}
    
    void readSmartSettings();
    void writeSmartSettings();
    void showEvent(QShowEvent* e);
    void hideEvent(QHideEvent* e);
    void copyModelToWindow();
    void copyWindowToModel();
    void showAtTab(int index);
private:
    void buildStylesList();
    QList<int> parseValueString(const String& str);
private slots:
    void propertyChanged();
    void dimensionTextChanged();
    void posOrSizeTextChanged();
    void updateStylesList();
    void styleItemChanged(QListWidgetItem*);
    void styleItemSelectionChanged(QListWidgetItem*);
    void setButtonClicked();
};


#endif   // SET_PROPERTIES_DIALOG_H
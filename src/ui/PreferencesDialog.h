/////////////////////////////////////////////////////////////////////
// File: PreferencesDialog.h                                       //
// Date: 2010-03-06                                                //
// Desc: The UI window which displays the app's preferences.       //
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

#ifndef PREFERENCES_DIALOG_H
#define PREFERENCES_DIALOG_H

#include "window_detective/include.h"
#include <QtWidgets>
#include "window_detective/Settings.h"
#include "ui/forms/ui_PreferencesDialog.h"

class PreferencesDialog : public QDialog, private Ui::PreferencesDialog {
    Q_OBJECT
private:
    bool hasHighlightWindowChanged;
    bool hasStayOnTopChanged;
    QMenu settingsMenu;

public:
    PreferencesDialog(QWidget *parent = 0);
    ~PreferencesDialog() {}

    void copyModelToWindow();
    void copyWindowToModel();
signals:
    void highlightWindowChanged();
    void stayOnTopChanged(bool shouldStayOnTop);
protected:
    void showEvent(QShowEvent* e);
private slots:
    void borderRadioButtonClicked();
    void filledRadioButtonClicked();
    void highlightWindowValueChanged();
    void chooseFolderButtonClicked();
    void restoreDefaults();
    void exportSettings();
    void importSettings();
    void applyPreferences();
};

#endif   // PREFERENCES_DIALOG_H
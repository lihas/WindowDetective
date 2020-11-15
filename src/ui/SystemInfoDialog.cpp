/////////////////////////////////////////////////////////////////////
// File: SystemInfoDialog.cpp                                      //
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

#include "SystemInfoDialog.h"
#include "window_detective/Settings.h"
#include "window_detective/StringFormatter.h"
#include "window_detective/main.h"


SystemInfoDialog::SystemInfoDialog(QWidget* parent):
    QDialog(parent) {
    if (Settings::stayOnTop) {
        setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    }
    setupUi(this);
    tabWidget->setCurrentIndex(0);

    String cssString;
    QTextStream stream(&cssString);
    loadCssStyle("SystemInfoDialog", stream);
    setStyleSheet(cssString);
}

void SystemInfoDialog::readSmartSettings() {
    // If the settings don't exist, don't try to read them.
    // It will only mess up the window positions by defaulting to 0
    if (!Settings::isAppInstalled() || !SmartSettings::subKeyExist("systemInfoViewer")) {
        return;
    }

    SmartSettings settings;
    settings.setSubKey("systemInfoViewer");

    // Window geometry
    bool shouldMaximize = settings.read<int>("isMaximized");
    int x = settings.read<int>("x");
    int y = settings.read<int>("y");
    int width = settings.read<int>("width");
    int height = settings.read<int>("height");
    move(x, y);
    resize(width, height);
    if (shouldMaximize) {
        showMaximized();
    }

    // Tab index
    tabWidget->setCurrentIndex(settings.read<int>("tabIndex"));
}

void SystemInfoDialog::writeSmartSettings() {
    if (!Settings::isAppInstalled()) {
        return;
    }
    SmartSettings settings;

    // Main window geometry
    settings.setSubKey("systemInfoViewer");
    settings.write<bool>("isMaximized", isMaximized());
    if (!isMaximized()) {   // Only remember un-maximised pos
        settings.writeWindowPos("x", x());
        settings.writeWindowPos("y", y());
        settings.writeWindowPos("width", width());
        settings.writeWindowPos("height", height());
    }

    // Tab index
    settings.write<int>("tabIndex", tabWidget->currentIndex());
}

void SystemInfoDialog::showEvent(QShowEvent*) {
    readSmartSettings();

    // Do this every time the dialog is opened, in case data has changed
    generalInfoTab->populate();
}

void SystemInfoDialog::hideEvent(QHideEvent*) {
    writeSmartSettings();
}
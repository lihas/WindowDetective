/////////////////////////////////////////////////////////////////////
// File: PreferencesDialog.cpp                                     //
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

#include "PreferencesDialog.h"
#include "window_detective/main.h"
#include "window_detective/Settings.h"
#include "window_detective/Logger.h"


PreferencesDialog::PreferencesDialog(QWidget *parent) :
    QDialog(parent),
    hasHighlightWindowChanged(false),
    hasStayOnTopChanged(false),
    settingsMenu() {
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    if (Settings::stayOnTop) {
        setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    }
    setupUi(this);
    QPushButton* okButton = dialogButtons->addButton(QDialogButtonBox::Ok);
    QPushButton* applyButton = dialogButtons->addButton(QDialogButtonBox::Apply);

    settingsMenu.addAction(actnRestoreDefaults);
    settingsMenu.addSeparator();
    settingsMenu.addAction(actnExportSettings);
    settingsMenu.addAction(actnImportSettings);
    settingsButton->setMenu(&settingsMenu);

    // TODO: This isn't implemented yet, so hide it in the UI
    chPickTransparent->hide();

    connect(rbBorder, SIGNAL(clicked()), this, SLOT(borderRadioButtonClicked()));
    connect(rbFilled, SIGNAL(clicked()), this, SLOT(filledRadioButtonClicked()));
    connect(btnChooseFolder, SIGNAL(clicked()), this, SLOT(chooseFolderButtonClicked()));
    connect(slHighlighterTransparency, SIGNAL(valueChanged(int)), this, SLOT(highlightWindowValueChanged()));
    connect(actnRestoreDefaults, SIGNAL(triggered()), this, SLOT(restoreDefaults()));
    connect(actnExportSettings, SIGNAL(triggered()), this, SLOT(exportSettings()));
    connect(actnImportSettings, SIGNAL(triggered()), this, SLOT(importSettings()));
    connect(okButton, SIGNAL(clicked()), this, SLOT(applyPreferences()));
    connect(applyButton, SIGNAL(clicked()), this, SLOT(applyPreferences()));
}

/*--------------------------------------------------------------------------+
| Copies the model data (Settings in this case) to the UI widgets           |
+--------------------------------------------------------------------------*/
void PreferencesDialog::copyModelToWindow() {
    // General
    switch (Settings::regexType) {
        case QRegExp::RegExp: rbStandardRegex->click(); break;
        case QRegExp::Wildcard: rbWildcardRegex->click(); break;
        case QRegExp::WildcardUnix: rbWildcardUnixRegex->click(); break;
        default:     break;  // None selected - shouldn't happen
    }

    chStayOnTop->setChecked(Settings::stayOnTop);

    // Window Tree
    chGreyHiddenWindows->setChecked(Settings::greyHiddenWindows);
    spnChangeDuration->setValue(Settings::treeChangeDuration);
    btnCreatedColour1->setColour(Settings::itemCreatedColourImmediate);
    btnCreatedColour2->setColour(Settings::itemCreatedColourUnexpanded);
    btnDestroyedColour1->setColour(Settings::itemDestroyedColourImmediate);
    btnDestroyedColour2->setColour(Settings::itemDestroyedColourUnexpanded);
    btnChangedColour1->setColour(Settings::itemChangedColourImmediate);
    btnChangedColour2->setColour(Settings::itemChangedColourUnexpanded);
    chOpenPropertiesOnSelect->setChecked(Settings::openPropertiesOnSelect);

    // Picker
    chPickTransparent->setChecked(Settings::canPickTransparentWindows);
    chHideWhilePicking->setChecked(Settings::hideWhilePicking);

    switch (Settings::highlighterStyle) {
        case Border: rbBorder->click(); break;
        case Filled: rbFilled->click(); break;
        default:     break;  // None selected - shouldn't happen
    }

    btnHighlighterColour->setColour(Settings::highlighterColour);
    slHighlighterTransparency->setValue(Settings::highlighterColour.alpha());
    spnThickness->setValue(Settings::highlighterBorderThickness);

    QStringList labels = Settings::infoLabels;
    chWindowClass->setChecked(labels.contains("windowClass"));
    chWindowText->setChecked(labels.contains("text"));
    chWindowHandle->setChecked(labels.contains("handle"));
    chParentHandle->setChecked(labels.contains("parentHandle"));
    chWindowDimensions->setChecked(labels.contains("dimensions"));
    chWindowPosition->setChecked(labels.contains("position"));
    chWindowSize->setChecked(labels.contains("size"));

    // Logging
    chLogToFile->setChecked(Settings::enableLogging);
    chEnableBalloon->setChecked(Settings::enableBalloonNotifications);
    txtLogFolder->setText(Settings::logOutputFolder);
}

/*--------------------------------------------------------------------------+
| Copies the widget's values to their respective model data.                |
+--------------------------------------------------------------------------*/
void PreferencesDialog::copyWindowToModel() {
    // General
    if (rbStandardRegex->isChecked())
        Settings::regexType = QRegExp::RegExp;
    else if (rbWildcardRegex->isChecked())
        Settings::regexType = QRegExp::Wildcard;
    else if (rbWildcardUnixRegex->isChecked())
        Settings::regexType = QRegExp::WildcardUnix;

    hasStayOnTopChanged = (Settings::stayOnTop != chStayOnTop->isChecked());
    Settings::stayOnTop = chStayOnTop->isChecked();

    // Window Tree
    Settings::greyHiddenWindows = chGreyHiddenWindows->isChecked();
    Settings::treeChangeDuration = spnChangeDuration->value();
    Settings::itemCreatedColourImmediate = btnCreatedColour1->getColour();
    Settings::itemCreatedColourUnexpanded = btnCreatedColour2->getColour();
    Settings::itemDestroyedColourImmediate = btnDestroyedColour1->getColour();
    Settings::itemDestroyedColourUnexpanded = btnDestroyedColour2->getColour();
    Settings::itemChangedColourImmediate = btnChangedColour1->getColour();
    Settings::itemChangedColourUnexpanded = btnChangedColour2->getColour();
    Settings::openPropertiesOnSelect = chOpenPropertiesOnSelect->isChecked();

    // Picker
    Settings::canPickTransparentWindows = chPickTransparent->isChecked();
    Settings::hideWhilePicking = chHideWhilePicking->isChecked();

    if (rbBorder->isChecked())
        Settings::highlighterStyle = Border;
    else if (rbFilled->isChecked())
        Settings::highlighterStyle = Filled;

    Settings::highlighterColour = btnHighlighterColour->getColour();
    Settings::highlighterColour.setAlpha(slHighlighterTransparency->value());
    Settings::highlighterBorderThickness = spnThickness->value();

    Settings::infoLabels.clear();
    if (chWindowClass->isChecked())
        Settings::infoLabels.append("windowClass");
    if (chWindowText->isChecked())
        Settings::infoLabels.append("text");
    if (chWindowHandle->isChecked())
        Settings::infoLabels.append("handle");
    if (chParentHandle->isChecked())
        Settings::infoLabels.append("parentHandle");
    if (chWindowDimensions->isChecked())
        Settings::infoLabels.append("dimensions");
    if (chWindowPosition->isChecked())
        Settings::infoLabels.append("position");
    if (chWindowSize->isChecked())
        Settings::infoLabels.append("size");

    // Logging
    Settings::enableLogging = chLogToFile->isChecked();
    Settings::logOutputFolder = txtLogFolder->text();
    Settings::enableBalloonNotifications = chEnableBalloon->isChecked();
    if (Settings::enableLogging) {
        Logger::current().startLoggingToFile();
    }
    else {
        Logger::current().stopLoggingToFile();
    }
}

void PreferencesDialog::showEvent(QShowEvent*) {
    copyModelToWindow();
}

void PreferencesDialog::borderRadioButtonClicked() {
    // Set a sensible transparency to use for border style
    if (slHighlighterTransparency->value() < 128)
        slHighlighterTransparency->setValue(255);
}

void PreferencesDialog::filledRadioButtonClicked() {
    // Set a sensible transparency to use for filled style
    if (slHighlighterTransparency->value() > 200)
        slHighlighterTransparency->setValue(64);
}

void PreferencesDialog::chooseFolderButtonClicked() {
    String folder = QFileDialog::getExistingDirectory(this,
                        tr("Select a folder to write the log to"),
                        QDir::homePath());
    if (!folder.isEmpty())
        txtLogFolder->setText(folder);
}

/*--------------------------------------------------------------------------+
| We need to know when any of the highlight window's properties             |
| has been changed because it will need to be rebuilt.                      |
+--------------------------------------------------------------------------*/
void PreferencesDialog::highlightWindowValueChanged() {
    hasHighlightWindowChanged = true;
}

/*--------------------------------------------------------------------------+
| Restores settings to the default values they were when the                |
| application was first installed.                                          |
+--------------------------------------------------------------------------*/
void PreferencesDialog::restoreDefaults() {
    QMessageBox msgBox;
    msgBox.setText(tr("Restore Defaults?"));
    msgBox.setInformativeText(tr("This will reset the settings to the values they were when "
                                 "the application was first installed.\n"
                                 "Are you sure you want to continue?"));
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);

    if (msgBox.exec() == QMessageBox::Yes) {
        Settings::restore();
        Settings::write();
        copyModelToWindow();
    }
}

/*--------------------------------------------------------------------------+
| Writes the settings to a file chosen by the user.                         |
+--------------------------------------------------------------------------*/
void PreferencesDialog::exportSettings() {
    String fileName = QFileDialog::getSaveFileName(this, tr("Export Settings"),
                        QDir::homePath(), "Settings Files (*.ini);;All Files (*.*)");
    if (fileName.isEmpty()) {
        return;    // User cancelled
    }

    QFile file(fileName);
    if (!file.open(QFile::WriteOnly)) {
        String msg = tr("Could not open file for writing: \"%1\"").arg(fileName);
        QMessageBox::warning(this, tr("Export Settings"), msg);
        Logger::error(msg);
        return;
    }
    file.close();   // QSettings will open the file when it needs to write it

    Settings::write(fileName);
}

/*--------------------------------------------------------------------------+
| Reads the settings from a file chosen by the user.                        |
+--------------------------------------------------------------------------*/
void PreferencesDialog::importSettings() {
    String fileName = QFileDialog::getOpenFileName(this, tr("Import Settings"),
                        QDir::homePath(), "Settings Files (*.ini);;All Files (*.*)");
    if (fileName.isEmpty()) {
        return;    // User cancelled
    }

    QFile file(fileName);
    if (!file.open(QFile::ReadOnly)) {
        String msg = tr("Could not read file: \"%1\"").arg(fileName);
        QMessageBox::warning(this, tr("Import Settings"), msg);
        Logger::error(msg);
        return;
    }
    file.close();   // QSettings will open the file when it needs to read from it

    Settings::read(fileName);
    Settings::write();
    copyModelToWindow();
}

/*--------------------------------------------------------------------------+
| Applies the values to the model and saves them. If any highlight window   |
| values have changed, a signal is emitted to tell any HighlightWindows to  |
| rebuild themselves.                                                       |
+--------------------------------------------------------------------------*/
void PreferencesDialog::applyPreferences() {
    copyWindowToModel();
    Settings::write();

    if (hasStayOnTopChanged) {
        emit stayOnTopChanged(Settings::stayOnTop);
        hasStayOnTopChanged = false;
    }

    if (hasHighlightWindowChanged) {
        emit highlightWindowChanged();
        hasHighlightWindowChanged = false;
    }
}

//////////////////////////////////////////////////////////////////////////
// File: Settings.xpp                                                   //
// Date: 2010-02-26                                                     //
// Desc: Handles reading and writing settings that are stored in the    //
//   Windows registry. Values are written when the application exits    //
//   or when the user changes them in the preferences.                  //
//   If the application is run on a machine which it is not             //
//   installed on, no settings are saved to the registry unless         //
//   specified by the user.                                             //
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

#include "Settings.h"
#include "window_detective/main.h"
#include "window_detective/Logger.h"
#include "window_detective/QtHelpers.h"


int Settings::appInstalled = -1;

bool Settings::canPickTransparentWindows;
bool Settings::hideWhilePicking;
bool Settings::stayOnTop;
bool Settings::allowInspectOwnWindows;
int Settings::messageTimeoutPeriod;
QRegExp::PatternSyntax Settings::regexType;
bool Settings::greyHiddenWindows;
int Settings::treeChangeDuration;
QColor Settings::itemCreatedColourImmediate;
QColor Settings::itemCreatedColourUnexpanded;
QColor Settings::itemDestroyedColourImmediate;
QColor Settings::itemDestroyedColourUnexpanded;
QColor Settings::itemChangedColourImmediate;
QColor Settings::itemChangedColourUnexpanded;
QColor Settings::highlighterColour;
bool Settings::openPropertiesOnSelect;
HighlightStyle Settings::highlighterStyle;
int Settings::highlighterBorderThickness;
QStringList Settings::infoLabels;
bool Settings::enableLogging;
bool Settings::enableBalloonNotifications;
String Settings::logOutputFolder;

/*--------------------------------------------------------------------------+
| If the app's registry key does not exist (because this app was            |
| not installed), then don't create it. No settings will be saved.          |
+--------------------------------------------------------------------------*/
bool Settings::isAppInstalled() {
    if (appInstalled != -1)
        return (bool)appInstalled; // Cached result

    HKEY key;
    LONG result = RegOpenKeyExW(HKEY_CURRENT_USER,
                                L"Software\\Window Detective", 0,
                                KEY_QUERY_VALUE, &key);
    appInstalled = ((result == ERROR_SUCCESS) ? 1 : 0);
    return (bool)appInstalled;
}

/*--------------------------------------------------------------------------+
| Sets up default values for settings.                                      |
+--------------------------------------------------------------------------*/
void Settings::initialize() {
    canPickTransparentWindows = false;
    hideWhilePicking = true;
    stayOnTop = false;
    allowInspectOwnWindows = false;
    messageTimeoutPeriod = 500;
    regexType = QRegExp::RegExp;
    greyHiddenWindows = false;
    treeChangeDuration = 500;
    itemCreatedColourImmediate = QColor(0,255,0);
    itemCreatedColourUnexpanded = QColor(128,255,128);
    itemDestroyedColourImmediate = QColor(255,0,0);
    itemDestroyedColourUnexpanded = QColor(255,128,128);
    itemChangedColourImmediate = QColor(0,0,0);
    itemChangedColourUnexpanded = QColor(80,80,80);
    openPropertiesOnSelect = false;
    highlighterColour = Qt::red;
    highlighterStyle = Border;
    highlighterBorderThickness = 4;
    infoLabels = String("windowClass,handle,dimensions,size").split(",");
    enableLogging = false;
    enableBalloonNotifications = true;
    logOutputFolder = "";
}

/*--------------------------------------------------------------------------+
| Reads the settings from the registry (under HKCU\Software).               |
| If the registry key does not exist, then don't try to read.               |
+--------------------------------------------------------------------------*/
void Settings::read() {
    if (!isAppInstalled())
        return;
    QSettings registrySettings(APP_NAME, APP_NAME);
    read(registrySettings);
}

/*--------------------------------------------------------------------------+
| Writes the settings to the registry. If the Window Detective              |
| registry key does not already exist, then it won't be written to,         |
| as the application probably isn't installed.                              |
+--------------------------------------------------------------------------*/
void Settings::write() {
    if (!isAppInstalled())
        return;
    QSettings registrySettings(APP_NAME, APP_NAME);
    write(registrySettings);
}

/*--------------------------------------------------------------------------+
| Reads (imports) the settings from the given INI file.                     |
+--------------------------------------------------------------------------*/
void Settings::read(const String& fileName) {
    QSettings iniSettings(fileName, QSettings::IniFormat);
    read(iniSettings);
}

/*--------------------------------------------------------------------------+
| Writes (exports) the settings to the given INI file. If the file          |
| does not exist, it will be created.                                       |
+--------------------------------------------------------------------------*/
void Settings::write(String& fileName) {
    QSettings iniSettings(fileName, QSettings::IniFormat);
    write(iniSettings);
}

/*--------------------------------------------------------------------------+
| Helper functions to read a value from the settings and, if it             |
| exists, convert it to the correct type and store it in the given          |
| variable (passed by reference).                                           |
+--------------------------------------------------------------------------*/
void readBool(const QSettings& settings, String name, bool& var) {
    if (settings.contains(name)) var = settings.value(name).toBool();
}
void readInt(const QSettings& settings, String name, int& var) {
    if (settings.contains(name)) var = settings.value(name).toInt();
}
void readString(const QSettings& settings, String name, String& var) {
    if (settings.contains(name)) var = settings.value(name).toString();
}
void readColour(const QSettings& settings, String name, QColor& var) {
    if (settings.contains(name)) var = stringToColour(settings.value(name).toString());
}
template <typename EnumType>
void readEnum(const QSettings& settings, String name, EnumType& var) {
    if (settings.contains(name)) var = static_cast<EnumType>(settings.value(name).toInt());
}

/*--------------------------------------------------------------------------+
| This function does the actual reading of values, either from the          |
| registry or from an INI file.                                             |
+--------------------------------------------------------------------------*/
void Settings::read(const QSettings& settings) {
    readBool(settings, "canPickTransparentWindows", canPickTransparentWindows);
    readBool(settings, "hideWhilePicking", hideWhilePicking);
    readBool(settings, "stayOnTop", stayOnTop);
    readBool(settings, "allowInspectOwnWindows", allowInspectOwnWindows);
    readInt(settings, "messageTimeoutPeriod", messageTimeoutPeriod);
    readEnum<QRegExp::PatternSyntax>(settings, "regexType", regexType);

    readBool(settings, "tree/greyHiddenWindows", greyHiddenWindows);
    readInt(settings, "tree/changeDuration", treeChangeDuration);
    readColour(settings, "tree/itemCreatedColourImmediate", itemCreatedColourImmediate);
    readColour(settings, "tree/itemCreatedColourUnexpanded", itemCreatedColourUnexpanded);
    readColour(settings, "tree/itemDestroyedColourImmediate", itemDestroyedColourImmediate);
    readColour(settings, "tree/itemDestroyedColourUnexpanded", itemDestroyedColourUnexpanded);
    readColour(settings, "tree/itemChangedColourImmediate", itemChangedColourImmediate);
    readColour(settings, "tree/itemChangedColourUnexpanded", itemChangedColourUnexpanded);
    readBool(settings, "tree/openPropertiesOnSelect", openPropertiesOnSelect);

    readColour(settings, "highlighter/colour", highlighterColour);
    readEnum<HighlightStyle>(settings, "highlighter/style", highlighterStyle);
    readInt(settings, "highlighter/borderThickness", highlighterBorderThickness);

    String infoLabelString = infoLabels.join(",");  // Have to convert to string and back again
    readString(settings, "infoWindow/labels", infoLabelString);
    infoLabels = infoLabelString.split(",");

    readBool(settings, "logging/enable", enableLogging);
    readBool(settings, "logging/enableBalloonNotifications", enableBalloonNotifications);
    readString(settings, "logging/outputFolder", logOutputFolder);
}

/*--------------------------------------------------------------------------+
| This function does the actual writing of values, either to the            |
| registry or to an INI file.                                               |
+--------------------------------------------------------------------------*/
void Settings::write(QSettings& settings) {
    settings.setValue("canPickTransparentWindows", canPickTransparentWindows);
    settings.setValue("hideWhilePicking", hideWhilePicking);
    settings.setValue("stayOnTop", stayOnTop);
    settings.setValue("allowInspectOwnWindows", allowInspectOwnWindows);
    settings.setValue("messageTimeoutPeriod", messageTimeoutPeriod);
    settings.setValue("regexType", static_cast<int>(regexType));

    settings.setValue("tree/greyHiddenWindows", greyHiddenWindows);
    settings.setValue("tree/changeDuration", treeChangeDuration);
    settings.setValue("tree/itemCreatedColourImmediate", colourToString(itemCreatedColourImmediate));
    settings.setValue("tree/itemCreatedColourUnexpanded", colourToString(itemCreatedColourUnexpanded));
    settings.setValue("tree/itemDestroyedColourImmediate", colourToString(itemDestroyedColourImmediate));
    settings.setValue("tree/itemDestroyedColourUnexpanded", colourToString(itemDestroyedColourUnexpanded));
    settings.setValue("tree/itemChangedColourImmediate", colourToString(itemChangedColourImmediate));
    settings.setValue("tree/itemChangedColourUnexpanded", colourToString(itemChangedColourUnexpanded));
    settings.setValue("tree/openPropertiesOnSelect", openPropertiesOnSelect);

    settings.setValue("highlighter/colour", colourToString(highlighterColour));
    settings.setValue("highlighter/style", static_cast<int>(highlighterStyle));
    settings.setValue("highlighter/borderThickness", highlighterBorderThickness);

    settings.setValue("infoWindow/labels", infoLabels.join(","));

    settings.setValue("logging/enable", enableLogging);
    settings.setValue("logging/enableBalloonNotifications", enableBalloonNotifications);
    settings.setValue("logging/outputFolder", logOutputFolder);
}

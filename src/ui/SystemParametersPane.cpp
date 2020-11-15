/////////////////////////////////////////////////////////////////////
// File: SystemParametersPane.cpp                                  //
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

#include "SystemParametersPane.h"
#include "window_detective/QtHelpers.h"
#include "window_detective/Logger.h"
#include "inspector/WindowMisc.h"


SystemParametersPane::SystemParametersPane(QWidget* parent):
    QWidget(parent) {
    setupUi(this);
    int listWidth = parameterGroupList->sizeHintForColumn(0) + 5;
    parameterGroupList->setMinimumWidth(listWidth);  // Fix width to fit contents
    parameterGroupList->setMaximumWidth(listWidth);
    parameterGroupList->setCurrentRow(0);

    foreach(QAbstractButton* widget, pages->findChildren<QAbstractButton*>()) {
        connect(widget, SIGNAL(clicked(bool)), this, SLOT(valueChanged()));
    }
    foreach(QSpinBox* widget, pages->findChildren<QSpinBox*>()) {
        connect(widget, SIGNAL(valueChanged(int)), this, SLOT(valueChanged()));
    }

    connect(buttonBox, SIGNAL(clicked(QAbstractButton*)), this, SLOT(buttonClicked(QAbstractButton*)));
}

/*--------------------------------------------------------------------------+
| Gets various general system information (by calling the                   |
| SystemParametersInfo function) and puts it in the UI.                     |
+--------------------------------------------------------------------------*/
// TODO:
//  * Show info on multiple monitors. See http://msdn.microsoft.com/en-us/library/dd145072%28v=VS.85%29.aspx
void SystemParametersPane::populate() {
    //===  Accessibility parameters  ===
    animations->setChecked(getParameter<bool>(SPI_GETCLIENTAREAANIMATION));
    focusBorder->setValue(QSize(getParameter<uint>(SPI_GETFOCUSBORDERWIDTH),
                                getParameter<uint>(SPI_GETFOCUSBORDERHEIGHT)));
    notificationPopupDuration->setValue(getParameter<ulong>(SPI_GETMESSAGEDURATION));
    mouseSonar->setChecked(getParameter<bool>(SPI_GETMOUSESONAR));
    mouseVanish->setChecked(getParameter<bool>(SPI_GETMOUSEVANISH));

    //===  Desktop parameters  ===
    WCHAR path[MAX_PATH];
    getSystemParameter(SPI_GETDESKWALLPAPER, MAX_PATH, &path);
    wallpaperPath->setText(wCharToString(path));
    clearType->setChecked(getParameter<bool>(SPI_GETCLEARTYPE));
    dropShadow->setChecked(getParameter<bool>(SPI_GETDROPSHADOW));
    fontSmoothing->setChecked(getParameter<bool>(SPI_GETFONTSMOOTHING));

    //===  Icon parameters  ===
    LOGFONT logFont;
    getSystemParameter(SPI_GETICONTITLELOGFONT, sizeof(LOGFONT), &logFont);
    if (iconTitleFont->getModel()) { delete iconTitleFont->getModel(); }
    iconTitleFont->setModel(new WinFont(logFont));
    iconSpacing->setValue(QSize(getParameter<int>(SPI_ICONHORIZONTALSPACING),
                                getParameter<int>(SPI_ICONVERTICALSPACING)));
    iconTitleWrap->setChecked(getParameter<bool>(SPI_GETICONTITLEWRAP));
    
    //===  Input parameters  ===
    beeper->setChecked(getParameter<bool>(SPI_GETBEEP));
    blockSimulatedInput->setChecked(getParameter<bool>(SPI_GETBLOCKSENDINPUTRESETS));
    keyboardCues->setChecked(getParameter<bool>(SPI_GETKEYBOARDCUES));
    keyboardSpeed->setValue(getParameter<uint>(SPI_GETKEYBOARDSPEED));
    keyboardDelay->setValue(getParameter<int>(SPI_GETKEYBOARDDELAY));
    mouseSpeed->setValue(getParameter<int>(SPI_GETMOUSESPEED));
    mouseTrails->setValue(getParameter<int>(SPI_GETMOUSETRAILS));
    mouseHoverTime->setValue(getParameter<uint>(SPI_GETMOUSEHOVERTIME));
    mouseHoverSize->setValue(QSize(getParameter<uint>(SPI_GETMOUSEHOVERWIDTH),
                                   getParameter<uint>(SPI_GETMOUSEHOVERHEIGHT)));
    snapDefaultButton->setChecked(getParameter<bool>(SPI_GETSNAPTODEFBUTTON));
    mouseWheelX->setValue(getParameter<uint>(SPI_GETWHEELSCROLLCHARS));
    mouseWheelY->setValue(getParameter<uint>(SPI_GETWHEELSCROLLLINES));

    //===  Menu parameters  ===
    bool isAlignmentRight = getParameter<bool>(SPI_GETMENUDROPALIGNMENT);
    menuAlignmentLeft->setChecked(!isAlignmentRight);
    menuAlignmentRight->setChecked(isAlignmentRight);
    bool isMenuAnimationFade = getParameter<bool>(SPI_GETMENUFADE);
    menuAnimationFade->setChecked(isMenuAnimationFade);
    menuAnimationSlide->setChecked(!isMenuAnimationFade);
    menuDelay->setValue(getParameter<uint>(SPI_GETMENUSHOWDELAY));

    //===  Screen saver parameters  ===
    screenSaverPassword->setChecked(getParameter<bool>(SPI_GETSCREENSAVESECURE));
    screenSaverTimeout->setValue(getParameter<int>(SPI_GETSCREENSAVETIMEOUT));

    //===  Time-out parameters  ===
    // None of these parameters are supported on Vista or lower
    if (getOSVersion() >= 601) {
        hungTimeout->setValue(getParameter<int>(SPI_GETHUNGAPPTIMEOUT));
        killTimeout->setValue(getParameter<int>(SPI_GETWAITTOKILLTIMEOUT));
        killServiceTimeout->setValue(getParameter<int>(SPI_GETWAITTOKILLSERVICETIMEOUT));
    }
    else {
        hungTimeout->setEnabled(false);
        killTimeout->setEnabled(false);
        killServiceTimeout->setEnabled(false);
    }

    //===  UI effects parameters  ===
    comboBoxAnimation->setChecked(getParameter<bool>(SPI_GETCOMBOBOXANIMATION));
    cursorShadow->setChecked(getParameter<bool>(SPI_GETCURSORSHADOW));
    hotTracking->setChecked(getParameter<bool>(SPI_GETHOTTRACKING));
    listBoxSmoothScrolling->setChecked(getParameter<bool>(SPI_GETLISTBOXSMOOTHSCROLLING));
    menuAnimationEnabled->setChecked(getParameter<bool>(SPI_GETMENUANIMATION));
    selectionFade->setChecked(getParameter<bool>(SPI_GETSELECTIONFADE));
    toolTipAnimation->setChecked(getParameter<bool>(SPI_GETTOOLTIPANIMATION));
    bool isToolTipAnimationFade = getParameter<bool>(SPI_GETTOOLTIPFADE);
    toolTipAnimationFade->setChecked(isToolTipAnimationFade);
    toolTipAnimationSlide->setChecked(!isToolTipAnimationFade);

    //===  Window parameters  ===
    windowTracking->setChecked(getParameter<bool>(SPI_GETACTIVEWINDOWTRACKING));
    windowTrackingTop->setChecked(getParameter<bool>(SPI_GETACTIVEWNDTRKZORDER));
    windowTrackingDelay->setValue(getParameter<uint>(SPI_GETACTIVEWNDTRKTIMEOUT));
    windowBorder->setValue(getParameter<uint>(SPI_GETBORDER));
    caretWidth->setValue(getParameter<uint>(SPI_GETCARETWIDTH));
    windowDocking->setChecked(getParameter<bool>(SPI_GETDOCKMOVING));
    dragMaximize->setChecked(getParameter<bool>(SPI_GETDRAGFROMMAXIMIZE));
    mouseDockThreshold->setValue(getParameter<uint>(SPI_GETMOUSEDOCKTHRESHOLD));
    mouseUndockThreshold->setValue(getParameter<uint>(SPI_GETMOUSEDRAGOUTTHRESHOLD));
    verticalSnapping->setChecked(getParameter<bool>(SPI_GETSNAPSIZING));
    mouseRestoreThreshold->setValue(getParameter<uint>(SPI_GETMOUSESIDEMOVETHRESHOLD));
    fullWindowDragging->setChecked(getParameter<bool>(SPI_GETDRAGFULLWINDOWS));
    foregroundFlashCount->setValue(getParameter<uint>(SPI_GETFOREGROUNDFLASHCOUNT));
    foregroundLockTimeout->setValue(getParameter<uint>(SPI_GETFOREGROUNDLOCKTIMEOUT));

    markAllUnmodified();
}

/*--------------------------------------------------------------------------+
| Applies any changed parameters.                                           |
+--------------------------------------------------------------------------*/
void SystemParametersPane::save() {
    #define SET(key, widget, getter, setter) \
        if (widget->isWindowModified()) { setter(key, widget->getter); }

    //===  Accessibility parameters  ===
    SET(SPI_SETCLIENTAREAANIMATION, animations, isChecked(), setParameter2<bool>);
    SET(SPI_SETFOCUSBORDERWIDTH, focusBorder, value().width(), setParameter2<uint>);
    SET(SPI_SETFOCUSBORDERHEIGHT, focusBorder, value().height(), setParameter2<uint>);
    SET(SPI_SETMESSAGEDURATION, notificationPopupDuration, value(), setParameter2<ulong>);
    SET(SPI_SETMOUSESONAR, mouseSonar, isChecked(), setParameter2<bool>);
    SET(SPI_SETMOUSEVANISH, mouseVanish, isChecked(), setParameter2<bool>);

    //===  Desktop parameters  ===
    SET(SPI_SETCLEARTYPE, clearType, isChecked(), setParameter2<bool>);
    SET(SPI_SETDROPSHADOW, dropShadow, isChecked(), setParameter2<bool>);
    SET(SPI_SETFONTSMOOTHING, fontSmoothing, isChecked(), setParameter1<bool>);

    //===  Icon parameters  ===
    SET(SPI_ICONHORIZONTALSPACING, iconSpacing, value().width(), setParameter1<int>);
    SET(SPI_ICONVERTICALSPACING, iconSpacing, value().height(), setParameter1<int>);
    SET(SPI_SETICONTITLEWRAP, iconTitleWrap, isChecked(), setParameter1<bool>);

    //===  Input parameters  ===
    SET(SPI_SETBEEP, beeper, isChecked(), setParameter1<bool>);
    SET(SPI_SETBLOCKSENDINPUTRESETS, blockSimulatedInput, isChecked(), setParameter1<bool>);
    SET(SPI_SETKEYBOARDCUES, keyboardCues, isChecked(), setParameter2<bool>);
    SET(SPI_SETKEYBOARDSPEED, keyboardSpeed, value(), setParameter1<uint>);
    SET(SPI_SETKEYBOARDDELAY, keyboardDelay, value(), setParameter1<int>);
    SET(SPI_SETMOUSESPEED, mouseSpeed, value(), setParameter2<int>);
    SET(SPI_SETMOUSETRAILS, mouseTrails, value(), setParameter1<int>);
    SET(SPI_SETMOUSEHOVERTIME, mouseHoverTime, value(), setParameter1<uint>);
    SET(SPI_SETMOUSEHOVERWIDTH, mouseHoverSize, value().width(), setParameter1<uint>);
    SET(SPI_SETMOUSEHOVERHEIGHT, mouseHoverSize, value().height(), setParameter1<uint>);
    SET(SPI_SETSNAPTODEFBUTTON, snapDefaultButton, isChecked(), setParameter1<bool>);
    SET(SPI_SETWHEELSCROLLCHARS, mouseWheelX, value(), setParameter1<uint>);
    SET(SPI_SETWHEELSCROLLLINES, mouseWheelY, value(), setParameter1<uint>);

    //===  Menu parameters  ===
    SET(SPI_SETMENUDROPALIGNMENT, menuAlignmentRight, isChecked(), setParameter1<bool>);
    SET(SPI_SETMENUFADE, menuAnimationFade, isChecked(), setParameter2<bool>);
    SET(SPI_SETMENUSHOWDELAY, menuDelay, value(), setParameter1<uint>);

    //===  Screen saver parameters  ===
    SET(SPI_SETSCREENSAVESECURE, screenSaverPassword, isChecked(), setParameter1<bool>);
    SET(SPI_SETSCREENSAVETIMEOUT, screenSaverTimeout, value(), setParameter1<int>);

    //===  Time-out parameters  ===
    // None of these parameters are supported on Vista or lower
    if (getOSVersion() >= 601) {
        SET(SPI_SETHUNGAPPTIMEOUT, hungTimeout, value(), setParameter1<int>);
        SET(SPI_SETWAITTOKILLTIMEOUT, killTimeout, value(), setParameter1<int>);
        SET(SPI_SETWAITTOKILLSERVICETIMEOUT, killServiceTimeout, value(), setParameter1<int>);
    }

    //===  UI effects parameters  ===
    SET(SPI_SETCOMBOBOXANIMATION, comboBoxAnimation, isChecked(), setParameter2<bool>);
    SET(SPI_SETCURSORSHADOW, cursorShadow, isChecked(), setParameter2<bool>);
    SET(SPI_SETHOTTRACKING, hotTracking, isChecked(), setParameter2<bool>);
    SET(SPI_SETLISTBOXSMOOTHSCROLLING, listBoxSmoothScrolling, isChecked(), setParameter2<bool>);
    SET(SPI_SETMENUANIMATION, menuAnimationEnabled, isChecked(), setParameter2<bool>);
    SET(SPI_SETSELECTIONFADE, selectionFade, isChecked(), setParameter2<bool>);
    SET(SPI_SETTOOLTIPANIMATION, toolTipAnimation, isChecked(), setParameter2<bool>);
    SET(SPI_SETTOOLTIPFADE, toolTipAnimationFade, isChecked(), setParameter2<bool>);

    //===  Window parameters  ===
    SET(SPI_SETACTIVEWINDOWTRACKING, windowTracking, isChecked(), setParameter2<bool>);
    SET(SPI_SETACTIVEWNDTRKZORDER, windowTrackingTop, isChecked(), setParameter2<bool>);
    SET(SPI_SETACTIVEWNDTRKTIMEOUT, windowTrackingDelay, value(), setParameter2<uint>);
    SET(SPI_SETBORDER, windowBorder, value(), setParameter1<int>);
    SET(SPI_SETCARETWIDTH, caretWidth, value(), setParameter2<uint>);
    SET(SPI_SETDOCKMOVING, windowDocking, isChecked(), setParameter1<bool>);                //
    SET(SPI_SETDRAGFROMMAXIMIZE, dragMaximize, isChecked(), setParameter1<bool>);           // MSDN says these should be param 2,
    SET(SPI_SETMOUSEDOCKTHRESHOLD, mouseDockThreshold, value(), setParameter1<uint>);       // but they are not.
    SET(SPI_SETMOUSEDRAGOUTTHRESHOLD, mouseUndockThreshold, value(), setParameter1<uint>);  //
    SET(SPI_SETSNAPSIZING, verticalSnapping, isChecked(), setParameter1<bool>);             //
    SET(SPI_SETMOUSESIDEMOVETHRESHOLD, mouseRestoreThreshold, value(), setParameter1<uint>);//
    SET(SPI_SETDRAGFULLWINDOWS, fullWindowDragging, isChecked(), setParameter1<bool>);
    SET(SPI_SETFOREGROUNDFLASHCOUNT, foregroundFlashCount, value(), setParameter2<uint>);
    SET(SPI_SETFOREGROUNDLOCKTIMEOUT, foregroundLockTimeout, value(), setParameter2<uint>);

    markAllUnmodified();
}

/*--------------------------------------------------------------------------+
| Triggered when any input widget has it's value changed.                   |
+--------------------------------------------------------------------------*/
void SystemParametersPane::valueChanged() {
    QWidget* widget = dynamic_cast<QWidget*>(sender());
    if (widget) {
        // Walk up the parent hierarchy, marking each as modified.
        do {
            widget->setWindowModified(true);
            widget = dynamic_cast<QWidget*>(widget->parent());
        } while (widget && !dynamic_cast<QStackedWidget*>(widget));
        buttonBox->button(QDialogButtonBox::Apply)->setEnabled(true);
    }
}

/*--------------------------------------------------------------------------+
| Triggered when reset or apply button is pressed.                          |
+--------------------------------------------------------------------------*/
void SystemParametersPane::buttonClicked(QAbstractButton* button) {
    if (button == buttonBox->button(QDialogButtonBox::Apply)) {
        save();
    }
    else if (button == buttonBox->button(QDialogButtonBox::Reset)) {
        populate();
    }
}

/*--------------------------------------------------------------------------+
| Removes the modified status from all input widgets.                       |
+--------------------------------------------------------------------------*/
void SystemParametersPane::markAllUnmodified() {
    foreach(QWidget* widget, findChildren<QWidget*>()) {
        widget->setWindowModified(false);
    }
    buttonBox->button(QDialogButtonBox::Apply)->setEnabled(false);
}


void SystemParametersPane::getSystemParameter(uint key, uint param1, PVOID param2) {
    if (!SystemParametersInfoW(key, param1, param2, 0)) {
        Logger::osError(TR("Unable to get system parameter %1").arg(hexString(key, 4)));
    }
}

void SystemParametersPane::setSystemParameter(uint key, uint param1, PVOID param2) {
    if (!SystemParametersInfoW(key, param1, param2, /*if permanent: SPIF_UPDATEINIFILE | */SPIF_SENDCHANGE)) {
        Logger::osError(TR("Unable to set system parameter %1").arg(hexString(key, 4)));
    }
}

template<typename T>
T SystemParametersPane::getParameter(uint key) {
    T value = 0;
    getSystemParameter(key, 0, &value);
    return value;
}

template<typename T>
void SystemParametersPane::setParameter1(uint key, T value) {
    setSystemParameter(key, value, 0);
}

template<typename T>
void SystemParametersPane::setParameter2(uint key, T value) {
    setSystemParameter(key, 0, (PVOID)value);
}

template<typename T>
void SystemParametersPane::setParameter3(uint key, T value) {
    setSystemParameter(key, 0, &value);
}

template<>
bool SystemParametersPane::getParameter<bool>(uint key) {
    BOOL value = FALSE;
    getSystemParameter(key, 0, &value);
    return value == TRUE;
}

template<>
void SystemParametersPane::setParameter1(uint key, bool value) {
    setSystemParameter(key, value ? TRUE : FALSE, 0);
}

template<>
void SystemParametersPane::setParameter2(uint key, bool value) {
    setSystemParameter(key, 0, (PVOID)(value ? TRUE : FALSE));
}
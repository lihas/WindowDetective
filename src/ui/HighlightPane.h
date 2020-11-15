/////////////////////////////////////////////////////////////////////
// File: HighlightPane.h                                       //
// Date: 2010-02-17                                                //
// Desc: This window is created as a "layered" window which is     //
//   transparent to mouse input and is always shown on top of      //
//   every other windows while still allowing those windows to     //
//   show through it. It is meant to be shown over the window      //
//   which needs to be highlighted. Various styles can be used to  //
//   show the highlight. The most basic is a red border of a       //
//   specified thickness, displayed at 100% alpha transparency,    //
//   with the rest of the window invisible (clipped). Another      //
//   style is a fully coloured window with an alpha transparency   //
//   of around 10-20%.                                             //
//   Note: Throughout this class, the term 'client' is used to     //
//   describe the window that this will display info for.          //
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

#ifndef HIGHLIGHT_PANE_H
#define HIGHLIGHT_PANE_H

#include <QtWidgets>
#include "window_detective/include.h"
#include "ui/InfoPane.h"
#include "inspector/inspector.h"


// Unique name for highlighter window.
#define HIGHLIGHT_WINDOW_CLASS_NAME  L"WD_HighlightPane"

class HighlightPane : public QObject {
    Q_OBJECT
private:
    HWND handle;                 // Handle of this window
    Window* prevWindow;          // Cache last client window highlighted
    InfoPane* infoWindow;        // Displays info about the highlighted window
    QTimer* flashTimer;          // Timer for flashing this window
    int flashTimes;              // Number of times to flash (show then hide)
public:
    static bool isWindowClassCreated;
    static void createWindowClass();
    static LRESULT CALLBACK wndProc(HWND, UINT, WPARAM, LPARAM);

    HighlightPane(bool showInfoWindow = false);
    ~HighlightPane();

    void create();
    void highlight(Window* window);
    void flash(Window* window, int interval = 250, int times = 4);
    void moveTo(Window* window);
    void show();
    void hide();
public slots:
    void update();
private slots:
    void doSingleFlash();
private:
    void createBorderRegion(const QRect& windowRect);
};

#endif   // HIGHLIGHT_PANE_H
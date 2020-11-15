/////////////////////////////////////////////////////////////////////
// File: MessagesPane.h                                          //
// Date: 2010-05-03                                                //
// Desc: Used to display the messages of a window. Typically added //
//   to an MDI area as a child window.                             //
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

#ifndef MESSAGES_PANE_H
#define MESSAGES_PANE_H

#include <QtWidgets>
#include "window_detective/include.h"
#include "ui/forms/ui_MessagesPane.h"
#include "inspector/inspector.h"
#include "ui/MessageFilterDialog.h"


class MessagesPane : public QMainWindow, private Ui::MessagesPane {
    Q_OBJECT
private:
    QIcon startIcon, stopIcon;
    Window* window;

public:
    MessagesPane(Window* window, QWidget* parent = 0);
    ~MessagesPane() {}

    Window* getModel() { return window; }
    void openFilterDialog(int tab = 0);
    //QMenu makeContextMenu(/*selected items*/);
    void start() { messageWidget->start(); }
    void stop() { messageWidget->stop(); }
signals:
    void locateWindow(Window*);
private slots:
    void windowDeleted(Window*);
    //void showContextMenu(const QPoint& pos);
    void locateActionTriggered();
    void saveButtonClicked();
    void toggleRunState();
    void autoExpandButtonClicked();
    void filterButtonClicked();
    void highlightButtonClicked();
};


#endif   // MESSAGES_PANE_H
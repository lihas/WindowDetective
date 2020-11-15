/////////////////////////////////////////////////////////////////////
// File: PropertiesPane.h                                        //
// Date: 2010-03-23                                                //
// Desc: Used to display the properties of a window. Typically     //
//   added to an MDI area as a child window.                       //
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

#ifndef PROPERTY_PANE_H
#define PROPERTY_PANE_H

#include <QtWidgets>
#include "window_detective/include.h"
#include "inspector/inspector.h"
#include "ui/forms/ui_PropertiesPane.h"


class PropertiesPane : public QMainWindow, private Ui::PropertiesPane {
    Q_OBJECT
private:
    Window* model;
    QList<AbstractPropertyPage*> pages;
    QList<bool> hasInitialized;   // Flags to lazy init each page when selected

public:
    PropertiesPane(Window* window, QWidget* parent = 0);
    ~PropertiesPane() {}

    void createPages();
    void addPropertyPage(AbstractPropertyPage* page, String title);
signals:
    void locateWindow(Window*);
private slots:
    void windowDeleted(Window*);
    void locateActionTriggered();
    void flashActionTriggered();
    void linkClicked(const QString& link);
    void saveToFile();
    void updateTabPage(int index);
    void update();
};


#endif   // PROPERTY_WINDOW_H
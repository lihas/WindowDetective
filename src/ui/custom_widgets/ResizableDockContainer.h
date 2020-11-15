/////////////////////////////////////////////////////////////////////
// File: ResizableDockContainer.h                                  //
// Date: 2017-06-26                                                //
// Desc: This is a hack to control the size of dock widgets.       //
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

#ifndef RESIZABLE_DOCK_CONTAINER_H
#define RESIZABLE_DOCK_CONTAINER_H

#include <QtWidgets>

class ResizableDockContainer : public QWidget {
    Q_OBJECT
private:
    QSize initialSize;

public:
    ResizableDockContainer(QWidget* parent = 0) : QWidget(parent) {}
    ~ResizableDockContainer() {}

	void setInitialSize(QSize s) { initialSize = s; }
	void setInitialSize(int width, int height) { initialSize = QSize(width, height); }
	QSize sizeHint() const { return initialSize; }
};

#endif   // RESIZABLE_DOCK_CONTAINER_H
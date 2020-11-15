/////////////////////////////////////////////////////////////////////
// File: BalloonTip.h                                            //
// Date: 2010-09-29                                                //
// Desc: Widget for displaying a tooltip in a speach-bubble or     //
//   balloon style similar to the Windows taskbar notifications.   //
//   TODO: Needs improvement.                                      //
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

#ifndef BALLOON_TIP_H
#define BALLOON_TIP_H

#include <QtWidgets>
#include "window_detective/include.h"

class BalloonTip : public QWidget {
    Q_OBJECT
private:
    static const QBrush backgroundBrush;
    static const QPen outlinePen;
    static const int textPadding = 6;
    static const int roundness = 8;
    static const int arrowHeight = 20;  // That triangle bit at the bottom
    QTimer expireTimer;

public:
    BalloonTip(QWidget* parent = 0);
    ~BalloonTip() {}

    void showMessage(const String& message, int timeout/*ms*/);
    void updatePosition();
protected:
    void paintEvent(QPaintEvent*);
};

#endif   // BALLOON_TIP_H
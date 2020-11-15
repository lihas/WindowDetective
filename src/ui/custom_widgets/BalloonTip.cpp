/////////////////////////////////////////////////////////////////////
// File: BalloonTip.cpp                                            //
// Date: 2010-09-29                                                //
// Desc: Widget for displaying a tooltip in a speach-bubble or     //
//   balloon style similar to the Windows taskbar notifications.   //
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


#include "BalloonTip.h"

const QBrush BalloonTip::backgroundBrush(QColor(255, 255, 225));
const QPen BalloonTip::outlinePen(Qt::black, 1);

/*--------------------------------------------------------------------------+
| Constructor.                                                              |
+--------------------------------------------------------------------------*/
BalloonTip::BalloonTip(QWidget* parent) :
    QWidget(parent, Qt::Tool | Qt::FramelessWindowHint),
    expireTimer() {
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_ShowWithoutActivating);
    expireTimer.setSingleShot(true);
    connect(&expireTimer, SIGNAL(timeout()), this, SLOT(hide()));
}

/*--------------------------------------------------------------------------+
| Returns a size which will fit all the text and have an aspect             |
| ratio of between 3:1 and 4:1. This is done by starting with a             |
| small width and increasing it until the desired ratio is attained.        |
| Limit the number of iterations to 50.                                     |
+--------------------------------------------------------------------------*/
QSize findBestSize(const QFontMetrics& fontMetrics, const String& message) {
    int width = 100;
    QRect rect = fontMetrics.boundingRect(0, 0, width, 0,
                    Qt::AlignLeft | Qt::TextWordWrap, message);
    int count = 0;
    float ratio = float(rect.width())/float(rect.height());
    while ((ratio < 3.0 || ratio > 4.0) && count < 50) {
        width = ratio < 3.0 ? width+20 : width-20;
        rect = fontMetrics.boundingRect(0, 0, width, 0,
                    Qt::AlignLeft | Qt::TextWordWrap, message);
        ratio = float(rect.width())/float(rect.height());
        ++count;
    }
    return rect.size();
}

/*--------------------------------------------------------------------------+
| Sets the message to display and shows the balloon above the owner.        |
| After 'timeout' milliseconds, the balloon will be hidden.                 |
+--------------------------------------------------------------------------*/
void BalloonTip::showMessage(const String& message, int timeout/*ms*/) {
    if (!parentWidget()) return;

    setWindowTitle(message);
    updatePosition();
    expireTimer.start(timeout);
    show();
    update();  // Force redraw if it is already showing
}

/*--------------------------------------------------------------------------+
| Updates this widget's position based on the position of it's owner        |
+--------------------------------------------------------------------------*/
void BalloonTip::updatePosition() {
    if (!parentWidget()) return;

    // TODO: Cache the calculated size. Invalidate whenever message changes
    QPoint ownerPos = parentWidget()->mapToGlobal(QPoint(0,0));
    QSize size = findBestSize(fontMetrics(), windowTitle());
    size.setWidth(size.width() + (textPadding*2));
    size.setHeight(size.height() + (textPadding*2) + arrowHeight);
    int x = ownerPos.x() - (size.width()-15-(parentWidget()->width()/2));
    int y = ownerPos.y() - size.height();
    move(x, y); resize(size);
}

/*--------------------------------------------------------------------------+
| Do custom painting. The entire rect is filled with the background         |
| colour and the clip region is used to make an outline path.               |
+--------------------------------------------------------------------------*/
void BalloonTip::paintEvent(QPaintEvent* e) {
    QWidget::paintEvent(e);

    QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);

    const int rectBase = height()-arrowHeight;
    QPoint p1(width()-35, rectBase-2);
    QPoint p2(width()-15, height());
    QPoint p3(width()-15, rectBase-2);
    QPolygon triangle;
    triangle << p1 << p2 << p3;

    // TODO: This doesn't look quite right when drawing the bottom
    // triangle bit. I need to erase the border of the rectangle
    // in the triangle area, but anti-aliasing means that the triangle's
    // border then slighly overlaps.
    painter.setBrush(backgroundBrush);
    painter.setPen(outlinePen);
    painter.drawRoundedRect(1, 1, width()-2, rectBase-2, roundness, roundness);
    painter.setPen(Qt::transparent);
    painter.drawPolygon(triangle);
    painter.setPen(outlinePen);
    painter.drawLine(p1, p2);
    painter.drawLine(p2, p3);

    painter.drawText(textPadding, textPadding,
                     width()-textPadding, rectBase-textPadding,
                     Qt::AlignLeft | Qt::AlignVCenter | Qt::TextWordWrap,
                     windowTitle());
}
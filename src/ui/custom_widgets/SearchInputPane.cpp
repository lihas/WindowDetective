//////////////////////////////////////////////////////////////////////////
// File: SearchInputPane.cpp                                            //
// Date: 2012-03-06                                                     //
// Desc: Custom text edit pane used for entering search text. It has a  //
//   small 'cancel' button to clear the text, and when blank displays   //
//   the word "Search" lightly in the background.                       //
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


#include "SearchInputPane.h"


SearchInputPane::SearchInputPane(QWidget* parent) :
    QLineEdit(parent),
    placeholderText() {

    clearButton = new QToolButton(this);
    QPixmap pixmap(":/img/edit_clear.png");
    clearButton->setIcon(QIcon(pixmap));
    clearButton->setCursor(Qt::ArrowCursor);
    clearButton->setStyleSheet("QToolButton { border: none; padding: 2px 0px; }");
    clearButton->hide();

    QSize thisSize = sizeHint();
    QSize btnSize = clearButton->sizeHint();
    int frameWidth = style()->pixelMetric(QStyle::PM_DefaultFrameWidth);
    //clearButton->setMinimumSize(btnSize.width(), thisSize.height() - (frameWidth * 2));
    setTextMargins(0, 0, btnSize.width() + frameWidth + 1, 0);

    connect(clearButton, SIGNAL(clicked()), this, SLOT(clear()));
    connect(this, SIGNAL(textChanged(const QString&)), this, SLOT(updateButton()));
}

void SearchInputPane::resizeEvent(QResizeEvent*) {
    QSize btnSize = clearButton->sizeHint();
    int frameWidth = style()->pixelMetric(QStyle::PM_DefaultFrameWidth);
    clearButton->move(rect().right() - frameWidth - btnSize.width(),
                      (rect().bottom() + 1 - btnSize.height())/2);
}

void SearchInputPane::updateButton() {
    clearButton->setVisible(!text().isEmpty());
}

void SearchInputPane::paintEvent(QPaintEvent* e) {
    // Paint the standard widget first
    QLineEdit::paintEvent(e);

    // Draw placeholder text. It will be italic, OS text colour with 50% transparency
    if (text().isEmpty() && !placeholderText.isEmpty()) {
        QPainter painter(this);
        painter.setRenderHint(QPainter::TextAntialiasing);
        QColor textColour = palette().color(QPalette::WindowText);
        QFont textFont = painter.font();
        textColour.setAlpha(128);
        textFont.setItalic(true);
        painter.setPen(textColour);
        painter.setFont(textFont);
        painter.drawText(padding, 0, width(), height(), Qt::AlignVCenter, placeholderText);
    }
}

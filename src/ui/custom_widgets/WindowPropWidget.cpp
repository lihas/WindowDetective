/////////////////////////////////////////////////////////////////////
// File: WindowPropWidget.cpp                                      //
// Date: 2011-02-17                                                //
// Desc: Displays a list of window user-set properties. These      //
//   properties are set by calling the SetProc API function.       //
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

#include "WindowPropWidget.h"

/*--------------------------------------------------------------------------+
| WindowPropWidget constructor.                                             |
+--------------------------------------------------------------------------*/
WindowPropWidget::WindowPropWidget(QWidget* parent) :
    QWidget(parent),
    container(NULL) {
    containerLayout = new QVBoxLayout(this);
    containerLayout->setSpacing(0);
    containerLayout->setContentsMargins(0, 0, 0, 0);
}

/*--------------------------------------------------------------------------+
| Updates the data in the UI.                                               |
+--------------------------------------------------------------------------*/
// TODO: Optimise this by only removing the individual items, rather that re-creating the
//  entire container widget. Then there will be no need for the container.
//  Also, if the model's size hasn't changed, just change the text in the widgets
void WindowPropWidget::update() {
    if (container) delete container;  // This will also delete all child widgets

    container = new QWidget(this);
    containerLayout->addWidget(container);
    QFormLayout* formLayout = new QFormLayout(container);
    formLayout->setContentsMargins(0, 0, 0, 0);

    QLabel* nameTitle = new QLabel(tr("Name"), container);
    QLabel* dataTitle = new QLabel(tr("Data"), container);
    QFont font;
    font.setBold(true);
    font.setWeight(75);
    nameTitle->setFont(font);   // TODO: Use stylesheet
    dataTitle->setFont(font);
    formLayout->addRow(nameTitle, dataTitle);

    WindowPropList::const_iterator i;
    for (i = model.begin(); i != model.end(); ++i) {
        QLabel* nameLabel = new QLabel((*i).name, container);
        QLabel* dataLabel = new QLabel(hexString((uint)(*i).data), container);
        nameLabel->setCursor(QCursor(Qt::IBeamCursor));
        nameLabel->setTextFormat(Qt::PlainText);
        nameLabel->setTextInteractionFlags(Qt::TextBrowserInteraction|Qt::TextSelectableByKeyboard);
        dataLabel->setCursor(QCursor(Qt::IBeamCursor));
        dataLabel->setTextFormat(Qt::PlainText);
        dataLabel->setTextInteractionFlags(Qt::TextBrowserInteraction|Qt::TextSelectableByKeyboard);
        formLayout->addRow(nameLabel, dataLabel);
    }
}

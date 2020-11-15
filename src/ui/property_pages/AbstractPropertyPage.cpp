/////////////////////////////////////////////////////////////////////
// File: AbstractPropertyPage.cpp                                  //
// Date: 2011-01-27                                                //
// Desc: The superclass for all property pages. Mainly handles     //
//   things common to all subclasses.                              //
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

#include "AbstractPropertyPage.h"
#include "window_detective/main.h"

AbstractPropertyPage::AbstractPropertyPage(QWidget* parent) :
    QWidget(parent), owner(NULL),
    evenRowColourProperty(Qt::white),
    oddRowColourProperty(Qt::white) {

    formLayout = new QFormLayout(this);
    formLayout->setContentsMargins(margin, margin, margin, margin);
    formLayout->setHorizontalSpacing(spacing);
    formLayout->setVerticalSpacing(spacing);
    formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);

    String cssString;
    QTextStream stream(&cssString);
    loadCssStyle("PropertiesWindow", stream);
    this->setStyleSheet(cssString);
}

/*--------------------------------------------------------------------------+
| Adds a row to the property form. Non spanning rows have a label           |
| on the left and the field widget on the right.                            |
+--------------------------------------------------------------------------*/
void AbstractPropertyPage::addRow(String labelText, QWidget* widget) {
    QLabel* label = new QLabel(labelText, this);
    label->setObjectName("propertyName");
    widget->setObjectName("propertyValue");
    formLayout->addRow(label, widget);
}

/*--------------------------------------------------------------------------+
| Adds a spanning row where the widget fills the whole row area.            |
| These use a sub-layout which places the label at the top left and         |
| the field widget filling the rest of the area.                            |
+--------------------------------------------------------------------------*/
void AbstractPropertyPage::addSpan(String labelText, QWidget* widget) {
    QWidget* containerWidget = new QWidget(this);
    QLabel* label = new QLabel(labelText, this);
    label->setObjectName("propertyName");
    widget->setObjectName("propertyValue");

    QVBoxLayout* layout = new QVBoxLayout(containerWidget);
    layout->setContentsMargins(9, 9, 9, 9);
    layout->addWidget(label);
    layout->addWidget(widget);
    formLayout->addRow(containerWidget);
}

/*--------------------------------------------------------------------------+
| Creates a label widget to be used for displaying property values.         |
| The data can be single-line, such as a string or number, or               |
| multi-line, such as lists. The text in this widget is selectable.         |
+--------------------------------------------------------------------------*/
QLabel* AbstractPropertyPage::makeValueLabel() {
    QLabel* label = new QLabel(this);
    label->setCursor(QCursor(Qt::IBeamCursor));
    label->setTextFormat(Qt::PlainText);
    label->setTextInteractionFlags(Qt::TextBrowserInteraction|Qt::TextSelectableByKeyboard);
    return label;
}

/*--------------------------------------------------------------------------+
| Custom paint event to draw alternate row colours.                         |
+--------------------------------------------------------------------------*/
void AbstractPropertyPage::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    painter.setPen(Qt::NoPen);

    // Fill the entire background with even colour first, then draw odd
    // rectangles. Probably more efficient this way
    painter.setBrush(evenRowColourProperty);
    painter.drawRect(0, 0, this->width(), this->height());

    int y = margin - (spacing / 2);
    bool alt = false;
    painter.setBrush(oddRowColourProperty);
    for (int i = 0; i < formLayout->rowCount(); ++i) {
        QLayoutItem* item = formLayout->itemAt(i, QFormLayout::FieldRole);
        if (!item) {
            item = formLayout->itemAt(i, QFormLayout::SpanningRole);
        }
        if (item) {
            int h = item->sizeHint().height() + spacing;
            if (alt) {
                painter.drawRect(0, y, this->width(), h);
            }
            y += h;
            alt = !alt;
        }
    }
}
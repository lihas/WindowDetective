/////////////////////////////////////////////////////////////////////
// File: BrushPropertyWidget.cpp                                   //
// Date: 2011-02-14                                                //
// Desc: Displays properties of a brush object. If that object is  //
//   NULL or the system brush, a simple line edit will display     //
//   that. Otherwise, a form layout will show the properties of    //
//   the object.                                                   //
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

#include "BrushPropertyWidget.h"
#include "window_detective/StringFormatter.h"
#include "window_detective/QtHelpers.h"


/*--------------------------------------------------------------------------+
| BrushPropertyWidget constructor.                                          |
+--------------------------------------------------------------------------*/
BrushPropertyWidget::BrushPropertyWidget(QWidget* parent) :
    QWidget(parent),
    formLayout(NULL),
    basicWidget(NULL),
    handleWidget(NULL),
    styleWidget(NULL),
    colourWidget(NULL),
    hatchWidget(NULL) {
}

/*--------------------------------------------------------------------------+
| Convenience function to create a text-browsable label.                    |
+--------------------------------------------------------------------------*/
QLabel* BrushPropertyWidget::makeValueLabel() {
    QLabel* label = new QLabel(this);
    label->setCursor(QCursor(Qt::IBeamCursor));
    label->setTextFormat(Qt::PlainText);
    label->setTextInteractionFlags(Qt::TextBrowserInteraction);
    return label;
}

/*--------------------------------------------------------------------------+
| Destroys layout and all child widgets, if they exist.                     |
+--------------------------------------------------------------------------*/
void BrushPropertyWidget::destroyWidgets() {
    #define DESTROY_WIDGET(w) if (w) { delete w; w = NULL; }
    DESTROY_WIDGET(formLayout);
    DESTROY_WIDGET(basicWidget);
    DESTROY_WIDGET(handleWidget);
    DESTROY_WIDGET(styleWidget);
    DESTROY_WIDGET(colourWidget);
    DESTROY_WIDGET(hatchWidget);
}

/*--------------------------------------------------------------------------+
| Builds a single line edit. Used when font is NULL or system brush         |
+--------------------------------------------------------------------------*/
void BrushPropertyWidget::buildBasicUI() {
    destroyWidgets();
    formLayout = new QFormLayout(this);
    formLayout->setContentsMargins(0, 0, 0, 0);
    formLayout->addRow(basicWidget = makeValueLabel());
}

/*--------------------------------------------------------------------------+
| Builds the full UI for displaying the brush's properties.                 |
+--------------------------------------------------------------------------*/
void BrushPropertyWidget::buildFullUI() {
    destroyWidgets();
    formLayout = new QFormLayout(this);
    formLayout->setContentsMargins(0, 0, 0, 0);
    formLayout->addRow(tr("Handle:"), handleWidget = makeValueLabel());
    formLayout->addRow(tr("Style:"), styleWidget = makeValueLabel());
    formLayout->addRow(tr("Colour:"), colourWidget = makeValueLabel());
    formLayout->addRow(tr("Hatch:"), hatchWidget = makeValueLabel());
}

/*--------------------------------------------------------------------------+
| Updates the data in the UI.                                               |
+--------------------------------------------------------------------------*/
void BrushPropertyWidget::update() {
    if (!model || !model->handle) {
        if (!basicWidget) buildBasicUI();
        basicWidget->setText(tr("none"));
        return;
    }

    // Check if the handle is actually a colour id
    uint id = (uint)(model->handle) - 1;
    if (Resources::hasConstant("SystemColour", id)) {
        if (!basicWidget) buildBasicUI();
        basicWidget->setText(Resources::getConstant("SystemColour", id));
        return;
    }

    if (!handleWidget) buildFullUI();
    handleWidget->setText(hexString((uint)model->handle));
    styleWidget->setText(stringLabel(model->getStyleName()));
    hatchWidget->setText(stringLabel(model->getHatchName()));

    // Set the background and foreground colour of the colour widget
    // If the average of all channels is less than 140,
    // then the text colour will be white, else it is black
    QColor colour = QColorFromCOLORREF(model->colour);
    int avg = (colour.red() + colour.green() + colour.blue()) / 3;
    String styleString;
    QTextStream stream(&styleString);
    stream << "background-color: rgb("
            << String::number(colour.red()) << ", "
            << String::number(colour.green()) << ", "
            << String::number(colour.blue()) << ");"
            << "color: rgb("
            << (avg < 140 ? "255, 255, 255" : "0, 0, 0") << ");";
    colourWidget->setStyleSheet(styleString);
    colourWidget->setText(stringLabel(colour));
}

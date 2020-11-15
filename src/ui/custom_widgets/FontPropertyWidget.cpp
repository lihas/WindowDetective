/////////////////////////////////////////////////////////////////////
// File: FontPropertyWidget.cpp                                    //
// Date: 2011-02-14                                                //
// Desc: Displays properties of a font object. If that object is   //
//   NULL or the system font, a simple line edit will display      //
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

#include "FontPropertyWidget.h"


/*--------------------------------------------------------------------------+
| FontPropertyWidget constructor.                                           |
+--------------------------------------------------------------------------*/
FontPropertyWidget::FontPropertyWidget(QWidget* parent) :
    QWidget(parent),
    model(NULL),
    formLayout(NULL),
    basicWidget(NULL),
    handleWidget(NULL),
    faceNameWidget(NULL),
    weightWidget(NULL),
    widthHeightWidget(NULL),
    qualityWidget(NULL),
    styleWidget(NULL) {
}

/*--------------------------------------------------------------------------+
| Convenience function to create a text-browsable label.                    |
+--------------------------------------------------------------------------*/
QLabel* FontPropertyWidget::makeValueLabel() {
    QLabel* label = new QLabel(this);
    label->setCursor(QCursor(Qt::IBeamCursor));
    label->setTextFormat(Qt::PlainText);
    label->setTextInteractionFlags(Qt::TextBrowserInteraction);
    return label;
}

/*--------------------------------------------------------------------------+
| Destroys layout and all child widgets, if they exist.                     |
+--------------------------------------------------------------------------*/
void FontPropertyWidget::destroyWidgets() {
    #define DESTROY_WIDGET(w) if (w) { delete w; w = NULL; }
    DESTROY_WIDGET(formLayout);
    DESTROY_WIDGET(basicWidget);
    DESTROY_WIDGET(handleWidget);
    DESTROY_WIDGET(faceNameWidget);
    DESTROY_WIDGET(weightWidget);
    DESTROY_WIDGET(widthHeightWidget);
    DESTROY_WIDGET(qualityWidget);
    DESTROY_WIDGET(styleWidget);
}

/*--------------------------------------------------------------------------+
| Builds a single line edit. Used when font is NULL or system font          |
+--------------------------------------------------------------------------*/
void FontPropertyWidget::buildBasicUI() {
    destroyWidgets();
    formLayout = new QFormLayout(this);
    formLayout->setContentsMargins(0, 0, 0, 0);
    formLayout->addRow(basicWidget = makeValueLabel());
}

/*--------------------------------------------------------------------------+
| Builds the full UI for displaying the font's properties.                  |
+--------------------------------------------------------------------------*/
void FontPropertyWidget::buildFullUI() {
    destroyWidgets();
    formLayout = new QFormLayout(this);
    formLayout->setContentsMargins(0, 0, 0, 0);
    formLayout->addRow(tr("Handle:"), handleWidget = makeValueLabel());
    formLayout->addRow(tr("Face name:"), faceNameWidget = makeValueLabel());
    formLayout->addRow(tr("Weight:"), weightWidget = makeValueLabel());
    formLayout->addRow(tr("Width/Height:"), widthHeightWidget = makeValueLabel());
    formLayout->addRow(tr("Quality:"), qualityWidget = makeValueLabel());
    formLayout->addRow(tr("Style:"), styleWidget = makeValueLabel());
}

/*--------------------------------------------------------------------------+
| Updates the data in the UI.                                               |
+--------------------------------------------------------------------------*/
void FontPropertyWidget::update() {
    if (model) {
        updateFullUI();
    }
    else {
        updateBasicUI();
    }
}

/*--------------------------------------------------------------------------+
| Updates the data in the basic UI. Rebuilds it if necessary.               |
+--------------------------------------------------------------------------*/
void FontPropertyWidget::updateBasicUI() {
    if (!basicWidget) {
        buildBasicUI();
    }

    if (!model) {
        basicWidget->setText(tr("none"));
    }
}

/*--------------------------------------------------------------------------+
| Updates the data in the full UI. Rebuilds it if necessary.                |
+--------------------------------------------------------------------------*/
void FontPropertyWidget::updateFullUI() {
    if (!handleWidget) {  // Test one of the widgets in the full UI
        buildFullUI();
    }

    String weightString, sizeString;
    weightString = model->getWeightName();
    if (weightString.isEmpty()) {
        weightString = String::number(model->weight);
    }
    else {
        weightString = weightString+" ("+String::number(model->weight)+")";
    }
    sizeString = String::number(model->width)+", "+String::number(model->height);
    if (model->handle) {
        handleWidget->setText(hexString((uint)model->handle));
    }
    faceNameWidget->setText(model->faceName);
    weightWidget->setText(weightString);
    widthHeightWidget->setText(sizeString);
    qualityWidget->setText(model->getQualityName());
    styleWidget->setText(model->getStyleString());
}
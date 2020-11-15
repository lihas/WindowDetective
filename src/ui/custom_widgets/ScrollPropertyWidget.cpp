/////////////////////////////////////////////////////////////////////
// File: ScrollPropertyWidget.cpp                                  //
// Date: 2012-06-15                                                //
// Desc: Displays scroll bar properties for a window. If the model //
//   is NULL, this will just be a label.                           //
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

#include "ScrollPropertyWidget.h"
#include "window_detective/StringFormatter.h"


/*--------------------------------------------------------------------------+
| ScrollPropertyWidget constructor.                                         |
+--------------------------------------------------------------------------*/
ScrollPropertyWidget::ScrollPropertyWidget(QWidget* parent) :
    QWidget(parent),
    formLayout(NULL),
    basicWidget(NULL),
    minWidget(NULL),
    maxWidget(NULL),
    posWidget(NULL),
    pageWidget(NULL) {
}

/*--------------------------------------------------------------------------+
| Convenience function to create a text-browsable label.                    |
+--------------------------------------------------------------------------*/
QLabel* ScrollPropertyWidget::makeValueLabel() {
    QLabel* label = new QLabel(this);
    label->setCursor(QCursor(Qt::IBeamCursor));
    label->setTextFormat(Qt::PlainText);
    label->setTextInteractionFlags(Qt::TextBrowserInteraction);
    return label;
}

/*--------------------------------------------------------------------------+
| Destroys layout and all child widgets, if they exist.                     |
+--------------------------------------------------------------------------*/
void ScrollPropertyWidget::destroyWidgets() {
    #define DESTROY_WIDGET(w) if (w) { delete w; w = NULL; }
    DESTROY_WIDGET(formLayout);
    DESTROY_WIDGET(basicWidget);
    DESTROY_WIDGET(minWidget);
    DESTROY_WIDGET(maxWidget);
    DESTROY_WIDGET(posWidget);
    DESTROY_WIDGET(pageWidget);
}

/*--------------------------------------------------------------------------+
| Builds a single line edit. Used when model is NULL.                       |
+--------------------------------------------------------------------------*/
void ScrollPropertyWidget::buildBasicUI() {
    destroyWidgets();
    formLayout = new QFormLayout(this);
    formLayout->setContentsMargins(0, 0, 0, 0);
    formLayout->addRow(basicWidget = makeValueLabel());
}

/*--------------------------------------------------------------------------+
| Builds the full UI for displaying the model's properties.                 |
+--------------------------------------------------------------------------*/
void ScrollPropertyWidget::buildFullUI() {
    destroyWidgets();
    formLayout = new QFormLayout(this);
    formLayout->setContentsMargins(0, 0, 0, 0);
    formLayout->addRow(tr("Min Position:"), minWidget = makeValueLabel());
    formLayout->addRow(tr("Max Position:"), maxWidget = makeValueLabel());
    formLayout->addRow(tr("Current Position:"), posWidget = makeValueLabel());
    formLayout->addRow(tr("Page:"), pageWidget = makeValueLabel());
}

/*--------------------------------------------------------------------------+
| Updates the data in the UI.                                               |
+--------------------------------------------------------------------------*/
void ScrollPropertyWidget::update() {
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
void ScrollPropertyWidget::updateBasicUI() {
    if (!basicWidget) buildBasicUI();
    if (!model) basicWidget->setText(tr("none"));
}

/*--------------------------------------------------------------------------+
| Updates the data in the full UI. Rebuilds it if necessary.                |
+--------------------------------------------------------------------------*/
void ScrollPropertyWidget::updateFullUI() {
    if (!minWidget) buildFullUI();   // Test one of the widgets in the full UI

    minWidget->setText(stringLabel(model->minPos));
    maxWidget->setText(stringLabel(model->maxPos));
    posWidget->setText(stringLabel(model->currentPos));
    pageWidget->setText(stringLabel(model->page) + " device units");
}
/////////////////////////////////////////////////////////////////////
// File: DateTimePickerPropertyPage.cpp                            //
// Date: 2011-06-10                                                //
// Desc: The property page for DateTimePicker controls.            //
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

#include "PropertiesPane.h"
#include "DateTimePickerPropertyPage.h"
#include "window_detective/StringFormatter.h"
#include "window_detective/main.h"


DateTimePickerPropertyPage::DateTimePickerPropertyPage(DateTimePicker* model, QWidget* parent) :
    AbstractPropertyPage(parent), model(model) {
    setWindowTitle("DateTimePicker");
}

void DateTimePickerPropertyPage::setupUi() {
    addRow(tr("Selected"), selectedTimeWidget = makeValueLabel());
    addRow(tr("Minimum"), minimumTimeWidget = makeValueLabel());
    addRow(tr("Maximum"), maximumTimeWidget = makeValueLabel());

    if (getOSVersion() >= 600) {
        addRow(tr("Ideal Size"), idealSizeWidget = makeValueLabel());
    }
    else {
        idealSizeWidget = NULL;
    }
}

/*--------------------------------------------------------------------------+
| Updates the data in each property widget.                                 |
+--------------------------------------------------------------------------*/
void DateTimePickerPropertyPage::updateProperties() {
    model->getRemoteInfo();  // We know we will need this info, so just get it now

    selectedTimeWidget->setText(stringLabel(model->getSelected()));
    minimumTimeWidget->setText(stringLabel(model->getMinimum()));
    maximumTimeWidget->setText(stringLabel(model->getMaximum()));
    if (idealSizeWidget) {
        idealSizeWidget->setText(stringLabel(model->getIdealSize()));
    }
}

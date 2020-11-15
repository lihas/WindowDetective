/////////////////////////////////////////////////////////////////////
// File: SizeInputWidget.h                                         //
// Date: 2017-07-13                                                //
// Desc: Widget with two spin boxes to enter width and height      //
//   values. The value is stored and retrieved as a QSize.         //
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

#include "SizeInputWidget.h"


SizeInputWidget::SizeInputWidget(QWidget* parent) :
    QWidget(parent),
    xSpinBox(NULL),
    ySpinBox(NULL),
    middleLabel(NULL) {
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
        
    QHBoxLayout* horizontalLayout = new QHBoxLayout(this);
    horizontalLayout->setContentsMargins(0, 0, 0, 0);

    middleLabel = new QLabel(this);
    middleLabel->setText(QApplication::translate("SizeInputWidget", "\303\227", 0));

    xSpinBox = new QSpinBox(this);
    xSpinBox->setObjectName(QStringLiteral("x"));
    sizePolicy.setHeightForWidth(xSpinBox->sizePolicy().hasHeightForWidth());
    xSpinBox->setSizePolicy(sizePolicy);
    xSpinBox->setMaximum(100000);
    xSpinBox->setSuffix(QApplication::translate("SizeInputWidget", " px", 0));
    
    ySpinBox = new QSpinBox(this);
    ySpinBox->setObjectName(QStringLiteral("y"));
    sizePolicy.setHeightForWidth(ySpinBox->sizePolicy().hasHeightForWidth());
    ySpinBox->setSizePolicy(sizePolicy);
    ySpinBox->setMaximum(100000);
    ySpinBox->setSuffix(QApplication::translate("SizeInputWidget", " px", 0));

    horizontalLayout->addWidget(xSpinBox);
    horizontalLayout->addWidget(middleLabel);
    horizontalLayout->addWidget(ySpinBox);
}
    
QSize SizeInputWidget::value() {
    QSize value;
    value.setWidth(xSpinBox->value());
    value.setHeight(ySpinBox->value());
    return value;
}

void SizeInputWidget::setValue(QSize size) {
    xSpinBox->setValue(size.width());
    ySpinBox->setValue(size.height());
}
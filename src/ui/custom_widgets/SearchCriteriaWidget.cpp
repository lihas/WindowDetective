/////////////////////////////////////////////////////////////////////
// File: SearchCriteriaWidget.cpp                                  //
// Date: 2010-11-03                                                //
// Desc: Widget for a search criteria item. It contains a combo    //
//   box for selecting the property to search for, a combo box for //
//   the operator, and a changable widget for entering the value.  //
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


#include "SearchCriteriaWidget.h"
#include "window_detective/Logger.h"
#include "inspector/WindowManager.h"
#include "ui/custom_widgets/HexSpinBox.h"
#include "ui/custom_widgets/CustomComboBoxes.h"
#include "ui/FindDialog.h"

SearchCriteriaWidget::SearchCriteriaWidget(QWidget *parent) :
    QWidget(parent), morphableWidget(NULL) {
    setupUi();
    setPropertyList();
    cbProperties->setCurrentIndex(0);
    changeType();

    connect(btnAdd, SIGNAL(clicked()), this, SIGNAL(addButtonClicked()));
    connect(btnRemove, SIGNAL(clicked()), this, SIGNAL(removeButtonClicked()));
    connect(cbProperties, SIGNAL(currentIndexChanged(int)), this, SLOT(changeType()));
}

void SearchCriteriaWidget::setupUi() {
    QHBoxLayout* horizontalLayout = new QHBoxLayout(this);
    horizontalLayout->setContentsMargins(0, 0, 0, 0);

    cbProperties = new QComboBox(this);
    cbOperators = new QComboBox(this);
    cbOperators->setMinimumWidth(100);
    cbOperators->setMaximumWidth(200);
    morphableWidgetContainer = new QWidget(this);
    morphableWidgetContainer->setMinimumWidth(100);
    morphableWidgetLayout = new QHBoxLayout(morphableWidgetContainer);
    morphableWidgetLayout->setSpacing(0);
    morphableWidgetLayout->setContentsMargins(0, 0, 0, 0);
    // This class is responsible for creating widget type.
    // Perhaps i can create a separate MorphableWidget class if i need it.
    
    horizontalLayout->addWidget(cbProperties);
    horizontalLayout->addWidget(cbOperators);
    horizontalLayout->addWidget(morphableWidgetContainer);

    QWidget* widget = new QWidget(this);
    widget->setMaximumSize(QSize(40, 20));
    QHBoxLayout* horizontalLayout2 = new QHBoxLayout(widget);
    horizontalLayout2->setSpacing(0);
    horizontalLayout2->setContentsMargins(0, 0, 0, 0);
    
    btnAdd = new QPushButton("+", widget);
    btnRemove = new QPushButton("-", widget);
    btnAdd->setMinimumSize(QSize(20, 20));
    btnAdd->setMaximumSize(QSize(20, 20));
    btnRemove->setMinimumSize(QSize(20, 20));
    btnRemove->setMaximumSize(QSize(20, 20));

    horizontalLayout2->addWidget(btnRemove);
    horizontalLayout2->addWidget(btnAdd);
    
    horizontalLayout->addWidget(widget);
    horizontalLayout->setStretch(0, 20);
    horizontalLayout->setStretch(1, 15);
    horizontalLayout->setStretch(2, 20);
}

void SearchCriteriaWidget::setPropertyList() {
    cbProperties->addItems(SearchCriteria::getPropertyNames());
}

PropertyEnum SearchCriteriaWidget::getSelectedProperty() {
    int index = cbProperties->currentIndex();
    if (index < 0 || index >= PropertyCount) {
        Logger::debug("SearchCriteriaWidget - Invalid property index");
        return (PropertyEnum)0;
    }
    return (PropertyEnum)index;
}

OperatorEnum SearchCriteriaWidget::getSelectedOperator() {
    PropertyEnum prop = getSelectedProperty();
    QList<OperatorEnum> operators = SearchCriteria::getOperatorsForProperty(prop);
    return operators.at(cbOperators->currentIndex());
}

/*--------------------------------------------------------------------------+
| Returns a QVariant containing the data in the morphable widget.           |
+--------------------------------------------------------------------------*/
QVariant SearchCriteriaWidget::getValue() {
    if (!morphableWidget) return QVariant();

    switch (getSelectedProperty()) {
        case TextProp: {
            QLineEdit* edit = dynamic_cast<QLineEdit*>(morphableWidget);
            if (edit) return QVariant(edit->text());
        }
        case HandleProp:
        case ThreadIdProp: {
            HexSpinBox* spinBox = dynamic_cast<HexSpinBox*>(morphableWidget);
            if (spinBox) return QVariant((uint)spinBox->value());
        }
        case IsUnicodeProp: {
            QComboBox* comboBox = dynamic_cast<QComboBox*>(morphableWidget);
            if (comboBox) return QVariant(comboBox->currentIndex() == 0);
        }
        case WindowClassProp: {
            WindowClassComboBox* comboBox = dynamic_cast<WindowClassComboBox*>(morphableWidget);
            if (comboBox) return qVariantFromValue<WindowClass*>(comboBox->currentValue());
        }
        case ParentProp: {
            WindowComboBox* comboBox = dynamic_cast<WindowComboBox*>(morphableWidget);
            if (comboBox) return qVariantFromValue<Window*>(comboBox->currentValue());
        }
        case StylesProp:
        case ExtendedStylesProp: {
            WindowStyleComboBox* comboBox = dynamic_cast<WindowStyleComboBox*>(morphableWidget);
            if (comboBox) return qVariantFromValue<WindowStyle*>(comboBox->currentValue());
        }
        case ProcessProp: {
            ProcessComboBox* comboBox = dynamic_cast<ProcessComboBox*>(morphableWidget);
            if (comboBox) return qVariantFromValue<Process*>(comboBox->currentValue());
        }
    }

    // If it gets to here, something is wrong
    Logger::debug("SearchCriteriaWidget::getValue - invalid widget type");
    return QVariant();
}

/*--------------------------------------------------------------------------+
| Creates and returns a SearchCriteriaItem from the data in this UI         |
+--------------------------------------------------------------------------*/
SearchCriteriaItem SearchCriteriaWidget::getCriteriaItem() {
    return SearchCriteriaItem(getSelectedProperty(),
                              getSelectedOperator(),
                              getValue());
}

/*--------------------------------------------------------------------------+
| Changes the morphable widget to a new one based on the given type.        |
| The old widget (if exists) will be destroyed and a new widget             |
| will be created and added to the container.                               |
+--------------------------------------------------------------------------*/
void SearchCriteriaWidget::changeMorphableWidget(PropertyEnum prop) {
    if (morphableWidget) {
        delete morphableWidget;
        morphableWidget = NULL;
    }

    switch (prop) {
        case TextProp: {
            morphableWidget = new QLineEdit();
            break;
        }
        case HandleProp:
        case ThreadIdProp: {
            HexSpinBox* spinBox = new HexSpinBox();
            spinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
            spinBox->displayAsHex(prop == HandleProp);
            morphableWidget = spinBox;
            break;
        }
        case IsUnicodeProp: {
            QComboBox* comboBox = new QComboBox();
            comboBox->addItems(QStringList()<<"true"<<"false");
            morphableWidget = comboBox;
            break;
        }
        case WindowClassProp: {
            WindowClassComboBox* comboBox = new WindowClassComboBox();
            comboBox->setList(Resources::windowClasses.values());
            morphableWidget = comboBox;
            break;
        }
        case ParentProp: {
            WindowComboBox* comboBox = new WindowComboBox();
            comboBox->setList(WindowManager::current().allWindows);
            morphableWidget = comboBox;
            break;
        }
        case StylesProp: {
            WindowStyleComboBox* comboBox = new WindowStyleComboBox();
            comboBox->setList(Resources::getStandardWindowStyles());
            morphableWidget = comboBox;
            break;
        }
        case ExtendedStylesProp: {
            WindowStyleComboBox* comboBox = new WindowStyleComboBox();
            comboBox->setList(Resources::getExtendedWindowStyles());
            morphableWidget = comboBox;
            break;
        }
        case ProcessProp: {
            ProcessComboBox* comboBox = new ProcessComboBox();
            comboBox->setList(WindowManager::current().allProcesses);
            morphableWidget = comboBox;
            break;
        }
        default: {
            morphableWidget = new QWidget();
            Logger::debug("SearchCriteriaWidget::changeMorphableWidget - invalid type");
            break;
        }
    }

    morphableWidget->setParent(morphableWidgetContainer);
    morphableWidgetLayout->addWidget(morphableWidget);
    morphableWidget->show();
}

void SearchCriteriaWidget::changeType() {
    PropertyEnum prop = getSelectedProperty();
    QList<OperatorEnum> operators = SearchCriteria::getOperatorsForProperty(prop);
    QStringList operatorNames = SearchCriteria::getOperatorNames();
    QStringList namesToUse;
    foreach (OperatorEnum op, operators) {
        namesToUse.append(operatorNames.at((int)op));
    }
    cbOperators->clear();
    cbOperators->addItems(namesToUse);
    changeMorphableWidget(prop);
}

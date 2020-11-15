//////////////////////////////////////////////////////////////////////////
// File: SearchCriteria.cpp                                             //
// Date: 2010-03-31                                                     //
// Desc: Stores criteria used to find a window.                         //
//   One or more criteria can be added and combined using a boolean     //
//   operator AND or OR. A window is found if it matches all or any of  //
//   the criteria, depending on the boolean operator.                   //
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

#include "SearchCriteria.h"
#include "window_detective/Settings.h"
#include "window_detective/Logger.h"
#include "window_detective/StringFormatter.h"


QList<QList<OperatorEnum>> SearchCriteria::propertyOperators;
QStringList SearchCriteria::propertyNames;
QStringList SearchCriteria::operatorNames;

bool compareString(OperatorEnum op, String a, String b);
bool compareInteger(OperatorEnum op, uint a, uint b);
bool compareBoolean(OperatorEnum op, bool a, bool b);
template <class T> bool compareObject(OperatorEnum op, T a, T b);
template <class T> bool listContains(OperatorEnum op, QList<T> list, T value);

/*--------------------------------------------------------------------------+
| Initialize static mapping tables.                                         |
+--------------------------------------------------------------------------*/
void SearchCriteria::initialize() {
    QList<OperatorEnum> objectOperators;
    objectOperators << GenericEqual
                    << GenericNotEqual;
    QList<OperatorEnum> stringOperators;
    stringOperators << StringEqual
                    << StringEqualCaseSensitive
                    << StringNotEqual
                    << StringContains
                    << StringMatchesRegex;
    QList<OperatorEnum> integerOperators;
    integerOperators<< IntegerEqual
                    << IntegerNotEqual
                    << IntegerLessThan
                    << IntegerLessThanOrEqual
                    << IntegerGreaterThan
                    << IntegerGreaterThanOrEqual;
    QList<OperatorEnum> booleanOperators;
    booleanOperators<< BooleanEqual;
    QList<OperatorEnum> listOperators;
    listOperators   << ListContains
                    << ListDoesNotContain;

    propertyOperators.insert(TextProp, stringOperators);
    propertyOperators.insert(HandleProp, integerOperators);
    propertyOperators.insert(WindowClassProp, objectOperators);
    propertyOperators.insert(ParentProp, objectOperators);
    propertyOperators.insert(StylesProp, listOperators);
    propertyOperators.insert(ExtendedStylesProp, listOperators);
    propertyOperators.insert(IsUnicodeProp, booleanOperators);
    propertyOperators.insert(ProcessProp, objectOperators);
    propertyOperators.insert(ThreadIdProp, integerOperators);

    propertyNames.insert(TextProp, "text");
    propertyNames.insert(HandleProp, "handle");
    propertyNames.insert(WindowClassProp, "window class");
    propertyNames.insert(ParentProp, "parent");
    propertyNames.insert(StylesProp, "styles");
    propertyNames.insert(ExtendedStylesProp, "extended styles");
    propertyNames.insert(IsUnicodeProp, "is unicode");
    propertyNames.insert(ProcessProp, "process");
    propertyNames.insert(ThreadIdProp, "thread id");

    operatorNames.insert(GenericEqual, "equals");
    operatorNames.insert(GenericNotEqual, "does not equal");
    operatorNames.insert(StringEqual, "equals");
    operatorNames.insert(StringEqualCaseSensitive, "equals (case sensitive)");
    operatorNames.insert(StringNotEqual, "does not equal");
    operatorNames.insert(StringContains, "contains");
    operatorNames.insert(StringMatchesRegex, "matches");
    operatorNames.insert(IntegerEqual, "=");
    operatorNames.insert(IntegerNotEqual, "!=");
    operatorNames.insert(IntegerLessThan, "<");
    operatorNames.insert(IntegerLessThanOrEqual, "<=");
    operatorNames.insert(IntegerGreaterThan, ">");
    operatorNames.insert(IntegerGreaterThanOrEqual, ">=");
    operatorNames.insert(BooleanEqual, "equals");
    operatorNames.insert(ListContains, "contains");
    operatorNames.insert(ListDoesNotContain, "does not contain");
}

SearchCriteria::SearchCriteria() :
    criteria(), relations() {
}

/*--------------------------------------------------------------------------+
| Sets the initial criteria as 'item'. Any previous criteria will be        |
| removed. There is no boolean relation associated with this item.          |
+--------------------------------------------------------------------------*/
void SearchCriteria::setCriteria(SearchCriteriaItem item) {
    criteria.clear();
    relations.clear();
    criteria.append(item);
}

/*--------------------------------------------------------------------------+
| Adds the criteria item to the list with the given relation.               |
+--------------------------------------------------------------------------*/
void SearchCriteria::addCriteria(SearchCriteriaItem item, BooleanRelation relation) {
    criteria.append(item);
    relations.append(relation);
}

/*--------------------------------------------------------------------------+
| Writes the criteria item on the stream.                                   |
+--------------------------------------------------------------------------*/
void SearchCriteriaItem::printOn(QTextStream& stream) const {
    stream << SearchCriteria::getPropertyNames().at((int)prop) << " "
           << SearchCriteria::getOperatorNames().at((int)op) << " ";

    switch (prop) {
        case TextProp:
            stream << value.toString();
            break;
        case HandleProp:
            stream << hexString(value.toUInt());
            break;
        case WindowClassProp:
            stream << value.value<WindowClass*>()->getDisplayName();
            break;
        case ParentProp:
            stream << value.value<Window*>()->getDisplayName();
            break;
        case StylesProp:
            stream << value.value<WindowStyle*>()->getName();
            break;
        case ExtendedStylesProp:
            stream << value.value<WindowStyle*>()->getName();
            break;
        case IsUnicodeProp:
            stream << (value.toBool() ? "true" : "false");
            break;
        case ProcessProp:
            stream << value.value<Process*>()->getDisplayName();
            break;
        case ThreadIdProp:
            stream << value.toUInt();
            break;
    }
}

/*--------------------------------------------------------------------------+
| Writes each criteria item on the stream, separated by a newline.          |
+--------------------------------------------------------------------------*/
void SearchCriteria::printOn(QTextStream& stream) const {
    if (criteria.isEmpty()) return;

    stream << criteria.first();
    for (int i = 1; i < criteria.size(); ++i) {
        stream << (relations.at(i-1) == BooleanAnd ? " and\n" : " or\n");
        stream << criteria.at(i);
    }
}

/*--------------------------------------------------------------------------+
| Returns true if the properties of the given window match the              |
| criteria, false otherwise.                                                |
+--------------------------------------------------------------------------*/
bool SearchCriteria::matches(Window* window) const {
    if (criteria.isEmpty()) return false;
    if (relations.size() != criteria.size() - 1) {
        Logger::debug("SearchCriteria: Number of relations does not match number of criteria");
        return false;
    }

    bool answer = matchesItem(criteria.first(), window);
    for (int i = 1; i < criteria.size(); ++i) {
        BooleanRelation relation = relations.at(i-1);
        if (relation == BooleanAnd) {
            answer &= matchesItem(criteria.at(i), window);
        }
        else if (relation == BooleanOr) {
            answer |= matchesItem(criteria.at(i), window);
        }
        else {
            Logger::debug("SearchCriteria: Invalid boolean relation, "+String::number((int)relation));
            return false;
        }
    }

    return answer;
}

/*--------------------------------------------------------------------------+
| Checks if the value given in the criteria matches that of the             |
| given window. The comparison is done based on the property's type.        |
+--------------------------------------------------------------------------*/
bool SearchCriteria::matchesItem(const SearchCriteriaItem& item, Window* window) const {
    switch (item.prop) {
        case TextProp:
            return compareString(item.op, window->getText(), item.value.toString());
        case HandleProp:
            return compareInteger(item.op, (uint)window->getHandle(), item.value.toUInt());
        case WindowClassProp:
            return compareObject<WindowClass*>(item.op, window->getWindowClass(), item.value.value<WindowClass*>());
        case ParentProp:
            return compareObject<Window*>(item.op, window->getParent(), item.value.value<Window*>());
        case StylesProp:
            return listContains<WindowStyle*>(item.op, window->getStandardStyles(), item.value.value<WindowStyle*>());
        case ExtendedStylesProp:
            return listContains<WindowStyle*>(item.op, window->getExtendedStyles(), item.value.value<WindowStyle*>());
        case IsUnicodeProp:
            return compareBoolean(item.op, window->isUnicode(), item.value.toBool());
        case ProcessProp:
            return compareObject(item.op, window->getProcess(), item.value.value<Process*>());
        case ThreadIdProp:
            return compareInteger(item.op, window->getThreadId(), item.value.toUInt());
        default: {
            Logger::debug("SearchCriteria: Invalid property, "+String::number((uint)item.prop));
            return false;
        }
    }
}

bool compareString(OperatorEnum op, String a, String b) {
    switch (op) {
        case StringEqual:
        case GenericEqual:
            return a.compare(b, Qt::CaseInsensitive) == 0;
        case StringEqualCaseSensitive:
            return a.compare(b, Qt::CaseSensitive) == 0;
        case StringNotEqual:
        case GenericNotEqual:
            return a.compare(b, Qt::CaseInsensitive) != 0;
        case StringContains:
            return a.contains(b, Qt::CaseInsensitive);
        case StringMatchesRegex:
            return QRegExp(b, Qt::CaseInsensitive, Settings::regexType).exactMatch(a);
        default: {
            Logger::debug("SearchCriteria: Invalid string operator, "+String::number((uint)op));
            return false;
        }
    }
}

bool compareInteger(OperatorEnum op, uint a, uint b) {
    switch (op) {
        case IntegerEqual:
        case GenericEqual:
            return a == b;
        case IntegerNotEqual:
        case GenericNotEqual:
            return a == b;
        case IntegerLessThan:
            return a < b;
        case IntegerLessThanOrEqual:
            return a <= b;
        case IntegerGreaterThan:
            return a > b;
        case IntegerGreaterThanOrEqual:
            return a >= b;
        default: {
            Logger::debug("SearchCriteria: Invalid integer operator, "+String::number((uint)op));
            return false;
        }
    }
}

bool compareBoolean(OperatorEnum op, bool a, bool b) {
    switch (op) {
        case BooleanEqual:
            return a == b;
        default: {
            Logger::debug("SearchCriteria: Invalid boolean operator, "+String::number((uint)op));
            return false;
        }
    }
}

template <class T>
bool compareObject(OperatorEnum op, T a, T b) {
    switch (op) {
        case GenericEqual:
            return a == b;
        case GenericNotEqual:
            return a != b;
        default: {
            Logger::debug("SearchCriteria: Invalid object operator, "+String::number((uint)op));
            return false;
        }
    }
}

template <class T>
bool listContains(OperatorEnum op, QList<T> list, T value) {
    switch (op) {
        case ListContains:
            return list.contains(value);
        case ListDoesNotContain:
            return !list.contains(value);
        default: {
            Logger::debug("SearchCriteria: Invalid list operator, "+String::number((uint)op));
            return false;
        }
    }
}

QTextStream& operator<<(QTextStream& stream, const SearchCriteriaItem& item) {
    item.printOn(stream);
    return stream;
}

QTextStream& operator<<(QTextStream& stream, const SearchCriteria& searchCriteria) {
    searchCriteria.printOn(stream);
    return stream;
}
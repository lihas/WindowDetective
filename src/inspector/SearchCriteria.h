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

#ifndef SEARCH_CRITERIA_H
#define SEARCH_CRITERIA_H

#include "inspector.h"


// Window properties to search for
enum PropertyEnum {
    TextProp,
    HandleProp,
    WindowClassProp,
    ParentProp,
    StylesProp,
    ExtendedStylesProp,
    IsUnicodeProp,
    ProcessProp,
    ThreadIdProp,
    PropertyCount
};


// Boolean operators that can be applied to a property
enum OperatorEnum {
    GenericEqual,
    GenericNotEqual,
    StringEqual,
    StringEqualCaseSensitive,
    StringNotEqual,
    StringContains,
    StringMatchesRegex,
    IntegerEqual,
    IntegerNotEqual,
    IntegerLessThan,
    IntegerLessThanOrEqual,
    IntegerGreaterThan,
    IntegerGreaterThanOrEqual,
    BooleanEqual,
    ListContains,
    ListDoesNotContain
};


enum BooleanRelation {
    BooleanAnd,
    BooleanOr
};


/*--------------------------------------------------------------------------+
| This object models a single search condition (criteria), where a          |
| particular attribute has some relation to a particular value.             |
| Example:                                                                  |
|    property = "text", operator = "begins with", value = "blah"            |
+--------------------------------------------------------------------------*/
class SearchCriteriaItem {
public:
    PropertyEnum prop;
    OperatorEnum op;
    QVariant value;

    SearchCriteriaItem() :
        prop(), op(), value() {}
    SearchCriteriaItem(PropertyEnum prop, OperatorEnum op, QVariant value) :
        prop(prop), op(op), value(value) {}

    void printOn(QTextStream& stream) const;
};


class SearchCriteria {
private:
    static QList<QList<OperatorEnum>> propertyOperators;
    static QStringList propertyNames;
    static QStringList operatorNames;
public:
    static void initialize();
    static QStringList getPropertyNames() { return propertyNames; }
    static QStringList getOperatorNames() { return operatorNames; }
    static QList<OperatorEnum> getOperatorsForProperty(PropertyEnum p) { return propertyOperators.at((int)p); }

private:
    QList<SearchCriteriaItem> criteria;
    QList<BooleanRelation> relations;
public:
    SearchCriteria();

    void setCriteria(SearchCriteriaItem item);
    void addCriteria(SearchCriteriaItem item, BooleanRelation relation);
    bool matches(Window* window) const;
    bool matchesItem(const SearchCriteriaItem& item, Window* window) const;
    void printOn(QTextStream& stream) const;
};

QTextStream& operator<<(QTextStream& s, const SearchCriteriaItem& item);
QTextStream& operator<<(QTextStream& s, const SearchCriteria& sc);


#endif   // SEARCH_CRITERIA_H
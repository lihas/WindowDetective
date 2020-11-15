//////////////////////////////////////////////////////////////////////////
// File: Resources.h                                                    //
// Date: 2010-07-29                                                     //
// Desc: Manages loading and accessing resources such as window         //
//   class definitions, style definitions, and icons.                   //
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

#ifndef RESOURCES_H
#define RESOURCES_H

#include <QtXml>
#include "window_detective/Error.h"
#include "window_detective/IniFile.h"
#include "inspector/inspector.h"
#include "inspector/DynamicData.h"


class Resources {
public:
    static QHash<String,WindowClass*> windowClasses;
    static WindowStyleList allWindowStyles;
    static WindowStyleList generalWindowStyles;
    static QHash<uint,WindowMessageDefn*> generalMessageDefns;
    static QHash<String,QHash<uint,WindowMessageDefn*>*> classMessageDefns;
    static QHash<String,QHash<uint,String>*> constants;
    static QHash<String,DataType*> dataTypes;
    static QHash<String,QIcon> windowClassIcons;
    static QIcon defaultWindowIcon;

    static void load(String appDir, String userDir = String());
    static void loadConstants(IniFile& ini);
    static void loadDataTypes(QDomElement root);
    static void loadSystemClasses(IniFile& ini);
    static void loadWindowStyles(IniFile& ini);
    static void loadMessagesDefns(QDomElement root);

    static bool hasConstant(String enumName, uint id);
    static String getConstant(String enumName, uint id);
    static QHash<uint,String> getConstants(String enumName);
    static DataType* getDataType(String typeName) { return dataTypes.value(typeName, NULL); }
    static WindowMessageDefn* getMessageDefn(uint id, WindowClass* windowClass = NULL);
    static QHash<uint,WindowMessageDefn*> getWindowClassMessageDefns(String windowClassName);
    static QIcon getWindowClassIcon(String name);
    static WindowStyleList getStandardWindowStyles();
    static WindowStyleList getExtendedWindowStyles();
};


#endif   // RESOURCES_H
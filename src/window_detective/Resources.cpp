//////////////////////////////////////////////////////////////////////////
// File: Resources.cpp                                                  //
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

#include "inspector/inspector.h"
#include "window_detective/Logger.h"
#include "window_detective/main.h"
#include "window_detective/StringFormatter.h"


QHash<String,WindowClass*> Resources::windowClasses;
WindowStyleList Resources::allWindowStyles;
WindowStyleList Resources::generalWindowStyles;
QHash<uint,WindowMessageDefn*> Resources::generalMessageDefns;
QHash<String,QHash<uint,WindowMessageDefn*>*> Resources::classMessageDefns;
QHash<String,QHash<uint,String>*> Resources::constants;
QHash<String,DataType*> Resources::dataTypes;
QHash<String,QIcon> Resources::windowClassIcons;
QIcon Resources::defaultWindowIcon;


/*--------------------------------------------------------------------------+
| Helper function to create an XML dom object from file contents.           |
+--------------------------------------------------------------------------*/
QDomElement loadXmlFile(const String& fileName) {
    QFile file(fileName);
    String fullPath = QFileInfo(file).absoluteFilePath();
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        Logger::error(TR("Could not read data file: %1:\n%2")
                        .arg(fullPath, file.errorString()));
        return QDomElement();
    }

    QDomDocument xmlDoc;
    String errorStr;
    int errorLine, errorCol;
    if (!xmlDoc.setContent(&file, true, &errorStr, &errorLine, &errorCol)) {
        Logger::error(TR("Parse error in file %1\n line %2, column %3: %4")
                        .arg(fullPath).arg(errorLine).arg(errorCol).arg(errorStr));
        return QDomElement();
    }
    
    return xmlDoc.documentElement();
}

/*--------------------------------------------------------------------------+
| Loads all resources from the application's directory. If a user           |
| directory is given, it will append any resources defined there.           |
+--------------------------------------------------------------------------*/
void Resources::load(String appDir, String userDir) {
    // Load the icon for windows that don't have an icon.
    defaultWindowIcon = QIcon(appDir + "\\window_class_icons\\generic_window.png");
    if (defaultWindowIcon.isNull()) {
        Logger::debug("Default window icon (generic_window.png) not found");
    }

    // Load from application directory
    loadConstants(IniFile(appDir + "\\constants.ini"));
    loadDataTypes(loadXmlFile(appDir + "\\data_types.xml"));
    loadSystemClasses(IniFile(appDir + "\\system_classes.ini"));
    loadWindowStyles(IniFile(appDir + "\\window_styles.ini"));
    loadMessagesDefns(loadXmlFile(appDir + "\\message_definitions.xml"));

    // Load from user directory, if it exists
    if (!userDir.isEmpty() && QDir(userDir).exists()) {
        loadConstants(IniFile(userDir + "\\constants.ini"));
        loadMessagesDefns(loadXmlFile(userDir + "\\message_definitions.xml"));
    }
}

/*--------------------------------------------------------------------------+
| Load the list of system defined constants.                                |
+--------------------------------------------------------------------------*/
void Resources::loadConstants(IniFile& ini) {
    while (!ini.isAtEnd()) {
        bool ok;
        String enumName = ini.currentGroup();
        QStringList values = ini.parseLine();

        if (values.size() == 2) {
            uint id = values.at(0).toULong(&ok, 0);
            String name = values.at(1);

            // Add the enum group if it does not already exist
            if (!constants.contains(enumName)) {
                constants.insert(enumName, new QHash<uint,String>());
            }
            // Now add the constant to the enum group
            constants.value(enumName)->insert(id, name);
        }
        else {
            Logger::error("Could not parse line in \"" +
                        ini.getFileName() + "\":\n" +
                        ini.getCurrentLine());
        }

        ini.selectNextEntry();
    }
}

/*------------------------------------------------------------------+
| Loads the types and structs defined in the XML file.              |
+------------------------------------------------------------------*/
void Resources::loadDataTypes(QDomElement root) {
    if (root.tagName() != "types") {
        Logger::warning(TR("Could not find \"types\" root node when loading data types."
                        "\nAttempting to continue anyway."));
    }

    // Parse primitive type definitions
    QDomElement child = root.firstChildElement("primitive");
    while (!child.isNull()) {
        PrimitiveType* newPrimitive = new PrimitiveType(child);
        dataTypes.insert(newPrimitive->getName(), newPrimitive);
        child = child.nextSiblingElement("primitive");
    }

    // Parse struct definitions
    child = root.firstChildElement("struct_definition");
    while (!child.isNull()) {
        try {
            StructDefinition* newDefinition = new StructDefinition(child);
            dataTypes.insert(newDefinition->getName(), newDefinition);
        }
        catch (DynamicStructError e) {
            Logger::error(e, TR("An error occured while reading struct definitions"));
        }
        child = child.nextSiblingElement("struct_definition");
    }
}

/*--------------------------------------------------------------------------+
| Load the list of known Win32 window classes. These are all the            |
| basic controls such as Static and Button.                                 |
+--------------------------------------------------------------------------*/
void Resources::loadSystemClasses(IniFile& ini) {
    while (!ini.isAtEnd()) {
        QStringList values = ini.parseLine();
        if (values.size() == 2) {
            String name = values.at(0);
            String normalizedName = name.toLower();
            String friendlyName = values.at(1);
            windowClasses.insert(normalizedName, new WindowClass(name, friendlyName));
        }
        else {
            Logger::error("Could not parse line in \"" +
                        ini.getFileName() + "\":\n" +
                        ini.getCurrentLine());
        }
        ini.selectNextEntry();
    }
}

/*--------------------------------------------------------------------------+
| Load the list of window style definitions.                                |
+--------------------------------------------------------------------------*/
void Resources::loadWindowStyles(IniFile& ini) {
    WindowStyle* newStyle = NULL;

    while (!ini.isAtEnd()) {
        QStringList classNames = ini.currentGroup().split(',');
        QStringList values = ini.parseLine();

        if (values.size() == 5 || values.size() == 6) {
            if (classNames.first() == "all") {
                newStyle = new WindowStyle(true);
                allWindowStyles.append(newStyle);
                generalWindowStyles.append(newStyle);
            }
            else {
                newStyle = new WindowStyle(false);
                allWindowStyles.append(newStyle);

                // Add this style to each class's list of applicable styles
                WindowClass* wndClass = NULL;
                for (int i = 0; i < classNames.size(); ++i) {
                    wndClass = windowClasses.value(classNames[i].toLower(), NULL);
                    if (wndClass) {
                        wndClass->addApplicableStyle(newStyle);
                    }
                    else {
                        Logger::error(TR("Could not load window styles for window class named \"%1\"."
                                         "It is not a system class.").arg(classNames[i]));
                    }
                }
            }
            newStyle->readFrom(values);
        }
        else {
            Logger::error(TR("Could not parse line in \"%1\":\n%2")
                            .arg(ini.getFileName(), ini.getCurrentLine()));
        }
        ini.selectNextEntry();
    }
}

/*--------------------------------------------------------------------------+
| Load the definitions of each window message.                              |
| For messages applicable to a certain window class, the class's name is    |
| used instead of a WindowClass object, because those objects are created   |
| on demand (i.e. when we actually see a window of that class).             |
+--------------------------------------------------------------------------*/
void Resources::loadMessagesDefns(QDomElement root) {
    if (root.tagName() != "messages") {
        Logger::warning(TR("Could not find \"messages\" root node when loading message definitions."
                        "\nAttempting to continue anyway."));
    }

    QDomElement groupElement = root.firstChildElement("message_group");
    while (!groupElement.isNull()) {
        QStringList classNames = groupElement.attribute("class").split(',');
        QDomElement msgElement = groupElement.firstChildElement("message");

        while (!msgElement.isNull()) {
            try {
                WindowMessageDefn* defn = new WindowMessageDefn(msgElement);
                if (classNames.first() == "all") {
                    generalMessageDefns.insert(defn->getId(), defn);
                }
                else {
                    // Add this message for each applicable window class
                    foreach (String className, classNames) {
                        String classKey = className.toLower();
                        QHash<uint,WindowMessageDefn*>* map = classMessageDefns.value(classKey);
                        if (!map) {
                            map = new QHash<uint,WindowMessageDefn*>();
                            classMessageDefns.insert(classKey, map);
                        }
                        map->insert(defn->getId(), defn);
                    }
                }
            }
            catch (Error e) {
                String msgName = msgElement.attribute("name");
                Logger::error(e, TR("An error occured while reading message definition \"%1\".").arg(msgName));
            }
            msgElement = msgElement.nextSiblingElement("message");
        }
        groupElement = groupElement.nextSiblingElement("message_group");
    }
}

/*--------------------------------------------------------------------------+
| Checks if the given constant id exists in the given enum.                 |
+--------------------------------------------------------------------------*/
bool Resources::hasConstant(String enumName, uint id) {
    QHash<uint,String>* map = constants.value(enumName, NULL);
    return map ? map->contains(id) : false;
}

/*--------------------------------------------------------------------------+
| Returns the name of the given constant id in the given enum.              |
| If the constant does not exist, a string representation of the id         |
| will be returned.                                                         |
+--------------------------------------------------------------------------*/
String Resources::getConstant(String enumName, uint id) {
    if (!hasConstant(enumName, id))
        return String::number(id);
    return constants.value(enumName)->value(id);
}

/*--------------------------------------------------------------------------+
| Returns all constants in the given enum.                                  |
+--------------------------------------------------------------------------*/
QHash<uint,String> Resources::getConstants(String enumName) {
    QHash<uint,String>* map = constants.value(enumName, NULL);
    return map ? *map : QHash<uint, String>();
}

/*--------------------------------------------------------------------------+
| Returns the window message definition for the given id, as applicable to  |
| the given window class. If the class is NULL, it's applicable to all      |
| classes. If no WindowMessageDefn exists, it will be created.              |
+--------------------------------------------------------------------------*/
WindowMessageDefn* Resources::getMessageDefn(uint id, WindowClass* windowClass) {
    WindowMessageDefn* defn = NULL;

    // If a window class is given, look for it first
    if (windowClass) {
        String classKey = windowClass->getName().toLower();
        QHash<uint,WindowMessageDefn*>* map = classMessageDefns.value(classKey, NULL);
        if (map) {
            defn = map->value(id, NULL);
            if (defn) return defn;
        }
    }

    // Then try general (WM_*) messages
    defn = generalMessageDefns.value(id, NULL);
    if (defn) return defn;
    
    // Still not found, create one and add it to general messages (as it's application defined)
    defn = new WindowMessageDefn(id);
    generalMessageDefns.insert(id, defn);
    return defn;
}

/*--------------------------------------------------------------------------+
| Returns all window messages applicable to the given window class.         |
| The name is used as the key, rather than a WindowClass object, because    |
| such an object may not yet exist for the given class.                     |
+--------------------------------------------------------------------------*/
QHash<uint,WindowMessageDefn*> Resources::getWindowClassMessageDefns(String windowClassName) {
    String classKey = windowClassName.toLower();
    QHash<uint,WindowMessageDefn*>* map = classMessageDefns.value(classKey, NULL);
    return map ? *map : QHash<uint,WindowMessageDefn*>();
}

/*--------------------------------------------------------------------------+
| Returns the icon representing the given window class. If it's not         |
| already loaded, the data folders (data/window_class_icons) are searched   |
| to find a png or ico file of the given name.                              |
| User data is checked first, so users are able to override app icons.      |
+--------------------------------------------------------------------------*/
QIcon Resources::getWindowClassIcon(String name) {
    // If it's cached, return that
    QHash<QString, QIcon>::const_iterator i = windowClassIcons.find(name);
    if (i != windowClassIcons.end()) {
        return i.value();
    }

    // First try user data - png format
    String path = userPath()+"/data/window_class_icons/"+name+".png";
    if (!QFile(path).exists()) {
        // Doesn't exist? Try ico format
        path = userPath()+"/data/window_class_icons/"+name+".ico";
        if (!QFile(path).exists()) {
            // If no user file, check app data - png format
            path = appPath()+"/data/window_class_icons/"+name+".png";
            if (!QFile(path).exists()) {
                // If it doesn't exist at all, use default
                return defaultWindowIcon;
            }
        }
    }
    windowClassIcons.insert(name, QIcon(path));
    return windowClassIcons.value(name);
}

WindowStyleList Resources::getStandardWindowStyles() {
    WindowStyleList standardStyles;
    WindowStyleList::const_iterator i;

    for (i = allWindowStyles.begin(); i != allWindowStyles.end(); ++i) {
        if (!(*i)->isExtended()) standardStyles.append(*i);
    }
    return standardStyles;
}

WindowStyleList Resources::getExtendedWindowStyles() {
    WindowStyleList extendedStyles;
    WindowStyleList::const_iterator i;

    for (i = allWindowStyles.begin(); i != allWindowStyles.end(); ++i) {
        if ((*i)->isExtended()) extendedStyles.append(*i);
    }
    return extendedStyles;
}

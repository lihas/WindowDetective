//////////////////////////////////////////////////////////////////////////
// File: SmartSettings.h                                                //
// Date: 2010-05-31                                                     //
// Desc: This class stores a "smart" value, a setting which is          //
//   remembered based on the number of times the value is set. It       //
//   contains a current value, as well as a list of previously set      //
//   values. The list contains a fixed number of values and acts        //
//   like a queue. When the current value is changed, it is also        //
//   pushed onto the list and the last one is removed.                  //
//   When a value is set, it only becomes the current if all other      //
//   remembered values are the same. If all values are different,       //
//   then the old current value is kept.                                //
//   This means that the value will only be remembered if the user      //
//   frequently sets it to a specific value. If they only change        //
//   it once, then it will not remember it and will keep the value      //
//   it had always been. It also can have a threshold which             //
//   ensures that the values don't have to be all identical but         //
//   can be within the threshold.                                       //
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

#ifndef SMART_SETTINGS_H
#define SMART_SETTINGS_H

#include "window_detective/include.h"


template <class T>
class SmartValue {
private:
    String name;
    T currentValue;
    QList<T> previousValues;
    int maxValues;

public:
    /*--------------------------------------------------------------------------+
    | SmartValue Constructor                                                    |
    | Creates an object using the registry key "name". The value will remember  |
    | a maximum of "maxValues" values and have no threshold.                    |
    +--------------------------------------------------------------------------*/
    SmartValue(String name, int maxValues) :
        name(name),
        maxValues(maxValues) {
        read();
    }

    ~SmartValue() {}

    /*--------------------------------------------------------------------------+
    | Reads the member variables from a data stream. The type (T) must have     |
    | defined the appropriate << and >> operators.                              |
    +--------------------------------------------------------------------------*/
    void read() {
        QSettings reg(APP_NAME, APP_NAME);

        String path = name.replace('.', '/');
        QByteArray regData = reg.value("smartSettings/"+path, "").toByteArray();
        if (!regData.isEmpty()) {
            QDataStream stream(regData);
            stream >> currentValue;
            stream >> previousValues;
        }
        else {
            currentValue = T();
            previousValues = QList<T>();
        }
    }

    /*--------------------------------------------------------------------------+
    | Writes the member variables to a data stream. The type (T) must           |
    | have defined the appropriate << and >> operators.                         |
    +--------------------------------------------------------------------------*/
    void store() {
        QSettings reg(APP_NAME, APP_NAME);
        QByteArray data;
        QDataStream stream(&data, QIODevice::WriteOnly);
        stream << currentValue;
        stream << previousValues;
        String path = name.replace('.', '/');
        reg.setValue("smartSettings/"+name, data);
    }

    void store(T newValue) {
        setValue(newValue);
        store();
    }

    T value() {
        return currentValue;
    }

    /*--------------------------------------------------------------------------+
    | Remembers the "newValue" and sets it as the current one if all            |
    | previous values are the same as it.                                       |
    +--------------------------------------------------------------------------*/
    void setValue(T newValue) {
        // Remember new value
        previousValues.prepend(newValue);
        if (previousValues.size() > maxValues) {
            previousValues.removeLast();
        }

        // Check if all previous values are the same
        bool allSame = true;
        for (int i = 1; i < previousValues.size(); ++i) {
            if (!compareValues(previousValues[i], newValue)) {
                allSame = false;
                break;
            }
        }

        // Make the current value the new one
        // if all previous values are the same
        if (allSame) {
            currentValue = newValue;
        }
    }

    virtual bool compareValues(T value1, T value2) {
        return (value1 == value2);
    }
};


template <class T>
class FuzzySmartValue : public SmartValue<T> {
private:
    T threshold;

public:
    /*--------------------------------------------------------------------------+
    | FuzzySmartValue Constructor                                               |
    | Creates an object using the registry key "name". The value will remember  |
    | a maximum of "maxValues" values and have the given threshold.             |
    | Note that the type must be a numerical value.                             |
    +--------------------------------------------------------------------------*/
    FuzzySmartValue(String name, int maxValues, T threshold) :
        SmartValue(name, maxValues),
        threshold(threshold) {
    }

    bool compareValues(T value1, T value2) {
        T difference = value1 - value2;
        return (difference > -threshold && difference < threshold);
    }
};


/*--------------------------------------------------------------------------+
| Class for reading and writing SmartValues.                                |
+--------------------------------------------------------------------------*/
class SmartSettings {
private:
    String subkey;
public:
    SmartSettings() :
        subkey(String()) {
    }

    /*--------------------------------------------------------------------------+
    | Sets the subkey in which all future reads/writes will occur. This means   |
    | that using a subkey "sub", a setting with the name "blah" will resolve to |
    | the full name "sub.blah"                                                  |
    +--------------------------------------------------------------------------*/
    void setSubKey(String keyName) {
        subkey = keyName;
    }

    /*--------------------------------------------------------------------------+
    | Returns a boolean indicating if the given subkey of the                   |
    | "smartSettings" registry key exists.                                      |
    +--------------------------------------------------------------------------*/
    static bool subKeyExist(String subkeyName) {
        HKEY key;
        String name = "Software\\Window Detective\\Window Detective\\smartSettings\\";
        name += subkeyName;
        LONG result = RegOpenKeyExW(HKEY_CURRENT_USER, (LPCWSTR)name.utf16(), 0, KEY_QUERY_VALUE, &key);
        return (result == ERROR_SUCCESS) ? true : false;
    }

    String resolveFullName(String name) {
        return (subkey.isEmpty() ? name : (subkey + "." + name));
    }

    template <class T> T read(String name) {
        String fullName = resolveFullName(name);
        return SmartValue<T>(fullName, 3).value();
    }

    template <class T> void write(String name, T value) {
        String fullName = resolveFullName(name);
        SmartValue<T>(fullName, 3).store(value);
    }

    void writeWindowPos(String name, int value) {
        String fullName = resolveFullName(name);
        FuzzySmartValue<int>(fullName, 2, 100).store(value);
    }
};

#endif   // SMART_SETTINGS_H
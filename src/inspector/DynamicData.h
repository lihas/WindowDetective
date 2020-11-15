//////////////////////////////////////////////////////////////////////////
// File: DynamicData.h                                                  //
// Date: 2010-07-28                                                     //
// Desc: Classes for defining custom data structures. Raw data is       //
//   stored in a block of memory, where each member can be accessed     //
//   using a defined offset and size. The type is also defined along    //
//   with a format (using printf notation).                             //
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

#ifndef DYNAMIC_DATA_H
#define DYNAMIC_DATA_H

#include <QtXml>
#include "window_detective\include.h"
#include "window_detective\Error.h"


// Class declarations
class DataType;
class PrimitiveType;
class FieldDefinition;
class StructDefinition;
class DynamicStruct;


/*--------------------------------------------------------------------------+
| Abstract data type.                                                       |
+--------------------------------------------------------------------------*/
class DataType {
protected:
    String name;                   // Name of this type (e.g. "int", "HWND")
    String printFormat;            // How the data will be printed (using printf-like notation)

public:
    DataType() : name(), printFormat() {}
    String getName() const { return name; }
    String getPrintFormat() const { return printFormat; }
    void setPrintFormat(String str) { printFormat = str; }
    virtual ushort getSize() const = 0;
    virtual ushort getAlignment() const = 0;
    virtual bool isPrimitive() const { return false; }
    virtual bool isStruct() const { return false; }
};


/*--------------------------------------------------------------------------+
| Primitive data type (e.g. int, float).                                    |
+--------------------------------------------------------------------------*/
class PrimitiveType : public DataType {
private:
    ushort size;                     // Size of data (can be 1, 2, 4 or 8 bytes)

public:
    PrimitiveType(QDomElement& node);
    ushort getSize() const { return size; }
    ushort getAlignment() const { return size; }
    bool isPrimitive() const { return true; }
};


/*--------------------------------------------------------------------------+
| Field (variable) for a struct. Can contain any data type.                 |
+--------------------------------------------------------------------------*/
class FieldDefinition {
protected:
    enum FieldFormatType {
        FormatNormal,
        FormatEnum,
        FormatFlags
    };
    String name;                   // Name of this field (i.e. the variable's name)
    DataType* dataType;            // The type of data this field holds
    ushort offset;                 // The byte offset of this field in it's struct
    FieldFormatType formatType;    // When Enum or Flags, printFormat will contain the enum or flag name
    String printFormat;            // Use data type's format if this is empty

public:
    FieldDefinition(QDomElement& node, ushort offset);
    FieldDefinition(String name, String typeName);
    FieldDefinition(StructDefinition* structDefn);
    String getName() const { return name; }
    DataType* getType() const { return dataType; }
    ushort getOffset() const { return offset; }
    String getPrintFormat() const { return printFormat; }
    void setPrintFormat(String str) { printFormat = str; }
    String toString(byte* data) const;
};


/*--------------------------------------------------------------------------+
| Structure type.                                                           |
+--------------------------------------------------------------------------*/
class StructDefinition : public DataType {
private:
    QList<FieldDefinition> fields; // List of fields (members variables)
    ushort size;                   // The combined size of the data types

public:
    StructDefinition(QDomElement& node);

    const FieldDefinition& getField(String name) const;
    const FieldDefinition& getField(int i) const { return fields[i]; }
    int numFields() const { return fields.size(); }
    ushort getSize() const { return size; }
    ushort getAlignment() const;
    bool isStruct() const { return true; }
};


/*--------------------------------------------------------------------------+
| Structure instance.                                                       |
+--------------------------------------------------------------------------*/
class DynamicStruct {
private:
    StructDefinition* definition;   // The type of struct (i.e. the 'class' of this 'instance')
    byte* data;                     // The raw data
    ushort size;                    // Total size of the data (may not be the same as the definiton)

public:
    DynamicStruct() : definition(NULL), data(NULL), size(0) {} // Default constructor - NULL data
    DynamicStruct(StructDefinition* defn, void* data, ushort size);
    ~DynamicStruct();

    void init(StructDefinition* defn, void* data, ushort size);
    StructDefinition* getDefinition() const { return definition; }
    byte* getData() const { return data; }
    ushort getSize() const { return size; }
    bool isNull() const { return data == NULL; }
    template <typename T> T get(String fieldName) const;
    String fieldToString(int fieldIndex) const;

    void toXmlStream(QXmlStreamWriter& stream) const;
};

/*--------------------------------------------------------------------------+
| Template definition (must be in header).                                  |
| Returns the data at the given field, converted to the given type.         |
+--------------------------------------------------------------------------*/
template <typename T>
T DynamicStruct::get(String fieldName) const {
    // TODO
    // check sizeof(T)
    // return static_cast<T>(offset(fieldName));
    return T();
}


/*********************/
/*** Error classes ***/
/*********************/

class DynamicStructError : public Error {
public:
    DynamicStructError() : Error() {}
    DynamicStructError(String msg) : Error("DynamicStructError", msg) {}
};


#endif   // DYNAMIC_DATA_H
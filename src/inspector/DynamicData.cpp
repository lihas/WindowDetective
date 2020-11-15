//////////////////////////////////////////////////////////////////////////
// File: DynamicData.cpp                                                //
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

#include "DynamicData.h"
#include "window_detective/Resources.h"


/*--------------------------------------------------------------------------+
| Returns a string representation of the given data.                        |
| The format notation used here is similar to that of the C printf function |
| but without the need for a percent sign at the start.                     |
| The following specifiers are allowed:                                     |
|  b    boolean ("true" or "false")                                         |
|  i    signed decimal integer                                              |
|  u    unsigned decimal integer                                            |
|  x    unsigned hexadecimal integer                                        |
+--------------------------------------------------------------------------*/
String formatData(byte* data, ushort size, char format) {
    #define CASE_BOOL(f, type) \
        case f: {                           \
            bool val = (bool)(*(type*)data);\
            return val ? "true" : "false";  \
        }
    #define CASE_NUM(f, type) \
        case f: {                           \
            type val = *(type*)data;        \
            return String::number(val);     \
        }
    #define CASE_HEX(f, type) \
        case f: {                           \
            type val = *(type*)data;        \
            return hexString(val);          \
        }

    switch (size) {
        case 1: {
            switch (format) {
                CASE_BOOL('b', char)
                CASE_NUM('i', char)
                CASE_NUM('u', uchar)
                CASE_HEX('x', uchar)
            }
        }
        case 2: {
            switch (format) {
                CASE_BOOL('b', short)
                CASE_NUM('i', short)
                CASE_NUM('u', ushort)
                CASE_HEX('x', ushort)
            }
        }
        case 4: {
            switch (format) {
                CASE_BOOL('b', int)
                CASE_NUM('i', int)
                CASE_NUM('u', uint)
                CASE_HEX('x', uint)
            }
        }
        case 8: {
            switch (format) {
                CASE_BOOL('b', int64)
                CASE_NUM('i', int64)
                CASE_NUM('u', uint64)
                CASE_HEX('x', uint64)
            }
        }
    }
    return "";
}


/***************************/
/*** PrimitiveType class ***/
/***************************/

/*--------------------------------------------------------------------------+
| Constructor. Creates a primitive type from the given XML.                 |
+--------------------------------------------------------------------------*/
PrimitiveType::PrimitiveType(QDomElement& node) {
    bool ok;
    name = node.attribute("name");
    size = node.attribute("size").toUInt(&ok);
    printFormat = node.attribute("format");
}


/*****************************/
/*** FieldDefinition class ***/
/*****************************/

/*--------------------------------------------------------------------------+
| Constructor. Creates object from XML.                                     |
+--------------------------------------------------------------------------*/
FieldDefinition::FieldDefinition(QDomElement& node, ushort unalignedOffset) {
    name = node.attribute("name");
    String typeName = node.attribute("type");
    dataType = Resources::getDataType(typeName);

    // Make sure the data type exists
    if (!dataType) {
        throw DynamicStructError(TR("Field \"%1\" - no such data type \"%2\".").arg(name, typeName));
    }

    // Compute correctly aligned offset
    ushort align = dataType->getAlignment();
    offset = (unalignedOffset + align - 1) & ~(align - 1);

    // Determine whether the field holds an enum or flags. If it does, the printFormat
    // will hold the name of the enum or flag (as defined in constants.ini)
    if (node.hasAttribute("enum")) {
        // Make sure the data type is a primitive
        if (!dataType->isPrimitive()) {
            throw DynamicStructError(TR("Enum field \"%1\" must be primitive type.").arg(name));
        }
        formatType = FormatEnum;
        printFormat = node.attribute("enum");
    }
    else if (node.hasAttribute("flags")) {
        if (!dataType->isPrimitive()) {
            throw DynamicStructError(TR("Flag field \"%1\" must be primitive type.").arg(name));
        }
        formatType = FormatFlags;
        printFormat = node.attribute("flags");
    }
    else {
        formatType = FormatNormal;
        printFormat = node.attribute("format");
    }
}

/*--------------------------------------------------------------------------+
| Constructor. Creates a field with the given name and type.                |
+--------------------------------------------------------------------------*/
FieldDefinition::FieldDefinition(String name, String typeName) :
    name(name),
    offset(0),
    formatType(FormatNormal) {
    dataType = Resources::getDataType(typeName);

    // Make sure the data type exists
    if (!dataType) {
        throw DynamicStructError(TR("Field \"%1\" - no such data type \"%2\".").arg(name, typeName));
    }
}

/*--------------------------------------------------------------------------+
| Constructor. Creates a field using the given struct definition as it's    |
| data type. This is used to create dummy fields for top-level structs,     |
| to make recursive functions neater.                                       |
+--------------------------------------------------------------------------*/
FieldDefinition::FieldDefinition(StructDefinition* structDefn) :
    offset(0),
    formatType(FormatNormal),
    printFormat() {
    name = structDefn->getName();
    dataType = structDefn;
}

/*--------------------------------------------------------------------------+
| Returns a string representation of the given data.                        |
+--------------------------------------------------------------------------*/
String FieldDefinition::toString(byte* data) const {
    if (!dataType || !data) return String();

    ushort size = dataType->getSize();
    String format = printFormat;
    if (format.isEmpty()) format = dataType->getPrintFormat();

    if (formatType == FormatNormal) {
        char fmtLetter = format.isEmpty() ? 'i' : format.at(0).toLatin1();
        return formatData(data, size, fmtLetter);
    }
    else {
        uint intData = 0;
        switch (size) {
            case 1: intData = (uint)(*(char*)data); break;
            case 2: intData = (uint)(*(short*)data); break;
            case 4: intData = (uint)(*(int*)data); break;
            // I don't think any enums would be 8 bytes wide
        }
        if (formatType == FormatEnum) {
            return Resources::getConstant(format, intData);
        }
        else if (formatType == FormatFlags) {
            String combination;
            QTextStream stream(&combination);
            bool isFirst = true;   // To determine if a "|" needs to be appended

            QHash<uint,String> flagNames = Resources::getConstants(format);
            QHash<uint,String>::const_iterator i;
            for (i = flagNames.begin(); i != flagNames.end(); ++i) {
                if ((i.key() & intData) == i.key()) {
                    if (!isFirst) stream << " | ";
                    stream << i.value();
                    isFirst = false;
                }
            }
            return combination;
        }
    }
    return "";
}


/******************************/
/*** StructDefinition class ***/
/******************************/

/*--------------------------------------------------------------------------+
| Constructor. Creates struct and fields from the given XML.                |
+--------------------------------------------------------------------------*/
StructDefinition::StructDefinition(QDomElement& node) :
    fields(), size(0) {
    name = node.attribute("name");
    ushort currentOffset = 0;
    QDomElement child = node.firstChildElement();
    while (!child.isNull()) {
        FieldDefinition field(child, currentOffset);
        fields.append(field);

        // The field computes it's correctly aligned offset. Increment that by field's size.
        currentOffset = field.getOffset() + field.getType()->getSize();

        child = child.nextSiblingElement();
    }
    // The struct must be properly aligned too, it might need padding at the end.
    ushort align = getAlignment();
    currentOffset = (currentOffset + align - 1) & ~(align - 1);
    size = currentOffset;
}

/*--------------------------------------------------------------------------+
| Returns the field definition with the given name.                         |
| Return NULL if one doesn't exist (caller must check for this).            |
+--------------------------------------------------------------------------*/
const FieldDefinition& StructDefinition::getField(String name) const {
    QList<FieldDefinition>::const_iterator i;
    for (i = fields.begin(); i != fields.end(); ++i) {
        if ((*i).getName() == name) {
            return *i;
        }
    }
    throw DynamicStructError(TR("No field named %1 in struct %2").arg(name, this->name));
}

/*--------------------------------------------------------------------------+
| The alignment of structs is that of their largest member.                 |
+--------------------------------------------------------------------------*/
ushort StructDefinition::getAlignment() const {
    ushort max = 0;

    QList<FieldDefinition>::const_iterator i;
    for (i = fields.begin(); i != fields.end(); ++i) {
        max = qMax(max, (*i).getType()->getAlignment());
    }

    return max;
}


/***************************/
/*** DynamicStruct class ***/
/***************************/

DynamicStruct::DynamicStruct(StructDefinition* defn, void* inData, ushort inSize) :
    definition(defn),
    data(NULL),
    size(inSize) {
    init(defn, inData, inSize);
}

DynamicStruct::~DynamicStruct() {
    if (data) free(data);
    data = NULL;
}


/*--------------------------------------------------------------------------+
| Initializes the structure with a copy of the given data.                  |
+--------------------------------------------------------------------------*/
void DynamicStruct::init(StructDefinition* defn, void* inData, ushort inSize) {
    // Delete any previous data
    if (data) {
        free(data);
        data = NULL;
    }

    definition = defn;

    // Allocate memory and copy data pointed at by dataPtr
    size = inSize;
    if (inData && size >= definition->getSize()) {
        data = (byte*)malloc(size);
        memcpy_s(data, size, inData, inSize);
    }
}

/*--------------------------------------------------------------------------+
| Returns a formatted string with the value of the field.                   |
+--------------------------------------------------------------------------*/
String DynamicStruct::fieldToString(int fieldIndex) const {
    const FieldDefinition& field = definition->getField(fieldIndex);
    DataType* dataType = field.getType();
    if (!dataType || !data) return String();

    byte* start = data + field.getOffset();
    return field.toString(start);
}

/*--------------------------------------------------------------------------+
| Writes an XML representation of this object to the given stream.          |
+--------------------------------------------------------------------------*/
void dataToXmlStream(QXmlStreamWriter& stream, const FieldDefinition& field, byte* data) {
    if (field.getType()->isStruct()) {
        stream.writeStartElement(field.getName());
        StructDefinition* structDefn = static_cast<StructDefinition*>(field.getType());
        for (int i = 0; i < structDefn->numFields(); ++i) {
            const FieldDefinition& subField = structDefn->getField(i);
            byte* subFieldData = data + subField.getOffset();
            dataToXmlStream(stream, subField, subFieldData);
        }
        stream.writeEndElement();
    }
    else {
        stream.writeTextElement(field.getName().replace(' ','_'), field.toString(data));
    }
}
void DynamicStruct::toXmlStream(QXmlStreamWriter& stream) const {
    dataToXmlStream(stream, FieldDefinition(getDefinition()), getData());
}

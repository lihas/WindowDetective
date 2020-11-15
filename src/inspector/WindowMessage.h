//////////////////////////////////////////////////////////////////////////
// File: WindowMessage.h                                                //
// Date: 2012-04-27                                                     //
// Desc: Classes for window message definitions and instances.          //
//   A message definition stores it's id and name, as well as           //
//   definitions of parameters that are passed in the wParam and lParam //
//   values. A message instance stores the actual data.                 //
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

#ifndef WINDOW_MESSAGE_H
#define WINDOW_MESSAGE_H

#include <QtXml>
#include "window_detective/Error.h"
#include "inspector/RemoteFunctions.h"
#include "inspector/DynamicData.h"
#include "hook/Hook.h"


/*--------------------------------------------------------------------------+
| Parameter for a message. Similar to a struct field, except that the data  |
| is taken from all or part of a message's wParam or lParam value.          |
+--------------------------------------------------------------------------*/
class MessageParameter : public FieldDefinition {
private:
    enum { WParam, LParam, Return } param;
    enum { Full, LoWord, HiWord, LoByte, HiByte } part;

public:
    MessageParameter(String name, String typeName) :
        FieldDefinition(name, typeName), part(Full) {}
    MessageParameter(QDomElement& node);
    static MessageParameter* makeWParam();
    static MessageParameter* makeLParam();
    bool isParam1() const { return param == WParam; }
    bool isParam2() const { return param == LParam; }
    bool isReturn() const { return param == Return; }
    String toString(const WindowMessage* msg) const;
};


/*--------------------------------------------------------------------------+
| The definition of a window message.                                       |
+--------------------------------------------------------------------------*/
class WindowMessageDefn {
private:
    uint id;                           // Message identifier
    String name;                       // Name as definied in Windows API, or registered by user
    QList<MessageParameter*> inParams; // Parameters passed in wParam or lParam
    QList<MessageParameter*> outParams;// Parameters passed out from wParam, lParam or return
    StructDefinition* structDefn1;     // Definition of extra data in wParam, if any
    StructDefinition* structDefn2;     // Definition of extra data in lParam, if any

public:
    WindowMessageDefn(QDomElement& node);
    WindowMessageDefn(UINT id);

    uint getId() const { return id; }
    String getName() const { return name; }
    const QList<MessageParameter*>& getInParams() const { return inParams; }
    const QList<MessageParameter*>& getOutParams() const { return outParams; }
    StructDefinition* getStructDefn1() const { return structDefn1; }
    StructDefinition* getStructDefn2() const { return structDefn2; }
    static String nameForId(uint id);
    void toXmlStream(QXmlStreamWriter& stream);
};


/*--------------------------------------------------------------------------+
| Represents a message event that a window receives                         |
+--------------------------------------------------------------------------*/
class WindowMessage {
private:
    WindowMessageDefn* defn;     // Like the "class" of this "instance"
    Window* window;              // Window that receives this message
    MessageType type;            // Indicates where the message came from
    QTime time;                  // Time when the message was captured by the hook
    WPARAM param1;               // 1st parameter (wParam)
    LPARAM param2;               // 2nd parameter (lParam)
    DynamicStruct extraData1;    // Extra data struct for wParam
    DynamicStruct extraData2;    // Extra data struct for lParam
    LRESULT returnValue;         // Return value from whoever handled this

public:
    WindowMessage() {}
    WindowMessage(WindowMessageDefn* defn, Window* window, WPARAM param1, LPARAM param2);
    WindowMessage(WindowMessageDefn* defn, Window* window, const MessageEvent& evnt);

    void initParams(WPARAM wParam, LPARAM lParam, LRESULT returnValue,
                    void* extraData1, ushort dataSize1, void* extraData2, ushort dataSize2);
    WindowMessageDefn* getDefinition() const { return defn; }
    Window* getWindow() const { return window; }
    uint getId() const { return defn ? defn->getId() : 0; }
    String getName() const { return defn ? defn->getName() : ""; }
    QTime getTime() const { return time; }
    WPARAM getParam1() const { return param1; }
    LPARAM getParam2() const { return param2; }
    const DynamicStruct& getExtraData1() const { return extraData1; }
    const DynamicStruct& getExtraData2() const { return extraData2; }
    LRESULT getReturnValue() const { return returnValue; }
    void setReturnValue(LRESULT val) { returnValue = val; }
    bool isSent() const   { return (type & MessageTypeMask) == MessageCall; }
    bool isPosted() const { return (type & MessageTypeMask) == MessageFromQueue; }
    bool isReturn() const { return (type & MessageTypeMask) == MessageReturn; }
    LRESULT send();
    void toXmlStream(QXmlStreamWriter& stream) const;
};


/*********************/
/*** Error classes ***/
/*********************/

class MessageParameterError : public Error {
public:
    MessageParameterError() : Error() {}
    MessageParameterError(String msg) : Error("MessageParameterError", msg) {}
};


#endif   // WINDOW_MESSAGE_H
//////////////////////////////////////////////////////////////////////////
// File: WindowMessage.cpp                                              //
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

#include "inspector.h"
#include "WindowManager.h"
#include "MessageHandler.h"
#include "window_detective/Logger.h"
#include "inspector/RemoteFunctions.h"
#include "window_detective/StringFormatter.h"
#include "window_detective/QtHelpers.h"


/******************************/
/*** MessageParameter class ***/
/******************************/

/*--------------------------------------------------------------------------+
| Constructor. Creates from the given XML element.                          |
+--------------------------------------------------------------------------*/
MessageParameter::MessageParameter(QDomElement& node) :
    FieldDefinition(node, 0) {

    String fromStr = node.attribute("from");

    int index;
    if ((index = fromStr.indexOf("LOWORD", 0, Qt::CaseInsensitive)) != -1) {
        part = LoWord;
    }
    else if ((index = fromStr.indexOf("HIWORD", 0, Qt::CaseInsensitive)) != -1) {
        part = HiWord;
    }
    else if ((index = fromStr.indexOf("LOBYTE", 0, Qt::CaseInsensitive)) != -1) {
        part = LoByte;
    }
    else if ((index = fromStr.indexOf("HIBYTE", 0, Qt::CaseInsensitive)) != -1) {
        part = HiByte;
    }
    else {
        index = 0;
        part = Full;
    }

    if (fromStr.indexOf("wParam", index, Qt::CaseInsensitive) != -1) {
        param = WParam;
    }
    else if (fromStr.indexOf("lParam", index, Qt::CaseInsensitive) != -1) {
        param = LParam;
    }
    else if (fromStr.indexOf("return", index, Qt::CaseInsensitive) != -1) {
        param = Return;
    }
    else {
        throw MessageParameterError(TR("Message parameter \"%1\" - unknown value in \"from\" attribute").arg(name));
    }
}

/*--------------------------------------------------------------------------+
| Factory functions. Create basic WPARAM and LPARAM parameters.             |
| Used for messages which are not defined in the XML.                       |
+--------------------------------------------------------------------------*/
MessageParameter* MessageParameter::makeWParam() {
    MessageParameter* param = new MessageParameter("wParam", "UINT_PTR");
    param->param = WParam;
    return param;
}
MessageParameter* MessageParameter::makeLParam() {
    MessageParameter* param = new MessageParameter("lParam", "UINT_PTR");
    param->param = LParam;
    return param;
}

/*--------------------------------------------------------------------------+
| Returns a string representation of the given data.                        |
+--------------------------------------------------------------------------*/
String MessageParameter::toString(const WindowMessage* msg) const {
    // Get the data from the parameter
    uint intData = 0;
    switch (param) {
        case WParam: intData = (uint)msg->getParam1(); break;
        case LParam: intData = (uint)msg->getParam2(); break;
        case Return: intData = (uint)msg->getReturnValue(); break;
    }

    // Get high or low part if necessary
    switch (part) {
        case LoWord: intData = LOWORD(intData); break;
        case HiWord: intData = HIWORD(intData); break;
        case LoByte: intData = LOBYTE(intData); break;
        case HiByte: intData = HIBYTE(intData); break;
    }

    // Do the rest of the formatting
    // TODO: This data will always be a certain size (32 or 64 bits). It would be good
    // to let the super method know this, otherwise it would be possible to configure
    // a message to have a param type larger than the actual wParam or lParam values.
    return FieldDefinition::toString((byte*)&intData);
}


/*******************************/
/*** WindowMessageDefn class ***/
/*******************************/

/*--------------------------------------------------------------------------+
| Constructor. Creates from the given XML element.                          |
+--------------------------------------------------------------------------*/
WindowMessageDefn::WindowMessageDefn(QDomElement& node) :
    structDefn1(NULL),
    structDefn2(NULL) {
    bool ok;

    id = node.attribute("id").toULong(&ok, 0);
    name = node.attribute("name");

    QDomElement child = node.firstChildElement("param");
    while (!child.isNull()) {
        MessageParameter* param = new MessageParameter(child);

        // Add to in/out parameter list.
        // Structs and pointers can be passed both in and out.
        if (param->getType()->isStruct()) {  // TODO: isPointer (and structs are also pointers)
            String passedStr = child.attribute("passed", "in");
            if (passedStr.indexOf("in", 0, Qt::CaseInsensitive) != -1) {
                inParams.append(param);
            }
            if (passedStr.indexOf("out", 0, Qt::CaseInsensitive) != -1) {
                outParams.append(param);
            }
        }
        else {
            if (param->isReturn()) {
                outParams.append(param);
            }
            else {
                inParams.append(param);
            }
        }

        // Remember the struct definition for easy access when creating message instances
        if (param->getType()->isStruct()) {
            if (param->isParam1()) {
                structDefn1 = static_cast<StructDefinition*>(param->getType());
            }
            else if (param->isParam2()) {
                structDefn2 = static_cast<StructDefinition*>(param->getType());
            }
        }
        child = child.nextSiblingElement("param");
    }
}

/*--------------------------------------------------------------------------+
| Constructor. Creates an application-defined message with the given id.    |
+--------------------------------------------------------------------------*/
WindowMessageDefn::WindowMessageDefn(uint id) :
    id(id),
    structDefn1(NULL),
    structDefn2(NULL) {
    name = nameForId(id);
    inParams.append(MessageParameter::makeWParam());
    inParams.append(MessageParameter::makeLParam());
    // TODO: Could also create return param too. And in XML constructor if it's not explicitly
    //   defined. Then there would be no need for the code in MessageWidget::addMessageParams
}

/*--------------------------------------------------------------------------+
| Returns an appropriate name for an application-defined message id.        |
+--------------------------------------------------------------------------*/
String WindowMessageDefn::nameForId(uint id) {
    if (id >= WM_USER && id <= 0x7FFF) {        // Specific to window class
        return "WM_USER + " + String::number(id-WM_USER);
    }
    else if (id >= WM_APP && id <= 0xBFFF) {    // Application wide
        return "WM_APP + " + String::number(id-WM_APP);
    }
    else if (id >= 0xC000 && id <= 0xFFFF) {    // Registered with a name
        WCHAR szName[256];
        ZeroMemory(szName, 256);
        int length = GetClipboardFormatNameW(id, szName, 256);
        if (length > 0) {
            return wCharToString(szName, length);
        }
    }
    return TR("Unknown");   // No name matches
}


/***************************/
/*** WindowMessage class ***/
/***************************/

/*--------------------------------------------------------------------------+
| Constructor. Takes id and parameters, no extra data.                      |
+--------------------------------------------------------------------------*/
WindowMessage::WindowMessage(WindowMessageDefn* defn, Window* window,
                             WPARAM wParam, LPARAM lParam) :
    defn(defn), window(window), type((MessageType)0), time() {
    initParams(wParam, lParam, 0, NULL, 0, NULL, 0);
}

/*--------------------------------------------------------------------------+
| Constructs a WindowMessage from a MessageEvent.                           |
+--------------------------------------------------------------------------*/
WindowMessage::WindowMessage(WindowMessageDefn* defn, Window* window, const MessageEvent& evnt) :
    defn(defn),
    window(window),
    type(evnt.type) {
    time = QTime(evnt.time.wHour,
                 evnt.time.wMinute,
                 evnt.time.wSecond,
                 evnt.time.wMilliseconds);
    initParams(evnt.wParam, evnt.lParam, evnt.returnValue,
               evnt.extraData1, evnt.dataSize1,
               evnt.extraData2, evnt.dataSize2);
}

/*--------------------------------------------------------------------------+
| Initialize parameter data, called by the constructors.                    |
+--------------------------------------------------------------------------*/
void WindowMessage::initParams(WPARAM wParam, LPARAM lParam, LRESULT returnValue,
                               void* extraData1, ushort dataSize1, void* extraData2, ushort dataSize2) {
    this->param1 = wParam;
    this->param2 = lParam;
    this->returnValue = returnValue;

    if (defn) {
        if (extraData1 && (dataSize1 > 0)) {
            StructDefinition* structDefn1 = defn->getStructDefn1();
            if (structDefn1) {
                this->extraData1.init(structDefn1, extraData1, dataSize1);
            }
        }
        if (extraData2 && (dataSize2 > 0)) {
            StructDefinition* structDefn2 = defn->getStructDefn2();
            if (structDefn2) {
                this->extraData2.init(structDefn2, extraData2, dataSize2);
            }
        }
    }
}

LRESULT WindowMessage::send() {
    if (!window) return 0;

    returnValue = window->sendMessage<LRESULT,WPARAM,LPARAM>(getId(), param1, param2);
    return returnValue;
}

/*--------------------------------------------------------------------------+
| Writes an XML representation of this object to the given stream.          |
+--------------------------------------------------------------------------*/
void WindowMessage::toXmlStream(QXmlStreamWriter& stream) const {
    stream.writeStartElement("windowMessage");
    stream.writeAttribute("id", stringLabel(getId()));
    stream.writeAttribute("name", stringLabel(getName()));
    if (isSent())        { stream.writeAttribute("type", "sent");    }
    else if (isPosted()) { stream.writeAttribute("type", "posted");  }
    else if (isReturn()) { stream.writeAttribute("type", "returned");}

    bool hasReturnParams = false;
    const WindowMessageDefn* defn = getDefinition();
    const QList<MessageParameter*> params = (isReturn() ? defn->getOutParams() : defn->getInParams());

    QList<MessageParameter*>::const_iterator i;
    for (i = params.begin(); i != params.end(); ++i) {
        MessageParameter* param = *i;
        if (param->isReturn()) hasReturnParams = true;
        if (param->getType()->isStruct()) {
            stream.writeStartElement(param->getName());
            if (param->isParam1()) {
                getExtraData1().toXmlStream(stream);
            }
            else if (param->isParam2()) {
                getExtraData2().toXmlStream(stream);
            }
            stream.writeEndElement();
        }
        else {
            stream.writeTextElement(param->getName().replace(' ','_'), param->toString(this));
        }
    }

    if (isReturn() && !hasReturnParams) {
        // Most messages will return 0 if they have been processed, so it's not necessary to
        // define a return param for each message. If it isn't explicitly defined, add it now.
        stream.writeTextElement("returnValue", hexString((uint)returnValue));
    }
    stream.writeEndElement();
}

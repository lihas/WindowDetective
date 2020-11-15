//////////////////////////////////////////////////////////////////////////
// File: WindowMisc.cpp                                                 //
// Date: 2010-03-04                                                     //
// Desc: Definitions of all window related classes. Most of these       //
//   objects are not often changed (unlike Window), and as such         //
//   they are only updated once in the contructor.                      //
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
#include "window_detective/StringFormatter.h"
#include "window_detective/QtHelpers.h"


/*************************/
/*** WindowClass class ***/
/*************************/

/*--------------------------------------------------------------------------+
| Basic constructor.                                                        |
| Used for creating a class that an application has registered.             |
+--------------------------------------------------------------------------*/
WindowClass::WindowClass(String name) :
    name(name), friendlyName(), styleBits(0),
    styles(), applicableStyles(), windowMessageNames(),
    classExtraBytes(0), windowExtraBytes(0),
    backgroundBrush(NULL), native(false) {

    // Find and load icon. Can be either PNG or ICO file
    icon = Resources::getWindowClassIcon(name);
}

/*--------------------------------------------------------------------------+
| Full constructor.                                                         |
| Used for creating a standard Win32 class from the INI file.               |
+--------------------------------------------------------------------------*/
WindowClass::WindowClass(String name, String friendlyName, bool isNative) :
    name(name), friendlyName(friendlyName), styleBits(0),
    styles(), applicableStyles(), windowMessageNames(),
    classExtraBytes(0), windowExtraBytes(0),
    backgroundBrush(NULL), native(isNative) {

    // Find and load icon. Can be either PNG or ICO file
    icon = Resources::getWindowClassIcon(name);
}

/*--------------------------------------------------------------------------+
| Copy constructor.                                                         |
+--------------------------------------------------------------------------*/
WindowClass::WindowClass(const WindowClass& other) :
    name(other.name),
    friendlyName(other.friendlyName),
    styleBits(other.styleBits),
    styles(other.styles),
    applicableStyles(other.applicableStyles),
    windowMessageNames(other.windowMessageNames),
    classExtraBytes(other.classExtraBytes),
    windowExtraBytes(other.windowExtraBytes),
    backgroundBrush(other.backgroundBrush),
    native(other.native),
    icon(other.icon) {
}

/*--------------------------------------------------------------------------+
| Destructor.                                                               |
+--------------------------------------------------------------------------*/
WindowClass::~WindowClass() {
    if (backgroundBrush) {
        delete backgroundBrush;
        backgroundBrush = NULL;
    }
}

/*--------------------------------------------------------------------------+
| Returns a hash map of all applicable window messages for this class.      |
+--------------------------------------------------------------------------*/
QHash<uint,WindowMessageDefn*> WindowClass::getApplicableMessages() const {
    return Resources::getWindowClassMessageDefns(getName());
}

/*--------------------------------------------------------------------------+
| Some built-in Win32 classes do not have a very descriptive name           |
| so return the class name followed by a "friendly" name.                   |
| e.g. "msctls_statusbar32 (Status Bar)"                                    |
|      "#32769 (Desktop)"                                                   |
+--------------------------------------------------------------------------*/
String WindowClass::getDisplayName() {
    if (friendlyName.isEmpty())
        return name;
    else
        return name + " (" + friendlyName + ")";
}

/*--------------------------------------------------------------------------+
| Returns a list of window class styles.                                    |
+--------------------------------------------------------------------------*/
QStringList WindowClass::getStyles() {
    if (styles.isEmpty()) {
        styles = WindowManager::current().parseClassStyle(styleBits);
    }
    return styles;
}

/*--------------------------------------------------------------------------+
| Appends the given window style object to the list of applicable           |
| styles for this class. Should only be used at initialization.             |
+--------------------------------------------------------------------------*/
void WindowClass::addApplicableStyle(WindowStyle* s) {
    applicableStyles.append(s);
}

/*--------------------------------------------------------------------------+
| Sets the style bits for this window class, and rebuilds the list.         |
+--------------------------------------------------------------------------*/
void WindowClass::setStyleBits(uint bits) {
    styleBits = bits;
    styles.clear();
}

void WindowClass::setBackgroundBrush(WinBrush* brush) {
    if (backgroundBrush) delete backgroundBrush;
    backgroundBrush = brush;
}

/*--------------------------------------------------------------------------+
| Writes an XML representation of this object to the given stream.          |
+--------------------------------------------------------------------------*/
void WindowClass::toXmlStream(QXmlStreamWriter& stream) const {
    stream.writeStartElement("windowClass");
     stream.writeTextElement("name", stringLabel(getName()));
     stream.writeTextElement("atom", hexString(getId()));
     stream.writeTextElement("styleBits", hexString(getStyleBits()));
     stream.writeTextElement("classExtraBytes", stringLabel(getClassExtraBytes()));
     stream.writeTextElement("windowExtraBytes", stringLabel(getWindowExtraBytes()));
     if (backgroundBrush) {
         backgroundBrush->toXmlStream(stream);
     }
    stream.writeEndElement();
}


/*************************/
/*** WindowStyle class ***/
/*************************/

/*--------------------------------------------------------------------------+
| Constructor.                                                              |
+--------------------------------------------------------------------------*/
WindowStyle::WindowStyle(bool isGeneric) :
    value(0), isGeneric(isGeneric), extended(false) {
}

/*--------------------------------------------------------------------------+
| Copy constructor.                                                         |
+--------------------------------------------------------------------------*/
WindowStyle::WindowStyle(const WindowStyle& other) :
    name(other.name),
    value(other.value),
    isGeneric(other.isGeneric),
    extended(other.extended),
    depends(other.depends),
    excludes(other.excludes),
    description(other.description) {
}

/*--------------------------------------------------------------------------+
| Creates this object from the given string values.                         |
| The values are as follows (same as in INI file):                          |
|   "id, name, depends, excludes, description"                              |
+--------------------------------------------------------------------------*/
void WindowStyle::readFrom(QStringList values) {
    bool ok;

    value = values.at(0).toULong(&ok, 0);
    name = values.at(1);
    extended = !values.at(2).compare("true", Qt::CaseInsensitive);
    depends = values.at(3).toULong(&ok, 0);
    excludes = values.at(4).toULong(&ok, 0);
    description = (values.size() == 6 ? values.at(5) : "");
}

/*--------------------------------------------------------------------------+
| Returns true if this style can be applied to a window of the              |
| given window class.                                                       |
+--------------------------------------------------------------------------*/
bool WindowStyle::isValidFor(WindowClass* windowClass) {
    // Generic window styles (WS_*) are valid for any class
    if (isGeneric)
        return true;

    // Otherwise, check if it is one of the class's applicable styles
    WindowStyleList list = windowClass->getApplicableStyles();
    WindowStyleList::const_iterator i;
    for (i = list.begin(); i != list.end(); ++i) {
        if (*i == this) return true;
    }
    return false;
}


/************************/
/*** WindowProp class ***/
/************************/

/*--------------------------------------------------------------------------+
| Writes an XML representation of this object to the given stream.          |
+--------------------------------------------------------------------------*/
void WindowProp::toXmlStream(QXmlStreamWriter& stream) const {
    stream.writeStartElement("windowProp");
     stream.writeTextElement("name", stringLabel(name));
     stream.writeTextElement("data", hexString((uint)data));
    stream.writeEndElement();
}


/**********************/
/*** WinBrush class ***/
/**********************/

/*--------------------------------------------------------------------------+
| Constructor.                                                              |
+--------------------------------------------------------------------------*/
WinBrush::WinBrush(HBRUSH handle, LOGBRUSH brush) :
    handle(handle) {
    style = brush.lbStyle;
    colour = brush.lbColor;
    hatchType = brush.lbHatch;
}

String WinBrush::getStyleName() const {
    return Resources::getConstant("BrushStyle", style);
}

String WinBrush::getHatchName() const {
    return Resources::getConstant("HatchStyle", hatchType);
}

/*--------------------------------------------------------------------------+
| Writes an XML representation of this object to the given stream.          |
+--------------------------------------------------------------------------*/
void WinBrush::toXmlStream(QXmlStreamWriter& stream) const {
    stream.writeStartElement("brush");
     if (handle) {
         // Check if the handle is actually a colour id
         uint id = (uint)handle - 1;
         if (Resources::hasConstant("SystemColour", id)) {
             stream.writeCharacters(Resources::getConstant("SystemColour", id));
         }
         else {
             stream.writeTextElement("handle", hexString((uint)handle));

             stream.writeStartElement("style");
             stream.writeAttribute("value", stringLabel(style));
             stream.writeAttribute("name", stringLabel(getStyleName()));
             stream.writeEndElement();

             stream.writeStartElement("hatch");
             stream.writeAttribute("value", stringLabel(hatchType));
             stream.writeAttribute("name", stringLabel(getHatchName()));
             stream.writeEndElement();

             QColor qColour = QColorFromCOLORREF(colour);
             stream.writeStartElement("colour");
             stream.writeAttribute("red", stringLabel(qColour.red()));
             stream.writeAttribute("green", stringLabel(qColour.green()));
             stream.writeAttribute("blue", stringLabel(qColour.blue()));
             stream.writeEndElement();
         }
     }
     else {
         stream.writeCharacters("none");
     }
    stream.writeEndElement();
}


/*********************/
/*** WinFont class ***/
/*********************/

/*--------------------------------------------------------------------------+
| Constructor for font handle and attributes (LOGFONT).                     |
+--------------------------------------------------------------------------*/
WinFont::WinFont(HFONT handle, LOGFONTW font) :
    handle(handle) {
    faceName = wCharToString(font.lfFaceName);
    width = font.lfWidth;
    height = font.lfHeight;
    weight = font.lfWeight;
    quality = font.lfQuality;
    style = (font.lfItalic & 0x01) |
           ((font.lfUnderline & 0x01) << 1) |
           ((font.lfStrikeOut & 0x01) << 2);
}

/*--------------------------------------------------------------------------+
| Constructor that defines the attributes of a font (LOGFONT), but not an   |
| actual font handle.                                                       |
+--------------------------------------------------------------------------*/
WinFont::WinFont(LOGFONTW font) :
    handle(NULL) {
    faceName = wCharToString(font.lfFaceName);
    width = font.lfWidth;
    height = font.lfHeight;
    weight = font.lfWeight;
    quality = font.lfQuality;
    style = (font.lfItalic & 0x01) |
           ((font.lfUnderline & 0x01) << 1) |
           ((font.lfStrikeOut & 0x01) << 2);
}

/*--------------------------------------------------------------------------+
| Copy Constructor.                                                         |
+--------------------------------------------------------------------------*/
WinFont::WinFont(const WinFont& other) :
    handle(other.handle),
    faceName(other.faceName),
    width(other.width),
    height(other.height),
    weight(other.weight),
    style(other.style),
    quality(other.quality) {
}

String WinFont::getWeightName() const {
    if (Resources::hasConstant("FontWeight", weight)) {
        return Resources::getConstant("FontWeight", weight);
    }
    else {
        return "";
    }
}

String WinFont::getQualityName() const {
    return Resources::getConstant("FontQuality", quality);
}

String WinFont::getStyleString() const {
    String s;

    if (!style) return "normal";
    if (style & 0x01) {
        if (!s.isEmpty()) s += ", ";
        s += "italic";
    }
    if (style & 0x02) {
        if (!s.isEmpty()) s += ", ";
        s += "underline";
    }
    if (style & 0x04) {
        if (!s.isEmpty()) s += ", ";
        s += "strike-out";
    }
    return s;
}

/*--------------------------------------------------------------------------+
| Writes an XML representation of this object to the given stream.          |
+--------------------------------------------------------------------------*/
void WinFont::toXmlStream(QXmlStreamWriter& stream) const {
    stream.writeStartElement("font");
     if (handle) {
         stream.writeTextElement("handle", hexString((uint)handle));
         stream.writeTextElement("faceName", stringLabel(faceName));

         stream.writeStartElement("weight");
         stream.writeAttribute("name", stringLabel(getWeightName()));
         stream.writeAttribute("value", stringLabel(weight));
         stream.writeEndElement();

         stream.writeStartElement("quality");
         stream.writeAttribute("name", stringLabel(getQualityName()));
         stream.writeAttribute("value", stringLabel(quality));
         stream.writeEndElement();

         stream.writeTextElement("width", stringLabel(width));
         stream.writeTextElement("height", stringLabel(height));
         stream.writeTextElement("style", stringLabel(getStyleString()));
     }
     else {
         stream.writeCharacters("none");
     }
    stream.writeEndElement();
}


/***************************/
/*** WinScrollInfo class ***/
/***************************/

/*--------------------------------------------------------------------------+
| Constructor.                                                              |
+--------------------------------------------------------------------------*/
WinScrollInfo::WinScrollInfo(const SCROLLINFO& info) :
    minPos(info.nMin),
    maxPos(info.nMax),
    currentPos(info.nPos),
    page(info.nPage) {
}

/*--------------------------------------------------------------------------+
| Copy Constructor.                                                         |
+--------------------------------------------------------------------------*/
WinScrollInfo::WinScrollInfo(const WinScrollInfo& other) :
    minPos(other.minPos),
    maxPos(other.maxPos),
    currentPos(other.currentPos),
    page(other.page) {
}

/*--------------------------------------------------------------------------+
| Writes an XML representation of this object to the given stream.          |
+--------------------------------------------------------------------------*/
void WinScrollInfo::toXmlStream(QXmlStreamWriter& stream) const {
    stream.writeStartElement("scrollInfo");
     stream.writeTextElement("minPos", stringLabel(minPos));
     stream.writeTextElement("maxPos", stringLabel(maxPos));
     stream.writeTextElement("currentPos", stringLabel(currentPos));
     stream.writeTextElement("page", stringLabel(page));
    stream.writeEndElement();
}
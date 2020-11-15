//////////////////////////////////////////////////////////////////////////
// File: StatusBar.cpp                                                  //
// Date: 2011-08-04                                                     //
// Desc: Object that represents a Status Bar control.                   //
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
#include "ui/property_pages/StatusBarPropertyPage.h"
#include "window_detective/StringFormatter.h"
#include "window_detective/QtHelpers.h"


/***************************/
/*** StatusBarPart class ***/
/***************************/

StatusBarPart::StatusBarPart(const StatusBarPartStruct& itemStruct) {
    this->text = wCharToString(itemStruct.text);
    this->boundingRect = QRectFromRECT(itemStruct.rect);
}


/***********************/
/*** StatusBar class ***/
/***********************/

/*--------------------------------------------------------------------------+
| Constructor.                                                              |
+--------------------------------------------------------------------------*/
StatusBar::StatusBar(HWND handle, WindowClass* wndClass) :
    Window(handle, wndClass),
    parts(),
    horzBorder(-1), vertBorder(-1),
    padding(-1),
    getRemoteInfoFlag(true) {
}

/*--------------------------------------------------------------------------+
| Returns true if the owner application is responsible for drawing          |
| it's contents. In this case, we cannot get it's text.                     |
+--------------------------------------------------------------------------*/
bool StatusBar::isOwnerDrawn() {
    return hasStyleBits(SBT_OWNERDRAW);
}

/*--------------------------------------------------------------------------+
| Returns the number of parts in the status bar.                            |
+--------------------------------------------------------------------------*/
uint StatusBar::getNumberOfParts() {
    return sendMessage<uint,int,int>(SB_GETPARTS, 0, 0);
}

/*--------------------------------------------------------------------------+
| <<REMOTE>> Calls the function in the remote process to get info.          |
+--------------------------------------------------------------------------*/
void StatusBar::getRemoteInfo() {
    // Set up struct to be passed to remote thread
    StatusBarInfoStruct itemStruct;
    ZeroMemory(&itemStruct, sizeof(StatusBarInfoStruct));
    itemStruct.handle = this->getHandle();
    itemStruct.totalNumber = this->getNumberOfParts();

    // Call the remote function in our hook DLL.
    DWORD result = CallRemoteFunction(handle, "GetStatusBarInfoRemote",
                              &itemStruct, sizeof(StatusBarInfoStruct));

    if (result == S_OK) {
        parts.clear();
        for (uint i = 0; i < itemStruct.numberRetrieved; ++i) {
            parts.append(StatusBarPart(itemStruct.items[i]));
        }
        if (itemStruct.numberRetrieved < itemStruct.totalNumber) {
            Logger::warning(TR("Window Detective can only get a maximum of %1 items for %2")
                               .arg(itemStruct.numberRetrieved)
                               .arg(getDisplayName()));
        }
        horzBorder = itemStruct.horzBorder;
        vertBorder = itemStruct.vertBorder;
        padding = itemStruct.padding;
    }
    else {
        String errorStr = TR("Could not get some status bar parts for %1").arg(getDisplayName());
        if (result == -1) {   // unknown error occurred
            Logger::warning(errorStr);
        }
        else {
            Logger::osWarning(result, errorStr);
        }
    }
}

/*--------------------------------------------------------------------------+
| Creates and returns a list of property pages for this object.             |
| Note: The UI window takes ownership of these wigdets.                     |
+--------------------------------------------------------------------------*/
QList<AbstractPropertyPage*> StatusBar::makePropertyPages() {
    return Window::makePropertyPages() << new StatusBarPropertyPage(this);
}

/*--------------------------------------------------------------------------+
| Writes an XML representation of this object to the given stream.          |
+--------------------------------------------------------------------------*/
void StatusBar::writeContents(QXmlStreamWriter& stream) {
    Window::writeContents(stream);

    getRemoteInfo();
    stream.writeTextElement("horzBorderWidth", stringLabel(getHorzBorderWidth()));
    stream.writeTextElement("vertBorderWidth", stringLabel(getVertBorderWidth()));
    stream.writeTextElement("paddingWidth", stringLabel(getPaddingWidth()));

    stream.writeStartElement("parts");
    stream.writeAttribute("count", stringLabel(getNumberOfParts()));
     QList<StatusBarPart> parts = getParts();
     QList<StatusBarPart>::const_iterator i;
     for (i = parts.begin(); i != parts.end(); ++i) {
         stream.writeStartElement("part");
         stream.writeAttribute("text", stringLabel((*i).text));
          stream.writeStartElement("boundingRect");
           writeElement(stream, (*i).boundingRect);
          stream.writeEndElement();
         stream.writeEndElement();
     }
    stream.writeEndElement();
}

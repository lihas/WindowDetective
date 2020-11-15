//////////////////////////////////////////////////////////////////////////
// File: Edit.cpp                                                       //
// Date: 2011-01-18                                                     //
// Desc: Object that represents a text edit control.                    //
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
#include "inspector/WindowManager.h"
#include "window_detective/Logger.h"
#include "ui/property_pages/EditPropertyPage.h"
#include "window_detective/StringFormatter.h"


/*--------------------------------------------------------------------------+
| Indicates whether there are any actions in the undo queue.                |
+--------------------------------------------------------------------------*/
bool Edit::canUndo() {
    return sendMessage<bool>(EM_CANUNDO);
}

/*--------------------------------------------------------------------------+
| Indicates whether the text in the control has been modified.              |
+--------------------------------------------------------------------------*/
bool Edit::isModified() {
    return sendMessage<bool>(EM_GETMODIFY);
}

/*--------------------------------------------------------------------------+
| Indicates whether newlines are accepted in the control.                   |
+--------------------------------------------------------------------------*/
bool Edit::isMultiLine() {
    return hasStyleBits(ES_MULTILINE);
}

/*--------------------------------------------------------------------------+
| Returns the starting and ending character positions of the                |
| current selection in the edit control.                                    |
+--------------------------------------------------------------------------*/
QPoint Edit::getSelectionRange() {
    DWORD startPos = 0, endPos = 0;
    sendMessage<int, DWORD*, DWORD*>(EM_GETSEL, &startPos, &endPos);
    return QPoint(startPos, endPos);
}

uint Edit::getNumberOfLines() {
    return sendMessage<uint>(EM_GETLINECOUNT);
}

uint Edit::getMaximumCharacters() {
    return sendMessage<uint>(EM_GETLIMITTEXT);
}

/*--------------------------------------------------------------------------+
| Creates and returns a list of property pages for this object.             |
| Note: The UI window takes ownership of these wigdets.                     |
+--------------------------------------------------------------------------*/
QList<AbstractPropertyPage*> Edit::makePropertyPages() {
    return Window::makePropertyPages() << new EditPropertyPage(this);
}

/*--------------------------------------------------------------------------+
| Writes an XML representation of this object to the given stream.          |
+--------------------------------------------------------------------------*/
void Edit::writeContents(QXmlStreamWriter& stream) {
    Window::writeContents(stream);

    stream.writeTextElement("canUndo", stringLabel(canUndo()));
    stream.writeTextElement("isModified", stringLabel(isModified()));

    QPoint point = getSelectionRange();
    stream.writeStartElement("selectionRange");
    stream.writeAttribute("start", stringLabel(point.x()));
    stream.writeAttribute("end", stringLabel(point.y()));
    stream.writeEndElement();

    stream.writeTextElement("maximumCharacters", stringLabel(getMaximumCharacters()));
    stream.writeTextElement("isMultiLine", stringLabel(isMultiLine()));
    stream.writeTextElement("numberOfLines", stringLabel(getNumberOfLines()));
}

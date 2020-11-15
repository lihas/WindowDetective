///////////////////////////////////////////////////////////////////////////////
// File: ComboBox.cpp                                                        //
// Date: 2011-01-18                                                          //
// Desc: Object that represents a combo box control.                         //
///////////////////////////////////////////////////////////////////////////////

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
#include "ui/property_pages/ComboBoxPropertyPage.h"
#include "window_detective/StringFormatter.h"
#include "window_detective/QtHelpers.h"


/*--------------------------------------------------------------------------+
| Returns true if the owner application is responsible for drawing it's     |
| contents. See also ComboBox::hasStrings.                                  |
+--------------------------------------------------------------------------*/
bool ComboBox::isOwnerDrawn() {
    return hasStyleBits(CBS_OWNERDRAWFIXED) || hasStyleBits(CBS_OWNERDRAWVARIABLE);
}

/*--------------------------------------------------------------------------+
| This is only used if it is owner drawn. Returns true if the combo box     |
| contains items consisting of strings. Otherwise, the control draws it's   |
| own contents, and we cannot get it's text.                                |
+--------------------------------------------------------------------------*/
bool ComboBox::hasStrings() {
    return hasStyleBits(CBS_HASSTRINGS);
}

/*--------------------------------------------------------------------------+
| Return the number of items in the combo box list.                         |
+--------------------------------------------------------------------------*/
uint ComboBox::getNumberOfItems() {
    return sendMessage<uint>(CB_GETCOUNT);
}

/*--------------------------------------------------------------------------+
| Returns the index of the currently selected item.                         |
+--------------------------------------------------------------------------*/
uint ComboBox::getSelectedIndex() {
    return sendMessage<uint>(CB_GETCURSEL);
}

/*--------------------------------------------------------------------------+
| Return the list of strings kept in this control.                          |
| Note: See ComboBox::hasStrings.                                           |
+--------------------------------------------------------------------------*/
QList<String> ComboBox::getItems() {
    if (items.isEmpty()) {
        bool isError = false;
        uint errorId = 0;
        WCHAR* buffer = NULL;    // Buffer for each item's text.
        int maxLength = 0;       // Used to determine size of buffer
        bool hasStrings = this->hasStrings();

        for (uint i = 0; i < getNumberOfItems(); ++i) {
            int length = sendMessage<int,int,int>(CB_GETLBTEXTLEN, i, NULL) + 1; // +1 for null terminator

            // Optimization: Expanding memory only when needed rather than
            // allocating and destroying separate memory for each string.
            if (length > maxLength) {
                if (buffer) delete[] buffer;
                buffer = new WCHAR[length];
                maxLength = length;
            }

            length = sendMessage<int,int,LPWSTR>(CB_GETLBTEXT, i, buffer);
            if (length != LB_ERR) {
                if (hasStrings) {
                    items.append(wCharToString(buffer, length));
                }
                else {
                    // The string will just be the byte array in hex
                    String str;
                    QTextStream stream(&str);
                    // In this case the buffer size is always the size, in bytes, of a DWORD.
                    // But we will also check the buffer's length just to be sure
                    for (uint i = 0; i < sizeof(DWORD) && i < length * sizeof(WCHAR); ++i) {
                        stream << String::number((uint)((byte*)buffer)[i], 16).toUpper()
                               << " ";
                    }
                    items.append(str);
                }
            }
            else {
                isError = true;
                errorId = GetLastError();
            }
        }
        if (buffer) delete[] buffer;

        // If there are any errors, wait until the end to report them
        if (isError) {
            Logger::osWarning(errorId, "Could not get some items from "+getDisplayName());
        }
    }
    return items;
}

/*--------------------------------------------------------------------------+
| Creates and returns a list of property pages for this object.             |
| Note: The UI window takes ownership of these wigdets.                     |
+--------------------------------------------------------------------------*/
QList<AbstractPropertyPage*> ComboBox::makePropertyPages() {
    return Window::makePropertyPages() << new ComboBoxPropertyPage(this);
}

/*--------------------------------------------------------------------------+
| Writes an XML representation of this object to the given stream.          |
+--------------------------------------------------------------------------*/
void ComboBox::writeContents(QXmlStreamWriter& stream) {
    Window::writeContents(stream);

    stream.writeTextElement("selectedIndex", stringLabel(getSelectedIndex()));

    stream.writeStartElement("items");
    stream.writeAttribute("count", stringLabel(getNumberOfItems()));
     QList<String> list = getItems();
     QList<String>::const_iterator i;
     for (i = list.begin(); i != list.end(); ++i) {
         stream.writeTextElement("item", *i);
     }
    stream.writeEndElement();
}

//////////////////////////////////////////////////////////////////////////
// File: ListBox.cpp                                                    //
// Date: 2011-01-18                                                     //
// Desc: Object that represents a list box control.                     //
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
#include "ui/property_pages/ListBoxPropertyPage.h"
#include "window_detective/StringFormatter.h"
#include "window_detective/QtHelpers.h"


/*--------------------------------------------------------------------------+
| Constructor - pretty basic.                                               |
+--------------------------------------------------------------------------*/
ListBox::ListBox(HWND handle, WindowClass* wndClass) :
    Window(handle, wndClass), items() {
}

/*--------------------------------------------------------------------------+
| Returns true if the owner application is responsible for drawing          |
| it's contents. See also ListBox::hasStrings.                              |
+--------------------------------------------------------------------------*/
bool ListBox::isOwnerDrawn() {
    return hasStyleBits(LBS_OWNERDRAWFIXED) || hasStyleBits(LBS_OWNERDRAWVARIABLE);
}

/*--------------------------------------------------------------------------+
| This is only used if it is owner drawn. Returns true if the list box      |
| contains items consisting of strings. Otherwise, the control draws it's   |
| own contents, and we cannot get it's text.                                |
+--------------------------------------------------------------------------*/
bool ListBox::hasStrings() {
    return hasStyleBits(LBS_HASSTRINGS);
}

/*--------------------------------------------------------------------------+
| Return the number of items in the list.                                   |
+--------------------------------------------------------------------------*/
uint ListBox::getNumberOfItems() {
    return sendMessage<uint>(LB_GETCOUNT);
}

/*--------------------------------------------------------------------------+
| Returns the number of selected items.                                     |
+--------------------------------------------------------------------------*/
uint ListBox::getNumberOfSelectedItems() {
    // If the listbox is multiple-selection, the first message will return
    // the number. Otherwise, the second message will return the index
    // of the selected item.
    uint count = sendMessage<uint>(LB_GETSELCOUNT);
    if (count == LB_ERR) count = sendMessage<uint>(LB_GETCURSEL);
    if (count == LB_ERR) count = 0; else count = 1;
    return count;
}

/*--------------------------------------------------------------------------+
| Return the list of strings kept in this control.                          |
| If ListBox::hasStrings is false, the list will contain integer            |
| values used by the owner-drawing routine.                                 |
+--------------------------------------------------------------------------*/
const QList<ListBoxItem>& ListBox::getItems() {
    if (items.isEmpty()) {
        uint errorId = 0;
        bool hasStrings = this->hasStrings();
        WCHAR* buffer = NULL;    // Buffer for each item's text.
        int maxLength = 0;       // Used to determine size of buffer
        ListBoxItem tempItem;

        for (uint i = 0; i < getNumberOfItems(); ++i) {
            int length = sendMessage<int,int,int>(LB_GETTEXTLEN, i, NULL) + 1; // +1 for null terminator

            // Optimization: Expanding memory only when needed rather than
            // allocating and destroying separate memory for each string.
            if (length > maxLength) {
                if (buffer) delete[] buffer;
                buffer = new WCHAR[length];
                maxLength = length;
            }

            length = sendMessage<int,int,LPWSTR>(LB_GETTEXT, i, buffer);
            if (length != LB_ERR) {
                tempItem.isSelected = (sendMessage<int,int,LPWSTR>(LB_GETSEL, i, NULL)) > 0;
                if (hasStrings) {
                    tempItem.text = wCharToString(buffer, length);
                }
                else {
                    // The string will just be the byte array in hex
                    String str;
                    QTextStream stream(&str);
                    for (uint i = 0; i < sizeof(DWORD); ++i) {
                        stream << String::number((uint)((byte*)buffer)[i], 16).toUpper()
                               << " ";
                    }
                    tempItem.text = str;
                }
                items.append(tempItem);
            }
            else {
                errorId = GetLastError();
            }
        }
        if (buffer) delete[] buffer;

        // If there are any errors, wait until the end to report them
        if (errorId != 0) {
            Logger::osWarning(errorId, "Could not get some items from "+getDisplayName());
        }
    }
    return items;
}

/*--------------------------------------------------------------------------+
| Creates and returns a list of property pages for this object.             |
| Note: The UI window takes ownership of these wigdets.                     |
+--------------------------------------------------------------------------*/
QList<AbstractPropertyPage*> ListBox::makePropertyPages() {
    return Window::makePropertyPages() << new ListBoxPropertyPage(this);
}

/*--------------------------------------------------------------------------+
| Writes an XML representation of this object to the given stream.          |
+--------------------------------------------------------------------------*/
void ListBox::writeContents(QXmlStreamWriter& stream) {
    Window::writeContents(stream);

    stream.writeStartElement("items");
    stream.writeAttribute("count", stringLabel(getNumberOfItems()));
     QList<ListBoxItem> list = getItems();
     QList<ListBoxItem>::const_iterator i;
     for (i = list.begin(); i != list.end(); ++i) {
         stream.writeEmptyElement("item");
         stream.writeAttribute("text", stringLabel((*i).text));
         stream.writeAttribute("isSelected", stringLabel((*i).isSelected));
     }
    stream.writeEndElement();
}

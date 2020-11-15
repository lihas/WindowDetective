//////////////////////////////////////////////////////////////////////////
// File: Tab.cpp                                                        //
// Date: 2011-08-02                                                     //
// Desc: Object that represents a tab control.                          //
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
#include "ui/property_pages/TabPropertyPage.h"
#include "window_detective/StringFormatter.h"
#include "window_detective/QtHelpers.h"


/*********************/
/*** TabItem class ***/
/*********************/

TabItem::TabItem(const TabItemStruct& itemStruct) {
    this->text = wCharToString(itemStruct.text);
    this->imageIndex = itemStruct.imageIndex;
    this->lParam = itemStruct.lParam;
}


/*****************/
/*** Tab class ***/
/*****************/

/*--------------------------------------------------------------------------+
| Constructor.                                                              |
+--------------------------------------------------------------------------*/
Tab::Tab(HWND handle, WindowClass* wndClass) :
    Window(handle, wndClass), items() {
}

/*--------------------------------------------------------------------------+
| Returns the total number of tab items.                                    |
+--------------------------------------------------------------------------*/
uint Tab::getNumberOfItems() {
    return sendMessage<uint>(TCM_GETITEMCOUNT);
}

/*--------------------------------------------------------------------------+
| Returns the index of the item that has the focus. This may be             |
| different than the selected item.                                         |
+--------------------------------------------------------------------------*/
uint Tab::getFocusIndex() {
    return sendMessage<uint>(TCM_GETCURFOCUS);
}

/*--------------------------------------------------------------------------+
| Returns the index of the currently selected item.                         |
+--------------------------------------------------------------------------*/
uint Tab::getSelectedIndex() {
    return sendMessage<uint>(TCM_GETCURSEL);
}

/*--------------------------------------------------------------------------+
| Returns a list of tab items.                                              |
| <<REMOTE>> Sending TCM_GETITEM must be done from remote process.          |
+--------------------------------------------------------------------------*/
const QList<TabItem>& Tab::getItems() {
    if (items.isEmpty()) {
        // Set up struct to be passed to remote thread
        TabItemsStruct itemStruct;
        ZeroMemory(&itemStruct, sizeof(TabItemsStruct));
        itemStruct.handle = this->getHandle();
        itemStruct.totalNumber = this->getNumberOfItems();

        // Call the remote function in our hook DLL.
        DWORD result = CallRemoteFunction(handle, "GetTabItemsRemote",
                                  &itemStruct, sizeof(TabItemsStruct));

        if (result == S_OK) {
            for (uint i = 0; i < itemStruct.numberRetrieved; ++i) {
                items.append(TabItem(itemStruct.items[i]));
            }
            if (itemStruct.numberRetrieved < itemStruct.totalNumber) {
                Logger::warning(TR("Window Detective can only get a maximum of %1 items for %2")
                                   .arg(itemStruct.numberRetrieved)
                                   .arg(getDisplayName()));
            }
        }
        else {
            String errorStr = TR("Could not get some tab items for %1").arg(getDisplayName());
            if (result == -1) {   // unknown error occurred
                Logger::warning(errorStr);
            }
            else {
                Logger::osWarning(result, errorStr);
            }
        }
    }
    return items;
}

/*--------------------------------------------------------------------------+
| Creates and returns a list of property pages for this object.             |
| Note: The UI window takes ownership of these wigdets.                     |
+--------------------------------------------------------------------------*/
QList<AbstractPropertyPage*> Tab::makePropertyPages() {
    return Window::makePropertyPages() << new TabPropertyPage(this);
}

/*--------------------------------------------------------------------------+
| Writes an XML representation of this object to the given stream.          |
+--------------------------------------------------------------------------*/
void Tab::writeContents(QXmlStreamWriter& stream) {
    Window::writeContents(stream);

    stream.writeTextElement("focusIndex", stringLabel(getFocusIndex()));
    stream.writeTextElement("selectedIndex", stringLabel(getSelectedIndex()));

    stream.writeStartElement("items");
    stream.writeAttribute("count", stringLabel(getNumberOfItems()));
     QList<TabItem> list = getItems();
     QList<TabItem>::const_iterator i;
     for (i = list.begin(); i != list.end(); ++i) {
         stream.writeEmptyElement("item");
         stream.writeAttribute("text", stringLabel((*i).text));
         stream.writeAttribute("imageIndex", stringLabel((*i).imageIndex));
         stream.writeAttribute("lParam", stringLabel((*i).lParam));
     }
    stream.writeEndElement();
}

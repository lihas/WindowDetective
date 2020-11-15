//////////////////////////////////////////////////////////////////////////
// File: DateTimePicker.cpp                                             //
// Date: 2011-06-10                                                     //
// Desc: Object that represents a date and time picker control.         //
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
#include "ui/property_pages/DateTimePickerPropertyPage.h"
#include "window_detective/StringFormatter.h"
#include "window_detective/QtHelpers.h"


/*--------------------------------------------------------------------------+
| Constructor.                                                              |
+--------------------------------------------------------------------------*/
DateTimePicker::DateTimePicker(HWND handle, WindowClass* wndClass) :
    Window(handle, wndClass),
    selectedDateTime(),
    minDateTime(), maxDateTime() {
}

/*--------------------------------------------------------------------------+
| Returns the size needed to display the control without clipping.          |
| Only available in Vista and above.                                        |
+--------------------------------------------------------------------------*/
QSize DateTimePicker::getIdealSize() {
    SIZE sizeStruct = {0, 0};
    if (sendMessage<bool,int,SIZE*>(DTM_GETIDEALSIZE, NULL, &sizeStruct)) {
        return QSize(sizeStruct.cx, sizeStruct.cy);
    }
    else {
        return QSize();   // Invalid size
    }
}

/*--------------------------------------------------------------------------+
| <<REMOTE>> Calls the function in the remote process to get info.          |
+--------------------------------------------------------------------------*/
void DateTimePicker::getRemoteInfo() {
    // Set up struct to be passed to remote thread
    DateTimeInfoStruct infoStruct;
    ZeroMemory(&infoStruct, sizeof(DateTimeInfoStruct));
    infoStruct.handle = this->getHandle();

    // Call the remote function in our hook DLL.
    DWORD result = CallRemoteFunction(handle, "GetDateTimeInfoRemote",
                              &infoStruct, sizeof(DateTimeInfoStruct));
    if (result == S_OK) {
        if (infoStruct.selectedTimeStatus == GDT_VALID) {
            selectedDateTime = QDateTimeFromSYSTEMTIME(infoStruct.selectedTime);
        }
        else if (infoStruct.selectedTimeStatus == GDT_NONE) {
            selectedDateTime = QDateTime();
        }
        else {
            Logger::error(TR("Unknown error getting selected time for %1").arg(getDisplayName()));
        }

        minDateTime = ((infoStruct.range & GDTR_MIN) == GDTR_MIN) ?
                        QDateTimeFromSYSTEMTIME(infoStruct.minTime) : QDateTime();
        maxDateTime = ((infoStruct.range & GDTR_MAX) == GDTR_MAX) ?
                        QDateTimeFromSYSTEMTIME(infoStruct.maxTime) : QDateTime();
    }
    else {
        String errorStr = TR("Could not get extended info for %1").arg(getDisplayName());
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
QList<AbstractPropertyPage*> DateTimePicker::makePropertyPages() {
    return Window::makePropertyPages() << new DateTimePickerPropertyPage(this);
}

/*--------------------------------------------------------------------------+
| Writes an XML representation of this object to the given stream.          |
+--------------------------------------------------------------------------*/
void DateTimePicker::writeContents(QXmlStreamWriter& stream) {
    Window::writeContents(stream);

    getRemoteInfo();
    stream.writeStartElement("selectedDateTime");
    if (!selectedDateTime.isNull()) {
        writeElement(stream, selectedDateTime);
    }
    stream.writeEndElement();

    stream.writeStartElement("minDateTime");
    if (!minDateTime.isNull()) {
        writeElement(stream, minDateTime);
    }
    stream.writeEndElement();

    stream.writeStartElement("maxDateTime");
    if (!maxDateTime.isNull()) {
        writeElement(stream, maxDateTime);
    }
    stream.writeEndElement();

    if (getOSVersion() >= 600) {
        stream.writeStartElement("idealSize");
         writeElement(stream, getIdealSize());
        stream.writeEndElement();
    }
}

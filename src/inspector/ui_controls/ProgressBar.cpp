//////////////////////////////////////////////////////////////////////////
// File: ProgressBar.cpp                                                //
// Date: 2011-08-01                                                     //
// Desc: Object that represents a progress bar.                         //
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
#include "ui/property_pages/ProgressBarPropertyPage.h"
#include "window_detective/StringFormatter.h"


/*--------------------------------------------------------------------------+
| Returns the current position of the progress bar.                         |
+--------------------------------------------------------------------------*/
uint ProgressBar::getCurrentPosition() {
    return sendMessage<uint>(PBM_GETPOS);
}

/*--------------------------------------------------------------------------+
| Returns the step increment of the progress bar.                           |
| The step increment is the amount by which the progress bar increases its  |
| current position whenever it receives a PBM_STEPIT message.               |
| By default, the step increment is set to 10.                              |
+--------------------------------------------------------------------------*/
uint ProgressBar::getStepIncrement() {
    return sendMessage<uint>(PBM_GETSTEP);
}

/*--------------------------------------------------------------------------+
| Returns the low limit of the progress bar.                                |
+--------------------------------------------------------------------------*/
uint ProgressBar::getMinimum() {
    return sendMessage<uint, int, int>(PBM_GETRANGE, 1, NULL);
}

/*--------------------------------------------------------------------------+
| Returns the high limit of the progress bar.                               |
+--------------------------------------------------------------------------*/
uint ProgressBar::getMaximum() {
    return sendMessage<uint, int, int>(PBM_GETRANGE, 0, NULL);
}

/*--------------------------------------------------------------------------+
| Returns the state the progress bar.                                       |
| Only available in Vista and above.                                        |
+--------------------------------------------------------------------------*/
uint ProgressBar::getState() {
    return sendMessage<uint>(PBM_GETSTATE);
}

/*--------------------------------------------------------------------------+
| Creates and returns a list of property pages for this object.             |
| Note: The UI window takes ownership of these wigdets.                     |
+--------------------------------------------------------------------------*/
QList<AbstractPropertyPage*> ProgressBar::makePropertyPages() {
    return Window::makePropertyPages() << new ProgressBarPropertyPage(this);
}

/*--------------------------------------------------------------------------+
| Writes an XML representation of this object to the given stream.          |
+--------------------------------------------------------------------------*/
void ProgressBar::writeContents(QXmlStreamWriter& stream) {
    Window::writeContents(stream);

    stream.writeTextElement("currentPosition", stringLabel(getCurrentPosition()));
    stream.writeTextElement("stepIncrement", stringLabel(getStepIncrement()));
    stream.writeTextElement("minimum", stringLabel(getMinimum()));
    stream.writeTextElement("maximum", stringLabel(getMaximum()));
    if (getOSVersion() >= 600) {
        stream.writeTextElement("state", stringLabel(getState()));
    }
}

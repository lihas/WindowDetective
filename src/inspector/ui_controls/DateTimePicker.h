//////////////////////////////////////////////////////////////////////////
// File: DateTimePicker.h                                               //
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

#ifndef DATE_TIME_PICKER_H
#define DATE_TIME_PICKER_H


class DateTimePicker : public Window {
private:
    QDateTime selectedDateTime;
    QDateTime minDateTime, maxDateTime;

public:
    DateTimePicker(HWND handle, WindowClass* wndClass);
    ~DateTimePicker() {}

    void getRemoteInfo();
    QDateTime getSelected() { return selectedDateTime; }
    QDateTime getMinimum() { return minDateTime; }
    QDateTime getMaximum() { return maxDateTime; }
    QSize getIdealSize();   // Only available in Vista and above

    QList<AbstractPropertyPage*> makePropertyPages();
    void writeContents(QXmlStreamWriter& stream);
};


#endif  // DATE_TIME_PICKER_H
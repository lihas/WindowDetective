//////////////////////////////////////////////////////////////////////////
// File: ProgressBar.h                                                  //
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

#ifndef PROGRESS_BAR_H
#define PROGRESS_BAR_H


class ProgressBar : public Window {
public:
    ProgressBar(HWND handle, WindowClass* wndClass) :
        Window(handle, wndClass) {}

    uint getCurrentPosition();
    uint getStepIncrement();
    uint getMinimum();
    uint getMaximum();
    uint getState();

    QList<AbstractPropertyPage*> makePropertyPages();
    void writeContents(QXmlStreamWriter& stream);
};


#endif  // PROGRESS_BAR_H
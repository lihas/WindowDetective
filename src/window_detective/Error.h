//////////////////////////////////////////////////////////////////////////
// File: Error.h                                                        //
// Date: 2010-04-01                                                     //
// Desc: Defines base Error class to store an error message and         //
//   the type of error (i.e. the class name).                           //
//   Subclasses can be defined for specific errors.                     //
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

#ifndef ERROR_H
#define ERROR_H

class Error {
protected:
    String message; // Error message
    String type;    // Class type
public:
    Error(String type = "Error", String msg = "")
        : type(type), message(msg) {}

    inline String getType() const { return type; }
    inline String getMsg() const { return message; }
    inline String getMsgStr() const { return type + ": " + message; }
};

#endif   // ERROR_H
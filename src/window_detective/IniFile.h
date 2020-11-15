//////////////////////////////////////////////////////////////////////////
// File: IniFile.h                                                      //
// Date: 2010-07-05                                                     //
// Desc: Provides functionality to read INI files. The INI files used   //
//   by this application are composed of group headers and lines of     //
//   comma-separated values. Groups are specified using square brackets //
//   in the same way as ordinary ini files.                             //
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

#ifndef INI_FILE_H
#define INI_FILE_H

#include "window_detective/include.h"

class IniFile {
private:
    String fileName;
    QStringList lines;
    int currentLine;
    String groupName;

public:
    IniFile(String fileName);

    String getFileName() { return fileName; }
    bool selectGroup(String name);
    void selectNextEntry();
    void selectNextInGroup();
    bool isAtEnd();
    bool isEndOfGroup();
    String currentGroup() { return groupName; }
    String getCurrentLine() { return lines[currentLine]; }
    QStringList parseLine();
};

#endif   // INI_FILE_H
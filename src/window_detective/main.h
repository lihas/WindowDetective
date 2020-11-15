///////////////////////////////////////////////////////////////////////////////
////////                                                                     //
//     _       _   _             __                                          //
//    | |     / / (_) ____  ____/ /____  _      __                           //
//    | | /| / / / / / __ \/ __  // __ \| | /| / /                           //
//    | |/ |/ / / / / / / / /_/ // /_/ /| |/ |/ /                            //
//    |__/|__/ /_/ /_/ /_/\__,_/ \____/ |__/|__/                             //
//              ____         __              __    _                         //
//             / __ \ ___ __/ /_ ___  ______/ /_  (_)_   __ ___              //
//            / / / // _ \_  __// _ \/ ___/  __/ / /| | / // _ \             //
//           / /_/ //  __// /_ /  __/ /__ / /_  / / | |/ //  __/             //
//          /_____/ \___/ \__/ \___/\___/ \__/ /_/  |___/ \___/              //
//                                                                           //
//    http://windowdetective.sourceforge.net/                                //
//                                                                     ////////
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

#ifndef MAIN_H
#define MAIN_H

#include "include.h"
#include "inspector/inspector.h"
#include <QtWidgets/QApplication>

// Unique ID for this app. Used to ensure only one instance
#define APP_GUID   L"{7f44ce61-463f-47cf-b282-d66e9fea2e9c}"

// Dynamically load some DLLs with functions specific to an OS version
// TODO: I am currently statically linking Psapi.dll, should i do that as well
//  as dynamically link it?
extern HMODULE KernelLibrary;
extern HMODULE PsApiLibrary;

class WindowDetective : public QApplication {
public:
    WindowDetective(int& argc, char** argv);
    ~WindowDetective();
};

void shutdownApplication();
String appPath();
String userPath();
void loadPickerCursor();
void showPickerCursor();
void restoreCursor();
void setAppStyle();
void loadCssStyle(String fileName, QTextStream& stream);
bool giveProcessDebugPrivilege();

#endif  // MAIN_H

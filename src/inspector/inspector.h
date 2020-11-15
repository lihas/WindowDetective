//////////////////////////////////////////////////////////////////////////
// File: inspector.h                                                    //
// Date: 2010-03-05                                                     //
// Desc: Main header file for Win32 window class definitions            //
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

#ifndef INSPECTOR_H
#define INSPECTOR_H

#include "window_detective/include.h"

// Forward declarations
class Window;
class WindowClass;
class WindowStyle;
class WindowMessage;
class WindowMessageDefn;
class WindowProp;
class WinBrush;
class WinFont;
class Process;

typedef QList<Window*> WindowList;
typedef QList<Process*> ProcessList;
typedef QList<WindowStyle*> WindowStyleList;
typedef QList<WindowProp> WindowPropList;

#include "window_detective/Resources.h"
#include "WindowMisc.h"
#include "WindowMessage.h"
#include "Process.h"
#include "ui_controls/Window.h"

Q_DECLARE_METATYPE(Window)
Q_DECLARE_METATYPE(WindowStyle)
Q_DECLARE_METATYPE(WindowClass)
Q_DECLARE_METATYPE(Process)
Q_DECLARE_METATYPE(Window*)
Q_DECLARE_METATYPE(WindowStyle*)
Q_DECLARE_METATYPE(WindowClass*)
Q_DECLARE_METATYPE(Process*)

#endif   // INSPECTOR_H
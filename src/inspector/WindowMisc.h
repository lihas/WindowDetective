//////////////////////////////////////////////////////////////////////////
// File: WindowMisc.h                                                   //
// Date: 2010-02-14                                                     //
// Desc: Miscellaneous window related class definitions                 //
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

#ifndef WINDOW_MISC_H
#define WINDOW_MISC_H

#include <QtGui/QIcon>
#include "hook/Hook.h"


/*--------------------------------------------------------------------------+
| Represents a type of window or control, e.g. Button, Static, etc          |
+--------------------------------------------------------------------------*/
class WindowClass {
protected:
    String name;                      // Name of the window class.
    ATOM id;                          // Value that uniquely identifies the window class.
    String friendlyName;              // The "user-friendly" name (for system classes).
    bool native;                      // Native system control or subclassed.
    QIcon icon;                       // An icon which represents this window type.
    uint styleBits;                   // The conbined bit-flags of each style.
    QStringList styles;               // List of styles applied to this window class.
    uint classExtraBytes;             // Extra memory allocated to class.
    uint windowExtraBytes;            // Extra memory allocated to each window instance.
    WinBrush* backgroundBrush;        // For painting window's background.
    WindowStyleList applicableStyles; // List of window styles that can be used for windows of this class
    QHash<uint,String> windowMessageNames;

public:
    WindowClass() {}
    WindowClass(String name);
    WindowClass(String name, String friendlyName, bool isNative = true);
    WindowClass(const WindowClass& other);
    ~WindowClass();

    String getName() const { return name; }
    ATOM getId() const { return id; }
    String getDisplayName();
    bool isNative() const { return native; }
    const QIcon getIcon() const { return icon; }
    uint getStyleBits() const { return styleBits; }
    QStringList getStyles();
    uint getClassExtraBytes() const { return classExtraBytes; }
    uint getWindowExtraBytes() const { return windowExtraBytes; }
    WinBrush* getBackgroundBrush() const { return backgroundBrush; }
    WindowStyleList getApplicableStyles() const { return applicableStyles; }
    void addApplicableStyle(WindowStyle* s);
    QHash<uint,WindowMessageDefn*> getApplicableMessages() const;

    void setId(ATOM atom) { id = atom; }
    void setStyleBits(uint bits);
    void setClassExtraBytes(uint bytes) { classExtraBytes = bytes; }
    void setWindowExtraBytes(uint bytes) { windowExtraBytes = bytes; }
    void setBackgroundBrush(WinBrush* brush);

    void toXmlStream(QXmlStreamWriter& stream) const;
};


/*--------------------------------------------------------------------------+
| Represents a specific window style flag, used to tell a control what      |
| type it is, how it should behave, and any other style information.        |
+--------------------------------------------------------------------------*/
class WindowStyle {
private:
    String name;             // Name of the style flag as used in the Windows API, e.g. WS_VISIBLE
    DWORD value;             // The value of the flag (should be a power of two)
    bool extended;           // If the style is an extended (WS_EX_*) style
    bool isGeneric;          // True if it applies to any window class
    DWORD depends;           // Only valid if window also includes these styles
    DWORD excludes;          // Only valid if these aren't set on window
    String description;      // Helpful info on this style

public:
    WindowStyle(bool isGeneric = true);
    WindowStyle(const WindowStyle& other);
    ~WindowStyle() {}

    void readFrom(QStringList values);
    String getName() const { return name; }
    String getDisplayName() const { return getName(); }
    QIcon getIcon() const { return QIcon(); }  // For generics to work in CustomComboBoxes.h
    uint getValue() const { return (uint)value; }
    String getDescription() const { return description; }
    bool isExtended() const { return extended; }
    bool isValidFor(WindowClass* windowClass);
};


/*--------------------------------------------------------------------------+
| Represents a window property as used by the Get/SetProp API.              |
+--------------------------------------------------------------------------*/
class WindowProp {
public:
    String name;
    HANDLE data;

    WindowProp(String name, HANDLE data) :
        name(name), data(data) {}

    void toXmlStream(QXmlStreamWriter& stream) const;
};


/*--------------------------------------------------------------------------+
| A Window's GDI brush (HBRUSH/LOGBRUSH)                                    |
+--------------------------------------------------------------------------*/
class WinBrush {
public:
    HBRUSH handle;
    UINT style;
    COLORREF colour;
    int hatchType;

    WinBrush(HBRUSH handle, LOGBRUSH brush);

    String getStyleName() const;
    String getHatchName() const;
    void toXmlStream(QXmlStreamWriter& stream) const;
};


/*--------------------------------------------------------------------------+
| A Window's GDI font (HFONT/LOGFONT)                                       |
+--------------------------------------------------------------------------*/
class WinFont {
public:
    HFONT handle;
    String faceName;
    int width, height;
    byte weight;
    byte style;     // bitfield containing italic, underline, strikeOut
    byte quality;

    WinFont(HFONT handle, LOGFONTW font);
    WinFont(LOGFONTW font);
    WinFont(const WinFont& other);

    String getWeightName() const;
    String getQualityName() const;
    String getStyleString() const;
    void toXmlStream(QXmlStreamWriter& stream) const;
};


/*--------------------------------------------------------------------------+
| ScrollBar information for a window (SCROLLINFO).                          |
+--------------------------------------------------------------------------*/
class WinScrollInfo {
public:
    int minPos, maxPos;
    int currentPos;
    uint page;

    WinScrollInfo(const SCROLLINFO& info);
    WinScrollInfo(const WinScrollInfo& other);

    void toXmlStream(QXmlStreamWriter& stream) const;
};


#endif   // WINDOW_MISC_H
Version 3.5.1         http://windowdetective.sourceforge.net
My improvements of Window Detective.
I have been a long term user of Window Detective.
It is an amazing software but lacks certain features which I want, for eg. x64 support.
The idea is to get all the changes mainlined to aurthor's original repository on sourceforge.

# Update 1 : Upgrading to QT 5.15.1, and VS 2019
QT 5.4  onwards has quite a bit of DPI awareness support.
QT 5.15 is LTS (Long term support version).

Install QT 5.15.1 SDK (https://www.qt.io/download-qt-installer). 
Select "MSVC 2019 32 bit", and "MSVC 2019 64 bit" during installation.
Make sure "QTDIRx64", and "QTDIRx86" environment variables point to the right paths.
Eg.
```
QTDIRx64=C:\qt\5.15.1\msvc2019_64
QTDIRx86=C:\qt\5.15.1\msvc2019
```

Copy the following binaries from "$(QTDIRx64)\bin" to "src\x64\Release"

```
Qt5Core.dll
Qt5Gui.dll
Qt5Network.dll
Qt5Widgets.dll
Qt5Xml.dll
```

Copy "$(QTDIRx64)\plugins\platforms\qwindows.dll" to "src\x64\Release\platforms\qwindows.dll"

Do the same for x86, and debug versions. Note that release versions dont have d at the end of file names, debug versions do have. Eg. Qt5Core.dll, and Qt5Cored.dll.


# Improvements
## 64 bit support
Had to upgrade solution to use Visual Studio 2012 as pre built VS2010 QT (5.1.0) binaries for x64 opengl didn't exist.
They do exist for VS2012, but then there is no pre built QT (5.1.0) x86 VS2012 OpenGL (https://download.qt.io/archive/qt/5.1/5.1.0/).

In the end decided to compile QT with VS2012, and to upgrade Window Detective to use the same VS version.

### Compiling QT 5.1.0 with VS2012
For x64: In "VS2012 x64 Cross Tools Command Prompt" run the following commands.
```
	1. git clone https://code.qt.io/qt/qt5.git
	2. git checkout v5.1.0
	3. edit .gitmodules file. 5.1.0 is an old version, and qtjsbackend no longer exists at the URL stored in .gitmodules. 
    [submodule "qtjsbackend"]
		path = qtjsbackend
		url = https://code.qt.io/cgit/{graveyard}/qtjsbackend.git
	4. perl ./init-repository --no-webkit
	5. ..\qt5\configure -developer-build -opensource -nomake examples -nomake tests -opengl desktop -prefix c:\qt\qtx64_vs2012
	6. Nmake
  7. Nmake install
```
For x86: run the same commands in "VS2012 x86 Native Tools Command Prompt"
```
	1. git clone https://code.qt.io/qt/qt5.git
	2. git checkout v5.1.0
	3. edit .gitmodules file. 5.1.0 is an old version, and qtjsbackend no longer exists at the URL stored in .gitmodules.
    [submodule "qtjsbackend"]
		path = qtjsbackend
		url = https://code.qt.io/cgit/{graveyard}/qtjsbackend.git
	4. perl ./init-repository --no-webkit
	5. ..\qt5\configure -developer-build -opensource -nomake examples -nomake tests -opengl desktop -prefix c:\qt\qtx86_vs2012
	6. Nmake
  7. Nmake install
```

Clone x86, and x64 code in different directories.<br />
After "Nmake install", qt binaries will be installed at the path given to "-prefix" parameter during configure.

Add the following environment variables, so that these binaries are found while compiling.
```
QTDIRx64=C:\Qt\qtx64_vs2012
QTDIRx86=C:\Qt\qtx86_vs2012
```

The binaries are now created in their separate folders (wrt orignal project on sourceforge), so they need access to files and folders present at their original location.

Eg. in "src\x64\Debug" directory, run the following commands. Do the same for other directories.
```
mklink /J data ..\..\..\data
mklink /J help ..\..\..\help
mklink /J styles ..\..\..\styles
mklink /J "user data" "..\..\..\user data"
mklink /J "user styles" "..\..\..\user styles"
mklink icudt51.dll ..\..\..\icudt51.dll
mklink icuin51.dll ..\..\..\icuin51.dll
mklink icuuc51.dll ..\..\..\icuuc51.dll
```

Copy the following binaries. from "c:\qt\qtx64_vs2012\bin" to "src\x64\Debug".
```
Qt5Cored.dll
Qt5Guid.dll
Qt5Networkd.dll
Qt5Widgetsd.dll
Qt5Xmld.dll
```

Do the same for x86, and release versions. Note that release versions dont have d at the end of file names, debug versions do have. Eg. Qt5Core.dll, and Qt5Cored.dll.

### Creating the installer
Note : Only create release version. Debug versions of DLLs provided by MS are not redistributable.
Copy the following file(s).
```
C:\qt\qtx64_vs2012\plugins\platforms\qwindows.dll to setup\QT\x64\platforms\qwindows.dll
C:\qt\qtx86_vs2012\plugins\platforms\qwindows.dll to setup\QT\x86\platforms\qwindows.dll
```

Download inno setup compiler from https://jrsoftware.org/isdl.php
Open setup\SetupScriptRelease.iss in it, and click build.
The installler exe will be created in "setup\Output\Release" as WindowDetectiveSetup.exe.
This will install both x86, and x64 versions on 64 bit OS, and just x86 version on 32 bit OS.

With x64 binary you would be able to see messages sent to 64 bit applications, which is currently not possible with 32 bit binary.
The drawback right now is that a single binary cannot be used for logging messages of both 32 bit, and 64 bit processes.


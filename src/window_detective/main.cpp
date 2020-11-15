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


#include "main.h"
#include "inspector/WindowManager.h"
#include "inspector/MessageHandler.h"
#include "ui/MainWindow.h"
#include "ui/ActionManager.h"
#include "Settings.h"
#include "Logger.h"
#include "QtHelpers.h"
#include <Shlobj.h>


QCursor pickerCursor;
QPalette defaultPalette;   // So we can restore it if need be

HMODULE KernelLibrary = NULL;
HMODULE PsApiLibrary = NULL;

/*--------------------------------------------------------------------------+
| Main application constructor. Initializes other classes, loads            |
| libraries and sets up various settings.                                   |
+--------------------------------------------------------------------------*/
WindowDetective::WindowDetective(int& argc, char** argv) :
    QApplication(argc, argv) {
    KernelLibrary = LoadLibrary(L"Kernel32.dll");
    PsApiLibrary = LoadLibrary(L"Psapi.dll");

    defaultPalette = QApplication::palette();
    setQuitOnLastWindowClosed(false);
    setWindowIcon(QIcon(":/Window Detective.ico"));

    addLibraryPath(appPath());
    setApplicationName(APP_NAME);
    setApplicationVersion(VERSION_STR);

    Settings::initialize();
    Settings::read();
    giveProcessDebugPrivilege();
    InfoPane::buildInfoLabels();
    loadPickerCursor();
    ActionManager::initialize();
    Resources::load(appPath()+"\\data", userPath()+"\\data");
    WindowManager::initialize();
    SearchCriteria::initialize();
    MessageHandler::current().initialize();
    setAppStyle();
}

// Perform any aditional cleanup when the app quits
WindowDetective::~WindowDetective() {
    FreeLibrary(KernelLibrary);
    FreeLibrary(PsApiLibrary);
}

/*--------------------------------------------------------------------------+
| Performs any necessary clean-up and then quits the application.           |
+--------------------------------------------------------------------------*/
void shutdownApplication() {
    MessageHandler::current().shutdown();
    QApplication::quit();
}

/*--------------------------------------------------------------------------+
| Loads the 'picker' cursor from file. If there is an error the system      |
| crosshair cursor will be used instead.                                    |
+--------------------------------------------------------------------------*/
void loadPickerCursor() {
    pickerCursor = QCursor(QPixmap(":/img/cursor.png"), 10, 10);
}

/*--------------------------------------------------------------------------+
| Sets the cursor to the 'target' cursor for picking windows                |
+--------------------------------------------------------------------------*/
void showPickerCursor() {
    QApplication::setOverrideCursor(pickerCursor);
}

void restoreCursor() {
    QApplication::restoreOverrideCursor();
}

/*--------------------------------------------------------------------------+
| Returns the directory path to the application executable.                 |
+--------------------------------------------------------------------------*/
String appPath() {
    static String path = QApplication::applicationDirPath();
    return path;
}

/*--------------------------------------------------------------------------+
| Returns the directory path of the user's application data.                |
| Unfortunately, QDesktopServices only provides the local app data          |
| directory. Have to use Win API to get the other one.                      |
+--------------------------------------------------------------------------*/
String userPath() {
    static String path;
    if (path.isEmpty()) {
        WCHAR buffer[MAX_PATH];

        HRESULT result = SHGetFolderPathW(NULL, CSIDL_APPDATA, NULL, 0, buffer);
        if (FAILED(result)) return "";

        path = wCharToString(buffer) + "\\" + APP_NAME;
    }
    return path;
}

/*--------------------------------------------------------------------------+
| Sets the application UI style using the Application.css style sheet.      |
+--------------------------------------------------------------------------*/
void setAppStyle() {
    String cssString;
    QTextStream stream(&cssString);
    loadCssStyle("Application", stream);
    qApp->setStyleSheet(cssString);
}


/*--------------------------------------------------------------------------+
| Loads the application and user CSS files with the given name, and writes  |
| them on the text stream in a <style> tag.                                 |
| This function should really be in the UI package...                       |
+--------------------------------------------------------------------------*/
void loadCssFile(String fileName, QTextStream& stream) {
    QFile file(fileName);
    if (file.exists() && file.open(QFile::ReadOnly)) {
        stream << file.readAll();
    }
}
void loadCssStyle(String name, QTextStream& stream) {
    loadCssFile(appPath()+"\\styles\\"+name+".css", stream);
    loadCssFile(userPath()+"\\styles\\"+name+".css", stream);
}

DWORD setProcessPrivileges(HANDLE hToken) {
    TOKEN_PRIVILEGES tp;
    TOKEN_PRIVILEGES tpPrev;
    LUID luidDebug;
    DWORD tpSize = sizeof(TOKEN_PRIVILEGES);

    ZeroMemory(&tpPrev, tpSize);

    if (!LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &luidDebug)) {
        return GetLastError();
    }

    // Get current privilege setting
    tp.PrivilegeCount = 1;
    tp.Privileges[0].Luid = luidDebug;
    tp.Privileges[0].Attributes = 0;
    if (!AdjustTokenPrivileges(hToken, FALSE, &tp, sizeof(TOKEN_PRIVILEGES), &tpPrev, &tpSize)) {
        return GetLastError();
    }

    // Set privilege based on previous setting
    tpPrev.PrivilegeCount = 1;
    tpPrev.Privileges[0].Luid = luidDebug;
    tpPrev.Privileges[0].Attributes |= SE_PRIVILEGE_ENABLED;
    if (!AdjustTokenPrivileges(hToken, FALSE, &tpPrev, tpSize, NULL, NULL)) {
        return GetLastError();
    }

    return 0;
}

/*--------------------------------------------------------------------------+
| Attempts to give the current process debug privilege. With debug          |
| privilege we can do more things with injecting code and stuff.            |
+--------------------------------------------------------------------------*/
bool giveProcessDebugPrivilege() {
    HANDLE hToken = NULL;
    DWORD result = 0;

    if (OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken)) {
        result = setProcessPrivileges(hToken);
    }
    else {
        result = GetLastError();
    }

    CloseHandle(hToken);

    if (result == 0) {
        Logger::info(QObject::tr("Successfully gave debug privilege to process"));
        return true;
    }
    else {
        Logger::osError(result, QObject::tr("Could not give debug privilege to process"));
        return false;
    }
}

int main(int argc, char *argv[]) {
    // Ensure only one instance is running. If it's already running,
    // find that window and bring it to the front.
    // TODO: A better way is described at http://www.flounder.com/nomultiples.htm
    // Also see http://doc.qt.nokia.com/solutions/4/qtsingleapplication/qtsingleapplication.html
    // It is exactly what i need and can even notify the other application to bring it's
    // window to the front (although i couldn't get that to work). But it uses the Qt network
    // module and so may be a bit bloated.
    // Download from http://qt.gitorious.org/qt-solutions
    HANDLE mutex = CreateMutexW(0, true, L"WD"APP_GUID);
    if (mutex && GetLastError() == ERROR_ALREADY_EXISTS) {
        CloseHandle(mutex);
        // FIXME: No methods of bringing the window to the top seem to work
        HWND otherWindow = FindWindowW(L"QWidget", L"Window Detective");
        if (otherWindow) {
            FlashWindow(otherWindow, FALSE);
        }
        exit(0);
    }

    // Create the app instance and initialize
    WindowDetective app(argc, argv);

    // If translation file exists, load it
    QTranslator translator;
    QDir dir(appPath(), "*.qm");
    QStringList tsFiles = dir.entryList();
    if (!tsFiles.isEmpty()) {
        translator.load(tsFiles.first(), appPath());
        app.installTranslator(&translator);
    }

    // Create and show the main window
    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
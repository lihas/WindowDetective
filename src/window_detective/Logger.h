//////////////////////////////////////////////////////////////////////////
// File: Logger.h                                                       //
// Date: 2010-03-05                                                     //
// Desc: Provides a mechanism for logging messages and errors.          //
//   Logs can be displayed in the message window of the GUI as well as  //
//   written or streamed to a file.                                     //
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

#ifndef LOGGER_H
#define LOGGER_H

#include "window_detective/include.h"
#include "window_detective/Error.h"

enum LogLevel {
    ErrorLevel = 4,
    WarnLevel  = 3,
    InfoLevel  = 2,
    DebugLevel = 1,
    TraceLevel = 0
};

class Log {
private:
    LogLevel level;
    String message;
    QDateTime timeStamp;

public:
    Log(String message, LogLevel level);
    Log(const Log& copy);

    String levelName();
    LogLevel getLevel() { return level; }
    String getMessage() { return message; }
    QDateTime getTimeStamp() { return timeStamp; }
    QDate getDate() { return timeStamp.date(); }
    QTime getTime() { return timeStamp.time(); }
    void writeTo(QFile* file);
};

/* UI widgets can inherit this to be notified by the Logger */
class LogListener {
public:
    virtual void logAdded(Log* log) = 0;
    virtual void logRemoved(Log* log) = 0;
};

class Logger {
private:
    QList<Log*> logs;            // List of all logs
    int maxLogs;                 // Max number of logs to keep
    QFile* file;                 // File to write to, NULL if none
    LogListener* listener;       // Object that gets notified of changes
public:
    static Logger& current();    // Singleton instance

    // Static functions for convenience
    static void error(String msg)   { current().log(msg, ErrorLevel);}
    static void warning(String msg) { current().log(msg, WarnLevel); }
    static void info(String msg)    { current().log(msg, InfoLevel); }
    static void debug(String msg)   { current().log(msg, DebugLevel);}

    static void error(const Error& e, String msg = "")  { current().log(e, msg, ErrorLevel);  }
    static void warning(const Error& e, String msg = ""){ current().log(e, msg, WarnLevel);   }
    static void info(const Error& e, String msg = "")   { current().log(e, msg, InfoLevel);   }
    static void debug(const Error& e, String msg = "")  { current().log(e, msg, DebugLevel);  }

    static void osError(String msg)   { current().logOSMessage(msg, ErrorLevel);}
    static void osWarning(String msg) { current().logOSMessage(msg, WarnLevel); }
    static void osError(uint errNum, String msg)  {current().logOSMessage(errNum,msg,ErrorLevel);}
    static void osWarning(uint errNum, String msg){current().logOSMessage(errNum,msg,WarnLevel); }

    Logger();
    ~Logger();

    void setListener(LogListener* l) { this->listener = l; }
    void removeListener() { this->listener = NULL; }
    void log(String message, LogLevel level);
    void log(const Error& e, String message, LogLevel level);
    void logOSMessage(String message, LogLevel level);
    void logOSMessage(uint errNum, String message, LogLevel level);

    void setStream(String fileName);
    void startLoggingToFile();
    void stopLoggingToFile();
    void saveLogs(String fileName);
    QList<Log*> getLogs() { return logs; }
    int numLogs() { return logs.size(); }
};

#endif   // LOGGER_H
//////////////////////////////////////////////////////////////////////////
// File: MessageHandler.h                                               //
// Date: 2010-04-21                                                     //
// Desc: Handles messages from other windows, which are detected        //
//   by the hook DLL.                                                   //
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

#include "window_detective/include.h"
#include "MessageHandler.h"
#include "WindowManager.h"
#include "window_detective/Settings.h"
#include "window_detective/Logger.h"
#include "window_detective/StringFormatter.h"
#include <QStringBuilder>


bool MessageHandler::isWindowClassCreated = false;
HWND MessageHandler::hwndReceiver = NULL;

/*--------------------------------------------------------------------------+
| Creates the window class that is used for receiving messages              |
| from the DLL injected into remote processes.                              |
+--------------------------------------------------------------------------*/
void MessageHandler::createWindowClass() {
    if (MessageHandler::isWindowClassCreated)
        return;   // Can only be called once

    WNDCLASS wndclass;
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = (WNDPROC)MessageHandler::wndProc;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hIcon = NULL;
    wndclass.hInstance = GetModuleHandle(NULL);
    wndclass.hCursor = NULL;
    wndclass.hbrBackground = NULL;
    wndclass.lpszMenuName = NULL;
    wndclass.lpszClassName = HANDLER_WINDOW_CLASS_NAME;

    if (RegisterClass(&wndclass)) {
        MessageHandler::isWindowClassCreated = true;
    }
    else {
        Logger::osError(TR("Could not register message handler window. "
                    "Window Detective will not be able to monitor "
                    "messages of other windows."));
    }
}

/*--------------------------------------------------------------------------+
| Window callback procedure for message handler.                            |
| Receives WM_COPYDATA messages from the DLL that is injected into the      |
| remote processes. The data sent is the window message that the remote     |
| window has received.                                                      |
+--------------------------------------------------------------------------*/
LRESULT CALLBACK MessageHandler::wndProc(HWND hwnd, UINT msgId, WPARAM wParam, LPARAM lParam) {
    if (msgId == WM_COPYDATA) {
        COPYDATASTRUCT* dataStruct = (COPYDATASTRUCT*)lParam;
        byte* totalData = (byte*)dataStruct->lpData;

        // The general message data is in the first part of the data passed.
        // Extra data is stored just after that. The pointers to this data
        // (which were copied with the general data) need to be changed to
        // point to the correct place. This data is deleted after this function
        // returns, so anything that uses it should take a copy.
        MessageEvent* msg = (MessageEvent*)totalData;
        byte* extraDataOffset = totalData + sizeof(MessageEvent);
        msg->extraData1 = (msg->dataSize1 > 0) ? (void*)extraDataOffset : NULL;
        msg->extraData2 = (msg->dataSize2 > 0) ? (void*)(extraDataOffset + msg->dataSize1) : NULL;

        MessageHandler::current().processMessage(*msg);
        return TRUE;
    }
    return DefWindowProc(hwnd, msgId, wParam, lParam);
}

/*--------------------------------------------------------------------------+
| Return the singleton instance, instantiating on first use.                |
+--------------------------------------------------------------------------*/
MessageHandler& MessageHandler::current() {
    static MessageHandler instance;
    return instance;
}


/*--------------------------------------------------------------------------+
| Creates the window which will receive messages from the DLL, then         |
| initializes the DLL data and installs the hooks.                          |
+--------------------------------------------------------------------------*/
void MessageHandler::initialize() {
    if (!MessageHandler::isWindowClassCreated)
        createWindowClass();

    hwndReceiver = CreateWindowEx(0, HANDLER_WINDOW_CLASS_NAME,
                L"", 0, 0, 0, 0, 0, NULL, NULL,
                GetModuleHandle(NULL), NULL);
    if (!hwndReceiver) {
        Logger::osError(TR("Could not create message handler window. "
                    "Window Detective will not be able to monitor "
                    "messages of other windows."));
    }
    HookDll::initialize(hwndReceiver, GetCurrentProcessId());
    initializeExtraDataInfo();
    installHook();
}

/*--------------------------------------------------------------------------+
| Should only be called when application quits.                             |
+--------------------------------------------------------------------------*/
void MessageHandler::shutdown() {
    removeHook();
    if (!DestroyWindow(hwndReceiver)) {
        Logger::osWarning(TR("Could not destroy message handler window"));
    }
}

/*--------------------------------------------------------------------------+
| Tell the Hook DLL about the sizes of WinAPI structs, so it knows how much |
| extra data to copy when processing a window message.                      |
+--------------------------------------------------------------------------*/
void addExtraDataInfoForDefns(WCHAR* className, const QHash<uint,WindowMessageDefn*> messageDefns) {
    MessageExtraDataInfo* messages = new MessageExtraDataInfo[messageDefns.size()];
    int index = 0;
    foreach (WindowMessageDefn* messageDefn, messageDefns) {
        StructDefinition* s1 = messageDefn->getStructDefn1();
        StructDefinition* s2 = messageDefn->getStructDefn2();
        if (s1 || s2) {
            messages[index].messageId = (ushort)messageDefn->getId();
            messages[index].extraData1Size = s1 ? s1->getSize() : 0;
            messages[index].extraData2Size = s2 ? s2->getSize() : 0;
            index++;
        }
    }
    if (index > 0) {
        HookDll::addExtraDataInfo(className, messages, index);
    }
    delete[] messages;
}
void MessageHandler::initializeExtraDataInfo() {
    addExtraDataInfoForDefns(NULL, Resources::generalMessageDefns);

    QHash<String, QHash<uint,WindowMessageDefn*>*>::const_iterator i;
    for (i = Resources::classMessageDefns.constBegin(); i != Resources::classMessageDefns.constEnd(); ++i) {
        addExtraDataInfoForDefns((WCHAR*)i.key().utf16(), *(i.value()));
    }
}

/*--------------------------------------------------------------------------+
| Installs a global (system-wide) hook to monitor messages being sent to    |
| and received by windows. The DLL is injected into each process that has   |
| a message queue.                                                          |
+--------------------------------------------------------------------------*/
bool MessageHandler::installHook() {
    // Call DLL to set hook
    DWORD_PTR result = HookDll::install();
    if (!result) {
        Logger::osError(result, TR("Failed to install message hook"));
        return false;
    }

    // The DLL won't be mapped into a remote process until a message is
    // actually sent to (some window of) the hooked thread.
    // So force DLL to inject immediately by sending each window a message
    SendMessageTimeout(HWND_BROADCAST, WM_NULL, 0, 0, SMTO_ABORTIFHUNG, 10, &result);
    return true;
}

bool MessageHandler::removeHook() {
    // Call DLL to remove hook
    DWORD_PTR result = HookDll::remove();
    if (result != S_OK) {
        Logger::osError(result, TR("Failed to remove message hook"));
        return false;
    }

    // As with installing the hook, the DLL won't be unmapped until a
    // window receives a message. If the DLL is not unmapped now, it could
    // stay in the remote process for a while (if it's not processing
    // messages). So we wait a bit longer here to give it more time.
    SendMessageTimeout(HWND_BROADCAST, WM_NULL, 0, 0, SMTO_NORMAL, 100, &result);
    return true;
}

/*--------------------------------------------------------------------------+
| Adds a listener object to the list of listeners. That object will then    |
| get notified whenever there is a new message from the given window.       |
| If the window is NULL, it will be notified of messages from all windows.  |
+--------------------------------------------------------------------------*/
bool MessageHandler::addMessageListener(WindowMessageListener* listener, Window* window) {
    HWND handle = window->getHandle();
    if (!listeners.contains(handle)) {
        listeners.insert(handle, listener);
        if (!HookDll::addWindowToMonitor(handle)) {
            Logger::osError(TR("Could not monitor messages for window %1."
                        "Window Detective can monitor a maximum of %2 windows.")
                        .arg(MAX_WINDOWS)
                        .arg(window->getDisplayName()));
            return false;
        }
    }
    return true;
}

/*--------------------------------------------------------------------------+
| Removes the listener object from the list of listeners. If it is          |
| listening to more than one window, all references will be removed.        |
+--------------------------------------------------------------------------*/
void MessageHandler::removeMessageListener(WindowMessageListener* l) {
    QMap<HWND,WindowMessageListener*>::const_iterator i;
    QList<HWND> keys;

    for (i = listeners.begin(); i != listeners.end(); ++i) {
         if (i.value() == l)
            keys.append(i.key());
    }
    for (int i = 0; i < keys.size(); ++i) {
        listeners.remove(keys[i]);
        HookDll::removeWindowToMonitor(keys[i]);
    }
}

/*--------------------------------------------------------------------------+
| Removes all listeners and stops monitoring their windows.                 |
+--------------------------------------------------------------------------*/
void MessageHandler::removeAllListeners() {
    HookDll::removeAllWindowsToMonitor();
    listeners.clear();
}

/*--------------------------------------------------------------------------+
| Removes all messages for the given window.                                |
+--------------------------------------------------------------------------*/
void MessageHandler::removeMessages(Window* window) {
    if (windowMessages.contains(window->getHandle())) {
        windowMessages[window->getHandle()].clear();
    }
}

/*--------------------------------------------------------------------------+
| Send the message data to our window so it can update itself.              |
| Also notify anyone listening for messages to this window.                 |
+--------------------------------------------------------------------------*/
void MessageHandler::processMessage(const MessageEvent& msg) {
    WindowManager& manager = WindowManager::current();
    if (msg.messageId == WM_CREATE) {
        manager.addWindow(msg.hwnd);
    }
    else if (msg.messageId == WM_DESTROY) {
        manager.removeWindow(msg.hwnd);
    }
    else {
        Window* window = manager.find(msg.hwnd);
        if (!window) {
            Logger::debug(TR("Message %1 from unknown window %2.")
                        .arg(msg.messageId)
                        .arg(hexString((uint)msg.hwnd)));
            return;
        }

        QList<WindowMessage*>& messages = windowMessages[window->getHandle()];

        WindowMessageDefn* defn = Resources::getMessageDefn(msg.messageId, window->getWindowClass());
        WindowMessage* newMessage = new WindowMessage(defn, window, msg);
        window->messageReceived(newMessage);        // Notify the window, so it can update itself
        if ((msg.type & MessageTypeMask) != 0) {    // If it's not just an update
            messages.append(newMessage);            //  then record the message and notify
            // TODO: Use signals and slots for this
            listeners.value(window->getHandle())->messageAdded(newMessage);
        }
        else {
            delete newMessage;                      //  otherwise, we don't need the message anymore
        }
    }
}

/*--------------------------------------------------------------------------+
| Writes the list of messages for the window to an XML file stream.         |
+--------------------------------------------------------------------------*/
void MessageHandler::writeMessagesToXml(Window* window, QXmlStreamWriter& stream) {
    if (!windowMessages.contains(window->getHandle())) return;

    stream.writeComment(TR("\nMessages for window %1\n"
                           "Created by Window Detective\n")
                           .arg(window->getDisplayName()));

    stream.writeStartElement("messageList");
    QList<WindowMessage*>& messages = windowMessages[window->getHandle()];
    QList<WindowMessage*>::const_iterator i;
    for (i = messages.begin(); i != messages.end(); ++i) {
        (*i)->toXmlStream(stream);
    }
    stream.writeEndElement();
}

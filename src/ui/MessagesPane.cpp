/////////////////////////////////////////////////////////////////////
// File: MessagesPane.h                                            //
// Date: 2010-05-03                                                //
// Desc: Used to display the messages of a window. Typically added //
//   to an MDI area as a child window.                             //
/////////////////////////////////////////////////////////////////////

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

#include "MessagesPane.h"
#include "inspector/MessageHandler.h"


MessagesPane::MessagesPane(Window* wnd, QWidget* parent) :
    QMainWindow(parent),
    window(wnd),
    startIcon(":/img/start.png"),
    stopIcon(":/img/stop.png") {
    setupUi(this);
    Q_ASSERT(window != NULL);
    messageWidget->setWindow(window);
    messageWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    actnCapture->setIcon(stopIcon);  // Message capture is started when the window opens
    setWindowTitle(tr("Window Messages - %1").arg(window->getDisplayName()));

    // Set the initial list of message types for filtering
    QList<MessageFilter> allMessages;
    QHash<uint,WindowMessageDefn*>::const_iterator i;
    QHash<uint,WindowMessageDefn*> tempList = Resources::generalMessageDefns;
    for (i = tempList.begin(); i != tempList.end(); ++i) {
        allMessages.append(MessageFilter((*i)->getName(), true));
    }
    tempList = getModel()->getWindowClass()->getApplicableMessages();
    for (i = tempList.begin(); i != tempList.end(); ++i) {
        allMessages.append(MessageFilter((*i)->getName(), true));
    }
    messageWidget->setMessageFilters(allMessages);

    connect(messageWidget, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(showContextMenu(const QPoint&)));
    connect(actnLocate, SIGNAL(triggered()), this, SLOT(locateActionTriggered()));
    connect(actnSave, SIGNAL(triggered()), this, SLOT(saveButtonClicked()));
    connect(actnCapture, SIGNAL(triggered()), this, SLOT(toggleRunState()));
    connect(actnClear, SIGNAL(triggered()), messageWidget, SLOT(clear()));
    connect(actnAutoExpand, SIGNAL(triggered()), this, SLOT(autoExpandButtonClicked()));
    connect(actnFilter, SIGNAL(triggered()), this, SLOT(filterButtonClicked()));
    connect(actnHighlight, SIGNAL(triggered()), this, SLOT(highlightButtonClicked()));
    
    messageWidget->start();
}

/*--------------------------------------------------------------------------+
| Called when a window is deleted. If it's the one this pane is monitoring, |
| then set it to NULL so we don't de-ref an invalid object.                 |
+--------------------------------------------------------------------------*/
void MessagesPane::windowDeleted(Window* wnd) {
    if (wnd == window) {
        window = NULL;
        messageWidget->unsetWindow();
    }
}

/*--------------------------------------------------------------------------+
| Constructs a menu with actions for the given items.                       |
+--------------------------------------------------------------------------*/
//QMenu MessagesPane::makeContextMenu(selected items) {
//     TODO
//}

/*--------------------------------------------------------------------------+
| Displays the context menu for the selected item/s.                        |
+--------------------------------------------------------------------------*/
//void MessagesPane::showContextMenu(const QPoint& /*unused*/) {
//    QMenu menu = makeContextMenu(/*selected items*/);
//    QAction* action = menu.exec(QCursor::pos());
//    if (!action) return;   // User cancelled
//
//    // TODO
//}

/*--------------------------------------------------------------------------+
| Opens the Message Filter dialog, on the given tab, then applies           |
| the changes if the user accepts.                                          |
+--------------------------------------------------------------------------*/
void MessagesPane::openFilterDialog(int tab) {
    MessageFilterDialog filterDialog(this);

    filterDialog.setMessageFilters(messageWidget->getMessageFilters());
    filterDialog.setIncludeOthers(messageWidget->shouldIncludeOthers());
    filterDialog.setHighlightedMessages(messageWidget->getHighlightedMessages());
    filterDialog.setTabIndex(tab);

    if (filterDialog.exec() == QDialog::Accepted) {    
        messageWidget->setMessageFilters(filterDialog.getMessageFilters());
        messageWidget->setIncludeOthers(filterDialog.shouldIncludeOthers());
        messageWidget->setHighlightedMessages(filterDialog.getHighlightedMessages());
    }
}

/*--------------------------------------------------------------------------+
| This just forwards the signal on with the window.                         |
+--------------------------------------------------------------------------*/
void MessagesPane::locateActionTriggered() {
    if (window) emit locateWindow(window);
}

/*--------------------------------------------------------------------------+
| Prompts for a file to save to, and writes as XML to that file.            |
+--------------------------------------------------------------------------*/
void MessagesPane::saveButtonClicked() {
    if (!window) {
        String msg = tr("The window messages cannot be saved because the window does not exist.");
        QMessageBox::warning(this, tr("Cannot Save Window Messages"), msg);
        return;
    }

    String fileName = QFileDialog::getSaveFileName(this, tr("Save Messages"),
                        QDir::homePath(), "XML Files (*.xml);;All Files (*.*)");
    if (fileName.isEmpty()) {
        return;    // User cancelled
    }

    QFile file(fileName);
    if (!file.open(QFile::WriteOnly)) {
        String msg = tr("Could not open file for writing: \"%1\"").arg(fileName);
        QMessageBox::warning(this, tr("Save Window Messages"), msg);
        Logger::error(msg);
        return;
    }

    QXmlStreamWriter stream(&file);
    stream.setAutoFormatting(true);
    stream.setAutoFormattingIndent(4/*spaces*/);
    stream.writeStartDocument();
    MessageHandler::current().writeMessagesToXml(window, stream);
    stream.writeEndDocument();
}

/*--------------------------------------------------------------------------+
| Toggle message capture and set button's icon to match. Note that the icon |
| indicates what the button *will* do, not it's current state. So a stop    |
| icon means capture is currently running, and the button will stop it.     |
+--------------------------------------------------------------------------*/
void MessagesPane::toggleRunState() {
    bool isRunning = messageWidget->isCapturing();
    if (!isRunning) {
        if (messageWidget->start()) {
            actnCapture->setIcon(stopIcon);
        }
    }
    else {
        messageWidget->stop();
        actnCapture->setIcon(startIcon);
    }
}

/*--------------------------------------------------------------------------+
| Sets the message widget to automatically expand new items.                |
+--------------------------------------------------------------------------*/
void MessagesPane::autoExpandButtonClicked() {
    messageWidget->setAutoExpand(actnAutoExpand->isChecked());
}

/*--------------------------------------------------------------------------+
| Opens the message filter dialog on the filter tab..                       |
+--------------------------------------------------------------------------*/
void MessagesPane::filterButtonClicked() {
    openFilterDialog(0);
}

/*--------------------------------------------------------------------------+
| Opens the message filter dialog on the highlight tab.                     |
+--------------------------------------------------------------------------*/
void MessagesPane::highlightButtonClicked() {
    openFilterDialog(1);
}

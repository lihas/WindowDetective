/////////////////////////////////////////////////////////////////////
// File: MessageWidget.cpp                                         //
// Date: 2010-05-03                                                //
// Desc: Widget for displaying a list of messages. Each message is //
//   actually a tree item whos children are the parameters and     //
//   return value.                                                 //
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


#include "MessageWidget.h"

#define AUTO_SCROLL_PADDING   30


MessageWidget::MessageWidget(QWidget *parent) :
    QTreeWidget(parent),
    window(NULL),
    autoExpand(false),
    isRunning(false),
    includeOthers(true),
    messageFilters(),
    highlightedMessages(),
    fMap(), hMap(),
    messageSentIcon(":/img/message_sent.png"),
    messagePostedIcon(":/img/message_posted.png"),
    messageReturnedIcon(":/img/message_returned.png") {
    QStringList labels;
    labels << tr("Name") << tr("Time") << tr(" ");
    setColumnCount(3);
    setHeaderLabels(labels);
    setColumnWidth(2, 25);
    header()->moveSection(0, 2);  // Make the expandable column third
}

MessageWidget::~MessageWidget() {
    stop();
}

bool MessageWidget::start() {
    if (window) {
        isRunning = MessageHandler::current().addMessageListener(this, window);
    }
    else {
        isRunning = false;
    }
    return isRunning;
}

void MessageWidget::stop() {
    MessageHandler::current().removeMessageListener(this);
    isRunning = false;
}

/*--------------------------------------------------------------------------+
| Remove all messages from this list and also from the MessageHandler.      |
+--------------------------------------------------------------------------*/
void MessageWidget::clear() {
    QTreeWidget::clear();
    if (window) MessageHandler::current().removeMessages(window);
}

/*--------------------------------------------------------------------------+
| These functions create tree widget items for each message or struct field |
| (name and data), formatted as a string. Child structs are built           |
| recursively.  Used by the messageAdded function.                          |
+--------------------------------------------------------------------------*/
void addStructField(QTreeWidgetItem* parent, const FieldDefinition& field, byte* data, bool autoExpand) {
    QTreeWidgetItem* item = new QTreeWidgetItem(parent);
    item->setExpanded(autoExpand);
    if (field.getType()->isStruct()) {
        item->setText(0, field.getName());
        StructDefinition* structDefn = static_cast<StructDefinition*>(field.getType());
        for (int i = 0; i < structDefn->numFields(); ++i) {
            const FieldDefinition& subField = structDefn->getField(i);
            byte* subFieldData = data + subField.getOffset();
            addStructField(item, subField, subFieldData, autoExpand);
        }
    }
    else {
        item->setText(0, field.getName() + " = " + field.toString(data));
    }
}
void addStruct(QTreeWidgetItem* parent, const DynamicStruct& ds, bool autoExpand) {
    if (!ds.isNull()) {
        StructDefinition* defn = ds.getDefinition();
        for (int i = 0; i < defn->numFields(); ++i) {
            const FieldDefinition& field = defn->getField(i);
            byte* data = ds.getData() + field.getOffset();
            addStructField(parent, field, data, autoExpand);
        }
    }
}
void addMessageParam(QTreeWidgetItem* parent, WindowMessage* msg, const MessageParameter* param, bool autoExpand) {
    QTreeWidgetItem* paramItem = new QTreeWidgetItem(parent);
    if (param->getType()->isStruct()) {
        paramItem->setExpanded(autoExpand);
        paramItem->setText(0, param->getName());
        if (param->isParam1()) {
            addStruct(paramItem, msg->getExtraData1(), autoExpand);
        }
        else if (param->isParam2()) {
            addStruct(paramItem, msg->getExtraData2(), autoExpand);
        }
    }
    else {
        paramItem->setText(0, param->getName() + " = " + param->toString(msg));
    }
}
void addMessageParams(QTreeWidgetItem* parent, WindowMessage* msg, bool autoExpand) {
    const WindowMessageDefn* defn = msg->getDefinition();
    bool hasReturnParams = false;

    const QList<MessageParameter*> params = (msg->isReturn() ? defn->getOutParams() : defn->getInParams());
    QList<MessageParameter*>::const_iterator i;
    for (i = params.begin(); i != params.end(); ++i) {
        if ((*i)->isReturn()) hasReturnParams = true;
        addMessageParam(parent, msg, *i, autoExpand);
    }

    if (msg->isReturn() && !hasReturnParams) {
        // Most messages will return 0 if they have been processed, so it's not necessary to
        // define a return param for each message. If it isn't explicitly defined, add it now.
        QTreeWidgetItem* resultItem = new QTreeWidgetItem(parent);
        resultItem->setText(0, "return value = " + String::number(msg->getReturnValue()));
    }
}

/*--------------------------------------------------------------------------+
| Called when a new message has been sent to the window. This adds a new    |
| widget item to the list, with the message's data.                         |
+--------------------------------------------------------------------------*/
void MessageWidget::messageAdded(WindowMessage* msg) {
    // Sanity check - we should only receive messages sent to the window we are monitoring
    if (!window) return;
    if (window != msg->getWindow()) {
        Logger::debug(TR("Message sent to wrong window.\n"
                         "message ID = %1, sent to = %2, supposed to go to = %3")
                         .arg(msg->getId())
                         .arg(window->getDisplayName())
                         .arg(msg->getWindow()->getDisplayName()));
        return;
    }

    String msgName = msg->getName();

    // Check if the message should be excluded (filtered).
    if (fMap.contains(msgName)) {
        if (!fMap.value(msgName)) {
            return;
        }
    }
    else if (!includeOthers) {
        return;
    }

    // Get scrollbar position before we add the item
    QScrollBar* sb = verticalScrollBar();
    bool autoScroll = (sb && sb->value() >= sb->maximum()-AUTO_SCROLL_PADDING);

    // Create the tree items and add them to the tree/list
    QTreeWidgetItem* item = new QTreeWidgetItem(this);
    item->setText(1, msg->getTime().toString(" HH:mm:ss.zzz"));
    if (msg->isSent())        { item->setIcon(2, messageSentIcon);    }
    else if (msg->isPosted()) { item->setIcon(2, messagePostedIcon);  }
    else if (msg->isReturn()) { item->setIcon(2, messageReturnedIcon);}
    item->setText(0, msgName + " (" + hexString(msg->getId(), 0) + ")");
    item->setExpanded(autoExpand);

    addMessageParams(item, msg, autoExpand);

    // Highlight text/background if any colours are set
    if (hMap.contains(msgName)) {
        QPair<QColor, QColor> colours = hMap.value(msgName);
        item->setForeground(0, QBrush(colours.first));
        item->setBackground(0, QBrush(colours.second));
    }

    // Auto-scroll if necessary
    if (autoScroll) scrollToBottom();
}

void MessageWidget::messageRemoved(WindowMessage* msg) {
    // TODO
}

/*--------------------------------------------------------------------------+
| Sets the list of message filters. A hash map is used                      |
| internally for faster lookups.                                            |
+--------------------------------------------------------------------------*/
void MessageWidget::setMessageFilters(QList<MessageFilter> list) {
    messageFilters = list;
    fMap.clear();

    QList<MessageFilter>::const_iterator i;
    for (i = list.begin(); i != list.end(); ++i) {
        fMap.insert(i->name, i->include);
    }
}


/*--------------------------------------------------------------------------+
| Sets the list of message highlights. A hash map is used                   |
| internally for faster lookups.                                            |
+--------------------------------------------------------------------------*/
void MessageWidget::setHighlightedMessages(QList<MessageHighlight> list) {
    highlightedMessages = list;
    hMap.clear();

    QList<MessageHighlight>::const_iterator i;
    for (i = list.begin(); i != list.end(); ++i) {
        hMap.insert(i->name, qMakePair(i->foregroundColour, i->backgroundColour));
    }
}

/********************************************************************************
** Form generated from reading UI file 'MessagesPane.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGESPANE_H
#define UI_MESSAGESPANE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "ui/custom_widgets/MessageWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MessagesPane
{
public:
    QAction *actnSave;
    QAction *actnAutoExpand;
    QAction *actnLocate;
    QAction *actnFilter;
    QAction *actnHighlight;
    QAction *actnCapture;
    QAction *actnClear;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    MessageWidget *messageWidget;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MessagesPane)
    {
        if (MessagesPane->objectName().isEmpty())
            MessagesPane->setObjectName(QStringLiteral("MessagesPane"));
        MessagesPane->resize(545, 383);
        actnSave = new QAction(MessagesPane);
        actnSave->setObjectName(QStringLiteral("actnSave"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actnSave->setIcon(icon);
        actnAutoExpand = new QAction(MessagesPane);
        actnAutoExpand->setObjectName(QStringLiteral("actnAutoExpand"));
        actnAutoExpand->setCheckable(true);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/auto_expand.png"), QSize(), QIcon::Normal, QIcon::Off);
        actnAutoExpand->setIcon(icon1);
        actnLocate = new QAction(MessagesPane);
        actnLocate->setObjectName(QStringLiteral("actnLocate"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/locate.png"), QSize(), QIcon::Normal, QIcon::Off);
        actnLocate->setIcon(icon2);
        actnFilter = new QAction(MessagesPane);
        actnFilter->setObjectName(QStringLiteral("actnFilter"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/img/filter.png"), QSize(), QIcon::Normal, QIcon::Off);
        actnFilter->setIcon(icon3);
        actnHighlight = new QAction(MessagesPane);
        actnHighlight->setObjectName(QStringLiteral("actnHighlight"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/img/highlight.png"), QSize(), QIcon::Normal, QIcon::Off);
        actnHighlight->setIcon(icon4);
        actnCapture = new QAction(MessagesPane);
        actnCapture->setObjectName(QStringLiteral("actnCapture"));
        actnClear = new QAction(MessagesPane);
        actnClear->setObjectName(QStringLiteral("actnClear"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/img/list_clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        actnClear->setIcon(icon5);
        centralwidget = new QWidget(MessagesPane);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        messageWidget = new MessageWidget(centralwidget);
        messageWidget->setObjectName(QStringLiteral("messageWidget"));
        messageWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        messageWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);

        gridLayout->addWidget(messageWidget, 0, 0, 1, 1);

        MessagesPane->setCentralWidget(centralwidget);
        toolBar = new QToolBar(MessagesPane);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setIconSize(QSize(16, 16));
        MessagesPane->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actnLocate);
        toolBar->addSeparator();
        toolBar->addAction(actnSave);
        toolBar->addSeparator();
        toolBar->addAction(actnCapture);
        toolBar->addAction(actnClear);
        toolBar->addSeparator();
        toolBar->addAction(actnAutoExpand);
        toolBar->addAction(actnFilter);
        toolBar->addAction(actnHighlight);

        retranslateUi(MessagesPane);

        QMetaObject::connectSlotsByName(MessagesPane);
    } // setupUi

    void retranslateUi(QMainWindow *MessagesPane)
    {
        MessagesPane->setWindowTitle(QApplication::translate("MessagesPane", "Window Messages", 0));
        actnSave->setText(QApplication::translate("MessagesPane", "Save Messages", 0));
        actnSave->setShortcut(QApplication::translate("MessagesPane", "Ctrl+S", 0));
        actnAutoExpand->setText(QApplication::translate("MessagesPane", "Auto Expand", 0));
#ifndef QT_NO_TOOLTIP
        actnAutoExpand->setToolTip(QApplication::translate("MessagesPane", "Automatically expand each new item", 0));
#endif // QT_NO_TOOLTIP
        actnLocate->setText(QApplication::translate("MessagesPane", "Locate", 0));
#ifndef QT_NO_TOOLTIP
        actnLocate->setToolTip(QApplication::translate("MessagesPane", "Shows the window in the hierarchy tree", 0));
#endif // QT_NO_TOOLTIP
        actnLocate->setShortcut(QApplication::translate("MessagesPane", "Ctrl+L", 0));
        actnFilter->setText(QApplication::translate("MessagesPane", "Filter", 0));
#ifndef QT_NO_TOOLTIP
        actnFilter->setToolTip(QApplication::translate("MessagesPane", "Include/exclude messages in the list", 0));
#endif // QT_NO_TOOLTIP
        actnHighlight->setText(QApplication::translate("MessagesPane", "Highlight", 0));
#ifndef QT_NO_TOOLTIP
        actnHighlight->setToolTip(QApplication::translate("MessagesPane", "Highlight messages in the list", 0));
#endif // QT_NO_TOOLTIP
        actnCapture->setText(QApplication::translate("MessagesPane", "Start/Stop", 0));
#ifndef QT_NO_TOOLTIP
        actnCapture->setToolTip(QApplication::translate("MessagesPane", "Starts/Stops capturing messages", 0));
#endif // QT_NO_TOOLTIP
        actnCapture->setShortcut(QApplication::translate("MessagesPane", "Space", 0));
        actnClear->setText(QApplication::translate("MessagesPane", "Clear", 0));
#ifndef QT_NO_TOOLTIP
        actnClear->setToolTip(QApplication::translate("MessagesPane", "Clears the message list", 0));
#endif // QT_NO_TOOLTIP
        actnClear->setShortcut(QApplication::translate("MessagesPane", "Del", 0));
        toolBar->setWindowTitle(QApplication::translate("MessagesPane", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MessagesPane: public Ui_MessagesPane {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGESPANE_H

/********************************************************************************
** Form generated from reading UI file 'MessagesPane.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGESPANE_H
#define UI_MESSAGESPANE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
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
            MessagesPane->setObjectName(QString::fromUtf8("MessagesPane"));
        MessagesPane->resize(545, 383);
        actnSave = new QAction(MessagesPane);
        actnSave->setObjectName(QString::fromUtf8("actnSave"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actnSave->setIcon(icon);
        actnAutoExpand = new QAction(MessagesPane);
        actnAutoExpand->setObjectName(QString::fromUtf8("actnAutoExpand"));
        actnAutoExpand->setCheckable(true);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/auto_expand.png"), QSize(), QIcon::Normal, QIcon::Off);
        actnAutoExpand->setIcon(icon1);
        actnLocate = new QAction(MessagesPane);
        actnLocate->setObjectName(QString::fromUtf8("actnLocate"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/locate.png"), QSize(), QIcon::Normal, QIcon::Off);
        actnLocate->setIcon(icon2);
        actnFilter = new QAction(MessagesPane);
        actnFilter->setObjectName(QString::fromUtf8("actnFilter"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/filter.png"), QSize(), QIcon::Normal, QIcon::Off);
        actnFilter->setIcon(icon3);
        actnHighlight = new QAction(MessagesPane);
        actnHighlight->setObjectName(QString::fromUtf8("actnHighlight"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/highlight.png"), QSize(), QIcon::Normal, QIcon::Off);
        actnHighlight->setIcon(icon4);
        actnCapture = new QAction(MessagesPane);
        actnCapture->setObjectName(QString::fromUtf8("actnCapture"));
        actnClear = new QAction(MessagesPane);
        actnClear->setObjectName(QString::fromUtf8("actnClear"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/list_clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        actnClear->setIcon(icon5);
        centralwidget = new QWidget(MessagesPane);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        messageWidget = new MessageWidget(centralwidget);
        messageWidget->setObjectName(QString::fromUtf8("messageWidget"));
        messageWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        messageWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);

        gridLayout->addWidget(messageWidget, 0, 0, 1, 1);

        MessagesPane->setCentralWidget(centralwidget);
        toolBar = new QToolBar(MessagesPane);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
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
        MessagesPane->setWindowTitle(QCoreApplication::translate("MessagesPane", "Window Messages", nullptr));
        actnSave->setText(QCoreApplication::translate("MessagesPane", "Save Messages", nullptr));
#if QT_CONFIG(shortcut)
        actnSave->setShortcut(QCoreApplication::translate("MessagesPane", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actnAutoExpand->setText(QCoreApplication::translate("MessagesPane", "Auto Expand", nullptr));
#if QT_CONFIG(tooltip)
        actnAutoExpand->setToolTip(QCoreApplication::translate("MessagesPane", "Automatically expand each new item", nullptr));
#endif // QT_CONFIG(tooltip)
        actnLocate->setText(QCoreApplication::translate("MessagesPane", "Locate", nullptr));
#if QT_CONFIG(tooltip)
        actnLocate->setToolTip(QCoreApplication::translate("MessagesPane", "Shows the window in the hierarchy tree", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actnLocate->setShortcut(QCoreApplication::translate("MessagesPane", "Ctrl+L", nullptr));
#endif // QT_CONFIG(shortcut)
        actnFilter->setText(QCoreApplication::translate("MessagesPane", "Filter", nullptr));
#if QT_CONFIG(tooltip)
        actnFilter->setToolTip(QCoreApplication::translate("MessagesPane", "Include/exclude messages in the list", nullptr));
#endif // QT_CONFIG(tooltip)
        actnHighlight->setText(QCoreApplication::translate("MessagesPane", "Highlight", nullptr));
#if QT_CONFIG(tooltip)
        actnHighlight->setToolTip(QCoreApplication::translate("MessagesPane", "Highlight messages in the list", nullptr));
#endif // QT_CONFIG(tooltip)
        actnCapture->setText(QCoreApplication::translate("MessagesPane", "Start/Stop", nullptr));
#if QT_CONFIG(tooltip)
        actnCapture->setToolTip(QCoreApplication::translate("MessagesPane", "Starts/Stops capturing messages", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actnCapture->setShortcut(QCoreApplication::translate("MessagesPane", "Space", nullptr));
#endif // QT_CONFIG(shortcut)
        actnClear->setText(QCoreApplication::translate("MessagesPane", "Clear", nullptr));
#if QT_CONFIG(tooltip)
        actnClear->setToolTip(QCoreApplication::translate("MessagesPane", "Clears the message list", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actnClear->setShortcut(QCoreApplication::translate("MessagesPane", "Del", nullptr));
#endif // QT_CONFIG(shortcut)
        toolBar->setWindowTitle(QCoreApplication::translate("MessagesPane", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MessagesPane: public Ui_MessagesPane {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGESPANE_H

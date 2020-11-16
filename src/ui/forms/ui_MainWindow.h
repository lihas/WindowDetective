/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ui/custom_widgets/ResizableDockContainer.h"
#include "ui/custom_widgets/WindowTree.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actnPreferences;
    QAction *actnHelp;
    QAction *actnAbout;
    QAction *actnFind;
    QAction *actnRefresh;
    QAction *actnTile;
    QAction *actnCascade;
    QAction *actnCloseAllMdi;
    QAction *actnSystemInfo;
    QAction *actionConnect_to_server;
    QAction *actionStart_Server;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QMdiArea *mdiArea;
    QMenuBar *menubar;
    QMenu *menuSpy;
    QMenu *menuRemote;
    QMenu *menuHelp;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuWindows;
    QDockWidget *treeDock;
    ResizableDockContainer *treeDockContents;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *cbTreeView;
    WindowTree *windowTree;
    QToolBar *pickerToolBar;
    QToolBar *mainToolBar;
    QDockWidget *logDock;
    ResizableDockContainer *logDockContents;
    QHBoxLayout *horizontalLayout_3;
    QTreeWidget *logList;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 800);
        actnPreferences = new QAction(MainWindow);
        actnPreferences->setObjectName(QString::fromUtf8("actnPreferences"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/preferences.png"), QSize(), QIcon::Normal, QIcon::Off);
        actnPreferences->setIcon(icon);
        actnHelp = new QAction(MainWindow);
        actnHelp->setObjectName(QString::fromUtf8("actnHelp"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actnHelp->setIcon(icon1);
        actnAbout = new QAction(MainWindow);
        actnAbout->setObjectName(QString::fromUtf8("actnAbout"));
        actnFind = new QAction(MainWindow);
        actnFind->setObjectName(QString::fromUtf8("actnFind"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/find.png"), QSize(), QIcon::Normal, QIcon::Off);
        actnFind->setIcon(icon2);
        actnRefresh = new QAction(MainWindow);
        actnRefresh->setObjectName(QString::fromUtf8("actnRefresh"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        actnRefresh->setIcon(icon3);
        actnTile = new QAction(MainWindow);
        actnTile->setObjectName(QString::fromUtf8("actnTile"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/tile.png"), QSize(), QIcon::Normal, QIcon::Off);
        actnTile->setIcon(icon4);
        actnCascade = new QAction(MainWindow);
        actnCascade->setObjectName(QString::fromUtf8("actnCascade"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/cascade.png"), QSize(), QIcon::Normal, QIcon::Off);
        actnCascade->setIcon(icon5);
        actnCloseAllMdi = new QAction(MainWindow);
        actnCloseAllMdi->setObjectName(QString::fromUtf8("actnCloseAllMdi"));
        actnSystemInfo = new QAction(MainWindow);
        actnSystemInfo->setObjectName(QString::fromUtf8("actnSystemInfo"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/img/system_info.png"), QSize(), QIcon::Normal, QIcon::Off);
        actnSystemInfo->setIcon(icon6);
        actionConnect_to_server = new QAction(MainWindow);
        actionConnect_to_server->setObjectName(QString::fromUtf8("actionConnect_to_server"));
        actionStart_Server = new QAction(MainWindow);
        actionStart_Server->setObjectName(QString::fromUtf8("actionStart_Server"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setSpacing(2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(2, 2, 2, 2);
        mdiArea = new QMdiArea(centralwidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));
        mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

        gridLayout_2->addWidget(mdiArea, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1000, 47));
        menuSpy = new QMenu(menubar);
        menuSpy->setObjectName(QString::fromUtf8("menuSpy"));
        menuRemote = new QMenu(menuSpy);
        menuRemote->setObjectName(QString::fromUtf8("menuRemote"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuWindows = new QMenu(menubar);
        menuWindows->setObjectName(QString::fromUtf8("menuWindows"));
        MainWindow->setMenuBar(menubar);
        treeDock = new QDockWidget(MainWindow);
        treeDock->setObjectName(QString::fromUtf8("treeDock"));
        treeDockContents = new ResizableDockContainer();
        treeDockContents->setObjectName(QString::fromUtf8("treeDockContents"));
        verticalLayout = new QVBoxLayout(treeDockContents);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(treeDockContents);
        widget->setObjectName(QString::fromUtf8("widget"));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(5, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        cbTreeView = new QComboBox(widget);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/img/window.png"), QSize(), QIcon::Normal, QIcon::Off);
        cbTreeView->addItem(icon7, QString());
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/img/process.png"), QSize(), QIcon::Normal, QIcon::Off);
        cbTreeView->addItem(icon8, QString());
        cbTreeView->setObjectName(QString::fromUtf8("cbTreeView"));

        formLayout->setWidget(0, QFormLayout::FieldRole, cbTreeView);


        verticalLayout->addWidget(widget);

        windowTree = new WindowTree(treeDockContents);
        windowTree->setObjectName(QString::fromUtf8("windowTree"));
        windowTree->setEditTriggers(QAbstractItemView::NoEditTriggers);
        windowTree->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        windowTree->setUniformRowHeights(true);
        windowTree->setAllColumnsShowFocus(true);

        verticalLayout->addWidget(windowTree);

        treeDock->setWidget(treeDockContents);
        MainWindow->addDockWidget(Qt::LeftDockWidgetArea, treeDock);
        pickerToolBar = new QToolBar(MainWindow);
        pickerToolBar->setObjectName(QString::fromUtf8("pickerToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, pickerToolBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setIconSize(QSize(16, 16));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        logDock = new QDockWidget(MainWindow);
        logDock->setObjectName(QString::fromUtf8("logDock"));
        logDockContents = new ResizableDockContainer();
        logDockContents->setObjectName(QString::fromUtf8("logDockContents"));
        horizontalLayout_3 = new QHBoxLayout(logDockContents);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        logList = new QTreeWidget(logDockContents);
        logList->setObjectName(QString::fromUtf8("logList"));
        logList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        logList->setDragDropOverwriteMode(false);
        logList->setSelectionMode(QAbstractItemView::NoSelection);
        logList->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        logList->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        logList->setRootIsDecorated(false);
        logList->setUniformRowHeights(true);

        horizontalLayout_3->addWidget(logList);

        logDock->setWidget(logDockContents);
        MainWindow->addDockWidget(Qt::BottomDockWidgetArea, logDock);

        menubar->addAction(menuSpy->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuWindows->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuSpy->addAction(actnFind);
        menuSpy->addSeparator();
        menuSpy->addAction(menuRemote->menuAction());
        menuRemote->addAction(actionConnect_to_server);
        menuRemote->addAction(actionStart_Server);
        menuHelp->addAction(actnHelp);
        menuHelp->addSeparator();
        menuHelp->addAction(actnAbout);
        menuEdit->addAction(actnPreferences);
        menuView->addAction(actnRefresh);
        menuView->addAction(actnSystemInfo);
        mainToolBar->addAction(actnFind);
        mainToolBar->addAction(actnRefresh);
        mainToolBar->addAction(actnSystemInfo);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Window Detective", nullptr));
        actnPreferences->setText(QCoreApplication::translate("MainWindow", "&Preferences...", nullptr));
        actnHelp->setText(QCoreApplication::translate("MainWindow", "&Help Contents", nullptr));
#if QT_CONFIG(shortcut)
        actnHelp->setShortcut(QCoreApplication::translate("MainWindow", "F1", nullptr));
#endif // QT_CONFIG(shortcut)
        actnAbout->setText(QCoreApplication::translate("MainWindow", "&About Window Detective", nullptr));
        actnFind->setText(QCoreApplication::translate("MainWindow", "&Find...", nullptr));
#if QT_CONFIG(tooltip)
        actnFind->setToolTip(QCoreApplication::translate("MainWindow", "Find a window", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actnFind->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_CONFIG(shortcut)
        actnRefresh->setText(QCoreApplication::translate("MainWindow", "&Refresh", nullptr));
#if QT_CONFIG(tooltip)
        actnRefresh->setToolTip(QCoreApplication::translate("MainWindow", "Refresh all window", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actnRefresh->setShortcut(QCoreApplication::translate("MainWindow", "F5", nullptr));
#endif // QT_CONFIG(shortcut)
        actnTile->setText(QCoreApplication::translate("MainWindow", "&Tile", nullptr));
        actnCascade->setText(QCoreApplication::translate("MainWindow", "&Cascade", nullptr));
        actnCloseAllMdi->setText(QCoreApplication::translate("MainWindow", "&Close All", nullptr));
#if QT_CONFIG(tooltip)
        actnCloseAllMdi->setToolTip(QCoreApplication::translate("MainWindow", "Close All MDI Windows", nullptr));
#endif // QT_CONFIG(tooltip)
        actnSystemInfo->setText(QCoreApplication::translate("MainWindow", "System Info", nullptr));
#if QT_CONFIG(tooltip)
        actnSystemInfo->setToolTip(QCoreApplication::translate("MainWindow", "View System UI Configuration Settings", nullptr));
#endif // QT_CONFIG(tooltip)
        actionConnect_to_server->setText(QCoreApplication::translate("MainWindow", "Connect to server", nullptr));
        actionStart_Server->setText(QCoreApplication::translate("MainWindow", "Start Server", nullptr));
#if QT_CONFIG(whatsthis)
        mdiArea->setWhatsThis(QCoreApplication::translate("MainWindow", "The main pane, holds multiple property or message panes.", nullptr));
#endif // QT_CONFIG(whatsthis)
        menuSpy->setTitle(QCoreApplication::translate("MainWindow", "&Inspect", nullptr));
        menuRemote->setTitle(QCoreApplication::translate("MainWindow", "Remote", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "&Help", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "&Edit", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "&View", nullptr));
        menuWindows->setTitle(QCoreApplication::translate("MainWindow", "&Windows", nullptr));
#if QT_CONFIG(whatsthis)
        treeDock->setWhatsThis(QCoreApplication::translate("MainWindow", "Lists all windows in the system, sorted either by relationship to the desktop window or by owner process", nullptr));
#endif // QT_CONFIG(whatsthis)
        treeDock->setWindowTitle(QCoreApplication::translate("MainWindow", "Window Hierarchy", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "View:", nullptr));
        cbTreeView->setItemText(0, QCoreApplication::translate("MainWindow", "Desktop window hierarchy", nullptr));
        cbTreeView->setItemText(1, QCoreApplication::translate("MainWindow", "Process window hierarchy", nullptr));

#if QT_CONFIG(whatsthis)
        cbTreeView->setWhatsThis(QCoreApplication::translate("MainWindow", "Selects how the windows are displayed in the tree.", nullptr));
#endif // QT_CONFIG(whatsthis)
        QTreeWidgetItem *___qtreewidgetitem = windowTree->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "Window", nullptr));
#if QT_CONFIG(whatsthis)
        windowTree->setWhatsThis(QCoreApplication::translate("MainWindow", "Lists all windows in the system, arranged either by relationship to the desktop window or by owner process.", nullptr));
#endif // QT_CONFIG(whatsthis)
        pickerToolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "Picker ToolBar", nullptr));
        mainToolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "Main ToolBar", nullptr));
#if QT_CONFIG(whatsthis)
        logDock->setWhatsThis(QCoreApplication::translate("MainWindow", "Displays any status messages or window events as they happen", nullptr));
#endif // QT_CONFIG(whatsthis)
        logDock->setWindowTitle(QCoreApplication::translate("MainWindow", "Logs", nullptr));
        QTreeWidgetItem *___qtreewidgetitem1 = logList->headerItem();
        ___qtreewidgetitem1->setText(2, QCoreApplication::translate("MainWindow", "Message", nullptr));
        ___qtreewidgetitem1->setText(1, QCoreApplication::translate("MainWindow", "Level", nullptr));
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("MainWindow", "Time", nullptr));
#if QT_CONFIG(whatsthis)
        logList->setWhatsThis(QCoreApplication::translate("MainWindow", "Displays any status messages, errors, or window events as they happen.", nullptr));
#endif // QT_CONFIG(whatsthis)
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

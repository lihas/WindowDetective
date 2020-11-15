/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1000, 800);
        actnPreferences = new QAction(MainWindow);
        actnPreferences->setObjectName(QStringLiteral("actnPreferences"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/preferences.png"), QSize(), QIcon::Normal, QIcon::Off);
        actnPreferences->setIcon(icon);
        actnHelp = new QAction(MainWindow);
        actnHelp->setObjectName(QStringLiteral("actnHelp"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actnHelp->setIcon(icon1);
        actnAbout = new QAction(MainWindow);
        actnAbout->setObjectName(QStringLiteral("actnAbout"));
        actnFind = new QAction(MainWindow);
        actnFind->setObjectName(QStringLiteral("actnFind"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/find.png"), QSize(), QIcon::Normal, QIcon::Off);
        actnFind->setIcon(icon2);
        actnRefresh = new QAction(MainWindow);
        actnRefresh->setObjectName(QStringLiteral("actnRefresh"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/img/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        actnRefresh->setIcon(icon3);
        actnTile = new QAction(MainWindow);
        actnTile->setObjectName(QStringLiteral("actnTile"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/img/tile.png"), QSize(), QIcon::Normal, QIcon::Off);
        actnTile->setIcon(icon4);
        actnCascade = new QAction(MainWindow);
        actnCascade->setObjectName(QStringLiteral("actnCascade"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/img/cascade.png"), QSize(), QIcon::Normal, QIcon::Off);
        actnCascade->setIcon(icon5);
        actnCloseAllMdi = new QAction(MainWindow);
        actnCloseAllMdi->setObjectName(QStringLiteral("actnCloseAllMdi"));
        actnSystemInfo = new QAction(MainWindow);
        actnSystemInfo->setObjectName(QStringLiteral("actnSystemInfo"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/img/system_info.png"), QSize(), QIcon::Normal, QIcon::Off);
        actnSystemInfo->setIcon(icon6);
        actionConnect_to_server = new QAction(MainWindow);
        actionConnect_to_server->setObjectName(QStringLiteral("actionConnect_to_server"));
        actionStart_Server = new QAction(MainWindow);
        actionStart_Server->setObjectName(QStringLiteral("actionStart_Server"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setSpacing(2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(2, 2, 2, 2);
        mdiArea = new QMdiArea(centralwidget);
        mdiArea->setObjectName(QStringLiteral("mdiArea"));
        mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

        gridLayout_2->addWidget(mdiArea, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1000, 47));
        menuSpy = new QMenu(menubar);
        menuSpy->setObjectName(QStringLiteral("menuSpy"));
        menuRemote = new QMenu(menuSpy);
        menuRemote->setObjectName(QStringLiteral("menuRemote"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuWindows = new QMenu(menubar);
        menuWindows->setObjectName(QStringLiteral("menuWindows"));
        MainWindow->setMenuBar(menubar);
        treeDock = new QDockWidget(MainWindow);
        treeDock->setObjectName(QStringLiteral("treeDock"));
        treeDockContents = new ResizableDockContainer();
        treeDockContents->setObjectName(QStringLiteral("treeDockContents"));
        verticalLayout = new QVBoxLayout(treeDockContents);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(treeDockContents);
        widget->setObjectName(QStringLiteral("widget"));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(5, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        cbTreeView = new QComboBox(widget);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/img/window.png"), QSize(), QIcon::Normal, QIcon::Off);
        cbTreeView->addItem(icon7, QString());
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/img/process.png"), QSize(), QIcon::Normal, QIcon::Off);
        cbTreeView->addItem(icon8, QString());
        cbTreeView->setObjectName(QStringLiteral("cbTreeView"));

        formLayout->setWidget(0, QFormLayout::FieldRole, cbTreeView);


        verticalLayout->addWidget(widget);

        windowTree = new WindowTree(treeDockContents);
        windowTree->setObjectName(QStringLiteral("windowTree"));
        windowTree->setEditTriggers(QAbstractItemView::NoEditTriggers);
        windowTree->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        windowTree->setUniformRowHeights(true);
        windowTree->setAllColumnsShowFocus(true);

        verticalLayout->addWidget(windowTree);

        treeDock->setWidget(treeDockContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), treeDock);
        pickerToolBar = new QToolBar(MainWindow);
        pickerToolBar->setObjectName(QStringLiteral("pickerToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, pickerToolBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setIconSize(QSize(16, 16));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        logDock = new QDockWidget(MainWindow);
        logDock->setObjectName(QStringLiteral("logDock"));
        logDockContents = new ResizableDockContainer();
        logDockContents->setObjectName(QStringLiteral("logDockContents"));
        horizontalLayout_3 = new QHBoxLayout(logDockContents);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        logList = new QTreeWidget(logDockContents);
        logList->setObjectName(QStringLiteral("logList"));
        logList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        logList->setDragDropOverwriteMode(false);
        logList->setSelectionMode(QAbstractItemView::NoSelection);
        logList->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        logList->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        logList->setRootIsDecorated(false);
        logList->setUniformRowHeights(true);

        horizontalLayout_3->addWidget(logList);

        logDock->setWidget(logDockContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), logDock);

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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Window Detective", 0));
        actnPreferences->setText(QApplication::translate("MainWindow", "&Preferences...", 0));
        actnHelp->setText(QApplication::translate("MainWindow", "&Help Contents", 0));
        actnHelp->setShortcut(QApplication::translate("MainWindow", "F1", 0));
        actnAbout->setText(QApplication::translate("MainWindow", "&About Window Detective", 0));
        actnFind->setText(QApplication::translate("MainWindow", "&Find...", 0));
#ifndef QT_NO_TOOLTIP
        actnFind->setToolTip(QApplication::translate("MainWindow", "Find a window", 0));
#endif // QT_NO_TOOLTIP
        actnFind->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", 0));
        actnRefresh->setText(QApplication::translate("MainWindow", "&Refresh", 0));
#ifndef QT_NO_TOOLTIP
        actnRefresh->setToolTip(QApplication::translate("MainWindow", "Refresh all window", 0));
#endif // QT_NO_TOOLTIP
        actnRefresh->setShortcut(QApplication::translate("MainWindow", "F5", 0));
        actnTile->setText(QApplication::translate("MainWindow", "&Tile", 0));
        actnCascade->setText(QApplication::translate("MainWindow", "&Cascade", 0));
        actnCloseAllMdi->setText(QApplication::translate("MainWindow", "&Close All", 0));
#ifndef QT_NO_TOOLTIP
        actnCloseAllMdi->setToolTip(QApplication::translate("MainWindow", "Close All MDI Windows", 0));
#endif // QT_NO_TOOLTIP
        actnSystemInfo->setText(QApplication::translate("MainWindow", "System Info", 0));
#ifndef QT_NO_TOOLTIP
        actnSystemInfo->setToolTip(QApplication::translate("MainWindow", "View System UI Configuration Settings", 0));
#endif // QT_NO_TOOLTIP
        actionConnect_to_server->setText(QApplication::translate("MainWindow", "Connect to server", 0));
        actionStart_Server->setText(QApplication::translate("MainWindow", "Start Server", 0));
#ifndef QT_NO_WHATSTHIS
        mdiArea->setWhatsThis(QApplication::translate("MainWindow", "The main pane, holds multiple property or message panes.", 0));
#endif // QT_NO_WHATSTHIS
        menuSpy->setTitle(QApplication::translate("MainWindow", "&Inspect", 0));
        menuRemote->setTitle(QApplication::translate("MainWindow", "Remote", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "&Help", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "&Edit", 0));
        menuView->setTitle(QApplication::translate("MainWindow", "&View", 0));
        menuWindows->setTitle(QApplication::translate("MainWindow", "&Windows", 0));
#ifndef QT_NO_WHATSTHIS
        treeDock->setWhatsThis(QApplication::translate("MainWindow", "Lists all windows in the system, sorted either by relationship to the desktop window or by owner process", 0));
#endif // QT_NO_WHATSTHIS
        treeDock->setWindowTitle(QApplication::translate("MainWindow", "Window Hierarchy", 0));
        label->setText(QApplication::translate("MainWindow", "View:", 0));
        cbTreeView->setItemText(0, QApplication::translate("MainWindow", "Desktop window hierarchy", 0));
        cbTreeView->setItemText(1, QApplication::translate("MainWindow", "Process window hierarchy", 0));

#ifndef QT_NO_WHATSTHIS
        cbTreeView->setWhatsThis(QApplication::translate("MainWindow", "Selects how the windows are displayed in the tree.", 0));
#endif // QT_NO_WHATSTHIS
        QTreeWidgetItem *___qtreewidgetitem = windowTree->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Window", 0));
#ifndef QT_NO_WHATSTHIS
        windowTree->setWhatsThis(QApplication::translate("MainWindow", "Lists all windows in the system, arranged either by relationship to the desktop window or by owner process.", 0));
#endif // QT_NO_WHATSTHIS
        pickerToolBar->setWindowTitle(QApplication::translate("MainWindow", "Picker ToolBar", 0));
        mainToolBar->setWindowTitle(QApplication::translate("MainWindow", "Main ToolBar", 0));
#ifndef QT_NO_WHATSTHIS
        logDock->setWhatsThis(QApplication::translate("MainWindow", "Displays any status messages or window events as they happen", 0));
#endif // QT_NO_WHATSTHIS
        logDock->setWindowTitle(QApplication::translate("MainWindow", "Logs", 0));
        QTreeWidgetItem *___qtreewidgetitem1 = logList->headerItem();
        ___qtreewidgetitem1->setText(2, QApplication::translate("MainWindow", "Message", 0));
        ___qtreewidgetitem1->setText(1, QApplication::translate("MainWindow", "Level", 0));
        ___qtreewidgetitem1->setText(0, QApplication::translate("MainWindow", "Time", 0));
#ifndef QT_NO_WHATSTHIS
        logList->setWhatsThis(QApplication::translate("MainWindow", "Displays any status messages, errors, or window events as they happen.", 0));
#endif // QT_NO_WHATSTHIS
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

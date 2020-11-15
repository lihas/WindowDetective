/********************************************************************************
** Form generated from reading UI file 'PropertiesPane.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROPERTIESPANE_H
#define UI_PROPERTIESPANE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PropertiesPane
{
public:
    QAction *actnLocate;
    QAction *actnSave;
    QAction *actnFlash;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QToolBar *toolBar;

    void setupUi(QMainWindow *PropertiesPane)
    {
        if (PropertiesPane->objectName().isEmpty())
            PropertiesPane->setObjectName(QStringLiteral("PropertiesPane"));
        PropertiesPane->resize(545, 383);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PropertiesPane->sizePolicy().hasHeightForWidth());
        PropertiesPane->setSizePolicy(sizePolicy);
        PropertiesPane->setMinimumSize(QSize(300, 200));
        actnLocate = new QAction(PropertiesPane);
        actnLocate->setObjectName(QStringLiteral("actnLocate"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/locate.png"), QSize(), QIcon::Normal, QIcon::Off);
        actnLocate->setIcon(icon);
        actnSave = new QAction(PropertiesPane);
        actnSave->setObjectName(QStringLiteral("actnSave"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actnSave->setIcon(icon1);
        actnFlash = new QAction(PropertiesPane);
        actnFlash->setObjectName(QStringLiteral("actnFlash"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/flash.png"), QSize(), QIcon::Normal, QIcon::Off);
        actnFlash->setIcon(icon2);
        centralwidget = new QWidget(PropertiesPane);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        PropertiesPane->setCentralWidget(centralwidget);
        toolBar = new QToolBar(PropertiesPane);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setIconSize(QSize(16, 16));
        toolBar->setFloatable(false);
        PropertiesPane->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actnLocate);
        toolBar->addAction(actnFlash);
        toolBar->addSeparator();
        toolBar->addAction(actnSave);

        retranslateUi(PropertiesPane);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(PropertiesPane);
    } // setupUi

    void retranslateUi(QMainWindow *PropertiesPane)
    {
        PropertiesPane->setWindowTitle(QApplication::translate("PropertiesPane", "Window Properties", 0));
        actnLocate->setText(QApplication::translate("PropertiesPane", "Locate", 0));
#ifndef QT_NO_TOOLTIP
        actnLocate->setToolTip(QApplication::translate("PropertiesPane", "Shows the window in the hierarchy tree", 0));
#endif // QT_NO_TOOLTIP
        actnLocate->setShortcut(QApplication::translate("PropertiesPane", "Ctrl+L", 0));
        actnSave->setText(QApplication::translate("PropertiesPane", "Save Window Properties", 0));
#ifndef QT_NO_TOOLTIP
        actnSave->setToolTip(QApplication::translate("PropertiesPane", "Save the window properties to a file in either text or xml format", 0));
#endif // QT_NO_TOOLTIP
        actnSave->setShortcut(QApplication::translate("PropertiesPane", "Ctrl+S", 0));
        actnFlash->setText(QApplication::translate("PropertiesPane", "Flash", 0));
        toolBar->setWindowTitle(QApplication::translate("PropertiesPane", "Tool Bar", 0));
    } // retranslateUi

};

namespace Ui {
    class PropertiesPane: public Ui_PropertiesPane {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROPERTIESPANE_H

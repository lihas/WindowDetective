/********************************************************************************
** Form generated from reading UI file 'PropertiesPane.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROPERTIESPANE_H
#define UI_PROPERTIESPANE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
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
            PropertiesPane->setObjectName(QString::fromUtf8("PropertiesPane"));
        PropertiesPane->resize(545, 383);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PropertiesPane->sizePolicy().hasHeightForWidth());
        PropertiesPane->setSizePolicy(sizePolicy);
        PropertiesPane->setMinimumSize(QSize(300, 200));
        actnLocate = new QAction(PropertiesPane);
        actnLocate->setObjectName(QString::fromUtf8("actnLocate"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/locate.png"), QSize(), QIcon::Normal, QIcon::Off);
        actnLocate->setIcon(icon);
        actnSave = new QAction(PropertiesPane);
        actnSave->setObjectName(QString::fromUtf8("actnSave"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actnSave->setIcon(icon1);
        actnFlash = new QAction(PropertiesPane);
        actnFlash->setObjectName(QString::fromUtf8("actnFlash"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/flash.png"), QSize(), QIcon::Normal, QIcon::Off);
        actnFlash->setIcon(icon2);
        centralwidget = new QWidget(PropertiesPane);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        PropertiesPane->setCentralWidget(centralwidget);
        toolBar = new QToolBar(PropertiesPane);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
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
        PropertiesPane->setWindowTitle(QCoreApplication::translate("PropertiesPane", "Window Properties", nullptr));
        actnLocate->setText(QCoreApplication::translate("PropertiesPane", "Locate", nullptr));
#if QT_CONFIG(tooltip)
        actnLocate->setToolTip(QCoreApplication::translate("PropertiesPane", "Shows the window in the hierarchy tree", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actnLocate->setShortcut(QCoreApplication::translate("PropertiesPane", "Ctrl+L", nullptr));
#endif // QT_CONFIG(shortcut)
        actnSave->setText(QCoreApplication::translate("PropertiesPane", "Save Window Properties", nullptr));
#if QT_CONFIG(tooltip)
        actnSave->setToolTip(QCoreApplication::translate("PropertiesPane", "Save the window properties to a file in either text or xml format", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actnSave->setShortcut(QCoreApplication::translate("PropertiesPane", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actnFlash->setText(QCoreApplication::translate("PropertiesPane", "Flash", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("PropertiesPane", "Tool Bar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PropertiesPane: public Ui_PropertiesPane {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROPERTIESPANE_H

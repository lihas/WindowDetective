/********************************************************************************
** Form generated from reading UI file 'SystemInfoDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMINFODIALOG_H
#define UI_SYSTEMINFODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include "ui\SystemColoursPane.h"
#include "ui\SystemMetricsPane.h"
#include "ui\SystemParametersPane.h"

QT_BEGIN_NAMESPACE

class Ui_SystemInfoDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    SystemParametersPane *generalInfoTab;
    QVBoxLayout *verticalLayout_4;
    SystemMetricsPane *systemMetricsTab;
    QVBoxLayout *verticalLayout_2;
    SystemColoursPane *systemColoursTab;
    QVBoxLayout *verticalLayout_3;

    void setupUi(QDialog *SystemInfoDialog)
    {
        if (SystemInfoDialog->objectName().isEmpty())
            SystemInfoDialog->setObjectName(QString::fromUtf8("SystemInfoDialog"));
        SystemInfoDialog->resize(530, 500);
        verticalLayout = new QVBoxLayout(SystemInfoDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        tabWidget = new QTabWidget(SystemInfoDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        generalInfoTab = new SystemParametersPane();
        generalInfoTab->setObjectName(QString::fromUtf8("generalInfoTab"));
        verticalLayout_4 = new QVBoxLayout(generalInfoTab);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(3, 3, 3, 3);
        tabWidget->addTab(generalInfoTab, QString());
        systemMetricsTab = new SystemMetricsPane();
        systemMetricsTab->setObjectName(QString::fromUtf8("systemMetricsTab"));
        verticalLayout_2 = new QVBoxLayout(systemMetricsTab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(3, 3, 3, 3);
        tabWidget->addTab(systemMetricsTab, QString());
        systemColoursTab = new SystemColoursPane();
        systemColoursTab->setObjectName(QString::fromUtf8("systemColoursTab"));
        verticalLayout_3 = new QVBoxLayout(systemColoursTab);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(3, 3, 3, 3);
        tabWidget->addTab(systemColoursTab, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(SystemInfoDialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SystemInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *SystemInfoDialog)
    {
        SystemInfoDialog->setWindowTitle(QCoreApplication::translate("SystemInfoDialog", "System Info", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(generalInfoTab), QCoreApplication::translate("SystemInfoDialog", "General Info", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(systemMetricsTab), QCoreApplication::translate("SystemInfoDialog", "System Metrics", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(systemColoursTab), QCoreApplication::translate("SystemInfoDialog", "System Colours", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SystemInfoDialog: public Ui_SystemInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMINFODIALOG_H

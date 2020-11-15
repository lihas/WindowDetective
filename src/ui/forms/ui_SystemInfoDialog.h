/********************************************************************************
** Form generated from reading UI file 'SystemInfoDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMINFODIALOG_H
#define UI_SYSTEMINFODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
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
            SystemInfoDialog->setObjectName(QStringLiteral("SystemInfoDialog"));
        SystemInfoDialog->resize(530, 500);
        verticalLayout = new QVBoxLayout(SystemInfoDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        tabWidget = new QTabWidget(SystemInfoDialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        generalInfoTab = new SystemParametersPane();
        generalInfoTab->setObjectName(QStringLiteral("generalInfoTab"));
        verticalLayout_4 = new QVBoxLayout(generalInfoTab);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(3, 3, 3, 3);
        tabWidget->addTab(generalInfoTab, QString());
        systemMetricsTab = new SystemMetricsPane();
        systemMetricsTab->setObjectName(QStringLiteral("systemMetricsTab"));
        verticalLayout_2 = new QVBoxLayout(systemMetricsTab);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(3, 3, 3, 3);
        tabWidget->addTab(systemMetricsTab, QString());
        systemColoursTab = new SystemColoursPane();
        systemColoursTab->setObjectName(QStringLiteral("systemColoursTab"));
        verticalLayout_3 = new QVBoxLayout(systemColoursTab);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(3, 3, 3, 3);
        tabWidget->addTab(systemColoursTab, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(SystemInfoDialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SystemInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *SystemInfoDialog)
    {
        SystemInfoDialog->setWindowTitle(QApplication::translate("SystemInfoDialog", "System Info", 0));
        tabWidget->setTabText(tabWidget->indexOf(generalInfoTab), QApplication::translate("SystemInfoDialog", "General Info", 0));
        tabWidget->setTabText(tabWidget->indexOf(systemMetricsTab), QApplication::translate("SystemInfoDialog", "System Metrics", 0));
        tabWidget->setTabText(tabWidget->indexOf(systemColoursTab), QApplication::translate("SystemInfoDialog", "System Colours", 0));
    } // retranslateUi

};

namespace Ui {
    class SystemInfoDialog: public Ui_SystemInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMINFODIALOG_H

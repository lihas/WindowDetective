/********************************************************************************
** Form generated from reading UI file 'SystemMetricsPane.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMMETRICSPANE_H
#define UI_SYSTEMMETRICSPANE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SystemMetricsPane
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableView *table;

    void setupUi(QWidget *SystemMetricsPane)
    {
        if (SystemMetricsPane->objectName().isEmpty())
            SystemMetricsPane->setObjectName(QStringLiteral("SystemMetricsPane"));
        SystemMetricsPane->resize(500, 400);
        verticalLayout = new QVBoxLayout(SystemMetricsPane);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(SystemMetricsPane);
        label->setObjectName(QStringLiteral("label"));
        label->setMargin(6);

        verticalLayout->addWidget(label);

        table = new QTableView(SystemMetricsPane);
        table->setObjectName(QStringLiteral("table"));
        table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table->setSelectionBehavior(QAbstractItemView::SelectRows);
        table->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        table->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        table->setWordWrap(false);
        table->setCornerButtonEnabled(false);
        table->horizontalHeader()->setHighlightSections(false);
        table->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        table->horizontalHeader()->setStretchLastSection(true);
        table->verticalHeader()->setCascadingSectionResizes(true);
        table->verticalHeader()->setDefaultSectionSize(0);
        table->verticalHeader()->setHighlightSections(false);
        table->verticalHeader()->setProperty("showSortIndicator", QVariant(false));

        verticalLayout->addWidget(table);


        retranslateUi(SystemMetricsPane);

        QMetaObject::connectSlotsByName(SystemMetricsPane);
    } // setupUi

    void retranslateUi(QWidget *SystemMetricsPane)
    {
        label->setText(QApplication::translate("SystemMetricsPane", "List of system metrics, obtained from the GetSystemMetrics API function", 0));
        Q_UNUSED(SystemMetricsPane);
    } // retranslateUi

};

namespace Ui {
    class SystemMetricsPane: public Ui_SystemMetricsPane {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMMETRICSPANE_H

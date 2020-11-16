/********************************************************************************
** Form generated from reading UI file 'MessageFilterDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEFILTERDIALOG_H
#define UI_MESSAGEFILTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ui/custom_widgets/SearchInputPane.h"

QT_BEGIN_NAMESPACE

class Ui_MessageFilterDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *filterTab;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_4;
    SearchInputPane *findPane;
    QListView *filterListView;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *otherMessagesCheckBox;
    QPushButton *includeAllButton;
    QPushButton *excludeAllButton;
    QSpacerItem *verticalSpacer_2;
    QPushButton *includeSelectedButton;
    QPushButton *excludeSelectedButton;
    QSpacerItem *verticalSpacer;
    QWidget *highlightTab;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *highlightsTable;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *addHighlightButton;
    QPushButton *removeHighlightButton;
    QDialogButtonBox *dialogButtons;

    void setupUi(QDialog *MessageFilterDialog)
    {
        if (MessageFilterDialog->objectName().isEmpty())
            MessageFilterDialog->setObjectName(QString::fromUtf8("MessageFilterDialog"));
        MessageFilterDialog->resize(495, 348);
        MessageFilterDialog->setMinimumSize(QSize(400, 300));
        verticalLayout = new QVBoxLayout(MessageFilterDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(MessageFilterDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        filterTab = new QWidget();
        filterTab->setObjectName(QString::fromUtf8("filterTab"));
        horizontalLayout_2 = new QHBoxLayout(filterTab);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        widget_3 = new QWidget(filterTab);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout_4 = new QVBoxLayout(widget_3);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        findPane = new SearchInputPane(widget_3);
        findPane->setObjectName(QString::fromUtf8("findPane"));

        verticalLayout_4->addWidget(findPane);

        filterListView = new QListView(widget_3);
        filterListView->setObjectName(QString::fromUtf8("filterListView"));
        filterListView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        filterListView->setSelectionMode(QAbstractItemView::ExtendedSelection);
        filterListView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        filterListView->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        filterListView->setUniformItemSizes(true);

        verticalLayout_4->addWidget(filterListView);


        horizontalLayout_2->addWidget(widget_3);

        widget = new QWidget(filterTab);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(6, -1, 6, -1);
        otherMessagesCheckBox = new QCheckBox(widget);
        otherMessagesCheckBox->setObjectName(QString::fromUtf8("otherMessagesCheckBox"));

        verticalLayout_2->addWidget(otherMessagesCheckBox);

        includeAllButton = new QPushButton(widget);
        includeAllButton->setObjectName(QString::fromUtf8("includeAllButton"));

        verticalLayout_2->addWidget(includeAllButton);

        excludeAllButton = new QPushButton(widget);
        excludeAllButton->setObjectName(QString::fromUtf8("excludeAllButton"));

        verticalLayout_2->addWidget(excludeAllButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        includeSelectedButton = new QPushButton(widget);
        includeSelectedButton->setObjectName(QString::fromUtf8("includeSelectedButton"));

        verticalLayout_2->addWidget(includeSelectedButton);

        excludeSelectedButton = new QPushButton(widget);
        excludeSelectedButton->setObjectName(QString::fromUtf8("excludeSelectedButton"));

        verticalLayout_2->addWidget(excludeSelectedButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_2->addWidget(widget);

        tabWidget->addTab(filterTab, QString());
        highlightTab = new QWidget();
        highlightTab->setObjectName(QString::fromUtf8("highlightTab"));
        verticalLayout_3 = new QVBoxLayout(highlightTab);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        highlightsTable = new QTableWidget(highlightTab);
        if (highlightsTable->columnCount() < 3)
            highlightsTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        highlightsTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        highlightsTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        highlightsTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        highlightsTable->setObjectName(QString::fromUtf8("highlightsTable"));
        highlightsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        highlightsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        highlightsTable->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        highlightsTable->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        highlightsTable->setWordWrap(false);
        highlightsTable->horizontalHeader()->setHighlightSections(false);
        highlightsTable->verticalHeader()->setVisible(false);
        highlightsTable->verticalHeader()->setHighlightSections(false);

        verticalLayout_3->addWidget(highlightsTable);

        widget_2 = new QWidget(highlightTab);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 3, -1, 3);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        addHighlightButton = new QPushButton(widget_2);
        addHighlightButton->setObjectName(QString::fromUtf8("addHighlightButton"));

        horizontalLayout->addWidget(addHighlightButton);

        removeHighlightButton = new QPushButton(widget_2);
        removeHighlightButton->setObjectName(QString::fromUtf8("removeHighlightButton"));

        horizontalLayout->addWidget(removeHighlightButton);


        verticalLayout_3->addWidget(widget_2);

        tabWidget->addTab(highlightTab, QString());

        verticalLayout->addWidget(tabWidget);

        dialogButtons = new QDialogButtonBox(MessageFilterDialog);
        dialogButtons->setObjectName(QString::fromUtf8("dialogButtons"));
        dialogButtons->setOrientation(Qt::Horizontal);
        dialogButtons->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(dialogButtons);

        QWidget::setTabOrder(tabWidget, findPane);
        QWidget::setTabOrder(findPane, filterListView);
        QWidget::setTabOrder(filterListView, otherMessagesCheckBox);
        QWidget::setTabOrder(otherMessagesCheckBox, includeAllButton);
        QWidget::setTabOrder(includeAllButton, excludeAllButton);
        QWidget::setTabOrder(excludeAllButton, includeSelectedButton);
        QWidget::setTabOrder(includeSelectedButton, excludeSelectedButton);
        QWidget::setTabOrder(excludeSelectedButton, dialogButtons);
        QWidget::setTabOrder(dialogButtons, highlightsTable);
        QWidget::setTabOrder(highlightsTable, addHighlightButton);
        QWidget::setTabOrder(addHighlightButton, removeHighlightButton);

        retranslateUi(MessageFilterDialog);
        QObject::connect(dialogButtons, SIGNAL(accepted()), MessageFilterDialog, SLOT(accept()));
        QObject::connect(dialogButtons, SIGNAL(rejected()), MessageFilterDialog, SLOT(reject()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MessageFilterDialog);
    } // setupUi

    void retranslateUi(QDialog *MessageFilterDialog)
    {
        MessageFilterDialog->setWindowTitle(QCoreApplication::translate("MessageFilterDialog", "Filter/Highlight Messages", nullptr));
#if QT_CONFIG(whatsthis)
        findPane->setWhatsThis(QCoreApplication::translate("MessageFilterDialog", "Type a full or partial message name to narrow down the list", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(whatsthis)
        filterListView->setWhatsThis(QCoreApplication::translate("MessageFilterDialog", "List of all applicable message types. Toggle checkbox to include or exclude.", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(whatsthis)
        otherMessagesCheckBox->setWhatsThis(QCoreApplication::translate("MessageFilterDialog", "Include/Exclude unknown messages (ones not in the list).", nullptr));
#endif // QT_CONFIG(whatsthis)
        otherMessagesCheckBox->setText(QCoreApplication::translate("MessageFilterDialog", "All Others", nullptr));
#if QT_CONFIG(whatsthis)
        includeAllButton->setWhatsThis(QCoreApplication::translate("MessageFilterDialog", "Click to include all message types (ticks all boxes in the list).", nullptr));
#endif // QT_CONFIG(whatsthis)
        includeAllButton->setText(QCoreApplication::translate("MessageFilterDialog", "I&nclude All", nullptr));
#if QT_CONFIG(whatsthis)
        excludeAllButton->setWhatsThis(QCoreApplication::translate("MessageFilterDialog", "Click to exclude all message types (unticks all boxes in the list).", nullptr));
#endif // QT_CONFIG(whatsthis)
        excludeAllButton->setText(QCoreApplication::translate("MessageFilterDialog", "E&xclude All", nullptr));
#if QT_CONFIG(whatsthis)
        includeSelectedButton->setWhatsThis(QCoreApplication::translate("MessageFilterDialog", "Click to include all message types that are selected in the list.", nullptr));
#endif // QT_CONFIG(whatsthis)
        includeSelectedButton->setText(QCoreApplication::translate("MessageFilterDialog", "&Include Selected", nullptr));
#if QT_CONFIG(whatsthis)
        excludeSelectedButton->setWhatsThis(QCoreApplication::translate("MessageFilterDialog", "Click to exclude all message types that are selected in the list.", nullptr));
#endif // QT_CONFIG(whatsthis)
        excludeSelectedButton->setText(QCoreApplication::translate("MessageFilterDialog", "&Exclude Selected", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(filterTab), QCoreApplication::translate("MessageFilterDialog", "Filter", nullptr));
        QTableWidgetItem *___qtablewidgetitem = highlightsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MessageFilterDialog", "Message", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = highlightsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MessageFilterDialog", "Text Colour", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = highlightsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MessageFilterDialog", "Back Colour", nullptr));
#if QT_CONFIG(whatsthis)
        highlightsTable->setWhatsThis(QCoreApplication::translate("MessageFilterDialog", "List of message types to highlight. Double click each colour to change it.", nullptr));
#endif // QT_CONFIG(whatsthis)
        addHighlightButton->setText(QCoreApplication::translate("MessageFilterDialog", "Add", nullptr));
        removeHighlightButton->setText(QCoreApplication::translate("MessageFilterDialog", "Remove", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(highlightTab), QCoreApplication::translate("MessageFilterDialog", "Highlight", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MessageFilterDialog: public Ui_MessageFilterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEFILTERDIALOG_H

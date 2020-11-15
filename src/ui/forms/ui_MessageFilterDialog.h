/********************************************************************************
** Form generated from reading UI file 'MessageFilterDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEFILTERDIALOG_H
#define UI_MESSAGEFILTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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
            MessageFilterDialog->setObjectName(QStringLiteral("MessageFilterDialog"));
        MessageFilterDialog->resize(495, 348);
        MessageFilterDialog->setMinimumSize(QSize(400, 300));
        verticalLayout = new QVBoxLayout(MessageFilterDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(MessageFilterDialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        filterTab = new QWidget();
        filterTab->setObjectName(QStringLiteral("filterTab"));
        horizontalLayout_2 = new QHBoxLayout(filterTab);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        widget_3 = new QWidget(filterTab);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        verticalLayout_4 = new QVBoxLayout(widget_3);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        findPane = new SearchInputPane(widget_3);
        findPane->setObjectName(QStringLiteral("findPane"));

        verticalLayout_4->addWidget(findPane);

        filterListView = new QListView(widget_3);
        filterListView->setObjectName(QStringLiteral("filterListView"));
        filterListView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        filterListView->setSelectionMode(QAbstractItemView::ExtendedSelection);
        filterListView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        filterListView->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        filterListView->setUniformItemSizes(true);

        verticalLayout_4->addWidget(filterListView);


        horizontalLayout_2->addWidget(widget_3);

        widget = new QWidget(filterTab);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(6, -1, 6, -1);
        otherMessagesCheckBox = new QCheckBox(widget);
        otherMessagesCheckBox->setObjectName(QStringLiteral("otherMessagesCheckBox"));

        verticalLayout_2->addWidget(otherMessagesCheckBox);

        includeAllButton = new QPushButton(widget);
        includeAllButton->setObjectName(QStringLiteral("includeAllButton"));

        verticalLayout_2->addWidget(includeAllButton);

        excludeAllButton = new QPushButton(widget);
        excludeAllButton->setObjectName(QStringLiteral("excludeAllButton"));

        verticalLayout_2->addWidget(excludeAllButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        includeSelectedButton = new QPushButton(widget);
        includeSelectedButton->setObjectName(QStringLiteral("includeSelectedButton"));

        verticalLayout_2->addWidget(includeSelectedButton);

        excludeSelectedButton = new QPushButton(widget);
        excludeSelectedButton->setObjectName(QStringLiteral("excludeSelectedButton"));

        verticalLayout_2->addWidget(excludeSelectedButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_2->addWidget(widget);

        tabWidget->addTab(filterTab, QString());
        highlightTab = new QWidget();
        highlightTab->setObjectName(QStringLiteral("highlightTab"));
        verticalLayout_3 = new QVBoxLayout(highlightTab);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        highlightsTable = new QTableWidget(highlightTab);
        if (highlightsTable->columnCount() < 3)
            highlightsTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        highlightsTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        highlightsTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        highlightsTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        highlightsTable->setObjectName(QStringLiteral("highlightsTable"));
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
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 3, -1, 3);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        addHighlightButton = new QPushButton(widget_2);
        addHighlightButton->setObjectName(QStringLiteral("addHighlightButton"));

        horizontalLayout->addWidget(addHighlightButton);

        removeHighlightButton = new QPushButton(widget_2);
        removeHighlightButton->setObjectName(QStringLiteral("removeHighlightButton"));

        horizontalLayout->addWidget(removeHighlightButton);


        verticalLayout_3->addWidget(widget_2);

        tabWidget->addTab(highlightTab, QString());

        verticalLayout->addWidget(tabWidget);

        dialogButtons = new QDialogButtonBox(MessageFilterDialog);
        dialogButtons->setObjectName(QStringLiteral("dialogButtons"));
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
        MessageFilterDialog->setWindowTitle(QApplication::translate("MessageFilterDialog", "Filter/Highlight Messages", 0));
#ifndef QT_NO_WHATSTHIS
        findPane->setWhatsThis(QApplication::translate("MessageFilterDialog", "Type a full or partial message name to narrow down the list", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        filterListView->setWhatsThis(QApplication::translate("MessageFilterDialog", "List of all applicable message types. Toggle checkbox to include or exclude.", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        otherMessagesCheckBox->setWhatsThis(QApplication::translate("MessageFilterDialog", "Include/Exclude unknown messages (ones not in the list).", 0));
#endif // QT_NO_WHATSTHIS
        otherMessagesCheckBox->setText(QApplication::translate("MessageFilterDialog", "All Others", 0));
#ifndef QT_NO_WHATSTHIS
        includeAllButton->setWhatsThis(QApplication::translate("MessageFilterDialog", "Click to include all message types (ticks all boxes in the list).", 0));
#endif // QT_NO_WHATSTHIS
        includeAllButton->setText(QApplication::translate("MessageFilterDialog", "I&nclude All", 0));
#ifndef QT_NO_WHATSTHIS
        excludeAllButton->setWhatsThis(QApplication::translate("MessageFilterDialog", "Click to exclude all message types (unticks all boxes in the list).", 0));
#endif // QT_NO_WHATSTHIS
        excludeAllButton->setText(QApplication::translate("MessageFilterDialog", "E&xclude All", 0));
#ifndef QT_NO_WHATSTHIS
        includeSelectedButton->setWhatsThis(QApplication::translate("MessageFilterDialog", "Click to include all message types that are selected in the list.", 0));
#endif // QT_NO_WHATSTHIS
        includeSelectedButton->setText(QApplication::translate("MessageFilterDialog", "&Include Selected", 0));
#ifndef QT_NO_WHATSTHIS
        excludeSelectedButton->setWhatsThis(QApplication::translate("MessageFilterDialog", "Click to exclude all message types that are selected in the list.", 0));
#endif // QT_NO_WHATSTHIS
        excludeSelectedButton->setText(QApplication::translate("MessageFilterDialog", "&Exclude Selected", 0));
        tabWidget->setTabText(tabWidget->indexOf(filterTab), QApplication::translate("MessageFilterDialog", "Filter", 0));
        QTableWidgetItem *___qtablewidgetitem = highlightsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MessageFilterDialog", "Message", 0));
        QTableWidgetItem *___qtablewidgetitem1 = highlightsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MessageFilterDialog", "Text Colour", 0));
        QTableWidgetItem *___qtablewidgetitem2 = highlightsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MessageFilterDialog", "Back Colour", 0));
#ifndef QT_NO_WHATSTHIS
        highlightsTable->setWhatsThis(QApplication::translate("MessageFilterDialog", "List of message types to highlight. Double click each colour to change it.", 0));
#endif // QT_NO_WHATSTHIS
        addHighlightButton->setText(QApplication::translate("MessageFilterDialog", "Add", 0));
        removeHighlightButton->setText(QApplication::translate("MessageFilterDialog", "Remove", 0));
        tabWidget->setTabText(tabWidget->indexOf(highlightTab), QApplication::translate("MessageFilterDialog", "Highlight", 0));
    } // retranslateUi

};

namespace Ui {
    class MessageFilterDialog: public Ui_MessageFilterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEFILTERDIALOG_H

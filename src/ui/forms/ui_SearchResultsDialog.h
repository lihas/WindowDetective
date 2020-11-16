/********************************************************************************
** Form generated from reading UI file 'SearchResultsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHRESULTSDIALOG_H
#define UI_SEARCHRESULTSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ui/custom_widgets/WindowTree.h"

QT_BEGIN_NAMESPACE

class Ui_SearchResultsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *criteriaLabel;
    WindowTree *windowList;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *repeatButton;
    QPushButton *closeButton;

    void setupUi(QDialog *SearchResultsDialog)
    {
        if (SearchResultsDialog->objectName().isEmpty())
            SearchResultsDialog->setObjectName(QString::fromUtf8("SearchResultsDialog"));
        SearchResultsDialog->resize(480, 380);
        verticalLayout = new QVBoxLayout(SearchResultsDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        criteriaLabel = new QLabel(SearchResultsDialog);
        criteriaLabel->setObjectName(QString::fromUtf8("criteriaLabel"));

        verticalLayout->addWidget(criteriaLabel);

        windowList = new WindowTree(SearchResultsDialog);
        windowList->setObjectName(QString::fromUtf8("windowList"));
        windowList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        windowList->setDragDropOverwriteMode(false);
        windowList->setSelectionBehavior(QAbstractItemView::SelectRows);
        windowList->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        windowList->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        windowList->setRootIsDecorated(false);
        windowList->header()->setStretchLastSection(false);

        verticalLayout->addWidget(windowList);

        widget = new QWidget(SearchResultsDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(3, 3, 3, 3);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        repeatButton = new QPushButton(widget);
        repeatButton->setObjectName(QString::fromUtf8("repeatButton"));

        horizontalLayout->addWidget(repeatButton);

        closeButton = new QPushButton(widget);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        horizontalLayout->addWidget(closeButton);


        verticalLayout->addWidget(widget);


        retranslateUi(SearchResultsDialog);

        QMetaObject::connectSlotsByName(SearchResultsDialog);
    } // setupUi

    void retranslateUi(QDialog *SearchResultsDialog)
    {
        SearchResultsDialog->setWindowTitle(QCoreApplication::translate("SearchResultsDialog", "Search Results", nullptr));
        criteriaLabel->setText(QCoreApplication::translate("SearchResultsDialog", "Search Criteria", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = windowList->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("SearchResultsDialog", "Window", nullptr));
#if QT_CONFIG(whatsthis)
        repeatButton->setWhatsThis(QCoreApplication::translate("SearchResultsDialog", "Re-runs this search, and updates the results.", nullptr));
#endif // QT_CONFIG(whatsthis)
        repeatButton->setText(QCoreApplication::translate("SearchResultsDialog", "&Repeat", nullptr));
        closeButton->setText(QCoreApplication::translate("SearchResultsDialog", "&Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchResultsDialog: public Ui_SearchResultsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHRESULTSDIALOG_H

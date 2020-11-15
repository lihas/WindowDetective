/********************************************************************************
** Form generated from reading UI file 'SearchResultsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHRESULTSDIALOG_H
#define UI_SEARCHRESULTSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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
            SearchResultsDialog->setObjectName(QStringLiteral("SearchResultsDialog"));
        SearchResultsDialog->resize(480, 380);
        verticalLayout = new QVBoxLayout(SearchResultsDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        criteriaLabel = new QLabel(SearchResultsDialog);
        criteriaLabel->setObjectName(QStringLiteral("criteriaLabel"));

        verticalLayout->addWidget(criteriaLabel);

        windowList = new WindowTree(SearchResultsDialog);
        windowList->setObjectName(QStringLiteral("windowList"));
        windowList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        windowList->setDragDropOverwriteMode(false);
        windowList->setSelectionBehavior(QAbstractItemView::SelectRows);
        windowList->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        windowList->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        windowList->setRootIsDecorated(false);
        windowList->header()->setStretchLastSection(false);

        verticalLayout->addWidget(windowList);

        widget = new QWidget(SearchResultsDialog);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(3, 3, 3, 3);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        repeatButton = new QPushButton(widget);
        repeatButton->setObjectName(QStringLiteral("repeatButton"));

        horizontalLayout->addWidget(repeatButton);

        closeButton = new QPushButton(widget);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        horizontalLayout->addWidget(closeButton);


        verticalLayout->addWidget(widget);


        retranslateUi(SearchResultsDialog);

        QMetaObject::connectSlotsByName(SearchResultsDialog);
    } // setupUi

    void retranslateUi(QDialog *SearchResultsDialog)
    {
        SearchResultsDialog->setWindowTitle(QApplication::translate("SearchResultsDialog", "Search Results", 0));
        criteriaLabel->setText(QApplication::translate("SearchResultsDialog", "Search Criteria", 0));
        QTreeWidgetItem *___qtreewidgetitem = windowList->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("SearchResultsDialog", "Window", 0));
#ifndef QT_NO_WHATSTHIS
        repeatButton->setWhatsThis(QApplication::translate("SearchResultsDialog", "Re-runs this search, and updates the results.", 0));
#endif // QT_NO_WHATSTHIS
        repeatButton->setText(QApplication::translate("SearchResultsDialog", "&Repeat", 0));
        closeButton->setText(QApplication::translate("SearchResultsDialog", "&Close", 0));
    } // retranslateUi

};

namespace Ui {
    class SearchResultsDialog: public Ui_SearchResultsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHRESULTSDIALOG_H

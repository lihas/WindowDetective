/********************************************************************************
** Form generated from reading UI file 'SystemColoursPane.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMCOLOURSPANE_H
#define UI_SYSTEMCOLOURSPANE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SystemColoursPane
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *resetColoursButton;
    QTableView *table;

    void setupUi(QWidget *SystemColoursPane)
    {
        if (SystemColoursPane->objectName().isEmpty())
            SystemColoursPane->setObjectName(QStringLiteral("SystemColoursPane"));
        SystemColoursPane->resize(500, 400);
        verticalLayout = new QVBoxLayout(SystemColoursPane);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(SystemColoursPane);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(6, 6, 6, 3);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setWordWrap(true);

        horizontalLayout->addWidget(label);

        resetColoursButton = new QPushButton(widget);
        resetColoursButton->setObjectName(QStringLiteral("resetColoursButton"));
        resetColoursButton->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(resetColoursButton);


        verticalLayout->addWidget(widget);

        table = new QTableView(SystemColoursPane);
        table->setObjectName(QStringLiteral("table"));
        table->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
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


        retranslateUi(SystemColoursPane);

        QMetaObject::connectSlotsByName(SystemColoursPane);
    } // setupUi

    void retranslateUi(QWidget *SystemColoursPane)
    {
        label->setText(QApplication::translate("SystemColoursPane", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Double-click a colour to change it.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Note: The Operating System will inform all windows of this change (by sending a WM_SYSCOLORCHANGE message). However, this change only affects the current session. The new colors are not saved when the system terminates.</span></p></body></html>", 0));
#ifndef QT_NO_WHATSTHIS
        resetColoursButton->setWhatsThis(QApplication::translate("SystemColoursPane", "Resets the colours to what they were when this dialog was opened.", 0));
#endif // QT_NO_WHATSTHIS
        resetColoursButton->setText(QApplication::translate("SystemColoursPane", "Reset", 0));
        Q_UNUSED(SystemColoursPane);
    } // retranslateUi

};

namespace Ui {
    class SystemColoursPane: public Ui_SystemColoursPane {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMCOLOURSPANE_H

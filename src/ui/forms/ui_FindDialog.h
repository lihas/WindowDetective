/********************************************************************************
** Form generated from reading UI file 'FindDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDDIALOG_H
#define UI_FINDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ui/custom_widgets/CustomComboBoxes.h"
#include "ui/custom_widgets/HexSpinBox.h"

QT_BEGIN_NAMESPACE

class Ui_FindDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *basicTab;
    QFormLayout *formLayout;
    QRadioButton *rbWindowText;
    QRadioButton *rbHandle;
    QRadioButton *rbWindowClass;
    WindowClassComboBox *cbWindowClass;
    HexSpinBox *spnHandle;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QLineEdit *txtWindowText;
    QCheckBox *chCaseSensitive;
    QCheckBox *chUseRegex;
    QSpacerItem *horizontalSpacer;
    QWidget *advancedTab;
    QGridLayout *gridLayout_2;
    QScrollArea *scrollArea;
    QWidget *criteriaWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *booleanRelationPanel;
    QVBoxLayout *booleanRelationPanelLayout;
    QWidget *padding;
    QSpacerItem *booleanRelationSpacer;
    QWidget *itemsPanel;
    QVBoxLayout *itemsPanelLayout;
    QSpacerItem *itemsSpacer;
    QDialogButtonBox *dialogButtons;

    void setupUi(QDialog *FindDialog)
    {
        if (FindDialog->objectName().isEmpty())
            FindDialog->setObjectName(QString::fromUtf8("FindDialog"));
        FindDialog->resize(477, 328);
        FindDialog->setMinimumSize(QSize(300, 200));
        verticalLayout = new QVBoxLayout(FindDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        tabWidget = new QTabWidget(FindDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        basicTab = new QWidget();
        basicTab->setObjectName(QString::fromUtf8("basicTab"));
        basicTab->setAutoFillBackground(true);
        formLayout = new QFormLayout(basicTab);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setVerticalSpacing(9);
        rbWindowText = new QRadioButton(basicTab);
        rbWindowText->setObjectName(QString::fromUtf8("rbWindowText"));

        formLayout->setWidget(0, QFormLayout::LabelRole, rbWindowText);

        rbHandle = new QRadioButton(basicTab);
        rbHandle->setObjectName(QString::fromUtf8("rbHandle"));

        formLayout->setWidget(1, QFormLayout::LabelRole, rbHandle);

        rbWindowClass = new QRadioButton(basicTab);
        rbWindowClass->setObjectName(QString::fromUtf8("rbWindowClass"));

        formLayout->setWidget(2, QFormLayout::LabelRole, rbWindowClass);

        cbWindowClass = new WindowClassComboBox(basicTab);
        cbWindowClass->setObjectName(QString::fromUtf8("cbWindowClass"));
        cbWindowClass->setEditable(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, cbWindowClass);

        spnHandle = new HexSpinBox(basicTab);
        spnHandle->setObjectName(QString::fromUtf8("spnHandle"));
        spnHandle->setMaximumSize(QSize(150, 16777215));
        spnHandle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spnHandle->setButtonSymbols(QAbstractSpinBox::NoButtons);

        formLayout->setWidget(1, QFormLayout::FieldRole, spnHandle);

        widget_2 = new QWidget(basicTab);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        txtWindowText = new QLineEdit(widget_2);
        txtWindowText->setObjectName(QString::fromUtf8("txtWindowText"));

        gridLayout->addWidget(txtWindowText, 0, 0, 1, 3);

        chCaseSensitive = new QCheckBox(widget_2);
        chCaseSensitive->setObjectName(QString::fromUtf8("chCaseSensitive"));

        gridLayout->addWidget(chCaseSensitive, 1, 0, 1, 1);

        chUseRegex = new QCheckBox(widget_2);
        chUseRegex->setObjectName(QString::fromUtf8("chUseRegex"));

        gridLayout->addWidget(chUseRegex, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);


        formLayout->setWidget(0, QFormLayout::FieldRole, widget_2);

        tabWidget->addTab(basicTab, QString());
        advancedTab = new QWidget();
        advancedTab->setObjectName(QString::fromUtf8("advancedTab"));
        advancedTab->setAutoFillBackground(true);
        gridLayout_2 = new QGridLayout(advancedTab);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(advancedTab);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setWidgetResizable(true);
        criteriaWidget = new QWidget();
        criteriaWidget->setObjectName(QString::fromUtf8("criteriaWidget"));
        criteriaWidget->setGeometry(QRect(0, 0, 98, 33));
        horizontalLayout = new QHBoxLayout(criteriaWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        booleanRelationPanel = new QWidget(criteriaWidget);
        booleanRelationPanel->setObjectName(QString::fromUtf8("booleanRelationPanel"));
        booleanRelationPanel->setMinimumSize(QSize(60, 0));
        booleanRelationPanel->setMaximumSize(QSize(60, 16777215));
        booleanRelationPanelLayout = new QVBoxLayout(booleanRelationPanel);
        booleanRelationPanelLayout->setSpacing(7);
        booleanRelationPanelLayout->setObjectName(QString::fromUtf8("booleanRelationPanelLayout"));
        booleanRelationPanelLayout->setContentsMargins(3, 3, 3, 3);
        padding = new QWidget(booleanRelationPanel);
        padding->setObjectName(QString::fromUtf8("padding"));
        padding->setMinimumSize(QSize(0, 20));
        padding->setMaximumSize(QSize(16777215, 20));

        booleanRelationPanelLayout->addWidget(padding);

        booleanRelationSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        booleanRelationPanelLayout->addItem(booleanRelationSpacer);


        horizontalLayout->addWidget(booleanRelationPanel);

        itemsPanel = new QWidget(criteriaWidget);
        itemsPanel->setObjectName(QString::fromUtf8("itemsPanel"));
        itemsPanelLayout = new QVBoxLayout(itemsPanel);
        itemsPanelLayout->setSpacing(7);
        itemsPanelLayout->setObjectName(QString::fromUtf8("itemsPanelLayout"));
        itemsPanelLayout->setContentsMargins(3, 5, 3, 3);
        itemsSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        itemsPanelLayout->addItem(itemsSpacer);


        horizontalLayout->addWidget(itemsPanel);

        scrollArea->setWidget(criteriaWidget);

        gridLayout_2->addWidget(scrollArea, 0, 0, 1, 1);

        tabWidget->addTab(advancedTab, QString());

        verticalLayout->addWidget(tabWidget);

        dialogButtons = new QDialogButtonBox(FindDialog);
        dialogButtons->setObjectName(QString::fromUtf8("dialogButtons"));
        dialogButtons->setOrientation(Qt::Horizontal);
        dialogButtons->setStandardButtons(QDialogButtonBox::Close);

        verticalLayout->addWidget(dialogButtons);

        QWidget::setTabOrder(tabWidget, rbWindowText);
        QWidget::setTabOrder(rbWindowText, txtWindowText);
        QWidget::setTabOrder(txtWindowText, chCaseSensitive);
        QWidget::setTabOrder(chCaseSensitive, chUseRegex);
        QWidget::setTabOrder(chUseRegex, rbHandle);
        QWidget::setTabOrder(rbHandle, spnHandle);
        QWidget::setTabOrder(spnHandle, rbWindowClass);
        QWidget::setTabOrder(rbWindowClass, cbWindowClass);

        retranslateUi(FindDialog);
        QObject::connect(dialogButtons, SIGNAL(accepted()), FindDialog, SLOT(accept()));
        QObject::connect(dialogButtons, SIGNAL(rejected()), FindDialog, SLOT(reject()));
        QObject::connect(rbWindowText, SIGNAL(clicked()), txtWindowText, SLOT(setFocus()));
        QObject::connect(rbHandle, SIGNAL(clicked()), spnHandle, SLOT(setFocus()));
        QObject::connect(rbWindowClass, SIGNAL(clicked()), cbWindowClass, SLOT(setFocus()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FindDialog);
    } // setupUi

    void retranslateUi(QDialog *FindDialog)
    {
        FindDialog->setWindowTitle(QCoreApplication::translate("FindDialog", "Find", nullptr));
#if QT_CONFIG(whatsthis)
        rbWindowText->setWhatsThis(QCoreApplication::translate("FindDialog", "Select to use text search.", nullptr));
#endif // QT_CONFIG(whatsthis)
        rbWindowText->setText(QCoreApplication::translate("FindDialog", "&Text:", nullptr));
#if QT_CONFIG(whatsthis)
        rbHandle->setWhatsThis(QCoreApplication::translate("FindDialog", "Select to use handle search.", nullptr));
#endif // QT_CONFIG(whatsthis)
        rbHandle->setText(QCoreApplication::translate("FindDialog", "&Handle:", nullptr));
#if QT_CONFIG(whatsthis)
        rbWindowClass->setWhatsThis(QCoreApplication::translate("FindDialog", "Select to use class search.", nullptr));
#endif // QT_CONFIG(whatsthis)
        rbWindowClass->setText(QCoreApplication::translate("FindDialog", "&Class:", nullptr));
#if QT_CONFIG(whatsthis)
        cbWindowClass->setWhatsThis(QCoreApplication::translate("FindDialog", "Search for window class name.", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(whatsthis)
        spnHandle->setWhatsThis(QCoreApplication::translate("FindDialog", "Search for window handle (HWND).", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(whatsthis)
        txtWindowText->setWhatsThis(QCoreApplication::translate("FindDialog", "Search for window text. Enter simple text or regular expression.", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(whatsthis)
        chCaseSensitive->setWhatsThis(QCoreApplication::translate("FindDialog", "Tick to enable case sensitive search.", nullptr));
#endif // QT_CONFIG(whatsthis)
        chCaseSensitive->setText(QCoreApplication::translate("FindDialog", "Case &Sensitive", nullptr));
#if QT_CONFIG(whatsthis)
        chUseRegex->setWhatsThis(QCoreApplication::translate("FindDialog", "Tick to enable regular expression search.", nullptr));
#endif // QT_CONFIG(whatsthis)
        chUseRegex->setText(QCoreApplication::translate("FindDialog", "&Regular Expression", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(basicTab), QCoreApplication::translate("FindDialog", "Basic", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(advancedTab), QCoreApplication::translate("FindDialog", "Advanced", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindDialog: public Ui_FindDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDDIALOG_H

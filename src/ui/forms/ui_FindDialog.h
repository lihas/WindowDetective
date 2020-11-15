/********************************************************************************
** Form generated from reading UI file 'FindDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDDIALOG_H
#define UI_FINDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
            FindDialog->setObjectName(QStringLiteral("FindDialog"));
        FindDialog->resize(477, 328);
        FindDialog->setMinimumSize(QSize(300, 200));
        verticalLayout = new QVBoxLayout(FindDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        tabWidget = new QTabWidget(FindDialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        basicTab = new QWidget();
        basicTab->setObjectName(QStringLiteral("basicTab"));
        basicTab->setAutoFillBackground(true);
        formLayout = new QFormLayout(basicTab);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setVerticalSpacing(9);
        rbWindowText = new QRadioButton(basicTab);
        rbWindowText->setObjectName(QStringLiteral("rbWindowText"));

        formLayout->setWidget(0, QFormLayout::LabelRole, rbWindowText);

        rbHandle = new QRadioButton(basicTab);
        rbHandle->setObjectName(QStringLiteral("rbHandle"));

        formLayout->setWidget(1, QFormLayout::LabelRole, rbHandle);

        rbWindowClass = new QRadioButton(basicTab);
        rbWindowClass->setObjectName(QStringLiteral("rbWindowClass"));

        formLayout->setWidget(2, QFormLayout::LabelRole, rbWindowClass);

        cbWindowClass = new WindowClassComboBox(basicTab);
        cbWindowClass->setObjectName(QStringLiteral("cbWindowClass"));
        cbWindowClass->setEditable(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, cbWindowClass);

        spnHandle = new HexSpinBox(basicTab);
        spnHandle->setObjectName(QStringLiteral("spnHandle"));
        spnHandle->setMaximumSize(QSize(150, 16777215));
        spnHandle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spnHandle->setButtonSymbols(QAbstractSpinBox::NoButtons);

        formLayout->setWidget(1, QFormLayout::FieldRole, spnHandle);

        widget_2 = new QWidget(basicTab);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        txtWindowText = new QLineEdit(widget_2);
        txtWindowText->setObjectName(QStringLiteral("txtWindowText"));

        gridLayout->addWidget(txtWindowText, 0, 0, 1, 3);

        chCaseSensitive = new QCheckBox(widget_2);
        chCaseSensitive->setObjectName(QStringLiteral("chCaseSensitive"));

        gridLayout->addWidget(chCaseSensitive, 1, 0, 1, 1);

        chUseRegex = new QCheckBox(widget_2);
        chUseRegex->setObjectName(QStringLiteral("chUseRegex"));

        gridLayout->addWidget(chUseRegex, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);


        formLayout->setWidget(0, QFormLayout::FieldRole, widget_2);

        tabWidget->addTab(basicTab, QString());
        advancedTab = new QWidget();
        advancedTab->setObjectName(QStringLiteral("advancedTab"));
        advancedTab->setAutoFillBackground(true);
        gridLayout_2 = new QGridLayout(advancedTab);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(advancedTab);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setWidgetResizable(true);
        criteriaWidget = new QWidget();
        criteriaWidget->setObjectName(QStringLiteral("criteriaWidget"));
        criteriaWidget->setGeometry(QRect(0, 0, 98, 33));
        horizontalLayout = new QHBoxLayout(criteriaWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        booleanRelationPanel = new QWidget(criteriaWidget);
        booleanRelationPanel->setObjectName(QStringLiteral("booleanRelationPanel"));
        booleanRelationPanel->setMinimumSize(QSize(60, 0));
        booleanRelationPanel->setMaximumSize(QSize(60, 16777215));
        booleanRelationPanelLayout = new QVBoxLayout(booleanRelationPanel);
        booleanRelationPanelLayout->setSpacing(7);
        booleanRelationPanelLayout->setObjectName(QStringLiteral("booleanRelationPanelLayout"));
        booleanRelationPanelLayout->setContentsMargins(3, 3, 3, 3);
        padding = new QWidget(booleanRelationPanel);
        padding->setObjectName(QStringLiteral("padding"));
        padding->setMinimumSize(QSize(0, 20));
        padding->setMaximumSize(QSize(16777215, 20));

        booleanRelationPanelLayout->addWidget(padding);

        booleanRelationSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        booleanRelationPanelLayout->addItem(booleanRelationSpacer);


        horizontalLayout->addWidget(booleanRelationPanel);

        itemsPanel = new QWidget(criteriaWidget);
        itemsPanel->setObjectName(QStringLiteral("itemsPanel"));
        itemsPanelLayout = new QVBoxLayout(itemsPanel);
        itemsPanelLayout->setSpacing(7);
        itemsPanelLayout->setObjectName(QStringLiteral("itemsPanelLayout"));
        itemsPanelLayout->setContentsMargins(3, 5, 3, 3);
        itemsSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        itemsPanelLayout->addItem(itemsSpacer);


        horizontalLayout->addWidget(itemsPanel);

        scrollArea->setWidget(criteriaWidget);

        gridLayout_2->addWidget(scrollArea, 0, 0, 1, 1);

        tabWidget->addTab(advancedTab, QString());

        verticalLayout->addWidget(tabWidget);

        dialogButtons = new QDialogButtonBox(FindDialog);
        dialogButtons->setObjectName(QStringLiteral("dialogButtons"));
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
        FindDialog->setWindowTitle(QApplication::translate("FindDialog", "Find", 0));
#ifndef QT_NO_WHATSTHIS
        rbWindowText->setWhatsThis(QApplication::translate("FindDialog", "Select to use text search.", 0));
#endif // QT_NO_WHATSTHIS
        rbWindowText->setText(QApplication::translate("FindDialog", "&Text:", 0));
#ifndef QT_NO_WHATSTHIS
        rbHandle->setWhatsThis(QApplication::translate("FindDialog", "Select to use handle search.", 0));
#endif // QT_NO_WHATSTHIS
        rbHandle->setText(QApplication::translate("FindDialog", "&Handle:", 0));
#ifndef QT_NO_WHATSTHIS
        rbWindowClass->setWhatsThis(QApplication::translate("FindDialog", "Select to use class search.", 0));
#endif // QT_NO_WHATSTHIS
        rbWindowClass->setText(QApplication::translate("FindDialog", "&Class:", 0));
#ifndef QT_NO_WHATSTHIS
        cbWindowClass->setWhatsThis(QApplication::translate("FindDialog", "Search for window class name.", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        spnHandle->setWhatsThis(QApplication::translate("FindDialog", "Search for window handle (HWND).", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        txtWindowText->setWhatsThis(QApplication::translate("FindDialog", "Search for window text. Enter simple text or regular expression.", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        chCaseSensitive->setWhatsThis(QApplication::translate("FindDialog", "Tick to enable case sensitive search.", 0));
#endif // QT_NO_WHATSTHIS
        chCaseSensitive->setText(QApplication::translate("FindDialog", "Case &Sensitive", 0));
#ifndef QT_NO_WHATSTHIS
        chUseRegex->setWhatsThis(QApplication::translate("FindDialog", "Tick to enable regular expression search.", 0));
#endif // QT_NO_WHATSTHIS
        chUseRegex->setText(QApplication::translate("FindDialog", "&Regular Expression", 0));
        tabWidget->setTabText(tabWidget->indexOf(basicTab), QApplication::translate("FindDialog", "Basic", 0));
        tabWidget->setTabText(tabWidget->indexOf(advancedTab), QApplication::translate("FindDialog", "Advanced", 0));
    } // retranslateUi

};

namespace Ui {
    class FindDialog: public Ui_FindDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDDIALOG_H

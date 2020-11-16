/********************************************************************************
** Form generated from reading UI file 'SetPropertiesDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETPROPERTIESDIALOG_H
#define UI_SETPROPERTIESDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ui/custom_widgets/HexSpinBox.h"

QT_BEGIN_NAMESPACE

class Ui_SetPropertiesDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *generalTab;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_2;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QLineEdit *txtWindowText;
    QWidget *widget_3;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLineEdit *txtDimensions;
    QLabel *label_3;
    QLineEdit *txtPos;
    QLabel *label_4;
    QLineEdit *txtSize;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *chVisible;
    QCheckBox *chEnabled;
    QCheckBox *chAlwaysOnTop;
    QSpacerItem *verticalSpacer;
    QWidget *stylesTab;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_5;
    QGridLayout *gridLayout_5;
    QLabel *label_5;
    QLabel *label_6;
    HexSpinBox *spnStyleBits;
    HexSpinBox *spnExStyleBits;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *stylesList;
    QPlainTextEdit *txtStyleDesc;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *setButton;
    QPushButton *closeButton;

    void setupUi(QDialog *SetPropertiesDialog)
    {
        if (SetPropertiesDialog->objectName().isEmpty())
            SetPropertiesDialog->setObjectName(QString::fromUtf8("SetPropertiesDialog"));
        SetPropertiesDialog->setWindowModality(Qt::ApplicationModal);
        SetPropertiesDialog->resize(425, 313);
        SetPropertiesDialog->setMinimumSize(QSize(400, 300));
        verticalLayout = new QVBoxLayout(SetPropertiesDialog);
        verticalLayout->setSpacing(3);
        verticalLayout->setContentsMargins(3, 3, 3, 3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(SetPropertiesDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        generalTab = new QWidget();
        generalTab->setObjectName(QString::fromUtf8("generalTab"));
        generalTab->setAutoFillBackground(true);
        verticalLayout_2 = new QVBoxLayout(generalTab);
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget_2 = new QWidget(generalTab);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout_3 = new QGridLayout(widget_2);
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        txtWindowText = new QLineEdit(widget_2);
        txtWindowText->setObjectName(QString::fromUtf8("txtWindowText"));

        gridLayout_3->addWidget(txtWindowText, 0, 1, 1, 1);


        verticalLayout_2->addWidget(widget_2);

        widget_3 = new QWidget(generalTab);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMaximumSize(QSize(300, 16777215));
        gridLayout_2 = new QGridLayout(widget_3);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        txtDimensions = new QLineEdit(widget_3);
        txtDimensions->setObjectName(QString::fromUtf8("txtDimensions"));

        gridLayout_2->addWidget(txtDimensions, 0, 1, 1, 3);

        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        txtPos = new QLineEdit(widget_3);
        txtPos->setObjectName(QString::fromUtf8("txtPos"));

        gridLayout_2->addWidget(txtPos, 1, 1, 1, 1);

        label_4 = new QLabel(widget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_4, 1, 2, 1, 1);

        txtSize = new QLineEdit(widget_3);
        txtSize->setObjectName(QString::fromUtf8("txtSize"));

        gridLayout_2->addWidget(txtSize, 1, 3, 1, 1);


        verticalLayout_2->addWidget(widget_3);

        widget_4 = new QWidget(generalTab);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        verticalLayout_4 = new QVBoxLayout(widget_4);
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        chVisible = new QCheckBox(widget_4);
        chVisible->setObjectName(QString::fromUtf8("chVisible"));

        verticalLayout_4->addWidget(chVisible);

        chEnabled = new QCheckBox(widget_4);
        chEnabled->setObjectName(QString::fromUtf8("chEnabled"));

        verticalLayout_4->addWidget(chEnabled);

        chAlwaysOnTop = new QCheckBox(widget_4);
        chAlwaysOnTop->setObjectName(QString::fromUtf8("chAlwaysOnTop"));

        verticalLayout_4->addWidget(chAlwaysOnTop);


        verticalLayout_2->addWidget(widget_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        tabWidget->addTab(generalTab, QString());
        stylesTab = new QWidget();
        stylesTab->setObjectName(QString::fromUtf8("stylesTab"));
        stylesTab->setAutoFillBackground(true);
        verticalLayout_3 = new QVBoxLayout(stylesTab);
        verticalLayout_3->setContentsMargins(3, 3, 3, 3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget_5 = new QWidget(stylesTab);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        gridLayout_5 = new QGridLayout(widget_5);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(3, 0, 3, 0);
        label_5 = new QLabel(widget_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_5->addWidget(label_5, 0, 0, 1, 1);

        label_6 = new QLabel(widget_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_5->addWidget(label_6, 1, 0, 1, 1);

        spnStyleBits = new HexSpinBox(widget_5);
        spnStyleBits->setObjectName(QString::fromUtf8("spnStyleBits"));
        spnStyleBits->setMinimumSize(QSize(100, 0));
        spnStyleBits->setMaximumSize(QSize(200, 16777215));
        spnStyleBits->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spnStyleBits->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_5->addWidget(spnStyleBits, 0, 1, 1, 1);

        spnExStyleBits = new HexSpinBox(widget_5);
        spnExStyleBits->setObjectName(QString::fromUtf8("spnExStyleBits"));
        spnExStyleBits->setMinimumSize(QSize(100, 0));
        spnExStyleBits->setMaximumSize(QSize(200, 16777215));
        spnExStyleBits->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spnExStyleBits->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_5->addWidget(spnExStyleBits, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_2, 0, 2, 1, 1);


        verticalLayout_3->addWidget(widget_5);

        widget_6 = new QWidget(stylesTab);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_2 = new QHBoxLayout(widget_6);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        stylesList = new QListWidget(widget_6);
        stylesList->setObjectName(QString::fromUtf8("stylesList"));
        stylesList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        stylesList->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        stylesList->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        stylesList->setUniformItemSizes(true);

        horizontalLayout_2->addWidget(stylesList);

        txtStyleDesc = new QPlainTextEdit(widget_6);
        txtStyleDesc->setObjectName(QString::fromUtf8("txtStyleDesc"));
        txtStyleDesc->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        txtStyleDesc->setUndoRedoEnabled(false);
        txtStyleDesc->setReadOnly(true);
        txtStyleDesc->setTextInteractionFlags(Qt::NoTextInteraction);

        horizontalLayout_2->addWidget(txtStyleDesc);

        horizontalLayout_2->setStretch(0, 20);
        horizontalLayout_2->setStretch(1, 10);

        verticalLayout_3->addWidget(widget_6);

        tabWidget->addTab(stylesTab, QString());

        verticalLayout->addWidget(tabWidget);

        widget = new QWidget(SetPropertiesDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 3, -1, 3);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        setButton = new QPushButton(widget);
        setButton->setObjectName(QString::fromUtf8("setButton"));

        horizontalLayout->addWidget(setButton);

        closeButton = new QPushButton(widget);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        horizontalLayout->addWidget(closeButton);


        verticalLayout->addWidget(widget);

        QWidget::setTabOrder(tabWidget, txtWindowText);
        QWidget::setTabOrder(txtWindowText, txtDimensions);
        QWidget::setTabOrder(txtDimensions, txtPos);
        QWidget::setTabOrder(txtPos, txtSize);
        QWidget::setTabOrder(txtSize, chVisible);
        QWidget::setTabOrder(chVisible, chEnabled);
        QWidget::setTabOrder(chEnabled, chAlwaysOnTop);
        QWidget::setTabOrder(chAlwaysOnTop, setButton);
        QWidget::setTabOrder(setButton, closeButton);
        QWidget::setTabOrder(closeButton, spnStyleBits);
        QWidget::setTabOrder(spnStyleBits, spnExStyleBits);
        QWidget::setTabOrder(spnExStyleBits, stylesList);
        QWidget::setTabOrder(stylesList, txtStyleDesc);

        retranslateUi(SetPropertiesDialog);
        QObject::connect(closeButton, SIGNAL(clicked()), SetPropertiesDialog, SLOT(close()));

        tabWidget->setCurrentIndex(1);
        setButton->setDefault(true);


        QMetaObject::connectSlotsByName(SetPropertiesDialog);
    } // setupUi

    void retranslateUi(QDialog *SetPropertiesDialog)
    {
        SetPropertiesDialog->setWindowTitle(QCoreApplication::translate("SetPropertiesDialog", "Set Properties [*]", nullptr));
        label->setText(QCoreApplication::translate("SetPropertiesDialog", "Text:", nullptr));
        label_2->setText(QCoreApplication::translate("SetPropertiesDialog", "Dimensions:", nullptr));
        label_3->setText(QCoreApplication::translate("SetPropertiesDialog", "Pos:", nullptr));
        label_4->setText(QCoreApplication::translate("SetPropertiesDialog", "Size:", nullptr));
        chVisible->setText(QCoreApplication::translate("SetPropertiesDialog", "Visible", nullptr));
        chEnabled->setText(QCoreApplication::translate("SetPropertiesDialog", "Enabled", nullptr));
        chAlwaysOnTop->setText(QCoreApplication::translate("SetPropertiesDialog", "Always on top", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(generalTab), QCoreApplication::translate("SetPropertiesDialog", "General", nullptr));
        label_5->setText(QCoreApplication::translate("SetPropertiesDialog", "Style bits:", nullptr));
        label_6->setText(QCoreApplication::translate("SetPropertiesDialog", "Extended Style bits:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(stylesTab), QCoreApplication::translate("SetPropertiesDialog", "Styles", nullptr));
        setButton->setText(QCoreApplication::translate("SetPropertiesDialog", "&Set", nullptr));
        closeButton->setText(QCoreApplication::translate("SetPropertiesDialog", "&Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SetPropertiesDialog: public Ui_SetPropertiesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETPROPERTIESDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'PreferencesDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREFERENCESDIALOG_H
#define UI_PREFERENCESDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ui/custom_widgets/ColourButton.h"

QT_BEGIN_NAMESPACE

class Ui_PreferencesDialog
{
public:
    QAction *actnRestoreDefaults;
    QAction *actnExportSettings;
    QAction *actnImportSettings;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaContents;
    QGridLayout *gridLayout_4;
    QStackedWidget *pages;
    QWidget *generalPage;
    QFormLayout *formLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QRadioButton *rbStandardRegex;
    QRadioButton *rbWildcardRegex;
    QRadioButton *rbWildcardUnixRegex;
    QGroupBox *groupBox_11;
    QVBoxLayout *verticalLayout_13;
    QCheckBox *chStayOnTop;
    QWidget *windowTreePage;
    QFormLayout *formLayout_5;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_16;
    QWidget *widget_11;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_15;
    QSpinBox *spnChangeDuration;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *groupBox_8;
    QHBoxLayout *horizontalLayout_5;
    QWidget *widget_12;
    QGridLayout *gridLayout_6;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_17;
    ColourButton *btnCreatedColour1;
    ColourButton *btnCreatedColour2;
    QLabel *label_18;
    ColourButton *btnDestroyedColour1;
    ColourButton *btnDestroyedColour2;
    QLabel *label_22;
    ColourButton *btnChangedColour1;
    ColourButton *btnChangedColour2;
    QLabel *label_21;
    QGroupBox *groupBox_9;
    QVBoxLayout *verticalLayout_12;
    QCheckBox *chGreyHiddenWindows;
    QGroupBox *groupBox_12;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *chOpenPropertiesOnSelect;
    QWidget *pickerPage;
    QFormLayout *formLayout_4;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_7;
    QWidget *widget_6;
    QGridLayout *gridLayout_3;
    QCheckBox *chWindowClass;
    QCheckBox *chWindowHandle;
    QCheckBox *chWindowText;
    QCheckBox *chWindowDimensions;
    QCheckBox *chWindowPosition;
    QCheckBox *chWindowSize;
    QCheckBox *chParentHandle;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QWidget *widget_4;
    QGridLayout *gridLayout_2;
    QRadioButton *rbFilled;
    QRadioButton *rbBorder;
    QLabel *label_4;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_10;
    QSpinBox *spnThickness;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_5;
    QGridLayout *gridLayout;
    ColourButton *btnHighlighterColour;
    QSlider *slHighlighterTransparency;
    QLabel *label_2;
    QLabel *label_6;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_9;
    QLabel *label_8;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_5;
    QCheckBox *chPickTransparent;
    QCheckBox *chHideWhilePicking;
    QWidget *loggingPage;
    QFormLayout *formLayout_2;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout_3;
    QCheckBox *chLogToFile;
    QLabel *label_11;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *txtLogFolder;
    QPushButton *btnChooseFolder;
    QGroupBox *groupBox_10;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_23;
    QCheckBox *chEnableBalloon;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *settingsButton;
    QDialogButtonBox *dialogButtons;

    void setupUi(QDialog *PreferencesDialog)
    {
        if (PreferencesDialog->objectName().isEmpty())
            PreferencesDialog->setObjectName(QStringLiteral("PreferencesDialog"));
        PreferencesDialog->resize(608, 457);
        PreferencesDialog->setMinimumSize(QSize(500, 400));
        actnRestoreDefaults = new QAction(PreferencesDialog);
        actnRestoreDefaults->setObjectName(QStringLiteral("actnRestoreDefaults"));
        actnExportSettings = new QAction(PreferencesDialog);
        actnExportSettings->setObjectName(QStringLiteral("actnExportSettings"));
        actnImportSettings = new QAction(PreferencesDialog);
        actnImportSettings->setObjectName(QStringLiteral("actnImportSettings"));
        verticalLayout = new QVBoxLayout(PreferencesDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(PreferencesDialog);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(4);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(4, 4, 4, 4);
        listWidget = new QListWidget(widget);
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/pref_general.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setTextAlignment(Qt::AlignHCenter|Qt::AlignBottom);
        __qlistwidgetitem->setIcon(icon);
        __qlistwidgetitem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/pref_window_tree.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget);
        __qlistwidgetitem1->setTextAlignment(Qt::AlignHCenter|Qt::AlignBottom);
        __qlistwidgetitem1->setIcon(icon1);
        __qlistwidgetitem1->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/pref_picker.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(listWidget);
        __qlistwidgetitem2->setTextAlignment(Qt::AlignHCenter|Qt::AlignBottom);
        __qlistwidgetitem2->setIcon(icon2);
        __qlistwidgetitem2->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/img/pref_log.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(listWidget);
        __qlistwidgetitem3->setTextAlignment(Qt::AlignHCenter|Qt::AlignBottom);
        __qlistwidgetitem3->setIcon(icon3);
        __qlistwidgetitem3->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setMinimumSize(QSize(85, 0));
        listWidget->setMaximumSize(QSize(78, 16777215));
        listWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listWidget->setIconSize(QSize(32, 32));
        listWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        listWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        listWidget->setMovement(QListView::Static);
        listWidget->setFlow(QListView::TopToBottom);
        listWidget->setProperty("isWrapping", QVariant(false));
        listWidget->setSpacing(15);
        listWidget->setViewMode(QListView::IconMode);
        listWidget->setWordWrap(true);

        horizontalLayout->addWidget(listWidget);

        scrollArea = new QScrollArea(widget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaContents = new QWidget();
        scrollAreaContents->setObjectName(QStringLiteral("scrollAreaContents"));
        scrollAreaContents->setGeometry(QRect(0, 0, 492, 411));
        gridLayout_4 = new QGridLayout(scrollAreaContents);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        pages = new QStackedWidget(scrollAreaContents);
        pages->setObjectName(QStringLiteral("pages"));
        generalPage = new QWidget();
        generalPage->setObjectName(QStringLiteral("generalPage"));
        formLayout = new QFormLayout(generalPage);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        groupBox = new QGroupBox(generalPage);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setWordWrap(true);

        verticalLayout_3->addWidget(label);

        rbStandardRegex = new QRadioButton(groupBox);
        rbStandardRegex->setObjectName(QStringLiteral("rbStandardRegex"));

        verticalLayout_3->addWidget(rbStandardRegex);

        rbWildcardRegex = new QRadioButton(groupBox);
        rbWildcardRegex->setObjectName(QStringLiteral("rbWildcardRegex"));

        verticalLayout_3->addWidget(rbWildcardRegex);

        rbWildcardUnixRegex = new QRadioButton(groupBox);
        rbWildcardUnixRegex->setObjectName(QStringLiteral("rbWildcardUnixRegex"));

        verticalLayout_3->addWidget(rbWildcardUnixRegex);


        formLayout->setWidget(0, QFormLayout::SpanningRole, groupBox);

        groupBox_11 = new QGroupBox(generalPage);
        groupBox_11->setObjectName(QStringLiteral("groupBox_11"));
        verticalLayout_13 = new QVBoxLayout(groupBox_11);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        chStayOnTop = new QCheckBox(groupBox_11);
        chStayOnTop->setObjectName(QStringLiteral("chStayOnTop"));

        verticalLayout_13->addWidget(chStayOnTop);


        formLayout->setWidget(1, QFormLayout::SpanningRole, groupBox_11);

        pages->addWidget(generalPage);
        windowTreePage = new QWidget();
        windowTreePage->setObjectName(QStringLiteral("windowTreePage"));
        formLayout_5 = new QFormLayout(windowTreePage);
        formLayout_5->setObjectName(QStringLiteral("formLayout_5"));
        formLayout_5->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        groupBox_7 = new QGroupBox(windowTreePage);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        verticalLayout_10 = new QVBoxLayout(groupBox_7);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        label_16 = new QLabel(groupBox_7);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setWordWrap(true);

        verticalLayout_10->addWidget(label_16);

        widget_11 = new QWidget(groupBox_7);
        widget_11->setObjectName(QStringLiteral("widget_11"));
        horizontalLayout_6 = new QHBoxLayout(widget_11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(6, 0, 0, 0);
        label_15 = new QLabel(widget_11);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_6->addWidget(label_15);

        spnChangeDuration = new QSpinBox(widget_11);
        spnChangeDuration->setObjectName(QStringLiteral("spnChangeDuration"));
        spnChangeDuration->setMinimum(1);
        spnChangeDuration->setMaximum(10000);

        horizontalLayout_6->addWidget(spnChangeDuration);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        verticalLayout_10->addWidget(widget_11);

        groupBox_8 = new QGroupBox(groupBox_7);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        horizontalLayout_5 = new QHBoxLayout(groupBox_8);
        horizontalLayout_5->setSpacing(10);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, 3, -1, 3);
        widget_12 = new QWidget(groupBox_8);
        widget_12->setObjectName(QStringLiteral("widget_12"));
        gridLayout_6 = new QGridLayout(widget_12);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setHorizontalSpacing(10);
        gridLayout_6->setVerticalSpacing(3);
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        label_19 = new QLabel(widget_12);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_19, 0, 1, 1, 1);

        label_20 = new QLabel(widget_12);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_20, 0, 2, 1, 1);

        label_17 = new QLabel(widget_12);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_6->addWidget(label_17, 1, 0, 1, 1);

        btnCreatedColour1 = new ColourButton(widget_12);
        btnCreatedColour1->setObjectName(QStringLiteral("btnCreatedColour1"));
        btnCreatedColour1->setMinimumSize(QSize(50, 0));
        btnCreatedColour1->setMaximumSize(QSize(50, 16777215));

        gridLayout_6->addWidget(btnCreatedColour1, 1, 1, 1, 1);

        btnCreatedColour2 = new ColourButton(widget_12);
        btnCreatedColour2->setObjectName(QStringLiteral("btnCreatedColour2"));
        btnCreatedColour2->setMinimumSize(QSize(50, 0));
        btnCreatedColour2->setMaximumSize(QSize(50, 16777215));

        gridLayout_6->addWidget(btnCreatedColour2, 1, 2, 1, 1);

        label_18 = new QLabel(widget_12);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_6->addWidget(label_18, 2, 0, 1, 1);

        btnDestroyedColour1 = new ColourButton(widget_12);
        btnDestroyedColour1->setObjectName(QStringLiteral("btnDestroyedColour1"));
        btnDestroyedColour1->setMinimumSize(QSize(50, 0));
        btnDestroyedColour1->setMaximumSize(QSize(50, 16777215));

        gridLayout_6->addWidget(btnDestroyedColour1, 2, 1, 1, 1);

        btnDestroyedColour2 = new ColourButton(widget_12);
        btnDestroyedColour2->setObjectName(QStringLiteral("btnDestroyedColour2"));
        btnDestroyedColour2->setMinimumSize(QSize(50, 0));
        btnDestroyedColour2->setMaximumSize(QSize(50, 16777215));

        gridLayout_6->addWidget(btnDestroyedColour2, 2, 2, 1, 1);

        label_22 = new QLabel(widget_12);
        label_22->setObjectName(QStringLiteral("label_22"));

        gridLayout_6->addWidget(label_22, 3, 0, 1, 1);

        btnChangedColour1 = new ColourButton(widget_12);
        btnChangedColour1->setObjectName(QStringLiteral("btnChangedColour1"));
        btnChangedColour1->setMinimumSize(QSize(50, 0));
        btnChangedColour1->setMaximumSize(QSize(50, 16777215));

        gridLayout_6->addWidget(btnChangedColour1, 3, 1, 1, 1);

        btnChangedColour2 = new ColourButton(widget_12);
        btnChangedColour2->setObjectName(QStringLiteral("btnChangedColour2"));
        btnChangedColour2->setMinimumSize(QSize(50, 0));
        btnChangedColour2->setMaximumSize(QSize(50, 16777215));

        gridLayout_6->addWidget(btnChangedColour2, 3, 2, 1, 1);


        horizontalLayout_5->addWidget(widget_12);

        label_21 = new QLabel(groupBox_8);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_21->setWordWrap(true);

        horizontalLayout_5->addWidget(label_21);

        horizontalLayout_5->setStretch(1, 1);

        verticalLayout_10->addWidget(groupBox_8);


        formLayout_5->setWidget(1, QFormLayout::SpanningRole, groupBox_7);

        groupBox_9 = new QGroupBox(windowTreePage);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        verticalLayout_12 = new QVBoxLayout(groupBox_9);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        chGreyHiddenWindows = new QCheckBox(groupBox_9);
        chGreyHiddenWindows->setObjectName(QStringLiteral("chGreyHiddenWindows"));

        verticalLayout_12->addWidget(chGreyHiddenWindows);


        formLayout_5->setWidget(0, QFormLayout::SpanningRole, groupBox_9);

        groupBox_12 = new QGroupBox(windowTreePage);
        groupBox_12->setObjectName(QStringLiteral("groupBox_12"));
        verticalLayout_2 = new QVBoxLayout(groupBox_12);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        chOpenPropertiesOnSelect = new QCheckBox(groupBox_12);
        chOpenPropertiesOnSelect->setObjectName(QStringLiteral("chOpenPropertiesOnSelect"));

        verticalLayout_2->addWidget(chOpenPropertiesOnSelect);


        formLayout_5->setWidget(2, QFormLayout::SpanningRole, groupBox_12);

        pages->addWidget(windowTreePage);
        pickerPage = new QWidget();
        pickerPage->setObjectName(QStringLiteral("pickerPage"));
        formLayout_4 = new QFormLayout(pickerPage);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        formLayout_4->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        groupBox_5 = new QGroupBox(pickerPage);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        verticalLayout_4 = new QVBoxLayout(groupBox_5);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_7 = new QLabel(groupBox_5);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setWordWrap(true);

        verticalLayout_4->addWidget(label_7);

        widget_6 = new QWidget(groupBox_5);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        gridLayout_3 = new QGridLayout(widget_6);
        gridLayout_3->setSpacing(5);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(-1, 3, -1, 3);
        chWindowClass = new QCheckBox(widget_6);
        chWindowClass->setObjectName(QStringLiteral("chWindowClass"));
        chWindowClass->setMinimumSize(QSize(0, 15));

        gridLayout_3->addWidget(chWindowClass, 0, 0, 1, 1);

        chWindowHandle = new QCheckBox(widget_6);
        chWindowHandle->setObjectName(QStringLiteral("chWindowHandle"));
        chWindowHandle->setMinimumSize(QSize(0, 15));

        gridLayout_3->addWidget(chWindowHandle, 0, 1, 1, 1);

        chWindowText = new QCheckBox(widget_6);
        chWindowText->setObjectName(QStringLiteral("chWindowText"));
        chWindowText->setMinimumSize(QSize(0, 15));

        gridLayout_3->addWidget(chWindowText, 1, 0, 1, 1);

        chWindowDimensions = new QCheckBox(widget_6);
        chWindowDimensions->setObjectName(QStringLiteral("chWindowDimensions"));
        chWindowDimensions->setMinimumSize(QSize(0, 15));

        gridLayout_3->addWidget(chWindowDimensions, 1, 1, 1, 1);

        chWindowPosition = new QCheckBox(widget_6);
        chWindowPosition->setObjectName(QStringLiteral("chWindowPosition"));
        chWindowPosition->setMinimumSize(QSize(0, 15));

        gridLayout_3->addWidget(chWindowPosition, 2, 0, 1, 1);

        chWindowSize = new QCheckBox(widget_6);
        chWindowSize->setObjectName(QStringLiteral("chWindowSize"));
        chWindowSize->setMinimumSize(QSize(0, 15));

        gridLayout_3->addWidget(chWindowSize, 2, 1, 1, 1);

        chParentHandle = new QCheckBox(widget_6);
        chParentHandle->setObjectName(QStringLiteral("chParentHandle"));
        chParentHandle->setMinimumSize(QSize(0, 15));

        gridLayout_3->addWidget(chParentHandle, 3, 0, 1, 1);


        verticalLayout_4->addWidget(widget_6);


        formLayout_4->setWidget(1, QFormLayout::SpanningRole, groupBox_5);

        groupBox_6 = new QGroupBox(pickerPage);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        verticalLayout_5 = new QVBoxLayout(groupBox_6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_5 = new QLabel(groupBox_6);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_5->addWidget(label_5);

        widget_4 = new QWidget(groupBox_6);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        gridLayout_2 = new QGridLayout(widget_4);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(3);
        gridLayout_2->setContentsMargins(-1, 0, -1, 0);
        rbFilled = new QRadioButton(widget_4);
        rbFilled->setObjectName(QStringLiteral("rbFilled"));

        gridLayout_2->addWidget(rbFilled, 2, 0, 1, 1);

        rbBorder = new QRadioButton(widget_4);
        rbBorder->setObjectName(QStringLiteral("rbBorder"));

        gridLayout_2->addWidget(rbBorder, 0, 0, 1, 1);

        label_4 = new QLabel(widget_4);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 0, 1, 1, 1);

        label_3 = new QLabel(widget_4);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 2, 2, 1, 1);

        widget_8 = new QWidget(widget_4);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        horizontalLayout_4 = new QHBoxLayout(widget_8);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(18, 0, 0, 0);
        label_10 = new QLabel(widget_8);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_4->addWidget(label_10);

        spnThickness = new QSpinBox(widget_8);
        spnThickness->setObjectName(QStringLiteral("spnThickness"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(spnThickness->sizePolicy().hasHeightForWidth());
        spnThickness->setSizePolicy(sizePolicy);
        spnThickness->setMinimum(1);
        spnThickness->setMaximum(100);

        horizontalLayout_4->addWidget(spnThickness);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        gridLayout_2->addWidget(widget_8, 1, 0, 1, 3);


        verticalLayout_5->addWidget(widget_4);

        widget_5 = new QWidget(groupBox_6);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        gridLayout = new QGridLayout(widget_5);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setVerticalSpacing(2);
        gridLayout->setContentsMargins(0, 3, -1, 3);
        btnHighlighterColour = new ColourButton(widget_5);
        btnHighlighterColour->setObjectName(QStringLiteral("btnHighlighterColour"));
        btnHighlighterColour->setMinimumSize(QSize(50, 0));
        btnHighlighterColour->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(btnHighlighterColour, 2, 1, 1, 1);

        slHighlighterTransparency = new QSlider(widget_5);
        slHighlighterTransparency->setObjectName(QStringLiteral("slHighlighterTransparency"));
        slHighlighterTransparency->setMaximumSize(QSize(300, 16777215));
        slHighlighterTransparency->setMaximum(255);
        slHighlighterTransparency->setTracking(false);
        slHighlighterTransparency->setOrientation(Qt::Horizontal);
        slHighlighterTransparency->setTickPosition(QSlider::TicksBelow);
        slHighlighterTransparency->setTickInterval(10);

        gridLayout->addWidget(slHighlighterTransparency, 2, 3, 1, 1);

        label_2 = new QLabel(widget_5);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 2, 1, 1);

        label_6 = new QLabel(widget_5);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        widget_7 = new QWidget(widget_5);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        horizontalLayout_3 = new QHBoxLayout(widget_7);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(widget_7);
        label_9->setObjectName(QStringLiteral("label_9"));
        QFont font;
        font.setPointSize(7);
        label_9->setFont(font);

        horizontalLayout_3->addWidget(label_9);

        label_8 = new QLabel(widget_7);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_8);


        gridLayout->addWidget(widget_7, 0, 3, 1, 1);


        verticalLayout_5->addWidget(widget_5);


        formLayout_4->setWidget(2, QFormLayout::SpanningRole, groupBox_6);

        groupBox_3 = new QGroupBox(pickerPage);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_5 = new QGridLayout(groupBox_3);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        chPickTransparent = new QCheckBox(groupBox_3);
        chPickTransparent->setObjectName(QStringLiteral("chPickTransparent"));

        gridLayout_5->addWidget(chPickTransparent, 0, 0, 1, 1);

        chHideWhilePicking = new QCheckBox(groupBox_3);
        chHideWhilePicking->setObjectName(QStringLiteral("chHideWhilePicking"));

        gridLayout_5->addWidget(chHideWhilePicking, 1, 0, 1, 1);


        formLayout_4->setWidget(0, QFormLayout::SpanningRole, groupBox_3);

        pages->addWidget(pickerPage);
        loggingPage = new QWidget();
        loggingPage->setObjectName(QStringLiteral("loggingPage"));
        formLayout_2 = new QFormLayout(loggingPage);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        groupBox_2 = new QGroupBox(loggingPage);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        formLayout_3 = new QFormLayout(groupBox_2);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        chLogToFile = new QCheckBox(groupBox_2);
        chLogToFile->setObjectName(QStringLiteral("chLogToFile"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, chLogToFile);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setWordWrap(true);

        formLayout_3->setWidget(0, QFormLayout::SpanningRole, label_11);

        widget_3 = new QWidget(groupBox_2);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(15, 0, 0, 0);
        txtLogFolder = new QLineEdit(widget_3);
        txtLogFolder->setObjectName(QStringLiteral("txtLogFolder"));
        txtLogFolder->setEnabled(false);

        horizontalLayout_2->addWidget(txtLogFolder);

        btnChooseFolder = new QPushButton(widget_3);
        btnChooseFolder->setObjectName(QStringLiteral("btnChooseFolder"));
        btnChooseFolder->setEnabled(false);

        horizontalLayout_2->addWidget(btnChooseFolder);


        formLayout_3->setWidget(2, QFormLayout::SpanningRole, widget_3);


        formLayout_2->setWidget(1, QFormLayout::SpanningRole, groupBox_2);

        groupBox_10 = new QGroupBox(loggingPage);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        verticalLayout_11 = new QVBoxLayout(groupBox_10);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        label_23 = new QLabel(groupBox_10);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setWordWrap(true);

        verticalLayout_11->addWidget(label_23);

        chEnableBalloon = new QCheckBox(groupBox_10);
        chEnableBalloon->setObjectName(QStringLiteral("chEnableBalloon"));

        verticalLayout_11->addWidget(chEnableBalloon);


        formLayout_2->setWidget(0, QFormLayout::SpanningRole, groupBox_10);

        pages->addWidget(loggingPage);

        gridLayout_4->addWidget(pages, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaContents);

        horizontalLayout->addWidget(scrollArea);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(PreferencesDialog);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout_7 = new QHBoxLayout(widget_2);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(-1, 6, -1, -1);
        settingsButton = new QPushButton(widget_2);
        settingsButton->setObjectName(QStringLiteral("settingsButton"));

        horizontalLayout_7->addWidget(settingsButton);

        dialogButtons = new QDialogButtonBox(widget_2);
        dialogButtons->setObjectName(QStringLiteral("dialogButtons"));
        dialogButtons->setOrientation(Qt::Horizontal);
        dialogButtons->setStandardButtons(QDialogButtonBox::Cancel);

        horizontalLayout_7->addWidget(dialogButtons);


        verticalLayout->addWidget(widget_2);

        QWidget::setTabOrder(rbStandardRegex, rbWildcardRegex);
        QWidget::setTabOrder(rbWildcardRegex, rbWildcardUnixRegex);
        QWidget::setTabOrder(rbWildcardUnixRegex, chGreyHiddenWindows);
        QWidget::setTabOrder(chGreyHiddenWindows, spnChangeDuration);
        QWidget::setTabOrder(spnChangeDuration, btnCreatedColour1);
        QWidget::setTabOrder(btnCreatedColour1, btnCreatedColour2);
        QWidget::setTabOrder(btnCreatedColour2, btnDestroyedColour1);
        QWidget::setTabOrder(btnDestroyedColour1, btnDestroyedColour2);
        QWidget::setTabOrder(btnDestroyedColour2, btnChangedColour1);
        QWidget::setTabOrder(btnChangedColour1, btnChangedColour2);
        QWidget::setTabOrder(btnChangedColour2, chPickTransparent);
        QWidget::setTabOrder(chPickTransparent, chHideWhilePicking);
        QWidget::setTabOrder(chHideWhilePicking, chWindowClass);
        QWidget::setTabOrder(chWindowClass, chWindowHandle);
        QWidget::setTabOrder(chWindowHandle, chWindowText);
        QWidget::setTabOrder(chWindowText, chWindowDimensions);
        QWidget::setTabOrder(chWindowDimensions, chWindowPosition);
        QWidget::setTabOrder(chWindowPosition, chWindowSize);
        QWidget::setTabOrder(chWindowSize, chParentHandle);
        QWidget::setTabOrder(chParentHandle, rbBorder);
        QWidget::setTabOrder(rbBorder, spnThickness);
        QWidget::setTabOrder(spnThickness, rbFilled);
        QWidget::setTabOrder(rbFilled, btnHighlighterColour);
        QWidget::setTabOrder(btnHighlighterColour, slHighlighterTransparency);
        QWidget::setTabOrder(slHighlighterTransparency, chEnableBalloon);
        QWidget::setTabOrder(chEnableBalloon, chLogToFile);
        QWidget::setTabOrder(chLogToFile, txtLogFolder);
        QWidget::setTabOrder(txtLogFolder, btnChooseFolder);
        QWidget::setTabOrder(btnChooseFolder, dialogButtons);
        QWidget::setTabOrder(dialogButtons, scrollArea);
        QWidget::setTabOrder(scrollArea, listWidget);

        retranslateUi(PreferencesDialog);
        QObject::connect(dialogButtons, SIGNAL(accepted()), PreferencesDialog, SLOT(accept()));
        QObject::connect(dialogButtons, SIGNAL(rejected()), PreferencesDialog, SLOT(reject()));
        QObject::connect(chLogToFile, SIGNAL(toggled(bool)), txtLogFolder, SLOT(setEnabled(bool)));
        QObject::connect(chLogToFile, SIGNAL(toggled(bool)), btnChooseFolder, SLOT(setEnabled(bool)));
        QObject::connect(rbBorder, SIGNAL(toggled(bool)), label_10, SLOT(setEnabled(bool)));
        QObject::connect(rbBorder, SIGNAL(toggled(bool)), spnThickness, SLOT(setEnabled(bool)));
        QObject::connect(listWidget, SIGNAL(currentRowChanged(int)), pages, SLOT(setCurrentIndex(int)));

        pages->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PreferencesDialog);
    } // setupUi

    void retranslateUi(QDialog *PreferencesDialog)
    {
        PreferencesDialog->setWindowTitle(QApplication::translate("PreferencesDialog", "Preferences [*]", 0));
        actnRestoreDefaults->setText(QApplication::translate("PreferencesDialog", "Restore Defaults", 0));
#ifndef QT_NO_TOOLTIP
        actnRestoreDefaults->setToolTip(QApplication::translate("PreferencesDialog", "Restore default settings", 0));
#endif // QT_NO_TOOLTIP
        actnExportSettings->setText(QApplication::translate("PreferencesDialog", "Export Settings", 0));
#ifndef QT_NO_TOOLTIP
        actnExportSettings->setToolTip(QApplication::translate("PreferencesDialog", "Export settings to file", 0));
#endif // QT_NO_TOOLTIP
        actnImportSettings->setText(QApplication::translate("PreferencesDialog", "Import Settings", 0));
#ifndef QT_NO_TOOLTIP
        actnImportSettings->setToolTip(QApplication::translate("PreferencesDialog", "Import settings from file", 0));
#endif // QT_NO_TOOLTIP

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("PreferencesDialog", "General", 0));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("PreferencesDialog", "Window Tree", 0));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("PreferencesDialog", "Picker", 0));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("PreferencesDialog", "Logging", 0));
        listWidget->setSortingEnabled(__sortingEnabled);

        groupBox->setTitle(QApplication::translate("PreferencesDialog", "Regular Expression Syntax", 0));
        label->setText(QApplication::translate("PreferencesDialog", "When matching a regular expression, such as in the Find dialog, Window Detective will use the following syntax:", 0));
#ifndef QT_NO_TOOLTIP
        rbStandardRegex->setToolTip(QApplication::translate("PreferencesDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Arial,Geneva,Helvetica,sans-serif'; font-size:medium; color:#000000;\">A rich Perl-like pattern matching syntax.</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        rbStandardRegex->setText(QApplication::translate("PreferencesDialog", "Standard &RegExp", 0));
#ifndef QT_NO_TOOLTIP
        rbWildcardRegex->setToolTip(QApplication::translate("PreferencesDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Arial,Geneva,Helvetica,sans-serif'; font-size:medium; color:#000000;\">This provides a simple pattern matching syntax similar to that used by shells (command interpreters) for &quot;file globbing&quot;.</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        rbWildcardRegex->setText(QApplication::translate("PreferencesDialog", "&Wildcard", 0));
#ifndef QT_NO_TOOLTIP
        rbWildcardUnixRegex->setToolTip(QApplication::translate("PreferencesDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Arial,Geneva,Helvetica,sans-serif'; font-size:medium; color:#000000;\">This is similar to Wildcard but with the behavior of a Unix shell. The wildcard characters can be escaped with the character &quot;&quot;.</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        rbWildcardUnixRegex->setText(QApplication::translate("PreferencesDialog", "Wildcard &Unix", 0));
        groupBox_11->setTitle(QApplication::translate("PreferencesDialog", "User Interface", 0));
        chStayOnTop->setText(QApplication::translate("PreferencesDialog", "&Keep Window Detective windows on top", 0));
        groupBox_7->setTitle(QApplication::translate("PreferencesDialog", "Change Highlighing", 0));
        label_16->setText(QApplication::translate("PreferencesDialog", "When an item in the tree is changed, it will be highlighted. Choose the duration and highlight colour below", 0));
        label_15->setText(QApplication::translate("PreferencesDialog", "Duration:", 0));
        spnChangeDuration->setSuffix(QApplication::translate("PreferencesDialog", " ms", 0));
        groupBox_8->setTitle(QApplication::translate("PreferencesDialog", "Colour", 0));
        label_19->setText(QApplication::translate("PreferencesDialog", "Immediate", 0));
        label_20->setText(QApplication::translate("PreferencesDialog", "Unexpanded", 0));
        label_17->setText(QApplication::translate("PreferencesDialog", "Created", 0));
        btnCreatedColour1->setText(QString());
        btnCreatedColour2->setText(QString());
        label_18->setText(QApplication::translate("PreferencesDialog", "Destroyed", 0));
        btnDestroyedColour1->setText(QString());
        btnDestroyedColour2->setText(QString());
        label_22->setText(QApplication::translate("PreferencesDialog", "Changed", 0));
        btnChangedColour1->setText(QString());
        btnChangedColour2->setText(QString());
        label_21->setText(QApplication::translate("PreferencesDialog", "Choose colours for each highlight event. The immediate colour is the colour of the item that is updated. The unexpanded colour is the colour of the closest visible (expanded) ancestor of an item which is not expanded.", 0));
        groupBox_9->setTitle(QApplication::translate("PreferencesDialog", "Hidden Windows", 0));
        chGreyHiddenWindows->setText(QApplication::translate("PreferencesDialog", "&Grey hidden windows", 0));
        groupBox_12->setTitle(QApplication::translate("PreferencesDialog", "Window Properties", 0));
        chOpenPropertiesOnSelect->setText(QApplication::translate("PreferencesDialog", "Show properties when item is selected in tree", 0));
        groupBox_5->setTitle(QApplication::translate("PreferencesDialog", "Window Info", 0));
        label_7->setText(QApplication::translate("PreferencesDialog", "Select what info should be displayed in the info window when using the picker", 0));
        chWindowClass->setText(QApplication::translate("PreferencesDialog", "&Window Class", 0));
        chWindowHandle->setText(QApplication::translate("PreferencesDialog", "&Handle", 0));
        chWindowText->setText(QApplication::translate("PreferencesDialog", "&Text/Title", 0));
        chWindowDimensions->setText(QApplication::translate("PreferencesDialog", "&Dimensions", 0));
        chWindowPosition->setText(QApplication::translate("PreferencesDialog", "&Position", 0));
        chWindowSize->setText(QApplication::translate("PreferencesDialog", "&Size", 0));
        chParentHandle->setText(QApplication::translate("PreferencesDialog", "Pa&rent Handle", 0));
        groupBox_6->setTitle(QApplication::translate("PreferencesDialog", "Window Highlight", 0));
        label_5->setText(QApplication::translate("PreferencesDialog", "Style:", 0));
        rbFilled->setText(QApplication::translate("PreferencesDialog", "&Filled", 0));
        rbBorder->setText(QApplication::translate("PreferencesDialog", "&Border", 0));
        label_4->setText(QApplication::translate("PreferencesDialog", "- A border is drawn around the chosen window", 0));
        label_3->setText(QApplication::translate("PreferencesDialog", "- The chosen window is filled completely", 0));
        label_10->setText(QApplication::translate("PreferencesDialog", "Thickness:", 0));
        spnThickness->setSuffix(QApplication::translate("PreferencesDialog", " px", 0));
        btnHighlighterColour->setText(QString());
        label_2->setText(QApplication::translate("PreferencesDialog", "Transparency:", 0));
        label_6->setText(QApplication::translate("PreferencesDialog", "Colour:", 0));
        label_9->setText(QApplication::translate("PreferencesDialog", "transparent", 0));
        label_8->setText(QApplication::translate("PreferencesDialog", "opaque", 0));
        groupBox_3->setTitle(QApplication::translate("PreferencesDialog", "Picker", 0));
#ifndef QT_NO_WHATSTHIS
        chPickTransparent->setWhatsThis(QApplication::translate("PreferencesDialog", "If enabled, windows or controls with the WS_EX_TRANSPARENT are also detected", 0));
#endif // QT_NO_WHATSTHIS
        chPickTransparent->setText(QApplication::translate("PreferencesDialog", "&Allow to pick transparent windows", 0));
        chHideWhilePicking->setText(QApplication::translate("PreferencesDialog", "Hide &main window while picking", 0));
        groupBox_2->setTitle(QApplication::translate("PreferencesDialog", "Logging to File", 0));
        chLogToFile->setText(QApplication::translate("PreferencesDialog", "&Enable", 0));
        label_11->setText(QApplication::translate("PreferencesDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">If enabled, all logs will be written to a file. Select a folder to output to, a log file will be generated named &quot;Window_Detective_&lt;current\302\240date&gt;.log&quot;.</span></p></body></html>", 0));
        btnChooseFolder->setText(QApplication::translate("PreferencesDialog", "Choose Folder...", 0));
        groupBox_10->setTitle(QApplication::translate("PreferencesDialog", "Notifications", 0));
        label_23->setText(QApplication::translate("PreferencesDialog", "When an error or important event occurs, a balloon pops up to notify you (as well as logging it).", 0));
        chEnableBalloon->setText(QApplication::translate("PreferencesDialog", "Enable &Balloon Notifications", 0));
        settingsButton->setText(QApplication::translate("PreferencesDialog", "Settings", 0));
    } // retranslateUi

};

namespace Ui {
    class PreferencesDialog: public Ui_PreferencesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREFERENCESDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'SystemParametersPane.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMPARAMETERSPANE_H
#define UI_SYSTEMPARAMETERSPANE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ui\custom_widgets\FontPropertyWidget.h"
#include "ui\custom_widgets\SizeInputWidget.h"

QT_BEGIN_NAMESPACE

class Ui_SystemParametersPane
{
public:
    QGridLayout *gridLayout;
    QListWidget *parameterGroupList;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QDialogButtonBox *buttonBox;
    QStackedWidget *pages;
    QWidget *accessibilityPage;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *accessibilityArea;
    QGridLayout *gridLayout_2;
    QLabel *mouseVanishLabel;
    QLabel *mouseSonarLabel;
    QLabel *animationsLabel;
    QCheckBox *mouseSonar;
    QLabel *focusBorderLabel;
    QLabel *notificationPopupDurationLabel;
    QCheckBox *animations;
    QSpinBox *notificationPopupDuration;
    QCheckBox *mouseVanish;
    SizeInputWidget *focusBorder;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_4;
    QWidget *desktopPage;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea_2;
    QWidget *desktopArea;
    QGridLayout *gridLayout_3;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_6;
    QLabel *wallpaperPath;
    QLabel *fontSmoothingLabel;
    QCheckBox *fontSmoothing;
    QLabel *dropShadowLabel;
    QLabel *wallpaperPathLabel;
    QLabel *clearTypeLabel;
    QCheckBox *dropShadow;
    QCheckBox *clearType;
    QSpacerItem *verticalSpacer_2;
    QWidget *iconPage;
    QVBoxLayout *verticalLayout_3;
    QScrollArea *scrollArea_3;
    QWidget *iconArea;
    QGridLayout *gridLayout_4;
    SizeInputWidget *iconSpacing;
    FontPropertyWidget *iconTitleFont;
    QLabel *iconTitleFontLabel;
    QCheckBox *iconTitleWrap;
    QSpacerItem *verticalSpacer_3;
    QLabel *iconTitleWrapLabel;
    QLabel *iconSpacingLabel;
    QSpacerItem *horizontalSpacer_5;
    QWidget *inputPage;
    QVBoxLayout *verticalLayout_4;
    QScrollArea *scrollArea_4;
    QWidget *inputArea;
    QGridLayout *gridLayout_5;
    SizeInputWidget *mouseHoverSize;
    QCheckBox *snapDefaultButton;
    QSpinBox *mouseWheelX;
    QLabel *mouseWheelXLabel;
    QLabel *mouseHoverSizeLabel;
    QSpinBox *mouseHoverTime;
    QLabel *mouseHoverTimeLabel;
    QSpinBox *mouseTrails;
    QLabel *mouseTrailsLabel;
    QSpinBox *mouseSpeed;
    QLabel *mouseSpeedLabel;
    QSpinBox *keyboardDelay;
    QLabel *keyboardDelayLabel;
    QSpinBox *keyboardSpeed;
    QLabel *keyboardSpeedLabel;
    QCheckBox *keyboardCues;
    QLabel *keyboardCuesLabel;
    QCheckBox *blockSimulatedInput;
    QLabel *blockSimulatedInputLabel;
    QCheckBox *beeper;
    QLabel *beeperLabel;
    QLabel *mouseWheelYLabel;
    QSpinBox *mouseWheelY;
    QLabel *snapDefaultButtonLabel;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_6;
    QWidget *menuPage;
    QVBoxLayout *verticalLayout_5;
    QScrollArea *scrollArea_5;
    QWidget *menuArea;
    QGridLayout *gridLayout_6;
    QSpacerItem *verticalSpacer_5;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *menuAlignmentRight;
    QRadioButton *menuAlignmentLeft;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *menuAnimationFade;
    QRadioButton *menuAnimationSlide;
    QSpacerItem *horizontalSpacer_2;
    QLabel *menuAlignmentLabel;
    QLabel *menuAnimationLabel;
    QLabel *menuDelayLabel;
    QSpinBox *menuDelay;
    QSpacerItem *horizontalSpacer_7;
    QWidget *screenSaverPage;
    QVBoxLayout *verticalLayout_7;
    QScrollArea *scrollArea_7;
    QWidget *screenSaverArea;
    QGridLayout *gridLayout_7;
    QCheckBox *screenSaverPassword;
    QLabel *screenSaverPasswordLabel;
    QLabel *screenSaverTimeoutLabel;
    QSpacerItem *verticalSpacer_6;
    QSpinBox *screenSaverTimeout;
    QSpacerItem *horizontalSpacer_8;
    QWidget *timeoutPage;
    QVBoxLayout *verticalLayout_8;
    QScrollArea *scrollArea_8;
    QWidget *timeoutArea;
    QGridLayout *gridLayout_8;
    QSpacerItem *verticalSpacer_7;
    QSpinBox *hungTimeout;
    QSpinBox *killTimeout;
    QSpinBox *killServiceTimeout;
    QLabel *hungTimeoutLabel;
    QLabel *killServiceTimeoutLabel;
    QLabel *killTimeoutLabel;
    QSpacerItem *horizontalSpacer_9;
    QWidget *uiEffectPage;
    QVBoxLayout *verticalLayout_9;
    QScrollArea *scrollArea_9;
    QWidget *uiEffectArea;
    QGridLayout *gridLayout_9;
    QLabel *selectionFadeLabel;
    QLabel *menuAnimationEnabledLabel;
    QCheckBox *menuAnimationEnabled;
    QCheckBox *selectionFade;
    QCheckBox *listBoxSmoothScrolling;
    QLabel *cursorShadowLabel;
    QCheckBox *comboBoxAnimation;
    QLabel *listBoxSmoothScrollingLabel;
    QCheckBox *hotTracking;
    QLabel *hotTrackingLabel;
    QCheckBox *cursorShadow;
    QLabel *comboBoxAnimationLabel;
    QLabel *toolTipAnimationLabel2;
    QCheckBox *toolTipAnimation;
    QLabel *toolTipAnimationLabel;
    QSpacerItem *verticalSpacer_8;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *toolTipAnimationFade;
    QRadioButton *toolTipAnimationSlide;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_10;
    QWidget *windowPage;
    QVBoxLayout *verticalLayout_10;
    QScrollArea *scrollArea_10;
    QWidget *windowArea;
    QGridLayout *gridLayout_10;
    QCheckBox *verticalSnapping;
    QLabel *verticalSnappingLabel;
    QSpinBox *mouseUndockThreshold;
    QLabel *mouseUndockThresholdLabel;
    QSpinBox *mouseDockThreshold;
    QLabel *mouseDockThresholdLabel;
    QCheckBox *dragMaximize;
    QLabel *dragMaximizeLlabel;
    QCheckBox *windowDocking;
    QLabel *windowDockingLabel;
    QSpinBox *caretWidth;
    QLabel *caretWidthLabel;
    QSpinBox *windowBorder;
    QLabel *windowBorderLlabel;
    QSpinBox *windowTrackingDelay;
    QLabel *windowTrackingDelayLabel;
    QCheckBox *windowTrackingTop;
    QLabel *windowTrackingTopLabel;
    QCheckBox *windowTracking;
    QLabel *windowTrackingLabel;
    QSpacerItem *verticalSpacer_9;
    QSpinBox *foregroundFlashCount;
    QLabel *fullWindowDraggingLabel;
    QCheckBox *fullWindowDragging;
    QSpinBox *foregroundLockTimeout;
    QLabel *foregroundLockTimeoutLabel;
    QLabel *foregroundFlashCountLabel;
    QSpacerItem *horizontalSpacer_11;
    QLabel *mouseRestoreThresholdLabel;
    QSpinBox *mouseRestoreThreshold;
    QLabel *label;

    void setupUi(QWidget *SystemParametersPane)
    {
        if (SystemParametersPane->objectName().isEmpty())
            SystemParametersPane->setObjectName(QString::fromUtf8("SystemParametersPane"));
        SystemParametersPane->resize(600, 450);
        gridLayout = new QGridLayout(SystemParametersPane);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        parameterGroupList = new QListWidget(SystemParametersPane);
        new QListWidgetItem(parameterGroupList);
        new QListWidgetItem(parameterGroupList);
        new QListWidgetItem(parameterGroupList);
        new QListWidgetItem(parameterGroupList);
        new QListWidgetItem(parameterGroupList);
        new QListWidgetItem(parameterGroupList);
        new QListWidgetItem(parameterGroupList);
        new QListWidgetItem(parameterGroupList);
        new QListWidgetItem(parameterGroupList);
        parameterGroupList->setObjectName(QString::fromUtf8("parameterGroupList"));

        gridLayout->addWidget(parameterGroupList, 1, 0, 1, 1);

        widget_3 = new QWidget(SystemParametersPane);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(6, 6, 6, 6);
        buttonBox = new QDialogButtonBox(widget_3);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Reset);

        horizontalLayout->addWidget(buttonBox);


        gridLayout->addWidget(widget_3, 2, 0, 1, 2);

        pages = new QStackedWidget(SystemParametersPane);
        pages->setObjectName(QString::fromUtf8("pages"));
        accessibilityPage = new QWidget();
        accessibilityPage->setObjectName(QString::fromUtf8("accessibilityPage"));
        verticalLayout = new QVBoxLayout(accessibilityPage);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(accessibilityPage);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        accessibilityArea = new QWidget();
        accessibilityArea->setObjectName(QString::fromUtf8("accessibilityArea"));
        accessibilityArea->setGeometry(QRect(0, 0, 319, 120));
        gridLayout_2 = new QGridLayout(accessibilityArea);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(20);
        mouseVanishLabel = new QLabel(accessibilityArea);
        mouseVanishLabel->setObjectName(QString::fromUtf8("mouseVanishLabel"));

        gridLayout_2->addWidget(mouseVanishLabel, 5, 0, 1, 1);

        mouseSonarLabel = new QLabel(accessibilityArea);
        mouseSonarLabel->setObjectName(QString::fromUtf8("mouseSonarLabel"));

        gridLayout_2->addWidget(mouseSonarLabel, 4, 0, 1, 1);

        animationsLabel = new QLabel(accessibilityArea);
        animationsLabel->setObjectName(QString::fromUtf8("animationsLabel"));

        gridLayout_2->addWidget(animationsLabel, 0, 0, 1, 1);

        mouseSonar = new QCheckBox(accessibilityArea);
        mouseSonar->setObjectName(QString::fromUtf8("mouseSonar"));

        gridLayout_2->addWidget(mouseSonar, 4, 1, 1, 1);

        focusBorderLabel = new QLabel(accessibilityArea);
        focusBorderLabel->setObjectName(QString::fromUtf8("focusBorderLabel"));

        gridLayout_2->addWidget(focusBorderLabel, 1, 0, 1, 1);

        notificationPopupDurationLabel = new QLabel(accessibilityArea);
        notificationPopupDurationLabel->setObjectName(QString::fromUtf8("notificationPopupDurationLabel"));

        gridLayout_2->addWidget(notificationPopupDurationLabel, 3, 0, 1, 1);

        animations = new QCheckBox(accessibilityArea);
        animations->setObjectName(QString::fromUtf8("animations"));

        gridLayout_2->addWidget(animations, 0, 1, 1, 1);

        notificationPopupDuration = new QSpinBox(accessibilityArea);
        notificationPopupDuration->setObjectName(QString::fromUtf8("notificationPopupDuration"));
        notificationPopupDuration->setMaximum(1000000000);

        gridLayout_2->addWidget(notificationPopupDuration, 3, 1, 1, 1);

        mouseVanish = new QCheckBox(accessibilityArea);
        mouseVanish->setObjectName(QString::fromUtf8("mouseVanish"));

        gridLayout_2->addWidget(mouseVanish, 5, 1, 1, 1);

        focusBorder = new SizeInputWidget(accessibilityArea);
        focusBorder->setObjectName(QString::fromUtf8("focusBorder"));

        gridLayout_2->addWidget(focusBorder, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 6, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 0, 2, 1, 1);

        scrollArea->setWidget(accessibilityArea);

        verticalLayout->addWidget(scrollArea);

        pages->addWidget(accessibilityPage);
        desktopPage = new QWidget();
        desktopPage->setObjectName(QString::fromUtf8("desktopPage"));
        verticalLayout_2 = new QVBoxLayout(desktopPage);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        scrollArea_2 = new QScrollArea(desktopPage);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        desktopArea = new QWidget();
        desktopArea->setObjectName(QString::fromUtf8("desktopArea"));
        desktopArea->setGeometry(QRect(0, 0, 200, 134));
        gridLayout_3 = new QGridLayout(desktopArea);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(20);
        widget_5 = new QWidget(desktopArea);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        verticalLayout_6 = new QVBoxLayout(widget_5);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        wallpaperPath = new QLabel(widget_5);
        wallpaperPath->setObjectName(QString::fromUtf8("wallpaperPath"));
        wallpaperPath->setCursor(QCursor(Qt::IBeamCursor));
        wallpaperPath->setTextFormat(Qt::PlainText);
        wallpaperPath->setWordWrap(true);
        wallpaperPath->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout_6->addWidget(wallpaperPath);


        gridLayout_3->addWidget(widget_5, 0, 1, 1, 1);

        fontSmoothingLabel = new QLabel(desktopArea);
        fontSmoothingLabel->setObjectName(QString::fromUtf8("fontSmoothingLabel"));

        gridLayout_3->addWidget(fontSmoothingLabel, 3, 0, 1, 1);

        fontSmoothing = new QCheckBox(desktopArea);
        fontSmoothing->setObjectName(QString::fromUtf8("fontSmoothing"));

        gridLayout_3->addWidget(fontSmoothing, 3, 1, 1, 1);

        dropShadowLabel = new QLabel(desktopArea);
        dropShadowLabel->setObjectName(QString::fromUtf8("dropShadowLabel"));

        gridLayout_3->addWidget(dropShadowLabel, 2, 0, 1, 1);

        wallpaperPathLabel = new QLabel(desktopArea);
        wallpaperPathLabel->setObjectName(QString::fromUtf8("wallpaperPathLabel"));

        gridLayout_3->addWidget(wallpaperPathLabel, 0, 0, 1, 1);

        clearTypeLabel = new QLabel(desktopArea);
        clearTypeLabel->setObjectName(QString::fromUtf8("clearTypeLabel"));

        gridLayout_3->addWidget(clearTypeLabel, 1, 0, 1, 1);

        dropShadow = new QCheckBox(desktopArea);
        dropShadow->setObjectName(QString::fromUtf8("dropShadow"));

        gridLayout_3->addWidget(dropShadow, 2, 1, 1, 1);

        clearType = new QCheckBox(desktopArea);
        clearType->setObjectName(QString::fromUtf8("clearType"));

        gridLayout_3->addWidget(clearType, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 4, 0, 1, 1);

        gridLayout_3->setColumnStretch(0, 1);
        gridLayout_3->setColumnStretch(1, 2);
        scrollArea_2->setWidget(desktopArea);

        verticalLayout_2->addWidget(scrollArea_2);

        pages->addWidget(desktopPage);
        iconPage = new QWidget();
        iconPage->setObjectName(QString::fromUtf8("iconPage"));
        verticalLayout_3 = new QVBoxLayout(iconPage);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        scrollArea_3 = new QScrollArea(iconPage);
        scrollArea_3->setObjectName(QString::fromUtf8("scrollArea_3"));
        scrollArea_3->setWidgetResizable(true);
        iconArea = new QWidget();
        iconArea->setObjectName(QString::fromUtf8("iconArea"));
        iconArea->setGeometry(QRect(0, 0, 123, 75));
        gridLayout_4 = new QGridLayout(iconArea);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setHorizontalSpacing(20);
        iconSpacing = new SizeInputWidget(iconArea);
        iconSpacing->setObjectName(QString::fromUtf8("iconSpacing"));

        gridLayout_4->addWidget(iconSpacing, 1, 1, 1, 1);

        iconTitleFont = new FontPropertyWidget(iconArea);
        iconTitleFont->setObjectName(QString::fromUtf8("iconTitleFont"));

        gridLayout_4->addWidget(iconTitleFont, 0, 1, 1, 1);

        iconTitleFontLabel = new QLabel(iconArea);
        iconTitleFontLabel->setObjectName(QString::fromUtf8("iconTitleFontLabel"));

        gridLayout_4->addWidget(iconTitleFontLabel, 0, 0, 1, 1);

        iconTitleWrap = new QCheckBox(iconArea);
        iconTitleWrap->setObjectName(QString::fromUtf8("iconTitleWrap"));

        gridLayout_4->addWidget(iconTitleWrap, 2, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_3, 3, 0, 1, 1);

        iconTitleWrapLabel = new QLabel(iconArea);
        iconTitleWrapLabel->setObjectName(QString::fromUtf8("iconTitleWrapLabel"));

        gridLayout_4->addWidget(iconTitleWrapLabel, 2, 0, 1, 1);

        iconSpacingLabel = new QLabel(iconArea);
        iconSpacingLabel->setObjectName(QString::fromUtf8("iconSpacingLabel"));

        gridLayout_4->addWidget(iconSpacingLabel, 1, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_5, 0, 2, 1, 1);

        scrollArea_3->setWidget(iconArea);

        verticalLayout_3->addWidget(scrollArea_3);

        pages->addWidget(iconPage);
        inputPage = new QWidget();
        inputPage->setObjectName(QString::fromUtf8("inputPage"));
        verticalLayout_4 = new QVBoxLayout(inputPage);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        scrollArea_4 = new QScrollArea(inputPage);
        scrollArea_4->setObjectName(QString::fromUtf8("scrollArea_4"));
        scrollArea_4->setWidgetResizable(true);
        inputArea = new QWidget();
        inputArea->setObjectName(QString::fromUtf8("inputArea"));
        inputArea->setGeometry(QRect(0, 0, 310, 295));
        gridLayout_5 = new QGridLayout(inputArea);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setHorizontalSpacing(20);
        mouseHoverSize = new SizeInputWidget(inputArea);
        mouseHoverSize->setObjectName(QString::fromUtf8("mouseHoverSize"));

        gridLayout_5->addWidget(mouseHoverSize, 8, 1, 1, 1);

        snapDefaultButton = new QCheckBox(inputArea);
        snapDefaultButton->setObjectName(QString::fromUtf8("snapDefaultButton"));

        gridLayout_5->addWidget(snapDefaultButton, 9, 1, 1, 1);

        mouseWheelX = new QSpinBox(inputArea);
        mouseWheelX->setObjectName(QString::fromUtf8("mouseWheelX"));
        mouseWheelX->setMaximum(1000000000);
        mouseWheelX->setValue(3);

        gridLayout_5->addWidget(mouseWheelX, 10, 1, 1, 1);

        mouseWheelXLabel = new QLabel(inputArea);
        mouseWheelXLabel->setObjectName(QString::fromUtf8("mouseWheelXLabel"));

        gridLayout_5->addWidget(mouseWheelXLabel, 10, 0, 1, 1);

        mouseHoverSizeLabel = new QLabel(inputArea);
        mouseHoverSizeLabel->setObjectName(QString::fromUtf8("mouseHoverSizeLabel"));

        gridLayout_5->addWidget(mouseHoverSizeLabel, 8, 0, 1, 1);

        mouseHoverTime = new QSpinBox(inputArea);
        mouseHoverTime->setObjectName(QString::fromUtf8("mouseHoverTime"));
        mouseHoverTime->setMinimum(10);
        mouseHoverTime->setMaximum(2147483647);

        gridLayout_5->addWidget(mouseHoverTime, 7, 1, 1, 1);

        mouseHoverTimeLabel = new QLabel(inputArea);
        mouseHoverTimeLabel->setObjectName(QString::fromUtf8("mouseHoverTimeLabel"));

        gridLayout_5->addWidget(mouseHoverTimeLabel, 7, 0, 1, 1);

        mouseTrails = new QSpinBox(inputArea);
        mouseTrails->setObjectName(QString::fromUtf8("mouseTrails"));

        gridLayout_5->addWidget(mouseTrails, 6, 1, 1, 1);

        mouseTrailsLabel = new QLabel(inputArea);
        mouseTrailsLabel->setObjectName(QString::fromUtf8("mouseTrailsLabel"));

        gridLayout_5->addWidget(mouseTrailsLabel, 6, 0, 1, 1);

        mouseSpeed = new QSpinBox(inputArea);
        mouseSpeed->setObjectName(QString::fromUtf8("mouseSpeed"));
        mouseSpeed->setMinimum(1);
        mouseSpeed->setMaximum(20);
        mouseSpeed->setValue(10);

        gridLayout_5->addWidget(mouseSpeed, 5, 1, 1, 1);

        mouseSpeedLabel = new QLabel(inputArea);
        mouseSpeedLabel->setObjectName(QString::fromUtf8("mouseSpeedLabel"));

        gridLayout_5->addWidget(mouseSpeedLabel, 5, 0, 1, 1);

        keyboardDelay = new QSpinBox(inputArea);
        keyboardDelay->setObjectName(QString::fromUtf8("keyboardDelay"));
        keyboardDelay->setMaximum(3);

        gridLayout_5->addWidget(keyboardDelay, 4, 1, 1, 1);

        keyboardDelayLabel = new QLabel(inputArea);
        keyboardDelayLabel->setObjectName(QString::fromUtf8("keyboardDelayLabel"));

        gridLayout_5->addWidget(keyboardDelayLabel, 4, 0, 1, 1);

        keyboardSpeed = new QSpinBox(inputArea);
        keyboardSpeed->setObjectName(QString::fromUtf8("keyboardSpeed"));
        keyboardSpeed->setMaximum(31);

        gridLayout_5->addWidget(keyboardSpeed, 3, 1, 1, 1);

        keyboardSpeedLabel = new QLabel(inputArea);
        keyboardSpeedLabel->setObjectName(QString::fromUtf8("keyboardSpeedLabel"));

        gridLayout_5->addWidget(keyboardSpeedLabel, 3, 0, 1, 1);

        keyboardCues = new QCheckBox(inputArea);
        keyboardCues->setObjectName(QString::fromUtf8("keyboardCues"));

        gridLayout_5->addWidget(keyboardCues, 2, 1, 1, 1);

        keyboardCuesLabel = new QLabel(inputArea);
        keyboardCuesLabel->setObjectName(QString::fromUtf8("keyboardCuesLabel"));

        gridLayout_5->addWidget(keyboardCuesLabel, 2, 0, 1, 1);

        blockSimulatedInput = new QCheckBox(inputArea);
        blockSimulatedInput->setObjectName(QString::fromUtf8("blockSimulatedInput"));

        gridLayout_5->addWidget(blockSimulatedInput, 1, 1, 1, 1);

        blockSimulatedInputLabel = new QLabel(inputArea);
        blockSimulatedInputLabel->setObjectName(QString::fromUtf8("blockSimulatedInputLabel"));

        gridLayout_5->addWidget(blockSimulatedInputLabel, 1, 0, 1, 1);

        beeper = new QCheckBox(inputArea);
        beeper->setObjectName(QString::fromUtf8("beeper"));

        gridLayout_5->addWidget(beeper, 0, 1, 1, 1);

        beeperLabel = new QLabel(inputArea);
        beeperLabel->setObjectName(QString::fromUtf8("beeperLabel"));

        gridLayout_5->addWidget(beeperLabel, 0, 0, 1, 1);

        mouseWheelYLabel = new QLabel(inputArea);
        mouseWheelYLabel->setObjectName(QString::fromUtf8("mouseWheelYLabel"));

        gridLayout_5->addWidget(mouseWheelYLabel, 11, 0, 1, 1);

        mouseWheelY = new QSpinBox(inputArea);
        mouseWheelY->setObjectName(QString::fromUtf8("mouseWheelY"));
        mouseWheelY->setMaximum(1000000000);
        mouseWheelY->setValue(3);

        gridLayout_5->addWidget(mouseWheelY, 11, 1, 1, 1);

        snapDefaultButtonLabel = new QLabel(inputArea);
        snapDefaultButtonLabel->setObjectName(QString::fromUtf8("snapDefaultButtonLabel"));

        gridLayout_5->addWidget(snapDefaultButtonLabel, 9, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_4, 12, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_6, 0, 2, 1, 1);

        scrollArea_4->setWidget(inputArea);

        verticalLayout_4->addWidget(scrollArea_4);

        pages->addWidget(inputPage);
        menuPage = new QWidget();
        menuPage->setObjectName(QString::fromUtf8("menuPage"));
        verticalLayout_5 = new QVBoxLayout(menuPage);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        scrollArea_5 = new QScrollArea(menuPage);
        scrollArea_5->setObjectName(QString::fromUtf8("scrollArea_5"));
        scrollArea_5->setWidgetResizable(true);
        menuArea = new QWidget();
        menuArea->setObjectName(QString::fromUtf8("menuArea"));
        menuArea->setGeometry(QRect(0, 0, 313, 90));
        gridLayout_6 = new QGridLayout(menuArea);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setHorizontalSpacing(20);
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_5, 3, 0, 1, 1);

        widget = new QWidget(menuArea);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(9);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        menuAlignmentRight = new QRadioButton(widget);
        menuAlignmentRight->setObjectName(QString::fromUtf8("menuAlignmentRight"));

        horizontalLayout_2->addWidget(menuAlignmentRight);

        menuAlignmentLeft = new QRadioButton(widget);
        menuAlignmentLeft->setObjectName(QString::fromUtf8("menuAlignmentLeft"));

        horizontalLayout_2->addWidget(menuAlignmentLeft);

        horizontalSpacer = new QSpacerItem(40, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout_6->addWidget(widget, 0, 1, 1, 1);

        widget_2 = new QWidget(menuArea);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setSpacing(9);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        menuAnimationFade = new QRadioButton(widget_2);
        menuAnimationFade->setObjectName(QString::fromUtf8("menuAnimationFade"));

        horizontalLayout_3->addWidget(menuAnimationFade);

        menuAnimationSlide = new QRadioButton(widget_2);
        menuAnimationSlide->setObjectName(QString::fromUtf8("menuAnimationSlide"));

        horizontalLayout_3->addWidget(menuAnimationSlide);

        horizontalSpacer_2 = new QSpacerItem(40, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        gridLayout_6->addWidget(widget_2, 1, 1, 1, 1);

        menuAlignmentLabel = new QLabel(menuArea);
        menuAlignmentLabel->setObjectName(QString::fromUtf8("menuAlignmentLabel"));

        gridLayout_6->addWidget(menuAlignmentLabel, 0, 0, 1, 1);

        menuAnimationLabel = new QLabel(menuArea);
        menuAnimationLabel->setObjectName(QString::fromUtf8("menuAnimationLabel"));

        gridLayout_6->addWidget(menuAnimationLabel, 1, 0, 1, 1);

        menuDelayLabel = new QLabel(menuArea);
        menuDelayLabel->setObjectName(QString::fromUtf8("menuDelayLabel"));

        gridLayout_6->addWidget(menuDelayLabel, 2, 0, 1, 1);

        menuDelay = new QSpinBox(menuArea);
        menuDelay->setObjectName(QString::fromUtf8("menuDelay"));
        menuDelay->setMaximum(1000000000);

        gridLayout_6->addWidget(menuDelay, 2, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_7, 0, 2, 1, 1);

        scrollArea_5->setWidget(menuArea);

        verticalLayout_5->addWidget(scrollArea_5);

        pages->addWidget(menuPage);
        screenSaverPage = new QWidget();
        screenSaverPage->setObjectName(QString::fromUtf8("screenSaverPage"));
        verticalLayout_7 = new QVBoxLayout(screenSaverPage);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        scrollArea_7 = new QScrollArea(screenSaverPage);
        scrollArea_7->setObjectName(QString::fromUtf8("scrollArea_7"));
        scrollArea_7->setWidgetResizable(true);
        screenSaverArea = new QWidget();
        screenSaverArea->setObjectName(QString::fromUtf8("screenSaverArea"));
        screenSaverArea->setGeometry(QRect(0, 0, 274, 63));
        gridLayout_7 = new QGridLayout(screenSaverArea);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setHorizontalSpacing(20);
        screenSaverPassword = new QCheckBox(screenSaverArea);
        screenSaverPassword->setObjectName(QString::fromUtf8("screenSaverPassword"));

        gridLayout_7->addWidget(screenSaverPassword, 0, 1, 1, 1);

        screenSaverPasswordLabel = new QLabel(screenSaverArea);
        screenSaverPasswordLabel->setObjectName(QString::fromUtf8("screenSaverPasswordLabel"));

        gridLayout_7->addWidget(screenSaverPasswordLabel, 0, 0, 1, 1);

        screenSaverTimeoutLabel = new QLabel(screenSaverArea);
        screenSaverTimeoutLabel->setObjectName(QString::fromUtf8("screenSaverTimeoutLabel"));

        gridLayout_7->addWidget(screenSaverTimeoutLabel, 1, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_6, 2, 0, 1, 1);

        screenSaverTimeout = new QSpinBox(screenSaverArea);
        screenSaverTimeout->setObjectName(QString::fromUtf8("screenSaverTimeout"));
        screenSaverTimeout->setMaximum(1000000000);

        gridLayout_7->addWidget(screenSaverTimeout, 1, 1, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_8, 0, 2, 1, 1);

        scrollArea_7->setWidget(screenSaverArea);

        verticalLayout_7->addWidget(scrollArea_7);

        pages->addWidget(screenSaverPage);
        timeoutPage = new QWidget();
        timeoutPage->setObjectName(QString::fromUtf8("timeoutPage"));
        verticalLayout_8 = new QVBoxLayout(timeoutPage);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        scrollArea_8 = new QScrollArea(timeoutPage);
        scrollArea_8->setObjectName(QString::fromUtf8("scrollArea_8"));
        scrollArea_8->setWidgetResizable(true);
        timeoutArea = new QWidget();
        timeoutArea->setObjectName(QString::fromUtf8("timeoutArea"));
        timeoutArea->setGeometry(QRect(0, 0, 330, 96));
        gridLayout_8 = new QGridLayout(timeoutArea);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setHorizontalSpacing(20);
        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_8->addItem(verticalSpacer_7, 3, 0, 1, 1);

        hungTimeout = new QSpinBox(timeoutArea);
        hungTimeout->setObjectName(QString::fromUtf8("hungTimeout"));
        hungTimeout->setMaximum(1000000000);

        gridLayout_8->addWidget(hungTimeout, 0, 1, 1, 1);

        killTimeout = new QSpinBox(timeoutArea);
        killTimeout->setObjectName(QString::fromUtf8("killTimeout"));
        killTimeout->setMaximum(1000000000);

        gridLayout_8->addWidget(killTimeout, 1, 1, 1, 1);

        killServiceTimeout = new QSpinBox(timeoutArea);
        killServiceTimeout->setObjectName(QString::fromUtf8("killServiceTimeout"));
        killServiceTimeout->setMaximum(1000000000);

        gridLayout_8->addWidget(killServiceTimeout, 2, 1, 1, 1);

        hungTimeoutLabel = new QLabel(timeoutArea);
        hungTimeoutLabel->setObjectName(QString::fromUtf8("hungTimeoutLabel"));

        gridLayout_8->addWidget(hungTimeoutLabel, 0, 0, 1, 1);

        killServiceTimeoutLabel = new QLabel(timeoutArea);
        killServiceTimeoutLabel->setObjectName(QString::fromUtf8("killServiceTimeoutLabel"));

        gridLayout_8->addWidget(killServiceTimeoutLabel, 2, 0, 1, 1);

        killTimeoutLabel = new QLabel(timeoutArea);
        killTimeoutLabel->setObjectName(QString::fromUtf8("killTimeoutLabel"));

        gridLayout_8->addWidget(killTimeoutLabel, 1, 0, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_9, 0, 2, 1, 1);

        scrollArea_8->setWidget(timeoutArea);

        verticalLayout_8->addWidget(scrollArea_8);

        pages->addWidget(timeoutPage);
        uiEffectPage = new QWidget();
        uiEffectPage->setObjectName(QString::fromUtf8("uiEffectPage"));
        verticalLayout_9 = new QVBoxLayout(uiEffectPage);
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        scrollArea_9 = new QScrollArea(uiEffectPage);
        scrollArea_9->setObjectName(QString::fromUtf8("scrollArea_9"));
        scrollArea_9->setWidgetResizable(true);
        uiEffectArea = new QWidget();
        uiEffectArea->setObjectName(QString::fromUtf8("uiEffectArea"));
        uiEffectArea->setGeometry(QRect(0, 0, 284, 174));
        gridLayout_9 = new QGridLayout(uiEffectArea);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setHorizontalSpacing(20);
        selectionFadeLabel = new QLabel(uiEffectArea);
        selectionFadeLabel->setObjectName(QString::fromUtf8("selectionFadeLabel"));

        gridLayout_9->addWidget(selectionFadeLabel, 5, 0, 1, 1);

        menuAnimationEnabledLabel = new QLabel(uiEffectArea);
        menuAnimationEnabledLabel->setObjectName(QString::fromUtf8("menuAnimationEnabledLabel"));

        gridLayout_9->addWidget(menuAnimationEnabledLabel, 4, 0, 1, 1);

        menuAnimationEnabled = new QCheckBox(uiEffectArea);
        menuAnimationEnabled->setObjectName(QString::fromUtf8("menuAnimationEnabled"));

        gridLayout_9->addWidget(menuAnimationEnabled, 4, 1, 1, 1);

        selectionFade = new QCheckBox(uiEffectArea);
        selectionFade->setObjectName(QString::fromUtf8("selectionFade"));

        gridLayout_9->addWidget(selectionFade, 5, 1, 1, 1);

        listBoxSmoothScrolling = new QCheckBox(uiEffectArea);
        listBoxSmoothScrolling->setObjectName(QString::fromUtf8("listBoxSmoothScrolling"));

        gridLayout_9->addWidget(listBoxSmoothScrolling, 3, 1, 1, 1);

        cursorShadowLabel = new QLabel(uiEffectArea);
        cursorShadowLabel->setObjectName(QString::fromUtf8("cursorShadowLabel"));

        gridLayout_9->addWidget(cursorShadowLabel, 1, 0, 1, 1);

        comboBoxAnimation = new QCheckBox(uiEffectArea);
        comboBoxAnimation->setObjectName(QString::fromUtf8("comboBoxAnimation"));

        gridLayout_9->addWidget(comboBoxAnimation, 0, 1, 1, 1);

        listBoxSmoothScrollingLabel = new QLabel(uiEffectArea);
        listBoxSmoothScrollingLabel->setObjectName(QString::fromUtf8("listBoxSmoothScrollingLabel"));

        gridLayout_9->addWidget(listBoxSmoothScrollingLabel, 3, 0, 1, 1);

        hotTracking = new QCheckBox(uiEffectArea);
        hotTracking->setObjectName(QString::fromUtf8("hotTracking"));

        gridLayout_9->addWidget(hotTracking, 2, 1, 1, 1);

        hotTrackingLabel = new QLabel(uiEffectArea);
        hotTrackingLabel->setObjectName(QString::fromUtf8("hotTrackingLabel"));

        gridLayout_9->addWidget(hotTrackingLabel, 2, 0, 1, 1);

        cursorShadow = new QCheckBox(uiEffectArea);
        cursorShadow->setObjectName(QString::fromUtf8("cursorShadow"));

        gridLayout_9->addWidget(cursorShadow, 1, 1, 1, 1);

        comboBoxAnimationLabel = new QLabel(uiEffectArea);
        comboBoxAnimationLabel->setObjectName(QString::fromUtf8("comboBoxAnimationLabel"));

        gridLayout_9->addWidget(comboBoxAnimationLabel, 0, 0, 1, 1);

        toolTipAnimationLabel2 = new QLabel(uiEffectArea);
        toolTipAnimationLabel2->setObjectName(QString::fromUtf8("toolTipAnimationLabel2"));

        gridLayout_9->addWidget(toolTipAnimationLabel2, 7, 0, 1, 1);

        toolTipAnimation = new QCheckBox(uiEffectArea);
        toolTipAnimation->setObjectName(QString::fromUtf8("toolTipAnimation"));

        gridLayout_9->addWidget(toolTipAnimation, 6, 1, 1, 1);

        toolTipAnimationLabel = new QLabel(uiEffectArea);
        toolTipAnimationLabel->setObjectName(QString::fromUtf8("toolTipAnimationLabel"));

        gridLayout_9->addWidget(toolTipAnimationLabel, 6, 0, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_9->addItem(verticalSpacer_8, 8, 0, 1, 1);

        widget_4 = new QWidget(uiEffectArea);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setSpacing(9);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        toolTipAnimationFade = new QRadioButton(widget_4);
        toolTipAnimationFade->setObjectName(QString::fromUtf8("toolTipAnimationFade"));

        horizontalLayout_4->addWidget(toolTipAnimationFade);

        toolTipAnimationSlide = new QRadioButton(widget_4);
        toolTipAnimationSlide->setObjectName(QString::fromUtf8("toolTipAnimationSlide"));

        horizontalLayout_4->addWidget(toolTipAnimationSlide);

        horizontalSpacer_3 = new QSpacerItem(40, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        gridLayout_9->addWidget(widget_4, 7, 1, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_10, 0, 2, 1, 1);

        scrollArea_9->setWidget(uiEffectArea);

        verticalLayout_9->addWidget(scrollArea_9);

        pages->addWidget(uiEffectPage);
        windowPage = new QWidget();
        windowPage->setObjectName(QString::fromUtf8("windowPage"));
        verticalLayout_10 = new QVBoxLayout(windowPage);
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        scrollArea_10 = new QScrollArea(windowPage);
        scrollArea_10->setObjectName(QString::fromUtf8("scrollArea_10"));
        scrollArea_10->setWidgetResizable(true);
        windowArea = new QWidget();
        windowArea->setObjectName(QString::fromUtf8("windowArea"));
        windowArea->setGeometry(QRect(0, 0, 358, 388));
        gridLayout_10 = new QGridLayout(windowArea);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setHorizontalSpacing(20);
        verticalSnapping = new QCheckBox(windowArea);
        verticalSnapping->setObjectName(QString::fromUtf8("verticalSnapping"));

        gridLayout_10->addWidget(verticalSnapping, 9, 1, 1, 1);

        verticalSnappingLabel = new QLabel(windowArea);
        verticalSnappingLabel->setObjectName(QString::fromUtf8("verticalSnappingLabel"));

        gridLayout_10->addWidget(verticalSnappingLabel, 9, 0, 1, 1);

        mouseUndockThreshold = new QSpinBox(windowArea);
        mouseUndockThreshold->setObjectName(QString::fromUtf8("mouseUndockThreshold"));
        mouseUndockThreshold->setMaximum(1000000000);

        gridLayout_10->addWidget(mouseUndockThreshold, 8, 1, 1, 1);

        mouseUndockThresholdLabel = new QLabel(windowArea);
        mouseUndockThresholdLabel->setObjectName(QString::fromUtf8("mouseUndockThresholdLabel"));

        gridLayout_10->addWidget(mouseUndockThresholdLabel, 8, 0, 1, 1);

        mouseDockThreshold = new QSpinBox(windowArea);
        mouseDockThreshold->setObjectName(QString::fromUtf8("mouseDockThreshold"));
        mouseDockThreshold->setMaximum(1000000000);

        gridLayout_10->addWidget(mouseDockThreshold, 7, 1, 1, 1);

        mouseDockThresholdLabel = new QLabel(windowArea);
        mouseDockThresholdLabel->setObjectName(QString::fromUtf8("mouseDockThresholdLabel"));

        gridLayout_10->addWidget(mouseDockThresholdLabel, 7, 0, 1, 1);

        dragMaximize = new QCheckBox(windowArea);
        dragMaximize->setObjectName(QString::fromUtf8("dragMaximize"));

        gridLayout_10->addWidget(dragMaximize, 6, 1, 1, 1);

        dragMaximizeLlabel = new QLabel(windowArea);
        dragMaximizeLlabel->setObjectName(QString::fromUtf8("dragMaximizeLlabel"));

        gridLayout_10->addWidget(dragMaximizeLlabel, 6, 0, 1, 1);

        windowDocking = new QCheckBox(windowArea);
        windowDocking->setObjectName(QString::fromUtf8("windowDocking"));

        gridLayout_10->addWidget(windowDocking, 5, 1, 1, 1);

        windowDockingLabel = new QLabel(windowArea);
        windowDockingLabel->setObjectName(QString::fromUtf8("windowDockingLabel"));

        gridLayout_10->addWidget(windowDockingLabel, 5, 0, 1, 1);

        caretWidth = new QSpinBox(windowArea);
        caretWidth->setObjectName(QString::fromUtf8("caretWidth"));
        caretWidth->setMaximum(10000);

        gridLayout_10->addWidget(caretWidth, 4, 1, 1, 1);

        caretWidthLabel = new QLabel(windowArea);
        caretWidthLabel->setObjectName(QString::fromUtf8("caretWidthLabel"));

        gridLayout_10->addWidget(caretWidthLabel, 4, 0, 1, 1);

        windowBorder = new QSpinBox(windowArea);
        windowBorder->setObjectName(QString::fromUtf8("windowBorder"));
        windowBorder->setMaximum(1000000000);

        gridLayout_10->addWidget(windowBorder, 3, 1, 1, 1);

        windowBorderLlabel = new QLabel(windowArea);
        windowBorderLlabel->setObjectName(QString::fromUtf8("windowBorderLlabel"));

        gridLayout_10->addWidget(windowBorderLlabel, 3, 0, 1, 1);

        windowTrackingDelay = new QSpinBox(windowArea);
        windowTrackingDelay->setObjectName(QString::fromUtf8("windowTrackingDelay"));
        windowTrackingDelay->setMaximum(1000000000);

        gridLayout_10->addWidget(windowTrackingDelay, 2, 1, 1, 1);

        windowTrackingDelayLabel = new QLabel(windowArea);
        windowTrackingDelayLabel->setObjectName(QString::fromUtf8("windowTrackingDelayLabel"));

        gridLayout_10->addWidget(windowTrackingDelayLabel, 2, 0, 1, 1);

        windowTrackingTop = new QCheckBox(windowArea);
        windowTrackingTop->setObjectName(QString::fromUtf8("windowTrackingTop"));

        gridLayout_10->addWidget(windowTrackingTop, 1, 1, 1, 1);

        windowTrackingTopLabel = new QLabel(windowArea);
        windowTrackingTopLabel->setObjectName(QString::fromUtf8("windowTrackingTopLabel"));

        gridLayout_10->addWidget(windowTrackingTopLabel, 1, 0, 1, 1);

        windowTracking = new QCheckBox(windowArea);
        windowTracking->setObjectName(QString::fromUtf8("windowTracking"));

        gridLayout_10->addWidget(windowTracking, 0, 1, 1, 1);

        windowTrackingLabel = new QLabel(windowArea);
        windowTrackingLabel->setObjectName(QString::fromUtf8("windowTrackingLabel"));

        gridLayout_10->addWidget(windowTrackingLabel, 0, 0, 1, 1);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_10->addItem(verticalSpacer_9, 14, 0, 1, 1);

        foregroundFlashCount = new QSpinBox(windowArea);
        foregroundFlashCount->setObjectName(QString::fromUtf8("foregroundFlashCount"));
        foregroundFlashCount->setMaximum(1000000000);

        gridLayout_10->addWidget(foregroundFlashCount, 12, 1, 1, 1);

        fullWindowDraggingLabel = new QLabel(windowArea);
        fullWindowDraggingLabel->setObjectName(QString::fromUtf8("fullWindowDraggingLabel"));

        gridLayout_10->addWidget(fullWindowDraggingLabel, 11, 0, 1, 1);

        fullWindowDragging = new QCheckBox(windowArea);
        fullWindowDragging->setObjectName(QString::fromUtf8("fullWindowDragging"));

        gridLayout_10->addWidget(fullWindowDragging, 11, 1, 1, 1);

        foregroundLockTimeout = new QSpinBox(windowArea);
        foregroundLockTimeout->setObjectName(QString::fromUtf8("foregroundLockTimeout"));
        foregroundLockTimeout->setMaximum(1000000000);

        gridLayout_10->addWidget(foregroundLockTimeout, 13, 1, 1, 1);

        foregroundLockTimeoutLabel = new QLabel(windowArea);
        foregroundLockTimeoutLabel->setObjectName(QString::fromUtf8("foregroundLockTimeoutLabel"));

        gridLayout_10->addWidget(foregroundLockTimeoutLabel, 13, 0, 1, 1);

        foregroundFlashCountLabel = new QLabel(windowArea);
        foregroundFlashCountLabel->setObjectName(QString::fromUtf8("foregroundFlashCountLabel"));

        gridLayout_10->addWidget(foregroundFlashCountLabel, 12, 0, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer_11, 0, 2, 1, 1);

        mouseRestoreThresholdLabel = new QLabel(windowArea);
        mouseRestoreThresholdLabel->setObjectName(QString::fromUtf8("mouseRestoreThresholdLabel"));

        gridLayout_10->addWidget(mouseRestoreThresholdLabel, 10, 0, 1, 1);

        mouseRestoreThreshold = new QSpinBox(windowArea);
        mouseRestoreThreshold->setObjectName(QString::fromUtf8("mouseRestoreThreshold"));
        mouseRestoreThreshold->setMaximum(1000000000);

        gridLayout_10->addWidget(mouseRestoreThreshold, 10, 1, 1, 1);

        scrollArea_10->setWidget(windowArea);

        verticalLayout_10->addWidget(scrollArea_10);

        pages->addWidget(windowPage);

        gridLayout->addWidget(pages, 1, 1, 1, 1);

        label = new QLabel(SystemParametersPane);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMargin(6);

        gridLayout->addWidget(label, 0, 0, 1, 2);


        retranslateUi(SystemParametersPane);
        QObject::connect(parameterGroupList, SIGNAL(currentRowChanged(int)), pages, SLOT(setCurrentIndex(int)));

        pages->setCurrentIndex(8);


        QMetaObject::connectSlotsByName(SystemParametersPane);
    } // setupUi

    void retranslateUi(QWidget *SystemParametersPane)
    {

        const bool __sortingEnabled = parameterGroupList->isSortingEnabled();
        parameterGroupList->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = parameterGroupList->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("SystemParametersPane", "Accessibility parameters", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = parameterGroupList->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("SystemParametersPane", "Desktop parameters", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = parameterGroupList->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("SystemParametersPane", "Icon parameters", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = parameterGroupList->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("SystemParametersPane", "Input parameters", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = parameterGroupList->item(4);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("SystemParametersPane", "Menu parameters", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = parameterGroupList->item(5);
        ___qlistwidgetitem5->setText(QCoreApplication::translate("SystemParametersPane", "Screen saver parameters", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = parameterGroupList->item(6);
        ___qlistwidgetitem6->setText(QCoreApplication::translate("SystemParametersPane", "Time-out parameters", nullptr));
        QListWidgetItem *___qlistwidgetitem7 = parameterGroupList->item(7);
        ___qlistwidgetitem7->setText(QCoreApplication::translate("SystemParametersPane", "UI effect parameters", nullptr));
        QListWidgetItem *___qlistwidgetitem8 = parameterGroupList->item(8);
        ___qlistwidgetitem8->setText(QCoreApplication::translate("SystemParametersPane", "Window parameters", nullptr));
        parameterGroupList->setSortingEnabled(__sortingEnabled);

        mouseVanishLabel->setText(QCoreApplication::translate("SystemParametersPane", "Mouse Vanish", nullptr));
        mouseSonarLabel->setText(QCoreApplication::translate("SystemParametersPane", "Mouse Sonar", nullptr));
        animationsLabel->setText(QCoreApplication::translate("SystemParametersPane", "Animations", nullptr));
        mouseSonar->setText(QString());
        focusBorderLabel->setText(QCoreApplication::translate("SystemParametersPane", "Focus rectangle border", nullptr));
        notificationPopupDurationLabel->setText(QCoreApplication::translate("SystemParametersPane", "Notification pop-up duration", nullptr));
        animations->setText(QString());
        notificationPopupDuration->setSuffix(QCoreApplication::translate("SystemParametersPane", " seconds", nullptr));
        mouseVanish->setText(QString());
        wallpaperPath->setText(QCoreApplication::translate("SystemParametersPane", "###", nullptr));
        fontSmoothingLabel->setText(QCoreApplication::translate("SystemParametersPane", "Font smoothing (antialiasing)", nullptr));
        fontSmoothing->setText(QString());
        dropShadowLabel->setText(QCoreApplication::translate("SystemParametersPane", "Drop shadow effect", nullptr));
        wallpaperPathLabel->setText(QCoreApplication::translate("SystemParametersPane", "Desktop wallpaper path", nullptr));
        clearTypeLabel->setText(QCoreApplication::translate("SystemParametersPane", "ClearType", nullptr));
        dropShadow->setText(QString());
        clearType->setText(QString());
        iconTitleFontLabel->setText(QCoreApplication::translate("SystemParametersPane", "Title font", nullptr));
        iconTitleWrap->setText(QString());
        iconTitleWrapLabel->setText(QCoreApplication::translate("SystemParametersPane", "Wrap titles", nullptr));
        iconSpacingLabel->setText(QCoreApplication::translate("SystemParametersPane", "Spacing", nullptr));
#if QT_CONFIG(tooltip)
        mouseHoverSize->setToolTip(QCoreApplication::translate("SystemParametersPane", "Width and height, in pixels, of the rectangle within which the mouse pointer has to stay for TrackMouseEvent to generate a WM_MOUSEHOVER message.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        snapDefaultButton->setToolTip(QCoreApplication::translate("SystemParametersPane", "Determines whether the snap-to-default-button feature is enabled. If enabled, the mouse cursor automatically moves to the default button, such as OK or Apply, of a dialog box.", nullptr));
#endif // QT_CONFIG(tooltip)
        snapDefaultButton->setText(QString());
#if QT_CONFIG(tooltip)
        mouseWheelX->setToolTip(QCoreApplication::translate("SystemParametersPane", "Number of characters to scroll when the horizontal mouse wheel is moved.", nullptr));
#endif // QT_CONFIG(tooltip)
        mouseWheelX->setSuffix(QCoreApplication::translate("SystemParametersPane", " characters", nullptr));
#if QT_CONFIG(tooltip)
        mouseWheelXLabel->setToolTip(QCoreApplication::translate("SystemParametersPane", "Number of characters to scroll when the horizontal mouse wheel is moved.", nullptr));
#endif // QT_CONFIG(tooltip)
        mouseWheelXLabel->setText(QCoreApplication::translate("SystemParametersPane", "Wheel scroll horizontal", nullptr));
#if QT_CONFIG(tooltip)
        mouseHoverSizeLabel->setToolTip(QCoreApplication::translate("SystemParametersPane", "Width and height, in pixels, of the rectangle within which the mouse pointer has to stay for TrackMouseEvent to generate a WM_MOUSEHOVER message.", nullptr));
#endif // QT_CONFIG(tooltip)
        mouseHoverSizeLabel->setText(QCoreApplication::translate("SystemParametersPane", "Mouse hover size", nullptr));
#if QT_CONFIG(tooltip)
        mouseHoverTime->setToolTip(QCoreApplication::translate("SystemParametersPane", "Time, in milliseconds, that the mouse pointer has to stay in the hover rectangle for TrackMouseEvent to generate a WM_MOUSEHOVER message.", nullptr));
#endif // QT_CONFIG(tooltip)
        mouseHoverTime->setSuffix(QCoreApplication::translate("SystemParametersPane", " milliseconds", nullptr));
#if QT_CONFIG(tooltip)
        mouseHoverTimeLabel->setToolTip(QCoreApplication::translate("SystemParametersPane", "Time, in milliseconds, that the mouse pointer has to stay in the hover rectangle for TrackMouseEvent to generate a WM_MOUSEHOVER message.", nullptr));
#endif // QT_CONFIG(tooltip)
        mouseHoverTimeLabel->setText(QCoreApplication::translate("SystemParametersPane", "Mouse hover time", nullptr));
#if QT_CONFIG(tooltip)
        mouseTrails->setToolTip(QCoreApplication::translate("SystemParametersPane", "This feature improves the visibility of mouse cursor movements by briefly showing a trail of cursors and quickly erasing them.\n"
"Value indicates the number of cursors drawn in the trail.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        mouseTrailsLabel->setToolTip(QCoreApplication::translate("SystemParametersPane", "This feature improves the visibility of mouse cursor movements by briefly showing a trail of cursors and quickly erasing them.\n"
"Value indicates the number of cursors drawn in the trail.", nullptr));
#endif // QT_CONFIG(tooltip)
        mouseTrailsLabel->setText(QCoreApplication::translate("SystemParametersPane", "Mouse trails", nullptr));
#if QT_CONFIG(tooltip)
        mouseSpeed->setToolTip(QCoreApplication::translate("SystemParametersPane", "Current mouse speed.\n"
"The mouse speed determines how far the pointer will move based on the distance the mouse moves. Value ranges between 1 (slowest) and 20 (fastest), with 10 being the default.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        mouseSpeedLabel->setToolTip(QCoreApplication::translate("SystemParametersPane", "Current mouse speed.\n"
"The mouse speed determines how far the pointer will move based on the distance the mouse moves. Value ranges between 1 (slowest) and 20 (fastest), with 10 being the default.", nullptr));
#endif // QT_CONFIG(tooltip)
        mouseSpeedLabel->setText(QCoreApplication::translate("SystemParametersPane", "Mouse speed", nullptr));
#if QT_CONFIG(tooltip)
        keyboardDelay->setToolTip(QCoreApplication::translate("SystemParametersPane", "Keyboard repeat-delay setting, which is a value in the range from 0 (approximately 250 ms delay) through 3 (approximately 1 second delay). The actual delay associated with each value may vary depending on the hardware.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        keyboardDelayLabel->setToolTip(QCoreApplication::translate("SystemParametersPane", "Keyboard repeat-delay setting, which is a value in the range from 0 (approximately 250 ms delay) through 3 (approximately 1 second delay). The actual delay associated with each value may vary depending on the hardware.", nullptr));
#endif // QT_CONFIG(tooltip)
        keyboardDelayLabel->setText(QCoreApplication::translate("SystemParametersPane", "Keyboard delay", nullptr));
#if QT_CONFIG(tooltip)
        keyboardSpeed->setToolTip(QCoreApplication::translate("SystemParametersPane", "Keyboard repeat-speed setting, which is a value in the range from 0 (approximately 2.5 repetitions per second) through 31 (approximately 30 repetitions per second). The actual repeat rates are hardware-dependent and may vary from a linear scale by as much as 20%.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        keyboardSpeedLabel->setToolTip(QCoreApplication::translate("SystemParametersPane", "Keyboard repeat-speed setting, which is a value in the range from 0 (approximately 2.5 repetitions per second) through 31 (approximately 30 repetitions per second). The actual repeat rates are hardware-dependent and may vary from a linear scale by as much as 20%.", nullptr));
#endif // QT_CONFIG(tooltip)
        keyboardSpeedLabel->setText(QCoreApplication::translate("SystemParametersPane", "Keyboard speed", nullptr));
#if QT_CONFIG(tooltip)
        keyboardCues->setToolTip(QCoreApplication::translate("SystemParametersPane", "Determines whether menu access keys are always underlined.", nullptr));
#endif // QT_CONFIG(tooltip)
        keyboardCues->setText(QString());
#if QT_CONFIG(tooltip)
        keyboardCuesLabel->setToolTip(QCoreApplication::translate("SystemParametersPane", "Determines whether menu access keys are always underlined.", nullptr));
#endif // QT_CONFIG(tooltip)
        keyboardCuesLabel->setText(QCoreApplication::translate("SystemParametersPane", "Keyboard cues", nullptr));
#if QT_CONFIG(tooltip)
        blockSimulatedInput->setToolTip(QCoreApplication::translate("SystemParametersPane", "Indicates whether an application can reset the screensaver's timer by calling the SendInput function to simulate keyboard or mouse input. True if the simulated input will be blocked.", nullptr));
#endif // QT_CONFIG(tooltip)
        blockSimulatedInput->setText(QString());
#if QT_CONFIG(tooltip)
        blockSimulatedInputLabel->setToolTip(QCoreApplication::translate("SystemParametersPane", "Indicates whether an application can reset the screensaver's timer by calling the SendInput function to simulate keyboard or mouse input. True if the simulated input will be blocked.", nullptr));
#endif // QT_CONFIG(tooltip)
        blockSimulatedInputLabel->setText(QCoreApplication::translate("SystemParametersPane", "Block simulated input", nullptr));
        beeper->setText(QString());
        beeperLabel->setText(QCoreApplication::translate("SystemParametersPane", "Beeper", nullptr));
#if QT_CONFIG(tooltip)
        mouseWheelYLabel->setToolTip(QCoreApplication::translate("SystemParametersPane", "Number of lines to scroll when the vertical mouse wheel is moved.", nullptr));
#endif // QT_CONFIG(tooltip)
        mouseWheelYLabel->setText(QCoreApplication::translate("SystemParametersPane", "Wheel scroll vertical", nullptr));
#if QT_CONFIG(tooltip)
        mouseWheelY->setToolTip(QCoreApplication::translate("SystemParametersPane", "Number of lines to scroll when the vertical mouse wheel is moved.", nullptr));
#endif // QT_CONFIG(tooltip)
        mouseWheelY->setSuffix(QCoreApplication::translate("SystemParametersPane", " lines", nullptr));
#if QT_CONFIG(tooltip)
        snapDefaultButtonLabel->setToolTip(QCoreApplication::translate("SystemParametersPane", "Determines whether the snap-to-default-button feature is enabled. If enabled, the mouse cursor automatically moves to the default button, such as OK or Apply, of a dialog box.", nullptr));
#endif // QT_CONFIG(tooltip)
        snapDefaultButtonLabel->setText(QCoreApplication::translate("SystemParametersPane", "Snap to default button", nullptr));
        menuAlignmentRight->setText(QCoreApplication::translate("SystemParametersPane", "Left", nullptr));
        menuAlignmentLeft->setText(QCoreApplication::translate("SystemParametersPane", "Right", nullptr));
        menuAnimationFade->setText(QCoreApplication::translate("SystemParametersPane", "Fade", nullptr));
        menuAnimationSlide->setText(QCoreApplication::translate("SystemParametersPane", "Slide", nullptr));
        menuAlignmentLabel->setText(QCoreApplication::translate("SystemParametersPane", "Pop-up menu alignment", nullptr));
        menuAnimationLabel->setText(QCoreApplication::translate("SystemParametersPane", "Menu animation type", nullptr));
#if QT_CONFIG(tooltip)
        menuDelayLabel->setToolTip(QCoreApplication::translate("SystemParametersPane", "Time, in milliseconds, that the system waits before displaying a shortcut menu when the mouse cursor is over a submenu item.", nullptr));
#endif // QT_CONFIG(tooltip)
        menuDelayLabel->setText(QCoreApplication::translate("SystemParametersPane", "Sub-menu show delay", nullptr));
#if QT_CONFIG(tooltip)
        menuDelay->setToolTip(QCoreApplication::translate("SystemParametersPane", "Time, in milliseconds, that the system waits before displaying a shortcut menu when the mouse cursor is over a submenu item.", nullptr));
#endif // QT_CONFIG(tooltip)
        menuDelay->setSuffix(QCoreApplication::translate("SystemParametersPane", " milliseconds", nullptr));
        screenSaverPassword->setText(QString());
        screenSaverPasswordLabel->setText(QCoreApplication::translate("SystemParametersPane", "Password required", nullptr));
        screenSaverTimeoutLabel->setText(QCoreApplication::translate("SystemParametersPane", "Timeout", nullptr));
        screenSaverTimeout->setSuffix(QCoreApplication::translate("SystemParametersPane", " seconds", nullptr));
#if QT_CONFIG(tooltip)
        hungTimeout->setToolTip(QCoreApplication::translate("SystemParametersPane", "Number of milliseconds that the system waits before terminating an application that does not respond to a shutdown request.", nullptr));
#endif // QT_CONFIG(tooltip)
        hungTimeout->setSuffix(QCoreApplication::translate("SystemParametersPane", " milliseconds", nullptr));
#if QT_CONFIG(tooltip)
        killTimeout->setToolTip(QCoreApplication::translate("SystemParametersPane", "Number of milliseconds that the system waits before terminating an application that does not respond to a shutdown request.", nullptr));
#endif // QT_CONFIG(tooltip)
        killTimeout->setSuffix(QCoreApplication::translate("SystemParametersPane", " milliseconds", nullptr));
#if QT_CONFIG(tooltip)
        killServiceTimeout->setToolTip(QCoreApplication::translate("SystemParametersPane", "Number of milliseconds that the service control manager waits before terminating a service that does not respond to a shutdown request.", nullptr));
#endif // QT_CONFIG(tooltip)
        killServiceTimeout->setSuffix(QCoreApplication::translate("SystemParametersPane", " milliseconds", nullptr));
#if QT_CONFIG(tooltip)
        hungTimeoutLabel->setToolTip(QCoreApplication::translate("SystemParametersPane", "Number of milliseconds that the system waits before terminating an application that does not respond to a shutdown request.", nullptr));
#endif // QT_CONFIG(tooltip)
        hungTimeoutLabel->setText(QCoreApplication::translate("SystemParametersPane", "Hung app time-out", nullptr));
#if QT_CONFIG(tooltip)
        killServiceTimeoutLabel->setToolTip(QCoreApplication::translate("SystemParametersPane", "Number of milliseconds that the service control manager waits before terminating a service that does not respond to a shutdown request.", nullptr));
#endif // QT_CONFIG(tooltip)
        killServiceTimeoutLabel->setText(QCoreApplication::translate("SystemParametersPane", "Wait to kill service time-out", nullptr));
#if QT_CONFIG(tooltip)
        killTimeoutLabel->setToolTip(QCoreApplication::translate("SystemParametersPane", "Number of milliseconds that the system waits before terminating an application that does not respond to a shutdown request.", nullptr));
#endif // QT_CONFIG(tooltip)
        killTimeoutLabel->setText(QCoreApplication::translate("SystemParametersPane", "Wait to kill app time-out", nullptr));
#if QT_CONFIG(tooltip)
        selectionFadeLabel->setToolTip(QCoreApplication::translate("SystemParametersPane", "The selection fade effect causes the menu item selected by the user to remain on the screen briefly while fading out after the menu is dismissed.", nullptr));
#endif // QT_CONFIG(tooltip)
        selectionFadeLabel->setText(QCoreApplication::translate("SystemParametersPane", "Menu selection fade", nullptr));
        menuAnimationEnabledLabel->setText(QCoreApplication::translate("SystemParametersPane", "Menu animation", nullptr));
        menuAnimationEnabled->setText(QString());
#if QT_CONFIG(tooltip)
        selectionFade->setToolTip(QCoreApplication::translate("SystemParametersPane", "The selection fade effect causes the menu item selected by the user to remain on the screen briefly while fading out after the menu is dismissed.", nullptr));
#endif // QT_CONFIG(tooltip)
        selectionFade->setText(QString());
        listBoxSmoothScrolling->setText(QString());
        cursorShadowLabel->setText(QCoreApplication::translate("SystemParametersPane", "Cursor shadow", nullptr));
#if QT_CONFIG(tooltip)
        comboBoxAnimation->setToolTip(QCoreApplication::translate("SystemParametersPane", "Determines whether the slide-open effect for combo boxes is enabled.", nullptr));
#endif // QT_CONFIG(tooltip)
        comboBoxAnimation->setText(QString());
        listBoxSmoothScrollingLabel->setText(QCoreApplication::translate("SystemParametersPane", "List box smooth-scrolling", nullptr));
        hotTracking->setText(QString());
#if QT_CONFIG(tooltip)
        hotTrackingLabel->setToolTip(QCoreApplication::translate("SystemParametersPane", "Determines whether hot tracking of user-interface elements, such as menu names on menu bars, is enabled.\n"
"\n"
"Hot tracking means that when the cursor moves over an item, it is highlighted but not selected.", nullptr));
#endif // QT_CONFIG(tooltip)
        hotTrackingLabel->setText(QCoreApplication::translate("SystemParametersPane", "Hot tracking", nullptr));
        cursorShadow->setText(QString());
#if QT_CONFIG(tooltip)
        comboBoxAnimationLabel->setToolTip(QCoreApplication::translate("SystemParametersPane", "Determines whether the slide-open effect for combo boxes is enabled.", nullptr));
#endif // QT_CONFIG(tooltip)
        comboBoxAnimationLabel->setText(QCoreApplication::translate("SystemParametersPane", "Combo box animation", nullptr));
        toolTipAnimationLabel2->setText(QCoreApplication::translate("SystemParametersPane", "ToolTip animation type", nullptr));
        toolTipAnimation->setText(QString());
        toolTipAnimationLabel->setText(QCoreApplication::translate("SystemParametersPane", "ToolTip animation", nullptr));
        toolTipAnimationFade->setText(QCoreApplication::translate("SystemParametersPane", "Fade", nullptr));
        toolTipAnimationSlide->setText(QCoreApplication::translate("SystemParametersPane", "Slide", nullptr));
#if QT_CONFIG(tooltip)
        verticalSnapping->setToolTip(QCoreApplication::translate("SystemParametersPane", "Determines whether a window is vertically maximized when it is sized to the top or bottom of a monitor or monitor array.", nullptr));
#endif // QT_CONFIG(tooltip)
        verticalSnapping->setText(QString());
#if QT_CONFIG(tooltip)
        verticalSnappingLabel->setToolTip(QCoreApplication::translate("SystemParametersPane", "Determines whether a window is vertically maximized when it is sized to the top or bottom of a monitor or monitor array.", nullptr));
#endif // QT_CONFIG(tooltip)
        verticalSnappingLabel->setText(QCoreApplication::translate("SystemParametersPane", "Vertical maximize snapping", nullptr));
#if QT_CONFIG(tooltip)
        mouseUndockThreshold->setToolTip(QCoreApplication::translate("SystemParametersPane", "Threshold in pixels where undocking behavior is triggered by using a mouse to drag a window from the edge of a monitor or a monitor array toward the center.\n"
"Default: 20", nullptr));
#endif // QT_CONFIG(tooltip)
        mouseUndockThreshold->setSuffix(QCoreApplication::translate("SystemParametersPane", " px", nullptr));
#if QT_CONFIG(tooltip)
        mouseUndockThresholdLabel->setToolTip(QCoreApplication::translate("SystemParametersPane", "Threshold in pixels where undocking behavior is triggered by using a mouse to drag a window from the edge of a monitor or a monitor array toward the center.\n"
"Default: 20", nullptr));
#endif // QT_CONFIG(tooltip)
        mouseUndockThresholdLabel->setText(QCoreApplication::translate("SystemParametersPane", "Mouse undock threshold", nullptr));
#if QT_CONFIG(tooltip)
        mouseDockThreshold->setToolTip(QCoreApplication::translate("SystemParametersPane", "Threshold in pixels where docking behavior is triggered by using a mouse to drag a window to the edge of a monitor or monitor array.\n"
"Default: 1", nullptr));
#endif // QT_CONFIG(tooltip)
        mouseDockThreshold->setSuffix(QCoreApplication::translate("SystemParametersPane", " px", nullptr));
#if QT_CONFIG(tooltip)
        mouseDockThresholdLabel->setToolTip(QCoreApplication::translate("SystemParametersPane", "Threshold in pixels where docking behavior is triggered by using a mouse to drag a window to the edge of a monitor or monitor array.\n"
"Default: 1", nullptr));
#endif // QT_CONFIG(tooltip)
        mouseDockThresholdLabel->setText(QCoreApplication::translate("SystemParametersPane", "Mouse dock threshold", nullptr));
#if QT_CONFIG(tooltip)
        dragMaximize->setToolTip(QCoreApplication::translate("SystemParametersPane", "Determines whether a maximized window is restored when its caption bar is dragged.", nullptr));
#endif // QT_CONFIG(tooltip)
        dragMaximize->setText(QString());
#if QT_CONFIG(tooltip)
        dragMaximizeLlabel->setToolTip(QCoreApplication::translate("SystemParametersPane", "Determines whether a maximized window is restored when its caption bar is dragged.", nullptr));
#endif // QT_CONFIG(tooltip)
        dragMaximizeLlabel->setText(QCoreApplication::translate("SystemParametersPane", "Drag from maximize", nullptr));
#if QT_CONFIG(tooltip)
        windowDocking->setToolTip(QCoreApplication::translate("SystemParametersPane", "Determines whether a window is docked when it is moved to the top, left, or right edges of a monitor or monitor array.", nullptr));
#endif // QT_CONFIG(tooltip)
        windowDocking->setText(QString());
#if QT_CONFIG(tooltip)
        windowDockingLabel->setToolTip(QCoreApplication::translate("SystemParametersPane", "Determines whether a window is docked when it is moved to the top, left, or right edges of a monitor or monitor array.", nullptr));
#endif // QT_CONFIG(tooltip)
        windowDockingLabel->setText(QCoreApplication::translate("SystemParametersPane", "Window docked at edge", nullptr));
        caretWidth->setSuffix(QCoreApplication::translate("SystemParametersPane", " px", nullptr));
        caretWidthLabel->setText(QCoreApplication::translate("SystemParametersPane", "Caret width", nullptr));
        windowBorderLlabel->setText(QCoreApplication::translate("SystemParametersPane", "Window sizing border", nullptr));
        windowTrackingDelay->setSuffix(QCoreApplication::translate("SystemParametersPane", " milliseconds", nullptr));
        windowTrackingDelayLabel->setText(QCoreApplication::translate("SystemParametersPane", "Active window tracking delay", nullptr));
#if QT_CONFIG(tooltip)
        windowTrackingTop->setToolTip(QCoreApplication::translate("SystemParametersPane", "Determines whether windows activated through active window tracking will be brought to the top.", nullptr));
#endif // QT_CONFIG(tooltip)
        windowTrackingTop->setText(QString());
#if QT_CONFIG(tooltip)
        windowTrackingTopLabel->setToolTip(QCoreApplication::translate("SystemParametersPane", "Determines whether windows activated through active window tracking will be brought to the top.", nullptr));
#endif // QT_CONFIG(tooltip)
        windowTrackingTopLabel->setText(QCoreApplication::translate("SystemParametersPane", "Active windows to top", nullptr));
        windowTracking->setText(QString());
#if QT_CONFIG(tooltip)
        windowTrackingLabel->setToolTip(QCoreApplication::translate("SystemParametersPane", "Whether active window tracking (activating the window the mouse is on) is on or off.", nullptr));
#endif // QT_CONFIG(tooltip)
        windowTrackingLabel->setText(QCoreApplication::translate("SystemParametersPane", "Active window tracking", nullptr));
#if QT_CONFIG(tooltip)
        foregroundFlashCount->setToolTip(QCoreApplication::translate("SystemParametersPane", "Number of times SetForegroundWindow will flash the taskbar button when rejecting a foreground switch request.", nullptr));
#endif // QT_CONFIG(tooltip)
        fullWindowDraggingLabel->setText(QCoreApplication::translate("SystemParametersPane", "Full window dragging", nullptr));
        fullWindowDragging->setText(QString());
#if QT_CONFIG(tooltip)
        foregroundLockTimeout->setToolTip(QCoreApplication::translate("SystemParametersPane", "Amount of time following user input, in milliseconds, during which the system will not allow applications to force themselves into the foreground.", nullptr));
#endif // QT_CONFIG(tooltip)
        foregroundLockTimeout->setSuffix(QCoreApplication::translate("SystemParametersPane", " milliseconds", nullptr));
#if QT_CONFIG(tooltip)
        foregroundLockTimeoutLabel->setToolTip(QCoreApplication::translate("SystemParametersPane", "Amount of time following user input, in milliseconds, during which the system will not allow applications to force themselves into the foreground.", nullptr));
#endif // QT_CONFIG(tooltip)
        foregroundLockTimeoutLabel->setText(QCoreApplication::translate("SystemParametersPane", "Foreground lock time-out", nullptr));
#if QT_CONFIG(tooltip)
        foregroundFlashCountLabel->setToolTip(QCoreApplication::translate("SystemParametersPane", "Number of times SetForegroundWindow will flash the taskbar button when rejecting a foreground switch request.", nullptr));
#endif // QT_CONFIG(tooltip)
        foregroundFlashCountLabel->setText(QCoreApplication::translate("SystemParametersPane", "Foreground flash count", nullptr));
#if QT_CONFIG(tooltip)
        mouseRestoreThresholdLabel->setToolTip(QCoreApplication::translate("SystemParametersPane", "Threshold in pixels from the top of the monitor where a vertically maximized window is restored when dragged with the mouse.\n"
"Default: 50", nullptr));
#endif // QT_CONFIG(tooltip)
        mouseRestoreThresholdLabel->setText(QCoreApplication::translate("SystemParametersPane", "Mouse vertical restore threshold", nullptr));
#if QT_CONFIG(tooltip)
        mouseRestoreThreshold->setToolTip(QCoreApplication::translate("SystemParametersPane", "Threshold in pixels from the top of the monitor where a vertically maximized window is restored when dragged with the mouse.\n"
"Default: 50", nullptr));
#endif // QT_CONFIG(tooltip)
        mouseRestoreThreshold->setSuffix(QCoreApplication::translate("SystemParametersPane", " px", nullptr));
        label->setText(QCoreApplication::translate("SystemParametersPane", "List of system-wide parameters, obtained from the SystemParametersInfo API function", nullptr));
        (void)SystemParametersPane;
    } // retranslateUi

};

namespace Ui {
    class SystemParametersPane: public Ui_SystemParametersPane {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMPARAMETERSPANE_H

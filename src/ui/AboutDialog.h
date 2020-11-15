/////////////////////////////////////////////////////////////////////
// File: AboutDialog.h                                             //
// Date: 2010-06-15                                                //
// Desc: The dialog shown in Help > About Window Detective.        //
//    Includes version number, description and Qt info.            //
/////////////////////////////////////////////////////////////////////

/********************************************************************
  Window Detective
  Copyright (C) 2010-2017 XTAL256

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
********************************************************************/

#ifndef ABOUT_DIALOG_H
#define ABOUT_DIALOG_H

#include <QtWidgets>
#include "window_detective/include.h"

class MagnifyingGlass;

class AboutDialog : public QDialog {
    Q_OBJECT
public:
    QVBoxLayout* dialogLayout;
    QFrame* mainFrame;
    QHBoxLayout* mainFrameLayout;
    QFrame* leftFrame;
    QLabel* windowImageLabel;
    QFrame* centerFrame;
    QVBoxLayout* centerFrameLayout;
    QLabel* titleLabel;
    QLabel* versionLabel;
    QLabel* descriptionLabel;
    QPlainTextEdit* licenseText;
    QLabel* websiteLabel;
    QFrame* bottomFrame;
    QHBoxLayout* bottomFrameLayout;
    QSpacerItem* horizontalSpacer;
    QLabel* aboutQtLabel;
    QPushButton* aboutQtButton;
    QPushButton* closeButton;
    MagnifyingGlass* magnifyingGlass;

public:
    AboutDialog(QWidget* parent = 0);

    void setupUi();
    void retranslateUi();
private slots:
    void restoreMagnifyingGlassPos();
protected:
    void showEvent(QShowEvent*);
    void hideEvent(QHideEvent*);
    void moveEvent(QMoveEvent*);
};


/* Easter-egg :) */
class MagnifyingGlass : public QWidget {
    Q_OBJECT
public:
    const static int LENS_SIZE = 64;
    QRect lensRect;
    QPixmap magnifyingGlassImage;
    QPixmap windowImage;
    QImage desktopImage;
    QPointF* distortionField;
    QPoint dragPosition;
    String caption;
    int fontPointSize;
    float distortionFactor;
    bool hasGrabbedHandle;

public:
    MagnifyingGlass(QWidget* parent = 0);
    ~MagnifyingGlass();

    QSize sizeHint() const;
    QSize size() const;
    void takeScreenshot();
    bool isInHandle(const QPoint& p) const;
    void computeDistortion();
    QPointF& distortionFieldAt(int x, int y);
    QRgb& pixel(QRgb* pixels, int x, int y) {return *(pixels+(y*LENS_SIZE)+x);}
    const QRgb& pixel(const QRgb* pixels, int x, int y) {return *(pixels+(y*LENS_SIZE)+x);}
protected:
    void mousePressEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void wheelEvent(QWheelEvent*);
    void paintEvent(QPaintEvent*);
signals:
    void finishedLooking();
};

QT_END_NAMESPACE

#endif // ABOUT_DIALOG_H

/////////////////////////////////////////////////////////////////////
// File: AboutDialog.cpp                                           //
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

#include "AboutDialog.h"
#include "window_detective/resource.h"
#include "window_detective/main.h"

AboutDialog::AboutDialog(QWidget* parent) :
    QDialog(parent) {
    setupUi();
    connect(aboutQtButton, SIGNAL(clicked()), qApp, SLOT(aboutQt()));
    connect(closeButton, SIGNAL(clicked()), this, SLOT(reject()));
    connect(magnifyingGlass, SIGNAL(finishedLooking()), this, SLOT(restoreMagnifyingGlassPos()));
}

void AboutDialog::setupUi() {
    resize(500, 400);
    setMinimumSize(400, 300);
    setMaximumSize(800, 600);
    dialogLayout = new QVBoxLayout(this);
    dialogLayout->setContentsMargins(3, 3, 3, 3);
    mainFrame = new QFrame(this);
    mainFrameLayout = new QHBoxLayout(mainFrame);
    mainFrameLayout->setContentsMargins(10, 10, 0, 0);
    leftFrame = new QFrame(mainFrame);
    leftFrame->setMinimumSize(QSize(128, 0));   // Enough for window and magnifying glass
    windowImageLabel = new QLabel(leftFrame);
    QPixmap windowImage(":/img/window_large.png");
    windowImageLabel->setGeometry(QRect(QPoint(7, 24), windowImage.size()));
    windowImageLabel->setMinimumSize(windowImage.size());
    windowImageLabel->setMaximumSize(windowImage.size());
    windowImageLabel->setPixmap(windowImage);
    mainFrameLayout->addWidget(leftFrame);
    centerFrame = new QFrame(mainFrame);
    centerFrameLayout = new QVBoxLayout(centerFrame);
    titleLabel = new QLabel(centerFrame);
    QFont font;
    font.setPointSize(10);
    font.setBold(true);
    font.setWeight(75);
    titleLabel->setFont(font);
    titleLabel->setMinimumSize(QSize(0, 30));
    centerFrameLayout->addWidget(titleLabel);
    versionLabel = new QLabel(centerFrame);
    centerFrameLayout->addWidget(versionLabel);
    descriptionLabel = new QLabel(centerFrame);
    descriptionLabel->setWordWrap(true);
    centerFrameLayout->addWidget(descriptionLabel);
    licenseText = new QPlainTextEdit(centerFrame);
    licenseText->setReadOnly(true);
    licenseText->setLineWrapMode(QPlainTextEdit::NoWrap);
    centerFrameLayout->addWidget(licenseText);
    websiteLabel = new QLabel(centerFrame);
    websiteLabel->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::LinksAccessibleByKeyboard);
    websiteLabel->setOpenExternalLinks(true);
    websiteLabel->setTextFormat(Qt::RichText);
    centerFrameLayout->addWidget(websiteLabel);
    mainFrameLayout->addWidget(centerFrame);
    dialogLayout->addWidget(mainFrame);
    bottomFrame = new QFrame(this);
    bottomFrameLayout = new QHBoxLayout(bottomFrame);
    horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    bottomFrameLayout->addItem(horizontalSpacer);
    aboutQtLabel = new QLabel(bottomFrame);
    bottomFrameLayout->addWidget(aboutQtLabel);
    aboutQtButton = new QPushButton(bottomFrame);
    aboutQtButton->setMinimumSize(QSize(75, 0));
    bottomFrameLayout->addWidget(aboutQtButton);
    closeButton = new QPushButton(bottomFrame);
    closeButton->setMinimumSize(QSize(75, 0));
    bottomFrameLayout->addWidget(closeButton);
    dialogLayout->addWidget(bottomFrame);
    dialogLayout->setStretch(0, 10);
    dialogLayout->setStretch(1, 1);

    magnifyingGlass = new MagnifyingGlass(this);
    magnifyingGlass->hide();
    magnifyingGlass->move(leftFrame->mapToGlobal(QPoint(21, 0)));

    retranslateUi();
}

void AboutDialog::retranslateUi() {
    setWindowTitle(tr("About") + " " + APP_NAME);
    titleLabel->setText(APP_NAME);
    versionLabel->setText(tr("Version") + " " + VERSION_STR);
    descriptionLabel->setText(tr(LONG_DESC));
    QString linkString = "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" "\
                    "\"http://www.w3.org/TR/REC-html40/strict.dtd\"><html><body>"\
                    "<a href=\"" WEBSITE "\">" WEBSITE "</a></body></html>";
    websiteLabel->setText(linkString);
    aboutQtLabel->setText(tr("This program is built using the Qt framework"));
    aboutQtButton->setText(tr("About &Qt"));
    closeButton->setText(tr("&Close"));

    QFile licenseFile(appPath() + "/copying.txt");
    if (licenseFile.exists()) {
        if (licenseFile.open(QFile::ReadOnly)) {
            QTextStream stream(&licenseFile);
            licenseText->setPlainText(stream.readAll());
        }
        else {
            licenseText->setPlainText(tr("Could not open license file"));
        }
    }
    else {
        licenseText->setPlainText(tr("License file not found"));
    }
}

void AboutDialog::restoreMagnifyingGlassPos() {
    magnifyingGlass->move(leftFrame->mapToGlobal(QPoint(21, 0)));
    magnifyingGlass->show();
}

void AboutDialog::showEvent(QShowEvent*) {
    restoreMagnifyingGlassPos();
    magnifyingGlass->takeScreenshot();
}

void AboutDialog::hideEvent(QHideEvent*) {
    magnifyingGlass->hide();
}

void AboutDialog::moveEvent(QMoveEvent*) {
    restoreMagnifyingGlassPos();
}


/***********************/
/***  Easter-egg :)  ***/
/***********************/

MagnifyingGlass::MagnifyingGlass(QWidget* parent) :
    QWidget(parent, Qt::Tool | Qt::FramelessWindowHint),
    lensRect(5, 5, LENS_SIZE, LENS_SIZE),
    fontPointSize(-1),
    distortionFactor(0.74f),
    hasGrabbedHandle(false),
    distortionField(NULL), desktopImage(),
    caption("Thank you for using Window Detective!"),
    magnifyingGlassImage(":/img/magnifying_glass.png"),
    windowImage(":/img/window_large.png") {
    setMask(magnifyingGlassImage.mask());
    setMouseTracking(true);
    computeDistortion();
}

MagnifyingGlass::~MagnifyingGlass() {
    if (distortionField) delete[] distortionField;
}

QSize MagnifyingGlass::sizeHint() const {
    return magnifyingGlassImage.size();
}

QSize MagnifyingGlass::size() const {
    return magnifyingGlassImage.size();
}

void MagnifyingGlass::computeDistortion() {
    // I could use only a quarter of the size, since the distortion
    // can be mirrored vertically and horizontally. But it's easier this way.
    const int halfWidth = LENS_SIZE / 2;
    const int halfHeight = LENS_SIZE / 2;
    if (distortionField) delete[] distortionField;
    distortionField = new QPointF[LENS_SIZE * LENS_SIZE];

    for (int y = 0; y < LENS_SIZE; ++y) {
        for (int x = 0; x < LENS_SIZE; ++x) {
            float cx = (float)(x - halfWidth);
            float cy = (float)(y - halfHeight);
            float oldRadius = sqrt((cx * cx) + (cy * cy));
            float angle = atan2(cy, cx);

            float newRadius = distortionFactor * (1.0f/cos(oldRadius*0.02)) * oldRadius;
            float newX = (newRadius * cos(angle)) + halfWidth;
            float newY = (newRadius * sin(angle)) + halfHeight;

            distortionFieldAt(x, y) = QPointF(newX, newY);
        }
    }
}

QPointF& MagnifyingGlass::distortionFieldAt(int x, int y) {
    return *(distortionField + (y * LENS_SIZE) + x);
}

QRgb blend(float rx1, float rx2, float ry1, float ry2,
           QRgb p11, QRgb p21, QRgb p12, QRgb p22) {

    // ((rx1 * ry1) * p11) + ((rx2 * ry1) * p21) + ((rx1 * ry2) * p12) + ((rx2 * ry2) * p22)
    float red11 = (rx1 * ry1) * qRed(p11);
    float green11 = (rx1 * ry1) * qGreen(p11);
    float blue11 = (rx1 * ry1) * qBlue(p11);

    float red21 = (rx2 * ry1) * qRed(p21);
    float green21 = (rx2 * ry1) * qGreen(p21);
    float blue21 = (rx2 * ry1) * qBlue(p21);

    float red12 = (rx1 * ry2) * qRed(p12);
    float green12 = (rx1 * ry2) * qGreen(p12);
    float blue12 = (rx1 * ry2) * qBlue(p12);

    float red22 = (rx2 * ry2) * qRed(p22);
    float green22 = (rx2 * ry2) * qGreen(p22);
    float blue22 = (rx2 * ry2) * qBlue(p22);

    int red = (int)(red11 + red12 + red21 + red22);
    int green = (int)(green11 + green12 + green21 + green22);
    int blue = (int)(blue11 + blue12 + blue21 + blue22);

    return qRgb(red, green, blue);
}

void MagnifyingGlass::takeScreenshot() {
    QDesktopWidget* desktop = QApplication::desktop();
    QPixmap desktopPixmap = QPixmap::grabWindow(desktop->winId(), 0, 0, desktop->width(), desktop->height());
	QRect screenRect = desktop->availableGeometry();

    QPainter painter(&desktopPixmap);

    // Draw over the top of the MagnifyingGlass in the screenshot
    QPoint absolutePos = mapToGlobal(QPoint(0, 0));
    QPalette palette = QApplication::palette();
    painter.fillRect(QRect(absolutePos, size()), palette.window().color());
    painter.drawPixmap(absolutePos + QPoint(-14, 24), windowImage);

    // Make sure the text fits - start at 50pt and decrement if necessary
    QFont font("Arial", 50);
    if (fontPointSize == -1) {
        fontPointSize = 50;
        int count = 0;
        int textWidth = screenRect.width() - 40;   // 20px on either size
        while (count < 10 && (QFontMetrics(font).width(caption) > textWidth)) {
            fontPointSize -= 3;
            font.setPointSizeF(fontPointSize);
            ++count;
        }
    }

    font.setStyleStrategy(QFont::ForceOutline);
    painter.setRenderHint(QPainter::Antialiasing);
    QPainterPath textPath;

    textPath.addText(screenRect.x() + 20, screenRect.y() + QFontMetrics(font).height() + 20, font, caption);
    painter.setPen(QPen(Qt::white, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    QLinearGradient gradient(0, 0, 0, 100);
    gradient.setColorAt(0.0, QColor(255, 0, 0));
    gradient.setColorAt(1.0, QColor(255, 128, 0));
    painter.setBrush(gradient);
    painter.drawPath(textPath);

    desktopImage = desktopPixmap.toImage();
}

bool MagnifyingGlass::isInHandle(const QPoint& p) const {
    return (p.x() > 65) && (p.y() > 64);
}

void MagnifyingGlass::mousePressEvent(QMouseEvent* e) {
    if (e->button() == Qt::LeftButton) {
        if (isInHandle(e->pos())) {
            hasGrabbedHandle = true;
            setCursor(Qt::ClosedHandCursor);
            dragPosition = e->globalPos() - pos();
            takeScreenshot();
        }
    }
}

void MagnifyingGlass::mouseReleaseEvent(QMouseEvent* e) {
    if (e->button() == Qt::LeftButton) {
        if (isInHandle(e->pos())) {
            setCursor(Qt::OpenHandCursor);
        }
        else {
            unsetCursor();
        }
        hasGrabbedHandle = false;
        update(lensRect);
        emit finishedLooking();
    }
}

void MagnifyingGlass::mouseMoveEvent(QMouseEvent* e) {
    if ((e->buttons() & Qt::LeftButton) && hasGrabbedHandle) {
        move(e->globalPos() - dragPosition);
        repaint(lensRect);
    }
    else {
        if (isInHandle(e->pos())) {
            setCursor(Qt::OpenHandCursor);
        }
        else {
            unsetCursor();
        }
    }
}

void MagnifyingGlass::wheelEvent(QWheelEvent* e) {
    if (hasGrabbedHandle) {
        int numDegrees = e->delta() / 8;   // See doco on QWheelEvent::delta for magic numbers
        int numSteps = numDegrees / 15;
        distortionFactor += 0.01f * (float)numSteps;
        computeDistortion();
        repaint(lensRect);
        e->accept();
    }
    else {
        e->ignore();
    }
}

void MagnifyingGlass::paintEvent(QPaintEvent*) {
    QPainter painter(this);

    QRect sourceRect = lensRect.translated(mapToGlobal(QPoint(0, 0)));
    QImage originalImage = desktopImage.copy(sourceRect);
    QImage warpedImage(LENS_SIZE, LENS_SIZE, originalImage.format());
    warpedImage.fill(0xffffffff);
    const QRgb* oldPixels = (QRgb*)originalImage.bits();
    QRgb* newPixels = (QRgb*)warpedImage.bits();

    for (int y = 0; y < LENS_SIZE; ++y) {
        for (int x = 0; x < LENS_SIZE; ++x) {
            QPointF newPos = distortionFieldAt(x, y);
            int newX = (int)newPos.x();
            int newY = (int)newPos.y();

            float rx2 = newPos.x() - (float)newX;   // Ratios
            float rx1 = 1 - rx2;
            float ry2 = newPos.y() - (float)newY;
            float ry1 = 1 - ry2;

            if (newX >= 0 && newY >= 0 && newX < LENS_SIZE-1 && newY < LENS_SIZE-1) {
                QRgb p11 = pixel(oldPixels, newX, newY);
                QRgb p21 = pixel(oldPixels, newX+1, newY);
                QRgb p12 = pixel(oldPixels, newX, newY+1);
                QRgb p22 = pixel(oldPixels, newX+1, newY+1);

                pixel(newPixels, x, y) = blend(rx1, rx2, ry1, ry2, p11, p21, p12, p22);
            }
        }
    }

    painter.drawImage(lensRect, warpedImage);
    painter.drawPixmap(0, 0, magnifyingGlassImage);

    // Testing //////////////
    // x axis is original radius, y axis is the radius after distortion
    /*painter.setPen(Qt::red);
    for (int x = 0; x < LENS_SIZE-1; ++x) {
        painter.drawLine(x+5,
                         69 - (distortionFactor * (1.0f/cos(x*0.02)) * x),
                         x+6,
                         69 - (distortionFactor * (1.0f/cos((x+1)*0.02)) * x)
                        );
    }*/
    /////////////////////////
}

/////////////////////////////////////////////////////////////////////
// File: PropertiesPane.cpp                                        //
// Date: 2010-03-23                                                //
// Desc: Used to display the properties of a window. Typically     //
//   added to an MDI area as a child window.                       //
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

#include "PropertiesPane.h"
#include "GenericPropertyPage.h"
#include "WindowClassPropertyPage.h"
#include "inspector/WindowManager.h"

/*--------------------------------------------------------------------------+
| Constructor.                                                              |
+--------------------------------------------------------------------------*/
PropertiesPane::PropertiesPane(Window* window, QWidget* parent) :
    QMainWindow(parent), model(window),
    pages(), hasInitialized() {
    setupUi(this);
    Q_ASSERT(window != NULL);

    connect(actnLocate, SIGNAL(triggered()), this, SLOT(locateActionTriggered()));
    connect(actnFlash, SIGNAL(triggered()), this, SLOT(flashActionTriggered()));
    connect(actnSave, SIGNAL(triggered()), this, SLOT(saveToFile()));
    connect(tabWidget, SIGNAL(currentChanged(int)), this, SLOT(updateTabPage(int)));

    setWindowTitle(tr("Window Properties - %1").arg(model->getDisplayName()));
    createPages();
    updateTabPage(0);  // Initialize first page only
}

/*--------------------------------------------------------------------------+
| Creates the property pages and adds them to tabs.                         |
+--------------------------------------------------------------------------*/
void PropertiesPane::createPages() {
    QList<AbstractPropertyPage*> modelPages = model->makePropertyPages();
    QList<AbstractPropertyPage*>::const_iterator i;
    for (i = modelPages.begin(); i != modelPages.end(); ++i) {
        addPropertyPage(*i, (*i)->windowTitle());
    }
    addPropertyPage(new WindowClassPropertyPage(model->getWindowClass()), "Window Class");
}

/*--------------------------------------------------------------------------+
| Adds the given widget as a tab with the given title.                      |
+--------------------------------------------------------------------------*/
void PropertiesPane::addPropertyPage(AbstractPropertyPage* page, String title) {
    page->setOwner(this);
    page->setupUi();
    QScrollArea* scrollArea = new QScrollArea(this);
    scrollArea->setWidget(page);
    scrollArea->setWidgetResizable(true);
    scrollArea->setFrameShape(QFrame::NoFrame);
    scrollArea->setLineWidth(0);
    tabWidget->addTab(scrollArea, title);
    pages.append(page);
    hasInitialized.append(false);
}

/*--------------------------------------------------------------------------+
| Called when a window is deleted. If it's the one this pane is showing,    |
| then set it to NULL so we don't de-ref an invalid object.                 |
+--------------------------------------------------------------------------*/
void PropertiesPane::windowDeleted(Window* wnd) {
    if (wnd == model) {
        model = NULL;
        setEnabled(false);
    }
}

/*--------------------------------------------------------------------------+
| This just forwards the signal on with the model.                          |
+--------------------------------------------------------------------------*/
void PropertiesPane::locateActionTriggered() {
    emit locateWindow(model);
}

void PropertiesPane::flashActionTriggered() {
    if (model) {
        model->flash();
    }
}

/*--------------------------------------------------------------------------+
| A link was clicked in one of the property pages. Process it and           |
| notify any objects interested.                                            |
+--------------------------------------------------------------------------*/
void PropertiesPane::linkClicked(const String& link) {
    if (link.startsWith("hwnd:")) {
        bool isOk = true;
        HWND handle = (HWND)link.mid(5).toUInt(&isOk, 0);
        Window* window = WindowManager::current().find(handle);
        if (window) emit locateWindow(window);
    }
}

/*--------------------------------------------------------------------------+
| Opens the "Save File" dialog then writes the properties to the            |
| selected file in either text or xml format.                               |
+--------------------------------------------------------------------------*/
void PropertiesPane::saveToFile() {
    String fileName = QFileDialog::getSaveFileName(this, tr("Save Window Properties"),
                        QDir::homePath(), "XML Files (*.xml);;All Files (*.*)");
    if (fileName.isEmpty()) {
        return;    // User cancelled
    }

    QFile file(fileName);
    if (!file.open(QFile::WriteOnly)) {
        String msg = tr("Could not open file for writing.\n\"%1\"").arg(fileName);
        QMessageBox::warning(this, tr("Save Window Properties"), msg);
        Logger::error(msg);
        return;
    }
    
    QXmlStreamWriter stream(&file);
    stream.setAutoFormatting(true);
    stream.setAutoFormattingIndent(4);  // 4 spaces
    stream.writeStartDocument();
    stream.writeComment(tr("\nProperties for window %1\nCreated by Window Detective\n")
                           .arg(model->getDisplayName()));
    model->toXmlStream(stream);
    stream.writeEndDocument();
}

/*--------------------------------------------------------------------------+
| The tab page has just changed. If the newly selected page has not         |
| been initialized yet, do it now.                                          |
+--------------------------------------------------------------------------*/
void PropertiesPane::updateTabPage(int index) {
    if (index < hasInitialized.size() && !hasInitialized.at(index)) {
        pages.at(index)->updateProperties();
        hasInitialized[index] = true;
    }
}

/*--------------------------------------------------------------------------+
| The window has changed, set the properties again.                         |
+--------------------------------------------------------------------------*/
void PropertiesPane::update() {
    // Set initialized flag to false for each page.
    QList<bool>::iterator i;
    for (i = hasInitialized.begin(); i != hasInitialized.end(); ++i) {
        *i = false;
    }

    // Now refresh the current page
    updateTabPage(tabWidget->currentIndex());
}

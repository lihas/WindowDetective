/////////////////////////////////////////////////////////////////////
// File: CustomComboBoxes.h                                        //
// Date: 2010-04-01                                                //
// Desc: Specialized combo boxes that hold a list of objects such  //
//   as windows, window classes and window styles.                 //
//   Each provide an auto-complete feature for choosing an item.   //
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

#ifndef CUSTOM_COMBO_BOXES_H
#define CUSTOM_COMBO_BOXES_H

#include <QtWidgets>
#include "window_detective/include.h"
#include "inspector/inspector.h"


/*********************/
/*** Generic class ***/
/*********************/
template<class T>
class ObjectComboBox : public QComboBox {
protected:
    QList<T*> objects;

public:
    ObjectComboBox(QWidget* parent = 0) :
        QComboBox(parent),
        objects() {
        setEditable(true);
        view()->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    }

    T* currentValue() {
        int index = this->currentIndex();
        return index == -1 ? NULL : objects.at(index);
    }

    QList<T> getList() {
        return objects;
    }

    void setList(QList<T*> list) { 
        QStringList completerList;
        objects = list;

        // TODO: Selecting an item from completer list does not update icon or current index
        clear();
        foreach (T* object, list) {
            addItem(object->getIcon(), object->getDisplayName());
            completerList << object->getDisplayName();
        }

        QCompleter* completer = new QCompleter(completerList, this);
        completer->setCaseSensitivity(Qt::CaseInsensitive);
        completer->setCompletionMode(QCompleter::PopupCompletion);
        setCompleter(completer);
    }
};


class WindowClassComboBox : public ObjectComboBox<WindowClass> {
public: WindowClassComboBox(QWidget* parent = 0) : ObjectComboBox(parent) {}
};

class WindowComboBox : public ObjectComboBox<Window> {
public: WindowComboBox(QWidget* parent = 0) : ObjectComboBox(parent) {}
};

class WindowStyleComboBox : public ObjectComboBox<WindowStyle> {
public: WindowStyleComboBox(QWidget* parent = 0) : ObjectComboBox(parent) {}
};

class ProcessComboBox : public ObjectComboBox<Process> {
public: ProcessComboBox(QWidget* parent = 0) : ObjectComboBox(parent) {}
};


#endif   // CUSTOM_COMBO_BOXES_H
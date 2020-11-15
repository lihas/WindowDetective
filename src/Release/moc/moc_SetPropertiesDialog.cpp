/****************************************************************************
** Meta object code from reading C++ file 'SetPropertiesDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ui/SetPropertiesDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SetPropertiesDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SetPropertiesDialog_t {
    QByteArrayData data[10];
    char stringdata[174];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_SetPropertiesDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_SetPropertiesDialog_t qt_meta_stringdata_SetPropertiesDialog = {
    {
QT_MOC_LITERAL(0, 0, 19),
QT_MOC_LITERAL(1, 20, 15),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 20),
QT_MOC_LITERAL(4, 58, 20),
QT_MOC_LITERAL(5, 79, 16),
QT_MOC_LITERAL(6, 96, 16),
QT_MOC_LITERAL(7, 113, 16),
QT_MOC_LITERAL(8, 130, 25),
QT_MOC_LITERAL(9, 156, 16)
    },
    "SetPropertiesDialog\0propertyChanged\0"
    "\0dimensionTextChanged\0posOrSizeTextChanged\0"
    "updateStylesList\0styleItemChanged\0"
    "QListWidgetItem*\0styleItemSelectionChanged\0"
    "setButtonClicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SetPropertiesDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08,
       3,    0,   50,    2, 0x08,
       4,    0,   51,    2, 0x08,
       5,    0,   52,    2, 0x08,
       6,    1,   53,    2, 0x08,
       8,    1,   56,    2, 0x08,
       9,    0,   59,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void,

       0        // eod
};

void SetPropertiesDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SetPropertiesDialog *_t = static_cast<SetPropertiesDialog *>(_o);
        switch (_id) {
        case 0: _t->propertyChanged(); break;
        case 1: _t->dimensionTextChanged(); break;
        case 2: _t->posOrSizeTextChanged(); break;
        case 3: _t->updateStylesList(); break;
        case 4: _t->styleItemChanged((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 5: _t->styleItemSelectionChanged((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 6: _t->setButtonClicked(); break;
        default: ;
        }
    }
}

const QMetaObject SetPropertiesDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SetPropertiesDialog.data,
      qt_meta_data_SetPropertiesDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *SetPropertiesDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SetPropertiesDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SetPropertiesDialog.stringdata))
        return static_cast<void*>(const_cast< SetPropertiesDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int SetPropertiesDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

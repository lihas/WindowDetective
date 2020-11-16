/****************************************************************************
** Meta object code from reading C++ file 'SetPropertiesDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ui/SetPropertiesDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SetPropertiesDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SetPropertiesDialog_t {
    QByteArrayData data[10];
    char stringdata0[173];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SetPropertiesDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SetPropertiesDialog_t qt_meta_stringdata_SetPropertiesDialog = {
    {
QT_MOC_LITERAL(0, 0, 19), // "SetPropertiesDialog"
QT_MOC_LITERAL(1, 20, 15), // "propertyChanged"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 20), // "dimensionTextChanged"
QT_MOC_LITERAL(4, 58, 20), // "posOrSizeTextChanged"
QT_MOC_LITERAL(5, 79, 16), // "updateStylesList"
QT_MOC_LITERAL(6, 96, 16), // "styleItemChanged"
QT_MOC_LITERAL(7, 113, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(8, 130, 25), // "styleItemSelectionChanged"
QT_MOC_LITERAL(9, 156, 16) // "setButtonClicked"

    },
    "SetPropertiesDialog\0propertyChanged\0"
    "\0dimensionTextChanged\0posOrSizeTextChanged\0"
    "updateStylesList\0styleItemChanged\0"
    "QListWidgetItem*\0styleItemSelectionChanged\0"
    "setButtonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SetPropertiesDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    1,   53,    2, 0x08 /* Private */,
       8,    1,   56,    2, 0x08 /* Private */,
       9,    0,   59,    2, 0x08 /* Private */,

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
        auto *_t = static_cast<SetPropertiesDialog *>(_o);
        Q_UNUSED(_t)
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

QT_INIT_METAOBJECT const QMetaObject SetPropertiesDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_SetPropertiesDialog.data,
    qt_meta_data_SetPropertiesDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SetPropertiesDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SetPropertiesDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SetPropertiesDialog.stringdata0))
        return static_cast<void*>(this);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE

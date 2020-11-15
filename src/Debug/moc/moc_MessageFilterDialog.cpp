/****************************************************************************
** Meta object code from reading C++ file 'MessageFilterDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ui/MessageFilterDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MessageFilterDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MessageFilterDialog_t {
    QByteArrayData data[12];
    char stringdata[185];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MessageFilterDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MessageFilterDialog_t qt_meta_stringdata_MessageFilterDialog = {
    {
QT_MOC_LITERAL(0, 0, 19),
QT_MOC_LITERAL(1, 20, 10),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 10),
QT_MOC_LITERAL(4, 43, 15),
QT_MOC_LITERAL(5, 59, 15),
QT_MOC_LITERAL(6, 75, 15),
QT_MOC_LITERAL(7, 91, 24),
QT_MOC_LITERAL(8, 116, 26),
QT_MOC_LITERAL(9, 143, 3),
QT_MOC_LITERAL(10, 147, 6),
QT_MOC_LITERAL(11, 154, 29)
    },
    "MessageFilterDialog\0includeAll\0\0"
    "excludeAll\0includeSelected\0excludeSelected\0"
    "addNewHighlight\0removeSelectedHighlights\0"
    "highlightCellDoubleClicked\0row\0column\0"
    "highlightItemSelectionChanged\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MessageFilterDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x0a,
       3,    0,   55,    2, 0x0a,
       4,    0,   56,    2, 0x0a,
       5,    0,   57,    2, 0x0a,
       6,    0,   58,    2, 0x0a,
       7,    0,   59,    2, 0x0a,
       8,    2,   60,    2, 0x0a,
      11,    0,   65,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::Void,

       0        // eod
};

void MessageFilterDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MessageFilterDialog *_t = static_cast<MessageFilterDialog *>(_o);
        switch (_id) {
        case 0: _t->includeAll(); break;
        case 1: _t->excludeAll(); break;
        case 2: _t->includeSelected(); break;
        case 3: _t->excludeSelected(); break;
        case 4: _t->addNewHighlight(); break;
        case 5: _t->removeSelectedHighlights(); break;
        case 6: _t->highlightCellDoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->highlightItemSelectionChanged(); break;
        default: ;
        }
    }
}

const QMetaObject MessageFilterDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MessageFilterDialog.data,
      qt_meta_data_MessageFilterDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *MessageFilterDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MessageFilterDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MessageFilterDialog.stringdata))
        return static_cast<void*>(const_cast< MessageFilterDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int MessageFilterDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

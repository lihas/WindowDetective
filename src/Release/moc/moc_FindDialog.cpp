/****************************************************************************
** Meta object code from reading C++ file 'FindDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ui/FindDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FindDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FindDialog_t {
    QByteArrayData data[12];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FindDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FindDialog_t qt_meta_stringdata_FindDialog = {
    {
QT_MOC_LITERAL(0, 0, 10), // "FindDialog"
QT_MOC_LITERAL(1, 11, 17), // "singleWindowFound"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 7), // "Window*"
QT_MOC_LITERAL(4, 38, 12), // "focusChanged"
QT_MOC_LITERAL(5, 51, 8), // "QWidget*"
QT_MOC_LITERAL(6, 60, 3), // "old"
QT_MOC_LITERAL(7, 64, 3), // "now"
QT_MOC_LITERAL(8, 68, 15), // "addCriteriaItem"
QT_MOC_LITERAL(9, 84, 6), // "sender"
QT_MOC_LITERAL(10, 91, 18), // "removeCriteriaItem"
QT_MOC_LITERAL(11, 110, 17) // "findButtonClicked"

    },
    "FindDialog\0singleWindowFound\0\0Window*\0"
    "focusChanged\0QWidget*\0old\0now\0"
    "addCriteriaItem\0sender\0removeCriteriaItem\0"
    "findButtonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FindDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   42,    2, 0x08 /* Private */,
       8,    1,   47,    2, 0x08 /* Private */,
      10,    1,   50,    2, 0x08 /* Private */,
      11,    0,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5,    6,    7,
    QMetaType::Void, 0x80000000 | 5,    9,
    QMetaType::Void, 0x80000000 | 5,    9,
    QMetaType::Void,

       0        // eod
};

void FindDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FindDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->singleWindowFound((*reinterpret_cast< Window*(*)>(_a[1]))); break;
        case 1: _t->focusChanged((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2]))); break;
        case 2: _t->addCriteriaItem((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 3: _t->removeCriteriaItem((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 4: _t->findButtonClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Window* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FindDialog::*)(Window * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FindDialog::singleWindowFound)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FindDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_FindDialog.data,
    qt_meta_data_FindDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FindDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FindDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FindDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int FindDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void FindDialog::singleWindowFound(Window * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

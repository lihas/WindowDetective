/****************************************************************************
** Meta object code from reading C++ file 'MessagesPane.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ui/MessagesPane.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MessagesPane.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MessagesPane_t {
    QByteArrayData data[11];
    char stringdata0[171];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MessagesPane_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MessagesPane_t qt_meta_stringdata_MessagesPane = {
    {
QT_MOC_LITERAL(0, 0, 12), // "MessagesPane"
QT_MOC_LITERAL(1, 13, 12), // "locateWindow"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 7), // "Window*"
QT_MOC_LITERAL(4, 35, 13), // "windowDeleted"
QT_MOC_LITERAL(5, 49, 21), // "locateActionTriggered"
QT_MOC_LITERAL(6, 71, 17), // "saveButtonClicked"
QT_MOC_LITERAL(7, 89, 14), // "toggleRunState"
QT_MOC_LITERAL(8, 104, 23), // "autoExpandButtonClicked"
QT_MOC_LITERAL(9, 128, 19), // "filterButtonClicked"
QT_MOC_LITERAL(10, 148, 22) // "highlightButtonClicked"

    },
    "MessagesPane\0locateWindow\0\0Window*\0"
    "windowDeleted\0locateActionTriggered\0"
    "saveButtonClicked\0toggleRunState\0"
    "autoExpandButtonClicked\0filterButtonClicked\0"
    "highlightButtonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MessagesPane[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   57,    2, 0x08 /* Private */,
       5,    0,   60,    2, 0x08 /* Private */,
       6,    0,   61,    2, 0x08 /* Private */,
       7,    0,   62,    2, 0x08 /* Private */,
       8,    0,   63,    2, 0x08 /* Private */,
       9,    0,   64,    2, 0x08 /* Private */,
      10,    0,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MessagesPane::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MessagesPane *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->locateWindow((*reinterpret_cast< Window*(*)>(_a[1]))); break;
        case 1: _t->windowDeleted((*reinterpret_cast< Window*(*)>(_a[1]))); break;
        case 2: _t->locateActionTriggered(); break;
        case 3: _t->saveButtonClicked(); break;
        case 4: _t->toggleRunState(); break;
        case 5: _t->autoExpandButtonClicked(); break;
        case 6: _t->filterButtonClicked(); break;
        case 7: _t->highlightButtonClicked(); break;
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
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Window* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MessagesPane::*)(Window * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessagesPane::locateWindow)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MessagesPane::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MessagesPane.data,
    qt_meta_data_MessagesPane,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MessagesPane::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MessagesPane::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MessagesPane.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MessagesPane::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void MessagesPane::locateWindow(Window * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

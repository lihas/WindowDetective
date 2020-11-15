/****************************************************************************
** Meta object code from reading C++ file 'MessagesPane.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ui/MessagesPane.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MessagesPane.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MessagesPane_t {
    QByteArrayData data[11];
    char stringdata[172];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MessagesPane_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MessagesPane_t qt_meta_stringdata_MessagesPane = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 12),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 7),
QT_MOC_LITERAL(4, 35, 13),
QT_MOC_LITERAL(5, 49, 21),
QT_MOC_LITERAL(6, 71, 17),
QT_MOC_LITERAL(7, 89, 14),
QT_MOC_LITERAL(8, 104, 23),
QT_MOC_LITERAL(9, 128, 19),
QT_MOC_LITERAL(10, 148, 22)
    },
    "MessagesPane\0locateWindow\0\0Window*\0"
    "windowDeleted\0locateActionTriggered\0"
    "saveButtonClicked\0toggleRunState\0"
    "autoExpandButtonClicked\0filterButtonClicked\0"
    "highlightButtonClicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MessagesPane[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       4,    1,   57,    2, 0x08,
       5,    0,   60,    2, 0x08,
       6,    0,   61,    2, 0x08,
       7,    0,   62,    2, 0x08,
       8,    0,   63,    2, 0x08,
       9,    0,   64,    2, 0x08,
      10,    0,   65,    2, 0x08,

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
        MessagesPane *_t = static_cast<MessagesPane *>(_o);
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
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MessagesPane::*_t)(Window * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MessagesPane::locateWindow)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject MessagesPane::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MessagesPane.data,
      qt_meta_data_MessagesPane,  qt_static_metacall, 0, 0}
};


const QMetaObject *MessagesPane::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MessagesPane::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MessagesPane.stringdata))
        return static_cast<void*>(const_cast< MessagesPane*>(this));
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
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'WindowManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../inspector/WindowManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WindowManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WindowManager_t {
    QByteArrayData data[10];
    char stringdata[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_WindowManager_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_WindowManager_t qt_meta_stringdata_WindowManager = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 11),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 7),
QT_MOC_LITERAL(4, 35, 6),
QT_MOC_LITERAL(5, 42, 13),
QT_MOC_LITERAL(6, 56, 12),
QT_MOC_LITERAL(7, 69, 8),
QT_MOC_LITERAL(8, 78, 7),
QT_MOC_LITERAL(9, 86, 14)
    },
    "WindowManager\0windowAdded\0\0Window*\0"
    "window\0windowRemoved\0processAdded\0"
    "Process*\0process\0processRemoved\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WindowManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x05,
       5,    1,   37,    2, 0x05,
       6,    1,   40,    2, 0x05,
       9,    1,   43,    2, 0x05,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

void WindowManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WindowManager *_t = static_cast<WindowManager *>(_o);
        switch (_id) {
        case 0: _t->windowAdded((*reinterpret_cast< Window*(*)>(_a[1]))); break;
        case 1: _t->windowRemoved((*reinterpret_cast< Window*(*)>(_a[1]))); break;
        case 2: _t->processAdded((*reinterpret_cast< Process*(*)>(_a[1]))); break;
        case 3: _t->processRemoved((*reinterpret_cast< Process*(*)>(_a[1]))); break;
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
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Process* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Process* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WindowManager::*_t)(Window * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WindowManager::windowAdded)) {
                *result = 0;
            }
        }
        {
            typedef void (WindowManager::*_t)(Window * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WindowManager::windowRemoved)) {
                *result = 1;
            }
        }
        {
            typedef void (WindowManager::*_t)(Process * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WindowManager::processAdded)) {
                *result = 2;
            }
        }
        {
            typedef void (WindowManager::*_t)(Process * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WindowManager::processRemoved)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject WindowManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WindowManager.data,
      qt_meta_data_WindowManager,  qt_static_metacall, 0, 0}
};


const QMetaObject *WindowManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WindowManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WindowManager.stringdata))
        return static_cast<void*>(const_cast< WindowManager*>(this));
    return QObject::qt_metacast(_clname);
}

int WindowManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void WindowManager::windowAdded(Window * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WindowManager::windowRemoved(Window * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void WindowManager::processAdded(Process * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void WindowManager::processRemoved(Process * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE

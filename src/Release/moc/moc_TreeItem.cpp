/****************************************************************************
** Meta object code from reading C++ file 'TreeItem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ui/custom_widgets/TreeItem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TreeItem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TreeHighlight_t {
    QByteArrayData data[5];
    char stringdata0[49];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TreeHighlight_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TreeHighlight_t qt_meta_stringdata_TreeHighlight = {
    {
QT_MOC_LITERAL(0, 0, 13), // "TreeHighlight"
QT_MOC_LITERAL(1, 14, 9), // "highlight"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 11), // "isImmediate"
QT_MOC_LITERAL(4, 37, 11) // "unhighlight"

    },
    "TreeHighlight\0highlight\0\0isImmediate\0"
    "unhighlight"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TreeHighlight[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       1,    0,   32,    2, 0x2a /* Public | MethodCloned */,
       4,    0,   33,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TreeHighlight::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TreeHighlight *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->highlight((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->highlight(); break;
        case 2: _t->unhighlight(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TreeHighlight::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TreeHighlight.data,
    qt_meta_data_TreeHighlight,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TreeHighlight::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TreeHighlight::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TreeHighlight.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TreeHighlight::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
struct qt_meta_stringdata_TreeItem_t {
    QByteArrayData data[5];
    char stringdata0[37];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TreeItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TreeItem_t qt_meta_stringdata_TreeItem = {
    {
QT_MOC_LITERAL(0, 0, 8), // "TreeItem"
QT_MOC_LITERAL(1, 9, 6), // "update"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 12), // "UpdateReason"
QT_MOC_LITERAL(4, 30, 6) // "reason"

    },
    "TreeItem\0update\0\0UpdateReason\0reason"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TreeItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void TreeItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TreeItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->update((*reinterpret_cast< UpdateReason(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TreeItem::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TreeItem.data,
    qt_meta_data_TreeItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TreeItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TreeItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TreeItem.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QTreeWidgetItem"))
        return static_cast< QTreeWidgetItem*>(this);
    return QObject::qt_metacast(_clname);
}

int TreeItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_ProcessItem_t {
    QByteArrayData data[1];
    char stringdata0[12];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProcessItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProcessItem_t qt_meta_stringdata_ProcessItem = {
    {
QT_MOC_LITERAL(0, 0, 11) // "ProcessItem"

    },
    "ProcessItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProcessItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void ProcessItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ProcessItem::staticMetaObject = { {
    QMetaObject::SuperData::link<TreeItem::staticMetaObject>(),
    qt_meta_stringdata_ProcessItem.data,
    qt_meta_data_ProcessItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ProcessItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProcessItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProcessItem.stringdata0))
        return static_cast<void*>(this);
    return TreeItem::qt_metacast(_clname);
}

int ProcessItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TreeItem::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_WindowItem_t {
    QByteArrayData data[1];
    char stringdata0[11];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WindowItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WindowItem_t qt_meta_stringdata_WindowItem = {
    {
QT_MOC_LITERAL(0, 0, 10) // "WindowItem"

    },
    "WindowItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WindowItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void WindowItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject WindowItem::staticMetaObject = { {
    QMetaObject::SuperData::link<TreeItem::staticMetaObject>(),
    qt_meta_stringdata_WindowItem.data,
    qt_meta_data_WindowItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WindowItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WindowItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WindowItem.stringdata0))
        return static_cast<void*>(this);
    return TreeItem::qt_metacast(_clname);
}

int WindowItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TreeItem::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

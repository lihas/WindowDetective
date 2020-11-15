/****************************************************************************
** Meta object code from reading C++ file 'TreeItem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ui/custom_widgets/TreeItem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TreeItem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TreeHighlight_t {
    QByteArrayData data[5];
    char stringdata[50];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_TreeHighlight_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_TreeHighlight_t qt_meta_stringdata_TreeHighlight = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 9),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 11),
QT_MOC_LITERAL(4, 37, 11)
    },
    "TreeHighlight\0highlight\0\0isImmediate\0"
    "unhighlight\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TreeHighlight[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a,
       1,    0,   32,    2, 0x2a,
       4,    0,   33,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TreeHighlight::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TreeHighlight *_t = static_cast<TreeHighlight *>(_o);
        switch (_id) {
        case 0: _t->highlight((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->highlight(); break;
        case 2: _t->unhighlight(); break;
        default: ;
        }
    }
}

const QMetaObject TreeHighlight::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TreeHighlight.data,
      qt_meta_data_TreeHighlight,  qt_static_metacall, 0, 0}
};


const QMetaObject *TreeHighlight::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TreeHighlight::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TreeHighlight.stringdata))
        return static_cast<void*>(const_cast< TreeHighlight*>(this));
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
    char stringdata[38];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_TreeItem_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_TreeItem_t qt_meta_stringdata_TreeItem = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 6),
QT_MOC_LITERAL(2, 16, 0),
QT_MOC_LITERAL(3, 17, 12),
QT_MOC_LITERAL(4, 30, 6)
    },
    "TreeItem\0update\0\0UpdateReason\0reason\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TreeItem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void TreeItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TreeItem *_t = static_cast<TreeItem *>(_o);
        switch (_id) {
        case 0: _t->update((*reinterpret_cast< UpdateReason(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject TreeItem::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TreeItem.data,
      qt_meta_data_TreeItem,  qt_static_metacall, 0, 0}
};


const QMetaObject *TreeItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TreeItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TreeItem.stringdata))
        return static_cast<void*>(const_cast< TreeItem*>(this));
    if (!strcmp(_clname, "QTreeWidgetItem"))
        return static_cast< QTreeWidgetItem*>(const_cast< TreeItem*>(this));
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
    char stringdata[13];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ProcessItem_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ProcessItem_t qt_meta_stringdata_ProcessItem = {
    {
QT_MOC_LITERAL(0, 0, 11)
    },
    "ProcessItem\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProcessItem[] = {

 // content:
       7,       // revision
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

const QMetaObject ProcessItem::staticMetaObject = {
    { &TreeItem::staticMetaObject, qt_meta_stringdata_ProcessItem.data,
      qt_meta_data_ProcessItem,  qt_static_metacall, 0, 0}
};


const QMetaObject *ProcessItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProcessItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ProcessItem.stringdata))
        return static_cast<void*>(const_cast< ProcessItem*>(this));
    return TreeItem::qt_metacast(_clname);
}

int ProcessItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TreeItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_WindowItem_t {
    QByteArrayData data[1];
    char stringdata[12];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_WindowItem_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_WindowItem_t qt_meta_stringdata_WindowItem = {
    {
QT_MOC_LITERAL(0, 0, 10)
    },
    "WindowItem\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WindowItem[] = {

 // content:
       7,       // revision
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

const QMetaObject WindowItem::staticMetaObject = {
    { &TreeItem::staticMetaObject, qt_meta_stringdata_WindowItem.data,
      qt_meta_data_WindowItem,  qt_static_metacall, 0, 0}
};


const QMetaObject *WindowItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WindowItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WindowItem.stringdata))
        return static_cast<void*>(const_cast< WindowItem*>(this));
    return TreeItem::qt_metacast(_clname);
}

int WindowItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TreeItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE

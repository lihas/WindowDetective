/****************************************************************************
** Meta object code from reading C++ file 'WindowTree.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ui/custom_widgets/WindowTree.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WindowTree.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WindowTree_t {
    QByteArrayData data[13];
    char stringdata0[143];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WindowTree_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WindowTree_t qt_meta_stringdata_WindowTree = {
    {
QT_MOC_LITERAL(0, 0, 10), // "WindowTree"
QT_MOC_LITERAL(1, 11, 15), // "insertNewWindow"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 7), // "Window*"
QT_MOC_LITERAL(4, 36, 6), // "window"
QT_MOC_LITERAL(5, 43, 12), // "removeWindow"
QT_MOC_LITERAL(6, 56, 16), // "insertNewProcess"
QT_MOC_LITERAL(7, 73, 8), // "Process*"
QT_MOC_LITERAL(8, 82, 7), // "process"
QT_MOC_LITERAL(9, 90, 13), // "removeProcess"
QT_MOC_LITERAL(10, 104, 16), // "treeItemExpanded"
QT_MOC_LITERAL(11, 121, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(12, 138, 4) // "item"

    },
    "WindowTree\0insertNewWindow\0\0Window*\0"
    "window\0removeWindow\0insertNewProcess\0"
    "Process*\0process\0removeProcess\0"
    "treeItemExpanded\0QTreeWidgetItem*\0"
    "item"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WindowTree[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x09 /* Protected */,
       5,    1,   42,    2, 0x09 /* Protected */,
       6,    1,   45,    2, 0x09 /* Protected */,
       9,    1,   48,    2, 0x09 /* Protected */,
      10,    1,   51,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 11,   12,

       0        // eod
};

void WindowTree::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WindowTree *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->insertNewWindow((*reinterpret_cast< Window*(*)>(_a[1]))); break;
        case 1: _t->removeWindow((*reinterpret_cast< Window*(*)>(_a[1]))); break;
        case 2: _t->insertNewProcess((*reinterpret_cast< Process*(*)>(_a[1]))); break;
        case 3: _t->removeProcess((*reinterpret_cast< Process*(*)>(_a[1]))); break;
        case 4: _t->treeItemExpanded((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
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
    }
}

QT_INIT_METAOBJECT const QMetaObject WindowTree::staticMetaObject = { {
    QMetaObject::SuperData::link<QTreeWidget::staticMetaObject>(),
    qt_meta_stringdata_WindowTree.data,
    qt_meta_data_WindowTree,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WindowTree::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WindowTree::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WindowTree.stringdata0))
        return static_cast<void*>(this);
    return QTreeWidget::qt_metacast(_clname);
}

int WindowTree::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE

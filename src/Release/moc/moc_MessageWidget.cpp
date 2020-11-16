/****************************************************************************
** Meta object code from reading C++ file 'MessageWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ui/custom_widgets/MessageWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MessageWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MessageWidget_t {
    QByteArrayData data[5];
    char stringdata0[32];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MessageWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MessageWidget_t qt_meta_stringdata_MessageWidget = {
    {
QT_MOC_LITERAL(0, 0, 13), // "MessageWidget"
QT_MOC_LITERAL(1, 14, 5), // "start"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 4), // "stop"
QT_MOC_LITERAL(4, 26, 5) // "clear"

    },
    "MessageWidget\0start\0\0stop\0clear"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MessageWidget[] = {

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
       1,    0,   29,    2, 0x0a /* Public */,
       3,    0,   30,    2, 0x0a /* Public */,
       4,    0,   31,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MessageWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MessageWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->start();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->stop(); break;
        case 2: _t->clear(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MessageWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QTreeWidget::staticMetaObject>(),
    qt_meta_stringdata_MessageWidget.data,
    qt_meta_data_MessageWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MessageWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MessageWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MessageWidget.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "WindowMessageListener"))
        return static_cast< WindowMessageListener*>(this);
    return QTreeWidget::qt_metacast(_clname);
}

int MessageWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE

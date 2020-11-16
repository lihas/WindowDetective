/****************************************************************************
** Meta object code from reading C++ file 'PreferencesDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ui/PreferencesDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PreferencesDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PreferencesDialog_t {
    QByteArrayData data[13];
    char stringdata0[242];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PreferencesDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PreferencesDialog_t qt_meta_stringdata_PreferencesDialog = {
    {
QT_MOC_LITERAL(0, 0, 17), // "PreferencesDialog"
QT_MOC_LITERAL(1, 18, 22), // "highlightWindowChanged"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 16), // "stayOnTopChanged"
QT_MOC_LITERAL(4, 59, 15), // "shouldStayOnTop"
QT_MOC_LITERAL(5, 75, 24), // "borderRadioButtonClicked"
QT_MOC_LITERAL(6, 100, 24), // "filledRadioButtonClicked"
QT_MOC_LITERAL(7, 125, 27), // "highlightWindowValueChanged"
QT_MOC_LITERAL(8, 153, 25), // "chooseFolderButtonClicked"
QT_MOC_LITERAL(9, 179, 15), // "restoreDefaults"
QT_MOC_LITERAL(10, 195, 14), // "exportSettings"
QT_MOC_LITERAL(11, 210, 14), // "importSettings"
QT_MOC_LITERAL(12, 225, 16) // "applyPreferences"

    },
    "PreferencesDialog\0highlightWindowChanged\0"
    "\0stayOnTopChanged\0shouldStayOnTop\0"
    "borderRadioButtonClicked\0"
    "filledRadioButtonClicked\0"
    "highlightWindowValueChanged\0"
    "chooseFolderButtonClicked\0restoreDefaults\0"
    "exportSettings\0importSettings\0"
    "applyPreferences"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PreferencesDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    1,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   68,    2, 0x08 /* Private */,
       6,    0,   69,    2, 0x08 /* Private */,
       7,    0,   70,    2, 0x08 /* Private */,
       8,    0,   71,    2, 0x08 /* Private */,
       9,    0,   72,    2, 0x08 /* Private */,
      10,    0,   73,    2, 0x08 /* Private */,
      11,    0,   74,    2, 0x08 /* Private */,
      12,    0,   75,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PreferencesDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PreferencesDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->highlightWindowChanged(); break;
        case 1: _t->stayOnTopChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->borderRadioButtonClicked(); break;
        case 3: _t->filledRadioButtonClicked(); break;
        case 4: _t->highlightWindowValueChanged(); break;
        case 5: _t->chooseFolderButtonClicked(); break;
        case 6: _t->restoreDefaults(); break;
        case 7: _t->exportSettings(); break;
        case 8: _t->importSettings(); break;
        case 9: _t->applyPreferences(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PreferencesDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PreferencesDialog::highlightWindowChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PreferencesDialog::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PreferencesDialog::stayOnTopChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PreferencesDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_PreferencesDialog.data,
    qt_meta_data_PreferencesDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PreferencesDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PreferencesDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PreferencesDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int PreferencesDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void PreferencesDialog::highlightWindowChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void PreferencesDialog::stayOnTopChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

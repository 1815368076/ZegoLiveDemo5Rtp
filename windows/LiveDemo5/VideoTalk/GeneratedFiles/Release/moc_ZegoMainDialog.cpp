/****************************************************************************
** Meta object code from reading C++ file 'ZegoMainDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Dialog/ZegoMainDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ZegoMainDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ZegoMainDialog_t {
    QByteArrayData data[10];
    char stringdata0[159];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ZegoMainDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ZegoMainDialog_t qt_meta_stringdata_ZegoMainDialog = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ZegoMainDialog"
QT_MOC_LITERAL(1, 15, 17), // "OnButtonEnterRoom"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 16), // "OnButtonSettings"
QT_MOC_LITERAL(4, 51, 13), // "OnButtonClose"
QT_MOC_LITERAL(5, 65, 15), // "OnButtonMinimum"
QT_MOC_LITERAL(6, 81, 17), // "OnButtonJumpToNet"
QT_MOC_LITERAL(7, 99, 32), // "OnReturnConfigFromSettingsDialog"
QT_MOC_LITERAL(8, 132, 15), // "QZegoUserConfig"
QT_MOC_LITERAL(9, 148, 10) // "userConfig"

    },
    "ZegoMainDialog\0OnButtonEnterRoom\0\0"
    "OnButtonSettings\0OnButtonClose\0"
    "OnButtonMinimum\0OnButtonJumpToNet\0"
    "OnReturnConfigFromSettingsDialog\0"
    "QZegoUserConfig\0userConfig"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ZegoMainDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    1,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void ZegoMainDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ZegoMainDialog *_t = static_cast<ZegoMainDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnButtonEnterRoom(); break;
        case 1: _t->OnButtonSettings(); break;
        case 2: _t->OnButtonClose(); break;
        case 3: _t->OnButtonMinimum(); break;
        case 4: _t->OnButtonJumpToNet(); break;
        case 5: _t->OnReturnConfigFromSettingsDialog((*reinterpret_cast< QZegoUserConfig(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ZegoMainDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ZegoMainDialog.data,
      qt_meta_data_ZegoMainDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ZegoMainDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZegoMainDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ZegoMainDialog.stringdata0))
        return static_cast<void*>(const_cast< ZegoMainDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ZegoMainDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

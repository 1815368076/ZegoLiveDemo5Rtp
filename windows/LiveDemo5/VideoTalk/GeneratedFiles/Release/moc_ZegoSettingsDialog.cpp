/****************************************************************************
** Meta object code from reading C++ file 'ZegoSettingsDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Dialog/ZegoSettingsDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ZegoSettingsDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ZegoSettingsDialog_t {
    QByteArrayData data[21];
    char stringdata0[392];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ZegoSettingsDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ZegoSettingsDialog_t qt_meta_stringdata_ZegoSettingsDialog = {
    {
QT_MOC_LITERAL(0, 0, 18), // "ZegoSettingsDialog"
QT_MOC_LITERAL(1, 19, 24), // "sigChangedSettingsConfig"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 27), // "sigReturnConfigToMainDialog"
QT_MOC_LITERAL(4, 73, 15), // "QZegoUserConfig"
QT_MOC_LITERAL(5, 89, 10), // "userConfig"
QT_MOC_LITERAL(6, 100, 13), // "OnButtonClose"
QT_MOC_LITERAL(7, 114, 15), // "OnButtonMinimum"
QT_MOC_LITERAL(8, 130, 18), // "OnButtonSaveConfig"
QT_MOC_LITERAL(9, 149, 17), // "OnButtonUploadLog"
QT_MOC_LITERAL(10, 167, 21), // "OnButtonSwitchTestEnv"
QT_MOC_LITERAL(11, 189, 26), // "OnButtonSwtichSurfaceMerge"
QT_MOC_LITERAL(12, 216, 20), // "OnCheckSliderPressed"
QT_MOC_LITERAL(13, 237, 21), // "OnCheckSliderReleased"
QT_MOC_LITERAL(14, 259, 19), // "OnSliderValueChange"
QT_MOC_LITERAL(15, 279, 5), // "value"
QT_MOC_LITERAL(16, 285, 25), // "OnButtonSliderValueChange"
QT_MOC_LITERAL(17, 311, 23), // "OnChangedSettingsConfig"
QT_MOC_LITERAL(18, 335, 27), // "OnComboBoxCheckVideoQuality"
QT_MOC_LITERAL(19, 363, 2), // "id"
QT_MOC_LITERAL(20, 366, 25) // "OnComboBoxCheckAppVersion"

    },
    "ZegoSettingsDialog\0sigChangedSettingsConfig\0"
    "\0sigReturnConfigToMainDialog\0"
    "QZegoUserConfig\0userConfig\0OnButtonClose\0"
    "OnButtonMinimum\0OnButtonSaveConfig\0"
    "OnButtonUploadLog\0OnButtonSwitchTestEnv\0"
    "OnButtonSwtichSurfaceMerge\0"
    "OnCheckSliderPressed\0OnCheckSliderReleased\0"
    "OnSliderValueChange\0value\0"
    "OnButtonSliderValueChange\0"
    "OnChangedSettingsConfig\0"
    "OnComboBoxCheckVideoQuality\0id\0"
    "OnComboBoxCheckAppVersion"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ZegoSettingsDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    1,   90,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   93,    2, 0x08 /* Private */,
       7,    0,   94,    2, 0x08 /* Private */,
       8,    0,   95,    2, 0x08 /* Private */,
       9,    0,   96,    2, 0x08 /* Private */,
      10,    0,   97,    2, 0x08 /* Private */,
      11,    0,   98,    2, 0x08 /* Private */,
      12,    0,   99,    2, 0x08 /* Private */,
      13,    0,  100,    2, 0x08 /* Private */,
      14,    1,  101,    2, 0x08 /* Private */,
      16,    0,  104,    2, 0x08 /* Private */,
      17,    0,  105,    2, 0x08 /* Private */,
      18,    1,  106,    2, 0x08 /* Private */,
      20,    1,  109,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   19,

       0        // eod
};

void ZegoSettingsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ZegoSettingsDialog *_t = static_cast<ZegoSettingsDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigChangedSettingsConfig(); break;
        case 1: _t->sigReturnConfigToMainDialog((*reinterpret_cast< QZegoUserConfig(*)>(_a[1]))); break;
        case 2: _t->OnButtonClose(); break;
        case 3: _t->OnButtonMinimum(); break;
        case 4: _t->OnButtonSaveConfig(); break;
        case 5: _t->OnButtonUploadLog(); break;
        case 6: _t->OnButtonSwitchTestEnv(); break;
        case 7: _t->OnButtonSwtichSurfaceMerge(); break;
        case 8: _t->OnCheckSliderPressed(); break;
        case 9: _t->OnCheckSliderReleased(); break;
        case 10: _t->OnSliderValueChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->OnButtonSliderValueChange(); break;
        case 12: _t->OnChangedSettingsConfig(); break;
        case 13: _t->OnComboBoxCheckVideoQuality((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->OnComboBoxCheckAppVersion((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ZegoSettingsDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ZegoSettingsDialog::sigChangedSettingsConfig)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ZegoSettingsDialog::*_t)(QZegoUserConfig );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ZegoSettingsDialog::sigReturnConfigToMainDialog)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject ZegoSettingsDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ZegoSettingsDialog.data,
      qt_meta_data_ZegoSettingsDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ZegoSettingsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZegoSettingsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ZegoSettingsDialog.stringdata0))
        return static_cast<void*>(const_cast< ZegoSettingsDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ZegoSettingsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void ZegoSettingsDialog::sigChangedSettingsConfig()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void ZegoSettingsDialog::sigReturnConfigToMainDialog(QZegoUserConfig _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'ZegoMoreAnchorDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Dialog/ZegoMoreAnchorDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ZegoMoreAnchorDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ZegoMoreAnchorDialog_t {
    QByteArrayData data[21];
    char stringdata0[281];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ZegoMoreAnchorDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ZegoMoreAnchorDialog_t qt_meta_stringdata_ZegoMoreAnchorDialog = {
    {
QT_MOC_LITERAL(0, 0, 20), // "ZegoMoreAnchorDialog"
QT_MOC_LITERAL(1, 21, 11), // "OnLoginRoom"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 9), // "errorCode"
QT_MOC_LITERAL(4, 44, 6), // "roomId"
QT_MOC_LITERAL(5, 51, 18), // "QVector<StreamPtr>"
QT_MOC_LITERAL(6, 70, 11), // "vStreamList"
QT_MOC_LITERAL(7, 82, 15), // "OnStreamUpdated"
QT_MOC_LITERAL(8, 98, 30), // "LIVEROOM::ZegoStreamUpdateType"
QT_MOC_LITERAL(9, 129, 4), // "type"
QT_MOC_LITERAL(10, 134, 20), // "OnPublishStateUpdate"
QT_MOC_LITERAL(11, 155, 9), // "stateCode"
QT_MOC_LITERAL(12, 165, 8), // "streamId"
QT_MOC_LITERAL(13, 174, 9), // "StreamPtr"
QT_MOC_LITERAL(14, 184, 10), // "streamInfo"
QT_MOC_LITERAL(15, 195, 17), // "OnPlayStateUpdate"
QT_MOC_LITERAL(16, 213, 17), // "OnJoinLiveRequest"
QT_MOC_LITERAL(17, 231, 3), // "seq"
QT_MOC_LITERAL(18, 235, 10), // "fromUserId"
QT_MOC_LITERAL(19, 246, 12), // "fromUserName"
QT_MOC_LITERAL(20, 259, 21) // "OnButtonSwitchPublish"

    },
    "ZegoMoreAnchorDialog\0OnLoginRoom\0\0"
    "errorCode\0roomId\0QVector<StreamPtr>\0"
    "vStreamList\0OnStreamUpdated\0"
    "LIVEROOM::ZegoStreamUpdateType\0type\0"
    "OnPublishStateUpdate\0stateCode\0streamId\0"
    "StreamPtr\0streamInfo\0OnPlayStateUpdate\0"
    "OnJoinLiveRequest\0seq\0fromUserId\0"
    "fromUserName\0OnButtonSwitchPublish"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ZegoMoreAnchorDialog[] = {

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
       1,    3,   44,    2, 0x09 /* Protected */,
       7,    3,   51,    2, 0x09 /* Protected */,
      10,    3,   58,    2, 0x09 /* Protected */,
      15,    2,   65,    2, 0x09 /* Protected */,
      16,    4,   70,    2, 0x09 /* Protected */,
      20,    0,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, 0x80000000 | 5,    3,    4,    6,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 5, 0x80000000 | 8,    4,    6,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, 0x80000000 | 13,   11,   12,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   11,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,   17,   18,   19,    4,
    QMetaType::Void,

       0        // eod
};

void ZegoMoreAnchorDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ZegoMoreAnchorDialog *_t = static_cast<ZegoMoreAnchorDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnLoginRoom((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< QVector<StreamPtr>(*)>(_a[3]))); break;
        case 1: _t->OnStreamUpdated((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QVector<StreamPtr>(*)>(_a[2])),(*reinterpret_cast< LIVEROOM::ZegoStreamUpdateType(*)>(_a[3]))); break;
        case 2: _t->OnPublishStateUpdate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< StreamPtr(*)>(_a[3]))); break;
        case 3: _t->OnPlayStateUpdate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->OnJoinLiveRequest((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 5: _t->OnButtonSwitchPublish(); break;
        default: ;
        }
    }
}

const QMetaObject ZegoMoreAnchorDialog::staticMetaObject = {
    { &ZegoBaseDialog::staticMetaObject, qt_meta_stringdata_ZegoMoreAnchorDialog.data,
      qt_meta_data_ZegoMoreAnchorDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ZegoMoreAnchorDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZegoMoreAnchorDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ZegoMoreAnchorDialog.stringdata0))
        return static_cast<void*>(const_cast< ZegoMoreAnchorDialog*>(this));
    return ZegoBaseDialog::qt_metacast(_clname);
}

int ZegoMoreAnchorDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ZegoBaseDialog::qt_metacall(_c, _id, _a);
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

/****************************************************************************
** Meta object code from reading C++ file 'ZegoMoreAudienceDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Dialog/ZegoMoreAudienceDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ZegoMoreAudienceDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ZegoMoreAudienceDialog_t {
    QByteArrayData data[25];
    char stringdata0[327];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ZegoMoreAudienceDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ZegoMoreAudienceDialog_t qt_meta_stringdata_ZegoMoreAudienceDialog = {
    {
QT_MOC_LITERAL(0, 0, 22), // "ZegoMoreAudienceDialog"
QT_MOC_LITERAL(1, 23, 11), // "OnLoginRoom"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 9), // "errorCode"
QT_MOC_LITERAL(4, 46, 6), // "roomId"
QT_MOC_LITERAL(5, 53, 18), // "QVector<StreamPtr>"
QT_MOC_LITERAL(6, 72, 11), // "vStreamList"
QT_MOC_LITERAL(7, 84, 15), // "OnStreamUpdated"
QT_MOC_LITERAL(8, 100, 30), // "LIVEROOM::ZegoStreamUpdateType"
QT_MOC_LITERAL(9, 131, 4), // "type"
QT_MOC_LITERAL(10, 136, 20), // "OnPublishStateUpdate"
QT_MOC_LITERAL(11, 157, 9), // "stateCode"
QT_MOC_LITERAL(12, 167, 8), // "streamId"
QT_MOC_LITERAL(13, 176, 9), // "StreamPtr"
QT_MOC_LITERAL(14, 186, 10), // "streamInfo"
QT_MOC_LITERAL(15, 197, 17), // "OnPlayStateUpdate"
QT_MOC_LITERAL(16, 215, 18), // "OnJoinLiveResponse"
QT_MOC_LITERAL(17, 234, 6), // "result"
QT_MOC_LITERAL(18, 241, 10), // "fromUserId"
QT_MOC_LITERAL(19, 252, 12), // "fromUserName"
QT_MOC_LITERAL(20, 265, 3), // "seq"
QT_MOC_LITERAL(21, 269, 24), // "OnRecvEndJoinLiveCommand"
QT_MOC_LITERAL(22, 294, 6), // "userId"
QT_MOC_LITERAL(23, 301, 8), // "userName"
QT_MOC_LITERAL(24, 310, 16) // "OnButtonJoinLive"

    },
    "ZegoMoreAudienceDialog\0OnLoginRoom\0\0"
    "errorCode\0roomId\0QVector<StreamPtr>\0"
    "vStreamList\0OnStreamUpdated\0"
    "LIVEROOM::ZegoStreamUpdateType\0type\0"
    "OnPublishStateUpdate\0stateCode\0streamId\0"
    "StreamPtr\0streamInfo\0OnPlayStateUpdate\0"
    "OnJoinLiveResponse\0result\0fromUserId\0"
    "fromUserName\0seq\0OnRecvEndJoinLiveCommand\0"
    "userId\0userName\0OnButtonJoinLive"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ZegoMoreAudienceDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   49,    2, 0x09 /* Protected */,
       7,    3,   56,    2, 0x09 /* Protected */,
      10,    3,   63,    2, 0x09 /* Protected */,
      15,    2,   70,    2, 0x09 /* Protected */,
      16,    4,   75,    2, 0x09 /* Protected */,
      21,    3,   84,    2, 0x09 /* Protected */,
      24,    0,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, 0x80000000 | 5,    3,    4,    6,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 5, 0x80000000 | 8,    4,    6,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, 0x80000000 | 13,   11,   12,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   11,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Int,   17,   18,   19,   20,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   22,   23,    4,
    QMetaType::Void,

       0        // eod
};

void ZegoMoreAudienceDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ZegoMoreAudienceDialog *_t = static_cast<ZegoMoreAudienceDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnLoginRoom((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< QVector<StreamPtr>(*)>(_a[3]))); break;
        case 1: _t->OnStreamUpdated((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QVector<StreamPtr>(*)>(_a[2])),(*reinterpret_cast< LIVEROOM::ZegoStreamUpdateType(*)>(_a[3]))); break;
        case 2: _t->OnPublishStateUpdate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< StreamPtr(*)>(_a[3]))); break;
        case 3: _t->OnPlayStateUpdate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->OnJoinLiveResponse((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 5: _t->OnRecvEndJoinLiveCommand((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 6: _t->OnButtonJoinLive(); break;
        default: ;
        }
    }
}

const QMetaObject ZegoMoreAudienceDialog::staticMetaObject = {
    { &ZegoBaseDialog::staticMetaObject, qt_meta_stringdata_ZegoMoreAudienceDialog.data,
      qt_meta_data_ZegoMoreAudienceDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ZegoMoreAudienceDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZegoMoreAudienceDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ZegoMoreAudienceDialog.stringdata0))
        return static_cast<void*>(const_cast< ZegoMoreAudienceDialog*>(this));
    return ZegoBaseDialog::qt_metacast(_clname);
}

int ZegoMoreAudienceDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ZegoBaseDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

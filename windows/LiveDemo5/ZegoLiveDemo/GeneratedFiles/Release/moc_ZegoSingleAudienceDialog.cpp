/****************************************************************************
** Meta object code from reading C++ file 'ZegoSingleAudienceDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Dialog/ZegoSingleAudienceDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ZegoSingleAudienceDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ZegoSingleAudienceDialog_t {
    QByteArrayData data[55];
    char stringdata0[744];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ZegoSingleAudienceDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ZegoSingleAudienceDialog_t qt_meta_stringdata_ZegoSingleAudienceDialog = {
    {
QT_MOC_LITERAL(0, 0, 24), // "ZegoSingleAudienceDialog"
QT_MOC_LITERAL(1, 25, 20), // "sigSaveVideoSettings"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 11), // "SettingsPtr"
QT_MOC_LITERAL(4, 59, 8), // "settings"
QT_MOC_LITERAL(5, 68, 11), // "OnLoginRoom"
QT_MOC_LITERAL(6, 80, 9), // "errorCode"
QT_MOC_LITERAL(7, 90, 6), // "roomId"
QT_MOC_LITERAL(8, 97, 18), // "QVector<StreamPtr>"
QT_MOC_LITERAL(9, 116, 11), // "vStreamList"
QT_MOC_LITERAL(10, 128, 15), // "OnStreamUpdated"
QT_MOC_LITERAL(11, 144, 30), // "LIVEROOM::ZegoStreamUpdateType"
QT_MOC_LITERAL(12, 175, 4), // "type"
QT_MOC_LITERAL(13, 180, 17), // "OnPlayStateUpdate"
QT_MOC_LITERAL(14, 198, 9), // "stateCode"
QT_MOC_LITERAL(15, 208, 8), // "streamId"
QT_MOC_LITERAL(16, 217, 12), // "OnUserUpdate"
QT_MOC_LITERAL(17, 230, 16), // "QVector<QString>"
QT_MOC_LITERAL(18, 247, 7), // "userIDs"
QT_MOC_LITERAL(19, 255, 9), // "userNames"
QT_MOC_LITERAL(20, 265, 12), // "QVector<int>"
QT_MOC_LITERAL(21, 278, 9), // "userFlags"
QT_MOC_LITERAL(22, 288, 9), // "userRoles"
QT_MOC_LITERAL(23, 298, 9), // "userCount"
QT_MOC_LITERAL(24, 308, 28), // "LIVEROOM::ZegoUserUpdateType"
QT_MOC_LITERAL(25, 337, 12), // "OnDisconnect"
QT_MOC_LITERAL(26, 350, 9), // "OnKickOut"
QT_MOC_LITERAL(27, 360, 6), // "reason"
QT_MOC_LITERAL(28, 367, 19), // "OnPlayQualityUpdate"
QT_MOC_LITERAL(29, 387, 7), // "quality"
QT_MOC_LITERAL(30, 395, 8), // "videoFPS"
QT_MOC_LITERAL(31, 404, 8), // "videoKBS"
QT_MOC_LITERAL(32, 413, 17), // "OnSendRoomMessage"
QT_MOC_LITERAL(33, 431, 6), // "roomID"
QT_MOC_LITERAL(34, 438, 7), // "sendSeq"
QT_MOC_LITERAL(35, 446, 9), // "messageId"
QT_MOC_LITERAL(36, 456, 17), // "OnRecvRoomMessage"
QT_MOC_LITERAL(37, 474, 19), // "QVector<RoomMsgPtr>"
QT_MOC_LITERAL(38, 494, 12), // "vRoomMsgList"
QT_MOC_LITERAL(39, 507, 20), // "OnAudioDeviceChanged"
QT_MOC_LITERAL(40, 528, 19), // "AV::AudioDeviceType"
QT_MOC_LITERAL(41, 548, 10), // "deviceType"
QT_MOC_LITERAL(42, 559, 11), // "strDeviceId"
QT_MOC_LITERAL(43, 571, 13), // "strDeviceName"
QT_MOC_LITERAL(44, 585, 15), // "AV::DeviceState"
QT_MOC_LITERAL(45, 601, 5), // "state"
QT_MOC_LITERAL(46, 607, 20), // "OnVideoDeviceChanged"
QT_MOC_LITERAL(47, 628, 18), // "OnClickTitleButton"
QT_MOC_LITERAL(48, 647, 7), // "OnClose"
QT_MOC_LITERAL(49, 655, 19), // "OnButtonSendMessage"
QT_MOC_LITERAL(50, 675, 13), // "OnButtonSound"
QT_MOC_LITERAL(51, 689, 11), // "OnShareLink"
QT_MOC_LITERAL(52, 701, 19), // "OnSwitchAudioDevice"
QT_MOC_LITERAL(53, 721, 2), // "id"
QT_MOC_LITERAL(54, 724, 19) // "OnSwitchVideoDevice"

    },
    "ZegoSingleAudienceDialog\0sigSaveVideoSettings\0"
    "\0SettingsPtr\0settings\0OnLoginRoom\0"
    "errorCode\0roomId\0QVector<StreamPtr>\0"
    "vStreamList\0OnStreamUpdated\0"
    "LIVEROOM::ZegoStreamUpdateType\0type\0"
    "OnPlayStateUpdate\0stateCode\0streamId\0"
    "OnUserUpdate\0QVector<QString>\0userIDs\0"
    "userNames\0QVector<int>\0userFlags\0"
    "userRoles\0userCount\0LIVEROOM::ZegoUserUpdateType\0"
    "OnDisconnect\0OnKickOut\0reason\0"
    "OnPlayQualityUpdate\0quality\0videoFPS\0"
    "videoKBS\0OnSendRoomMessage\0roomID\0"
    "sendSeq\0messageId\0OnRecvRoomMessage\0"
    "QVector<RoomMsgPtr>\0vRoomMsgList\0"
    "OnAudioDeviceChanged\0AV::AudioDeviceType\0"
    "deviceType\0strDeviceId\0strDeviceName\0"
    "AV::DeviceState\0state\0OnVideoDeviceChanged\0"
    "OnClickTitleButton\0OnClose\0"
    "OnButtonSendMessage\0OnButtonSound\0"
    "OnShareLink\0OnSwitchAudioDevice\0id\0"
    "OnSwitchVideoDevice"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ZegoSingleAudienceDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  109,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    3,  112,    2, 0x09 /* Protected */,
      10,    3,  119,    2, 0x09 /* Protected */,
      13,    2,  126,    2, 0x09 /* Protected */,
      16,    6,  131,    2, 0x09 /* Protected */,
      25,    2,  144,    2, 0x09 /* Protected */,
      26,    2,  149,    2, 0x09 /* Protected */,
      28,    4,  154,    2, 0x09 /* Protected */,
      32,    4,  163,    2, 0x09 /* Protected */,
      36,    2,  172,    2, 0x09 /* Protected */,
      39,    4,  177,    2, 0x09 /* Protected */,
      46,    3,  186,    2, 0x09 /* Protected */,
      47,    0,  193,    2, 0x08 /* Private */,
      48,    0,  194,    2, 0x08 /* Private */,
      49,    0,  195,    2, 0x08 /* Private */,
      50,    0,  196,    2, 0x08 /* Private */,
      51,    0,  197,    2, 0x08 /* Private */,
      52,    1,  198,    2, 0x08 /* Private */,
      54,    1,  201,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, 0x80000000 | 8,    6,    7,    9,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 8, 0x80000000 | 11,    7,    9,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   14,   15,
    QMetaType::Void, 0x80000000 | 17, 0x80000000 | 17, 0x80000000 | 20, 0x80000000 | 20, QMetaType::UInt, 0x80000000 | 24,   18,   19,   21,   22,   23,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   27,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Double, QMetaType::Double,   15,   29,   30,   31,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::ULongLong,    6,   33,   34,   35,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 37,    7,   38,
    QMetaType::Void, 0x80000000 | 40, QMetaType::QString, QMetaType::QString, 0x80000000 | 44,   41,   42,   43,   45,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 44,   42,   43,   45,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   53,
    QMetaType::Void, QMetaType::Int,   53,

       0        // eod
};

void ZegoSingleAudienceDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ZegoSingleAudienceDialog *_t = static_cast<ZegoSingleAudienceDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigSaveVideoSettings((*reinterpret_cast< SettingsPtr(*)>(_a[1]))); break;
        case 1: _t->OnLoginRoom((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< QVector<StreamPtr>(*)>(_a[3]))); break;
        case 2: _t->OnStreamUpdated((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QVector<StreamPtr>(*)>(_a[2])),(*reinterpret_cast< LIVEROOM::ZegoStreamUpdateType(*)>(_a[3]))); break;
        case 3: _t->OnPlayStateUpdate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->OnUserUpdate((*reinterpret_cast< QVector<QString>(*)>(_a[1])),(*reinterpret_cast< QVector<QString>(*)>(_a[2])),(*reinterpret_cast< QVector<int>(*)>(_a[3])),(*reinterpret_cast< QVector<int>(*)>(_a[4])),(*reinterpret_cast< uint(*)>(_a[5])),(*reinterpret_cast< LIVEROOM::ZegoUserUpdateType(*)>(_a[6]))); break;
        case 5: _t->OnDisconnect((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 6: _t->OnKickOut((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 7: _t->OnPlayQualityUpdate((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 8: _t->OnSendRoomMessage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< unsigned long long(*)>(_a[4]))); break;
        case 9: _t->OnRecvRoomMessage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QVector<RoomMsgPtr>(*)>(_a[2]))); break;
        case 10: _t->OnAudioDeviceChanged((*reinterpret_cast< AV::AudioDeviceType(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< AV::DeviceState(*)>(_a[4]))); break;
        case 11: _t->OnVideoDeviceChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< AV::DeviceState(*)>(_a[3]))); break;
        case 12: _t->OnClickTitleButton(); break;
        case 13: _t->OnClose(); break;
        case 14: _t->OnButtonSendMessage(); break;
        case 15: _t->OnButtonSound(); break;
        case 16: _t->OnShareLink(); break;
        case 17: _t->OnSwitchAudioDevice((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->OnSwitchVideoDevice((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QString> >(); break;
            case 3:
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ZegoSingleAudienceDialog::*_t)(SettingsPtr );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ZegoSingleAudienceDialog::sigSaveVideoSettings)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ZegoSingleAudienceDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ZegoSingleAudienceDialog.data,
      qt_meta_data_ZegoSingleAudienceDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ZegoSingleAudienceDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZegoSingleAudienceDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ZegoSingleAudienceDialog.stringdata0))
        return static_cast<void*>(const_cast< ZegoSingleAudienceDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ZegoSingleAudienceDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void ZegoSingleAudienceDialog::sigSaveVideoSettings(SettingsPtr _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

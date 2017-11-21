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
    QByteArrayData data[79];
    char stringdata0[1067];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ZegoMoreAnchorDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ZegoMoreAnchorDialog_t qt_meta_stringdata_ZegoMoreAnchorDialog = {
    {
QT_MOC_LITERAL(0, 0, 20), // "ZegoMoreAnchorDialog"
QT_MOC_LITERAL(1, 21, 20), // "sigSaveVideoSettings"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 11), // "SettingsPtr"
QT_MOC_LITERAL(4, 55, 8), // "settings"
QT_MOC_LITERAL(5, 64, 11), // "OnLoginRoom"
QT_MOC_LITERAL(6, 76, 9), // "errorCode"
QT_MOC_LITERAL(7, 86, 6), // "roomId"
QT_MOC_LITERAL(8, 93, 18), // "QVector<StreamPtr>"
QT_MOC_LITERAL(9, 112, 11), // "vStreamList"
QT_MOC_LITERAL(10, 124, 15), // "OnStreamUpdated"
QT_MOC_LITERAL(11, 140, 30), // "LIVEROOM::ZegoStreamUpdateType"
QT_MOC_LITERAL(12, 171, 4), // "type"
QT_MOC_LITERAL(13, 176, 20), // "OnPublishStateUpdate"
QT_MOC_LITERAL(14, 197, 9), // "stateCode"
QT_MOC_LITERAL(15, 207, 8), // "streamId"
QT_MOC_LITERAL(16, 216, 9), // "StreamPtr"
QT_MOC_LITERAL(17, 226, 10), // "streamInfo"
QT_MOC_LITERAL(18, 237, 17), // "OnPlayStateUpdate"
QT_MOC_LITERAL(19, 255, 12), // "OnUserUpdate"
QT_MOC_LITERAL(20, 268, 16), // "QVector<QString>"
QT_MOC_LITERAL(21, 285, 7), // "userIDs"
QT_MOC_LITERAL(22, 293, 9), // "userNames"
QT_MOC_LITERAL(23, 303, 12), // "QVector<int>"
QT_MOC_LITERAL(24, 316, 9), // "userFlags"
QT_MOC_LITERAL(25, 326, 9), // "userRoles"
QT_MOC_LITERAL(26, 336, 9), // "userCount"
QT_MOC_LITERAL(27, 346, 28), // "LIVEROOM::ZegoUserUpdateType"
QT_MOC_LITERAL(28, 375, 12), // "OnDisconnect"
QT_MOC_LITERAL(29, 388, 9), // "OnKickOut"
QT_MOC_LITERAL(30, 398, 6), // "reason"
QT_MOC_LITERAL(31, 405, 19), // "OnPlayQualityUpdate"
QT_MOC_LITERAL(32, 425, 7), // "quality"
QT_MOC_LITERAL(33, 433, 8), // "videoFPS"
QT_MOC_LITERAL(34, 442, 8), // "videoKBS"
QT_MOC_LITERAL(35, 451, 22), // "OnPublishQualityUpdate"
QT_MOC_LITERAL(36, 474, 12), // "OnAVAuxInput"
QT_MOC_LITERAL(37, 487, 14), // "unsigned char*"
QT_MOC_LITERAL(38, 502, 5), // "pData"
QT_MOC_LITERAL(39, 508, 4), // "int*"
QT_MOC_LITERAL(40, 513, 8), // "pDataLen"
QT_MOC_LITERAL(41, 522, 13), // "pDataLenValue"
QT_MOC_LITERAL(42, 536, 11), // "pSampleRate"
QT_MOC_LITERAL(43, 548, 12), // "pNumChannels"
QT_MOC_LITERAL(44, 561, 17), // "OnSendRoomMessage"
QT_MOC_LITERAL(45, 579, 6), // "roomID"
QT_MOC_LITERAL(46, 586, 7), // "sendSeq"
QT_MOC_LITERAL(47, 594, 9), // "messageId"
QT_MOC_LITERAL(48, 604, 17), // "OnRecvRoomMessage"
QT_MOC_LITERAL(49, 622, 19), // "QVector<RoomMsgPtr>"
QT_MOC_LITERAL(50, 642, 12), // "vRoomMsgList"
QT_MOC_LITERAL(51, 655, 17), // "OnJoinLiveRequest"
QT_MOC_LITERAL(52, 673, 3), // "seq"
QT_MOC_LITERAL(53, 677, 10), // "fromUserId"
QT_MOC_LITERAL(54, 688, 12), // "fromUserName"
QT_MOC_LITERAL(55, 701, 20), // "OnAudioDeviceChanged"
QT_MOC_LITERAL(56, 722, 19), // "AV::AudioDeviceType"
QT_MOC_LITERAL(57, 742, 10), // "deviceType"
QT_MOC_LITERAL(58, 753, 11), // "strDeviceId"
QT_MOC_LITERAL(59, 765, 13), // "strDeviceName"
QT_MOC_LITERAL(60, 779, 15), // "AV::DeviceState"
QT_MOC_LITERAL(61, 795, 5), // "state"
QT_MOC_LITERAL(62, 801, 20), // "OnVideoDeviceChanged"
QT_MOC_LITERAL(63, 822, 18), // "OnClickTitleButton"
QT_MOC_LITERAL(64, 841, 7), // "OnClose"
QT_MOC_LITERAL(65, 849, 21), // "OnButtonSwitchPublish"
QT_MOC_LITERAL(66, 871, 19), // "OnButtonSendMessage"
QT_MOC_LITERAL(67, 891, 20), // "OnButtonSoundCapture"
QT_MOC_LITERAL(68, 912, 18), // "OnButtonMircoPhone"
QT_MOC_LITERAL(69, 931, 13), // "OnButtonSound"
QT_MOC_LITERAL(70, 945, 12), // "OnProgChange"
QT_MOC_LITERAL(71, 958, 11), // "OnShareLink"
QT_MOC_LITERAL(72, 970, 11), // "OnButtonAux"
QT_MOC_LITERAL(73, 982, 15), // "OnUseDefaultAux"
QT_MOC_LITERAL(74, 998, 17), // "OnGetMusicAppPath"
QT_MOC_LITERAL(75, 1016, 7), // "exePath"
QT_MOC_LITERAL(76, 1024, 19), // "OnSwitchAudioDevice"
QT_MOC_LITERAL(77, 1044, 2), // "id"
QT_MOC_LITERAL(78, 1047, 19) // "OnSwitchVideoDevice"

    },
    "ZegoMoreAnchorDialog\0sigSaveVideoSettings\0"
    "\0SettingsPtr\0settings\0OnLoginRoom\0"
    "errorCode\0roomId\0QVector<StreamPtr>\0"
    "vStreamList\0OnStreamUpdated\0"
    "LIVEROOM::ZegoStreamUpdateType\0type\0"
    "OnPublishStateUpdate\0stateCode\0streamId\0"
    "StreamPtr\0streamInfo\0OnPlayStateUpdate\0"
    "OnUserUpdate\0QVector<QString>\0userIDs\0"
    "userNames\0QVector<int>\0userFlags\0"
    "userRoles\0userCount\0LIVEROOM::ZegoUserUpdateType\0"
    "OnDisconnect\0OnKickOut\0reason\0"
    "OnPlayQualityUpdate\0quality\0videoFPS\0"
    "videoKBS\0OnPublishQualityUpdate\0"
    "OnAVAuxInput\0unsigned char*\0pData\0"
    "int*\0pDataLen\0pDataLenValue\0pSampleRate\0"
    "pNumChannels\0OnSendRoomMessage\0roomID\0"
    "sendSeq\0messageId\0OnRecvRoomMessage\0"
    "QVector<RoomMsgPtr>\0vRoomMsgList\0"
    "OnJoinLiveRequest\0seq\0fromUserId\0"
    "fromUserName\0OnAudioDeviceChanged\0"
    "AV::AudioDeviceType\0deviceType\0"
    "strDeviceId\0strDeviceName\0AV::DeviceState\0"
    "state\0OnVideoDeviceChanged\0"
    "OnClickTitleButton\0OnClose\0"
    "OnButtonSwitchPublish\0OnButtonSendMessage\0"
    "OnButtonSoundCapture\0OnButtonMircoPhone\0"
    "OnButtonSound\0OnProgChange\0OnShareLink\0"
    "OnButtonAux\0OnUseDefaultAux\0"
    "OnGetMusicAppPath\0exePath\0OnSwitchAudioDevice\0"
    "id\0OnSwitchVideoDevice"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ZegoMoreAnchorDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      30,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  164,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    3,  167,    2, 0x09 /* Protected */,
      10,    3,  174,    2, 0x09 /* Protected */,
      13,    3,  181,    2, 0x09 /* Protected */,
      18,    2,  188,    2, 0x09 /* Protected */,
      19,    6,  193,    2, 0x09 /* Protected */,
      28,    2,  206,    2, 0x09 /* Protected */,
      29,    2,  211,    2, 0x09 /* Protected */,
      31,    4,  216,    2, 0x09 /* Protected */,
      35,    4,  225,    2, 0x09 /* Protected */,
      36,    5,  234,    2, 0x09 /* Protected */,
      44,    4,  245,    2, 0x09 /* Protected */,
      48,    2,  254,    2, 0x09 /* Protected */,
      51,    4,  259,    2, 0x09 /* Protected */,
      55,    4,  268,    2, 0x09 /* Protected */,
      62,    3,  277,    2, 0x09 /* Protected */,
      63,    0,  284,    2, 0x08 /* Private */,
      64,    0,  285,    2, 0x08 /* Private */,
      65,    0,  286,    2, 0x08 /* Private */,
      66,    0,  287,    2, 0x08 /* Private */,
      67,    0,  288,    2, 0x08 /* Private */,
      68,    0,  289,    2, 0x08 /* Private */,
      69,    0,  290,    2, 0x08 /* Private */,
      70,    0,  291,    2, 0x08 /* Private */,
      71,    0,  292,    2, 0x08 /* Private */,
      72,    0,  293,    2, 0x08 /* Private */,
      73,    1,  294,    2, 0x08 /* Private */,
      74,    1,  297,    2, 0x08 /* Private */,
      76,    1,  300,    2, 0x08 /* Private */,
      78,    1,  303,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, 0x80000000 | 8,    6,    7,    9,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 8, 0x80000000 | 11,    7,    9,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, 0x80000000 | 16,   14,   15,   17,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   14,   15,
    QMetaType::Void, 0x80000000 | 20, 0x80000000 | 20, 0x80000000 | 23, 0x80000000 | 23, QMetaType::UInt, 0x80000000 | 27,   21,   22,   24,   25,   26,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   30,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Double, QMetaType::Double,   15,   32,   33,   34,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Double, QMetaType::Double,   15,   32,   33,   34,
    QMetaType::Void, 0x80000000 | 37, 0x80000000 | 39, QMetaType::Int, 0x80000000 | 39, 0x80000000 | 39,   38,   40,   41,   42,   43,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::ULongLong,    6,   45,   46,   47,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 49,    7,   50,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,   52,   53,   54,    7,
    QMetaType::Void, 0x80000000 | 56, QMetaType::QString, QMetaType::QString, 0x80000000 | 60,   57,   58,   59,   61,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 60,   58,   59,   61,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   61,
    QMetaType::Void, QMetaType::QString,   75,
    QMetaType::Void, QMetaType::Int,   77,
    QMetaType::Void, QMetaType::Int,   77,

       0        // eod
};

void ZegoMoreAnchorDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ZegoMoreAnchorDialog *_t = static_cast<ZegoMoreAnchorDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigSaveVideoSettings((*reinterpret_cast< SettingsPtr(*)>(_a[1]))); break;
        case 1: _t->OnLoginRoom((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< QVector<StreamPtr>(*)>(_a[3]))); break;
        case 2: _t->OnStreamUpdated((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QVector<StreamPtr>(*)>(_a[2])),(*reinterpret_cast< LIVEROOM::ZegoStreamUpdateType(*)>(_a[3]))); break;
        case 3: _t->OnPublishStateUpdate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< StreamPtr(*)>(_a[3]))); break;
        case 4: _t->OnPlayStateUpdate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 5: _t->OnUserUpdate((*reinterpret_cast< QVector<QString>(*)>(_a[1])),(*reinterpret_cast< QVector<QString>(*)>(_a[2])),(*reinterpret_cast< QVector<int>(*)>(_a[3])),(*reinterpret_cast< QVector<int>(*)>(_a[4])),(*reinterpret_cast< uint(*)>(_a[5])),(*reinterpret_cast< LIVEROOM::ZegoUserUpdateType(*)>(_a[6]))); break;
        case 6: _t->OnDisconnect((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 7: _t->OnKickOut((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 8: _t->OnPlayQualityUpdate((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 9: _t->OnPublishQualityUpdate((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 10: _t->OnAVAuxInput((*reinterpret_cast< unsigned char*(*)>(_a[1])),(*reinterpret_cast< int*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int*(*)>(_a[4])),(*reinterpret_cast< int*(*)>(_a[5]))); break;
        case 11: _t->OnSendRoomMessage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< unsigned long long(*)>(_a[4]))); break;
        case 12: _t->OnRecvRoomMessage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QVector<RoomMsgPtr>(*)>(_a[2]))); break;
        case 13: _t->OnJoinLiveRequest((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 14: _t->OnAudioDeviceChanged((*reinterpret_cast< AV::AudioDeviceType(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< AV::DeviceState(*)>(_a[4]))); break;
        case 15: _t->OnVideoDeviceChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< AV::DeviceState(*)>(_a[3]))); break;
        case 16: _t->OnClickTitleButton(); break;
        case 17: _t->OnClose(); break;
        case 18: _t->OnButtonSwitchPublish(); break;
        case 19: _t->OnButtonSendMessage(); break;
        case 20: _t->OnButtonSoundCapture(); break;
        case 21: _t->OnButtonMircoPhone(); break;
        case 22: _t->OnButtonSound(); break;
        case 23: _t->OnProgChange(); break;
        case 24: _t->OnShareLink(); break;
        case 25: _t->OnButtonAux(); break;
        case 26: _t->OnUseDefaultAux((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 27: _t->OnGetMusicAppPath((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 28: _t->OnSwitchAudioDevice((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->OnSwitchVideoDevice((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
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
            typedef void (ZegoMoreAnchorDialog::*_t)(SettingsPtr );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ZegoMoreAnchorDialog::sigSaveVideoSettings)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ZegoMoreAnchorDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ZegoMoreAnchorDialog.data,
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
    return QDialog::qt_metacast(_clname);
}

int ZegoMoreAnchorDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    }
    return _id;
}

// SIGNAL 0
void ZegoMoreAnchorDialog::sigSaveVideoSettings(SettingsPtr _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

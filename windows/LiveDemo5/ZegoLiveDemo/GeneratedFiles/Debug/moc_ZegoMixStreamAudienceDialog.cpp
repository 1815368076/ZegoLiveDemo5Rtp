/****************************************************************************
** Meta object code from reading C++ file 'ZegoMixStreamAudienceDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Dialog/ZegoMixStreamAudienceDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ZegoMixStreamAudienceDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ZegoMixStreamAudienceDialog_t {
    QByteArrayData data[87];
    char stringdata0[1157];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ZegoMixStreamAudienceDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ZegoMixStreamAudienceDialog_t qt_meta_stringdata_ZegoMixStreamAudienceDialog = {
    {
QT_MOC_LITERAL(0, 0, 27), // "ZegoMixStreamAudienceDialog"
QT_MOC_LITERAL(1, 28, 20), // "sigSaveVideoSettings"
QT_MOC_LITERAL(2, 49, 0), // ""
QT_MOC_LITERAL(3, 50, 11), // "SettingsPtr"
QT_MOC_LITERAL(4, 62, 8), // "settings"
QT_MOC_LITERAL(5, 71, 11), // "OnLoginRoom"
QT_MOC_LITERAL(6, 83, 9), // "errorCode"
QT_MOC_LITERAL(7, 93, 6), // "roomId"
QT_MOC_LITERAL(8, 100, 18), // "QVector<StreamPtr>"
QT_MOC_LITERAL(9, 119, 11), // "vStreamList"
QT_MOC_LITERAL(10, 131, 15), // "OnStreamUpdated"
QT_MOC_LITERAL(11, 147, 30), // "LIVEROOM::ZegoStreamUpdateType"
QT_MOC_LITERAL(12, 178, 4), // "type"
QT_MOC_LITERAL(13, 183, 20), // "OnPublishStateUpdate"
QT_MOC_LITERAL(14, 204, 9), // "stateCode"
QT_MOC_LITERAL(15, 214, 8), // "streamId"
QT_MOC_LITERAL(16, 223, 9), // "StreamPtr"
QT_MOC_LITERAL(17, 233, 10), // "streamInfo"
QT_MOC_LITERAL(18, 244, 17), // "OnPlayStateUpdate"
QT_MOC_LITERAL(19, 262, 12), // "OnUserUpdate"
QT_MOC_LITERAL(20, 275, 16), // "QVector<QString>"
QT_MOC_LITERAL(21, 292, 7), // "userIDs"
QT_MOC_LITERAL(22, 300, 9), // "userNames"
QT_MOC_LITERAL(23, 310, 12), // "QVector<int>"
QT_MOC_LITERAL(24, 323, 9), // "userFlags"
QT_MOC_LITERAL(25, 333, 9), // "userRoles"
QT_MOC_LITERAL(26, 343, 9), // "userCount"
QT_MOC_LITERAL(27, 353, 28), // "LIVEROOM::ZegoUserUpdateType"
QT_MOC_LITERAL(28, 382, 12), // "OnDisconnect"
QT_MOC_LITERAL(29, 395, 9), // "OnKickOut"
QT_MOC_LITERAL(30, 405, 6), // "reason"
QT_MOC_LITERAL(31, 412, 19), // "OnPlayQualityUpdate"
QT_MOC_LITERAL(32, 432, 7), // "quality"
QT_MOC_LITERAL(33, 440, 8), // "videoFPS"
QT_MOC_LITERAL(34, 449, 8), // "videoKBS"
QT_MOC_LITERAL(35, 458, 22), // "OnPublishQualityUpdate"
QT_MOC_LITERAL(36, 481, 12), // "OnAVAuxInput"
QT_MOC_LITERAL(37, 494, 14), // "unsigned char*"
QT_MOC_LITERAL(38, 509, 5), // "pData"
QT_MOC_LITERAL(39, 515, 4), // "int*"
QT_MOC_LITERAL(40, 520, 8), // "pDataLen"
QT_MOC_LITERAL(41, 529, 13), // "pDataLenValue"
QT_MOC_LITERAL(42, 543, 11), // "pSampleRate"
QT_MOC_LITERAL(43, 555, 12), // "pNumChannels"
QT_MOC_LITERAL(44, 568, 17), // "OnSendRoomMessage"
QT_MOC_LITERAL(45, 586, 6), // "roomID"
QT_MOC_LITERAL(46, 593, 7), // "sendSeq"
QT_MOC_LITERAL(47, 601, 9), // "messageId"
QT_MOC_LITERAL(48, 611, 17), // "OnRecvRoomMessage"
QT_MOC_LITERAL(49, 629, 19), // "QVector<RoomMsgPtr>"
QT_MOC_LITERAL(50, 649, 12), // "vRoomMsgList"
QT_MOC_LITERAL(51, 662, 18), // "OnJoinLiveResponse"
QT_MOC_LITERAL(52, 681, 6), // "result"
QT_MOC_LITERAL(53, 688, 10), // "fromUserId"
QT_MOC_LITERAL(54, 699, 12), // "fromUserName"
QT_MOC_LITERAL(55, 712, 3), // "seq"
QT_MOC_LITERAL(56, 716, 20), // "OnAudioDeviceChanged"
QT_MOC_LITERAL(57, 737, 19), // "AV::AudioDeviceType"
QT_MOC_LITERAL(58, 757, 10), // "deviceType"
QT_MOC_LITERAL(59, 768, 11), // "strDeviceId"
QT_MOC_LITERAL(60, 780, 13), // "strDeviceName"
QT_MOC_LITERAL(61, 794, 15), // "AV::DeviceState"
QT_MOC_LITERAL(62, 810, 5), // "state"
QT_MOC_LITERAL(63, 816, 20), // "OnVideoDeviceChanged"
QT_MOC_LITERAL(64, 837, 11), // "OnMixStream"
QT_MOC_LITERAL(65, 849, 6), // "hlsUrl"
QT_MOC_LITERAL(66, 856, 7), // "rtmpUrl"
QT_MOC_LITERAL(67, 864, 11), // "mixStreamID"
QT_MOC_LITERAL(68, 876, 24), // "OnRecvEndJoinLiveCommand"
QT_MOC_LITERAL(69, 901, 6), // "userId"
QT_MOC_LITERAL(70, 908, 8), // "userName"
QT_MOC_LITERAL(71, 917, 18), // "OnClickTitleButton"
QT_MOC_LITERAL(72, 936, 7), // "OnClose"
QT_MOC_LITERAL(73, 944, 16), // "OnButtonJoinLive"
QT_MOC_LITERAL(74, 961, 19), // "OnButtonSendMessage"
QT_MOC_LITERAL(75, 981, 20), // "OnButtonSoundCapture"
QT_MOC_LITERAL(76, 1002, 18), // "OnButtonMircoPhone"
QT_MOC_LITERAL(77, 1021, 13), // "OnButtonSound"
QT_MOC_LITERAL(78, 1035, 12), // "OnProgChange"
QT_MOC_LITERAL(79, 1048, 11), // "OnShareLink"
QT_MOC_LITERAL(80, 1060, 11), // "OnButtonAux"
QT_MOC_LITERAL(81, 1072, 15), // "OnUseDefaultAux"
QT_MOC_LITERAL(82, 1088, 17), // "OnGetMusicAppPath"
QT_MOC_LITERAL(83, 1106, 7), // "exePath"
QT_MOC_LITERAL(84, 1114, 19), // "OnSwitchAudioDevice"
QT_MOC_LITERAL(85, 1134, 2), // "id"
QT_MOC_LITERAL(86, 1137, 19) // "OnSwitchVideoDevice"

    },
    "ZegoMixStreamAudienceDialog\0"
    "sigSaveVideoSettings\0\0SettingsPtr\0"
    "settings\0OnLoginRoom\0errorCode\0roomId\0"
    "QVector<StreamPtr>\0vStreamList\0"
    "OnStreamUpdated\0LIVEROOM::ZegoStreamUpdateType\0"
    "type\0OnPublishStateUpdate\0stateCode\0"
    "streamId\0StreamPtr\0streamInfo\0"
    "OnPlayStateUpdate\0OnUserUpdate\0"
    "QVector<QString>\0userIDs\0userNames\0"
    "QVector<int>\0userFlags\0userRoles\0"
    "userCount\0LIVEROOM::ZegoUserUpdateType\0"
    "OnDisconnect\0OnKickOut\0reason\0"
    "OnPlayQualityUpdate\0quality\0videoFPS\0"
    "videoKBS\0OnPublishQualityUpdate\0"
    "OnAVAuxInput\0unsigned char*\0pData\0"
    "int*\0pDataLen\0pDataLenValue\0pSampleRate\0"
    "pNumChannels\0OnSendRoomMessage\0roomID\0"
    "sendSeq\0messageId\0OnRecvRoomMessage\0"
    "QVector<RoomMsgPtr>\0vRoomMsgList\0"
    "OnJoinLiveResponse\0result\0fromUserId\0"
    "fromUserName\0seq\0OnAudioDeviceChanged\0"
    "AV::AudioDeviceType\0deviceType\0"
    "strDeviceId\0strDeviceName\0AV::DeviceState\0"
    "state\0OnVideoDeviceChanged\0OnMixStream\0"
    "hlsUrl\0rtmpUrl\0mixStreamID\0"
    "OnRecvEndJoinLiveCommand\0userId\0"
    "userName\0OnClickTitleButton\0OnClose\0"
    "OnButtonJoinLive\0OnButtonSendMessage\0"
    "OnButtonSoundCapture\0OnButtonMircoPhone\0"
    "OnButtonSound\0OnProgChange\0OnShareLink\0"
    "OnButtonAux\0OnUseDefaultAux\0"
    "OnGetMusicAppPath\0exePath\0OnSwitchAudioDevice\0"
    "id\0OnSwitchVideoDevice"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ZegoMixStreamAudienceDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      32,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  174,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    3,  177,    2, 0x09 /* Protected */,
      10,    3,  184,    2, 0x09 /* Protected */,
      13,    3,  191,    2, 0x09 /* Protected */,
      18,    2,  198,    2, 0x09 /* Protected */,
      19,    6,  203,    2, 0x09 /* Protected */,
      28,    2,  216,    2, 0x09 /* Protected */,
      29,    2,  221,    2, 0x09 /* Protected */,
      31,    4,  226,    2, 0x09 /* Protected */,
      35,    4,  235,    2, 0x09 /* Protected */,
      36,    5,  244,    2, 0x09 /* Protected */,
      44,    4,  255,    2, 0x09 /* Protected */,
      48,    2,  264,    2, 0x09 /* Protected */,
      51,    4,  269,    2, 0x09 /* Protected */,
      56,    4,  278,    2, 0x09 /* Protected */,
      63,    3,  287,    2, 0x09 /* Protected */,
      64,    5,  294,    2, 0x09 /* Protected */,
      68,    3,  305,    2, 0x09 /* Protected */,
      71,    0,  312,    2, 0x08 /* Private */,
      72,    0,  313,    2, 0x08 /* Private */,
      73,    0,  314,    2, 0x08 /* Private */,
      74,    0,  315,    2, 0x08 /* Private */,
      75,    0,  316,    2, 0x08 /* Private */,
      76,    0,  317,    2, 0x08 /* Private */,
      77,    0,  318,    2, 0x08 /* Private */,
      78,    0,  319,    2, 0x08 /* Private */,
      79,    0,  320,    2, 0x08 /* Private */,
      80,    0,  321,    2, 0x08 /* Private */,
      81,    1,  322,    2, 0x08 /* Private */,
      82,    1,  325,    2, 0x08 /* Private */,
      84,    1,  328,    2, 0x08 /* Private */,
      86,    1,  331,    2, 0x08 /* Private */,

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
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Int,   52,   53,   54,   55,
    QMetaType::Void, 0x80000000 | 57, QMetaType::QString, QMetaType::QString, 0x80000000 | 61,   58,   59,   60,   62,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 61,   59,   60,   62,
    QMetaType::Void, QMetaType::UInt, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int,    6,   65,   66,   67,   55,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   69,   70,    7,
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
    QMetaType::Void, QMetaType::Bool,   62,
    QMetaType::Void, QMetaType::QString,   83,
    QMetaType::Void, QMetaType::Int,   85,
    QMetaType::Void, QMetaType::Int,   85,

       0        // eod
};

void ZegoMixStreamAudienceDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ZegoMixStreamAudienceDialog *_t = static_cast<ZegoMixStreamAudienceDialog *>(_o);
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
        case 13: _t->OnJoinLiveResponse((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 14: _t->OnAudioDeviceChanged((*reinterpret_cast< AV::AudioDeviceType(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< AV::DeviceState(*)>(_a[4]))); break;
        case 15: _t->OnVideoDeviceChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< AV::DeviceState(*)>(_a[3]))); break;
        case 16: _t->OnMixStream((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 17: _t->OnRecvEndJoinLiveCommand((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 18: _t->OnClickTitleButton(); break;
        case 19: _t->OnClose(); break;
        case 20: _t->OnButtonJoinLive(); break;
        case 21: _t->OnButtonSendMessage(); break;
        case 22: _t->OnButtonSoundCapture(); break;
        case 23: _t->OnButtonMircoPhone(); break;
        case 24: _t->OnButtonSound(); break;
        case 25: _t->OnProgChange(); break;
        case 26: _t->OnShareLink(); break;
        case 27: _t->OnButtonAux(); break;
        case 28: _t->OnUseDefaultAux((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 29: _t->OnGetMusicAppPath((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 30: _t->OnSwitchAudioDevice((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: _t->OnSwitchVideoDevice((*reinterpret_cast< int(*)>(_a[1]))); break;
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
            typedef void (ZegoMixStreamAudienceDialog::*_t)(SettingsPtr );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ZegoMixStreamAudienceDialog::sigSaveVideoSettings)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ZegoMixStreamAudienceDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ZegoMixStreamAudienceDialog.data,
      qt_meta_data_ZegoMixStreamAudienceDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ZegoMixStreamAudienceDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZegoMixStreamAudienceDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ZegoMixStreamAudienceDialog.stringdata0))
        return static_cast<void*>(const_cast< ZegoMixStreamAudienceDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ZegoMixStreamAudienceDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 32)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 32;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 32)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 32;
    }
    return _id;
}

// SIGNAL 0
void ZegoMixStreamAudienceDialog::sigSaveVideoSettings(SettingsPtr _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

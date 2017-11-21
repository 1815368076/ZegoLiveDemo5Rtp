/****************************************************************************
** Meta object code from reading C++ file 'ZegoMixStreamAnchorDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Dialog/ZegoMixStreamAnchorDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ZegoMixStreamAnchorDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ZegoMixStreamAnchorDialog_t {
    QByteArrayData data[83];
    char stringdata0[1111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ZegoMixStreamAnchorDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ZegoMixStreamAnchorDialog_t qt_meta_stringdata_ZegoMixStreamAnchorDialog = {
    {
QT_MOC_LITERAL(0, 0, 25), // "ZegoMixStreamAnchorDialog"
QT_MOC_LITERAL(1, 26, 20), // "sigSaveVideoSettings"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 11), // "SettingsPtr"
QT_MOC_LITERAL(4, 60, 8), // "settings"
QT_MOC_LITERAL(5, 69, 11), // "OnLoginRoom"
QT_MOC_LITERAL(6, 81, 9), // "errorCode"
QT_MOC_LITERAL(7, 91, 6), // "roomId"
QT_MOC_LITERAL(8, 98, 18), // "QVector<StreamPtr>"
QT_MOC_LITERAL(9, 117, 11), // "vStreamList"
QT_MOC_LITERAL(10, 129, 15), // "OnStreamUpdated"
QT_MOC_LITERAL(11, 145, 30), // "LIVEROOM::ZegoStreamUpdateType"
QT_MOC_LITERAL(12, 176, 4), // "type"
QT_MOC_LITERAL(13, 181, 20), // "OnPublishStateUpdate"
QT_MOC_LITERAL(14, 202, 9), // "stateCode"
QT_MOC_LITERAL(15, 212, 8), // "streamId"
QT_MOC_LITERAL(16, 221, 9), // "StreamPtr"
QT_MOC_LITERAL(17, 231, 10), // "streamInfo"
QT_MOC_LITERAL(18, 242, 17), // "OnPlayStateUpdate"
QT_MOC_LITERAL(19, 260, 12), // "OnUserUpdate"
QT_MOC_LITERAL(20, 273, 16), // "QVector<QString>"
QT_MOC_LITERAL(21, 290, 7), // "userIDs"
QT_MOC_LITERAL(22, 298, 9), // "userNames"
QT_MOC_LITERAL(23, 308, 12), // "QVector<int>"
QT_MOC_LITERAL(24, 321, 9), // "userFlags"
QT_MOC_LITERAL(25, 331, 9), // "userRoles"
QT_MOC_LITERAL(26, 341, 9), // "userCount"
QT_MOC_LITERAL(27, 351, 28), // "LIVEROOM::ZegoUserUpdateType"
QT_MOC_LITERAL(28, 380, 12), // "OnDisconnect"
QT_MOC_LITERAL(29, 393, 9), // "OnKickOut"
QT_MOC_LITERAL(30, 403, 6), // "reason"
QT_MOC_LITERAL(31, 410, 19), // "OnPlayQualityUpdate"
QT_MOC_LITERAL(32, 430, 7), // "quality"
QT_MOC_LITERAL(33, 438, 8), // "videoFPS"
QT_MOC_LITERAL(34, 447, 8), // "videoKBS"
QT_MOC_LITERAL(35, 456, 22), // "OnPublishQualityUpdate"
QT_MOC_LITERAL(36, 479, 12), // "OnAVAuxInput"
QT_MOC_LITERAL(37, 492, 14), // "unsigned char*"
QT_MOC_LITERAL(38, 507, 5), // "pData"
QT_MOC_LITERAL(39, 513, 4), // "int*"
QT_MOC_LITERAL(40, 518, 8), // "pDataLen"
QT_MOC_LITERAL(41, 527, 13), // "pDataLenValue"
QT_MOC_LITERAL(42, 541, 11), // "pSampleRate"
QT_MOC_LITERAL(43, 553, 12), // "pNumChannels"
QT_MOC_LITERAL(44, 566, 17), // "OnSendRoomMessage"
QT_MOC_LITERAL(45, 584, 6), // "roomID"
QT_MOC_LITERAL(46, 591, 7), // "sendSeq"
QT_MOC_LITERAL(47, 599, 9), // "messageId"
QT_MOC_LITERAL(48, 609, 17), // "OnRecvRoomMessage"
QT_MOC_LITERAL(49, 627, 19), // "QVector<RoomMsgPtr>"
QT_MOC_LITERAL(50, 647, 12), // "vRoomMsgList"
QT_MOC_LITERAL(51, 660, 17), // "OnJoinLiveRequest"
QT_MOC_LITERAL(52, 678, 3), // "seq"
QT_MOC_LITERAL(53, 682, 10), // "fromUserId"
QT_MOC_LITERAL(54, 693, 12), // "fromUserName"
QT_MOC_LITERAL(55, 706, 20), // "OnAudioDeviceChanged"
QT_MOC_LITERAL(56, 727, 19), // "AV::AudioDeviceType"
QT_MOC_LITERAL(57, 747, 10), // "deviceType"
QT_MOC_LITERAL(58, 758, 11), // "strDeviceId"
QT_MOC_LITERAL(59, 770, 13), // "strDeviceName"
QT_MOC_LITERAL(60, 784, 15), // "AV::DeviceState"
QT_MOC_LITERAL(61, 800, 5), // "state"
QT_MOC_LITERAL(62, 806, 20), // "OnVideoDeviceChanged"
QT_MOC_LITERAL(63, 827, 11), // "OnMixStream"
QT_MOC_LITERAL(64, 839, 6), // "hlsUrl"
QT_MOC_LITERAL(65, 846, 7), // "rtmpUrl"
QT_MOC_LITERAL(66, 854, 11), // "mixStreamID"
QT_MOC_LITERAL(67, 866, 18), // "OnClickTitleButton"
QT_MOC_LITERAL(68, 885, 7), // "OnClose"
QT_MOC_LITERAL(69, 893, 21), // "OnButtonSwitchPublish"
QT_MOC_LITERAL(70, 915, 19), // "OnButtonSendMessage"
QT_MOC_LITERAL(71, 935, 20), // "OnButtonSoundCapture"
QT_MOC_LITERAL(72, 956, 18), // "OnButtonMircoPhone"
QT_MOC_LITERAL(73, 975, 13), // "OnButtonSound"
QT_MOC_LITERAL(74, 989, 12), // "OnProgChange"
QT_MOC_LITERAL(75, 1002, 11), // "OnShareLink"
QT_MOC_LITERAL(76, 1014, 11), // "OnButtonAux"
QT_MOC_LITERAL(77, 1026, 15), // "OnUseDefaultAux"
QT_MOC_LITERAL(78, 1042, 17), // "OnGetMusicAppPath"
QT_MOC_LITERAL(79, 1060, 7), // "exePath"
QT_MOC_LITERAL(80, 1068, 19), // "OnSwitchAudioDevice"
QT_MOC_LITERAL(81, 1088, 2), // "id"
QT_MOC_LITERAL(82, 1091, 19) // "OnSwitchVideoDevice"

    },
    "ZegoMixStreamAnchorDialog\0"
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
    "OnJoinLiveRequest\0seq\0fromUserId\0"
    "fromUserName\0OnAudioDeviceChanged\0"
    "AV::AudioDeviceType\0deviceType\0"
    "strDeviceId\0strDeviceName\0AV::DeviceState\0"
    "state\0OnVideoDeviceChanged\0OnMixStream\0"
    "hlsUrl\0rtmpUrl\0mixStreamID\0"
    "OnClickTitleButton\0OnClose\0"
    "OnButtonSwitchPublish\0OnButtonSendMessage\0"
    "OnButtonSoundCapture\0OnButtonMircoPhone\0"
    "OnButtonSound\0OnProgChange\0OnShareLink\0"
    "OnButtonAux\0OnUseDefaultAux\0"
    "OnGetMusicAppPath\0exePath\0OnSwitchAudioDevice\0"
    "id\0OnSwitchVideoDevice"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ZegoMixStreamAnchorDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      31,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  169,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    3,  172,    2, 0x09 /* Protected */,
      10,    3,  179,    2, 0x09 /* Protected */,
      13,    3,  186,    2, 0x09 /* Protected */,
      18,    2,  193,    2, 0x09 /* Protected */,
      19,    6,  198,    2, 0x09 /* Protected */,
      28,    2,  211,    2, 0x09 /* Protected */,
      29,    2,  216,    2, 0x09 /* Protected */,
      31,    4,  221,    2, 0x09 /* Protected */,
      35,    4,  230,    2, 0x09 /* Protected */,
      36,    5,  239,    2, 0x09 /* Protected */,
      44,    4,  250,    2, 0x09 /* Protected */,
      48,    2,  259,    2, 0x09 /* Protected */,
      51,    4,  264,    2, 0x09 /* Protected */,
      55,    4,  273,    2, 0x09 /* Protected */,
      62,    3,  282,    2, 0x09 /* Protected */,
      63,    5,  289,    2, 0x09 /* Protected */,
      67,    0,  300,    2, 0x08 /* Private */,
      68,    0,  301,    2, 0x08 /* Private */,
      69,    0,  302,    2, 0x08 /* Private */,
      70,    0,  303,    2, 0x08 /* Private */,
      71,    0,  304,    2, 0x08 /* Private */,
      72,    0,  305,    2, 0x08 /* Private */,
      73,    0,  306,    2, 0x08 /* Private */,
      74,    0,  307,    2, 0x08 /* Private */,
      75,    0,  308,    2, 0x08 /* Private */,
      76,    0,  309,    2, 0x08 /* Private */,
      77,    1,  310,    2, 0x08 /* Private */,
      78,    1,  313,    2, 0x08 /* Private */,
      80,    1,  316,    2, 0x08 /* Private */,
      82,    1,  319,    2, 0x08 /* Private */,

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
    QMetaType::Void, QMetaType::UInt, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int,    6,   64,   65,   66,   52,
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
    QMetaType::Void, QMetaType::QString,   79,
    QMetaType::Void, QMetaType::Int,   81,
    QMetaType::Void, QMetaType::Int,   81,

       0        // eod
};

void ZegoMixStreamAnchorDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ZegoMixStreamAnchorDialog *_t = static_cast<ZegoMixStreamAnchorDialog *>(_o);
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
        case 16: _t->OnMixStream((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 17: _t->OnClickTitleButton(); break;
        case 18: _t->OnClose(); break;
        case 19: _t->OnButtonSwitchPublish(); break;
        case 20: _t->OnButtonSendMessage(); break;
        case 21: _t->OnButtonSoundCapture(); break;
        case 22: _t->OnButtonMircoPhone(); break;
        case 23: _t->OnButtonSound(); break;
        case 24: _t->OnProgChange(); break;
        case 25: _t->OnShareLink(); break;
        case 26: _t->OnButtonAux(); break;
        case 27: _t->OnUseDefaultAux((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 28: _t->OnGetMusicAppPath((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 29: _t->OnSwitchAudioDevice((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->OnSwitchVideoDevice((*reinterpret_cast< int(*)>(_a[1]))); break;
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
            typedef void (ZegoMixStreamAnchorDialog::*_t)(SettingsPtr );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ZegoMixStreamAnchorDialog::sigSaveVideoSettings)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ZegoMixStreamAnchorDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ZegoMixStreamAnchorDialog.data,
      qt_meta_data_ZegoMixStreamAnchorDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ZegoMixStreamAnchorDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZegoMixStreamAnchorDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ZegoMixStreamAnchorDialog.stringdata0))
        return static_cast<void*>(const_cast< ZegoMixStreamAnchorDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ZegoMixStreamAnchorDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    }
    return _id;
}

// SIGNAL 0
void ZegoMixStreamAnchorDialog::sigSaveVideoSettings(SettingsPtr _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

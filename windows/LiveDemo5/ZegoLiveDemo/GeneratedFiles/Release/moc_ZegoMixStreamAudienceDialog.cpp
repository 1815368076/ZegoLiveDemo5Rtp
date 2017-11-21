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
    QByteArrayData data[98];
    char stringdata0[1325];
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
QT_MOC_LITERAL(5, 71, 20), // "sigShowSnapShotImage"
QT_MOC_LITERAL(6, 92, 7), // "QImage*"
QT_MOC_LITERAL(7, 100, 9), // "imageData"
QT_MOC_LITERAL(8, 110, 11), // "OnLoginRoom"
QT_MOC_LITERAL(9, 122, 9), // "errorCode"
QT_MOC_LITERAL(10, 132, 6), // "roomId"
QT_MOC_LITERAL(11, 139, 18), // "QVector<StreamPtr>"
QT_MOC_LITERAL(12, 158, 11), // "vStreamList"
QT_MOC_LITERAL(13, 170, 15), // "OnStreamUpdated"
QT_MOC_LITERAL(14, 186, 30), // "LIVEROOM::ZegoStreamUpdateType"
QT_MOC_LITERAL(15, 217, 4), // "type"
QT_MOC_LITERAL(16, 222, 20), // "OnPublishStateUpdate"
QT_MOC_LITERAL(17, 243, 9), // "stateCode"
QT_MOC_LITERAL(18, 253, 8), // "streamId"
QT_MOC_LITERAL(19, 262, 9), // "StreamPtr"
QT_MOC_LITERAL(20, 272, 10), // "streamInfo"
QT_MOC_LITERAL(21, 283, 17), // "OnPlayStateUpdate"
QT_MOC_LITERAL(22, 301, 12), // "OnUserUpdate"
QT_MOC_LITERAL(23, 314, 16), // "QVector<QString>"
QT_MOC_LITERAL(24, 331, 7), // "userIDs"
QT_MOC_LITERAL(25, 339, 9), // "userNames"
QT_MOC_LITERAL(26, 349, 12), // "QVector<int>"
QT_MOC_LITERAL(27, 362, 9), // "userFlags"
QT_MOC_LITERAL(28, 372, 9), // "userRoles"
QT_MOC_LITERAL(29, 382, 9), // "userCount"
QT_MOC_LITERAL(30, 392, 28), // "LIVEROOM::ZegoUserUpdateType"
QT_MOC_LITERAL(31, 421, 12), // "OnDisconnect"
QT_MOC_LITERAL(32, 434, 9), // "OnKickOut"
QT_MOC_LITERAL(33, 444, 6), // "reason"
QT_MOC_LITERAL(34, 451, 19), // "OnPlayQualityUpdate"
QT_MOC_LITERAL(35, 471, 7), // "quality"
QT_MOC_LITERAL(36, 479, 8), // "videoFPS"
QT_MOC_LITERAL(37, 488, 8), // "videoKBS"
QT_MOC_LITERAL(38, 497, 22), // "OnPublishQualityUpdate"
QT_MOC_LITERAL(39, 520, 12), // "OnAVAuxInput"
QT_MOC_LITERAL(40, 533, 14), // "unsigned char*"
QT_MOC_LITERAL(41, 548, 5), // "pData"
QT_MOC_LITERAL(42, 554, 4), // "int*"
QT_MOC_LITERAL(43, 559, 8), // "pDataLen"
QT_MOC_LITERAL(44, 568, 13), // "pDataLenValue"
QT_MOC_LITERAL(45, 582, 11), // "pSampleRate"
QT_MOC_LITERAL(46, 594, 12), // "pNumChannels"
QT_MOC_LITERAL(47, 607, 17), // "OnSendRoomMessage"
QT_MOC_LITERAL(48, 625, 6), // "roomID"
QT_MOC_LITERAL(49, 632, 7), // "sendSeq"
QT_MOC_LITERAL(50, 640, 9), // "messageId"
QT_MOC_LITERAL(51, 650, 17), // "OnRecvRoomMessage"
QT_MOC_LITERAL(52, 668, 19), // "QVector<RoomMsgPtr>"
QT_MOC_LITERAL(53, 688, 12), // "vRoomMsgList"
QT_MOC_LITERAL(54, 701, 18), // "OnJoinLiveResponse"
QT_MOC_LITERAL(55, 720, 6), // "result"
QT_MOC_LITERAL(56, 727, 10), // "fromUserId"
QT_MOC_LITERAL(57, 738, 12), // "fromUserName"
QT_MOC_LITERAL(58, 751, 3), // "seq"
QT_MOC_LITERAL(59, 755, 20), // "OnAudioDeviceChanged"
QT_MOC_LITERAL(60, 776, 19), // "AV::AudioDeviceType"
QT_MOC_LITERAL(61, 796, 10), // "deviceType"
QT_MOC_LITERAL(62, 807, 11), // "strDeviceId"
QT_MOC_LITERAL(63, 819, 13), // "strDeviceName"
QT_MOC_LITERAL(64, 833, 15), // "AV::DeviceState"
QT_MOC_LITERAL(65, 849, 5), // "state"
QT_MOC_LITERAL(66, 855, 20), // "OnVideoDeviceChanged"
QT_MOC_LITERAL(67, 876, 11), // "OnMixStream"
QT_MOC_LITERAL(68, 888, 6), // "hlsUrl"
QT_MOC_LITERAL(69, 895, 7), // "rtmpUrl"
QT_MOC_LITERAL(70, 903, 11), // "mixStreamID"
QT_MOC_LITERAL(71, 915, 24), // "OnRecvEndJoinLiveCommand"
QT_MOC_LITERAL(72, 940, 6), // "userId"
QT_MOC_LITERAL(73, 947, 8), // "userName"
QT_MOC_LITERAL(74, 956, 17), // "OnPreviewSnapshot"
QT_MOC_LITERAL(75, 974, 6), // "pImage"
QT_MOC_LITERAL(76, 981, 10), // "OnSnapshot"
QT_MOC_LITERAL(77, 992, 8), // "streamID"
QT_MOC_LITERAL(78, 1001, 18), // "OnClickTitleButton"
QT_MOC_LITERAL(79, 1020, 7), // "OnClose"
QT_MOC_LITERAL(80, 1028, 16), // "OnButtonJoinLive"
QT_MOC_LITERAL(81, 1045, 19), // "OnButtonSendMessage"
QT_MOC_LITERAL(82, 1065, 20), // "OnButtonSoundCapture"
QT_MOC_LITERAL(83, 1086, 18), // "OnButtonMircoPhone"
QT_MOC_LITERAL(84, 1105, 13), // "OnButtonSound"
QT_MOC_LITERAL(85, 1119, 12), // "OnProgChange"
QT_MOC_LITERAL(86, 1132, 11), // "OnShareLink"
QT_MOC_LITERAL(87, 1144, 11), // "OnButtonAux"
QT_MOC_LITERAL(88, 1156, 17), // "OnSnapshotPreview"
QT_MOC_LITERAL(89, 1174, 22), // "OnSnapshotWithStreamID"
QT_MOC_LITERAL(90, 1197, 15), // "OnUseDefaultAux"
QT_MOC_LITERAL(91, 1213, 17), // "OnGetMusicAppPath"
QT_MOC_LITERAL(92, 1231, 7), // "exePath"
QT_MOC_LITERAL(93, 1239, 19), // "OnSwitchAudioDevice"
QT_MOC_LITERAL(94, 1259, 2), // "id"
QT_MOC_LITERAL(95, 1262, 19), // "OnSwitchVideoDevice"
QT_MOC_LITERAL(96, 1282, 22), // "OnButtonShowFullScreen"
QT_MOC_LITERAL(97, 1305, 19) // "OnShowSnapShotImage"

    },
    "ZegoMixStreamAudienceDialog\0"
    "sigSaveVideoSettings\0\0SettingsPtr\0"
    "settings\0sigShowSnapShotImage\0QImage*\0"
    "imageData\0OnLoginRoom\0errorCode\0roomId\0"
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
    "userName\0OnPreviewSnapshot\0pImage\0"
    "OnSnapshot\0streamID\0OnClickTitleButton\0"
    "OnClose\0OnButtonJoinLive\0OnButtonSendMessage\0"
    "OnButtonSoundCapture\0OnButtonMircoPhone\0"
    "OnButtonSound\0OnProgChange\0OnShareLink\0"
    "OnButtonAux\0OnSnapshotPreview\0"
    "OnSnapshotWithStreamID\0OnUseDefaultAux\0"
    "OnGetMusicAppPath\0exePath\0OnSwitchAudioDevice\0"
    "id\0OnSwitchVideoDevice\0OnButtonShowFullScreen\0"
    "OnShowSnapShotImage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ZegoMixStreamAudienceDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      39,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  209,    2, 0x06 /* Public */,
       5,    1,  212,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    3,  215,    2, 0x09 /* Protected */,
      13,    3,  222,    2, 0x09 /* Protected */,
      16,    3,  229,    2, 0x09 /* Protected */,
      21,    2,  236,    2, 0x09 /* Protected */,
      22,    6,  241,    2, 0x09 /* Protected */,
      31,    2,  254,    2, 0x09 /* Protected */,
      32,    2,  259,    2, 0x09 /* Protected */,
      34,    4,  264,    2, 0x09 /* Protected */,
      38,    4,  273,    2, 0x09 /* Protected */,
      39,    5,  282,    2, 0x09 /* Protected */,
      47,    4,  293,    2, 0x09 /* Protected */,
      51,    2,  302,    2, 0x09 /* Protected */,
      54,    4,  307,    2, 0x09 /* Protected */,
      59,    4,  316,    2, 0x09 /* Protected */,
      66,    3,  325,    2, 0x09 /* Protected */,
      67,    5,  332,    2, 0x09 /* Protected */,
      71,    3,  343,    2, 0x09 /* Protected */,
      74,    1,  350,    2, 0x09 /* Protected */,
      76,    2,  353,    2, 0x09 /* Protected */,
      78,    0,  358,    2, 0x08 /* Private */,
      79,    0,  359,    2, 0x08 /* Private */,
      80,    0,  360,    2, 0x08 /* Private */,
      81,    0,  361,    2, 0x08 /* Private */,
      82,    0,  362,    2, 0x08 /* Private */,
      83,    0,  363,    2, 0x08 /* Private */,
      84,    0,  364,    2, 0x08 /* Private */,
      85,    0,  365,    2, 0x08 /* Private */,
      86,    0,  366,    2, 0x08 /* Private */,
      87,    0,  367,    2, 0x08 /* Private */,
      88,    0,  368,    2, 0x08 /* Private */,
      89,    1,  369,    2, 0x08 /* Private */,
      90,    1,  372,    2, 0x08 /* Private */,
      91,    1,  375,    2, 0x08 /* Private */,
      93,    1,  378,    2, 0x08 /* Private */,
      95,    1,  381,    2, 0x08 /* Private */,
      96,    0,  384,    2, 0x08 /* Private */,
      97,    1,  385,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, 0x80000000 | 11,    9,   10,   12,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 11, 0x80000000 | 14,   10,   12,   15,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, 0x80000000 | 19,   17,   18,   20,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   17,   18,
    QMetaType::Void, 0x80000000 | 23, 0x80000000 | 23, 0x80000000 | 26, 0x80000000 | 26, QMetaType::UInt, 0x80000000 | 30,   24,   25,   27,   28,   29,   15,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    9,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   33,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Double, QMetaType::Double,   18,   35,   36,   37,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Double, QMetaType::Double,   18,   35,   36,   37,
    QMetaType::Void, 0x80000000 | 40, 0x80000000 | 42, QMetaType::Int, 0x80000000 | 42, 0x80000000 | 42,   41,   43,   44,   45,   46,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::ULongLong,    9,   48,   49,   50,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 52,   10,   53,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Int,   55,   56,   57,   58,
    QMetaType::Void, 0x80000000 | 60, QMetaType::QString, QMetaType::QString, 0x80000000 | 64,   61,   62,   63,   65,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 64,   62,   63,   65,
    QMetaType::Void, QMetaType::UInt, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int,    9,   68,   69,   70,   58,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   72,   73,   10,
    QMetaType::Void, QMetaType::VoidStar,   75,
    QMetaType::Void, QMetaType::VoidStar, QMetaType::QString,   75,   77,
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
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   77,
    QMetaType::Void, QMetaType::Bool,   65,
    QMetaType::Void, QMetaType::QString,   92,
    QMetaType::Void, QMetaType::Int,   94,
    QMetaType::Void, QMetaType::Int,   94,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void ZegoMixStreamAudienceDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ZegoMixStreamAudienceDialog *_t = static_cast<ZegoMixStreamAudienceDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigSaveVideoSettings((*reinterpret_cast< SettingsPtr(*)>(_a[1]))); break;
        case 1: _t->sigShowSnapShotImage((*reinterpret_cast< QImage*(*)>(_a[1]))); break;
        case 2: _t->OnLoginRoom((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< QVector<StreamPtr>(*)>(_a[3]))); break;
        case 3: _t->OnStreamUpdated((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QVector<StreamPtr>(*)>(_a[2])),(*reinterpret_cast< LIVEROOM::ZegoStreamUpdateType(*)>(_a[3]))); break;
        case 4: _t->OnPublishStateUpdate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< StreamPtr(*)>(_a[3]))); break;
        case 5: _t->OnPlayStateUpdate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 6: _t->OnUserUpdate((*reinterpret_cast< QVector<QString>(*)>(_a[1])),(*reinterpret_cast< QVector<QString>(*)>(_a[2])),(*reinterpret_cast< QVector<int>(*)>(_a[3])),(*reinterpret_cast< QVector<int>(*)>(_a[4])),(*reinterpret_cast< uint(*)>(_a[5])),(*reinterpret_cast< LIVEROOM::ZegoUserUpdateType(*)>(_a[6]))); break;
        case 7: _t->OnDisconnect((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 8: _t->OnKickOut((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 9: _t->OnPlayQualityUpdate((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 10: _t->OnPublishQualityUpdate((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 11: _t->OnAVAuxInput((*reinterpret_cast< unsigned char*(*)>(_a[1])),(*reinterpret_cast< int*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int*(*)>(_a[4])),(*reinterpret_cast< int*(*)>(_a[5]))); break;
        case 12: _t->OnSendRoomMessage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< unsigned long long(*)>(_a[4]))); break;
        case 13: _t->OnRecvRoomMessage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QVector<RoomMsgPtr>(*)>(_a[2]))); break;
        case 14: _t->OnJoinLiveResponse((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 15: _t->OnAudioDeviceChanged((*reinterpret_cast< AV::AudioDeviceType(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< AV::DeviceState(*)>(_a[4]))); break;
        case 16: _t->OnVideoDeviceChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< AV::DeviceState(*)>(_a[3]))); break;
        case 17: _t->OnMixStream((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 18: _t->OnRecvEndJoinLiveCommand((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 19: _t->OnPreviewSnapshot((*reinterpret_cast< void*(*)>(_a[1]))); break;
        case 20: _t->OnSnapshot((*reinterpret_cast< void*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 21: _t->OnClickTitleButton(); break;
        case 22: _t->OnClose(); break;
        case 23: _t->OnButtonJoinLive(); break;
        case 24: _t->OnButtonSendMessage(); break;
        case 25: _t->OnButtonSoundCapture(); break;
        case 26: _t->OnButtonMircoPhone(); break;
        case 27: _t->OnButtonSound(); break;
        case 28: _t->OnProgChange(); break;
        case 29: _t->OnShareLink(); break;
        case 30: _t->OnButtonAux(); break;
        case 31: _t->OnSnapshotPreview(); break;
        case 32: _t->OnSnapshotWithStreamID((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 33: _t->OnUseDefaultAux((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 34: _t->OnGetMusicAppPath((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 35: _t->OnSwitchAudioDevice((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 36: _t->OnSwitchVideoDevice((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 37: _t->OnButtonShowFullScreen(); break;
        case 38: _t->OnShowSnapShotImage((*reinterpret_cast< QImage*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
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
        {
            typedef void (ZegoMixStreamAudienceDialog::*_t)(QImage * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ZegoMixStreamAudienceDialog::sigShowSnapShotImage)) {
                *result = 1;
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
        if (_id < 39)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 39;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 39)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 39;
    }
    return _id;
}

// SIGNAL 0
void ZegoMixStreamAudienceDialog::sigSaveVideoSettings(SettingsPtr _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ZegoMixStreamAudienceDialog::sigShowSnapShotImage(QImage * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE

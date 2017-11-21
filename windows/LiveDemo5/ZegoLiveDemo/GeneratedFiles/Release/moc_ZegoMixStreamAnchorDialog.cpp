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
    QByteArrayData data[94];
    char stringdata0[1279];
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
QT_MOC_LITERAL(5, 69, 20), // "sigShowSnapShotImage"
QT_MOC_LITERAL(6, 90, 7), // "QImage*"
QT_MOC_LITERAL(7, 98, 9), // "imageData"
QT_MOC_LITERAL(8, 108, 11), // "OnLoginRoom"
QT_MOC_LITERAL(9, 120, 9), // "errorCode"
QT_MOC_LITERAL(10, 130, 6), // "roomId"
QT_MOC_LITERAL(11, 137, 18), // "QVector<StreamPtr>"
QT_MOC_LITERAL(12, 156, 11), // "vStreamList"
QT_MOC_LITERAL(13, 168, 15), // "OnStreamUpdated"
QT_MOC_LITERAL(14, 184, 30), // "LIVEROOM::ZegoStreamUpdateType"
QT_MOC_LITERAL(15, 215, 4), // "type"
QT_MOC_LITERAL(16, 220, 20), // "OnPublishStateUpdate"
QT_MOC_LITERAL(17, 241, 9), // "stateCode"
QT_MOC_LITERAL(18, 251, 8), // "streamId"
QT_MOC_LITERAL(19, 260, 9), // "StreamPtr"
QT_MOC_LITERAL(20, 270, 10), // "streamInfo"
QT_MOC_LITERAL(21, 281, 17), // "OnPlayStateUpdate"
QT_MOC_LITERAL(22, 299, 12), // "OnUserUpdate"
QT_MOC_LITERAL(23, 312, 16), // "QVector<QString>"
QT_MOC_LITERAL(24, 329, 7), // "userIDs"
QT_MOC_LITERAL(25, 337, 9), // "userNames"
QT_MOC_LITERAL(26, 347, 12), // "QVector<int>"
QT_MOC_LITERAL(27, 360, 9), // "userFlags"
QT_MOC_LITERAL(28, 370, 9), // "userRoles"
QT_MOC_LITERAL(29, 380, 9), // "userCount"
QT_MOC_LITERAL(30, 390, 28), // "LIVEROOM::ZegoUserUpdateType"
QT_MOC_LITERAL(31, 419, 12), // "OnDisconnect"
QT_MOC_LITERAL(32, 432, 9), // "OnKickOut"
QT_MOC_LITERAL(33, 442, 6), // "reason"
QT_MOC_LITERAL(34, 449, 19), // "OnPlayQualityUpdate"
QT_MOC_LITERAL(35, 469, 7), // "quality"
QT_MOC_LITERAL(36, 477, 8), // "videoFPS"
QT_MOC_LITERAL(37, 486, 8), // "videoKBS"
QT_MOC_LITERAL(38, 495, 22), // "OnPublishQualityUpdate"
QT_MOC_LITERAL(39, 518, 12), // "OnAVAuxInput"
QT_MOC_LITERAL(40, 531, 14), // "unsigned char*"
QT_MOC_LITERAL(41, 546, 5), // "pData"
QT_MOC_LITERAL(42, 552, 4), // "int*"
QT_MOC_LITERAL(43, 557, 8), // "pDataLen"
QT_MOC_LITERAL(44, 566, 13), // "pDataLenValue"
QT_MOC_LITERAL(45, 580, 11), // "pSampleRate"
QT_MOC_LITERAL(46, 592, 12), // "pNumChannels"
QT_MOC_LITERAL(47, 605, 17), // "OnSendRoomMessage"
QT_MOC_LITERAL(48, 623, 6), // "roomID"
QT_MOC_LITERAL(49, 630, 7), // "sendSeq"
QT_MOC_LITERAL(50, 638, 9), // "messageId"
QT_MOC_LITERAL(51, 648, 17), // "OnRecvRoomMessage"
QT_MOC_LITERAL(52, 666, 19), // "QVector<RoomMsgPtr>"
QT_MOC_LITERAL(53, 686, 12), // "vRoomMsgList"
QT_MOC_LITERAL(54, 699, 17), // "OnJoinLiveRequest"
QT_MOC_LITERAL(55, 717, 3), // "seq"
QT_MOC_LITERAL(56, 721, 10), // "fromUserId"
QT_MOC_LITERAL(57, 732, 12), // "fromUserName"
QT_MOC_LITERAL(58, 745, 20), // "OnAudioDeviceChanged"
QT_MOC_LITERAL(59, 766, 19), // "AV::AudioDeviceType"
QT_MOC_LITERAL(60, 786, 10), // "deviceType"
QT_MOC_LITERAL(61, 797, 11), // "strDeviceId"
QT_MOC_LITERAL(62, 809, 13), // "strDeviceName"
QT_MOC_LITERAL(63, 823, 15), // "AV::DeviceState"
QT_MOC_LITERAL(64, 839, 5), // "state"
QT_MOC_LITERAL(65, 845, 20), // "OnVideoDeviceChanged"
QT_MOC_LITERAL(66, 866, 11), // "OnMixStream"
QT_MOC_LITERAL(67, 878, 6), // "hlsUrl"
QT_MOC_LITERAL(68, 885, 7), // "rtmpUrl"
QT_MOC_LITERAL(69, 893, 11), // "mixStreamID"
QT_MOC_LITERAL(70, 905, 17), // "OnPreviewSnapshot"
QT_MOC_LITERAL(71, 923, 6), // "pImage"
QT_MOC_LITERAL(72, 930, 10), // "OnSnapshot"
QT_MOC_LITERAL(73, 941, 8), // "streamID"
QT_MOC_LITERAL(74, 950, 18), // "OnClickTitleButton"
QT_MOC_LITERAL(75, 969, 7), // "OnClose"
QT_MOC_LITERAL(76, 977, 21), // "OnButtonSwitchPublish"
QT_MOC_LITERAL(77, 999, 19), // "OnButtonSendMessage"
QT_MOC_LITERAL(78, 1019, 20), // "OnButtonSoundCapture"
QT_MOC_LITERAL(79, 1040, 18), // "OnButtonMircoPhone"
QT_MOC_LITERAL(80, 1059, 13), // "OnButtonSound"
QT_MOC_LITERAL(81, 1073, 12), // "OnProgChange"
QT_MOC_LITERAL(82, 1086, 11), // "OnShareLink"
QT_MOC_LITERAL(83, 1098, 11), // "OnButtonAux"
QT_MOC_LITERAL(84, 1110, 17), // "OnSnapshotPreview"
QT_MOC_LITERAL(85, 1128, 22), // "OnSnapshotWithStreamID"
QT_MOC_LITERAL(86, 1151, 15), // "OnUseDefaultAux"
QT_MOC_LITERAL(87, 1167, 17), // "OnGetMusicAppPath"
QT_MOC_LITERAL(88, 1185, 7), // "exePath"
QT_MOC_LITERAL(89, 1193, 19), // "OnSwitchAudioDevice"
QT_MOC_LITERAL(90, 1213, 2), // "id"
QT_MOC_LITERAL(91, 1216, 19), // "OnSwitchVideoDevice"
QT_MOC_LITERAL(92, 1236, 22), // "OnButtonShowFullScreen"
QT_MOC_LITERAL(93, 1259, 19) // "OnShowSnapShotImage"

    },
    "ZegoMixStreamAnchorDialog\0"
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
    "OnJoinLiveRequest\0seq\0fromUserId\0"
    "fromUserName\0OnAudioDeviceChanged\0"
    "AV::AudioDeviceType\0deviceType\0"
    "strDeviceId\0strDeviceName\0AV::DeviceState\0"
    "state\0OnVideoDeviceChanged\0OnMixStream\0"
    "hlsUrl\0rtmpUrl\0mixStreamID\0OnPreviewSnapshot\0"
    "pImage\0OnSnapshot\0streamID\0"
    "OnClickTitleButton\0OnClose\0"
    "OnButtonSwitchPublish\0OnButtonSendMessage\0"
    "OnButtonSoundCapture\0OnButtonMircoPhone\0"
    "OnButtonSound\0OnProgChange\0OnShareLink\0"
    "OnButtonAux\0OnSnapshotPreview\0"
    "OnSnapshotWithStreamID\0OnUseDefaultAux\0"
    "OnGetMusicAppPath\0exePath\0OnSwitchAudioDevice\0"
    "id\0OnSwitchVideoDevice\0OnButtonShowFullScreen\0"
    "OnShowSnapShotImage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ZegoMixStreamAnchorDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      38,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  204,    2, 0x06 /* Public */,
       5,    1,  207,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    3,  210,    2, 0x09 /* Protected */,
      13,    3,  217,    2, 0x09 /* Protected */,
      16,    3,  224,    2, 0x09 /* Protected */,
      21,    2,  231,    2, 0x09 /* Protected */,
      22,    6,  236,    2, 0x09 /* Protected */,
      31,    2,  249,    2, 0x09 /* Protected */,
      32,    2,  254,    2, 0x09 /* Protected */,
      34,    4,  259,    2, 0x09 /* Protected */,
      38,    4,  268,    2, 0x09 /* Protected */,
      39,    5,  277,    2, 0x09 /* Protected */,
      47,    4,  288,    2, 0x09 /* Protected */,
      51,    2,  297,    2, 0x09 /* Protected */,
      54,    4,  302,    2, 0x09 /* Protected */,
      58,    4,  311,    2, 0x09 /* Protected */,
      65,    3,  320,    2, 0x09 /* Protected */,
      66,    5,  327,    2, 0x09 /* Protected */,
      70,    1,  338,    2, 0x09 /* Protected */,
      72,    2,  341,    2, 0x09 /* Protected */,
      74,    0,  346,    2, 0x08 /* Private */,
      75,    0,  347,    2, 0x08 /* Private */,
      76,    0,  348,    2, 0x08 /* Private */,
      77,    0,  349,    2, 0x08 /* Private */,
      78,    0,  350,    2, 0x08 /* Private */,
      79,    0,  351,    2, 0x08 /* Private */,
      80,    0,  352,    2, 0x08 /* Private */,
      81,    0,  353,    2, 0x08 /* Private */,
      82,    0,  354,    2, 0x08 /* Private */,
      83,    0,  355,    2, 0x08 /* Private */,
      84,    0,  356,    2, 0x08 /* Private */,
      85,    1,  357,    2, 0x08 /* Private */,
      86,    1,  360,    2, 0x08 /* Private */,
      87,    1,  363,    2, 0x08 /* Private */,
      89,    1,  366,    2, 0x08 /* Private */,
      91,    1,  369,    2, 0x08 /* Private */,
      92,    0,  372,    2, 0x08 /* Private */,
      93,    1,  373,    2, 0x08 /* Private */,

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
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,   55,   56,   57,   10,
    QMetaType::Void, 0x80000000 | 59, QMetaType::QString, QMetaType::QString, 0x80000000 | 63,   60,   61,   62,   64,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 63,   61,   62,   64,
    QMetaType::Void, QMetaType::UInt, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int,    9,   67,   68,   69,   55,
    QMetaType::Void, QMetaType::VoidStar,   71,
    QMetaType::Void, QMetaType::VoidStar, QMetaType::QString,   71,   73,
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
    QMetaType::Void, QMetaType::QString,   73,
    QMetaType::Void, QMetaType::Bool,   64,
    QMetaType::Void, QMetaType::QString,   88,
    QMetaType::Void, QMetaType::Int,   90,
    QMetaType::Void, QMetaType::Int,   90,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void ZegoMixStreamAnchorDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ZegoMixStreamAnchorDialog *_t = static_cast<ZegoMixStreamAnchorDialog *>(_o);
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
        case 14: _t->OnJoinLiveRequest((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 15: _t->OnAudioDeviceChanged((*reinterpret_cast< AV::AudioDeviceType(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< AV::DeviceState(*)>(_a[4]))); break;
        case 16: _t->OnVideoDeviceChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< AV::DeviceState(*)>(_a[3]))); break;
        case 17: _t->OnMixStream((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 18: _t->OnPreviewSnapshot((*reinterpret_cast< void*(*)>(_a[1]))); break;
        case 19: _t->OnSnapshot((*reinterpret_cast< void*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 20: _t->OnClickTitleButton(); break;
        case 21: _t->OnClose(); break;
        case 22: _t->OnButtonSwitchPublish(); break;
        case 23: _t->OnButtonSendMessage(); break;
        case 24: _t->OnButtonSoundCapture(); break;
        case 25: _t->OnButtonMircoPhone(); break;
        case 26: _t->OnButtonSound(); break;
        case 27: _t->OnProgChange(); break;
        case 28: _t->OnShareLink(); break;
        case 29: _t->OnButtonAux(); break;
        case 30: _t->OnSnapshotPreview(); break;
        case 31: _t->OnSnapshotWithStreamID((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 32: _t->OnUseDefaultAux((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 33: _t->OnGetMusicAppPath((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 34: _t->OnSwitchAudioDevice((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 35: _t->OnSwitchVideoDevice((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 36: _t->OnButtonShowFullScreen(); break;
        case 37: _t->OnShowSnapShotImage((*reinterpret_cast< QImage*(*)>(_a[1]))); break;
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
            typedef void (ZegoMixStreamAnchorDialog::*_t)(SettingsPtr );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ZegoMixStreamAnchorDialog::sigSaveVideoSettings)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ZegoMixStreamAnchorDialog::*_t)(QImage * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ZegoMixStreamAnchorDialog::sigShowSnapShotImage)) {
                *result = 1;
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
        if (_id < 38)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 38;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 38)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 38;
    }
    return _id;
}

// SIGNAL 0
void ZegoMixStreamAnchorDialog::sigSaveVideoSettings(SettingsPtr _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ZegoMixStreamAnchorDialog::sigShowSnapShotImage(QImage * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE

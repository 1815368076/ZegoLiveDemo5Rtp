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
    QByteArrayData data[93];
    char stringdata0[1284];
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
QT_MOC_LITERAL(5, 64, 20), // "sigShowSnapShotImage"
QT_MOC_LITERAL(6, 85, 7), // "QImage*"
QT_MOC_LITERAL(7, 93, 9), // "imageData"
QT_MOC_LITERAL(8, 103, 11), // "OnLoginRoom"
QT_MOC_LITERAL(9, 115, 9), // "errorCode"
QT_MOC_LITERAL(10, 125, 6), // "roomId"
QT_MOC_LITERAL(11, 132, 18), // "QVector<StreamPtr>"
QT_MOC_LITERAL(12, 151, 11), // "vStreamList"
QT_MOC_LITERAL(13, 163, 15), // "OnStreamUpdated"
QT_MOC_LITERAL(14, 179, 30), // "LIVEROOM::ZegoStreamUpdateType"
QT_MOC_LITERAL(15, 210, 4), // "type"
QT_MOC_LITERAL(16, 215, 20), // "OnPublishStateUpdate"
QT_MOC_LITERAL(17, 236, 9), // "stateCode"
QT_MOC_LITERAL(18, 246, 8), // "streamId"
QT_MOC_LITERAL(19, 255, 9), // "StreamPtr"
QT_MOC_LITERAL(20, 265, 10), // "streamInfo"
QT_MOC_LITERAL(21, 276, 17), // "OnPlayStateUpdate"
QT_MOC_LITERAL(22, 294, 12), // "OnUserUpdate"
QT_MOC_LITERAL(23, 307, 16), // "QVector<QString>"
QT_MOC_LITERAL(24, 324, 7), // "userIDs"
QT_MOC_LITERAL(25, 332, 9), // "userNames"
QT_MOC_LITERAL(26, 342, 12), // "QVector<int>"
QT_MOC_LITERAL(27, 355, 9), // "userFlags"
QT_MOC_LITERAL(28, 365, 9), // "userRoles"
QT_MOC_LITERAL(29, 375, 9), // "userCount"
QT_MOC_LITERAL(30, 385, 28), // "LIVEROOM::ZegoUserUpdateType"
QT_MOC_LITERAL(31, 414, 12), // "OnDisconnect"
QT_MOC_LITERAL(32, 427, 9), // "OnKickOut"
QT_MOC_LITERAL(33, 437, 6), // "reason"
QT_MOC_LITERAL(34, 444, 19), // "OnPlayQualityUpdate"
QT_MOC_LITERAL(35, 464, 7), // "quality"
QT_MOC_LITERAL(36, 472, 8), // "videoFPS"
QT_MOC_LITERAL(37, 481, 8), // "videoKBS"
QT_MOC_LITERAL(38, 490, 22), // "OnPublishQualityUpdate"
QT_MOC_LITERAL(39, 513, 12), // "OnAVAuxInput"
QT_MOC_LITERAL(40, 526, 14), // "unsigned char*"
QT_MOC_LITERAL(41, 541, 5), // "pData"
QT_MOC_LITERAL(42, 547, 4), // "int*"
QT_MOC_LITERAL(43, 552, 8), // "pDataLen"
QT_MOC_LITERAL(44, 561, 13), // "pDataLenValue"
QT_MOC_LITERAL(45, 575, 11), // "pSampleRate"
QT_MOC_LITERAL(46, 587, 12), // "pNumChannels"
QT_MOC_LITERAL(47, 600, 17), // "OnSendRoomMessage"
QT_MOC_LITERAL(48, 618, 6), // "roomID"
QT_MOC_LITERAL(49, 625, 7), // "sendSeq"
QT_MOC_LITERAL(50, 633, 9), // "messageId"
QT_MOC_LITERAL(51, 643, 17), // "OnRecvRoomMessage"
QT_MOC_LITERAL(52, 661, 19), // "QVector<RoomMsgPtr>"
QT_MOC_LITERAL(53, 681, 12), // "vRoomMsgList"
QT_MOC_LITERAL(54, 694, 17), // "OnJoinLiveRequest"
QT_MOC_LITERAL(55, 712, 3), // "seq"
QT_MOC_LITERAL(56, 716, 10), // "fromUserId"
QT_MOC_LITERAL(57, 727, 12), // "fromUserName"
QT_MOC_LITERAL(58, 740, 20), // "OnAudioDeviceChanged"
QT_MOC_LITERAL(59, 761, 19), // "AV::AudioDeviceType"
QT_MOC_LITERAL(60, 781, 10), // "deviceType"
QT_MOC_LITERAL(61, 792, 11), // "strDeviceId"
QT_MOC_LITERAL(62, 804, 13), // "strDeviceName"
QT_MOC_LITERAL(63, 818, 15), // "AV::DeviceState"
QT_MOC_LITERAL(64, 834, 5), // "state"
QT_MOC_LITERAL(65, 840, 20), // "OnVideoDeviceChanged"
QT_MOC_LITERAL(66, 861, 20), // "OnSurfaceMergeResult"
QT_MOC_LITERAL(67, 882, 16), // "surfaceMergeData"
QT_MOC_LITERAL(68, 899, 10), // "datalength"
QT_MOC_LITERAL(69, 910, 17), // "OnPreviewSnapshot"
QT_MOC_LITERAL(70, 928, 6), // "pImage"
QT_MOC_LITERAL(71, 935, 10), // "OnSnapshot"
QT_MOC_LITERAL(72, 946, 8), // "streamID"
QT_MOC_LITERAL(73, 955, 18), // "OnClickTitleButton"
QT_MOC_LITERAL(74, 974, 7), // "OnClose"
QT_MOC_LITERAL(75, 982, 21), // "OnButtonSwitchPublish"
QT_MOC_LITERAL(76, 1004, 19), // "OnButtonSendMessage"
QT_MOC_LITERAL(77, 1024, 20), // "OnButtonSoundCapture"
QT_MOC_LITERAL(78, 1045, 18), // "OnButtonMircoPhone"
QT_MOC_LITERAL(79, 1064, 13), // "OnButtonSound"
QT_MOC_LITERAL(80, 1078, 12), // "OnProgChange"
QT_MOC_LITERAL(81, 1091, 11), // "OnShareLink"
QT_MOC_LITERAL(82, 1103, 11), // "OnButtonAux"
QT_MOC_LITERAL(83, 1115, 17), // "OnSnapshotPreview"
QT_MOC_LITERAL(84, 1133, 22), // "OnSnapshotWithStreamID"
QT_MOC_LITERAL(85, 1156, 15), // "OnUseDefaultAux"
QT_MOC_LITERAL(86, 1172, 17), // "OnGetMusicAppPath"
QT_MOC_LITERAL(87, 1190, 7), // "exePath"
QT_MOC_LITERAL(88, 1198, 19), // "OnSwitchAudioDevice"
QT_MOC_LITERAL(89, 1218, 2), // "id"
QT_MOC_LITERAL(90, 1221, 19), // "OnSwitchVideoDevice"
QT_MOC_LITERAL(91, 1241, 22), // "OnButtonShowFullScreen"
QT_MOC_LITERAL(92, 1264, 19) // "OnShowSnapShotImage"

    },
    "ZegoMoreAnchorDialog\0sigSaveVideoSettings\0"
    "\0SettingsPtr\0settings\0sigShowSnapShotImage\0"
    "QImage*\0imageData\0OnLoginRoom\0errorCode\0"
    "roomId\0QVector<StreamPtr>\0vStreamList\0"
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
    "state\0OnVideoDeviceChanged\0"
    "OnSurfaceMergeResult\0surfaceMergeData\0"
    "datalength\0OnPreviewSnapshot\0pImage\0"
    "OnSnapshot\0streamID\0OnClickTitleButton\0"
    "OnClose\0OnButtonSwitchPublish\0"
    "OnButtonSendMessage\0OnButtonSoundCapture\0"
    "OnButtonMircoPhone\0OnButtonSound\0"
    "OnProgChange\0OnShareLink\0OnButtonAux\0"
    "OnSnapshotPreview\0OnSnapshotWithStreamID\0"
    "OnUseDefaultAux\0OnGetMusicAppPath\0"
    "exePath\0OnSwitchAudioDevice\0id\0"
    "OnSwitchVideoDevice\0OnButtonShowFullScreen\0"
    "OnShowSnapShotImage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ZegoMoreAnchorDialog[] = {

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
      66,    2,  327,    2, 0x09 /* Protected */,
      69,    1,  332,    2, 0x09 /* Protected */,
      71,    2,  335,    2, 0x09 /* Protected */,
      73,    0,  340,    2, 0x08 /* Private */,
      74,    0,  341,    2, 0x08 /* Private */,
      75,    0,  342,    2, 0x08 /* Private */,
      76,    0,  343,    2, 0x08 /* Private */,
      77,    0,  344,    2, 0x08 /* Private */,
      78,    0,  345,    2, 0x08 /* Private */,
      79,    0,  346,    2, 0x08 /* Private */,
      80,    0,  347,    2, 0x08 /* Private */,
      81,    0,  348,    2, 0x08 /* Private */,
      82,    0,  349,    2, 0x08 /* Private */,
      83,    0,  350,    2, 0x08 /* Private */,
      84,    1,  351,    2, 0x08 /* Private */,
      85,    1,  354,    2, 0x08 /* Private */,
      86,    1,  357,    2, 0x08 /* Private */,
      88,    1,  360,    2, 0x08 /* Private */,
      90,    1,  363,    2, 0x08 /* Private */,
      91,    0,  366,    2, 0x08 /* Private */,
      92,    1,  367,    2, 0x08 /* Private */,

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
    QMetaType::Void, 0x80000000 | 40, QMetaType::Int,   67,   68,
    QMetaType::Void, QMetaType::VoidStar,   70,
    QMetaType::Void, QMetaType::VoidStar, QMetaType::QString,   70,   72,
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
    QMetaType::Void, QMetaType::QString,   72,
    QMetaType::Void, QMetaType::Bool,   64,
    QMetaType::Void, QMetaType::QString,   87,
    QMetaType::Void, QMetaType::Int,   89,
    QMetaType::Void, QMetaType::Int,   89,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void ZegoMoreAnchorDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ZegoMoreAnchorDialog *_t = static_cast<ZegoMoreAnchorDialog *>(_o);
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
        case 17: _t->OnSurfaceMergeResult((*reinterpret_cast< unsigned char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
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
            typedef void (ZegoMoreAnchorDialog::*_t)(SettingsPtr );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ZegoMoreAnchorDialog::sigSaveVideoSettings)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ZegoMoreAnchorDialog::*_t)(QImage * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ZegoMoreAnchorDialog::sigShowSnapShotImage)) {
                *result = 1;
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
void ZegoMoreAnchorDialog::sigSaveVideoSettings(SettingsPtr _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ZegoMoreAnchorDialog::sigShowSnapShotImage(QImage * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE

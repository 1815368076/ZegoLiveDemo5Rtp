/****************************************************************************
** Meta object code from reading C++ file 'ZegoSingleAnchorDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Dialog/ZegoSingleAnchorDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ZegoSingleAnchorDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ZegoSingleAnchorDialog_t {
    QByteArrayData data[85];
    char stringdata0[1163];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ZegoSingleAnchorDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ZegoSingleAnchorDialog_t qt_meta_stringdata_ZegoSingleAnchorDialog = {
    {
QT_MOC_LITERAL(0, 0, 22), // "ZegoSingleAnchorDialog"
QT_MOC_LITERAL(1, 23, 20), // "sigSaveVideoSettings"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 11), // "SettingsPtr"
QT_MOC_LITERAL(4, 57, 8), // "settings"
QT_MOC_LITERAL(5, 66, 20), // "sigShowSnapShotImage"
QT_MOC_LITERAL(6, 87, 7), // "QImage*"
QT_MOC_LITERAL(7, 95, 9), // "imageData"
QT_MOC_LITERAL(8, 105, 11), // "OnLoginRoom"
QT_MOC_LITERAL(9, 117, 9), // "errorCode"
QT_MOC_LITERAL(10, 127, 6), // "roomId"
QT_MOC_LITERAL(11, 134, 18), // "QVector<StreamPtr>"
QT_MOC_LITERAL(12, 153, 11), // "vStreamList"
QT_MOC_LITERAL(13, 165, 20), // "OnPublishStateUpdate"
QT_MOC_LITERAL(14, 186, 9), // "stateCode"
QT_MOC_LITERAL(15, 196, 8), // "streamId"
QT_MOC_LITERAL(16, 205, 9), // "StreamPtr"
QT_MOC_LITERAL(17, 215, 10), // "streamInfo"
QT_MOC_LITERAL(18, 226, 12), // "OnUserUpdate"
QT_MOC_LITERAL(19, 239, 16), // "QVector<QString>"
QT_MOC_LITERAL(20, 256, 7), // "userIDs"
QT_MOC_LITERAL(21, 264, 9), // "userNames"
QT_MOC_LITERAL(22, 274, 12), // "QVector<int>"
QT_MOC_LITERAL(23, 287, 9), // "userFlags"
QT_MOC_LITERAL(24, 297, 9), // "userRoles"
QT_MOC_LITERAL(25, 307, 9), // "userCount"
QT_MOC_LITERAL(26, 317, 28), // "LIVEROOM::ZegoUserUpdateType"
QT_MOC_LITERAL(27, 346, 4), // "type"
QT_MOC_LITERAL(28, 351, 12), // "OnDisconnect"
QT_MOC_LITERAL(29, 364, 9), // "OnKickOut"
QT_MOC_LITERAL(30, 374, 6), // "reason"
QT_MOC_LITERAL(31, 381, 22), // "OnPublishQualityUpdate"
QT_MOC_LITERAL(32, 404, 7), // "quality"
QT_MOC_LITERAL(33, 412, 8), // "videoFPS"
QT_MOC_LITERAL(34, 421, 8), // "videoKBS"
QT_MOC_LITERAL(35, 430, 12), // "OnAVAuxInput"
QT_MOC_LITERAL(36, 443, 14), // "unsigned char*"
QT_MOC_LITERAL(37, 458, 5), // "pData"
QT_MOC_LITERAL(38, 464, 4), // "int*"
QT_MOC_LITERAL(39, 469, 8), // "pDataLen"
QT_MOC_LITERAL(40, 478, 13), // "pDataLenValue"
QT_MOC_LITERAL(41, 492, 11), // "pSampleRate"
QT_MOC_LITERAL(42, 504, 12), // "pNumChannels"
QT_MOC_LITERAL(43, 517, 17), // "OnSendRoomMessage"
QT_MOC_LITERAL(44, 535, 6), // "roomID"
QT_MOC_LITERAL(45, 542, 7), // "sendSeq"
QT_MOC_LITERAL(46, 550, 9), // "messageId"
QT_MOC_LITERAL(47, 560, 17), // "OnRecvRoomMessage"
QT_MOC_LITERAL(48, 578, 19), // "QVector<RoomMsgPtr>"
QT_MOC_LITERAL(49, 598, 12), // "vRoomMsgList"
QT_MOC_LITERAL(50, 611, 20), // "OnAudioDeviceChanged"
QT_MOC_LITERAL(51, 632, 19), // "AV::AudioDeviceType"
QT_MOC_LITERAL(52, 652, 10), // "deviceType"
QT_MOC_LITERAL(53, 663, 11), // "strDeviceId"
QT_MOC_LITERAL(54, 675, 13), // "strDeviceName"
QT_MOC_LITERAL(55, 689, 15), // "AV::DeviceState"
QT_MOC_LITERAL(56, 705, 5), // "state"
QT_MOC_LITERAL(57, 711, 20), // "OnVideoDeviceChanged"
QT_MOC_LITERAL(58, 732, 20), // "OnSurfaceMergeResult"
QT_MOC_LITERAL(59, 753, 16), // "surfaceMergeData"
QT_MOC_LITERAL(60, 770, 10), // "datalength"
QT_MOC_LITERAL(61, 781, 17), // "OnPreviewSnapshot"
QT_MOC_LITERAL(62, 799, 6), // "pImage"
QT_MOC_LITERAL(63, 806, 18), // "OnClickTitleButton"
QT_MOC_LITERAL(64, 825, 7), // "OnClose"
QT_MOC_LITERAL(65, 833, 21), // "OnButtonSwitchPublish"
QT_MOC_LITERAL(66, 855, 19), // "OnButtonSendMessage"
QT_MOC_LITERAL(67, 875, 20), // "OnButtonSoundCapture"
QT_MOC_LITERAL(68, 896, 18), // "OnButtonMircoPhone"
QT_MOC_LITERAL(69, 915, 13), // "OnButtonSound"
QT_MOC_LITERAL(70, 929, 12), // "OnProgChange"
QT_MOC_LITERAL(71, 942, 11), // "OnShareLink"
QT_MOC_LITERAL(72, 954, 11), // "OnButtonAux"
QT_MOC_LITERAL(73, 966, 17), // "OnSnapshotPreview"
QT_MOC_LITERAL(74, 984, 15), // "OnUseDefaultAux"
QT_MOC_LITERAL(75, 1000, 17), // "OnGetMusicAppPath"
QT_MOC_LITERAL(76, 1018, 7), // "exePath"
QT_MOC_LITERAL(77, 1026, 19), // "OnSwitchAudioDevice"
QT_MOC_LITERAL(78, 1046, 2), // "id"
QT_MOC_LITERAL(79, 1049, 19), // "OnSwitchVideoDevice"
QT_MOC_LITERAL(80, 1069, 20), // "OnSwitchVideoDevice2"
QT_MOC_LITERAL(81, 1090, 22), // "OnButtonShowFullScreen"
QT_MOC_LITERAL(82, 1113, 19), // "OnShowSnapShotImage"
QT_MOC_LITERAL(83, 1133, 20), // "getCameraIndexFromID"
QT_MOC_LITERAL(84, 1154, 8) // "cameraID"

    },
    "ZegoSingleAnchorDialog\0sigSaveVideoSettings\0"
    "\0SettingsPtr\0settings\0sigShowSnapShotImage\0"
    "QImage*\0imageData\0OnLoginRoom\0errorCode\0"
    "roomId\0QVector<StreamPtr>\0vStreamList\0"
    "OnPublishStateUpdate\0stateCode\0streamId\0"
    "StreamPtr\0streamInfo\0OnUserUpdate\0"
    "QVector<QString>\0userIDs\0userNames\0"
    "QVector<int>\0userFlags\0userRoles\0"
    "userCount\0LIVEROOM::ZegoUserUpdateType\0"
    "type\0OnDisconnect\0OnKickOut\0reason\0"
    "OnPublishQualityUpdate\0quality\0videoFPS\0"
    "videoKBS\0OnAVAuxInput\0unsigned char*\0"
    "pData\0int*\0pDataLen\0pDataLenValue\0"
    "pSampleRate\0pNumChannels\0OnSendRoomMessage\0"
    "roomID\0sendSeq\0messageId\0OnRecvRoomMessage\0"
    "QVector<RoomMsgPtr>\0vRoomMsgList\0"
    "OnAudioDeviceChanged\0AV::AudioDeviceType\0"
    "deviceType\0strDeviceId\0strDeviceName\0"
    "AV::DeviceState\0state\0OnVideoDeviceChanged\0"
    "OnSurfaceMergeResult\0surfaceMergeData\0"
    "datalength\0OnPreviewSnapshot\0pImage\0"
    "OnClickTitleButton\0OnClose\0"
    "OnButtonSwitchPublish\0OnButtonSendMessage\0"
    "OnButtonSoundCapture\0OnButtonMircoPhone\0"
    "OnButtonSound\0OnProgChange\0OnShareLink\0"
    "OnButtonAux\0OnSnapshotPreview\0"
    "OnUseDefaultAux\0OnGetMusicAppPath\0"
    "exePath\0OnSwitchAudioDevice\0id\0"
    "OnSwitchVideoDevice\0OnSwitchVideoDevice2\0"
    "OnButtonShowFullScreen\0OnShowSnapShotImage\0"
    "getCameraIndexFromID\0cameraID"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ZegoSingleAnchorDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      34,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  184,    2, 0x06 /* Public */,
       5,    1,  187,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    3,  190,    2, 0x09 /* Protected */,
      13,    3,  197,    2, 0x09 /* Protected */,
      18,    6,  204,    2, 0x09 /* Protected */,
      28,    2,  217,    2, 0x09 /* Protected */,
      29,    2,  222,    2, 0x09 /* Protected */,
      31,    4,  227,    2, 0x09 /* Protected */,
      35,    5,  236,    2, 0x09 /* Protected */,
      43,    4,  247,    2, 0x09 /* Protected */,
      47,    2,  256,    2, 0x09 /* Protected */,
      50,    4,  261,    2, 0x09 /* Protected */,
      57,    3,  270,    2, 0x09 /* Protected */,
      58,    2,  277,    2, 0x09 /* Protected */,
      61,    1,  282,    2, 0x09 /* Protected */,
      63,    0,  285,    2, 0x08 /* Private */,
      64,    0,  286,    2, 0x08 /* Private */,
      65,    0,  287,    2, 0x08 /* Private */,
      66,    0,  288,    2, 0x08 /* Private */,
      67,    0,  289,    2, 0x08 /* Private */,
      68,    0,  290,    2, 0x08 /* Private */,
      69,    0,  291,    2, 0x08 /* Private */,
      70,    0,  292,    2, 0x08 /* Private */,
      71,    0,  293,    2, 0x08 /* Private */,
      72,    0,  294,    2, 0x08 /* Private */,
      73,    0,  295,    2, 0x08 /* Private */,
      74,    1,  296,    2, 0x08 /* Private */,
      75,    1,  299,    2, 0x08 /* Private */,
      77,    1,  302,    2, 0x08 /* Private */,
      79,    1,  305,    2, 0x08 /* Private */,
      80,    1,  308,    2, 0x08 /* Private */,
      81,    0,  311,    2, 0x08 /* Private */,
      82,    1,  312,    2, 0x08 /* Private */,
      83,    1,  315,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, 0x80000000 | 11,    9,   10,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, 0x80000000 | 16,   14,   15,   17,
    QMetaType::Void, 0x80000000 | 19, 0x80000000 | 19, 0x80000000 | 22, 0x80000000 | 22, QMetaType::UInt, 0x80000000 | 26,   20,   21,   23,   24,   25,   27,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    9,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   30,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Double, QMetaType::Double,   15,   32,   33,   34,
    QMetaType::Void, 0x80000000 | 36, 0x80000000 | 38, QMetaType::Int, 0x80000000 | 38, 0x80000000 | 38,   37,   39,   40,   41,   42,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::ULongLong,    9,   44,   45,   46,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 48,   10,   49,
    QMetaType::Void, 0x80000000 | 51, QMetaType::QString, QMetaType::QString, 0x80000000 | 55,   52,   53,   54,   56,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 55,   53,   54,   56,
    QMetaType::Void, 0x80000000 | 36, QMetaType::Int,   59,   60,
    QMetaType::Void, QMetaType::VoidStar,   62,
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
    QMetaType::Void, QMetaType::Bool,   56,
    QMetaType::Void, QMetaType::QString,   76,
    QMetaType::Void, QMetaType::Int,   78,
    QMetaType::Void, QMetaType::Int,   78,
    QMetaType::Void, QMetaType::Int,   78,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Int, QMetaType::QString,   84,

       0        // eod
};

void ZegoSingleAnchorDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ZegoSingleAnchorDialog *_t = static_cast<ZegoSingleAnchorDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigSaveVideoSettings((*reinterpret_cast< SettingsPtr(*)>(_a[1]))); break;
        case 1: _t->sigShowSnapShotImage((*reinterpret_cast< QImage*(*)>(_a[1]))); break;
        case 2: _t->OnLoginRoom((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< QVector<StreamPtr>(*)>(_a[3]))); break;
        case 3: _t->OnPublishStateUpdate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< StreamPtr(*)>(_a[3]))); break;
        case 4: _t->OnUserUpdate((*reinterpret_cast< QVector<QString>(*)>(_a[1])),(*reinterpret_cast< QVector<QString>(*)>(_a[2])),(*reinterpret_cast< QVector<int>(*)>(_a[3])),(*reinterpret_cast< QVector<int>(*)>(_a[4])),(*reinterpret_cast< uint(*)>(_a[5])),(*reinterpret_cast< LIVEROOM::ZegoUserUpdateType(*)>(_a[6]))); break;
        case 5: _t->OnDisconnect((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 6: _t->OnKickOut((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 7: _t->OnPublishQualityUpdate((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 8: _t->OnAVAuxInput((*reinterpret_cast< unsigned char*(*)>(_a[1])),(*reinterpret_cast< int*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int*(*)>(_a[4])),(*reinterpret_cast< int*(*)>(_a[5]))); break;
        case 9: _t->OnSendRoomMessage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< unsigned long long(*)>(_a[4]))); break;
        case 10: _t->OnRecvRoomMessage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QVector<RoomMsgPtr>(*)>(_a[2]))); break;
        case 11: _t->OnAudioDeviceChanged((*reinterpret_cast< AV::AudioDeviceType(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< AV::DeviceState(*)>(_a[4]))); break;
        case 12: _t->OnVideoDeviceChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< AV::DeviceState(*)>(_a[3]))); break;
        case 13: _t->OnSurfaceMergeResult((*reinterpret_cast< unsigned char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 14: _t->OnPreviewSnapshot((*reinterpret_cast< void*(*)>(_a[1]))); break;
        case 15: _t->OnClickTitleButton(); break;
        case 16: _t->OnClose(); break;
        case 17: _t->OnButtonSwitchPublish(); break;
        case 18: _t->OnButtonSendMessage(); break;
        case 19: _t->OnButtonSoundCapture(); break;
        case 20: _t->OnButtonMircoPhone(); break;
        case 21: _t->OnButtonSound(); break;
        case 22: _t->OnProgChange(); break;
        case 23: _t->OnShareLink(); break;
        case 24: _t->OnButtonAux(); break;
        case 25: _t->OnSnapshotPreview(); break;
        case 26: _t->OnUseDefaultAux((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 27: _t->OnGetMusicAppPath((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 28: _t->OnSwitchAudioDevice((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->OnSwitchVideoDevice((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->OnSwitchVideoDevice2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: _t->OnButtonShowFullScreen(); break;
        case 32: _t->OnShowSnapShotImage((*reinterpret_cast< QImage*(*)>(_a[1]))); break;
        case 33: { int _r = _t->getCameraIndexFromID((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
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
            typedef void (ZegoSingleAnchorDialog::*_t)(SettingsPtr );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ZegoSingleAnchorDialog::sigSaveVideoSettings)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ZegoSingleAnchorDialog::*_t)(QImage * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ZegoSingleAnchorDialog::sigShowSnapShotImage)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject ZegoSingleAnchorDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ZegoSingleAnchorDialog.data,
      qt_meta_data_ZegoSingleAnchorDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ZegoSingleAnchorDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZegoSingleAnchorDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ZegoSingleAnchorDialog.stringdata0))
        return static_cast<void*>(const_cast< ZegoSingleAnchorDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ZegoSingleAnchorDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 34)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 34;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 34)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 34;
    }
    return _id;
}

// SIGNAL 0
void ZegoSingleAnchorDialog::sigSaveVideoSettings(SettingsPtr _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ZegoSingleAnchorDialog::sigShowSnapShotImage(QImage * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE

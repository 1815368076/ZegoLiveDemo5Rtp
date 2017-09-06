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
    QByteArrayData data[68];
    char stringdata0[896];
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
QT_MOC_LITERAL(5, 66, 11), // "OnLoginRoom"
QT_MOC_LITERAL(6, 78, 9), // "errorCode"
QT_MOC_LITERAL(7, 88, 6), // "roomId"
QT_MOC_LITERAL(8, 95, 18), // "QVector<StreamPtr>"
QT_MOC_LITERAL(9, 114, 11), // "vStreamList"
QT_MOC_LITERAL(10, 126, 20), // "OnPublishStateUpdate"
QT_MOC_LITERAL(11, 147, 9), // "stateCode"
QT_MOC_LITERAL(12, 157, 8), // "streamId"
QT_MOC_LITERAL(13, 166, 9), // "StreamPtr"
QT_MOC_LITERAL(14, 176, 10), // "streamInfo"
QT_MOC_LITERAL(15, 187, 12), // "OnUserUpdate"
QT_MOC_LITERAL(16, 200, 16), // "QVector<QString>"
QT_MOC_LITERAL(17, 217, 7), // "userIDs"
QT_MOC_LITERAL(18, 225, 9), // "userNames"
QT_MOC_LITERAL(19, 235, 12), // "QVector<int>"
QT_MOC_LITERAL(20, 248, 9), // "userFlags"
QT_MOC_LITERAL(21, 258, 9), // "userRoles"
QT_MOC_LITERAL(22, 268, 9), // "userCount"
QT_MOC_LITERAL(23, 278, 28), // "LIVEROOM::ZegoUserUpdateType"
QT_MOC_LITERAL(24, 307, 4), // "type"
QT_MOC_LITERAL(25, 312, 12), // "OnDisconnect"
QT_MOC_LITERAL(26, 325, 9), // "OnKickOut"
QT_MOC_LITERAL(27, 335, 6), // "reason"
QT_MOC_LITERAL(28, 342, 22), // "OnPublishQualityUpdate"
QT_MOC_LITERAL(29, 365, 7), // "quality"
QT_MOC_LITERAL(30, 373, 8), // "videoFPS"
QT_MOC_LITERAL(31, 382, 8), // "videoKBS"
QT_MOC_LITERAL(32, 391, 12), // "OnAVAuxInput"
QT_MOC_LITERAL(33, 404, 14), // "unsigned char*"
QT_MOC_LITERAL(34, 419, 5), // "pData"
QT_MOC_LITERAL(35, 425, 4), // "int*"
QT_MOC_LITERAL(36, 430, 8), // "pDataLen"
QT_MOC_LITERAL(37, 439, 13), // "pDataLenValue"
QT_MOC_LITERAL(38, 453, 11), // "pSampleRate"
QT_MOC_LITERAL(39, 465, 12), // "pNumChannels"
QT_MOC_LITERAL(40, 478, 17), // "OnSendRoomMessage"
QT_MOC_LITERAL(41, 496, 6), // "roomID"
QT_MOC_LITERAL(42, 503, 7), // "sendSeq"
QT_MOC_LITERAL(43, 511, 9), // "messageId"
QT_MOC_LITERAL(44, 521, 17), // "OnRecvRoomMessage"
QT_MOC_LITERAL(45, 539, 19), // "QVector<RoomMsgPtr>"
QT_MOC_LITERAL(46, 559, 12), // "vRoomMsgList"
QT_MOC_LITERAL(47, 572, 20), // "OnAudioDeviceChanged"
QT_MOC_LITERAL(48, 593, 19), // "AV::AudioDeviceType"
QT_MOC_LITERAL(49, 613, 10), // "deviceType"
QT_MOC_LITERAL(50, 624, 11), // "strDeviceId"
QT_MOC_LITERAL(51, 636, 13), // "strDeviceName"
QT_MOC_LITERAL(52, 650, 15), // "AV::DeviceState"
QT_MOC_LITERAL(53, 666, 5), // "state"
QT_MOC_LITERAL(54, 672, 20), // "OnVideoDeviceChanged"
QT_MOC_LITERAL(55, 693, 18), // "OnClickTitleButton"
QT_MOC_LITERAL(56, 712, 7), // "OnClose"
QT_MOC_LITERAL(57, 720, 21), // "OnButtonSwitchPublish"
QT_MOC_LITERAL(58, 742, 19), // "OnButtonSendMessage"
QT_MOC_LITERAL(59, 762, 20), // "OnButtonSoundCapture"
QT_MOC_LITERAL(60, 783, 18), // "OnButtonMircoPhone"
QT_MOC_LITERAL(61, 802, 13), // "OnButtonSound"
QT_MOC_LITERAL(62, 816, 12), // "OnProgChange"
QT_MOC_LITERAL(63, 829, 11), // "OnShareLink"
QT_MOC_LITERAL(64, 841, 11), // "OnButtonAux"
QT_MOC_LITERAL(65, 853, 19), // "OnSwitchAudioDevice"
QT_MOC_LITERAL(66, 873, 2), // "id"
QT_MOC_LITERAL(67, 876, 19) // "OnSwitchVideoDevice"

    },
    "ZegoSingleAnchorDialog\0sigSaveVideoSettings\0"
    "\0SettingsPtr\0settings\0OnLoginRoom\0"
    "errorCode\0roomId\0QVector<StreamPtr>\0"
    "vStreamList\0OnPublishStateUpdate\0"
    "stateCode\0streamId\0StreamPtr\0streamInfo\0"
    "OnUserUpdate\0QVector<QString>\0userIDs\0"
    "userNames\0QVector<int>\0userFlags\0"
    "userRoles\0userCount\0LIVEROOM::ZegoUserUpdateType\0"
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
    "OnClickTitleButton\0OnClose\0"
    "OnButtonSwitchPublish\0OnButtonSendMessage\0"
    "OnButtonSoundCapture\0OnButtonMircoPhone\0"
    "OnButtonSound\0OnProgChange\0OnShareLink\0"
    "OnButtonAux\0OnSwitchAudioDevice\0id\0"
    "OnSwitchVideoDevice"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ZegoSingleAnchorDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  134,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    3,  137,    2, 0x09 /* Protected */,
      10,    3,  144,    2, 0x09 /* Protected */,
      15,    6,  151,    2, 0x09 /* Protected */,
      25,    2,  164,    2, 0x09 /* Protected */,
      26,    2,  169,    2, 0x09 /* Protected */,
      28,    4,  174,    2, 0x09 /* Protected */,
      32,    5,  183,    2, 0x09 /* Protected */,
      40,    4,  194,    2, 0x09 /* Protected */,
      44,    2,  203,    2, 0x09 /* Protected */,
      47,    4,  208,    2, 0x09 /* Protected */,
      54,    3,  217,    2, 0x09 /* Protected */,
      55,    0,  224,    2, 0x08 /* Private */,
      56,    0,  225,    2, 0x08 /* Private */,
      57,    0,  226,    2, 0x08 /* Private */,
      58,    0,  227,    2, 0x08 /* Private */,
      59,    0,  228,    2, 0x08 /* Private */,
      60,    0,  229,    2, 0x08 /* Private */,
      61,    0,  230,    2, 0x08 /* Private */,
      62,    0,  231,    2, 0x08 /* Private */,
      63,    0,  232,    2, 0x08 /* Private */,
      64,    0,  233,    2, 0x08 /* Private */,
      65,    1,  234,    2, 0x08 /* Private */,
      67,    1,  237,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, 0x80000000 | 8,    6,    7,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, 0x80000000 | 13,   11,   12,   14,
    QMetaType::Void, 0x80000000 | 16, 0x80000000 | 16, 0x80000000 | 19, 0x80000000 | 19, QMetaType::UInt, 0x80000000 | 23,   17,   18,   20,   21,   22,   24,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   27,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Double, QMetaType::Double,   12,   29,   30,   31,
    QMetaType::Void, 0x80000000 | 33, 0x80000000 | 35, QMetaType::Int, 0x80000000 | 35, 0x80000000 | 35,   34,   36,   37,   38,   39,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::ULongLong,    6,   41,   42,   43,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 45,    7,   46,
    QMetaType::Void, 0x80000000 | 48, QMetaType::QString, QMetaType::QString, 0x80000000 | 52,   49,   50,   51,   53,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 52,   50,   51,   53,
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
    QMetaType::Void, QMetaType::Int,   66,
    QMetaType::Void, QMetaType::Int,   66,

       0        // eod
};

void ZegoSingleAnchorDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ZegoSingleAnchorDialog *_t = static_cast<ZegoSingleAnchorDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigSaveVideoSettings((*reinterpret_cast< SettingsPtr(*)>(_a[1]))); break;
        case 1: _t->OnLoginRoom((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< QVector<StreamPtr>(*)>(_a[3]))); break;
        case 2: _t->OnPublishStateUpdate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< StreamPtr(*)>(_a[3]))); break;
        case 3: _t->OnUserUpdate((*reinterpret_cast< QVector<QString>(*)>(_a[1])),(*reinterpret_cast< QVector<QString>(*)>(_a[2])),(*reinterpret_cast< QVector<int>(*)>(_a[3])),(*reinterpret_cast< QVector<int>(*)>(_a[4])),(*reinterpret_cast< uint(*)>(_a[5])),(*reinterpret_cast< LIVEROOM::ZegoUserUpdateType(*)>(_a[6]))); break;
        case 4: _t->OnDisconnect((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 5: _t->OnKickOut((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 6: _t->OnPublishQualityUpdate((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 7: _t->OnAVAuxInput((*reinterpret_cast< unsigned char*(*)>(_a[1])),(*reinterpret_cast< int*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int*(*)>(_a[4])),(*reinterpret_cast< int*(*)>(_a[5]))); break;
        case 8: _t->OnSendRoomMessage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< unsigned long long(*)>(_a[4]))); break;
        case 9: _t->OnRecvRoomMessage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QVector<RoomMsgPtr>(*)>(_a[2]))); break;
        case 10: _t->OnAudioDeviceChanged((*reinterpret_cast< AV::AudioDeviceType(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< AV::DeviceState(*)>(_a[4]))); break;
        case 11: _t->OnVideoDeviceChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< AV::DeviceState(*)>(_a[3]))); break;
        case 12: _t->OnClickTitleButton(); break;
        case 13: _t->OnClose(); break;
        case 14: _t->OnButtonSwitchPublish(); break;
        case 15: _t->OnButtonSendMessage(); break;
        case 16: _t->OnButtonSoundCapture(); break;
        case 17: _t->OnButtonMircoPhone(); break;
        case 18: _t->OnButtonSound(); break;
        case 19: _t->OnProgChange(); break;
        case 20: _t->OnShareLink(); break;
        case 21: _t->OnButtonAux(); break;
        case 22: _t->OnSwitchAudioDevice((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->OnSwitchVideoDevice((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
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
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    }
    return _id;
}

// SIGNAL 0
void ZegoSingleAnchorDialog::sigSaveVideoSettings(SettingsPtr _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

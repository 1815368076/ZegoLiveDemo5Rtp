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
    QByteArrayData data[64];
    char stringdata0[876];
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
QT_MOC_LITERAL(5, 68, 20), // "sigShowSnapShotImage"
QT_MOC_LITERAL(6, 89, 7), // "QImage*"
QT_MOC_LITERAL(7, 97, 9), // "imageData"
QT_MOC_LITERAL(8, 107, 11), // "OnLoginRoom"
QT_MOC_LITERAL(9, 119, 9), // "errorCode"
QT_MOC_LITERAL(10, 129, 6), // "roomId"
QT_MOC_LITERAL(11, 136, 18), // "QVector<StreamPtr>"
QT_MOC_LITERAL(12, 155, 11), // "vStreamList"
QT_MOC_LITERAL(13, 167, 15), // "OnStreamUpdated"
QT_MOC_LITERAL(14, 183, 30), // "LIVEROOM::ZegoStreamUpdateType"
QT_MOC_LITERAL(15, 214, 4), // "type"
QT_MOC_LITERAL(16, 219, 17), // "OnPlayStateUpdate"
QT_MOC_LITERAL(17, 237, 9), // "stateCode"
QT_MOC_LITERAL(18, 247, 8), // "streamId"
QT_MOC_LITERAL(19, 256, 12), // "OnUserUpdate"
QT_MOC_LITERAL(20, 269, 16), // "QVector<QString>"
QT_MOC_LITERAL(21, 286, 7), // "userIDs"
QT_MOC_LITERAL(22, 294, 9), // "userNames"
QT_MOC_LITERAL(23, 304, 12), // "QVector<int>"
QT_MOC_LITERAL(24, 317, 9), // "userFlags"
QT_MOC_LITERAL(25, 327, 9), // "userRoles"
QT_MOC_LITERAL(26, 337, 9), // "userCount"
QT_MOC_LITERAL(27, 347, 28), // "LIVEROOM::ZegoUserUpdateType"
QT_MOC_LITERAL(28, 376, 12), // "OnDisconnect"
QT_MOC_LITERAL(29, 389, 9), // "OnKickOut"
QT_MOC_LITERAL(30, 399, 6), // "reason"
QT_MOC_LITERAL(31, 406, 19), // "OnPlayQualityUpdate"
QT_MOC_LITERAL(32, 426, 7), // "quality"
QT_MOC_LITERAL(33, 434, 8), // "videoFPS"
QT_MOC_LITERAL(34, 443, 8), // "videoKBS"
QT_MOC_LITERAL(35, 452, 17), // "OnSendRoomMessage"
QT_MOC_LITERAL(36, 470, 6), // "roomID"
QT_MOC_LITERAL(37, 477, 7), // "sendSeq"
QT_MOC_LITERAL(38, 485, 9), // "messageId"
QT_MOC_LITERAL(39, 495, 17), // "OnRecvRoomMessage"
QT_MOC_LITERAL(40, 513, 19), // "QVector<RoomMsgPtr>"
QT_MOC_LITERAL(41, 533, 12), // "vRoomMsgList"
QT_MOC_LITERAL(42, 546, 20), // "OnAudioDeviceChanged"
QT_MOC_LITERAL(43, 567, 19), // "AV::AudioDeviceType"
QT_MOC_LITERAL(44, 587, 10), // "deviceType"
QT_MOC_LITERAL(45, 598, 11), // "strDeviceId"
QT_MOC_LITERAL(46, 610, 13), // "strDeviceName"
QT_MOC_LITERAL(47, 624, 15), // "AV::DeviceState"
QT_MOC_LITERAL(48, 640, 5), // "state"
QT_MOC_LITERAL(49, 646, 20), // "OnVideoDeviceChanged"
QT_MOC_LITERAL(50, 667, 10), // "OnSnapshot"
QT_MOC_LITERAL(51, 678, 6), // "pImage"
QT_MOC_LITERAL(52, 685, 8), // "streamID"
QT_MOC_LITERAL(53, 694, 18), // "OnClickTitleButton"
QT_MOC_LITERAL(54, 713, 7), // "OnClose"
QT_MOC_LITERAL(55, 721, 19), // "OnButtonSendMessage"
QT_MOC_LITERAL(56, 741, 13), // "OnButtonSound"
QT_MOC_LITERAL(57, 755, 11), // "OnShareLink"
QT_MOC_LITERAL(58, 767, 19), // "OnSwitchAudioDevice"
QT_MOC_LITERAL(59, 787, 2), // "id"
QT_MOC_LITERAL(60, 790, 19), // "OnSwitchVideoDevice"
QT_MOC_LITERAL(61, 810, 22), // "OnButtonShowFullScreen"
QT_MOC_LITERAL(62, 833, 19), // "OnShowSnapShotImage"
QT_MOC_LITERAL(63, 853, 22) // "OnSnapshotWithStreamID"

    },
    "ZegoSingleAudienceDialog\0sigSaveVideoSettings\0"
    "\0SettingsPtr\0settings\0sigShowSnapShotImage\0"
    "QImage*\0imageData\0OnLoginRoom\0errorCode\0"
    "roomId\0QVector<StreamPtr>\0vStreamList\0"
    "OnStreamUpdated\0LIVEROOM::ZegoStreamUpdateType\0"
    "type\0OnPlayStateUpdate\0stateCode\0"
    "streamId\0OnUserUpdate\0QVector<QString>\0"
    "userIDs\0userNames\0QVector<int>\0userFlags\0"
    "userRoles\0userCount\0LIVEROOM::ZegoUserUpdateType\0"
    "OnDisconnect\0OnKickOut\0reason\0"
    "OnPlayQualityUpdate\0quality\0videoFPS\0"
    "videoKBS\0OnSendRoomMessage\0roomID\0"
    "sendSeq\0messageId\0OnRecvRoomMessage\0"
    "QVector<RoomMsgPtr>\0vRoomMsgList\0"
    "OnAudioDeviceChanged\0AV::AudioDeviceType\0"
    "deviceType\0strDeviceId\0strDeviceName\0"
    "AV::DeviceState\0state\0OnVideoDeviceChanged\0"
    "OnSnapshot\0pImage\0streamID\0"
    "OnClickTitleButton\0OnClose\0"
    "OnButtonSendMessage\0OnButtonSound\0"
    "OnShareLink\0OnSwitchAudioDevice\0id\0"
    "OnSwitchVideoDevice\0OnButtonShowFullScreen\0"
    "OnShowSnapShotImage\0OnSnapshotWithStreamID"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ZegoSingleAudienceDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  134,    2, 0x06 /* Public */,
       5,    1,  137,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    3,  140,    2, 0x09 /* Protected */,
      13,    3,  147,    2, 0x09 /* Protected */,
      16,    2,  154,    2, 0x09 /* Protected */,
      19,    6,  159,    2, 0x09 /* Protected */,
      28,    2,  172,    2, 0x09 /* Protected */,
      29,    2,  177,    2, 0x09 /* Protected */,
      31,    4,  182,    2, 0x09 /* Protected */,
      35,    4,  191,    2, 0x09 /* Protected */,
      39,    2,  200,    2, 0x09 /* Protected */,
      42,    4,  205,    2, 0x09 /* Protected */,
      49,    3,  214,    2, 0x09 /* Protected */,
      50,    2,  221,    2, 0x09 /* Protected */,
      53,    0,  226,    2, 0x08 /* Private */,
      54,    0,  227,    2, 0x08 /* Private */,
      55,    0,  228,    2, 0x08 /* Private */,
      56,    0,  229,    2, 0x08 /* Private */,
      57,    0,  230,    2, 0x08 /* Private */,
      58,    1,  231,    2, 0x08 /* Private */,
      60,    1,  234,    2, 0x08 /* Private */,
      61,    0,  237,    2, 0x08 /* Private */,
      62,    1,  238,    2, 0x08 /* Private */,
      63,    1,  241,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, 0x80000000 | 11,    9,   10,   12,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 11, 0x80000000 | 14,   10,   12,   15,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   17,   18,
    QMetaType::Void, 0x80000000 | 20, 0x80000000 | 20, 0x80000000 | 23, 0x80000000 | 23, QMetaType::UInt, 0x80000000 | 27,   21,   22,   24,   25,   26,   15,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    9,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   30,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Double, QMetaType::Double,   18,   32,   33,   34,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::ULongLong,    9,   36,   37,   38,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 40,   10,   41,
    QMetaType::Void, 0x80000000 | 43, QMetaType::QString, QMetaType::QString, 0x80000000 | 47,   44,   45,   46,   48,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 47,   45,   46,   48,
    QMetaType::Void, QMetaType::VoidStar, QMetaType::QString,   51,   52,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   59,
    QMetaType::Void, QMetaType::Int,   59,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::QString,   52,

       0        // eod
};

void ZegoSingleAudienceDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ZegoSingleAudienceDialog *_t = static_cast<ZegoSingleAudienceDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigSaveVideoSettings((*reinterpret_cast< SettingsPtr(*)>(_a[1]))); break;
        case 1: _t->sigShowSnapShotImage((*reinterpret_cast< QImage*(*)>(_a[1]))); break;
        case 2: _t->OnLoginRoom((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< QVector<StreamPtr>(*)>(_a[3]))); break;
        case 3: _t->OnStreamUpdated((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QVector<StreamPtr>(*)>(_a[2])),(*reinterpret_cast< LIVEROOM::ZegoStreamUpdateType(*)>(_a[3]))); break;
        case 4: _t->OnPlayStateUpdate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 5: _t->OnUserUpdate((*reinterpret_cast< QVector<QString>(*)>(_a[1])),(*reinterpret_cast< QVector<QString>(*)>(_a[2])),(*reinterpret_cast< QVector<int>(*)>(_a[3])),(*reinterpret_cast< QVector<int>(*)>(_a[4])),(*reinterpret_cast< uint(*)>(_a[5])),(*reinterpret_cast< LIVEROOM::ZegoUserUpdateType(*)>(_a[6]))); break;
        case 6: _t->OnDisconnect((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 7: _t->OnKickOut((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 8: _t->OnPlayQualityUpdate((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 9: _t->OnSendRoomMessage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< unsigned long long(*)>(_a[4]))); break;
        case 10: _t->OnRecvRoomMessage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QVector<RoomMsgPtr>(*)>(_a[2]))); break;
        case 11: _t->OnAudioDeviceChanged((*reinterpret_cast< AV::AudioDeviceType(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< AV::DeviceState(*)>(_a[4]))); break;
        case 12: _t->OnVideoDeviceChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< AV::DeviceState(*)>(_a[3]))); break;
        case 13: _t->OnSnapshot((*reinterpret_cast< void*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 14: _t->OnClickTitleButton(); break;
        case 15: _t->OnClose(); break;
        case 16: _t->OnButtonSendMessage(); break;
        case 17: _t->OnButtonSound(); break;
        case 18: _t->OnShareLink(); break;
        case 19: _t->OnSwitchAudioDevice((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->OnSwitchVideoDevice((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->OnButtonShowFullScreen(); break;
        case 22: _t->OnShowSnapShotImage((*reinterpret_cast< QImage*(*)>(_a[1]))); break;
        case 23: _t->OnSnapshotWithStreamID((*reinterpret_cast< const QString(*)>(_a[1]))); break;
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
            typedef void (ZegoSingleAudienceDialog::*_t)(SettingsPtr );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ZegoSingleAudienceDialog::sigSaveVideoSettings)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ZegoSingleAudienceDialog::*_t)(QImage * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ZegoSingleAudienceDialog::sigShowSnapShotImage)) {
                *result = 1;
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
void ZegoSingleAudienceDialog::sigSaveVideoSettings(SettingsPtr _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ZegoSingleAudienceDialog::sigShowSnapShotImage(QImage * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE

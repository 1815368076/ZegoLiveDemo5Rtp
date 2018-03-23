/****************************************************************************
** Meta object code from reading C++ file 'ZegoVideoTalkDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Dialog/ZegoVideoTalkDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ZegoVideoTalkDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ZegoVideoTalkDialog_t {
    QByteArrayData data[65];
    char stringdata0[910];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ZegoVideoTalkDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ZegoVideoTalkDialog_t qt_meta_stringdata_ZegoVideoTalkDialog = {
    {
QT_MOC_LITERAL(0, 0, 19), // "ZegoVideoTalkDialog"
QT_MOC_LITERAL(1, 20, 11), // "OnLoginRoom"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 9), // "errorCode"
QT_MOC_LITERAL(4, 43, 6), // "roomId"
QT_MOC_LITERAL(5, 50, 18), // "QVector<StreamPtr>"
QT_MOC_LITERAL(6, 69, 11), // "vStreamList"
QT_MOC_LITERAL(7, 81, 15), // "OnStreamUpdated"
QT_MOC_LITERAL(8, 97, 30), // "LIVEROOM::ZegoStreamUpdateType"
QT_MOC_LITERAL(9, 128, 4), // "type"
QT_MOC_LITERAL(10, 133, 20), // "OnPublishStateUpdate"
QT_MOC_LITERAL(11, 154, 9), // "stateCode"
QT_MOC_LITERAL(12, 164, 8), // "streamId"
QT_MOC_LITERAL(13, 173, 9), // "StreamPtr"
QT_MOC_LITERAL(14, 183, 10), // "streamInfo"
QT_MOC_LITERAL(15, 194, 17), // "OnPlayStateUpdate"
QT_MOC_LITERAL(16, 212, 12), // "OnUserUpdate"
QT_MOC_LITERAL(17, 225, 16), // "QVector<QString>"
QT_MOC_LITERAL(18, 242, 7), // "userIDs"
QT_MOC_LITERAL(19, 250, 9), // "userNames"
QT_MOC_LITERAL(20, 260, 12), // "QVector<int>"
QT_MOC_LITERAL(21, 273, 9), // "userFlags"
QT_MOC_LITERAL(22, 283, 9), // "userRoles"
QT_MOC_LITERAL(23, 293, 9), // "userCount"
QT_MOC_LITERAL(24, 303, 28), // "LIVEROOM::ZegoUserUpdateType"
QT_MOC_LITERAL(25, 332, 12), // "OnDisconnect"
QT_MOC_LITERAL(26, 345, 9), // "OnKickOut"
QT_MOC_LITERAL(27, 355, 6), // "reason"
QT_MOC_LITERAL(28, 362, 19), // "OnPlayQualityUpdate"
QT_MOC_LITERAL(29, 382, 7), // "quality"
QT_MOC_LITERAL(30, 390, 8), // "videoFPS"
QT_MOC_LITERAL(31, 399, 8), // "videoKBS"
QT_MOC_LITERAL(32, 408, 22), // "OnPublishQualityUpdate"
QT_MOC_LITERAL(33, 431, 12), // "OnAVAuxInput"
QT_MOC_LITERAL(34, 444, 14), // "unsigned char*"
QT_MOC_LITERAL(35, 459, 5), // "pData"
QT_MOC_LITERAL(36, 465, 4), // "int*"
QT_MOC_LITERAL(37, 470, 8), // "pDataLen"
QT_MOC_LITERAL(38, 479, 13), // "pDataLenValue"
QT_MOC_LITERAL(39, 493, 11), // "pSampleRate"
QT_MOC_LITERAL(40, 505, 12), // "pNumChannels"
QT_MOC_LITERAL(41, 518, 20), // "OnAudioDeviceChanged"
QT_MOC_LITERAL(42, 539, 19), // "AV::AudioDeviceType"
QT_MOC_LITERAL(43, 559, 10), // "deviceType"
QT_MOC_LITERAL(44, 570, 11), // "strDeviceId"
QT_MOC_LITERAL(45, 582, 13), // "strDeviceName"
QT_MOC_LITERAL(46, 596, 15), // "AV::DeviceState"
QT_MOC_LITERAL(47, 612, 5), // "state"
QT_MOC_LITERAL(48, 618, 20), // "OnVideoDeviceChanged"
QT_MOC_LITERAL(49, 639, 13), // "OnButtonClose"
QT_MOC_LITERAL(50, 653, 15), // "OnButtonMaximum"
QT_MOC_LITERAL(51, 669, 15), // "OnButtonMinimum"
QT_MOC_LITERAL(52, 685, 23), // "OnButtonCheckMicroPhone"
QT_MOC_LITERAL(53, 709, 20), // "OnButtonCheckSpeaker"
QT_MOC_LITERAL(54, 730, 19), // "OnButtonCheckCamera"
QT_MOC_LITERAL(55, 750, 16), // "OnButtonCheckAux"
QT_MOC_LITERAL(56, 767, 25), // "OnButtonCheckSoundCapture"
QT_MOC_LITERAL(57, 793, 18), // "OnButtonFullScreen"
QT_MOC_LITERAL(58, 812, 12), // "OnProgChange"
QT_MOC_LITERAL(59, 825, 19), // "OnSwitchAudioDevice"
QT_MOC_LITERAL(60, 845, 2), // "id"
QT_MOC_LITERAL(61, 848, 19), // "OnSwitchVideoDevice"
QT_MOC_LITERAL(62, 868, 15), // "OnUseDefaultAux"
QT_MOC_LITERAL(63, 884, 17), // "OnGetMusicAppPath"
QT_MOC_LITERAL(64, 902, 7) // "exePath"

    },
    "ZegoVideoTalkDialog\0OnLoginRoom\0\0"
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
    "pNumChannels\0OnAudioDeviceChanged\0"
    "AV::AudioDeviceType\0deviceType\0"
    "strDeviceId\0strDeviceName\0AV::DeviceState\0"
    "state\0OnVideoDeviceChanged\0OnButtonClose\0"
    "OnButtonMaximum\0OnButtonMinimum\0"
    "OnButtonCheckMicroPhone\0OnButtonCheckSpeaker\0"
    "OnButtonCheckCamera\0OnButtonCheckAux\0"
    "OnButtonCheckSoundCapture\0OnButtonFullScreen\0"
    "OnProgChange\0OnSwitchAudioDevice\0id\0"
    "OnSwitchVideoDevice\0OnUseDefaultAux\0"
    "OnGetMusicAppPath\0exePath"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ZegoVideoTalkDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,  144,    2, 0x09 /* Protected */,
       7,    3,  151,    2, 0x09 /* Protected */,
      10,    3,  158,    2, 0x09 /* Protected */,
      15,    2,  165,    2, 0x09 /* Protected */,
      16,    6,  170,    2, 0x09 /* Protected */,
      25,    2,  183,    2, 0x09 /* Protected */,
      26,    2,  188,    2, 0x09 /* Protected */,
      28,    4,  193,    2, 0x09 /* Protected */,
      32,    4,  202,    2, 0x09 /* Protected */,
      33,    5,  211,    2, 0x09 /* Protected */,
      41,    4,  222,    2, 0x09 /* Protected */,
      48,    3,  231,    2, 0x09 /* Protected */,
      49,    0,  238,    2, 0x08 /* Private */,
      50,    0,  239,    2, 0x08 /* Private */,
      51,    0,  240,    2, 0x08 /* Private */,
      52,    0,  241,    2, 0x08 /* Private */,
      53,    0,  242,    2, 0x08 /* Private */,
      54,    0,  243,    2, 0x08 /* Private */,
      55,    0,  244,    2, 0x08 /* Private */,
      56,    0,  245,    2, 0x08 /* Private */,
      57,    0,  246,    2, 0x08 /* Private */,
      58,    0,  247,    2, 0x08 /* Private */,
      59,    1,  248,    2, 0x08 /* Private */,
      61,    1,  251,    2, 0x08 /* Private */,
      62,    1,  254,    2, 0x08 /* Private */,
      63,    1,  257,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, 0x80000000 | 5,    3,    4,    6,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 5, 0x80000000 | 8,    4,    6,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, 0x80000000 | 13,   11,   12,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   11,   12,
    QMetaType::Void, 0x80000000 | 17, 0x80000000 | 17, 0x80000000 | 20, 0x80000000 | 20, QMetaType::UInt, 0x80000000 | 24,   18,   19,   21,   22,   23,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   27,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Double, QMetaType::Double,   12,   29,   30,   31,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Double, QMetaType::Double,   12,   29,   30,   31,
    QMetaType::Void, 0x80000000 | 34, 0x80000000 | 36, QMetaType::Int, 0x80000000 | 36, 0x80000000 | 36,   35,   37,   38,   39,   40,
    QMetaType::Void, 0x80000000 | 42, QMetaType::QString, QMetaType::QString, 0x80000000 | 46,   43,   44,   45,   47,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 46,   44,   45,   47,
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
    QMetaType::Void, QMetaType::Int,   60,
    QMetaType::Void, QMetaType::Int,   60,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void, QMetaType::QString,   64,

       0        // eod
};

void ZegoVideoTalkDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ZegoVideoTalkDialog *_t = static_cast<ZegoVideoTalkDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnLoginRoom((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< QVector<StreamPtr>(*)>(_a[3]))); break;
        case 1: _t->OnStreamUpdated((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QVector<StreamPtr>(*)>(_a[2])),(*reinterpret_cast< LIVEROOM::ZegoStreamUpdateType(*)>(_a[3]))); break;
        case 2: _t->OnPublishStateUpdate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< StreamPtr(*)>(_a[3]))); break;
        case 3: _t->OnPlayStateUpdate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->OnUserUpdate((*reinterpret_cast< QVector<QString>(*)>(_a[1])),(*reinterpret_cast< QVector<QString>(*)>(_a[2])),(*reinterpret_cast< QVector<int>(*)>(_a[3])),(*reinterpret_cast< QVector<int>(*)>(_a[4])),(*reinterpret_cast< uint(*)>(_a[5])),(*reinterpret_cast< LIVEROOM::ZegoUserUpdateType(*)>(_a[6]))); break;
        case 5: _t->OnDisconnect((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 6: _t->OnKickOut((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 7: _t->OnPlayQualityUpdate((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 8: _t->OnPublishQualityUpdate((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 9: _t->OnAVAuxInput((*reinterpret_cast< unsigned char*(*)>(_a[1])),(*reinterpret_cast< int*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int*(*)>(_a[4])),(*reinterpret_cast< int*(*)>(_a[5]))); break;
        case 10: _t->OnAudioDeviceChanged((*reinterpret_cast< AV::AudioDeviceType(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< AV::DeviceState(*)>(_a[4]))); break;
        case 11: _t->OnVideoDeviceChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< AV::DeviceState(*)>(_a[3]))); break;
        case 12: _t->OnButtonClose(); break;
        case 13: _t->OnButtonMaximum(); break;
        case 14: _t->OnButtonMinimum(); break;
        case 15: _t->OnButtonCheckMicroPhone(); break;
        case 16: _t->OnButtonCheckSpeaker(); break;
        case 17: _t->OnButtonCheckCamera(); break;
        case 18: _t->OnButtonCheckAux(); break;
        case 19: _t->OnButtonCheckSoundCapture(); break;
        case 20: _t->OnButtonFullScreen(); break;
        case 21: _t->OnProgChange(); break;
        case 22: _t->OnSwitchAudioDevice((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->OnSwitchVideoDevice((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->OnUseDefaultAux((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: _t->OnGetMusicAppPath((*reinterpret_cast< QString(*)>(_a[1]))); break;
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
    }
}

const QMetaObject ZegoVideoTalkDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ZegoVideoTalkDialog.data,
      qt_meta_data_ZegoVideoTalkDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ZegoVideoTalkDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZegoVideoTalkDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ZegoVideoTalkDialog.stringdata0))
        return static_cast<void*>(const_cast< ZegoVideoTalkDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ZegoVideoTalkDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

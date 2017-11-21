#pragma execution_character_set("utf-8")

#ifndef ZEGOSINGLEAUDIENCEDIALOG_H
#define ZEGOSINGLEAUDIENCEDIALOG_H

#include <QtWidgets/QDialog>
#include <QStack>
#include <QVector>
#include <QLayout>
#include <QStringListModel>
#include <QTime>
#include <QTimer>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPaintEvent>
#include <QTextCodec>
#include <QJsonDocument>
#include <QVariantMap>
#include <QJsonObject>
#include <QFileDialog>
#include <QGridLayout>
#include <QStandardItemModel>
#include <QImage>
#include <QPixmap>
#ifdef Q_OS_WIN
Q_GUI_EXPORT QPixmap qt_pixmapFromWinHBITMAP(HBITMAP bitmap, int hbitmapFormat);
#endif
#include "ui_ZegoLiveRoomDialog.h"
#include "ZegoSettingsModel.h"
#include "ZegoRoomModel.h"
#include "ZegoAVView.h"
#include "LiveRoom.h"
#include "LiveRoom-IM.h"
#include "LiveRoom-Publisher.h"
#include "LiveRoom-Player.h"
#include "LiveRoomDefines.h"
#include "LiveRoomDefines-IM.h"
#include "ZegoRoomMsgModel.h"
#include "ZegoLiveDemo.h"
#include "NoFocusFrameDelegate.h"
#include "ZegoShareDialog.h"
#include "ZegoRoomMessageLabel.h"
#include "ZegoImageShowDialog.h"

#define MAX_VIEW_COUNT 12

//标题栏坐标范围
#define pos_min_y  0
#define pos_max_y  40

#define m_FirstAnchor "first"
#define m_HlsKey "Hls"
#define m_RtmpKey "rtmp"

class ZegoSingleAudienceDialog : public QDialog
{
	Q_OBJECT

public:
	ZegoSingleAudienceDialog(QWidget *parent = 0);
	ZegoSingleAudienceDialog(qreal dpi, SettingsPtr curSettings, RoomPtr room, QString curUserID, QString curUserName, QDialog *lastDialog, QDialog *parent = 0);
	~ZegoSingleAudienceDialog();
	void initDialog();

signals:
	//当直播窗口关闭时，将更改的视频设置传回给MainDialog（如，更换了摄像头、麦克风）
	void sigSaveVideoSettings(SettingsPtr settings);

protected slots:
	void OnLoginRoom(int errorCode, const QString& roomId, QVector<StreamPtr> vStreamList);
	void OnStreamUpdated(const QString& roomId, QVector<StreamPtr> vStreamList, LIVEROOM::ZegoStreamUpdateType type);

	void OnPlayStateUpdate(int stateCode, const QString& streamId);
	void OnUserUpdate(QVector<QString> userIDs, QVector<QString> userNames, QVector<int> userFlags, QVector<int> userRoles, unsigned int userCount, LIVEROOM::ZegoUserUpdateType type);
	void OnDisconnect(int errorCode, const QString& roomId);
	void OnKickOut(int reason, const QString& roomId);
	void OnPlayQualityUpdate(const QString& streamId, int quality, double videoFPS, double videoKBS);
	void OnSendRoomMessage(int errorCode, const QString& roomID, int sendSeq, unsigned long long messageId);
	void OnRecvRoomMessage(const QString& roomId, QVector<RoomMsgPtr> vRoomMsgList);
	void OnAudioDeviceChanged(AV::AudioDeviceType deviceType, const QString& strDeviceId, const QString& strDeviceName, AV::DeviceState state);
	void OnVideoDeviceChanged(const QString& strDeviceId, const QString& strDeviceName, AV::DeviceState state);
	void OnSnapshot(void *pImage, const QString &streamID);

protected:
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void mouseDoubleClickEvent(QMouseEvent *event);
	virtual void closeEvent(QCloseEvent *e);
	virtual bool eventFilter(QObject *target, QEvent *event);

signals:
	void sigShowSnapShotImage(QImage *imageData);

private slots:
	void OnClickTitleButton();
	void OnClose();
	void OnButtonSendMessage();
	void OnButtonSound();
	void OnShareLink();
	//切换音视频设备
	void OnSwitchAudioDevice(int id);
	void OnSwitchVideoDevice(int id);
	//全屏显示
	void OnButtonShowFullScreen();
	//截图
	void OnShowSnapShotImage(QImage *imageData);
	void OnSnapshotWithStreamID(const QString &streamID);

private:
	void insertStringListModelItem(QStringListModel * model, QString name, int size);
	void removeStringListModelItem(QStringListModel * model, QString name);
	void EnumVideoAndAudioDevice();
	void initComboBox();
	void FreeAVView(StreamPtr stream);
	void StartPlayStream(StreamPtr stream);
	void StopPlayStream(const QString& streamID);
	void SetOperation(bool state);
	void GetOut();
	bool praseJsonData(QJsonDocument doc);
	QString encodeStringAddingEscape(QString str);

	//成员列表增删函数
	void roomMemberAdd(QString userName);
	void roomMemberDelete(QString userName);

	int takeLeastAvaliableViewIndex();
private:
	Ui::ZegoLiveRoomDialog ui;
	qreal m_dpi;

	QVector<unsigned int> m_avaliableView;
	bool m_bCKEnableMic;
	bool m_bCKEnableSpeaker;
	SettingsPtr m_pAVSettings;
	RoomPtr m_pChatRoom;

	bool isMax = false;
	int m_iRequestJoinLiveSeq = -1;

	bool m_isLiveFullScreen = false;
    
	QString m_strCurUserID;
	QString m_strCurUserName;

	QVector<QString> m_vecAudioDeviceIDs;
	QVector<QString> m_vecVideoDeviceIDs;

	QVector<QZegoAVView *> AVViews;

	QString m_strLastSendMsg;

	//List
	QStringList m_MircoPhoneList;
	QStringList m_CameraList;

	//自定义的ComboBox下拉式页面
	QListView *m_cbMircoPhoneListView;
	QListView *m_cbCameraListView;

	//Model
	QStringListModel *m_cbMircoPhoneModel;
	QStringListModel *m_cbCameraModel;
	QStandardItemModel *m_chatModel;
	QStringListModel *m_memberModel;

	//实现自定义标题栏的拖动
	bool isMousePressed;
	QPoint mousePosition;

	//实时监控麦克风音量大小
	//QTimer *timer;

	//保存上一个界面的指针，用于退出该页面时显示它
	QDialog *m_lastDialog;

	//保存拉混流的ExtraInfo信息
	QString sharedHlsUrl;
	QString sharedRtmpUrl;

	//当pc为拉流端时，保存当前第一主播的streamID
	//QString m_anchorStreamID;
	//保留当前第一主播的流信息
	StreamPtr m_anchorStreamInfo;

	QZegoAVView *m_mainLiveView;
};

#endif
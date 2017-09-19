﻿#ifndef ZEGOMOREANCHORDIALOG_H
#define ZEGOMOREANCHORDIALOG_H

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

#define MAX_VIEW_COUNT 12

//标题栏坐标范围
#define pos_min_y  0
#define pos_max_y  40

#define m_FirstAnchor "first"
#define m_HlsKey "Hls"
#define m_RtmpKey "rtmp"

class ZegoMoreAnchorDialog : public QDialog
{
	Q_OBJECT

public:
	ZegoMoreAnchorDialog(QWidget *parent = 0);
	ZegoMoreAnchorDialog(SettingsPtr curSettings, RoomPtr room, QString curUserID, QString curUserName, QDialog *lastDialog, QDialog *parent = 0);
	~ZegoMoreAnchorDialog();
	void initDialog();

	protected slots:
	void OnLoginRoom(int errorCode, const QString& roomId, QVector<StreamPtr> vStreamList);
	void OnStreamUpdated(const QString& roomId, QVector<StreamPtr> vStreamList, LIVEROOM::ZegoStreamUpdateType type);
	void OnPublishStateUpdate(int stateCode, const QString& streamId, StreamPtr streamInfo);
	void OnPlayStateUpdate(int stateCode, const QString& streamId);
	void OnUserUpdate(QVector<QString> userIDs, QVector<QString> userNames, QVector<int> userFlags, QVector<int> userRoles, unsigned int userCount, LIVEROOM::ZegoUserUpdateType type);
	void OnDisconnect(int errorCode, const QString& roomId);
	void OnKickOut(int reason, const QString& roomId);
	void OnPlayQualityUpdate(const QString& streamId, int quality, double videoFPS, double videoKBS);
	void OnPublishQualityUpdate(const QString& streamId, int quality, double videoFPS, double videoKBS);
	void OnAVAuxInput(unsigned char *pData, int* pDataLen, int pDataLenValue, int *pSampleRate, int *pNumChannels);
	void OnSendRoomMessage(int errorCode, const QString& roomID, int sendSeq, unsigned long long messageId);
	void OnRecvRoomMessage(const QString& roomId, QVector<RoomMsgPtr> vRoomMsgList);
	void OnJoinLiveRequest(int seq, const QString& fromUserId, const QString& fromUserName, const QString& roomId);
	void OnAudioDeviceChanged(AV::AudioDeviceType deviceType, const QString& strDeviceId, const QString& strDeviceName, AV::DeviceState state);
	void OnVideoDeviceChanged(const QString& strDeviceId, const QString& strDeviceName, AV::DeviceState state);

protected:
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void mouseDoubleClickEvent(QMouseEvent *event);
	virtual void closeEvent(QCloseEvent *e);
	virtual bool eventFilter(QObject *target, QEvent *event);

signals:
	//当直播窗口关闭时，将更改的视频设置传回给MainDialog（如，更换了摄像头、麦克风）
	void sigSaveVideoSettings(SettingsPtr settings);

private slots:
	void OnClickTitleButton();
	void OnClose();
	void OnButtonSwitchPublish();
	void OnButtonSendMessage();
	void OnButtonSoundCapture();
	void OnButtonMircoPhone();
	void OnButtonSound();
	void OnProgChange();
	void OnShareLink();
	void OnButtonAux();

	//切换音视频设备
	void OnSwitchAudioDevice(int id);
	void OnSwitchVideoDevice(int id);

private:
	void insertStringListModelItem(QStringListModel * model, QString name, int size);
	void removeStringListModelItem(QStringListModel * model, QString name);
	void EnumVideoAndAudioDevice();
	void initComboBox();
	void StartPublishStream();
	void StopPublishStream(const QString& streamID);
	void FreeAVView(StreamPtr stream);
	void StartPlayStream(StreamPtr stream);
	void StopPlayStream(const QString& streamID);
	void GetOut();
	void BeginAux();
	void EndAux();
	bool praseJsonData(QJsonDocument doc);
	QString encodeStringAddingEscape(QString str);

	//成员列表增删函数
	void roomMemberAdd(QString userName);
	void roomMemberDelete(QString userName);

	//view布局函数
	int takeLeastAvaliableViewIndex();
	void initAVView(QZegoAVView *view);
	void addAVView(int addViewIndex);
	void removeAVView(int removeViewIndex);
	void updateViewLayout(int viewCount);

private:
	Ui::ZegoLiveRoomDialog ui;

	QVector<unsigned int> m_avaliableView;
	bool m_bCKEnableMic;
	bool m_bCKEnableSpeaker;
	SettingsPtr m_pAVSettings;
	RoomPtr m_pChatRoom;
	//混流参数
	unsigned char* m_pAuxData;
	int m_nAuxDataLen;
	int m_nAuxDataPos;

	bool m_bSystemCapture = false;
	bool m_bIsPublishing = false;
	bool isMax = false;

	QString m_strPublishStreamID;
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
	QStringListModel *m_chatModel;
	QStringListModel *m_memberModel;

	//实现自定义标题栏的拖动
	bool isMousePressed;
	QPoint mousePosition;

	//实时监控麦克风音量大小
	QTimer *timer;

	//保存上一个界面的指针，用于退出该页面时显示它
	QDialog *m_lastDialog;

	//分享链接
	QString sharedHlsUrl;
	QString sharedRtmpUrl;

	//保留当前第一主播的流信息
	StreamPtr m_anchorStreamInfo;

	//view的网格动态布局
	QGridLayout *gridLayout;
};

#endif
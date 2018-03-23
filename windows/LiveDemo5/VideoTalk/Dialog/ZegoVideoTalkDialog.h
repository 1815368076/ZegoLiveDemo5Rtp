#pragma execution_character_set("utf-8")

#ifndef ZEGOVIDEOTALKDIALOG_H
#define ZEGOVIDEOTALKDIALOG_H

#include <QtWidgets/QDialog>
#include <QWidget>
#include <QMouseEvent>
#include <QTimer>
#include <QStringListModel>
#include <QMessageBox>
#include <QFileDialog>
#include <QTime>
#include <QDateTime>
#include <QStandardItemModel>
#include "ui_ZegoVideoTalkDialog.h"
#include "Config/ZegoUserConfig.h"
#include "ZegoAVView.h"
#include "Delegate/NoFocusFrameDelegate.h"
#include "Model/ZegoSettingsModel.h"
#include "Model/ZegoRoomModel.h"
#include "ZegoAudioHook.h"
#include "ZegoMusicHookDialog.h"
#include "ZegoLogLabel.h"

#define MAX_VIEW_COUNT 12

//标题栏坐标范围
#define pos_min_x  0
#define pos_max_x  ui.m_zoneTitle->size().width()
#define pos_min_y  0
#define pos_max_y  ui.m_zoneTitle->size().height()

class ZegoVideoTalkDialog : public QDialog
{
	Q_OBJECT

public:
	ZegoVideoTalkDialog(QZegoUserConfig userConfig, RoomPtr chatRoom, QDialog *lastDialog, bool isVideoCustom, QWidget *parent = 0);
	~ZegoVideoTalkDialog();
	void initDialog();

	//sdk回调槽
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
	void OnAudioDeviceChanged(AV::AudioDeviceType deviceType, const QString& strDeviceId, const QString& strDeviceName, AV::DeviceState state);
	void OnVideoDeviceChanged(const QString& strDeviceId, const QString& strDeviceName, AV::DeviceState state);

	//UI回调槽
private slots:
	//Button槽
	void OnButtonClose();
	void OnButtonMaximum();
	void OnButtonMinimum();
	void OnButtonCheckMicroPhone();
	void OnButtonCheckSpeaker();
	void OnButtonCheckCamera();
	void OnButtonCheckAux();
	void OnButtonCheckSoundCapture();
	void OnButtonFullScreen();
	//Timer槽
	void OnProgChange();
	//ComboBox槽
	void OnSwitchAudioDevice(int id);
	void OnSwitchVideoDevice(int id);
	//混音app地址回调
	void OnUseDefaultAux(bool state);
#ifdef Q_OS_WIN
	void OnGetMusicAppPath(QString exePath);
#endif
protected:
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void closeEvent(QCloseEvent *event);
	virtual bool eventFilter(QObject *target, QEvent *event);

private:
	//推拉流
	void StartPublishStream();
	void StopPublishStream(const QString& streamID);
	void StartPlayStream(StreamPtr stream);
	void StopPlayStream(const QString& streamID);
#if (defined Q_OS_WIN32) && (defined USE_SURFACE_MERGE) 
	void StartSurfaceMerge();
#endif
	//初始化
	void initComboBox();
	void EnumVideoAndAudioDevice();
	//操作model增删的函数
	void insertStringListModelItem(QStringListModel * model, QString name, int size);
	void removeStringListModelItem(QStringListModel * model, QString name);
	//退出前清理
	void cleanBeforeGetOut();
	//view布局函数
	int takeLeastAvaliableViewIndex();
	void initAVView(QZegoAVView *view);
	void addAVView(int addViewIndex);
	void removeAVView(int removeViewIndex);
	void updateViewLayout(int viewCount);
	void FreeAVView(StreamPtr stream);
	//混音
	void BeginDefaultAux();
	void EndAux();
	//成员列表增删函数
	void roomMemberAdd(QString userName);
	void roomMemberDelete(QString userName);
	//打印日志
	void addLogString(QString log);

private:
	Ui::ZegoVideoTalkDialog ui;

	//当前房间号
	QString m_roomID;

	QZegoUserConfig m_userConfig;
	//自定义标题栏拖动
	bool m_isMousePressed = false;
	QPoint mousePosition;
	bool m_isMax = false;
	QVector<unsigned int> m_avaliableView;

	bool m_bCKEnableMic = true;
	bool m_bCKEnableSpeaker = true;
	bool m_bCKEnableCamera = true;

	bool m_isUseDefaultAux = false;
	bool m_bIsPublishing = false;
	bool m_isVideoCustom = false;
	bool m_isLiveFullScreen = false;
	SettingsPtr m_pAVSettings;
	RoomPtr m_pChatRoom;
	//混音参数
	unsigned char* m_pAuxData;
	int m_nAuxDataLen;
	int m_nAuxDataPos;

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

	//Model
	QStringListModel *m_cbMircoPhoneModel;
	QStringListModel *m_cbCameraModel;
	QStringListModel *m_memberModel;
	QStandardItemModel *m_logModel;

	//自定义的ComboBox下拉式页面
	QListView *m_cbMircoPhoneListView;
	QListView *m_cbCameraListView;

	//实时监控麦克风音量大小
	QTimer *timer;

	//保存上一个界面的指针，用于退出该页面时显示它
	QDialog *m_lastDialog;

	//view的网格动态布局
	QGridLayout *gridLayout;

	//保留自己的流信息
	StreamPtr m_anchorStreamInfo;

	//hook对话框对象
	ZegoMusicHookDialog hookDialog;
};

#endif // ZEGOVIDEOTALKDIALOG_H
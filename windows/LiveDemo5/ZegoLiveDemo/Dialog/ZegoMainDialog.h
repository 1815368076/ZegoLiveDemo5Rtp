#ifndef ZEGOMAINDIALOG_H
#define ZEGOMAINDIALOG_H

#include <QtWidgets/QDialog>
#include "ui_ZegoMainDialog.h"
#include "ZegoRoomModel.h"
#include "ZegoUserConfig.h"
#include "ZegoLiveDemo.h"
#include "ZegoBase.h"
#include "ZegoEnterRoomButton.h"
#include <QtNetwork/qnetworkaccessmanager.h> 
#include <QtNetwork/qnetworkrequest.h>
#include <QtNetwork/qnetworkreply.h>
#include <QFile>
#include <QUrl>
#include <QTimer>
#include <QJsonParseError>
#include <QTextCodec>
#include <QJsonObject>
#include <QMessageBox>
#include <QJsonArray>
#include <QDesktopServices>
#include <QListWidget>
#include <QMouseEvent>
#include <QStringListModel>
#include <QStandardItemModel>

//标题栏坐标范围
#define pos_min_x  0
#define pos_max_x  ui.m_zoneTitle->size().width()
#define pos_min_y  0
#define pos_max_y  ui.m_zoneTitle->size().height()

class ZegoMainDialog : public QDialog
{
	Q_OBJECT

public:
	ZegoMainDialog(QWidget *parent = 0);
	~ZegoMainDialog();
	void initDialog();

protected slots:
    void OnAudioDeviceChanged(AV::AudioDeviceType deviceType, const QString& strDeviceId, const QString& strDeviceName, AV::DeviceState state);
    void OnVideoDeviceChanged(const QString& strDeviceId, const QString& strDeviceName, AV::DeviceState state);

public slots:
	void OnButtonModeSheetChange(int id);
	void OnButtonQualityChange(int id);
	void OnSliderValueChange(int value);
	void OnButtonSliderValueChange();
	void OnButtonClickedRefresh();
	void OnButtonClickedPublish();
	void OnButtonEnterRoom();
	void OnButtonSwitchTestEnv();
	void OnButtonSwitchVideoCapture();
	void OnButtonSwitchVideoFilter();
	void OnButoonSwitchSurfaceMerge();
	void OnButtonUploadLog();
	void OnSaveUserIdChanged();
	void OnSaveUserNameChanged();
	void OnCheckSliderPressed();
	void OnCheckSliderReleased();

	void writeJsonData(QNetworkReply *reply);
	//切换音视频设备
	void OnSwitchAudioDevice(int id);
	void OnSwitchVideoDevice(int id);
	void OnSaveVideoSettings(SettingsPtr settings);

	void OnComboBoxAppVersionChanged(int id);

protected:
	virtual void mousePressEvent(QMouseEvent *e);
	virtual void mouseMoveEvent(QMouseEvent *e);
	virtual void mouseReleaseEvent(QMouseEvent *e);
	virtual bool eventFilter(QObject *target, QEvent *event);

private slots:
    void OnClickTitleButton();

private:
	void EnumVideoAndAudioDevice(SettingsPtr curSettings);
	void setDefalutVideoQuality(SettingsPtr curSettings);
	void PullRoomList();
	void ParseRoomList(QByteArray json);
	void RefreshRoomList(QVector<RoomPtr> roomList);
	void addModeButtonGroup();
	void addQualityButtonGroup();
	void initComboBox();
	void insertStringListModelItem(QStringListModel * model, QString name, int size);
	void removeStringListModelItem(QStringListModel * model, QString name);
	void banSwitch();    //禁用未实现功能的按钮

private:
	Ui::ZegoMainDialog ui;
	QVector<RoomPtr> m_roomList;
	QZegoUserConfig m_userConfig;

	//用于接收服务器房间数据的网络请求
	QNetworkAccessManager *m_networkManager;
	QByteArray json;

	//用户当前选择的直播模式
	int m_curMode;

	//直播属性为UDP,RTMP,国际版或自定义（0,1,2,3）
	int m_versionMode;

	//User
	QString m_strEdUserId;
	QString m_strEdUserName;

	//ButtonGroup
	QButtonGroup *m_modeButtonGroup;
	QButtonGroup *m_qualityButtonGroup;

	//VideoQuality
	QVector<QString> m_vecResolution;
	QVector<QString> m_vecBitrate;
	QVector<QString> m_vecFPS;

	//Devices
	QVector<QString> m_vecAudioDeviceIDs;
	QVector<QString> m_vecVideoDeviceIDs;

	//Model
	QStringListModel *m_cbMircoPhoneModel;
	QStringListModel *m_cbCameraModel;
	QStandardItemModel *m_roomListModel;

	//List
	QStringList m_MircoPhoneList;
	QStringList m_CameraList;

	//自定义的ComboBox下拉式页面
	QListView *m_cbMircoPhoneListView;
	QListView *m_cbCameraListView;

	//实现自定义标题栏的拖动
	bool isMousePressed;
	QPoint mousePosition;

	//当前视频质量是否自定义
	bool isVideoCustom;
	//检查当前slider是否pressed
	bool m_sliderPressed = false;
	//是否使用测试环境，默认不使用
	bool m_isUseTestEnv = false;
	//是否使用外部采集，默认不使用
	bool m_isUseVideoCapture = false;
	//是否使用外部滤镜，默认不使用
	bool m_isUseVideoFilter = false;
	//是否使用截屏推流，默认不使用
	bool m_isUseSurfaceMerge = false;
};

#endif // ZEGOMAINDIALOG_H

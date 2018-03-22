#pragma execution_character_set("utf-8")

#ifndef ZEGOSETTINGSDIALOG_H
#define ZEGOSETTINGSDIALOG_H

#include <QtWidgets/QDialog>
#include <QMouseEvent>
#include <QCloseEvent>
#include <QMessageBox>
#include <QMetaType>
#include "ui_ZegoSettingsDialog.h"
#include "Base/ZegoBase.h"
#include "Config/ZegoUserConfig.h"
#include "ZegoVideoTalkDemo.h"
#include "Model/ZegoSettingsModel.h"

//标题栏坐标范围
#define pos_min_x  0
#define pos_max_x  ui.m_zoneTitle->size().width()
#define pos_min_y  0
#define pos_max_y  ui.m_zoneTitle->size().height()

class ZegoSettingsDialog : public QDialog
{
	Q_OBJECT

public:
	ZegoSettingsDialog(QZegoUserConfig userConfig, QWidget *parent = 0);
	~ZegoSettingsDialog();
	void initDialog();

signals:
	void sigChangedSettingsConfig();
	void sigReturnConfigToMainDialog(QZegoUserConfig userConfig);

private slots:
    //Button槽
	void OnButtonClose();
	void OnButtonMinimum();
	void OnButtonSaveConfig();
	void OnButtonUploadLog();
	void OnButtonSwitchTestEnv();
	void OnButtonSwtichSurfaceMerge();
	//Slider槽
	void OnCheckSliderPressed();
	void OnCheckSliderReleased();
	void OnSliderValueChange(int value);
	void OnButtonSliderValueChange();
	//全局槽
	void OnChangedSettingsConfig();
	//ComboBox槽
	void OnComboBoxCheckVideoQuality(int id);
	void OnComboBoxCheckAppVersion(int id);

protected:
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void closeEvent(QCloseEvent *event);
	virtual bool eventFilter(QObject *target, QEvent *event);

private:
	void setDefalutVideoQuality();
	QVector<QString> handleAppSign(QString appSign);

private:
	Ui::ZegoSettingsDialog ui;

	//自定义标题栏拖动
	bool m_isMousePressed = false;
	QPoint mousePosition;

	//处理是否保存了设置的逻辑
	bool m_isConfigChanged = false;
	bool m_isSaveConfig = false;

	//用户配置
	QZegoUserConfig m_userConfig;
	QString m_strEdUserId;
	QString m_strEdUserName;
	//直播属性为UDP,RTMP,国际版或自定义（0,1,2,3）
	int m_versionMode = Version::ZEGO_PROTOCOL_UDP;

	//VideoQuality
	QVector<QString> m_vecResolution;
	QVector<QString> m_vecBitrate;
	QVector<QString> m_vecFPS;

	//Slider状态
	bool m_sliderPressed = false;
	//视频质量ComboBox状态
	bool m_isVideoCustom = false;
	//是否使用surfaceMerge
	bool m_isUseSurfaceMerge;
	//是否使用测试环境，默认不使用
	bool m_isUseTestEnv;
	//当前配置参数
	SettingsPtr m_pCurSettings;
	//用户更改配置后是否需要重新InitSDK，默认否
	bool m_isNeedReInstallSDK = false;

	//暂时保存当前设置的App版本(不一定保存)
	int m_tmpVersionMode;
	//暂时保存切换测试环境(不一定保存)
	bool m_tmpUseTestEnv = false;
	//暂时保存切换SurfaceMerge(不一定保存)
	bool m_tmpUseSurfaceMerge = false;
	//暂时保存VideoSettings(不一定保存)
	SettingsPtr m_tmpCurSettings;
	
};

#endif // ZEGOSETTINGSDIALOG_H
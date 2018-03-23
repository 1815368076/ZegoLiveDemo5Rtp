#pragma execution_character_set("utf-8")

#ifndef ZEGOMAINDIALOG_H
#define ZEGOMAINDIALOG_H

#include <QtWidgets/QDialog>
#include <QMouseEvent>
#include <QDesktopServices>
#include "ui_ZegoMainDialog.h"
#include "ZegoSettingsDialog.h"
#include "ZegoVideoTalkDialog.h"

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

private slots:
    void OnButtonEnterRoom();
    void OnButtonSettings();
	void OnButtonClose();
	void OnButtonMinimum();
	void OnButtonJumpToNet();
	void OnReturnConfigFromSettingsDialog(QZegoUserConfig userConfig);

protected:
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual bool eventFilter(QObject *target, QEvent *event);

private:
	Ui::ZegoMainDialog ui;

	//自定义标题栏拖动
	bool isMousePressed = false;
	QPoint mousePosition;
	//是否使用SurfaceMerge
	bool m_isUseSurfaceMerge = false;
	//读取/新建用户配置
	QZegoUserConfig m_userConfig;

	//用户ID和用户名
	QString m_strEdUserId;
	QString m_strEdUserName;

	bool m_isVideoCustom = false;
};

#endif // ZEGOMAINDIALOG_H

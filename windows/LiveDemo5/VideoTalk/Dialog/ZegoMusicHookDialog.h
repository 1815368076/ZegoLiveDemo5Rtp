#ifndef ZEGOMUSICHOOKDIALOG_H
#define ZEGOMUSICHOOKDIALOG_H

#include <QtWidgets/QDialog>
#include <QMessageBox>
#include <QMouseEvent>
#include "ui_ZegoMusicHookDialog.h"
#include "ZegoAudioHook.h"
#include "SoftWareInfo/ZegoSoftWareInfo.h"

#ifdef Q_OS_WIN
    #include <windows.h>
    #include <tlhelp32.h>
    #include <Psapi.h>

//标题栏坐标范围
#define pos_min_x  0
#define pos_max_x  ui.m_zoneTitle->size().width()
#define pos_min_y  0
#define pos_max_y  ui.m_zoneTitle->size().height()

class ZegoMusicHookDialog : public QDialog
{
	Q_OBJECT

public:
	ZegoMusicHookDialog(QWidget *parent = 0);
	~ZegoMusicHookDialog();
	void searchMusicAppFromReg();
	QString getAppPath();

	BOOL StartProcess(LPTSTR pszProcessPath);
	BOOL KillProcess(LPTSTR pszProcessPath);
	DWORD ProcessIsExist(LPTSTR pszProcessPath);

private slots:
    void OnSelectedMusicApp();
    void OnSendCustomAppPath();

protected:
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);

signals:
    void sigUseDefaultAux(bool state);
	void sigSendMusicAppPath(QString exePath);

private slots:
	void OnClose();
private:
	Ui::ZegoMusicHookDialog ui;
	//QVector<SoftInfo> m_musicAppList;
	SoftInfo KuGouMusic;
	SoftInfo CloudMusic;
	SoftInfo QQMusic;
	SoftInfo KuwoMusic;

	//自定义标题栏拖动
	bool isMousePressed = false;
	QPoint mousePosition;
};
#endif

#endif
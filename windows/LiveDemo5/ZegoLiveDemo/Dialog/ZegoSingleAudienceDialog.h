#pragma execution_character_set("utf-8")

#ifndef ZEGOSINGLEAUDIENCEDIALOG_H
#define ZEGOSINGLEAUDIENCEDIALOG_H

#include "Base/ZegoBaseDialog.h"

class ZegoSingleAudienceDialog : public ZegoBaseDialog
{
	Q_OBJECT

public:
	ZegoSingleAudienceDialog(QWidget *parent = 0);
	ZegoSingleAudienceDialog(qreal dpi, SettingsPtr curSettings, RoomPtr room, QString curUserID, QString curUserName, QDialog *lastDialog, QDialog *parent = 0);
	~ZegoSingleAudienceDialog();
	void initDialog();

protected slots:
	void OnLoginRoom(int errorCode, const QString& roomId, QVector<StreamPtr> vStreamList);
	void OnStreamUpdated(const QString& roomId, QVector<StreamPtr> vStreamList, LIVEROOM::ZegoStreamUpdateType type);
	void OnPlayStateUpdate(int stateCode, const QString& streamId);

private:
	void StartPlayStream(StreamPtr stream);
	void StopPlayStream(const QString& streamID);
	void GetOut();
	bool praseJsonData(QJsonDocument doc);
	
private:
	QString m_strCurUserID;
	QString m_strCurUserName;
};

#endif

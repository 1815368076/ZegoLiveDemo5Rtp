#pragma once

#include "Settings/ZegoSettingsModel.h"
#include <QSharedPointer>
#include <QFile>
#include <QSettings>


class QZegoUserConfig
{
public:
	QZegoUserConfig();
	~QZegoUserConfig();

	void LoadConfig(void);
	void SaveConfig(void);

	QString GetUserId(void);
	QString GetUserIdWithRole(void);
	void SetUserId(const QString strUserId);
	
	QString getUserName(void);
	void SetUserName(const QString strUserName);

	bool IsPrimary(void);
	void SetUserRole(bool primary);

	VideoQuality GetVideoQuality(void);
	void SetVideoQuality(VideoQuality quality);

	SettingsPtr GetVideoSettings(void);
	void SetVideoSettings(SettingsPtr curSettings);

private:
	bool LoadConfigInternal(void);

private:
	QString m_strIniPath;

	QString m_strUserId;
	QString m_strUserName;

	bool m_bPrimary;
	SettingsPtr m_pVideoSettings;
};

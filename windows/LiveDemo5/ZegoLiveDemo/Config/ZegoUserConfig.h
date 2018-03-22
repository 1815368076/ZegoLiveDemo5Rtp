#pragma once

#include "Settings/ZegoSettingsModel.h"
#include <QSharedPointer>
#include <QFile>
#include <QSettings>

struct AppConfig
{
	QString m_customAppId;
	QString m_customAppSign;

	const AppConfig& operator=(const AppConfig& other)
	{
		if (this == &other)
		{
			return *this;
		}

		m_customAppId = other.m_customAppId;
		m_customAppSign = other.m_customAppSign;
		return *this;
	}

	bool operator==(const AppConfig& other)
	{
		if (m_customAppId == other.m_customAppId && m_customAppSign == other.m_customAppSign)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

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

	bool GetUseTestEnv();
	void SetUseTestEnv(bool isUseTestEnv);

	AppConfig GetAppConfig();
	void SetAppId(QString appid);
	void SetAppSign(QString appsign);

	int GetAppVersion();
	void SetAppVersion(int ver);

private:
	bool LoadConfigInternal(void);

private:
	QString m_strIniPath;

	QString m_strUserId;
	QString m_strUserName;

	
	bool m_bPrimary;
	bool m_isUseTestEnv;

	SettingsPtr m_pVideoSettings;

	AppConfig m_customAppConfig;
	int m_appVersion;
};

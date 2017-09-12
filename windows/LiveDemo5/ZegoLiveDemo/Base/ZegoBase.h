#pragma once

#include <QObject>
#include "ZegoSettingsModel.h"
#include "ZegoSDKSignal.h"
#include "ZegoVideoCaptureFactoryDemo.h"
#include "ZegoVideoFilterFactoryDemo.h"

//demo版本的枚举类型
typedef enum _Version
{
	ZEGO_PROTOCOL_UDP = 0,
	ZEGO_PROTOCOL_UDP_INTERNATIONAL = 1,
	ZEGO_PROTOCOL_CUSTOM = 2
}Version;

class QZegoBase
{
public :
	QZegoBase();
	~QZegoBase();

	bool InitAVSDK(SettingsPtr pCurSetting, QString userID, QString userName);
	void UninitAVSDK(void);
	bool IsAVSdkInited(void);
	void setTestEnv(bool isTest);
	void setUseVideoCapture(bool isCapture);
	void setUseVideoFilter(bool isFilter);
	void setUseSurfaceMerge(bool isSurface);
	QZegoAVSignal* GetAVSignal(void);
	unsigned long GetAppID(void);
	unsigned char* GetAppSign();
	void setKey(int pKey);
	int getKey();

private :
	typedef enum _INIT_MASK {
		INIT_NONE = 0,
		INIT_AVSDK = 1,
		INIT_CRSDK = 2,
		INIT_ALL = INIT_AVSDK | INIT_CRSDK,
	}INIT_MASK;

	unsigned long m_dwInitedMask;
	QString m_strLogPathUTF8;
	//是否为测试环境
	bool isTestEnv = false;
	//是否使用外部采集
	bool isVideoCapture = false;
	//是否使用外部滤镜
	bool isVideoFilter = false;
	//是否使用截屏推流
	bool isSurfaceMerge = false;

	//appid、appsign默认为UDP版本
	int key = Version::ZEGO_PROTOCOL_UDP;

	QVector <unsigned int> appIDs;
	QVector <unsigned char *> appSigns;

	QZegoAVSignal* m_pAVSignal;
	//外部采集工厂对象
	VideoCaptureFactoryGlue *g_captureFactory;
	//外部滤镜工厂对象
	VideoFilterFactoryGlue *g_filterFactory;
};
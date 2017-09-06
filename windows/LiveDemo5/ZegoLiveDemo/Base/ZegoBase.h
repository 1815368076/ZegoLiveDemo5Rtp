#pragma once

#include <QObject>
#include "ZegoSettingsModel.h"
#include "ZegoSDKSignal.h"
#include "ZegoVideoCaptureFactoryDemo.h"
#include "ZegoVideoFilterFactoryDemo.h"

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

	QZegoAVSignal* m_pAVSignal;
	//外部采集工厂对象
	VideoCaptureFactoryGlue *g_captureFactory;
	//外部滤镜工厂对象
	VideoFilterFactoryGlue *g_filterFactory;
};
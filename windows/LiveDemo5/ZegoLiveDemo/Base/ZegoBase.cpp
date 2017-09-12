#include <QSharedPointer>
#include "ZegoBase.h"
#include "LiveRoom.h"
#include "LiveRoom-IM.h"
#include "LiveRoom-Player.h"
#include "LiveRoom-Publisher.h"
#include "ZegoSurfaceMerge.h"
#include <QDebug>

//#define  ZEGO_PROTOCOL_UDP
//#ifdef ZEGO_PROTOCOL_UDP
static unsigned long g_dwAppID_Udp = 1739272706;
static unsigned char g_bufSignKey_Udp[] =
{
	0x1e, 0xc3, 0xf8, 0x5c, 0xb2, 0xf2, 0x13, 0x70,
	0x26, 0x4e, 0xb3, 0x71, 0xc8, 0xc6, 0x5c, 0xa3,
	0x7f, 0xa3, 0x3b, 0x9d, 0xef, 0xef, 0x2a, 0x85,
	0xe0, 0xc8, 0x99, 0xae, 0x82, 0xc0, 0xf6, 0xf8
};

//#elif defined ZEGO_PROTOCOL_UDP_INTERNATIONAL
static unsigned long g_dwAppID_International = 3322882036;
static unsigned char g_bufSignKey_International[] =
{ 
	0x5d, 0xe6, 0x83, 0xac, 0xa4, 0xe5, 0xad, 0x43,
	0xe5, 0xea, 0xe3, 0x70, 0x6b, 0xe0, 0x77, 0xa4,
	0x18, 0x79, 0x38, 0x31, 0x2e, 0xcc, 0x17, 0x19,
	0x32, 0xd2, 0xfe, 0x22, 0x5b, 0x6b, 0x2b, 0x2f 
};

//#else
/*static unsigned long g_dwAppID2 = 1;
static unsigned char g_bufSignKey2[] =
{
	0x91, 0x93, 0xcc, 0x66, 0x2a, 0x1c, 0x0e, 0xc1,
	0x35, 0xec, 0x71, 0xfb, 0x07, 0x19, 0x4b, 0x38,
	0x41, 0xd4, 0xad, 0x83, 0x78, 0xf2, 0x59, 0x90,
	0xe0, 0xa4, 0x0c, 0x7f, 0xf4, 0x28, 0x41, 0xf7
};*/
//#endif

QZegoBase::QZegoBase(void) : m_dwInitedMask(INIT_NONE)
{
	//日志存放的路径
	m_strLogPathUTF8 = "ZegoLog/";

	appIDs.push_back(g_dwAppID_Udp);
	appIDs.push_back(g_dwAppID_International);

	appSigns.push_back(g_bufSignKey_Udp);
	appSigns.push_back(g_bufSignKey_International);

	m_pAVSignal = new QZegoAVSignal;

}

QZegoBase::~QZegoBase(void)
{
	UninitAVSDK();
	delete m_pAVSignal;
}

bool QZegoBase::InitAVSDK(SettingsPtr pCurSetting, QString userID, QString userName)
{
	if (!IsAVSdkInited())
	{
		qDebug() << "SDK init";
		//Qstring对象.toLocal8Bit().data()用于将QString转为const char*
		LIVEROOM::SetLogDir(m_strLogPathUTF8.toStdString().c_str());
		LIVEROOM::SetVerbose(true);
		LIVEROOM::SetBusinessType(0);
		LIVEROOM::SetUser(userID.toStdString().data(), userName.toStdString().data());
		// ToDo: 需要通过代码获取网络类型
		LIVEROOM::SetNetType(2);

		//是否使用测试环境
		LIVEROOM::SetUseTestEnv(isTestEnv);

		//是否使用外部采集
		if (isVideoCapture)
		{
			g_captureFactory = new VideoCaptureFactoryGlue;
		}
		else
		{
			g_captureFactory = NULL;
		}
		LIVEROOM::SetVideoCaptureFactory(g_captureFactory);

		//是否使用外部滤镜
		if (isVideoFilter)
		{
			g_filterFactory = new VideoFilterFactoryGlue;
		}
		else
		{
			g_filterFactory = NULL;
		}
		LIVEROOM::SetVideoFilterFactory(g_filterFactory);

		//是否使用截屏推流
		if (isSurfaceMerge)
		SurfaceMerge::Init();

		//设置回调
		LIVEROOM::SetLivePublisherCallback(m_pAVSignal);
		LIVEROOM::SetLivePlayerCallback(m_pAVSignal);
		LIVEROOM::SetRoomCallback(m_pAVSignal);
		LIVEROOM::SetIMCallback(m_pAVSignal);
		LIVEROOM::SetDeviceStateCallback(m_pAVSignal);

		LIVEROOM::InitSDK(appIDs[key], appSigns[key], 32);
	}

	LIVEROOM::EnableAux(false);
	//关闭噪音抑制开关
	LIVEROOM::EnableNoiseSuppress(false);

	LIVEROOM::SetPlayVolume(100);
	if (!pCurSetting->GetMircophoneId().isEmpty())
	{
		LIVEROOM::SetAudioDevice(AV::AudioDevice_Input, pCurSetting->GetMircophoneId().toStdString().data());
	}

	//为了调用OnUserUpdate
	LIVEROOM::SetRoomConfig(true, true);

	LIVEROOM::SetVideoCaptureResolution(pCurSetting->GetResolution().cx, pCurSetting->GetResolution().cy);
	LIVEROOM::SetVideoEncodeResolution(pCurSetting->GetResolution().cx, pCurSetting->GetResolution().cy);
	LIVEROOM::SetVideoBitrate(pCurSetting->GetBitrate());
	LIVEROOM::SetVideoFPS(pCurSetting->GetFps());
	if (!pCurSetting->GetCameraId().isEmpty())
	{
		LIVEROOM::SetVideoDevice(pCurSetting->GetCameraId().toStdString().data());
	}

	m_dwInitedMask |= INIT_AVSDK;
	return true;
}

void QZegoBase::UninitAVSDK(void)
{
	if (IsAVSdkInited())
	{
		qDebug() << "SDK uninit";
		LIVEROOM::SetLivePublisherCallback(nullptr);
		LIVEROOM::SetLivePlayerCallback(nullptr);
		LIVEROOM::SetRoomCallback(nullptr);
		LIVEROOM::SetIMCallback(nullptr);
		LIVEROOM::SetDeviceStateCallback(nullptr);

		if (isSurfaceMerge)
			SurfaceMerge::UnInit();

		LIVEROOM::UnInitSDK();

		unsigned long dwNegation = ~(unsigned long)INIT_AVSDK;
		m_dwInitedMask &= dwNegation;
	}
}

bool QZegoBase::IsAVSdkInited(void)
{
	return (m_dwInitedMask & INIT_AVSDK) == INIT_AVSDK;
}

QZegoAVSignal* QZegoBase::GetAVSignal(void)
{
	return m_pAVSignal;
}

unsigned long QZegoBase::GetAppID(void)
{
	return appIDs[key];
}

unsigned char* QZegoBase::GetAppSign()
{
	return appSigns[key];
}

void QZegoBase::setKey(int pKey)
{
	key = pKey;

}

int QZegoBase::getKey()
{
	return key;
}

void QZegoBase::setTestEnv(bool isTest)
{
	isTestEnv = isTest;
}

void QZegoBase::setUseVideoCapture(bool isCapture)
{
	isVideoCapture = isCapture;
}

void QZegoBase::setUseVideoFilter(bool isFilter)
{
	isVideoFilter = isFilter;
}

void QZegoBase::setUseSurfaceMerge(bool isSurface)
{
	isSurfaceMerge = isSurface;
}
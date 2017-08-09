#pragma once

#include <tuple>
#include "ZegoSettingsModel.h"
#include "SimpleIni.h"
#include "ZegoSDKSignal.h"
#include "audio_in_output.h"

class CZegoBase
{
public:
	CZegoBase(void);
	~CZegoBase(void);

	bool InitAVSdk(SettingsPtr pCurSetting, std::string userID, std::string userName);
	void UninitAVSdk(void);
	bool IsAVSdkInited(void);

	CZegoAVSignal& GetAVSignal(void);
    DWORD GetAppID(void);
    std::string GetAppName();
    bool IsTestEnv();
    bool IsGlobalVersion();

private:
    static void OnPrepData(const AVE::AudioFrame& inFrame, AVE::AudioFrame& outFrame);

private:
	typedef enum _INIT_MASK {
		INIT_NONE	= 0,
		INIT_AVSDK	= 1,
		INIT_CRSDK	= 2,
		INIT_ALL		= INIT_AVSDK | INIT_CRSDK,
	}INIT_MASK;

	DWORD m_dwInitedMask;
	std::string m_strLogPathUTF8;
    bool m_bIsTestEnv = false;
    bool m_bIsGlobalVersion = false;

	HWND m_hCommuWnd;
	CZegoAVSignal* m_pAVSignal;
};
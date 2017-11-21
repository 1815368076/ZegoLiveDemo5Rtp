#pragma once

#define ZEGO_API  __declspec(dllexport)

namespace ZEGO
{
	namespace AUDIOHOOK
	{
		//初始化音频Hook模块. SDK内部没有保证线程安全
		//目前只支持hook 32位app
		ZEGO_API void InitAuidoHook();

		//反初始化
		ZEGO_API void UnInitAudioHook();

		//启动音频hook
		//pszAppFilePath 注入的目标进程路径，如kugo
		//pszInjectDllPath 注入的dll路径
		//如果进程已经存在，hook会失败
		ZEGO_API bool StartAudioHook(const char *pszAppFilePath, const char *pszInjectDllPath);

		//开始音频录制
		ZEGO_API bool StartAudioRecord();
		//停止音频录制
		ZEGO_API void StopAudioRecord();
		
		//获取音频数据
		ZEGO_API void GetAUXData(unsigned char *pData, int *pDataLen, int *pSamepleRate, int *pNumChannels);
	}
}
#include "ZegoVideoTalkDemo.h"

QZegoVideoTalkDemoApp::QZegoVideoTalkDemoApp()
{
	
}

//全局唯一的base对象
QZegoVideoTalkDemoApp theApp;

QZegoBase& QZegoVideoTalkDemoApp::GetBase()
{
	return m_base;
}

QZegoAVSignal * GetAVSignal()
{
	return theApp.GetBase().GetAVSignal();
}
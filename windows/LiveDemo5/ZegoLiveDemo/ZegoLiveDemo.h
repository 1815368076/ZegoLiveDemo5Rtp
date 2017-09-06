#pragma once

#include "ZegoBase.h"


class QZegoLiveDemoApp
{
public:
	QZegoLiveDemoApp();

public:
	QZegoBase &GetBase();

private:
	QZegoBase m_base;
};

extern QZegoLiveDemoApp theApp;

QZegoAVSignal * GetAVSignal(void);
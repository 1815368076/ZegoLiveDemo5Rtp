#pragma once

#include <QPushButton>

class ZegoEnterRoomButton : public QPushButton
{
	Q_OBJECT
public:
	ZegoEnterRoomButton(QWidget  * parent = 0);
	~ZegoEnterRoomButton();

	void initButton();
	
};
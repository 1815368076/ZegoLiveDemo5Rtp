#pragma once

#include <QComboBox>
#include <QStringListModel>

class ZegoDeviceComboBox : public QComboBox
{
public:
	ZegoDeviceComboBox(QWidget * parent);
	~ZegoDeviceComboBox();

	void setCurrentIndexWithoutSignal(int index);
	void setNewModelWithoutSignal();

};
#include "ZegoDeviceComboBox.h"
#include <QDebug>

ZegoDeviceComboBox::ZegoDeviceComboBox(QWidget *parent) : QComboBox(parent)
{
	
}

ZegoDeviceComboBox::~ZegoDeviceComboBox()
{

}

void ZegoDeviceComboBox::setCurrentIndexWithoutSignal(int index)
{
	this->blockSignals(true);
	this->setCurrentIndex(index);
	this->blockSignals(false);
}

void ZegoDeviceComboBox::setNewModelWithoutSignal()
{
	this->blockSignals(true);
	this->setModel(new QStringListModel(this));
	this->blockSignals(false);
}


#include "ZegoImageButton.h"
#include <QDebug>
ZegoImageButton::ZegoImageButton(QWidget *parent) : QPushButton(parent)
{
	
}

ZegoImageButton::~ZegoImageButton()
{

}

void ZegoImageButton::setButtonIcon(const QString& iconFileName, QIcon::Mode mode, QIcon::State state)
{
	QIcon icon;
	if (m_dpi < 2.0)
	    iconFilePath = QStringLiteral(":/Resources/images/%1.png").arg(iconFileName);
	else
		iconFilePath = QStringLiteral(":/Resources/images/@2x/%1@2x.png").arg(iconFileName);

	icon.addFile(iconFilePath, QSize(), mode, state);

	QPixmap pixmap;
	pixmap.setDevicePixelRatio(m_dpi);
	icon.addPixmap(pixmap);

	this->setIcon(icon);
	qDebug() << "images " << iconFilePath << " dpi = " << this->devicePixelRatio();
}

void ZegoImageButton::setDPI(qreal dpi)
{
	m_dpi = dpi;
}
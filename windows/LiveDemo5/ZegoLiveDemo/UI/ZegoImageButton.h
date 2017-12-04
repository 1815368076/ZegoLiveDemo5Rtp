#pragma once

#include <QPushButton>
#include <QIcon>
#include <QPixmap>

class ZegoImageButton : public QPushButton
{
public:
	ZegoImageButton(QWidget * parent);
	~ZegoImageButton();

	void setButtonIcon(const QString& iconFileName, QIcon::Mode mode = QIcon::Mode::Normal, QIcon::State state = QIcon::State::Off);
	void setDPI(qreal dpi);

private:
	qreal m_dpi;
	QString iconFilePath;
};
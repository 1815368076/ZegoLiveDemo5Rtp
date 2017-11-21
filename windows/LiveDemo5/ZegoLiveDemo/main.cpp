#pragma execution_character_set("utf-8")

#include "ZegoMainDialog.h"
#include "ZegoLiveDemo.h"
#include <QtWidgets/QApplication>
#include <QSettings>
int main(int argc, char *argv[])
{
	QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
	QApplication app(argc, argv);
	qreal dpi = app.devicePixelRatio();
	ZegoMainDialog w(dpi);
	w.setFixedSize(930, 670);
	w.initDialog();
	w.show();

	return app.exec();
}

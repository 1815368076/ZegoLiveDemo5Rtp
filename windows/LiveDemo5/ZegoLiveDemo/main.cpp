#pragma execution_character_set("utf-8")

#include "ZegoMainDialog.h"
#include "ZegoLiveDemo.h"
#include <QtWidgets/QApplication>
#include <QSettings>

int main(int argc, char *argv[])
{

	QApplication app(argc, argv);
	app.setWindowIcon(QIcon("ZegoLiveDemo.ico"));
	ZegoMainDialog w;
	w.setFixedSize(930, 670);
	w.initDialog();
	w.show();

	return app.exec();
}

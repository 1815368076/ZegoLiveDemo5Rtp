#include "ZegoMainDialog.h"
#include "ZegoLiveDemo.h"
#include <QtWidgets/QApplication>
#include <QSettings>

int main(int argc, char *argv[])
{

	QApplication app(argc, argv);
	app.setWindowIcon(QIcon("ZegoLiveDemo.ico"));
	ZegoMainDialog w;
	w.setFixedSize(930, 606);
	w.initDialog();
	w.show();

	return app.exec();
}

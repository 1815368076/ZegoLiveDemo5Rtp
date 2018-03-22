#include "ZegoMainDialog.h"
#include <QDebug>

ZegoMainDialog::ZegoMainDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.m_bEnterRoom, &QPushButton::clicked, this, &ZegoMainDialog::OnButtonEnterRoom);
	connect(ui.m_bSettings, &QPushButton::clicked, this, &ZegoMainDialog::OnButtonSettings);

	connect(ui.m_bClose, &QPushButton::clicked, this, &ZegoMainDialog::OnButtonClose);
	connect(ui.m_bMin, &QPushButton::clicked, this, &ZegoMainDialog::OnButtonMinimum);
	connect(ui.m_bJumpToNet, &QPushButton::clicked, this, &ZegoMainDialog::OnButtonJumpToNet);

	this->setFixedSize(QSize(655, 250));
	this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏

	ui.m_edRoomID->installEventFilter(this);
}

ZegoMainDialog::~ZegoMainDialog()
{

}

void ZegoMainDialog::initDialog()
{
	//读取用户配置，若不存在则新建配置
	m_userConfig.LoadConfig();

	m_strEdUserId = m_userConfig.GetUserId();
    m_strEdUserName = m_userConfig.getUserName();

	SettingsPtr pCurSettings = m_userConfig.GetVideoSettings();
	if (pCurSettings != nullptr)
	{
		theApp.GetBase().InitAVSDK(pCurSettings, m_strEdUserId, m_strEdUserName);
	}
}

//UI信号槽
void ZegoMainDialog::OnButtonEnterRoom()
{
	QString roomID = ui.m_edRoomID->text();
	if (roomID.isEmpty())
	{
		QMessageBox::warning(NULL, tr("警告"), tr("房间号不能为空"));
		return;
	}

	QString strUserId = m_userConfig.GetUserId();
	QString strUserName = m_userConfig.getUserName();

	if (!LIVEROOM::SetUser(strUserId.toStdString().c_str(), strUserName.toStdString().c_str()))
	{
		QMessageBox::warning(NULL, tr("警告"), tr("用户ID或用户名错误"));
		return;
	}

	RoomPtr pRoom(new QZegoRoomModel(roomID, QString(""), strUserId, strUserName));
	ZegoVideoTalkDialog videotalk(m_userConfig, pRoom, this, m_isVideoCustom);
	videotalk.initDialog();
	this->hide();
	videotalk.exec();
}

void ZegoMainDialog::OnButtonSettings()
{
	ZegoSettingsDialog settings(m_userConfig);
	connect(&settings, &ZegoSettingsDialog::sigReturnConfigToMainDialog, this, &ZegoMainDialog::OnReturnConfigFromSettingsDialog);
	settings.initDialog();
	settings.exec();
}

void ZegoMainDialog::OnReturnConfigFromSettingsDialog(QZegoUserConfig userConfig)
{
	m_userConfig.SetUserId(userConfig.GetUserId());
	m_userConfig.SetUserName(userConfig.getUserName());
	m_userConfig.SetVideoSettings(userConfig.GetVideoSettings());
	m_userConfig.SetVideoQuality(userConfig.GetVideoQuality());
	m_userConfig.setAppVersion(userConfig.getAppVersion());
	
	m_strEdUserId = m_userConfig.GetUserId();
	m_strEdUserName = m_userConfig.getUserName();
}

void ZegoMainDialog::OnButtonClose()
{
	this->close();
}

void ZegoMainDialog::OnButtonMinimum()
{
	this->showMinimized();
}

void ZegoMainDialog::OnButtonJumpToNet()
{
	QDesktopServices::openUrl(QUrl(QLatin1String("https://www.zego.im")));
}

void ZegoMainDialog::mousePressEvent(QMouseEvent *event)
{
	mousePosition = event->pos();
	//只对标题栏范围内的鼠标事件进行处理
	if (mousePosition.x() <= pos_min_x)
		return;
	if (mousePosition.x() >= pos_max_x)
		return;
	if (mousePosition.y() <= pos_min_y)
		return;
	if (mousePosition.y() >= pos_max_y)
		return;
	isMousePressed = true;
}

void ZegoMainDialog::mouseMoveEvent(QMouseEvent *event)
{
	if (isMousePressed == true)
	{
		QPoint movePot = event->globalPos() - mousePosition;
		move(movePot);
	}
}

void ZegoMainDialog::mouseReleaseEvent(QMouseEvent *event)
{
	isMousePressed = false;
}

bool ZegoMainDialog::eventFilter(QObject *target, QEvent *event)
{
	if (target == ui.m_edRoomID) {
		if (event->type() == QEvent::KeyPress) {
			QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
			if (keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return)
			{
				OnButtonEnterRoom();
				return true;
			}
		}
	}

	return QDialog::eventFilter(target, event);
}
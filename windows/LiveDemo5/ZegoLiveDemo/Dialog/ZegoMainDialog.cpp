#include "ZegoMainDialog.h"
#include "ZegoSingleAnchorDialog.h"
#include "ZegoSingleAudienceDialog.h"
#include "ZegoMoreAnchorDialog.h"
#include "ZegoMoreAudienceDialog.h"
#include "ZegoMixStreamAnchorDialog.h"
#include "ZegoMixStreamAudienceDialog.h"
#include <QStyledItemDelegate>
#include "noFocusFrameDelegate.h"
#include "ZegoProgressIndicator.h"
#include <QScrollBar>

ZegoMainDialog::ZegoMainDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	
	connect(ui.m_bMin, &QPushButton::clicked, this, &ZegoMainDialog::OnClickTitleButton);
	connect(ui.m_bClose, &QPushButton::clicked, this, &ZegoMainDialog::OnClickTitleButton);
	connect(ui.m_bJumpToNet, &QPushButton::clicked, this, &ZegoMainDialog::OnClickTitleButton);

	connect(ui.m_bResolutionDown, &QPushButton::clicked, this, &ZegoMainDialog::OnButtonSliderValueChange);
	connect(ui.m_bResolutionUp, &QPushButton::clicked, this, &ZegoMainDialog::OnButtonSliderValueChange);
	connect(ui.m_bBitrateDown, &QPushButton::clicked, this, &ZegoMainDialog::OnButtonSliderValueChange);
	connect(ui.m_bBitrateUp, &QPushButton::clicked, this, &ZegoMainDialog::OnButtonSliderValueChange);
	connect(ui.m_bFPSDown, &QPushButton::clicked, this, &ZegoMainDialog::OnButtonSliderValueChange);
	connect(ui.m_bFPSUp, &QPushButton::clicked, this, &ZegoMainDialog::OnButtonSliderValueChange);

	connect(ui.m_bCreateRoom, &QPushButton::clicked, this, &ZegoMainDialog::OnButtonClickedPublish);
	connect(ui.m_bRefreshRoomList, &QPushButton::clicked, this, &ZegoMainDialog::OnButtonClickedRefresh);
	connect(ui.m_switchTestEnv, &QPushButton::clicked, this, &ZegoMainDialog::OnButtonSwitchTestEnv);
	connect(ui.m_switchCapture, &QPushButton::clicked, this, &ZegoMainDialog::OnButtonSwitchVideoCapture);
	connect(ui.m_switchFilter, &QPushButton::clicked, this, &ZegoMainDialog::OnButtonSwitchVideoFilter);
	connect(ui.m_switchSurfaceMerge, &QPushButton::clicked, this, &ZegoMainDialog::OnButoonSwitchSurfaceMerge);

	connect(ui.m_bUploadLog, &QPushButton::clicked, this, &ZegoMainDialog::OnButtonUploadLog);

	connect(ui.m_strEdUserId, &QLineEdit::textChanged, this, &ZegoMainDialog::OnSaveUserIdChanged);
	connect(ui.m_strEdUserName, &QLineEdit::textChanged, this, &ZegoMainDialog::OnSaveUserNameChanged);

	//设备变更（增删）
	connect(GetAVSignal(), &QZegoAVSignal::sigAudioDeviceChanged, this, &ZegoMainDialog::OnAudioDeviceChanged);
	connect(GetAVSignal(), &QZegoAVSignal::sigVideoDeviceChanged, this, &ZegoMainDialog::OnVideoDeviceChanged);
	//设备变更（改变）
	connect(ui.m_cbMircoPhone, SIGNAL(currentIndexChanged(int)), this, SLOT(OnSwitchAudioDevice(int)));
	connect(ui.m_cbCamera, SIGNAL(currentIndexChanged(int)), this, SLOT(OnSwitchVideoDevice(int)));

	this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏 

	ui.m_edRoomName->installEventFilter(this);
	ui.m_strEdUserId->installEventFilter(this);
	ui.m_strEdUserName->installEventFilter(this);

}

ZegoMainDialog::~ZegoMainDialog()
{
	//释放堆内存
	delete m_modeButtonGroup;
	delete m_qualityButtonGroup;
	delete m_cbMircoPhoneModel;
	delete m_cbCameraModel;
	delete m_roomListModel;
	delete m_cbMircoPhoneListView;
	delete m_cbCameraListView;

	m_roomList.clear();
	theApp.GetBase().UninitAVSDK();
	
}

//part1:功能函数
void ZegoMainDialog::initDialog()
{
	//初始化房间列表
	initRoomList();
	//禁用某些高级功能的按钮
	banSwitch();
	//初始化ComboBox
	initComboBox();
	//将三个模式按钮加入组中
	addModeButtonGroup();
	//将六个视频质量按钮加入组中
	addQualityButtonGroup();

	//从用户配置文件中读取配置信息，若找不到则新建配置文件
	m_userConfig.LoadConfig();

	m_strEdUserId = m_userConfig.GetUserId();
	m_strEdUserName = m_userConfig.GetUserName();

	ui.m_strEdUserId->setText(m_strEdUserId);
	ui.m_strEdUserName->setText(m_strEdUserName);

	//显示用户配置的视频质量
	QPushButton * pButton = (QPushButton *)m_qualityButtonGroup->button(m_userConfig.GetVideoQuality());
	pButton->setChecked(true);
	if (pButton == ui.m_bCustom)
		isVideoCustom = true;
	else
		isVideoCustom = false;

	//高级设置app版本为UDP,RTMP，国际版时，不用设置appid和appsign，默认为UDP
	m_versionMode = 0;

	if (m_versionMode >= 0 && m_versionMode <= 2)
	{
		ui.m_strEdAPPID->setText(QStringLiteral("%1").arg(theApp.GetBase().GetAppID()));
		ui.m_strEdAPPSign->setText(QStringLiteral("demo已设置"));
		ui.m_strEdAPPID->setEnabled(false);
		ui.m_strEdAPPSign->setEnabled(false);
	}

	SettingsPtr pCurSettings = m_userConfig.GetVideoSettings();

	if (pCurSettings != nullptr)
	{
		setDefalutVideoQuality(pCurSettings);
		EnumVideoAndAudioDevice(pCurSettings);

		QString userID = m_userConfig.GetUserId();
		QString userName = m_userConfig.GetUserName();
		theApp.GetBase().InitAVSDK(pCurSettings, userID, userName);

		//是否使用截屏推流,默认不使用
		pCurSettings->SetSurfaceMerge(m_isUseSurfaceMerge);
	}

	//sdk版本号
	ui.m_lbTitleVersion->setText(QStringLiteral("版本: %1").arg(QString(QLatin1String(LIVEROOM::GetSDKVersion()))));
	//pull房间列表
	PullRoomList();

}

void ZegoMainDialog::setDefalutVideoQuality(SettingsPtr curSettings)
{
	
	Size defResolution = curSettings->GetResolution();

	for (int i = 0; i < sizeof(g_Resolution) / sizeof(g_Resolution[0]); ++i)
	{
		QString strResolution;
		strResolution = QString(QStringLiteral("%1×%2")).arg(g_Resolution[i].cx).arg(g_Resolution[i].cy);
		m_vecResolution.push_back(strResolution);

		if (defResolution.cx == g_Resolution[i].cx && defResolution.cy == g_Resolution[i].cy)
		{
			//为了vec的索引值与slider的数组对应，采取反序
			ui.m_sliderResolution->setValue(g_Resolution_length - i);
			ui.m_lbValueResolution->setText(strResolution);
		}
	}

	connect(ui.m_sliderResolution, SIGNAL(valueChanged(int)), this, SLOT(OnSliderValueChange(int)));
	connect(ui.m_sliderResolution, &QSlider::sliderPressed, this, &ZegoMainDialog::OnCheckSliderPressed);
	connect(ui.m_sliderResolution, &QSlider::sliderReleased, this, &ZegoMainDialog::OnCheckSliderReleased);

	int defBitrate = curSettings->GetBitrate();

	for (int i = 0; i < sizeof(g_Bitrate) / sizeof(g_Bitrate[0]); ++i)
	{
		QString strBitrate;
		int m = g_Bitrate[i] / (1000 * 1000);
		strBitrate = QString(QStringLiteral("%1k")).arg(g_Bitrate[i] / 1000);
		m_vecBitrate.push_back(strBitrate);

		if (defBitrate == g_Bitrate[i])
		{
			ui.m_sliderBitrate->setValue(g_Bitrate_length - i);
			ui.m_lbValueBitrate->setText(strBitrate);
		}
	}

	connect(ui.m_sliderBitrate, SIGNAL(valueChanged(int)), this, SLOT(OnSliderValueChange(int)));
	connect(ui.m_sliderBitrate, &QSlider::sliderPressed, this, &ZegoMainDialog::OnCheckSliderPressed);
	connect(ui.m_sliderBitrate, &QSlider::sliderReleased, this, &ZegoMainDialog::OnCheckSliderReleased);

	int defFPS = curSettings->GetFps();

	for (int i = 0; i < sizeof(g_Fps) / sizeof(g_Fps[0]); ++i)
	{
		QString strFPS;
		strFPS = QString(QStringLiteral("%1")).arg(g_Fps[i]);
		m_vecFPS.push_back(strFPS);

		if (defFPS == g_Fps[i])
		{
			ui.m_sliderFPS->setValue(g_FPS_length - i);
			ui.m_lbValueFPS->setText(strFPS);
		}
	}

	connect(ui.m_sliderFPS, SIGNAL(valueChanged(int)), this, SLOT(OnSliderValueChange(int)));
	connect(ui.m_sliderFPS, &QSlider::sliderPressed, this, &ZegoMainDialog::OnCheckSliderPressed);
	connect(ui.m_sliderFPS, &QSlider::sliderReleased, this, &ZegoMainDialog::OnCheckSliderReleased);

}

void ZegoMainDialog::EnumVideoAndAudioDevice(SettingsPtr curSettings)
{
	//设备数
	int nDeviceCount = 0;
	AV::DeviceInfo* pDeviceList(NULL);

	//获取音频设备
	int curSelectionIndex = 0;
	pDeviceList = LIVEROOM::GetAudioDeviceList(AV::AudioDeviceType::AudioDevice_Input, nDeviceCount);
	for (int i = 0; i < nDeviceCount; ++i)
	{
		insertStringListModelItem(m_cbMircoPhoneModel, QString::fromUtf8(pDeviceList[i].szDeviceName), m_cbMircoPhoneModel->rowCount());
		m_vecAudioDeviceIDs.push_back(pDeviceList[i].szDeviceId);

		if (curSettings->GetMircophoneId() == QString(pDeviceList[i].szDeviceId))
			curSelectionIndex = i;
	}

	ui.m_cbMircoPhone->setCurrentIndex(curSelectionIndex);
	LIVEROOM::FreeDeviceList(pDeviceList);

	pDeviceList = NULL;

	//获取视频设备
	curSelectionIndex = 0;
	pDeviceList = LIVEROOM::GetVideoDeviceList(nDeviceCount);
	for (int i = 0; i < nDeviceCount; ++i)
	{
		insertStringListModelItem(m_cbCameraModel, QString::fromUtf8(pDeviceList[i].szDeviceName), m_cbCameraModel->rowCount());
		m_vecVideoDeviceIDs.push_back(pDeviceList[i].szDeviceId);

		if (curSettings->GetCameraId() == QString(pDeviceList[i].szDeviceId))
			curSelectionIndex = i;
	}

	ui.m_cbCamera->setCurrentIndex(curSelectionIndex);
	LIVEROOM::FreeDeviceList(pDeviceList);
	pDeviceList = NULL;
}

void ZegoMainDialog::initRoomList()
{
	
	//初始化model
	m_roomListModel = new QStandardItemModel(this);
	m_roomListModel->setColumnCount(4);

	//表头内容
	m_roomListModel->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("房间名"));
	m_roomListModel->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("直播模式"));
	m_roomListModel->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("连麦人数"));
	m_roomListModel->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("进入"));

	//绑定view和model
	ui.m_roomList->setModel(m_roomListModel);
	//设置列宽不可变
	ui.m_roomList->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
	ui.m_roomList->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
	ui.m_roomList->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
	ui.m_roomList->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
	//设置每列的宽度
	ui.m_roomList->setColumnWidth(0, 310);
	ui.m_roomList->setColumnWidth(1, 100);
	ui.m_roomList->setColumnWidth(2, 110);
	ui.m_roomList->setColumnWidth(3, 110);
	//隐藏列头
	ui.m_roomList->verticalHeader()->setVisible(false);
	//表头内容靠左
	ui.m_roomList->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
	//表头不可点击
	ui.m_roomList->horizontalHeader()->setSectionsClickable(false);
	//设置无边框
	ui.m_roomList->setFrameShape(QFrame::NoFrame);
	//列表内容不可编辑
	ui.m_roomList->setEditTriggers(QAbstractItemView::NoEditTriggers);
	//设置选中时为整行选中        
	ui.m_roomList->setSelectionBehavior(QAbstractItemView::SelectRows);
	//点击item时去除虚线框
	ui.m_roomList->setItemDelegate(new NoFocusFrameDelegate(this));

	ui.m_roomList->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{"
	                                                  "background: transparent;"
                                                      "width: 9px;"
                                                      "margin: 0px 0px 2px 0px;}"
                                                      "QScrollBar::handle:vertical{"
                                                      "background: rgb(195, 195, 195);"
	                                                  "min-height: 20px;"
	                                                  "border-radius: 3px;}"
		                                              "QScrollBar::handle:vertical:hover{"
	                                                  "background:rgba(0, 0, 0, 30%);}"
			                                          "QScrollBar::add-line:vertical{"
		                                              "height: 0px;"
		                                              "subcontrol-position: bottom;"
		                                              "subcontrol-origin: margin; }"
			                                          "QScrollBar::sub-line:vertical{"
		                                              "height: 0px;"
			                                          "subcontrol-position: top;"
			                                          "subcontrol-origin: margin; }");
	
}

void ZegoMainDialog::PullRoomList()
{
	//读取房间列表成功前转菊花
	ui.m_progIndicator->startAnimation();
	//先清空上次的房间列表
	m_roomListModel->removeRows(0, m_roomListModel->rowCount());

	QString cstrBaseUrl;
	if (!m_isUseTestEnv) //非测试环境
	    cstrBaseUrl.sprintf(("https://liveroom%u-api.zego.im/demo/roomlist?appid=%u"), theApp.GetBase().GetAppID(), theApp.GetBase().GetAppID());
	else                 //测试环境
		cstrBaseUrl.sprintf(("https://test2-liveroom-api.zego.im/demo/roomlist?appid=%u"), theApp.GetBase().GetAppID(), theApp.GetBase().GetAppID());

	QUrl url(cstrBaseUrl);

	m_networkManager = new QNetworkAccessManager(this);
	QNetworkRequest *m_networkRequest = new QNetworkRequest;
	m_networkRequest->setUrl(url);

	//建立信号槽，当请求服务器完毕之后，保存房间列表的JSON数据
	connect(m_networkManager, SIGNAL(finished(QNetworkReply *)), this, SLOT(writeJsonData(QNetworkReply *)));

	m_networkManager->get(*m_networkRequest);

}

void ZegoMainDialog::writeJsonData(QNetworkReply *reply)
{
	if (reply->error() == QNetworkReply::NoError){
		json = reply->readAll();

		qDebug() << "json = "<<json;
		//关闭请求
		reply->deleteLater();
	}
	else{
		reply->deleteLater();
	}

	//解析房间列表
	ParseRoomList(json);
}

void ZegoMainDialog::ParseRoomList(QByteArray json)
{
	if (json.size() == 0){ return; }

	QVector<RoomPtr> vRoomList;

	QJsonParseError json_error;
	QJsonDocument doc = QJsonDocument::fromJson(json, &json_error);

	if (json_error.error != QJsonParseError::NoError){ return; }

	if (!doc.isObject()) { return; }

	QJsonObject obj = doc.object();

	if (!obj.contains("code")) { return; }

	QJsonValue code = obj.take("code");

	if (code.toInt() != 0)
	{
		QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("获取房间列表失败"));
		return; 
	}

	if (!obj.contains("data")) { return; }

	QJsonObject data = obj["data"].toObject();

	if (!data.contains("room_list")) { return; }

	QJsonArray valArray = data["room_list"].toArray();


	for (int i = 0; i < valArray.size(); i++)
	{
		QJsonObject room = valArray.at(i).toObject();
		QString strRoomID = room["room_id"].toString();
		QString strRoomName = room["room_name"].toString();
		QString strAnchorID = room["anchor_id_name"].toString();
		QString strAnchorName = room["anchor_nick_name"].toString();

		int nAnchorSize = 0;
		QJsonArray streamInfo = room["stream_info"].toArray();
		nAnchorSize = streamInfo.size();
		//僵尸房间不加载
		if (nAnchorSize != 0){
			RoomPtr pRoom(new QZegoRoomModel(strRoomID, strRoomName, strAnchorID, strAnchorName));
			pRoom->setLivesCount(nAnchorSize);

			vRoomList.push_back(pRoom);
		}
	}

	//在UI界面中显示房间列表
	RefreshRoomList(vRoomList);
}

void ZegoMainDialog::RefreshRoomList(QVector<RoomPtr> roomList)
{

	m_roomList.clear();
	m_roomList = roomList;

	for (size_t index = 0; index < m_roomList.size(); index++)
	{
		//第一列：房间名
		QString strRoomName;
		strRoomName = m_roomList[index]->getRoomName();
		if (strRoomName.size() == 0)
			strRoomName = m_roomList[index]->getRoomId();

		m_roomListModel->setItem(index, 0, new QStandardItem(strRoomName));

		//第二列：直播模式
		QString strLiveMode;
		strLiveMode = m_roomList[index]->getRoomId().mid(0, 3);
		if (strLiveMode == QStringLiteral("#d-"))
		    m_roomListModel->setItem(index, 1, new QStandardItem(QStringLiteral("单主播模式")));
		else if (strLiveMode == QStringLiteral("#m-"))
			m_roomListModel->setItem(index, 1, new QStandardItem(QStringLiteral("连麦模式")));
		else if (strLiveMode == QStringLiteral("#s-"))
			m_roomListModel->setItem(index, 1, new QStandardItem(QStringLiteral("混流模式")));
		else if (strLiveMode == QStringLiteral("#g-"))
			m_roomListModel->setItem(index, 1, new QStandardItem(QStringLiteral("游戏模式")));
		else if (strLiveMode == QStringLiteral("#i-"))
			m_roomListModel->setItem(index, 1, new QStandardItem(QStringLiteral("狼人杀模式")));
		else
			m_roomListModel->setItem(index, 1, new QStandardItem(QStringLiteral("-")));

		//第三列：连麦人数
		QString strDetail(QStringLiteral("-"));
		unsigned int uLivesCount = m_roomList[index]->getLivesCount();

		if (uLivesCount != 0)
			strDetail = QString(QStringLiteral("%1人正在连麦")).arg(m_roomList[index]->getLivesCount());

		m_roomListModel->setItem(index, 2, new QStandardItem(strDetail));

		//第四列：进入按钮
		QPushButton *pBtn = new QPushButton();
		pBtn->setText(QStringLiteral("进入"));
		QFile qssFile("Resources/EnterButton.qss");
		qssFile.open(QFile::ReadOnly);
		if (qssFile.isOpen()){
			pBtn->setStyleSheet(qssFile.readAll());
			qssFile.close();
		}

		connect(pBtn, &QPushButton::clicked, this, &ZegoMainDialog::OnButtonEnterRoom);
		QModelIndex indexTmp = m_roomListModel->index(index, 3, QModelIndex());
		ui.m_roomList->setIndexWidget(indexTmp, pBtn);
		
	}
	//停止转菊花
	ui.m_progIndicator->stopAnimation();
}

void ZegoMainDialog::addModeButtonGroup()
{
	m_modeButtonGroup = new QButtonGroup(this);
	m_modeButtonGroup->addButton(ui.m_bSingleMode, 0);
	m_modeButtonGroup->addButton(ui.m_bMultiMode, 1);
	m_modeButtonGroup->addButton(ui.m_bMixMode, 2);
	
	//默认为单主播模式
	ui.m_bSingleMode->setChecked(true);
	m_curMode = LIVEROOM::ZEGO_SINGLE_ANCHOR;

	connect(m_modeButtonGroup, SIGNAL(buttonClicked(int)), this, SLOT(OnButtonModeSheetChange(int)));
}

void ZegoMainDialog::addQualityButtonGroup()
{
	m_qualityButtonGroup = new QButtonGroup(this);
	m_qualityButtonGroup->addButton(ui.m_bSuperLow, 0);
	m_qualityButtonGroup->addButton(ui.m_bLow, 1);
	m_qualityButtonGroup->addButton(ui.m_bStandard, 2);
	m_qualityButtonGroup->addButton(ui.m_bHigh, 3);
	m_qualityButtonGroup->addButton(ui.m_bSuperHigh, 4);
	m_qualityButtonGroup->addButton(ui.m_bExtremelyHigh, 5);
	m_qualityButtonGroup->addButton(ui.m_bCustom, 6);

	connect(m_qualityButtonGroup, SIGNAL(buttonClicked(int)), this, SLOT(OnButtonQualityChange(int)));
}

void ZegoMainDialog::initComboBox()
{
	
	m_cbMircoPhoneModel = new QStringListModel(this);
	
	m_cbMircoPhoneModel->setStringList(m_MircoPhoneList);

	m_cbMircoPhoneListView = new QListView(this);
	ui.m_cbMircoPhone->setView(m_cbMircoPhoneListView);
	ui.m_cbMircoPhone->setModel(m_cbMircoPhoneModel);
	ui.m_cbMircoPhone->setItemDelegate(new NoFocusFrameDelegate(this));

	m_cbCameraModel = new QStringListModel(this);
	
	m_cbCameraModel->setStringList(m_CameraList);

	m_cbCameraListView = new QListView(this);
	ui.m_cbCamera->setView(m_cbCameraListView);
	ui.m_cbCamera->setModel(m_cbCameraModel);
	ui.m_cbCamera->setItemDelegate(new NoFocusFrameDelegate(this));

	
}

void ZegoMainDialog::insertStringListModelItem(QStringListModel * model, QString name, int size)
{
	int row = size;
	model->insertRows(row, 1);
	QModelIndex index = model->index(row);
	model->setData(index,name);
}

void ZegoMainDialog::removeStringListModelItem(QStringListModel * model, QString name)
{
	if (model->rowCount() > 0)
	{
		int curIndex = -1;
		QStringList list = model->stringList();
		for (int i = 0; i < list.size(); i++)
		{
			if (list[i] == name)
				curIndex = i;
		}

		model->removeRows(curIndex, 1);
	}
}

void ZegoMainDialog::banSwitch()
{
	//以后功能开放了再取消禁用
	ui.m_switchCapture->setEnabled(false);
	ui.m_switchFilter->setEnabled(false);
	ui.m_switchAutoBitrate->setEnabled(false);
	ui.m_switchHardCode->setEnabled(false);
	ui.m_switchHardDecode->setEnabled(false);
	ui.m_switchMicAudio->setEnabled(false);
	ui.m_switchNational->setEnabled(false);
	ui.m_switchRender->setEnabled(false);
	ui.m_switchTimeCount->setEnabled(false);
}

//part2:SDK回调函数
void ZegoMainDialog::OnAudioDeviceChanged(AV::AudioDeviceType deviceType, const QString& strDeviceId, const QString& strDeviceName, AV::DeviceState state)
{
	if (deviceType == AV::AudioDeviceType::AudioDevice_Output)
		return;

	if (state == AV::DeviceState::Device_Added)
	{
		insertStringListModelItem(m_cbMircoPhoneModel, strDeviceName, m_cbMircoPhoneModel->rowCount());
		m_vecAudioDeviceIDs.push_back(strDeviceId);
		if (m_vecAudioDeviceIDs.size() == 1)
		{
			LIVEROOM::SetAudioDevice(AV::AudioDevice_Input, m_vecAudioDeviceIDs[0].toStdString().c_str());
			SettingsPtr curSettings = m_userConfig.GetVideoSettings();
			curSettings->SetMicrophoneId(m_vecAudioDeviceIDs[0]);
			m_userConfig.SetVideoSettings(curSettings);
			ui.m_cbMircoPhone->setCurrentIndex(0);
		}
		update();
	}
	else if (state == AV::DeviceState::Device_Deleted)
	{
		for (int i = 0; i < m_vecAudioDeviceIDs.size(); i++)
		{
			if (m_vecAudioDeviceIDs[i] != strDeviceId)
				continue;

			m_vecAudioDeviceIDs.erase(m_vecAudioDeviceIDs.begin() + i);


			int currentCurl = ui.m_cbMircoPhone->currentIndex();
			//如果currentCurl等于i说明当前删除的设备是当前正在使用的设备
			if (currentCurl == i)
			{
				//如果删除之后还有能播放的设备存在，则默认选择第一个音频设备
				if (m_vecAudioDeviceIDs.size() > 0)
				{
					LIVEROOM::SetAudioDevice(AV::AudioDevice_Input, m_vecAudioDeviceIDs[0].toStdString().c_str());
					SettingsPtr curSettings = m_userConfig.GetVideoSettings();
					curSettings->SetMicrophoneId(m_vecAudioDeviceIDs[0]);
					m_userConfig.SetVideoSettings(curSettings);
					ui.m_cbMircoPhone->setCurrentIndex(0);

				}
				else
				{
					LIVEROOM::SetAudioDevice(AV::AudioDevice_Input, NULL);
					SettingsPtr curSettings = m_userConfig.GetVideoSettings();
					curSettings->SetMicrophoneId("");
					m_userConfig.SetVideoSettings(curSettings);
				}
				removeStringListModelItem(m_cbMircoPhoneModel, strDeviceName);
				update();
				break;
			}


		}
	}

}

void ZegoMainDialog::OnVideoDeviceChanged(const QString& strDeviceId, const QString& strDeviceName, AV::DeviceState state)
{
	if (state == AV::DeviceState::Device_Added)
	{
		insertStringListModelItem(m_cbCameraModel, strDeviceName, m_cbCameraModel->rowCount());
		m_vecVideoDeviceIDs.push_back(strDeviceId);
		if (m_vecVideoDeviceIDs.size() == 1)
		{
			LIVEROOM::SetVideoDevice(m_vecVideoDeviceIDs[0].toStdString().c_str());
			SettingsPtr curSettings = m_userConfig.GetVideoSettings();
			curSettings->SetCameraId(m_vecVideoDeviceIDs[0]);
			m_userConfig.SetVideoSettings(curSettings);
			ui.m_cbCamera->setCurrentIndex(0);
		}
		update();
	}
	else if (state == AV::DeviceState::Device_Deleted)
	{
		for (int i = 0; i < m_vecVideoDeviceIDs.size(); i++)
		{
			if (m_vecVideoDeviceIDs[i] != strDeviceId)
				continue;

			m_vecVideoDeviceIDs.erase(m_vecVideoDeviceIDs.begin() + i);

			int currentCurl = ui.m_cbCamera->currentIndex();
			//如果currentCurl等于i说明当前删除的设备是当前正在使用的设备
			if (currentCurl == i)
			{
				//默认采集第一个视频设备
				if (m_vecVideoDeviceIDs.size() > 0)
				{
					LIVEROOM::SetVideoDevice(m_vecVideoDeviceIDs[0].toStdString().c_str());
					SettingsPtr curSettings = m_userConfig.GetVideoSettings();
					curSettings->SetCameraId(m_vecAudioDeviceIDs[0]);
					m_userConfig.SetVideoSettings(curSettings);
					ui.m_cbCamera->setCurrentIndex(0);
				}
				else
				{
					LIVEROOM::SetVideoDevice(NULL);
					SettingsPtr curSettings = m_userConfig.GetVideoSettings();
					curSettings->SetCameraId("");
					m_userConfig.SetVideoSettings(curSettings);
				}

			}
			removeStringListModelItem(m_cbCameraModel, strDeviceName);
			update();

			break;
		}
	}
}

//part3:UI回调函数
void ZegoMainDialog::OnButtonModeSheetChange(int id)
{
	QPushButton *button = (QPushButton *)m_modeButtonGroup->button(id);

	if (button->isChecked())
	{
		
		qDebug() << "Modebutton"<< id <<"checked";
		if (id == 0)
			m_curMode = LIVEROOM::ZEGO_SINGLE_ANCHOR;
		else if (id == 1)
			m_curMode = LIVEROOM::ZEGO_JOIN_PUBLISH;
		else if (id == 2)
			m_curMode = LIVEROOM::ZEGO_MIX_STREAM;
		
	}
	
}

void ZegoMainDialog::OnButtonQualityChange(int id)
{
	QPushButton *button = (QPushButton *)m_qualityButtonGroup->button(id);
	
	if (button->isChecked() && (id == VQ_SelfDef))
	{
		//isVideoCustom = true;
		qDebug() << "Qualitybutton" << id << "checked";
		//changeSliderState(true);
	}
	else if (button->isChecked())
	{
		qDebug() << "Qualitybutton" << id << "checked";
		isVideoCustom = false;
		//changeSliderState(false);
		m_userConfig.SetVideoQuality((VideoQuality)id);

		SettingsPtr curSettings = m_userConfig.GetVideoSettings();
		IndexSet index = curSettings->getIndex();

		ui.m_lbValueResolution->setText(m_vecResolution[index.indexResolution]);
		ui.m_lbValueBitrate->setText(m_vecBitrate[index.indexBitrate]);
		ui.m_lbValueFPS->setText(m_vecFPS[index.indexFps]);

		ui.m_sliderResolution->setValue(g_Resolution_length - index.indexResolution);
		ui.m_sliderBitrate->setValue(g_Bitrate_length - index.indexBitrate);
		ui.m_sliderFPS->setValue(g_FPS_length - index.indexFps);

		m_userConfig.SaveConfig();

	}
	
}

void ZegoMainDialog::OnClickTitleButton()
{
	QPushButton *pButton = qobject_cast<QPushButton *>(sender());

	if (pButton == ui.m_bMin)
	{
		this->showMinimized();
	}
	else if (pButton == ui.m_bClose)
	{
		close();
	}
	else if (pButton == ui.m_bJumpToNet)
	{
		QDesktopServices::openUrl(QUrl(QLatin1String("https://www.zego.im")));
	}
}

void ZegoMainDialog::OnSliderValueChange(int value)
{
	//每次slider改变时将当前视频质量改为“自定义”，同时将每次改动写入ini文件中

	QSlider *slider = qobject_cast<QSlider *>(sender());

	if (!isVideoCustom && m_sliderPressed)
	{
		isVideoCustom = true;
		ui.m_bCustom->setChecked(true);
	}

	SettingsPtr curSettings = m_userConfig.GetVideoSettings();
	if (slider == ui.m_sliderResolution)
	{
		slider->setValue(value);
		ui.m_lbValueResolution->setText(m_vecResolution[g_Resolution_length - value]);
		curSettings->SetResolution(g_Resolution[g_Resolution_length - value]);
	}
	else if (slider == ui.m_sliderBitrate)
	{
		slider->setValue(value);
		ui.m_lbValueBitrate->setText(m_vecBitrate[g_Bitrate_length - value]);
		curSettings->SetBitrate(g_Bitrate[g_Bitrate_length - value]);
	}
	else if (slider == ui.m_sliderFPS)
	{
		slider->setValue(value);
		ui.m_lbValueFPS->setText(m_vecFPS[g_FPS_length - value]);
		curSettings->SetFps(g_Fps[g_FPS_length - value]);
	}

	m_userConfig.SetVideoSettings(curSettings);
	m_userConfig.SaveConfig();
}

void ZegoMainDialog::OnButtonSliderValueChange()
{
	//每次增减视频参数时将当前视频质量改为“自定义”，同时将每次改动写入ini文件中
	if (!isVideoCustom)
	{
		isVideoCustom = true;
		ui.m_bCustom->setChecked(true);
	}

	QPushButton *button = qobject_cast<QPushButton *>(sender());

	SettingsPtr curSettings = m_userConfig.GetVideoSettings();

	if (button == ui.m_bResolutionDown)
	{
		int curValue = ui.m_sliderResolution->value() - 1;
		if (curValue >= 0){
			ui.m_sliderResolution->setValue(curValue);
			ui.m_lbValueResolution->setText(m_vecResolution[g_Resolution_length - curValue]);
			curSettings->SetResolution(g_Resolution[g_Resolution_length - curValue]);

			m_userConfig.SetVideoSettings(curSettings);
			m_userConfig.SaveConfig();
		}

	}
	else if (button == ui.m_bResolutionUp)
	{
		int curValue = ui.m_sliderResolution->value() + 1;
		if (curValue <= g_Resolution_length){
			ui.m_sliderResolution->setValue(curValue);
			ui.m_lbValueResolution->setText(m_vecResolution[g_Resolution_length - curValue]);
			curSettings->SetResolution(g_Resolution[g_Resolution_length - curValue]);

			m_userConfig.SetVideoSettings(curSettings);
			m_userConfig.SaveConfig();
		}
	}
	else if (button == ui.m_bBitrateDown)
	{
		int curValue = ui.m_sliderBitrate->value() - 1;
		if (curValue >= 0){
			ui.m_sliderBitrate->setValue(curValue);
			ui.m_lbValueBitrate->setText(m_vecBitrate[g_Bitrate_length - curValue]);
			curSettings->SetBitrate(g_Bitrate[g_Bitrate_length - curValue]);

			m_userConfig.SetVideoSettings(curSettings);
			m_userConfig.SaveConfig();
		}
	}
	else if (button == ui.m_bBitrateUp)
	{
		int curValue = ui.m_sliderBitrate->value() + 1;
		if (curValue <= g_Bitrate_length){
			ui.m_sliderBitrate->setValue(curValue);
			ui.m_lbValueBitrate->setText(m_vecBitrate[g_Bitrate_length - curValue]);
			curSettings->SetBitrate(g_Bitrate[g_Bitrate_length - curValue]);

			m_userConfig.SetVideoSettings(curSettings);
			m_userConfig.SaveConfig();
		}
	}
	else if (button == ui.m_bFPSDown)
	{
		int curValue = ui.m_sliderFPS->value() - 1;
		if (curValue >= 0)
		{
			ui.m_sliderFPS->setValue(curValue);
			ui.m_lbValueFPS->setText(m_vecFPS[g_FPS_length - curValue]);
			curSettings->SetFps(g_Fps[g_FPS_length - curValue]);

			m_userConfig.SetVideoSettings(curSettings);
			m_userConfig.SaveConfig();
		}
	}
	else if (button == ui.m_bFPSUp)
	{
		int curValue = ui.m_sliderFPS->value() + 1;
		if (curValue <= g_FPS_length)
		{
			ui.m_sliderFPS->setValue(curValue);
			ui.m_lbValueFPS->setText(m_vecFPS[g_FPS_length - curValue]);
			curSettings->SetFps(g_Fps[g_FPS_length - curValue]);

			m_userConfig.SetVideoSettings(curSettings);
			m_userConfig.SaveConfig();
		}
	}
}

void ZegoMainDialog::OnButtonClickedRefresh()
{
	PullRoomList();
}

void ZegoMainDialog::OnButtonClickedPublish()
{
	if (m_strEdUserId.isEmpty() || m_strEdUserName.isEmpty())
	{
		QMessageBox::warning(NULL, QStringLiteral("警告"), QStringLiteral("UserID或UserName不能为空"));
		return;
	}

	m_userConfig.SetUserRole(true);
	m_userConfig.SetUserId(m_strEdUserId);
	m_userConfig.SetUserName(m_strEdUserName);

	QString strUserId = m_userConfig.GetUserId();
	QString strUserName = m_userConfig.GetUserName();
	//更新用户信息
	LIVEROOM::SetUser(strUserId.toStdString().c_str(), strUserName.toStdString().c_str());

	SettingsPtr pCurSettings = m_userConfig.GetVideoSettings();
	if (pCurSettings == nullptr)
	{
		return;
	}

	if (pCurSettings->GetCameraId().length() == 0)
		pCurSettings->InitDeviceId();

	QString strMode;
	switch (m_curMode)
	{
	case LIVEROOM::ZEGO_SINGLE_ANCHOR:
		strMode = QStringLiteral("#d");
		break;
	case LIVEROOM::ZEGO_JOIN_PUBLISH:
		strMode = QStringLiteral("#m");
		break;
	case LIVEROOM::ZEGO_MIX_STREAM:
		strMode = QStringLiteral("#s");
		break;
	default:
		break;
	}

	QTime currentTime = QTime::currentTime();
	//获取当前时间的毫秒
	int ms = currentTime.msec();

	QString strRoomID = QString(QStringLiteral("%1-%2-%3")).arg(strMode).arg(m_userConfig.GetUserId()).arg(ms);
	QString strRoomName = QStringLiteral("windows-room-") + strUserId;

	QString inputRoomName = ui.m_edRoomName->text();
	if (!inputRoomName.isEmpty())
	{
		strRoomName = inputRoomName;
		ui.m_edRoomName->setText(QString(QStringLiteral("")));
	}

	qDebug() << "userId = " << strUserId << "  userName = " << strUserName << "  roomID = " << strRoomID << "  roomName = " << strRoomName;
	RoomPtr pRoom(new QZegoRoomModel(strRoomID, strRoomName, strUserId, strUserName));
	if (m_curMode == LIVEROOM::ZEGO_SINGLE_ANCHOR)
	{
		ZegoSingleAnchorDialog liveroom(pCurSettings, pRoom, strUserId, strUserName, this);
		liveroom.initDialog();
		connect(&liveroom, &ZegoSingleAnchorDialog::sigSaveVideoSettings, this, &ZegoMainDialog::OnSaveVideoSettings);

		//进入直播房间前先隐藏该界面
		this->hide();
		liveroom.exec();
	}
	else if (m_curMode == LIVEROOM::ZEGO_JOIN_PUBLISH)
	{
		ZegoMoreAnchorDialog liveroom(pCurSettings, pRoom, strUserId, strUserName, this);
		liveroom.initDialog();
		connect(&liveroom, &ZegoMoreAnchorDialog::sigSaveVideoSettings, this, &ZegoMainDialog::OnSaveVideoSettings);

		//进入直播房间前先隐藏该界面
		this->hide();
		liveroom.exec();
	}
	else if (m_curMode == LIVEROOM::ZEGO_MIX_STREAM)
	{
		ZegoMixStreamAnchorDialog liveroom(pCurSettings, pRoom, strUserId, strUserName, this);
		liveroom.initDialog();
		connect(&liveroom, &ZegoMixStreamAnchorDialog::sigSaveVideoSettings, this, &ZegoMainDialog::OnSaveVideoSettings);

		//进入直播房间前先隐藏该界面
		this->hide();
		liveroom.exec();
	}
}

void ZegoMainDialog::OnButtonEnterRoom()
{
	QPushButton *pButton = qobject_cast<QPushButton *>(sender());

	int row;
	for (int i = 0; i < m_roomList.size(); i++){
		QModelIndex index = m_roomListModel->index(i, 3, QModelIndex());
		if ((QPushButton*)ui.m_roomList->indexWidget(index) == pButton)
			row = i;
	}

	qDebug() << "this is row " << row;
	int roomIndex = row;

	RoomPtr pRoom = m_roomList[roomIndex];

	if (m_strEdUserId.isEmpty() || m_strEdUserName.isEmpty())
	{
		QMessageBox::warning(NULL, QStringLiteral("警告"), QStringLiteral("UserID或UserName不能为空"));
		return;
	}

	QString playLiveMode = pRoom->getRoomId().mid(0, 3);
	if (playLiveMode == QStringLiteral("#d-"))
		m_curMode = LIVEROOM::ZEGO_SINGLE_ANCHOR;
	else if (playLiveMode == QStringLiteral("#m-"))
		m_curMode = LIVEROOM::ZEGO_JOIN_PUBLISH;
	else if (playLiveMode == QStringLiteral("#s-"))
		m_curMode = LIVEROOM::ZEGO_MIX_STREAM;

	m_userConfig.SetUserRole(false);
	m_userConfig.SetUserId(m_strEdUserId);
	m_userConfig.SetUserName(m_strEdUserName);
	

	QString strUserId = m_userConfig.GetUserId();
	QString strUserName = m_userConfig.GetUserName();

	//更新用户信息
	LIVEROOM::SetUser(strUserId.toStdString().c_str(), strUserName.toStdString().c_str());

	SettingsPtr pCurSettings = m_userConfig.GetVideoSettings();

	if (pCurSettings == nullptr)
	{
		return;
	}

	m_userConfig.SaveConfig();

	if (m_curMode == LIVEROOM::ZEGO_SINGLE_ANCHOR)
	{
		ZegoSingleAudienceDialog liveroom(pCurSettings, pRoom, strUserId, strUserName, this);
		liveroom.initDialog();
		connect(&liveroom, &ZegoSingleAudienceDialog::sigSaveVideoSettings, this, &ZegoMainDialog::OnSaveVideoSettings);

		//进入直播房间前先隐藏该界面
		this->hide();
		liveroom.exec();
	}
	else if (m_curMode == LIVEROOM::ZEGO_JOIN_PUBLISH)
	{
		ZegoMoreAudienceDialog liveroom(pCurSettings, pRoom, strUserId, strUserName, this);
		liveroom.initDialog();
		connect(&liveroom, &ZegoMoreAudienceDialog::sigSaveVideoSettings, this, &ZegoMainDialog::OnSaveVideoSettings);

		//进入直播房间前先隐藏该界面
		this->hide();
		liveroom.exec();
	}
	else if (m_curMode == LIVEROOM::ZEGO_MIX_STREAM)
	{
		ZegoMixStreamAudienceDialog liveroom(pCurSettings, pRoom, strUserId, strUserName, this);
		liveroom.initDialog();
		connect(&liveroom, &ZegoMixStreamAudienceDialog::sigSaveVideoSettings, this, &ZegoMainDialog::OnSaveVideoSettings);

		//进入直播房间前先隐藏该界面
		this->hide();
		liveroom.exec();
	}
}

void ZegoMainDialog::OnButtonSwitchTestEnv()
{
	if (ui.m_switchTestEnv->isChecked())
	{
		qDebug() << "TestEnv checked!";
		m_isUseTestEnv = true;
	
	}
	else
	{
		qDebug() << "TestEnv unChecked!";
		m_isUseTestEnv = false;
		
	}

	ui.m_switchTestEnv->setEnabled(false);
	theApp.GetBase().setTestEnv(m_isUseTestEnv);
	theApp.GetBase().UninitAVSDK();
	theApp.GetBase().InitAVSDK(m_userConfig.GetVideoSettings(), m_strEdUserId, m_strEdUserName);
	ui.m_switchTestEnv->setEnabled(true);
	//当开启/关闭了测试环境时，其房间列表需要马上刷新一次，因为在两个环境下拉取房间列表不一样，避免出错
	PullRoomList();
}

void ZegoMainDialog::OnButtonSwitchVideoCapture()
{
	if (ui.m_switchCapture->isChecked())
	{
		qDebug() << "VideoCapture checked!";
		m_isUseVideoCapture = true;

	}
	else
	{
		qDebug() << "VideoCapture unChecked!";
		m_isUseVideoCapture = false;

	}

	ui.m_switchCapture->setEnabled(false);
	theApp.GetBase().setUseVideoCapture(m_isUseVideoCapture);
	theApp.GetBase().UninitAVSDK();
	theApp.GetBase().InitAVSDK(m_userConfig.GetVideoSettings(), m_strEdUserId, m_strEdUserName);
	ui.m_switchCapture->setEnabled(true);
}

void ZegoMainDialog::OnButtonSwitchVideoFilter()
{
	if (ui.m_switchFilter->isChecked())
	{
		qDebug() << "VideoFilter checked!";
		m_isUseVideoFilter = true;

	}
	else
	{
		qDebug() << "VideoFilter unChecked!";
		m_isUseVideoFilter = false;

	}

	ui.m_switchFilter->setEnabled(false);
	theApp.GetBase().setUseVideoFilter(m_isUseVideoFilter);
	theApp.GetBase().UninitAVSDK();
	theApp.GetBase().InitAVSDK(m_userConfig.GetVideoSettings(), m_strEdUserId, m_strEdUserName);
	ui.m_switchFilter->setEnabled(true);
}

void ZegoMainDialog::OnButoonSwitchSurfaceMerge()
{
	if (ui.m_switchSurfaceMerge->isChecked())
	{
		qDebug() << "SurfaceMerge checked!";
		m_isUseSurfaceMerge = true;

	}
	else
	{
		qDebug() << "SurfaceMerge unChecked!";
		m_isUseSurfaceMerge = false;

	}

	if (m_isUseSurfaceMerge)
	{
		ui.m_bMultiMode->setEnabled(false);
		ui.m_bMixMode->setEnabled(false);

		//只有单主播模式下可以开启屏幕推流
		if (!(m_curMode == LIVEROOM::ZEGO_SINGLE_ANCHOR))
		{
			ui.m_bMultiMode->setChecked(false);
			ui.m_bMixMode->setChecked(false);
			ui.m_bSingleMode->setChecked(true);
			m_curMode = LIVEROOM::ZEGO_SINGLE_ANCHOR;

		}
	}
	else
	{
		//恢复模式按钮
		ui.m_bMultiMode->setEnabled(true);
		ui.m_bMixMode->setEnabled(true);
	}

	ui.m_switchSurfaceMerge->setEnabled(false);
	theApp.GetBase().UninitAVSDK();
	theApp.GetBase().setUseSurfaceMerge(m_isUseSurfaceMerge);

	SettingsPtr curSettings = m_userConfig.GetVideoSettings();
	curSettings->SetSurfaceMerge(m_isUseSurfaceMerge);
	m_userConfig.SetVideoSettings(curSettings);

	theApp.GetBase().InitAVSDK(m_userConfig.GetVideoSettings(), m_strEdUserId, m_strEdUserName);
	ui.m_switchSurfaceMerge->setEnabled(true);
}

void ZegoMainDialog::OnCheckSliderPressed()
{
	m_sliderPressed = true;
}

void ZegoMainDialog::OnCheckSliderReleased()
{
	m_sliderPressed = false;
}

void ZegoMainDialog::OnSaveUserIdChanged()
{
	m_strEdUserId = ui.m_strEdUserId->text();
	m_userConfig.SetUserId(m_strEdUserId);
	m_userConfig.SaveConfig();
}

void ZegoMainDialog::OnSaveUserNameChanged()
{
	m_strEdUserName = ui.m_strEdUserName->text();
	m_userConfig.SetUserName(m_strEdUserName);
	m_userConfig.SaveConfig();
}

void ZegoMainDialog::OnSwitchAudioDevice(int id)
{
	qDebug() << "current audio id = " << id;
	if (id < m_vecAudioDeviceIDs.size())
	{
		LIVEROOM::SetAudioDevice(AV::AudioDevice_Input, m_vecAudioDeviceIDs[id].toStdString().c_str());
		SettingsPtr curSettings = m_userConfig.GetVideoSettings();
		curSettings->SetMicrophoneId(m_vecAudioDeviceIDs[id]);
		m_userConfig.SetVideoSettings(curSettings);
		ui.m_cbMircoPhone->setCurrentIndex(id);
		update();
	}
}

void ZegoMainDialog::OnSwitchVideoDevice(int id)
{
	qDebug() << "current video id = " << id;
	if (id < m_vecVideoDeviceIDs.size())
	{
		LIVEROOM::SetVideoDevice(m_vecVideoDeviceIDs[id].toStdString().c_str());
		SettingsPtr curSettings = m_userConfig.GetVideoSettings();
		curSettings->SetCameraId(m_vecVideoDeviceIDs[id]);
		m_userConfig.SetVideoSettings(curSettings);
		ui.m_cbCamera->setCurrentIndex(id);
		update();
	}
}

void ZegoMainDialog::OnSaveVideoSettings(SettingsPtr settings)
{
	qDebug() << "after change video device id = " << settings->GetCameraId();
	//是否更改了麦克风
	
	int index = 0;
	for (int i = 0; i < m_vecAudioDeviceIDs.size(); i++)
		if (m_vecAudioDeviceIDs[i] == settings->GetMircophoneId())
		{
			index = i;
		    break;
		}
		
	ui.m_cbMircoPhone->setCurrentIndex(index);
		
	//是否更改了摄像头
	index = 0;
	for (int i = 0; i < m_vecVideoDeviceIDs.size(); i++)
	{
		if (m_vecVideoDeviceIDs[i] == settings->GetCameraId())
		{
			index = i;
			break;
		}
	}
	
	ui.m_cbCamera->setCurrentIndex(index);
}

void ZegoMainDialog::OnButtonUploadLog()
{
	LIVEROOM::UploadLog();
	QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("日志上传成功"));
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
	if (target == ui.m_edRoomName) {
		if (event->type() == QEvent::KeyPress) {
			QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
			if (keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return) 
			{
				OnButtonClickedPublish();
				return true;
			}
		}
	}
	else if (target == ui.m_strEdUserId){
		if (event->type() == QEvent::KeyPress) {
			QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
			if (keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return)
			{
				ui.m_strEdUserId->clearFocus();
				return true;
			}
			else if (keyEvent->key() == Qt::Key_Tab)
			{
				ui.m_strEdUserId->clearFocus();
				ui.m_strEdUserName->setFocus();
				return true;
			}
		}
	}
	else if (target == ui.m_strEdUserName){
		if (event->type() == QEvent::KeyPress) {
			QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
			if (keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Tab){
				ui.m_strEdUserName->clearFocus();
				return true;
			}
		}
	}
	else if (target == ui.m_strEdAPPID){
		if (event->type() == QEvent::KeyPress) {
			QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
			if (keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return)
			{
				ui.m_strEdAPPID->clearFocus();
				return true;
			}
			else if (keyEvent->key() == Qt::Key_Tab)
			{
				ui.m_strEdAPPID->clearFocus();
				ui.m_strEdAPPSign->setFocus();
				return true;
			}
		}
	}
	else if (target == ui.m_strEdAPPSign){
		if (event->type() == QEvent::KeyPress) {
			QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
			if (keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Tab){
				ui.m_strEdAPPSign->clearFocus();
				return true;
			}
		}
	}

	return QDialog::eventFilter(target, event);
}

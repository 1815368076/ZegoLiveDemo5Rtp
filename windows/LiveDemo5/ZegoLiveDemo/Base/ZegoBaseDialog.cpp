﻿#include "ZegoBaseDialog.h"
#include "Signal/ZegoSDKSignal.h"
#ifdef Q_OS_MAC
#include "OSX_Objective-C/ZegoAVDevice.h"
#include "OSX_Objective-C/ZegoCGImageToQImage.h"
#endif
ZegoBaseDialog::ZegoBaseDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	//UI的信号槽
	connect(ui.m_bMin, &QPushButton::clicked, this, &ZegoBaseDialog::OnClickTitleButton);
	connect(ui.m_bMax, &QPushButton::clicked, this, &ZegoBaseDialog::OnClickTitleButton);
	connect(ui.m_bClose, &QPushButton::clicked, this, &ZegoBaseDialog::OnClickTitleButton);
}

ZegoBaseDialog::ZegoBaseDialog(qreal dpi, SettingsPtr curSettings, RoomPtr room, QString curUserID, QString curUserName, QDialog *lastDialog, bool isPublish2Stream, QDialog *parent)
	:m_dpi(dpi),
	m_pAVSettings(curSettings),
	m_pChatRoom(room),
	m_strCurUserID(curUserID),
	m_strCurUserName(curUserName),
	m_bCKEnableMic(true),
	m_bCKEnableSpeaker(true),
	m_isPublish2StreamMode(isPublish2Stream),
	m_lastDialog(lastDialog)
{
	ui.setupUi(this);


	//通过sdk的信号连接到本类的槽函数中
	connect(GetAVSignal(), &QZegoAVSignal::sigDisconnect, this, &ZegoBaseDialog::OnDisconnect);
	connect(GetAVSignal(), &QZegoAVSignal::sigKickOut, this, &ZegoBaseDialog::OnKickOut);
	connect(GetAVSignal(), &QZegoAVSignal::sigPublishQualityUpdate, this, &ZegoBaseDialog::OnPublishQualityUpdate);
	connect(GetAVSignal(), &QZegoAVSignal::sigPlayQualityUpdate, this, &ZegoBaseDialog::OnPlayQualityUpdate);
	connect(GetAVSignal(), &QZegoAVSignal::sigSendRoomMessage, this, &ZegoBaseDialog::OnSendRoomMessage);
	connect(GetAVSignal(), &QZegoAVSignal::sigRecvRoomMessage, this, &ZegoBaseDialog::OnRecvRoomMessage);
	connect(GetAVSignal(), &QZegoAVSignal::sigUserUpdate, this, &ZegoBaseDialog::OnUserUpdate);
	connect(GetAVSignal(), &QZegoAVSignal::sigAudioDeviceChanged, this, &ZegoBaseDialog::OnAudioDeviceChanged);
	connect(GetAVSignal(), &QZegoAVSignal::sigVideoDeviceChanged, this, &ZegoBaseDialog::OnVideoDeviceChanged);
	//信号与槽同步执行
	connect(GetAVSignal(), &QZegoAVSignal::sigAuxInput, this, &ZegoBaseDialog::OnAVAuxInput, Qt::DirectConnection);
#if (defined Q_OS_WIN32) && (defined Q_PROCESSOR_X86_32) && (defined USE_SURFACE_MERGE)
	connect(GetAVSignal(), &QZegoAVSignal::sigSurfaceMergeResult, this, &ZegoBaseDialog::OnSurfaceMergeResult, Qt::DirectConnection);
#endif
	connect(GetAVSignal(), &QZegoAVSignal::sigPreviewSnapshot, this, &ZegoBaseDialog::OnPreviewSnapshot, Qt::DirectConnection);
	connect(GetAVSignal(), &QZegoAVSignal::sigSnapshot, this, &ZegoBaseDialog::OnSnapshot, Qt::DirectConnection);

	//UI的信号槽
	connect(ui.m_bMin, &QPushButton::clicked, this, &ZegoBaseDialog::OnClickTitleButton);
	connect(ui.m_bMax, &QPushButton::clicked, this, &ZegoBaseDialog::OnClickTitleButton);
	connect(ui.m_bClose, &QPushButton::clicked, this, &ZegoBaseDialog::OnClickTitleButton);

	connect(ui.m_bSendMessage, &QPushButton::clicked, this, &ZegoBaseDialog::OnButtonSendMessage);
	connect(ui.m_bCapture, &QPushButton::clicked, this, &ZegoBaseDialog::OnButtonSoundCapture);
	connect(ui.m_bProgMircoPhone, &QPushButton::clicked, this, &ZegoBaseDialog::OnButtonMircoPhone);
	connect(ui.m_bSound, &QPushButton::clicked, this, &ZegoBaseDialog::OnButtonSound);
	connect(ui.m_bCamera, &QPushButton::clicked, this, &ZegoBaseDialog::OnButtonCamera);
	connect(ui.m_bShare, &QPushButton::clicked, this, &ZegoBaseDialog::OnShareLink);
	connect(ui.m_bAux, &QPushButton::clicked, this, &ZegoBaseDialog::OnButtonAux);
	connect(ui.m_bFullScreen, &QPushButton::clicked, this, &ZegoBaseDialog::OnButtonShowFullScreen);
	connect(ui.m_cbMircoPhone, SIGNAL(currentIndexChanged(int)), this, SLOT(OnSwitchAudioDevice(int)));
	connect(ui.m_cbCamera, SIGNAL(currentIndexChanged(int)), this, SLOT(OnSwitchVideoDevice(int)));

#if (defined Q_OS_WIN32) && (defined Q_PROCESSOR_X86_32) 
	connect(&hookDialog, &ZegoMusicHookDialog::sigUseDefaultAux, this, &ZegoBaseDialog::OnUseDefaultAux);
	connect(&hookDialog, &ZegoMusicHookDialog::sigSendMusicAppPath, this, &ZegoBaseDialog::OnGetMusicAppPath);
#endif
	connect(this, &ZegoBaseDialog::sigShowSnapShotImage, this, &ZegoBaseDialog::OnShowSnapShotImage);

	timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &ZegoBaseDialog::OnProgChange);

	//混音数据参数
	m_pAuxData = NULL;
	m_nAuxDataLen = 0;
	m_nAuxDataPos = 0;

	this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏 

	ui.m_edInput->installEventFilter(this);
	ui.m_zoneLiveView_Inner->installEventFilter(this);
	this->installEventFilter(this);

	//初始化网格布局
	gridLayout = new QGridLayout();
}

ZegoBaseDialog::~ZegoBaseDialog()
{

}

//功能函数
void ZegoBaseDialog::initDialog()
{
	//在mac系统下不支持声卡采集
#ifdef Q_OS_MAC
	ui.m_bCapture->setVisible(false);
#endif

	initButtonIcon();
	initComboBox();

	//对话框模型初始化
	m_chatModel = new QStandardItemModel(this);
	ui.m_listChat->setModel(m_chatModel);
	ui.m_listChat->horizontalHeader()->setVisible(false);
	ui.m_listChat->verticalHeader()->setVisible(false);
	ui.m_listChat->verticalHeader()->setDefaultSectionSize(26);
	ui.m_listChat->setItemDelegate(new NoFocusFrameDelegate(this));
	ui.m_listChat->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.m_listChat->setColumnWidth(0, 300);


	//成员列表初始化
	m_memberModel = new QStringListModel(this);
	ui.m_listMember->setModel(m_memberModel);
	ui.m_listMember->setItemDelegate(new NoFocusFrameDelegate(this));
	ui.m_listMember->setEditTriggers(QAbstractItemView::NoEditTriggers);

	//剩余能用的AVView
	for (int i = MAX_VIEW_COUNT; i >= 0; i--)
		m_avaliableView.push_front(i);
	
	//推流成功前不能开混音、声音采集、分享、停止直播
	SetOperation(false);

	//初始化允许使用麦克风和扬声器
	LIVEROOM::EnableMic(m_bCKEnableMic);
	LIVEROOM::EnableSpeaker(m_bCKEnableSpeaker);

	//枚举音视频设备
	EnumVideoAndAudioDevice();

	int role = LIVEROOM::ZegoRoomRole::Anchor;
	if (!LIVEROOM::LoginRoom(m_pChatRoom->getRoomId().toStdString().c_str(), role, m_pChatRoom->getRoomName().toStdString().c_str()))
	{
		QMessageBox::information(NULL, tr("提示"), tr("进入房间失败"));
	}

}

void ZegoBaseDialog::initButtonIcon()
{
	//imageButton
	ui.m_bMin->setButtonIcon("min");
	ui.m_bMax->setButtonIcon("max");
	ui.m_bClose->setButtonIcon("close");

	//switchButton
	ui.m_bSound->setButtonIcon("sound");
	ui.m_bCamera->setButtonIcon("camera");
}

void ZegoBaseDialog::initComboBox()
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

	initCameraListView2();

}

void ZegoBaseDialog::EnumVideoAndAudioDevice()
{
#ifdef Q_OS_WIN
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

		if (m_pAVSettings->GetMircophoneId() == QString(pDeviceList[i].szDeviceId))
			curSelectionIndex = i;
	}

	ui.m_cbMircoPhone->setCurrentIndexWithoutSignal(curSelectionIndex);

	qDebug() << "[MoreAnchorDialog::EnumAudioDevice]: current audio device : " << m_pAVSettings->GetMircophoneId();
	LIVEROOM::FreeDeviceList(pDeviceList);

	pDeviceList = NULL;

	//获取视频设备
	curSelectionIndex = 0;
	pDeviceList = LIVEROOM::GetVideoDeviceList(nDeviceCount);
	for (int i = 0; i < nDeviceCount; ++i)
	{
		insertStringListModelItem(m_cbCameraModel, QString::fromUtf8(pDeviceList[i].szDeviceName), m_cbCameraModel->rowCount());
		m_vecVideoDeviceIDs.push_back(pDeviceList[i].szDeviceId);

		if (m_pAVSettings->GetCameraId() == QString(pDeviceList[i].szDeviceId))
			curSelectionIndex = i;
	}

	ui.m_cbCamera->setCurrentIndexWithoutSignal(curSelectionIndex);
	qDebug() << "[MoreAnchorDialog::EnumVideoDevice]: current video device_main : " << m_pAVSettings->GetCameraId();

	curSelectionIndex = -1;
	for (int i = 0; i < nDeviceCount; ++i)
	{
		if (m_pAVSettings->GetCameraId2() == QString(pDeviceList[i].szDeviceId))
			curSelectionIndex = i;
	}

	if (curSelectionIndex < 0)
	{
		//先将第二个camera model用一个空的model绑定，此时就算推了第二路流也会没有图像
		ui.m_cbCamera2->setNewModelWithoutSignal();
	}
	else
	{
		ui.m_cbCamera2->setCurrentIndexWithoutSignal(curSelectionIndex);
	}

	qDebug() << "[MoreAnchorDialog::EnumVideoDevice]: current video device_aux : " << m_pAVSettings->GetCameraId2();
	LIVEROOM::FreeDeviceList(pDeviceList);
	pDeviceList = NULL;
#else
	QVector<deviceConfig> audioDeviceList = GetAudioDevicesWithOSX();
	QVector<deviceConfig> videoDeviceList = GetVideoDevicesWithOSX();

	//将从mac系统API中获取的Audio设备保存
	int curSelectionIndex = 0;
	for (int i = 0; i < audioDeviceList.size(); ++i)
	{
		insertStringListModelItem(m_cbMircoPhoneModel, audioDeviceList[i].deviceName, m_cbMircoPhoneModel->rowCount());
		m_vecAudioDeviceIDs.push_back(audioDeviceList[i].deviceId);

		if (m_pAVSettings->GetMircophoneId() == audioDeviceList[i].deviceId)
			curSelectionIndex = i;
	}

	ui.m_cbMircoPhone->setCurrentIndexWithoutSignal(curSelectionIndex);

	//将从mac系统API中获取的Video设备保存
	curSelectionIndex = 0;
	for (int i = 0; i < videoDeviceList.size(); ++i)
	{
		insertStringListModelItem(m_cbCameraModel, videoDeviceList[i].deviceName, m_cbCameraModel->rowCount());
		m_vecVideoDeviceIDs.push_back(videoDeviceList[i].deviceId);

		if (m_pAVSettings->GetCameraId() == videoDeviceList[i].deviceId)
			curSelectionIndex = i;
	}

	ui.m_cbCamera->setCurrentIndexWithoutSignal(curSelectionIndex);

	curSelectionIndex = -1;
	for (int i = 0; i < videoDeviceList.size(); ++i)
	{
		if (m_pAVSettings->GetCameraId2() == videoDeviceList[i].deviceId)
			curSelectionIndex = i;
    }

	if (curSelectionIndex < 0)
	{
		//先将第二个camera model用一个空的model绑定，此时就算推了第二路流也会没有图像
		ui.m_cbCamera2->setNewModelWithoutSignal();
	}
	else
	{
		ui.m_cbCamera2->setCurrentIndexWithoutSignal(curSelectionIndex);
	}
#endif
}

void ZegoBaseDialog::insertStringListModelItem(QStringListModel * model, QString name, int size)
{
	if (model == nullptr)
		return;

	int row = size;
	model->insertRows(row, 1);
	QModelIndex index = model->index(row);
	model->setData(index, name);

}

void ZegoBaseDialog::removeStringListModelItem(QStringListModel * model, QString name)
{
	if (model == nullptr)
		return;

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

void ZegoBaseDialog::SetOperation(bool state)
{
	ui.m_cbMircoPhone->setEnabled(state);
	ui.m_cbCamera->setEnabled(state);
	ui.m_lbMircoPhone->setEnabled(state);
	ui.m_lbCamera->setEnabled(state);

	ui.m_bAux->setEnabled(state);
	ui.m_bCapture->setEnabled(state);
	ui.m_bShare->setEnabled(state);
	ui.m_bProgMircoPhone->setEnabled(state);
	ui.m_bProgMircoPhone->setMyEnabled(state);
	ui.m_bCamera->setEnabled(state);
	ui.m_bProgMircoPhone->update();

}

int ZegoBaseDialog::takeLeastAvaliableViewIndex()
{
	int min = m_avaliableView[0];
	int minIndex = 0;
	for (int i = 1; i < m_avaliableView.size(); i++)
	{
		if (m_avaliableView[i] < min)
		{
			min = m_avaliableView[i];
			minIndex = i;
		}
	}

	m_avaliableView.takeAt(minIndex);
	return min;
}

void ZegoBaseDialog::initAVView(QZegoAVView *view)
{
	view->setMinimumSize(QSize(240, 0));
	view->setStyleSheet(QLatin1String("border: none;\n"
		"background-color: #383838;"));
}

void ZegoBaseDialog::addAVView(int addViewIndex, ZegoDialogType dialogType)
{
	QZegoAVView *newAVView = new QZegoAVView(dialogType);

	initAVView(newAVView);
	newAVView->setViewIndex(addViewIndex);
	AVViews.push_back(newAVView);

	updateViewLayout(AVViews.size());
}

void ZegoBaseDialog::removeAVView(int removeViewIndex)
{
	int viewIndex = -1;
	for (int i = 0; i < AVViews.size(); i++)
	{
		if (AVViews[i]->getViewIndex() == removeViewIndex)
		{
			viewIndex = i;
			break;
		}
	}

	QZegoAVView *popView = AVViews.takeAt(viewIndex);
	popView->deleteLater();

	updateViewLayout(AVViews.size());
}

void ZegoBaseDialog::updateViewLayout(int viewCount)
{
	
	for (int i = 0; i < viewCount; i++)
		gridLayout->removeWidget(AVViews[i]);

	gridLayout->deleteLater();

	gridLayout = new QGridLayout();
	gridLayout->setSpacing(0);
	gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
	ui.zoneLiveViewHorizontalLayout->addLayout(gridLayout);

	for (int i = 0; i < viewCount; i++)
	{
		int row, col;
		if (viewCount >= 1 && viewCount <= 4)
		{
			row = i / 2;
			col = i % 2;
		}
		else if (viewCount >= 5 && viewCount <= 9)
		{
			row = i / 3;
			col = i % 3;
		}
		else if (viewCount >= 10 && viewCount <= 12)
		{
			row = i / 4;
			col = i % 4;
		}
		qDebug() << "current row = " << row << " col = " << col;
		gridLayout->addWidget(AVViews[i], row, col, 1, 1);
	    gridLayout->setRowStretch(row, 1);
		gridLayout->setColumnStretch(col, 1);
	}
	
}

void ZegoBaseDialog::FreeAVView(StreamPtr stream)
{
	if (stream == nullptr)
	{
		return;
	}

	int nIndex = stream->getPlayView();

	m_avaliableView.push_front(nIndex);

	//刷新可用的view页面
	update();
}

QString ZegoBaseDialog::encodeStringAddingEscape(QString str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (str.at(i) == '!'){
			str.replace(i, 1, "%21");
			i += 2;
		}
		else if (str.at(i) == '*'){
			str.replace(i, 1, "%2A");
			i += 2;
		}
		else if (str.at(i) == '\''){
			str.replace(i, 1, "%27");
			i += 2;
		}
		else if (str.at(i) == '('){
			str.replace(i, 1, "%28");
			i += 2;
		}
		else if (str.at(i) == ')'){
			str.replace(i, 1, "%29");
			i += 2;
		}
		else if (str.at(i) == ';'){
			str.replace(i, 1, "%3B");
			i += 2;
		}
		else if (str.at(i) == ':'){
			str.replace(i, 1, "%3A");
			i += 2;
		}
		else if (str.at(i) == '@'){
			str.replace(i, 1, "%40");
			i += 2;
		}
		else if (str.at(i) == '&'){
			str.replace(i, 1, "%26");
			i += 2;
		}
		else if (str.at(i) == '='){
			str.replace(i, 1, "%3D");
			i += 2;
		}
		else if (str.at(i) == '+'){
			str.replace(i, 1, "%2B");
			i += 2;
		}
		else if (str.at(i) == '$'){
			str.replace(i, 1, "%24");
			i += 2;
		}
		else if (str.at(i) == ','){
			str.replace(i, 1, "%2C");
			i += 2;
		}
		else if (str.at(i) == '/'){
			str.replace(i, 1, "%2F");
			i += 2;
		}
		else if (str.at(i) == '?'){
			str.replace(i, 1, "%2A");
			i += 2;
		}
		else if (str.at(i) == '%'){
			str.replace(i, 1, "%25");
			i += 2;
		}
		else if (str.at(i) == '#'){
			str.replace(i, 1, "%23");
			i += 2;
		}
		else if (str.at(i) == '['){
			str.replace(i, 1, "%5B");
			i += 2;
		}
		else if (str.at(i) == ']'){
			str.replace(i, 1, "%5D");
			i += 2;
		}
	}
	return str;
}

void ZegoBaseDialog::roomMemberAdd(QString userName)
{
	if (m_memberModel == nullptr)
		return;

	insertStringListModelItem(m_memberModel, userName, m_memberModel->rowCount());
	ui.m_tabCommonAndUserList->setTabText(1, QString(tr("成员(%1)").arg(m_memberModel->rowCount())));
}

void ZegoBaseDialog::roomMemberDelete(QString userName)
{
	if (m_memberModel == nullptr)
		return;

	removeStringListModelItem(m_memberModel, userName);
	ui.m_tabCommonAndUserList->setTabText(1, QString(tr("成员(%1)").arg(m_memberModel->rowCount())));
}

void ZegoBaseDialog::BeginAux()
{
	QString filePath = QFileDialog::getOpenFileName(this,
		tr(QString("请选择一个混音文件").toStdString().c_str()),
		"./Resources",
		tr(QString("pcm文件(*.pcm)").toStdString().c_str()));


	if (!filePath.isEmpty())
	{
		FILE* fAux;
		fAux = fopen(filePath.toStdString().c_str(), "rb");

		if (fAux == NULL)
		{
			QMessageBox::warning(this, tr("警告"), tr("文件内容错误: %1").arg(filePath));
			return;
		}

		fseek(fAux, 0, SEEK_END);
		m_nAuxDataLen = ftell(fAux);

		if (m_nAuxDataLen > 0)
		{
			m_pAuxData = new unsigned char[m_nAuxDataLen];
			memset(m_pAuxData, 0, m_nAuxDataLen);
		}

		fseek(fAux, 0, 0);

		int nReadDataLen = fread(m_pAuxData, sizeof(unsigned char), m_nAuxDataLen, fAux);

		fclose(fAux);

		LIVEROOM::EnableAux(true);

		ui.m_bAux->setText(tr("关闭混音"));
	}
}

void ZegoBaseDialog::EndAux()
{
	LIVEROOM::EnableAux(false);

	ui.m_bAux->setText(tr("开启混音"));
	if (m_pAuxData)
	{
		delete[] m_pAuxData;
		m_pAuxData = NULL;
	}
	m_nAuxDataLen = 0;
	m_nAuxDataPos = 0;
}

void ZegoBaseDialog::setWaterPrint()
{
	QString waterPrintPath = QDir::currentPath();
#ifdef Q_OS_WIN
	waterPrintPath += "/Resources/waterprint/";
	if (m_dpi < 2.0)
	{
		waterPrintPath += "waterprint.png";
	}
	else
	{
		waterPrintPath += "waterprint@2x.png";
	}
#else
	waterPrintPath += "/ZegoLiveDemo.app/Contents/Resources/";
	if (m_dpi < 2.0)
	{
		waterPrintPath += "waterprint.png";
	}
	else
	{
		waterPrintPath += "waterprint@2x.png";
	}
    waterPrintPath = "file:" + waterPrintPath;
#endif
	QImage waterPrint(waterPrintPath);
	qDebug() << "water print path = " << waterPrintPath;

	//标准640 * 360，根据标准对当前分辨率的水印进行等比缩放
	int cx = m_pAVSettings->GetResolution().cx;
	int cy = m_pAVSettings->GetResolution().cy;
	float scaleX = cx * 1.0 / 640;
	float scaleY = cy * 1.0 / 360;

	LIVEROOM::SetPublishWaterMarkRect((int)(20 * scaleX), (int)(20 * scaleY), (int)(123 * scaleX), (int)(69 * scaleY));
	LIVEROOM::SetPreviewWaterMarkRect((int)(20 * scaleX), (int)(20 * scaleY), (int)(123 * scaleX), (int)(69 * scaleY));
	LIVEROOM::SetWaterMarkImagePath(waterPrintPath.toStdString().c_str());
}

int ZegoBaseDialog::getCameraIndexFromID(const QString& cameraID)
{
	for (int i = 0; i < m_vecVideoDeviceIDs.size(); ++i)
	{
		if (m_vecVideoDeviceIDs[i] == cameraID)
			return i;
	}

	return -1;
}

void ZegoBaseDialog::GetOut()
{
	//离开房间时先把混音功能和声卡采集关闭
#if (defined Q_OS_WIN32) && (defined Q_PROCESSOR_X86_32)
	if (isUseDefaultAux)
		EndAux();
	else
	{
		AUDIOHOOK::StopAudioRecord();
		LIVEROOM::EnableAux(false);
		AUDIOHOOK::UnInitAudioHook();

	}
#else
	EndAux();
#endif

	if (ui.m_bCapture->text() == tr("停止采集"))
#ifdef Q_OS_WIN
		LIVEROOM::EnableMixSystemPlayout(false);
#endif
	
	roomMemberDelete(m_strCurUserName);
	LIVEROOM::LogoutRoom();
	if (timer->isActive())
	{
		timer->stop();
		timer->deleteLater();
	}
	//释放堆内存
	delete m_cbMircoPhoneListView;
	delete m_cbCameraListView;
	delete m_memberModel;
	delete m_chatModel;
	delete m_cbMircoPhoneModel;
	delete m_cbCameraModel;
	delete gridLayout;
	//指针置为空
	m_cbMircoPhoneListView = nullptr;
	m_cbCameraListView = nullptr;
	m_memberModel = nullptr;
	m_chatModel = nullptr;
	m_cbMircoPhoneModel = nullptr;
	m_cbCameraModel = nullptr;
	gridLayout = nullptr;
	
}

//SDK回调
void ZegoBaseDialog::OnUserUpdate(QVector<QString> userIDs, QVector<QString> userNames, QVector<int> userFlags, QVector<int> userRoles, unsigned int userCount, LIVEROOM::ZegoUserUpdateType type)
{
	qDebug() << "onUserUpdate!";

	//全量更新
	if (type == LIVEROOM::ZegoUserUpdateType::UPDATE_TOTAL){
		//removeAll
		m_memberModel->removeRows(0, m_memberModel->rowCount());

		insertStringListModelItem(m_memberModel, m_strCurUserName, 0);
		for (int i = 0; i < userCount; i++)
		{
			insertStringListModelItem(m_memberModel, userNames[i], m_memberModel->rowCount());
		}
	}
	//增量更新
	else
	{

		for (int i = 0; i < userCount; i++)
		{

			if (userFlags[i] == LIVEROOM::USER_ADDED)
				insertStringListModelItem(m_memberModel, userNames[i], m_memberModel->rowCount());
			else
				removeStringListModelItem(m_memberModel, userNames[i]);
		}
	}

	ui.m_tabCommonAndUserList->setTabText(1, QString(tr("成员(%1)").arg(m_memberModel->rowCount())));
	ui.m_listMember->update();
}

void ZegoBaseDialog::OnDisconnect(int errorCode, const QString& roomId)
{
	if (m_pChatRoom->getRoomId() == roomId)
	{
		QMessageBox::information(NULL, tr("提示"), tr("您已掉线"));
		OnClose();
	}
}

void ZegoBaseDialog::OnKickOut(int reason, const QString& roomId)
{
	if (m_pChatRoom->getRoomId() == roomId)
	{
		QMessageBox::information(NULL, tr("提示"), tr("您已被踢出房间"));
		OnClose();
	}
}

void ZegoBaseDialog::OnPlayQualityUpdate(const QString& streamId, int quality, double videoFPS, double videoKBS)
{
	StreamPtr pStream = m_pChatRoom->getStreamById(streamId);

	if (pStream == nullptr)
		return;

	int nIndex = pStream->getPlayView();

	if (nIndex < 0 || nIndex > 11)
		return;

	AVViews[nIndex]->setCurrentQuality(quality);

	//QVector<QString> q = { QStringLiteral("优"), QStringLiteral("良"), QStringLiteral("中"), QStringLiteral("差") };
	//qDebug() << QStringLiteral("当前窗口") << nIndex << QStringLiteral("的直播质量为") << q[quality];
}

void ZegoBaseDialog::OnPublishQualityUpdate(const QString& streamId, int quality, double videoFPS, double videoKBS)
{
	StreamPtr pStream = m_pChatRoom->getStreamById(streamId);

	if (pStream == nullptr)
		return;

	int nIndex = pStream->getPlayView();

	if (nIndex < 0 || nIndex > 11)
		return;

	AVViews[nIndex]->setCurrentQuality(quality);

	//QVector<QString> q = { QStringLiteral("优"), QStringLiteral("良"), QStringLiteral("中"), QStringLiteral("差") };
	//qDebug() << QStringLiteral("当前窗口") << nIndex << QStringLiteral("的直播质量为") << q[quality];

}

void ZegoBaseDialog::OnAVAuxInput(unsigned char *pData, int *pDataLen, int pDataLenValue, int *pSampleRate, int *pNumChannels)
{
#if (defined Q_OS_WIN32) && (defined Q_PROCESSOR_X86_32)
	if (isUseDefaultAux)
	{
		if (m_pAuxData != nullptr && (*pDataLen < m_nAuxDataLen))
		{
			*pSampleRate = 44100;
			*pNumChannels = 2;
            //长度 = 采样率 * 20 / 1000 * 位深字节数 * 通道数 位深字节数固定为2
            //计算公式 length = 44100 * 20 / 1000 * 2 * 2 = 3528
            *pDataLen = (*pSampleRate)* 20 / 1000 * 2 * (*pNumChannels);
			if (m_nAuxDataPos + *pDataLen > m_nAuxDataLen)
			{
				m_nAuxDataPos = 0;
			}
            int nCopyLen = *pDataLen;
			memcpy(pData, m_pAuxData + m_nAuxDataPos, nCopyLen);

			m_nAuxDataPos += *pDataLen;


		}
		else
		{
			*pDataLen = 0;
		}
	}
	else
	{
		AUDIOHOOK::GetAUXData(pData, pDataLen, pSampleRate, pNumChannels);
	}
#else
	if (m_pAuxData != nullptr && (*pDataLen < m_nAuxDataLen))
	{
		*pSampleRate = 44100;
		*pNumChannels = 2;
        //长度 = 采样率 * 20 / 1000 * 位深字节数 * 通道数 位深字节数固定为2
        //计算公式 length = 44100 * 20 / 1000 * 2 * 2 = 3528
        *pDataLen = (*pSampleRate)* 20 / 1000 * 2 * (*pNumChannels);
		if (m_nAuxDataPos + *pDataLen > m_nAuxDataLen)
		{
			m_nAuxDataPos = 0;
		}

		int nCopyLen = *pDataLen;
		memcpy(pData, m_pAuxData + m_nAuxDataPos, nCopyLen);

		m_nAuxDataPos += *pDataLen;


	}
	else
	{
		*pDataLen = 0;
	}
#endif
}

void ZegoBaseDialog::OnSendRoomMessage(int errorCode, const QString& roomID, int sendSeq, unsigned long long messageId)
{
	if (errorCode != 0)
	{
		QMessageBox::warning(NULL, tr("消息发送失败"), tr("错误码: %1").arg(errorCode));
		return;
	}

	qDebug() << "message send success";
}

void ZegoBaseDialog::OnRecvRoomMessage(const QString& roomId, QVector<RoomMsgPtr> vRoomMsgList)
{
	for (auto& roomMsg : vRoomMsgList)
	{
		QString strTmpContent;
		strTmpContent = QString("%1").arg(roomMsg->getContent());
		
		QStandardItem *item = new QStandardItem;
		m_chatModel->appendRow(item);
		QModelIndex index = m_chatModel->indexFromItem(item);

		ZegoRoomMessageLabel *chatContent = new ZegoRoomMessageLabel;
		chatContent->setTextContent(roomMsg->getUserName(), strTmpContent);

		ui.m_listChat->setIndexWidget(index, chatContent);
		if (chatContent->getHeightNum() > 1)
			ui.m_listChat->resizeRowToContents(m_chatModel->rowCount() - 1);

		//每次接受消息均显示最后一条
		ui.m_listChat->scrollToBottom();

	}
}

void ZegoBaseDialog::OnAudioDeviceChanged(AV::AudioDeviceType deviceType, const QString& strDeviceId, const QString& strDeviceName, AV::DeviceState state)
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
			m_pAVSettings->SetMicrophoneId(m_vecAudioDeviceIDs[0]);
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
					m_pAVSettings->SetMicrophoneId(m_vecAudioDeviceIDs[0]);
					ui.m_cbMircoPhone->setCurrentIndex(0);

				}
				else
				{
					LIVEROOM::SetAudioDevice(AV::AudioDevice_Input, NULL);
					m_pAVSettings->SetMicrophoneId("");
				}
				removeStringListModelItem(m_cbMircoPhoneModel, strDeviceName);
				update();
				break;
			}


		}
	}
}

void ZegoBaseDialog::OnVideoDeviceChanged(const QString& strDeviceId, const QString& strDeviceName, AV::DeviceState state)
{
	if (state == AV::DeviceState::Device_Added)
	{
		insertStringListModelItem(m_cbCameraModel, strDeviceName, m_cbCameraModel->rowCount());
		m_vecVideoDeviceIDs.push_back(strDeviceId);
		if (m_vecVideoDeviceIDs.size() == 1)
		{
			LIVEROOM::StopPreview();
			LIVEROOM::SetVideoDevice(m_vecVideoDeviceIDs[0].toStdString().c_str());
			LIVEROOM::StartPreview();

			m_pAVSettings->SetCameraId(m_vecVideoDeviceIDs[0]);
			
			ui.m_cbCamera->setCurrentIndexWithoutSignal(0);
			ui.m_cbCamera2->setNewModelWithoutSignal();
			
		}
		//当前摄像头有两个的话，并且以推双流模式开播时，将最新加入的摄像头分配给摄像头2
		else if (m_vecVideoDeviceIDs.size() == 2 && m_isPublish2StreamMode)
		{
			LIVEROOM::StopPreview(ZEGO::AV::PUBLISH_CHN_AUX);
			LIVEROOM::SetVideoDevice(strDeviceId.toStdString().c_str(), ZEGO::AV::PUBLISH_CHN_AUX);

			m_pAVSettings->SetCameraId2(strDeviceId);

			ui.m_cbCamera2->blockSignals(true);
			ui.m_cbCamera2->setModel(m_cbCameraModel);
			ui.m_cbCamera2->setCurrentIndex(1);
			ui.m_cbCamera2->blockSignals(false);

			ui.m_cbCamera->setCurrentIndexWithoutSignal(0);
			m_pAVSettings->SetCameraId(m_vecVideoDeviceIDs[0]);

			LIVEROOM::EnableCamera(true, ZEGO::AV::PUBLISH_CHN_AUX);
			LIVEROOM::StartPreview(ZEGO::AV::PUBLISH_CHN_AUX);
		}
		update();

		qDebug() << "[MoreAnchorDialog::VideoDevice_Added]: current video device_main : " << m_pAVSettings->GetCameraId() << " video device_aux : " << m_pAVSettings->GetCameraId2();
	}
	else if (state == AV::DeviceState::Device_Deleted)
	{
		for (int i = 0; i < m_vecVideoDeviceIDs.size(); i++)
		{
			if (m_vecVideoDeviceIDs[i] != strDeviceId)
				continue;

			int currentCurl_1 = ui.m_cbCamera->currentIndex();
			int currentCurl_2 = ui.m_cbCamera2->currentIndex();
			//如果currentCurl等于i说明当前删除的设备是当前正在使用的设备1
			if (currentCurl_1 == i)
			{
				//默认采集靠前的没有被使用的视频设备
				if (m_vecVideoDeviceIDs.size() > 1)
				{
					int index = -1;
					for (int j = 0; j < m_vecVideoDeviceIDs.size(); ++j)
					{
						if ((j != currentCurl_1) && (j != currentCurl_2))
						{
							index = j;
							break;
						}
					}
					//这种情况是摄像头2占了剩下的一个设备，这个时候需将该设备给1
					if (index < 0)
					{
						LIVEROOM::EnableCamera(false, ZEGO::AV::PUBLISH_CHN_AUX);
						LIVEROOM::StopPreview(ZEGO::AV::PUBLISH_CHN_AUX);

						LIVEROOM::SetVideoDevice(m_vecVideoDeviceIDs[currentCurl_2].toStdString().c_str());
						m_pAVSettings->SetCameraId(m_vecVideoDeviceIDs[currentCurl_2]);
						
						ui.m_cbCamera->setCurrentIndexWithoutSignal(currentCurl_2);
						
						ui.m_cbCamera2->setNewModelWithoutSignal();
						m_pAVSettings->SetCameraId2("");
					}
					else
					{
						LIVEROOM::SetVideoDevice(m_vecVideoDeviceIDs[index].toStdString().c_str());
						m_pAVSettings->SetCameraId(m_vecVideoDeviceIDs[index]);
				
						ui.m_cbCamera->setCurrentIndexWithoutSignal(index);
					}

				}
				else if (m_vecVideoDeviceIDs.size() <= 1)
				{
					LIVEROOM::SetVideoDevice(nullptr);
					m_pAVSettings->SetCameraId("");

				}

			}
			else if (currentCurl_2 == i)
			{
				if (m_vecVideoDeviceIDs.size() > 1)
				{
					int index = -1;
					for (int j = 0; j < m_vecVideoDeviceIDs.size(); ++j)
					{
						if ((j != currentCurl_1) && (j != currentCurl_2))
						{
							index = j;
							break;
						}
					}
					//这种情况是摄像头1占了剩下的一个设备，这个时候设备2直接复制空
					if (index < 0)
					{
						LIVEROOM::EnableCamera(false, ZEGO::AV::PUBLISH_CHN_AUX);
						LIVEROOM::SetVideoDevice(nullptr, ZEGO::AV::PUBLISH_CHN_AUX);
						ui.m_cbCamera2->setNewModelWithoutSignal();
						m_pAVSettings->SetCameraId2("");
					}
					else
					{
						LIVEROOM::SetVideoDevice(m_vecVideoDeviceIDs[index].toStdString().c_str(), ZEGO::AV::PUBLISH_CHN_AUX);
						m_pAVSettings->SetCameraId2(m_vecVideoDeviceIDs[index]);
				
						ui.m_cbCamera2->setCurrentIndexWithoutSignal(index);
					}
				}
			}

			m_vecVideoDeviceIDs.erase(m_vecVideoDeviceIDs.begin() + i);
			ui.m_cbCamera->blockSignals(true);
			ui.m_cbCamera2->blockSignals(true);
			removeStringListModelItem(m_cbCameraModel, strDeviceName);
			ui.m_cbCamera->blockSignals(false);
			ui.m_cbCamera2->blockSignals(false);
			update();
			break;
		}

		qDebug() << "[MoreAnchorDialog::VideoDevice_Deleted]: current video device_main : " << m_pAVSettings->GetCameraId() << " video device_aux : " << m_pAVSettings->GetCameraId2();
	}
}

#if (defined Q_OS_WIN32) && (defined Q_PROCESSOR_X86_32) && (defined USE_SURFACE_MERGE)
void ZegoBaseDialog::OnSurfaceMergeResult(unsigned char *surfaceMergeData, int datalength)
{
	if (m_takeSnapShot)
	{
		//同一时刻只允许一个线程进入该代码段
		m_takeSnapShot = false;
		m_mutex.lock();
		m_image = new unsigned char[datalength];
		memcpy(m_image, surfaceMergeData, datalength);
		QImage *image = new QImage(m_image, m_pAVSettings->GetResolution().cx, m_pAVSettings->GetResolution().cy, QImage::Format_RGB32);
		emit sigShowSnapShotImage(image);
		m_mutex.unlock();
	}
}
#endif

void ZegoBaseDialog::OnPreviewSnapshot(void *pImage)
{
	QImage *image;

#ifdef Q_OS_WIN
	image = new QImage;
	QPixmap pixmap = qt_pixmapFromWinHBITMAP((HBITMAP)pImage, 0);
	*image = pixmap.toImage();
#else
	image = CGImageToQImage(pImage);
#endif
	//发送信号切线程，不能阻塞当前线程
	emit sigShowSnapShotImage(image);
}

void ZegoBaseDialog::OnSnapshot(void *pImage, const QString &streamID)
{
	QImage *image;

#ifdef Q_OS_WIN
	image = new QImage;
	QPixmap pixmap = qt_pixmapFromWinHBITMAP((HBITMAP)pImage, 0);
	*image = pixmap.toImage();
#else
	image = CGImageToQImage(pImage);
#endif

	//发送信号切线程，不能阻塞当前线程
	emit sigShowSnapShotImage(image);
}
//UI回调
void ZegoBaseDialog::OnClickTitleButton()
{
	QPushButton *pButton = qobject_cast<QPushButton *>(sender());

	if (pButton == ui.m_bMin)
	{
		this->showMinimized();
	}
	else if (pButton == ui.m_bClose)
	{
		this->close();
	}
	else if (pButton == ui.m_bMax)
	{
		if (isMax)
		{
			this->showNormal();
			isMax = false;
			ui.m_bMax->setButtonIcon("max");
		}
		else
		{
			this->showMaximized();
			isMax = true;
			ui.m_bMax->setButtonIcon("max_re");
		}
	}
}

void ZegoBaseDialog::OnClose()
{
	this->close();
}

void ZegoBaseDialog::OnButtonSendMessage()
{
	QString strChat;
	strChat = ui.m_edInput->toPlainText();

	m_strLastSendMsg = strChat;
	m_strLastSendMsg = m_strLastSendMsg.trimmed();

	if (!m_strLastSendMsg.isEmpty())
		LIVEROOM::SendRoomMessage(ROOM::ZegoMessageType::Text, ROOM::ZegoMessageCategory::Chat, ROOM::ZegoMessagePriority::Default, m_strLastSendMsg.toStdString().c_str());

	ui.m_edInput->setText("");

	QString strTmpContent;
	strTmpContent = QString("%1").arg(m_strLastSendMsg);

	QStandardItem *item = new QStandardItem;
	m_chatModel->appendRow(item);
	QModelIndex index = m_chatModel->indexFromItem(item);

	ZegoRoomMessageLabel *chatContent = new ZegoRoomMessageLabel;
	chatContent->setTextContent("我", strTmpContent);

	ui.m_listChat->setIndexWidget(index, chatContent);
	if (chatContent->getHeightNum() > 1)
		ui.m_listChat->resizeRowToContents(m_chatModel->rowCount() - 1);

	//每次发送消息均显示最后一条
	ui.m_listChat->scrollToBottom();
	m_strLastSendMsg.clear();

}

void ZegoBaseDialog::OnButtonSoundCapture()
{
	if (ui.m_bCapture->text() == tr("声卡采集"))
	{
#ifdef Q_OS_WIN
		LIVEROOM::EnableMixSystemPlayout(true);
#endif
		ui.m_bCapture->setText(tr("停止采集"));
	}
	else
	{
#ifdef Q_OS_WIN
		LIVEROOM::EnableMixSystemPlayout(false);
#endif
		ui.m_bCapture->setText(tr("声卡采集"));
	}
}

void ZegoBaseDialog::OnButtonMircoPhone()
{


	if (ui.m_bProgMircoPhone->isChecked())
	{
		m_bCKEnableMic = true;
		ui.m_bProgMircoPhone->setMyEnabled(true);
		timer->start(200);
	}
	else
	{
		m_bCKEnableMic = false;
		if (timer->isActive())
			timer->stop();
		ui.m_bProgMircoPhone->setMyEnabled(false);
		ui.m_bProgMircoPhone->update();
	}

	//使用麦克风
	LIVEROOM::EnableMic(m_bCKEnableMic);
}

void ZegoBaseDialog::OnButtonSound()
{


	if (ui.m_bSound->isChecked())
	{

		m_bCKEnableSpeaker = true;
	}
	else
	{

		m_bCKEnableSpeaker = false;
	}

	//使用扬声器
	LIVEROOM::EnableSpeaker(m_bCKEnableSpeaker);

}

void ZegoBaseDialog::OnButtonCamera()
{
	if (ui.m_bCamera->isChecked())
	{
		LIVEROOM::EnableCamera(true);
		LIVEROOM::StartPreview();
		if (m_isPublish2StreamMode)
		{
			LIVEROOM::EnableCamera(true, AV::PUBLISH_CHN_AUX);
			LIVEROOM::StartPreview(AV::PUBLISH_CHN_AUX);
		}
	}
	else
	{
		LIVEROOM::StopPreview();
		LIVEROOM::EnableCamera(false);
		if (m_isPublish2StreamMode)
		{
			LIVEROOM::StopPreview(AV::PUBLISH_CHN_AUX);
			LIVEROOM::EnableCamera(false, AV::PUBLISH_CHN_AUX);
		}
		update();
	}
}

void ZegoBaseDialog::OnProgChange()
{
	ui.m_bProgMircoPhone->setProgValue(LIVEROOM::GetCaptureSoundLevel());
	ui.m_bProgMircoPhone->update();
}

void ZegoBaseDialog::OnShareLink()
{

	QString encodeHls = encodeStringAddingEscape(sharedHlsUrl);
	QString encodeRtmp = encodeStringAddingEscape(sharedRtmpUrl);
	QString encodeID = encodeStringAddingEscape(m_pChatRoom->getRoomId());
	QString encodeStreamID = encodeStringAddingEscape(m_anchorStreamInfo->getStreamId());

	QString link("http://www.zego.im/share/index2?video=" + encodeHls + "&rtmp=" + encodeRtmp + "&id=" + encodeID + "&stream=" + encodeStreamID);
	ZegoShareDialog share(link);
	share.exec();

}

void ZegoBaseDialog::OnButtonShowFullScreen()
{
	//直播窗口总在最顶层
	ui.m_zoneLiveView_Inner->setWindowFlags(Qt::Dialog);
	ui.m_zoneLiveView_Inner->showFullScreen();
	m_isLiveFullScreen = true;
}

void ZegoBaseDialog::OnSnapshotPreview()
{
	if (m_pAVSettings->GetSurfaceMerge())
	{
		m_takeSnapShot = true;
	}
	else
	{
		LIVEROOM::TakeSnapshotPreview();
	}
}

void ZegoBaseDialog::OnSnapshotWithStreamID(const QString &streamID)
{
	LIVEROOM::TakeSnapshot(streamID.toStdString().c_str());
}

void ZegoBaseDialog::OnShowSnapShotImage(QImage *imageData)
{
	ZegoImageShowDialog imageShowDialog(imageData, imageData->width(), imageData->height(), m_pAVSettings);
	imageShowDialog.initDialog();
	imageShowDialog.exec();

	if (m_image)
	{
		delete[] m_image;
		m_image = nullptr;
	}

}

void ZegoBaseDialog::OnUseDefaultAux(bool state)
{
	BeginAux();
	isUseDefaultAux = state;
	ui.m_bAux->setEnabled(true);
	ui.m_bAux->setText(tr("关闭混音"));
}

#if (defined Q_OS_WIN32) && (defined Q_PROCESSOR_X86_32)
void ZegoBaseDialog::OnGetMusicAppPath(QString exePath)
{

	QString dllPath = QDir::currentPath() + "/MusicHook/ZegoMusicAudio.dll";

	const char*  exepath;
	QByteArray exeBA = exePath.toLocal8Bit();
	exepath = exeBA.data();

	const char*  dllpath;
	QByteArray dllBA = dllPath.toLocal8Bit();
	dllpath = dllBA.data();

	AUDIOHOOK::InitAuidoHook();
	if (!AUDIOHOOK::StartAudioHook(exepath, dllpath))
	{
		QMessageBox::warning(NULL, tr("警告"), tr("路径格式错误"));
		ui.m_bAux->setEnabled(true);
		ui.m_bAux->setText(tr("开启混音"));
		return;
	}

	AUDIOHOOK::StartAudioRecord();
	LIVEROOM::EnableAux(true);

	ui.m_bAux->setEnabled(true);
	ui.m_bAux->setText(tr("关闭混音"));
}
#endif

void ZegoBaseDialog::OnButtonAux()
{
	if (ui.m_bAux->text() == tr("开启混音"))
	{
		ui.m_bAux->setText(tr("开启中..."));
		ui.m_bAux->setEnabled(false);

#if (defined Q_OS_WIN32) && (defined Q_PROCESSOR_X86_32)

		hookDialog.searchMusicAppFromReg();
		if (hookDialog.exec() == QDialog::Rejected)
		{
			ui.m_bAux->setEnabled(true);
			ui.m_bAux->setText(tr("开启混音"));
		}

#endif

#ifdef Q_OS_MAC

		BeginAux();
		ui.m_bAux->setEnabled(true);
		ui.m_bAux->setText(tr("关闭混音"));
#endif

	}
	else
	{
		ui.m_bAux->setText(tr("关闭中..."));
		ui.m_bAux->setEnabled(false);

#if (defined Q_OS_WIN32) && (defined Q_PROCESSOR_X86_32)
		if (isUseDefaultAux)
		{
			EndAux();

		}
		else
		{
			AUDIOHOOK::StopAudioRecord();
			LIVEROOM::EnableAux(false);
			AUDIOHOOK::UnInitAudioHook();

		}
#else
		EndAux();
#endif
		ui.m_bAux->setEnabled(true);
		ui.m_bAux->setText(tr("开启混音"));
	}
}

void ZegoBaseDialog::OnSwitchAudioDevice(int id)
{
	if (id < 0)
		return;

	if (id < m_vecAudioDeviceIDs.size())
	{
		LIVEROOM::SetAudioDevice(AV::AudioDevice_Input, m_vecAudioDeviceIDs[id].toStdString().c_str());
		m_pAVSettings->SetMicrophoneId(m_vecAudioDeviceIDs[id]);
		ui.m_cbMircoPhone->setCurrentIndexWithoutSignal(id);

		//切换设备之后，如果当前设备被关闭，则开启
		if (!ui.m_bProgMircoPhone->isChecked())
			ui.m_bProgMircoPhone->setChecked(true);

		update();
	}
}

void ZegoBaseDialog::OnSwitchVideoDevice(int id)
{
	if (id < 0)
		return;

	if (id < m_vecVideoDeviceIDs.size())
	{
		//若摄像头1需要选取的摄像头已被摄像头2选取，则交换摄像头
		if (id == ui.m_cbCamera2->currentIndex())
		{
			//先关闭所有正在使用的摄像头，避免交换时先后次序不同导致的抢占问题
			LIVEROOM::StopPreview();
			LIVEROOM::StopPreview(ZEGO::AV::PUBLISH_CHN_AUX);
			LIVEROOM::EnableCamera(false);
			LIVEROOM::EnableCamera(false, ZEGO::AV::PUBLISH_CHN_AUX);

			m_pAVSettings->SetCameraId2(m_pAVSettings->GetCameraId());

			int curLastCameraIndex = getCameraIndexFromID(m_pAVSettings->GetCameraId());
			if (curLastCameraIndex < 0)
				return;

			ui.m_cbCamera2->setCurrentIndexWithoutSignal(curLastCameraIndex);

			LIVEROOM::SetVideoDevice(m_pAVSettings->GetCameraId().toStdString().c_str(), ZEGO::AV::PUBLISH_CHN_AUX);
		}

		LIVEROOM::SetVideoDevice(m_vecVideoDeviceIDs[id].toStdString().c_str());

		m_pAVSettings->SetCameraId(m_vecVideoDeviceIDs[id]);

		ui.m_cbCamera->setCurrentIndexWithoutSignal(id);
		update();

		LIVEROOM::EnableCamera(true);
		if(m_isPublish2StreamMode)
		    LIVEROOM::EnableCamera(true, ZEGO::AV::PUBLISH_CHN_AUX);
		LIVEROOM::StartPreview();
		if (m_isPublish2StreamMode)
		    LIVEROOM::StartPreview(ZEGO::AV::PUBLISH_CHN_AUX);

		//切换设备之后，如果当前设备被关闭，则开启
		if (!ui.m_bCamera->isChecked())
			ui.m_bCamera->setChecked(true);
		qDebug() << "[MoreAnchorDialog::VideoDevice_Changed_1]: current video device_main : " << m_pAVSettings->GetCameraId() << " video device_aux : " << m_pAVSettings->GetCameraId2();
	}
}

void ZegoBaseDialog::OnSwitchVideoDevice2(int id)
{
	if (id < 0)
		return;

	if (id < m_vecVideoDeviceIDs.size())
	{
		//若摄像头1需要选取的摄像头已被摄像头2选取，则交换摄像头
		if (id == ui.m_cbCamera->currentIndex())
		{
			//先关闭所有正在使用的摄像头，避免交换时先后次序不同导致的抢占问题
			LIVEROOM::StopPreview();
			LIVEROOM::StopPreview(ZEGO::AV::PUBLISH_CHN_AUX);
			LIVEROOM::EnableCamera(false);
			LIVEROOM::EnableCamera(false, ZEGO::AV::PUBLISH_CHN_AUX);

			m_pAVSettings->SetCameraId(m_pAVSettings->GetCameraId2());

			int curLastCameraIndex = getCameraIndexFromID(m_pAVSettings->GetCameraId2());
			if (curLastCameraIndex < 0)
				return;

			ui.m_cbCamera->setCurrentIndexWithoutSignal(curLastCameraIndex);

			LIVEROOM::SetVideoDevice(m_pAVSettings->GetCameraId2().toStdString().c_str());
		}

		LIVEROOM::SetVideoDevice(m_vecVideoDeviceIDs[id].toStdString().c_str(), ZEGO::AV::PUBLISH_CHN_AUX);
		m_pAVSettings->SetCameraId2(m_vecVideoDeviceIDs[id]);

		ui.m_cbCamera2->setCurrentIndexWithoutSignal(id);
		update();

		LIVEROOM::EnableCamera(true);
		LIVEROOM::EnableCamera(true, ZEGO::AV::PUBLISH_CHN_AUX);
		LIVEROOM::StartPreview();
		LIVEROOM::StartPreview(ZEGO::AV::PUBLISH_CHN_AUX);

		//切换设备之后，如果当前设备被关闭，则开启
		if (!ui.m_bCamera->isChecked())
			ui.m_bCamera->setChecked(true);
		qDebug() << "[MoreAnchorDialog::VideoDevice_Changed_2]: current video device_main : " << m_pAVSettings->GetCameraId() << " video device_aux : " << m_pAVSettings->GetCameraId2();
	}
}

void ZegoBaseDialog::mousePressEvent(QMouseEvent *event)
{
	mousePosition = event->pos();
	//只对标题栏范围内的鼠标事件进行处理

	if (mousePosition.y() <= pos_min_y)
		return;
	if (mousePosition.y() >= pos_max_y)
		return;
	isMousePressed = true;
}

void ZegoBaseDialog::mouseMoveEvent(QMouseEvent *event)
{
	if (isMousePressed == true)
	{
		QPoint movePot = event->globalPos() - mousePosition;
		move(movePot);
	}
}

void ZegoBaseDialog::mouseReleaseEvent(QMouseEvent *event)
{
	isMousePressed = false;
}

void ZegoBaseDialog::mouseDoubleClickEvent(QMouseEvent *event)
{
	//双击标题栏同样可以放大缩小

	mousePosition = event->pos();
	//只对标题栏范围内的鼠标事件进行处理

	if (mousePosition.y() <= pos_min_y)
		return;
	if (mousePosition.y() >= pos_max_y)
		return;

	if (isMax)
	{
		this->showNormal();
		isMax = false;
		ui.m_bMax->setButtonIcon("max");
	}
	else
	{
		this->showMaximized();
		isMax = true;
		ui.m_bMax->setButtonIcon("max_re");
	}

}

void ZegoBaseDialog::showEvent(QShowEvent *event)
{
	QDialog::showEvent(event);
	this->setAttribute(Qt::WA_Mapped);
}

void ZegoBaseDialog::closeEvent(QCloseEvent *e)
{
	QDialog::closeEvent(e);
	GetOut();
	//this->close();
	emit sigSaveVideoSettings(m_pAVSettings);
	m_lastDialog->show();
}

bool ZegoBaseDialog::eventFilter(QObject *target, QEvent *event)
{
	if (target == ui.m_edInput)
	{
		if (event->type() == QEvent::KeyPress)
		{
			QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
			if (keyEvent->key() == Qt::Key_Return && (keyEvent->modifiers() & Qt::ControlModifier))
			{
				ui.m_edInput->insertPlainText("\n");
				return true;
			}
			else if (keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return)
			{
				OnButtonSendMessage();
				return true;
			}
		}
	}
	else if (target == ui.m_zoneLiveView_Inner)
	{
		if (event->type() == QEvent::KeyPress)
		{
			QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
			if (keyEvent->key() == Qt::Key_Escape && m_isLiveFullScreen)
			{
				//qDebug() << "clicl esc";
				//ui.m_zoneLiveView_Inner->setParent(ui.m_zoneLiveView);
				ui.m_zoneLiveView_Inner->setWindowFlags(Qt::SubWindow);
				ui.m_zoneLiveView_Inner->showNormal();
				ui.horizontalLayout_ForAVView->addWidget(ui.m_zoneLiveView_Inner);
				m_isLiveFullScreen = false;
				return true;
			}
			else if (keyEvent->key() == Qt::Key_Escape && !m_isLiveFullScreen)
			{
				return true;
			}
		}
	}
	else
	{
		if (event->type() == QEvent::KeyPress)
		{
			QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
			if (keyEvent->key() == Qt::Key_Escape)
				return true;
		}
	}
	return QDialog::eventFilter(target, event);
}

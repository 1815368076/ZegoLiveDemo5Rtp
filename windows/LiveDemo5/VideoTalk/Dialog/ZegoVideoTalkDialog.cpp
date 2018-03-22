#include "ZegoVideoTalkDialog.h"
#include <QDebug>
#ifdef Q_OS_MAC
#include "ZegoAVDevice.h"
#endif
ZegoVideoTalkDialog::ZegoVideoTalkDialog(QZegoUserConfig userConfig, RoomPtr chatRoom, QDialog *lastDialog, bool isVideoCustom, QWidget *parent)
	: QDialog(parent), 
	  m_userConfig(userConfig), 
	  m_pChatRoom(chatRoom), 
	  m_lastDialog(lastDialog), 
	  m_isVideoCustom(isVideoCustom)
{
	ui.setupUi(this);

	//通过sdk的信号连接到本类的槽函数中
	connect(GetAVSignal(), &QZegoAVSignal::sigLoginRoom, this, &ZegoVideoTalkDialog::OnLoginRoom);
	connect(GetAVSignal(), &QZegoAVSignal::sigStreamUpdated, this, &ZegoVideoTalkDialog::OnStreamUpdated);
	connect(GetAVSignal(), &QZegoAVSignal::sigPublishStateUpdate, this, &ZegoVideoTalkDialog::OnPublishStateUpdate);
	connect(GetAVSignal(), &QZegoAVSignal::sigPlayStateUpdate, this, &ZegoVideoTalkDialog::OnPlayStateUpdate);
	connect(GetAVSignal(), &QZegoAVSignal::sigDisconnect, this, &ZegoVideoTalkDialog::OnDisconnect);
	connect(GetAVSignal(), &QZegoAVSignal::sigKickOut, this, &ZegoVideoTalkDialog::OnKickOut);
	connect(GetAVSignal(), &QZegoAVSignal::sigPublishQualityUpdate, this, &ZegoVideoTalkDialog::OnPublishQualityUpdate);
	connect(GetAVSignal(), &QZegoAVSignal::sigPlayQualityUpdate, this, &ZegoVideoTalkDialog::OnPlayQualityUpdate);
	connect(GetAVSignal(), &QZegoAVSignal::sigUserUpdate, this, &ZegoVideoTalkDialog::OnUserUpdate);
	connect(GetAVSignal(), &QZegoAVSignal::sigAudioDeviceChanged, this, &ZegoVideoTalkDialog::OnAudioDeviceChanged);
	connect(GetAVSignal(), &QZegoAVSignal::sigVideoDeviceChanged, this, &ZegoVideoTalkDialog::OnVideoDeviceChanged);
	//信号与槽同步执行
	connect(GetAVSignal(), &QZegoAVSignal::sigAuxInput, this, &ZegoVideoTalkDialog::OnAVAuxInput, Qt::DirectConnection);
	//标题栏按钮
	connect(ui.m_bClose, &QPushButton::clicked, this, &ZegoVideoTalkDialog::OnButtonClose);
	connect(ui.m_bMin, &QPushButton::clicked, this, &ZegoVideoTalkDialog::OnButtonMinimum);
	connect(ui.m_bMax, &QPushButton::clicked, this, &ZegoVideoTalkDialog::OnButtonMaximum);
	//ComboBox设备更改槽
	connect(ui.m_cbMircoPhone, SIGNAL(currentIndexChanged(int)), this, SLOT(OnSwitchAudioDevice(int)));
	connect(ui.m_cbCamera, SIGNAL(currentIndexChanged(int)), this, SLOT(OnSwitchVideoDevice(int)));
	//直播设置按钮
	connect(ui.m_bCapture, &QPushButton::clicked, this, &ZegoVideoTalkDialog::OnButtonCheckSoundCapture);
	connect(ui.m_bProgMircoPhone, &QPushButton::clicked, this, &ZegoVideoTalkDialog::OnButtonCheckMicroPhone);
	connect(ui.m_bSound, &QPushButton::clicked, this, &ZegoVideoTalkDialog::OnButtonCheckSpeaker);
	connect(ui.m_bAux, &QPushButton::clicked, this, &ZegoVideoTalkDialog::OnButtonCheckAux);
	connect(ui.m_bCamera, &QPushButton::clicked, this, &ZegoVideoTalkDialog::OnButtonCheckCamera);
	//hook信号槽回调
	connect(&hookDialog, &ZegoMusicHookDialog::sigUseDefaultAux, this, &ZegoVideoTalkDialog::OnUseDefaultAux);
	connect(&hookDialog, &ZegoMusicHookDialog::sigSendMusicAppPath, this, &ZegoVideoTalkDialog::OnGetMusicAppPath);

	connect(ui.m_bShowFullScreen, &QPushButton::clicked, this, &ZegoVideoTalkDialog::OnButtonFullScreen);
	timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &ZegoVideoTalkDialog::OnProgChange);

	//混音数据参数
	m_pAuxData = NULL;
	m_nAuxDataLen = 0;
	m_nAuxDataPos = 0;

	//在VideoTalk中均以SettingsPtr操作
	m_pAVSettings = m_userConfig.GetVideoSettings();
	//读取配置中用户ID和用户名
	m_strCurUserID = m_userConfig.GetUserId();
	m_strCurUserName = m_userConfig.getUserName();
	//去掉标题栏
	this->setWindowFlags(Qt::FramelessWindowHint);

	this->installEventFilter(this);
	//初始化网格布局
	gridLayout = new QGridLayout();
}

ZegoVideoTalkDialog::~ZegoVideoTalkDialog()
{

}

void ZegoVideoTalkDialog::initDialog()
{
	//在mac系统下不支持声卡采集
#ifdef Q_OS_MAC
	ui.m_bCapture->setVisible(false);
#endif
	//初始化麦克风摄像头的ComboBox
	initComboBox();

	//成员列表初始化
	m_memberModel = new QStringListModel(this);
	ui.m_listMember->setModel(m_memberModel);
	ui.m_listMember->setItemDelegate(new NoFocusFrameDelegate(this));
	ui.m_listMember->setEditTriggers(QAbstractItemView::NoEditTriggers);

	//日志列表初始化
	m_logModel = new QStandardItemModel(this);
	ui.m_listLog->setModel(m_logModel);
	ui.m_listLog->horizontalHeader()->setVisible(false);
	ui.m_listLog->verticalHeader()->setVisible(false);
	ui.m_listLog->verticalHeader()->setDefaultSectionSize(21);
	ui.m_listLog->setColumnWidth(0, 300);
	//读取标题内容
	QString strTitle = QString(tr("当前房间号：%1")).arg(m_pChatRoom->getRoomId());
	ui.m_lbRoomName->setText(strTitle);

	ui.m_edInput->setEnabled(false);
	//剩余能用的AVView
	for (int i = MAX_VIEW_COUNT; i >= 0; i--)
		m_avaliableView.push_front(i);

	// 推流成功前不能开混音、声音采集
	ui.m_bAux->setEnabled(false);
	ui.m_bCapture->setEnabled(false);

	//枚举音视频设备
	EnumVideoAndAudioDevice();

	int role = LIVEROOM::ZegoRoomRole::Audience;
	
	if (!LIVEROOM::LoginRoom(m_pChatRoom->getRoomId().toStdString().c_str(), role))
	{
		QMessageBox::information(NULL, tr("提示"), tr("进入房间失败"));
	}

	addLogString(tr("开始登陆房间"));

}

void ZegoVideoTalkDialog::StartPublishStream()
{
	QTime currentTime = QTime::currentTime();
	//获取当前时间的毫秒
	int ms = currentTime.msec();
	QString strStreamId;
#ifdef Q_OS_WIN
	strStreamId = QString("s-windows-%1-%2").arg(m_strCurUserID).arg(ms);
#else
	strStreamId = QString("s-mac-%1-%2").arg(m_strCurUserID).arg(ms);
#endif
	m_strPublishStreamID = strStreamId;

	StreamPtr pPublishStream(new QZegoStreamModel(m_strPublishStreamID, m_strCurUserID, m_strCurUserName, "", true));

	m_pChatRoom->addStream(pPublishStream);

	//推流前调用双声道
	LIVEROOM::SetAudioChannelCount(2);

	if (m_avaliableView.size() > 0)
	{

		int nIndex = takeLeastAvaliableViewIndex();
		pPublishStream->setPlayView(nIndex);
		addAVView(nIndex);
		
		if (theApp.GetBase().getUseSurfaceMerge())
		{
#if (defined Q_OS_WIN) && (defined USE_SURFACE_MERGE) 
			StartSurfaceMerge();
#endif
		}
		else
		{
			LIVEROOM::SetVideoFPS(m_pAVSettings->GetFps());
			LIVEROOM::SetVideoBitrate(m_pAVSettings->GetBitrate());
			LIVEROOM::SetVideoCaptureResolution(m_pAVSettings->GetResolution().cx, m_pAVSettings->GetResolution().cy);
			LIVEROOM::SetVideoEncodeResolution(m_pAVSettings->GetResolution().cx, m_pAVSettings->GetResolution().cy);

			//配置View
			LIVEROOM::SetPreviewView((void *)AVViews.last()->winId());
			LIVEROOM::SetPreviewViewMode(LIVEROOM::ZegoVideoViewModeScaleAspectFill);
			LIVEROOM::StartPreview();
		}

		QString streamID = m_strPublishStreamID;
		m_anchorStreamInfo = pPublishStream;
		
		addLogString(tr("创建流成功, streamID: %1").arg(streamID));
		if (LIVEROOM::StartPublishing(m_pChatRoom->getRoomName().toStdString().c_str(), streamID.toStdString().c_str(), LIVEROOM::ZEGO_JOIN_PUBLISH, ""))
		{
			m_bIsPublishing = true;
			addLogString(tr("开始直播，流ID: %1").arg(streamID));
		}
	}
}

void ZegoVideoTalkDialog::StopPublishStream(const QString& streamID)
{
	if (streamID.size() == 0){ return; }


	if (theApp.GetBase().getUseSurfaceMerge())
	{
#if (defined Q_OS_WIN) && (defined USE_SURFACE_MERGE) 
		SurfaceMerge::SetRenderView(nullptr);
		SurfaceMerge::UpdateSurface(nullptr, 0);
#endif
	}
	else
	{
		LIVEROOM::SetPreviewView(nullptr);
		LIVEROOM::StopPreview();
	}

	
	removeAVView(m_anchorStreamInfo->getPlayView());
	LIVEROOM::StopPublishing();
	m_bIsPublishing = false;
	StreamPtr pStream = m_pChatRoom->removeStream(streamID);
	FreeAVView(pStream);

	m_strPublishStreamID = "";
}

void ZegoVideoTalkDialog::StartPlayStream(StreamPtr stream)
{
	if (stream == nullptr) { return; }

	m_pChatRoom->addStream(stream);

	if (m_avaliableView.size() > 0)
	{
		int nIndex = takeLeastAvaliableViewIndex();
		qDebug() << "playStream nIndex = " << nIndex << " play stream id is " << stream->getStreamId();
		stream->setPlayView(nIndex);
		addAVView(nIndex);
		//配置View
		LIVEROOM::SetViewMode(LIVEROOM::ZegoVideoViewModeScaleAspectFill, stream->getStreamId().toStdString().c_str());
		LIVEROOM::StartPlayingStream(stream->getStreamId().toStdString().c_str(), (void *)AVViews.last()->winId());
	}
}

void ZegoVideoTalkDialog::StopPlayStream(const QString& streamID)
{
	if (streamID.size() == 0) { return; }

	StreamPtr curStream;
	for (auto stream : m_pChatRoom->getStreamList())
	{
		if (streamID == stream->getStreamId())
			curStream = stream;
	}

    if (curStream)
    {
        qDebug() << "stop play view index = " << curStream->getPlayView();
        removeAVView(curStream->getPlayView());
    }

	LIVEROOM::StopPlayingStream(streamID.toStdString().c_str());

	StreamPtr pStream = m_pChatRoom->removeStream(streamID);
	FreeAVView(pStream);
}

#if (defined Q_OS_WIN) && (defined USE_SURFACE_MERGE) 
void ZegoVideoTalkDialog::StartSurfaceMerge()
{

	int cx = m_pAVSettings->GetResolution().cx;
	int cy = m_pAVSettings->GetResolution().cy;

	SurfaceMerge::SetFPS(m_pAVSettings->GetFps());
	SurfaceMerge::SetCursorVisible(true);
	SurfaceMerge::SetSurfaceSize(cx, cy);

	SurfaceMerge::ZegoCaptureItem *itemList = new SurfaceMerge::ZegoCaptureItem[2];

	SurfaceMerge::ZegoCaptureItem itemCam;
	strcpy(itemCam.captureSource.deviceId, m_pAVSettings->GetCameraId().toStdString().c_str());
	itemCam.captureType = SurfaceMerge::CaptureType::Camera;
	itemCam.position = { cx - cx / 4, cy - cy / 4, cx / 4, cy / 4 };  //摄像头默认置于右下角

	unsigned int count = 0;
	SurfaceMerge::ScreenItem *screenList = SurfaceMerge::EnumScreenList(count);
	SurfaceMerge::ZegoCaptureItem itemWin;
	for (int i = 0; i < count; i++)
	{
		if (screenList[i].bPrimary)
		{
			strcpy(itemWin.captureSource.screenName, screenList[i].szName);
			break;
		}
	}

	itemWin.captureType = SurfaceMerge::CaptureType::Screen;
	itemWin.position = { 0, 0, cx, cy };
	itemList[0] = itemCam;
	itemList[1] = itemWin;

	SurfaceMerge::UpdateSurface(itemList, 2);
	AVViews.last()->setSurfaceMergeView(true);
	AVViews.last()->setSurfaceMergeItemRect(itemWin, itemCam);
	SurfaceMerge::SetRenderView((void *)AVViews.last()->winId());

	delete[]itemList;
	SurfaceMerge::FreeScreenList(screenList);
#endif
}

void ZegoVideoTalkDialog::addLogString(QString log)
{
	QDateTime dateTime;
	QTime time;
	QDate date;
	dateTime.setTime(time.currentTime());
	dateTime.setDate(date.currentDate());
	QString strDate = dateTime.toString("[hh-mm-ss-zzz]: ");

	QStandardItem *item = new QStandardItem;
	m_logModel->insertRow(0, item);
	QModelIndex index = m_logModel->indexFromItem(item);

	ZegoLogLabel *label = new ZegoLogLabel;
	label->setTextContent(strDate, log);
	
	
	ui.m_listLog->setIndexWidget(index, label);

	if (label->getHeightNum() > 1)
	    ui.m_listLog->resizeRowToContents(0);

	qDebug() << log;
	
}

void ZegoVideoTalkDialog::initComboBox()
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

void ZegoVideoTalkDialog::EnumVideoAndAudioDevice()
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

		if (m_pAVSettings->GetCameraId() == QString(pDeviceList[i].szDeviceId))
			curSelectionIndex = i;
		
	}

	ui.m_cbCamera->setCurrentIndex(curSelectionIndex);
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

	ui.m_cbMircoPhone->setCurrentIndex(curSelectionIndex);

	//将从mac系统API中获取的Video设备保存
	curSelectionIndex = 0;
	for (int i = 0; i < videoDeviceList.size(); ++i)
	{
		insertStringListModelItem(m_cbCameraModel, videoDeviceList[i].deviceName, m_cbCameraModel->rowCount());
		m_vecVideoDeviceIDs.push_back(videoDeviceList[i].deviceId);

		if (m_pAVSettings->GetCameraId() == videoDeviceList[i].deviceId)
			curSelectionIndex = i;
	}

	ui.m_cbCamera->setCurrentIndex(curSelectionIndex);
#endif
}

void ZegoVideoTalkDialog::BeginDefaultAux()
{
	QString filePath = QFileDialog::getOpenFileName(this,
		tr("请选择一个混音文件").toStdString().c_str(),
		"./Resources",
		tr("pcm文件(*.pcm)").toStdString().c_str());


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

void ZegoVideoTalkDialog::EndAux()
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

void ZegoVideoTalkDialog::insertStringListModelItem(QStringListModel * model, QString name, int size)
{
	if (model == nullptr)
		return;

	int row = size;
	model->insertRows(row, 1);
	QModelIndex index = model->index(row);
	model->setData(index, name);

}

void ZegoVideoTalkDialog::removeStringListModelItem(QStringListModel * model, QString name)
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

int ZegoVideoTalkDialog::takeLeastAvaliableViewIndex()
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

void ZegoVideoTalkDialog::initAVView(QZegoAVView *view)
{
	view->setMinimumSize(QSize(240, 0));
	view->setStyleSheet(QLatin1String("border: none;\n"
		"background-color: #383838;"));
}

void ZegoVideoTalkDialog::addAVView(int addViewIndex)
{
	QZegoAVView *newAVView = new QZegoAVView;
	initAVView(newAVView);
	newAVView->setViewIndex(addViewIndex);
	AVViews.push_back(newAVView);

	updateViewLayout(AVViews.size());
}

void ZegoVideoTalkDialog::removeAVView(int removeViewIndex)
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

void ZegoVideoTalkDialog::updateViewLayout(int viewCount)
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

void ZegoVideoTalkDialog::FreeAVView(StreamPtr stream)
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

void ZegoVideoTalkDialog::cleanBeforeGetOut()
{
	//离开房间时先把混音功能和声卡采集关闭
#ifdef Q_OS_WIN
	if (m_isUseDefaultAux)
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

	for (auto& stream : m_pChatRoom->getStreamList())
	{
		if (stream != nullptr){
			if (stream->isCurUserCreated())
			{
				StopPublishStream(stream->getStreamId());
			}
			else
			{
				StopPlayStream(stream->getStreamId());
			}
		}
	}

	roomMemberDelete(m_strCurUserName);
	LIVEROOM::LogoutRoom();
	if (timer != nullptr)
		timer->stop();

	//释放堆内存
	delete m_cbMircoPhoneListView;
	delete m_cbCameraListView;
	delete m_memberModel;
	delete m_cbMircoPhoneModel;
	delete m_cbCameraModel;
	delete timer;
	delete gridLayout;
	//指针置为空
	m_cbMircoPhoneListView = nullptr;
	m_cbCameraListView = nullptr;
	m_memberModel = nullptr;
	m_cbMircoPhoneModel = nullptr;
	m_cbCameraModel = nullptr;
	timer = nullptr;
	gridLayout = nullptr;
}

void ZegoVideoTalkDialog::roomMemberAdd(QString userName)
{
	if (m_memberModel == nullptr)
		return;

	insertStringListModelItem(m_memberModel, userName, m_memberModel->rowCount());
	ui.m_tabCommonAndUserList->setTabText(1, QString(tr("成员(%1)").arg(m_memberModel->rowCount())));
}

void ZegoVideoTalkDialog::roomMemberDelete(QString userName)
{
	if (m_memberModel == nullptr)
		return;

	removeStringListModelItem(m_memberModel, userName);
	ui.m_tabCommonAndUserList->setTabText(1, QString(tr("成员(%1)").arg(m_memberModel->rowCount())));
}

//-----------------------------------------------UI回调----------------------------------------------------------
void ZegoVideoTalkDialog::OnButtonClose()
{
	this->close();
}

void ZegoVideoTalkDialog::OnButtonMaximum()
{
	if (m_isMax)
	{
		this->showNormal();
		m_isMax = false;
	}
	else
	{
		this->showMaximized();
		m_isMax = true;
	}
}

void ZegoVideoTalkDialog::OnButtonMinimum()
{
	this->showMinimized();
}

void ZegoVideoTalkDialog::OnProgChange()
{
	ui.m_bProgMircoPhone->setProgValue(LIVEROOM::GetCaptureSoundLevel());
	ui.m_bProgMircoPhone->update();
}

void ZegoVideoTalkDialog::OnSwitchAudioDevice(int id)
{
	if (id < 0)
		return;

	if (id < m_vecAudioDeviceIDs.size())
	{
		LIVEROOM::SetAudioDevice(AV::AudioDevice_Input, m_vecAudioDeviceIDs[id].toStdString().c_str());
		SettingsPtr curSettings = m_userConfig.GetVideoSettings();
		curSettings->SetMicrophoneId(m_vecAudioDeviceIDs[id]);
		m_userConfig.SetVideoSettings(curSettings);
		ui.m_cbMircoPhone->setCurrentIndex(id);
	}
}

void ZegoVideoTalkDialog::OnSwitchVideoDevice(int id)
{
	if (id < 0)
		return;

	if (id < m_vecVideoDeviceIDs.size())
	{
		LIVEROOM::SetVideoDevice(m_vecVideoDeviceIDs[id].toStdString().c_str());
		SettingsPtr curSettings = m_userConfig.GetVideoSettings();
		curSettings->SetCameraId(m_vecVideoDeviceIDs[id]);
		m_userConfig.SetVideoSettings(curSettings);
		ui.m_cbCamera->setCurrentIndex(id);
	}
}

void ZegoVideoTalkDialog::OnButtonCheckMicroPhone()
{

	if (ui.m_bProgMircoPhone->isChecked())
	{
		m_bCKEnableMic = true;
		ui.m_bProgMircoPhone->setMyEnabled(true);
		timer->start(0);
	}
	else
	{
		m_bCKEnableMic = false;
		timer->stop();
		ui.m_bProgMircoPhone->setMyEnabled(false);
		ui.m_bProgMircoPhone->update();
	}

	//使用麦克风
	LIVEROOM::EnableMic(m_bCKEnableMic);
}

void ZegoVideoTalkDialog::OnButtonCheckSpeaker()
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

void ZegoVideoTalkDialog::OnButtonFullScreen()
{
	//直播窗口总在最顶层
	ui.m_zoneLiveView_Inner->setWindowFlags(ui.m_zoneLiveView_Inner->windowFlags() | Qt::WindowStaysOnTopHint);
	ui.m_zoneLiveView_Inner->setParent(NULL);
	ui.m_zoneLiveView_Inner->showFullScreen();
	m_isLiveFullScreen = true;
	
}

void ZegoVideoTalkDialog::OnButtonCheckCamera()
{
	if (ui.m_bCamera->isChecked())
	{
		m_bCKEnableCamera = true;
	}
	else
	{
		m_bCKEnableCamera = false;
	}

	//允许使用摄像头
	LIVEROOM::EnableCamera(m_bCKEnableCamera);
	update();
}

void ZegoVideoTalkDialog::OnButtonCheckAux()
{
	if (ui.m_bAux->text() == tr("开启混音"))
	{
		ui.m_bAux->setText(tr("开启中..."));
		ui.m_bAux->setEnabled(false);

#ifdef Q_OS_WIN

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

#ifdef Q_OS_WIN
		if (m_isUseDefaultAux)
		{
			EndAux();

		}
		else
		{
			AUDIOHOOK::StopAudioRecord();
			LIVEROOM::EnableAux(false);
			AUDIOHOOK::UnInitAudioHook();

		}
#elif Q_OS_MAC
		EndAux();
#endif
		ui.m_bAux->setEnabled(true);
		ui.m_bAux->setText(tr("开启混音"));
	}
}

void ZegoVideoTalkDialog::OnButtonCheckSoundCapture()
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

void ZegoVideoTalkDialog::OnUseDefaultAux(bool state)
{
	BeginDefaultAux();
	m_isUseDefaultAux = state;
	ui.m_bAux->setEnabled(true);
	ui.m_bAux->setText(tr("关闭混音"));
}

#ifdef Q_OS_WIN
void ZegoVideoTalkDialog::OnGetMusicAppPath(QString exePath)
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

void ZegoVideoTalkDialog::mousePressEvent(QMouseEvent *event)
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
	m_isMousePressed = true;
}

void ZegoVideoTalkDialog::mouseMoveEvent(QMouseEvent *event)
{
	if (m_isMousePressed == true)
	{
		QPoint movePot = event->globalPos() - mousePosition;
		move(movePot);
	}
}

void ZegoVideoTalkDialog::mouseReleaseEvent(QMouseEvent *event)
{
	m_isMousePressed = false;
}

void ZegoVideoTalkDialog::closeEvent(QCloseEvent *e)
{
	QDialog::closeEvent(e);
	cleanBeforeGetOut();
	//emit sigSaveVideoSettings(m_pAVSettings);
	m_lastDialog->show();
}

//-----------------------------------------------SDK回调-------------------------------------------------------------
void ZegoVideoTalkDialog::OnLoginRoom(int errorCode, const QString& strRoomID, QVector<StreamPtr> vStreamList)
{
	
	if (errorCode != 0)
	{
		addLogString(tr("登陆房间失败. error: %1").arg(errorCode));
		QMessageBox::information(NULL, tr("提示"), tr("登陆房间失败. error: %1").arg(errorCode));
		this->close();
		return;
	}

	addLogString(tr("登陆房间成功. roomID: %1").arg(strRoomID));

	//加入房间列表
	roomMemberAdd(m_strCurUserName);
	//登录房间成功即推流以及拉流
	StartPublishStream();

	for (auto& stream : vStreamList)
	{
		StartPlayStream(stream);
	}

}

void ZegoVideoTalkDialog::OnStreamUpdated(const QString& roomId, QVector<StreamPtr> vStreamList, LIVEROOM::ZegoStreamUpdateType type)
{
	//在连麦模式下，有流更新直接处理
	for (auto& stream : vStreamList)
	{
		if (stream != nullptr){
			if (type == LIVEROOM::ZegoStreamUpdateType::StreamAdded)
			{
				StartPlayStream(stream);
				addLogString(tr("新增一条流，流ID: %1").arg(stream->getStreamId()));

			}
			else if (type == LIVEROOM::ZegoStreamUpdateType::StreamDeleted)
			{
				StopPlayStream(stream->getStreamId());
				addLogString(tr("删除一条流，流ID: %1").arg(stream->getStreamId()));
			}
		}
	}


}

void ZegoVideoTalkDialog::OnPublishStateUpdate(int stateCode, const QString& streamId, StreamPtr streamInfo)
{

	if (stateCode == 0)
	{
		
		if (streamInfo != nullptr)
		{

			QString strUrl;
			QString strRtmpUrl = (streamInfo->m_vecRtmpUrls.size() > 0) ?
				streamInfo->m_vecRtmpUrls[0] : "";

			if (!strRtmpUrl.isEmpty())
			{
				strUrl.append("1. ");
				strUrl.append(strRtmpUrl);
				strUrl.append("\r\n");
			}

			QString strFlvUrl = (streamInfo->m_vecFlvUrls.size() > 0) ?
				streamInfo->m_vecFlvUrls[0] : "";

			if (!strFlvUrl.isEmpty())
			{
				strUrl.append("2. ");
				strUrl.append(strFlvUrl);
				strUrl.append("\r\n");
			}

			QString strHlsUrl = (streamInfo->m_vecHlsUrls.size() > 0) ?
				streamInfo->m_vecHlsUrls[0] : "";

			if (!strHlsUrl.isEmpty())
			{
				strUrl.append("3. ");
				strUrl.append(strHlsUrl);
				strUrl.append("\r\n");
			}

			addLogString(QString("Hls %1").arg(strHlsUrl));
			addLogString(QString("Rtmp %1").arg(strRtmpUrl));
			addLogString(tr("发布直播成功，流ID: %1").arg(streamId));

		}

		ui.m_bAux->setEnabled(true);
		ui.m_bCapture->setEnabled(true);
		//推流成功后启动计时器监听麦克风音量
		timer->start(0);

	}
	else
	{
		addLogString(tr("直播结束,流ID: %1, error: %2").arg(streamId).arg(stateCode));
		EndAux();
		// 停止预览, 回收view
		removeAVView(streamInfo->getPlayView());
		LIVEROOM::StopPreview();
		LIVEROOM::SetPreviewView(nullptr);
		StreamPtr pStream = m_pChatRoom->removeStream(streamId);
		FreeAVView(pStream);
	}
}

void ZegoVideoTalkDialog::OnPlayStateUpdate(int stateCode, const QString& streamId)
{
	
	if (stateCode != 0)
	{
		addLogString(tr("播放流失败，流ID: %1, error: %2").arg(streamId).arg(stateCode));
		// 回收view
		StreamPtr pStream = m_pChatRoom->removeStream(streamId);
		removeAVView(pStream->getPlayView());
		FreeAVView(pStream);
		return;
	}

	addLogString(tr("播放流成功，流ID: %1").arg(streamId));
}

void ZegoVideoTalkDialog::OnUserUpdate(QVector<QString> userIDs, QVector<QString> userNames, QVector<int> userFlags, QVector<int> userRoles, unsigned int userCount, LIVEROOM::ZegoUserUpdateType type)
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

void ZegoVideoTalkDialog::OnDisconnect(int errorCode, const QString& roomId)
{
	if (m_pChatRoom->getRoomId() == roomId)
	{
		QMessageBox::information(NULL, tr("提示"), tr("连接失败，error: %1").arg(errorCode));
		this->close();
	}
}

void ZegoVideoTalkDialog::OnKickOut(int reason, const QString& roomId)
{
	if (m_pChatRoom->getRoomId() == roomId)
	{
		QMessageBox::information(NULL, tr("提示"), tr("您已被踢出房间"));
		this->close();
	}
}

void ZegoVideoTalkDialog::OnPlayQualityUpdate(const QString& streamId, int quality, double videoFPS, double videoKBS)
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

void ZegoVideoTalkDialog::OnPublishQualityUpdate(const QString& streamId, int quality, double videoFPS, double videoKBS)
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

void ZegoVideoTalkDialog::OnAVAuxInput(unsigned char *pData, int *pDataLen, int pDataLenValue, int *pSampleRate, int *pNumChannels)
{
#ifdef Q_OS_WIN
	if (m_isUseDefaultAux)
	{
		if (m_pAuxData != nullptr && (*pDataLen < m_nAuxDataLen))
		{
			*pSampleRate = 44100;
			*pNumChannels = 2;

			if (m_nAuxDataPos + *pDataLen > m_nAuxDataLen)
			{
				m_nAuxDataPos = 0;
			}

			int nCopyLen = *pDataLen;
			memcpy(pData, m_pAuxData + m_nAuxDataPos, nCopyLen);

			m_nAuxDataPos += *pDataLen;

			*pDataLen = nCopyLen;


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

		if (m_nAuxDataPos + *pDataLen > m_nAuxDataLen)
		{
			m_nAuxDataPos = 0;
		}

		int nCopyLen = *pDataLen;
		memcpy(pData, m_pAuxData + m_nAuxDataPos, nCopyLen);

		m_nAuxDataPos += *pDataLen;

		*pDataLen = nCopyLen;


	}
	else
	{
		*pDataLen = 0;
	}
#endif
}

void ZegoVideoTalkDialog::OnAudioDeviceChanged(AV::AudioDeviceType deviceType, const QString& strDeviceId, const QString& strDeviceName, AV::DeviceState state)
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

void ZegoVideoTalkDialog::OnVideoDeviceChanged(const QString& strDeviceId, const QString& strDeviceName, AV::DeviceState state)
{
	if (state == AV::DeviceState::Device_Added)
	{
		insertStringListModelItem(m_cbCameraModel, strDeviceName, m_cbCameraModel->rowCount());
		m_vecVideoDeviceIDs.push_back(strDeviceId);
		if (m_vecVideoDeviceIDs.size() == 1)
		{
			LIVEROOM::SetVideoDevice(m_vecVideoDeviceIDs[0].toStdString().c_str());

			m_pAVSettings->SetCameraId(m_vecVideoDeviceIDs[0]);

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
					m_pAVSettings->SetCameraId(m_vecVideoDeviceIDs[0]);
					ui.m_cbCamera->setCurrentIndex(0);
				}
				else
				{
					LIVEROOM::SetVideoDevice(NULL);
					m_pAVSettings->SetCameraId("");
				}

			}
			removeStringListModelItem(m_cbCameraModel, strDeviceName);
			update();

			break;
		}
	}
}

bool ZegoVideoTalkDialog::eventFilter(QObject *target, QEvent *event)
{
	
		if (event->type() == QEvent::KeyPress)
		{
			QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
			if (keyEvent->key() == Qt::Key_Escape && m_isLiveFullScreen)
			{
				qDebug() << "clicl esc";
				ui.m_zoneLiveView_Inner->setParent(ui.m_zoneLiveView);
				ui.horizontalLayout_ForAVView->addWidget(ui.m_zoneLiveView_Inner);
				m_isLiveFullScreen = false;
				//取消直播窗口总在最顶层
				ui.m_zoneLiveView_Inner->setWindowFlags(ui.m_zoneLiveView_Inner->windowFlags() &~Qt::WindowStaysOnTopHint);
				return true;
			}
			else if (keyEvent->key() == Qt::Key_Escape && !m_isLiveFullScreen)
			{
				this->close();
				return true;
			}
		}
	
	return QDialog::eventFilter(target, event);
}
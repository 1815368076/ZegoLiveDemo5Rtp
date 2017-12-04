#include "ZegoMoreAnchorDialog.h"
#include "Signal/ZegoSDKSignal.h"
#include <QMessageBox>
#include <QDebug>
#ifdef Q_OS_MAC
#include "OSX_Objective-C/ZegoAVDevice.h"
#include "OSX_Objective-C/ZegoCGImageToQImage.h"
#endif
ZegoMoreAnchorDialog::ZegoMoreAnchorDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	//UI的信号槽
	connect(ui.m_bMin, &QPushButton::clicked, this, &ZegoMoreAnchorDialog::OnClickTitleButton);
	connect(ui.m_bMax, &QPushButton::clicked, this, &ZegoMoreAnchorDialog::OnClickTitleButton);
	connect(ui.m_bClose, &QPushButton::clicked, this, &ZegoMoreAnchorDialog::OnClickTitleButton);
}

ZegoMoreAnchorDialog::ZegoMoreAnchorDialog(qreal dpi, SettingsPtr curSettings, RoomPtr room, QString curUserID, QString curUserName, QDialog *lastDialog, QDialog *parent)
	:m_dpi(dpi),
	m_pAVSettings(curSettings),
	m_pChatRoom(room),
	m_strCurUserID(curUserID),
	m_strCurUserName(curUserName),
	m_bCKEnableMic(true),
	m_bCKEnableSpeaker(true),
	m_lastDialog(lastDialog)
{
	ui.setupUi(this);


	//通过sdk的信号连接到本类的槽函数中
	connect(GetAVSignal(), &QZegoAVSignal::sigLoginRoom, this, &ZegoMoreAnchorDialog::OnLoginRoom);
	connect(GetAVSignal(), &QZegoAVSignal::sigStreamUpdated, this, &ZegoMoreAnchorDialog::OnStreamUpdated);
	connect(GetAVSignal(), &QZegoAVSignal::sigPublishStateUpdate, this, &ZegoMoreAnchorDialog::OnPublishStateUpdate);
	connect(GetAVSignal(), &QZegoAVSignal::sigPlayStateUpdate, this, &ZegoMoreAnchorDialog::OnPlayStateUpdate);
	connect(GetAVSignal(), &QZegoAVSignal::sigDisconnect, this, &ZegoMoreAnchorDialog::OnDisconnect);
	connect(GetAVSignal(), &QZegoAVSignal::sigKickOut, this, &ZegoMoreAnchorDialog::OnKickOut);
	connect(GetAVSignal(), &QZegoAVSignal::sigPublishQualityUpdate, this, &ZegoMoreAnchorDialog::OnPublishQualityUpdate);
	connect(GetAVSignal(), &QZegoAVSignal::sigPlayQualityUpdate, this, &ZegoMoreAnchorDialog::OnPlayQualityUpdate);
	connect(GetAVSignal(), &QZegoAVSignal::sigSendRoomMessage, this, &ZegoMoreAnchorDialog::OnSendRoomMessage);
	connect(GetAVSignal(), &QZegoAVSignal::sigRecvRoomMessage, this, &ZegoMoreAnchorDialog::OnRecvRoomMessage);
	connect(GetAVSignal(), &QZegoAVSignal::sigJoinLiveRequest, this, &ZegoMoreAnchorDialog::OnJoinLiveRequest);
	connect(GetAVSignal(), &QZegoAVSignal::sigUserUpdate, this, &ZegoMoreAnchorDialog::OnUserUpdate);
	connect(GetAVSignal(), &QZegoAVSignal::sigAudioDeviceChanged, this, &ZegoMoreAnchorDialog::OnAudioDeviceChanged);
	connect(GetAVSignal(), &QZegoAVSignal::sigVideoDeviceChanged, this, &ZegoMoreAnchorDialog::OnVideoDeviceChanged);
	//信号与槽同步执行
	connect(GetAVSignal(), &QZegoAVSignal::sigAuxInput, this, &ZegoMoreAnchorDialog::OnAVAuxInput, Qt::DirectConnection);
#if (defined Q_OS_WIN) && (defined USE_SURFACE_MERGE)
	connect(GetAVSignal(), &QZegoAVSignal::sigSurfaceMergeResult, this, &ZegoMoreAnchorDialog::OnSurfaceMergeResult, Qt::DirectConnection);
#endif
	connect(GetAVSignal(), &QZegoAVSignal::sigPreviewSnapshot, this, &ZegoMoreAnchorDialog::OnPreviewSnapshot, Qt::DirectConnection);
	connect(GetAVSignal(), &QZegoAVSignal::sigSnapshot, this, &ZegoMoreAnchorDialog::OnSnapshot, Qt::DirectConnection);

	//UI的信号槽
	connect(ui.m_bMin, &QPushButton::clicked, this, &ZegoMoreAnchorDialog::OnClickTitleButton);
	connect(ui.m_bMax, &QPushButton::clicked, this, &ZegoMoreAnchorDialog::OnClickTitleButton);
	connect(ui.m_bClose, &QPushButton::clicked, this, &ZegoMoreAnchorDialog::OnClickTitleButton);

	connect(ui.m_bRequestJoinLive, &QPushButton::clicked, this, &ZegoMoreAnchorDialog::OnButtonSwitchPublish);
	connect(ui.m_bSendMessage, &QPushButton::clicked, this, &ZegoMoreAnchorDialog::OnButtonSendMessage);
	connect(ui.m_bCapture, &QPushButton::clicked, this, &ZegoMoreAnchorDialog::OnButtonSoundCapture);
	connect(ui.m_bProgMircoPhone, &QPushButton::clicked, this, &ZegoMoreAnchorDialog::OnButtonMircoPhone);
	connect(ui.m_bSound, &QPushButton::clicked, this, &ZegoMoreAnchorDialog::OnButtonSound);
	connect(ui.m_bShare, &QPushButton::clicked, this, &ZegoMoreAnchorDialog::OnShareLink);
	connect(ui.m_bAux, &QPushButton::clicked, this, &ZegoMoreAnchorDialog::OnButtonAux);
	connect(ui.m_bFullScreen, &QPushButton::clicked, this, &ZegoMoreAnchorDialog::OnButtonShowFullScreen);
	connect(ui.m_cbMircoPhone, SIGNAL(currentIndexChanged(int)), this, SLOT(OnSwitchAudioDevice(int)));
	connect(ui.m_cbCamera, SIGNAL(currentIndexChanged(int)), this, SLOT(OnSwitchVideoDevice(int)));

#ifdef Q_OS_WIN
	connect(&hookDialog, &ZegoMusicHookDialog::sigUseDefaultAux, this, &ZegoMoreAnchorDialog::OnUseDefaultAux);
	connect(&hookDialog, &ZegoMusicHookDialog::sigSendMusicAppPath, this, &ZegoMoreAnchorDialog::OnGetMusicAppPath);
#endif
	connect(this, &ZegoMoreAnchorDialog::sigShowSnapShotImage, this, &ZegoMoreAnchorDialog::OnShowSnapShotImage);

	timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &ZegoMoreAnchorDialog::OnProgChange);

	//混音数据参数
	m_pAuxData = NULL;
	m_nAuxDataLen = 0;
	m_nAuxDataPos = 0;

	this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏 

	ui.m_edInput->installEventFilter(this);
	this->installEventFilter(this);

	//初始化网格布局
	gridLayout = new QGridLayout();
}

ZegoMoreAnchorDialog::~ZegoMoreAnchorDialog()
{

}

//功能函数
void ZegoMoreAnchorDialog::initDialog()
{
	//在mac系统下不支持声卡采集
#ifdef Q_OS_MAC
	ui.m_bCapture->setVisible(false);
#endif

	//在主播端，请求连麦的按钮变为直播开关
	ui.m_bRequestJoinLive->setText(QStringLiteral("停止直播"));

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

	//读取标题内容
	QString strTitle = QString(QStringLiteral("【%1】%2")).arg(QStringLiteral("连麦模式")).arg(m_pChatRoom->getRoomName());
	ui.m_lbRoomName->setText(strTitle);

	//剩余能用的AVView
	for (int i = MAX_VIEW_COUNT; i >= 0; i--)
		m_avaliableView.push_front(i);
	
	//推流成功前不能开混音、声音采集、分享、停止直播
	ui.m_bAux->setEnabled(false);
	ui.m_bCapture->setEnabled(false);
	ui.m_bShare->setEnabled(false);
	ui.m_bRequestJoinLive->setEnabled(false);
	ui.m_lbCamera2->setVisible(false);
	ui.m_cbCamera2->setVisible(false);

	//允许使用麦克风
	LIVEROOM::EnableMic(m_bCKEnableMic);

	//枚举音视频设备
	EnumVideoAndAudioDevice();

	int role = LIVEROOM::ZegoRoomRole::Anchor;
	if (!LIVEROOM::LoginRoom(m_pChatRoom->getRoomId().toStdString().c_str(), role, m_pChatRoom->getRoomName().toStdString().c_str()))
	{
		QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("进入房间失败"));
	}

}

void ZegoMoreAnchorDialog::StartPublishStream()
{

	QTime currentTime = QTime::currentTime();
	//获取当前时间的毫秒
	int ms = currentTime.msec();
	QString strStreamId;
#ifdef Q_OS_WIN
	strStreamId = QString(QStringLiteral("s-windows-%1-%2")).arg(m_strCurUserID).arg(ms);
#else
	strStreamId = QString(QStringLiteral("s-mac-%1-%2")).arg(m_strCurUserID).arg(ms);
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
		AVViews.last()->setCurUser();
		connect(AVViews.last(), &QZegoAVView::sigSnapShotPreviewOnMoreAnchor, this, &ZegoMoreAnchorDialog::OnSnapshotPreview);

		qDebug() << "publish nIndex = " << nIndex << "publish stream id is" << pPublishStream->getStreamId();
		if (m_pAVSettings->GetSurfaceMerge())
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
			LIVEROOM::SetPreviewViewMode(LIVEROOM::ZegoVideoViewModeScaleAspectFit);
			LIVEROOM::StartPreview();
		}

		QString streamID = m_strPublishStreamID;
		m_anchorStreamInfo = pPublishStream;
		AVViews.last()->setViewStreamID(streamID);
		setWaterPrint();
		qDebug() << "start publishing!";
		if (!m_pAVSettings->GetUsePublish2Stream())
		{
			LIVEROOM::StartPublishing(m_pChatRoom->getRoomName().toStdString().c_str(), streamID.toStdString().c_str(), LIVEROOM::ZEGO_JOIN_PUBLISH, "");
		}
		else
		{
			LIVEROOM::StartPublishing2(m_pChatRoom->getRoomName().toStdString().c_str(), streamID.toStdString().c_str(), LIVEROOM::ZEGO_JOIN_PUBLISH, "");
		}
		m_bIsPublishing = true;
	}
}

void ZegoMoreAnchorDialog::StartPublishStream_Aux()
{
	QTime currentTime = QTime::currentTime();
	//获取当前时间的毫秒
	int ms = currentTime.msec();
	QString strStreamId;
#ifdef Q_OS_WIN
	strStreamId = QString(QStringLiteral("s-windows-%1-%2-aux")).arg(m_strCurUserID).arg(ms);
#else
	strStreamId = QString(QStringLiteral("s-mac-%1-%2-aux")).arg(m_strCurUserID).arg(ms);
#endif
	m_strPublishStreamID_Aux = strStreamId;

	StreamPtr pPublishStream(new QZegoStreamModel(m_strPublishStreamID_Aux, m_strCurUserID, m_strCurUserName, "", true, true));

	m_pChatRoom->addStream(pPublishStream);

	//推流前调用双声道
	LIVEROOM::SetAudioChannelCount(2);

	if (m_avaliableView.size() > 0)
	{

		int nIndex = takeLeastAvaliableViewIndex();
		pPublishStream->setPlayView(nIndex);
		addAVView(nIndex);
		AVViews.last()->setCurUser();
		connect(AVViews.last(), &QZegoAVView::sigSnapShotPreviewOnMoreAnchor, this, &ZegoMoreAnchorDialog::OnSnapshotPreview);

		qDebug() << "publish nIndex = " << nIndex << "publish stream id is" << pPublishStream->getStreamId();
		if (m_pAVSettings->GetSurfaceMerge())
		{
#if (defined Q_OS_WIN) && (defined USE_SURFACE_MERGE) 
			StartSurfaceMerge();
#endif
		}
		else
		{
			LIVEROOM::SetVideoFPS(m_pAVSettings->GetFps(), ZEGO::AV::PUBLISH_CHN_AUX);
			LIVEROOM::SetVideoBitrate(m_pAVSettings->GetBitrate(), ZEGO::AV::PUBLISH_CHN_AUX);
			LIVEROOM::SetVideoCaptureResolution(m_pAVSettings->GetResolution().cx, m_pAVSettings->GetResolution().cy, ZEGO::AV::PUBLISH_CHN_AUX);
			LIVEROOM::SetVideoEncodeResolution(m_pAVSettings->GetResolution().cx, m_pAVSettings->GetResolution().cy, ZEGO::AV::PUBLISH_CHN_AUX);

			//配置View
			LIVEROOM::SetPreviewView((void *)AVViews.last()->winId(), ZEGO::AV::PUBLISH_CHN_AUX);
			LIVEROOM::SetPreviewViewMode(LIVEROOM::ZegoVideoViewModeScaleAspectFit, ZEGO::AV::PUBLISH_CHN_AUX);
			LIVEROOM::StartPreview(ZEGO::AV::PUBLISH_CHN_AUX);
		}

		QString streamID = m_strPublishStreamID_Aux;
		m_anchorStreamInfo_Aux = pPublishStream;
		AVViews.last()->setViewStreamID(streamID);
		setWaterPrint();
		qDebug() << "start publishing aux!";
		LIVEROOM::StartPublishing2(m_pChatRoom->getRoomName().toStdString().c_str(), streamID.toStdString().c_str(), LIVEROOM::ZEGO_JOIN_PUBLISH, "", ZEGO::AV::PUBLISH_CHN_AUX);
		//m_bIsPublishing = true;
	}
}

void ZegoMoreAnchorDialog::StopPublishStream(const QString& streamID, AV::PublishChannelIndex idx)
{
	if (streamID.size() == 0){ return; }

	
	if (m_pAVSettings->GetSurfaceMerge())
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
		if (idx == ZEGO::AV::PUBLISH_CHN_MAIN)
		{
			LIVEROOM::SetPreviewView(nullptr);
			LIVEROOM::StopPreview();
		}
		else
		{
			LIVEROOM::SetPreviewView(nullptr, ZEGO::AV::PUBLISH_CHN_AUX);
			LIVEROOM::StopPreview(ZEGO::AV::PUBLISH_CHN_AUX);
		}
	}

	if (idx == ZEGO::AV::PUBLISH_CHN_MAIN)
	{
		qDebug() << "stop publish view index = " << m_anchorStreamInfo->getPlayView();
		removeAVView(m_anchorStreamInfo->getPlayView());
		LIVEROOM::StopPublishing();
		m_bIsPublishing = false;
		StreamPtr pStream = m_pChatRoom->removeStream(streamID);
		FreeAVView(pStream);
		m_strPublishStreamID = "";
	}
	else
	{
		qDebug() << "stop publish view index = " << m_anchorStreamInfo_Aux->getPlayView();
		removeAVView(m_anchorStreamInfo_Aux->getPlayView());
		LIVEROOM::StopPublishing(0, 0, ZEGO::AV::PUBLISH_CHN_AUX);
		m_bIsPublishing = false;
		StreamPtr pStream = m_pChatRoom->removeStream(streamID);
		FreeAVView(pStream);
		m_strPublishStreamID_Aux = "";
	}
	
}

void ZegoMoreAnchorDialog::StartPlayStream(StreamPtr stream)
{
	if (stream == nullptr) { return; }

	m_pChatRoom->addStream(stream);

	if (m_avaliableView.size() > 0)
	{
		int nIndex = takeLeastAvaliableViewIndex();
		qDebug() << "playStream nIndex = " << nIndex <<" play stream id is "<<stream->getStreamId();
		stream->setPlayView(nIndex);
		addAVView(nIndex);
		connect(AVViews.last(), &QZegoAVView::sigSnapShotOnMoreAnchorWithStreamID, this, &ZegoMoreAnchorDialog::OnSnapshotWithStreamID);
		AVViews.last()->setViewStreamID(stream->getStreamId());

		//配置View
		LIVEROOM::SetViewMode(LIVEROOM::ZegoVideoViewModeScaleAspectFit, stream->getStreamId().toStdString().c_str());
		LIVEROOM::StartPlayingStream(stream->getStreamId().toStdString().c_str(), (void *)AVViews.last()->winId());
	}
}

void ZegoMoreAnchorDialog::StopPlayStream(const QString& streamID)
{
	if (streamID.size() == 0) { return; }

	StreamPtr curStream;
	for (auto stream : m_pChatRoom->getStreamList())
	{
		if (streamID == stream->getStreamId())
			curStream = stream;
	}

	qDebug() << "stop play view index = " << curStream->getPlayView();

	removeAVView(curStream->getPlayView());
	LIVEROOM::StopPlayingStream(streamID.toStdString().c_str());

	StreamPtr pStream = m_pChatRoom->removeStream(streamID);
	FreeAVView(pStream);
}

void ZegoMoreAnchorDialog::GetOut()
{
	//离开房间时先把混音功能和声卡采集关闭
#ifdef Q_OS_WIN
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

	if (ui.m_bCapture->text() == QStringLiteral("停止采集"))
#ifdef Q_OS_WIN
		LIVEROOM::EnableMixSystemPlayout(false);
#endif

	for (auto& stream : m_pChatRoom->getStreamList())
	{
		if (stream != nullptr){
			if (stream->isCurUserCreated())
			{
				if (!stream->isCurUserCreated_Aux())
				    StopPublishStream(stream->getStreamId());
				else
					StopPublishStream(stream->getStreamId(), ZEGO::AV::PUBLISH_CHN_AUX);
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
	delete m_chatModel;
	delete m_cbMircoPhoneModel;
	delete m_cbCameraModel;
	delete timer;
	delete gridLayout;
	//指针置为空
	m_cbMircoPhoneListView = nullptr;
	m_cbCameraListView = nullptr;
	m_memberModel = nullptr;
	m_chatModel = nullptr;
	m_cbMircoPhoneModel = nullptr;
	m_cbCameraModel = nullptr;
	timer = nullptr;
	gridLayout = nullptr;
}

#if (defined Q_OS_WIN) && (defined USE_SURFACE_MERGE) 
void ZegoMoreAnchorDialog::StartSurfaceMerge()
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
}
#endif

void ZegoMoreAnchorDialog::initComboBox()
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

	m_cbCameraListView2 = new QListView(this);
	ui.m_cbCamera2->setView(m_cbCameraListView2);
	ui.m_cbCamera2->setModel(m_cbCameraModel);
	ui.m_cbCamera2->setItemDelegate(new NoFocusFrameDelegate(this));
}

void ZegoMoreAnchorDialog::EnumVideoAndAudioDevice()
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

	ui.m_cbCamera->blockSignals(true);
	ui.m_cbCamera->setCurrentIndex(curSelectionIndex);
	ui.m_cbCamera->blockSignals(false);
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
		ui.m_cbCamera2->setModel(new QStringListModel(this));
	}
	else
	{
		ui.m_cbCamera2->blockSignals(true);
		ui.m_cbCamera2->setCurrentIndex(curSelectionIndex);
		ui.m_cbCamera2->blockSignals(false);
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

void ZegoMoreAnchorDialog::insertStringListModelItem(QStringListModel * model, QString name, int size)
{
	if (model == nullptr)
		return;

	int row = size;
	model->insertRows(row, 1);
	QModelIndex index = model->index(row);
	model->setData(index, name);

}

void ZegoMoreAnchorDialog::removeStringListModelItem(QStringListModel * model, QString name)
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

int ZegoMoreAnchorDialog::takeLeastAvaliableViewIndex()
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

void ZegoMoreAnchorDialog::initAVView(QZegoAVView *view)
{
	view->setMinimumSize(QSize(240, 0));
	view->setStyleSheet(QLatin1String("border: none;\n"
		"background-color: #383838;"));
}

void ZegoMoreAnchorDialog::addAVView(int addViewIndex)
{
	QZegoAVView *newAVView = new QZegoAVView(ZEGODIALOG_MoreAnchor);

	initAVView(newAVView);
	newAVView->setViewIndex(addViewIndex);
	AVViews.push_back(newAVView);

	updateViewLayout(AVViews.size());
}

void ZegoMoreAnchorDialog::removeAVView(int removeViewIndex)
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

void ZegoMoreAnchorDialog::updateViewLayout(int viewCount)
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

void ZegoMoreAnchorDialog::FreeAVView(StreamPtr stream)
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

QString ZegoMoreAnchorDialog::encodeStringAddingEscape(QString str)
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

void ZegoMoreAnchorDialog::roomMemberAdd(QString userName)
{
	if (m_memberModel == nullptr)
		return;

	insertStringListModelItem(m_memberModel, userName, m_memberModel->rowCount());
	ui.m_tabCommonAndUserList->setTabText(1, QString(QStringLiteral("成员(%1)").arg(m_memberModel->rowCount())));
}

void ZegoMoreAnchorDialog::roomMemberDelete(QString userName)
{
	if (m_memberModel == nullptr)
		return;

	removeStringListModelItem(m_memberModel, userName);
	ui.m_tabCommonAndUserList->setTabText(1, QString(QStringLiteral("成员(%1)").arg(m_memberModel->rowCount())));
}

bool ZegoMoreAnchorDialog::praseJsonData(QJsonDocument doc)
{
	QJsonObject obj = doc.object();

	QJsonValue isFirstAnchor = obj.take(m_FirstAnchor);
	QJsonValue hlsUrl = obj.take(m_HlsKey);
	QJsonValue rtmpUrl = obj.take(m_RtmpKey);

	sharedHlsUrl = hlsUrl.toString();
	sharedRtmpUrl = rtmpUrl.toString();

	return true;
}

void ZegoMoreAnchorDialog::BeginAux()
{
	QString filePath = QFileDialog::getOpenFileName(this,
		tr(QStringLiteral("请选择一个混音文件").toStdString().c_str()),
		"./Resources",
		tr(QStringLiteral("pcm文件(*.pcm)").toStdString().c_str()));


	if (!filePath.isEmpty())
	{
		FILE* fAux;
		fAux = fopen(filePath.toStdString().c_str(), "rb");

		if (fAux == NULL)
		{
			QMessageBox::warning(this, QStringLiteral("警告"), QStringLiteral("文件内容错误: %1").arg(filePath));
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

		ui.m_bAux->setText(QStringLiteral("关闭混音"));
	}
}

void ZegoMoreAnchorDialog::EndAux()
{
	LIVEROOM::EnableAux(false);

	ui.m_bAux->setText(QStringLiteral("开启混音"));
	if (m_pAuxData)
	{
		delete[] m_pAuxData;
		m_pAuxData = NULL;
	}
	m_nAuxDataLen = 0;
	m_nAuxDataPos = 0;
}

void ZegoMoreAnchorDialog::setWaterPrint()
{
	QString waterPrintPath = QDir::currentPath();
	waterPrintPath += "/Resources/images/";
	if (m_dpi < 2.0)
	{
		waterPrintPath += "waterprint.png";
	}
	else
	{
		waterPrintPath += "@2x/waterprint@2x.png";
	}

	QImage waterPrint(waterPrintPath);

	//标准640 * 360，根据标准对当前分辨率的水印进行等比缩放
	int cx = m_pAVSettings->GetResolution().cx;
	int cy = m_pAVSettings->GetResolution().cy;
	float scaleX = cx * 1.0 / 640;
	float scaleY = cy * 1.0 / 360;

	LIVEROOM::SetPublishWaterMarkRect((int)(20 * scaleX), (int)(20 * scaleY), (int)(123 * scaleX), (int)(69 * scaleY));
	LIVEROOM::SetPreviewWaterMarkRect((int)(20 * scaleX), (int)(20 * scaleY), (int)(123 * scaleX), (int)(69 * scaleY));
	LIVEROOM::SetWaterMarkImagePath(waterPrintPath.toStdString().c_str());
}

int ZegoMoreAnchorDialog::getCameraIndexFromID(const QString& cameraID)
{
	for (int i = 0; i < m_vecVideoDeviceIDs.size(); ++i)
	{
		if (m_vecVideoDeviceIDs[i] == cameraID)
			return i;
	}

	return -1;
}

//SDK回调
void ZegoMoreAnchorDialog::OnLoginRoom(int errorCode, const QString& strRoomID, QVector<StreamPtr> vStreamList)
{
	qDebug() << "Login Room!";
	if (errorCode != 0)
	{
		QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("登陆房间失败,错误码: %1").arg(errorCode));
        OnClose();
		return;
	}

	//加入房间列表
	roomMemberAdd(m_strCurUserName);

    StartPublishStream();
	if (m_pAVSettings->GetUsePublish2Stream())
	    StartPublishStream_Aux();

}

void ZegoMoreAnchorDialog::OnStreamUpdated(const QString& roomId, QVector<StreamPtr> vStreamList, LIVEROOM::ZegoStreamUpdateType type)
{
	//在连麦模式下，有流更新直接处理
	for (auto& stream : vStreamList)
	{
		if (stream != nullptr){
			if (type == LIVEROOM::ZegoStreamUpdateType::StreamAdded)
			{
				StartPlayStream(stream);

			}
			else if (type == LIVEROOM::ZegoStreamUpdateType::StreamDeleted)
			{
				StopPlayStream(stream->getStreamId());

			}
		}
	}
	
	
}

void ZegoMoreAnchorDialog::OnPublishStateUpdate(int stateCode, const QString& streamId, StreamPtr streamInfo)
{
	
	if (stateCode == 0)
	{
		qDebug() << "Publish success!";
		if (streamInfo != nullptr)
		{
			
			//m_anchorStreamInfo = streamInfo;
			sharedHlsUrl = streamInfo->m_vecHlsUrls[0];
			sharedRtmpUrl = streamInfo->m_vecRtmpUrls[0];
			
			QString strUrl;

			QString strRtmpUrl = (streamInfo->m_vecRtmpUrls.size() > 0) ?
				streamInfo->m_vecRtmpUrls[0] : QStringLiteral("");

			if (!strRtmpUrl.isEmpty())
			{
				strUrl.append(QStringLiteral("1. "));
				strUrl.append(strRtmpUrl);
				strUrl.append(QStringLiteral("\r\n"));
			}

			QString strFlvUrl = (streamInfo->m_vecFlvUrls.size() > 0) ?
				streamInfo->m_vecFlvUrls[0] : QStringLiteral("");

			if (!strFlvUrl.isEmpty())
			{
				strUrl.append(QStringLiteral("2. "));
				strUrl.append(strFlvUrl);
				strUrl.append(QStringLiteral("\r\n"));
			}

			QString strHlsUrl = (streamInfo->m_vecHlsUrls.size() > 0) ?
				streamInfo->m_vecHlsUrls[0] : QStringLiteral("");

			if (!strHlsUrl.isEmpty())
			{
				strUrl.append(QStringLiteral("3. "));
				strUrl.append(strHlsUrl);
				strUrl.append(QStringLiteral("\r\n"));
			}

		}

		//在连麦模式下，推流成功时需将流媒体地址存到流附加信息中
		if (sharedHlsUrl.size() > 0 && sharedRtmpUrl.size() > 0)
		{
			//封装存放分享地址的json对象
			QMap<QString, QString> mapUrls = QMap<QString, QString>();

			mapUrls.insert(m_FirstAnchor, "true");
			mapUrls.insert(m_HlsKey, sharedHlsUrl);
			mapUrls.insert(m_RtmpKey, sharedRtmpUrl);

			QVariantMap vMap;
			QMapIterator<QString, QString> it(mapUrls);
			while (it.hasNext())
			{
				it.next();
				vMap.insert(it.key(), it.value());
			}

			QJsonDocument doc = QJsonDocument::fromVariant(vMap);
			QByteArray jba = doc.toJson();
			QString jsonString = QString(jba);
			//设置流附加消息，将混流信息传入
			LIVEROOM::SetPublishStreamExtraInfo(jsonString.toStdString().c_str());
		}
		
		ui.m_bAux->setEnabled(true);
		ui.m_bCapture->setEnabled(true);
		ui.m_bShare->setEnabled(true);

		ui.m_bRequestJoinLive->setText(QStringLiteral("停止直播"));
		ui.m_bRequestJoinLive->setEnabled(true);

		//推流成功后启动计时器监听麦克风音量
		timer->start(0);

	}
	else
	{
		QMessageBox::warning(NULL, QStringLiteral("推流失败"), QStringLiteral("错误码: %1").arg(stateCode));
		ui.m_bRequestJoinLive->setText(QStringLiteral("开始直播"));
		ui.m_bRequestJoinLive->setEnabled(true);
		EndAux();
		// 停止预览, 回收view
		removeAVView(streamInfo->getPlayView());
		LIVEROOM::StopPreview();
		LIVEROOM::SetPreviewView(nullptr);
		StreamPtr pStream = m_pChatRoom->removeStream(streamId);
		FreeAVView(pStream);
	}
}

void ZegoMoreAnchorDialog::OnPlayStateUpdate(int stateCode, const QString& streamId)
{
	qDebug() << "OnPlay! stateCode = " << stateCode;

	ui.m_bShare->setEnabled(true);

	if (stateCode != 0)
	{
		// 回收view
		StreamPtr pStream = m_pChatRoom->removeStream(streamId);
		removeAVView(pStream->getPlayView());
		FreeAVView(pStream);
	}


}

void ZegoMoreAnchorDialog::OnUserUpdate(QVector<QString> userIDs, QVector<QString> userNames, QVector<int> userFlags, QVector<int> userRoles, unsigned int userCount, LIVEROOM::ZegoUserUpdateType type)
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

	ui.m_tabCommonAndUserList->setTabText(1, QString(QStringLiteral("成员(%1)").arg(m_memberModel->rowCount())));
	ui.m_listMember->update();
}

void ZegoMoreAnchorDialog::OnDisconnect(int errorCode, const QString& roomId)
{
	if (m_pChatRoom->getRoomId() == roomId)
	{
		QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("您已掉线"));
		OnClose();
	}
}

void ZegoMoreAnchorDialog::OnKickOut(int reason, const QString& roomId)
{
	if (m_pChatRoom->getRoomId() == roomId)
	{
		QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("您已被踢出房间"));
		OnClose();
	}
}

void ZegoMoreAnchorDialog::OnPlayQualityUpdate(const QString& streamId, int quality, double videoFPS, double videoKBS)
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

void ZegoMoreAnchorDialog::OnPublishQualityUpdate(const QString& streamId, int quality, double videoFPS, double videoKBS)
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

void ZegoMoreAnchorDialog::OnAVAuxInput(unsigned char *pData, int *pDataLen, int pDataLenValue, int *pSampleRate, int *pNumChannels)
{
#ifdef Q_OS_WIN
	if (isUseDefaultAux)
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

void ZegoMoreAnchorDialog::OnSendRoomMessage(int errorCode, const QString& roomID, int sendSeq, unsigned long long messageId)
{
	if (errorCode != 0)
	{
		QMessageBox::warning(NULL, QStringLiteral("消息发送失败"), QStringLiteral("错误码: %1").arg(errorCode));
		return;
	}

	qDebug() << "message send success";
}

void ZegoMoreAnchorDialog::OnRecvRoomMessage(const QString& roomId, QVector<RoomMsgPtr> vRoomMsgList)
{
	for (auto& roomMsg : vRoomMsgList)
	{
		QString strTmpContent;
		strTmpContent = QString(QStringLiteral("%1")).arg(roomMsg->getContent());
		
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

void ZegoMoreAnchorDialog::OnJoinLiveRequest(int seq, const QString& fromUserId, const QString& fromUserName, const QString& roomId)
{
	QMessageBox box(QMessageBox::Warning, QStringLiteral("提示"), QString(QStringLiteral("%1正在请求连麦")).arg(fromUserId));
	box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	if (box.exec() == QMessageBox::Ok)
	{
		LIVEROOM::RespondJoinLiveReq(seq, 0);
	}
	else
	{
		LIVEROOM::RespondJoinLiveReq(seq, -1);
	}
}

void ZegoMoreAnchorDialog::OnAudioDeviceChanged(AV::AudioDeviceType deviceType, const QString& strDeviceId, const QString& strDeviceName, AV::DeviceState state)
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

void ZegoMoreAnchorDialog::OnVideoDeviceChanged(const QString& strDeviceId, const QString& strDeviceName, AV::DeviceState state)
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
			ui.m_cbCamera->blockSignals(true);
			ui.m_cbCamera->setCurrentIndex(0);
			ui.m_cbCamera->blockSignals(false);

			ui.m_cbCamera->blockSignals(true);
			ui.m_cbCamera2->setModel(new QStringListModel(this));
			ui.m_cbCamera->blockSignals(false);

		}
		//当前摄像头有两个的话，将最新加入的摄像头分配给摄像头2
		else if (m_vecVideoDeviceIDs.size() == 2)
		{
			LIVEROOM::StopPreview(ZEGO::AV::PUBLISH_CHN_AUX);
			LIVEROOM::SetVideoDevice(strDeviceId.toStdString().c_str(), ZEGO::AV::PUBLISH_CHN_AUX);

			m_pAVSettings->SetCameraId2(strDeviceId);

			ui.m_cbCamera2->blockSignals(true);
			ui.m_cbCamera2->setModel(m_cbCameraModel);
			ui.m_cbCamera2->setCurrentIndex(1);
			ui.m_cbCamera2->blockSignals(false);

			ui.m_cbCamera->blockSignals(true);
			ui.m_cbCamera->setCurrentIndex(0);
			ui.m_cbCamera->blockSignals(false);
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
						ui.m_cbCamera->blockSignals(true);
						ui.m_cbCamera->setCurrentIndex(currentCurl_2);
						ui.m_cbCamera->blockSignals(false);

						ui.m_cbCamera2->blockSignals(true);
						ui.m_cbCamera2->setModel(new QStringListModel(this));
						ui.m_cbCamera2->blockSignals(false);

						m_pAVSettings->SetCameraId2("");
					}
					else
					{
						LIVEROOM::SetVideoDevice(m_vecVideoDeviceIDs[index].toStdString().c_str());
						m_pAVSettings->SetCameraId(m_vecVideoDeviceIDs[index]);
						ui.m_cbCamera->blockSignals(true);
						ui.m_cbCamera->setCurrentIndex(index);
						ui.m_cbCamera->blockSignals(false);
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
						ui.m_cbCamera2->blockSignals(true);
						ui.m_cbCamera2->setModel(new QStringListModel(this));
						ui.m_cbCamera2->blockSignals(false);
						m_pAVSettings->SetCameraId2("");
					}
					else
					{
						LIVEROOM::SetVideoDevice(m_vecVideoDeviceIDs[index].toStdString().c_str(), ZEGO::AV::PUBLISH_CHN_AUX);
						m_pAVSettings->SetCameraId2(m_vecVideoDeviceIDs[index]);
						ui.m_cbCamera2->blockSignals(true);
						ui.m_cbCamera2->setCurrentIndex(index);
						ui.m_cbCamera2->blockSignals(false);
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

#if (defined Q_OS_WIN) && (defined USE_SURFACE_MERGE)
void ZegoMoreAnchorDialog::OnSurfaceMergeResult(unsigned char *surfaceMergeData, int datalength)
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

void ZegoMoreAnchorDialog::OnPreviewSnapshot(void *pImage)
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

void ZegoMoreAnchorDialog::OnSnapshot(void *pImage, const QString &streamID)
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
void ZegoMoreAnchorDialog::OnClickTitleButton()
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
		}
		else
		{
			this->showMaximized();
			isMax = true;
		}
	}
}

void ZegoMoreAnchorDialog::OnButtonSwitchPublish()
{
	//当前按钮文本为“开始直播”
	if (ui.m_bRequestJoinLive->text() == QStringLiteral("开始直播"))
	{
		ui.m_bRequestJoinLive->setText(QStringLiteral("开启中..."));
		ui.m_bRequestJoinLive->setEnabled(false);
		//开始推流
		StartPublishStream();
		if (m_pAVSettings->GetUsePublish2Stream())
			StartPublishStream_Aux();

	}
	//当前按钮文本为“停止直播”
	else
	{
		ui.m_bRequestJoinLive->setText(QStringLiteral("停止中..."));
		ui.m_bRequestJoinLive->setEnabled(false);
		StopPublishStream(m_strPublishStreamID);
		if (m_pAVSettings->GetUsePublish2Stream())
			StopPublishStream(m_strPublishStreamID_Aux, ZEGO::AV::PUBLISH_CHN_AUX);

		if (ui.m_bAux->text() == QStringLiteral("关闭混音"))
		{
			ui.m_bAux->setText(QStringLiteral("关闭中..."));
			ui.m_bAux->setEnabled(false);

#ifdef Q_OS_WIN
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
			ui.m_bAux->setText(QStringLiteral("开启混音"));
		}

		//停止直播后不能混音、声音采集、分享
		ui.m_bAux->setEnabled(false);
		ui.m_bCapture->setEnabled(false);
		ui.m_bShare->setEnabled(false);
		ui.m_bRequestJoinLive->setEnabled(true);
		ui.m_bRequestJoinLive->setText(QStringLiteral("开始直播"));
	}
}

void ZegoMoreAnchorDialog::OnClose()
{
	//GetOut();
	this->close();
	//m_lastDialog->show();
}

void ZegoMoreAnchorDialog::OnButtonSendMessage()
{
	QString strChat;
	strChat = ui.m_edInput->toPlainText();

	m_strLastSendMsg = strChat;
	m_strLastSendMsg = m_strLastSendMsg.trimmed();

	if (!m_strLastSendMsg.isEmpty())
		LIVEROOM::SendRoomMessage(ROOM::ZegoMessageType::Text, ROOM::ZegoMessageCategory::Chat, ROOM::ZegoMessagePriority::Default, m_strLastSendMsg.toStdString().c_str());

	ui.m_edInput->setText(QStringLiteral(""));

	QString strTmpContent;
	strTmpContent = QString(QStringLiteral("%1")).arg(m_strLastSendMsg);

	QStandardItem *item = new QStandardItem;
	m_chatModel->appendRow(item);
	QModelIndex index = m_chatModel->indexFromItem(item);

	ZegoRoomMessageLabel *chatContent = new ZegoRoomMessageLabel;
	chatContent->setTextContent(QStringLiteral("我"), strTmpContent);

	ui.m_listChat->setIndexWidget(index, chatContent);
	if (chatContent->getHeightNum() > 1)
		ui.m_listChat->resizeRowToContents(m_chatModel->rowCount() - 1);

	//每次发送消息均显示最后一条
	ui.m_listChat->scrollToBottom();
	m_strLastSendMsg.clear();

}

void ZegoMoreAnchorDialog::OnButtonSoundCapture()
{
	if (ui.m_bCapture->text() == QStringLiteral("声卡采集"))
	{
#ifdef Q_OS_WIN
		LIVEROOM::EnableMixSystemPlayout(true);
#endif
		ui.m_bCapture->setText(QStringLiteral("停止采集"));
	}
	else
	{
#ifdef Q_OS_WIN
		LIVEROOM::EnableMixSystemPlayout(false);
#endif
		ui.m_bCapture->setText(QStringLiteral("声卡采集"));
	}
}

void ZegoMoreAnchorDialog::OnButtonMircoPhone()
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

void ZegoMoreAnchorDialog::OnButtonSound()
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

void ZegoMoreAnchorDialog::OnProgChange()
{
	ui.m_bProgMircoPhone->setProgValue(LIVEROOM::GetCaptureSoundLevel());
	ui.m_bProgMircoPhone->update();
}

void ZegoMoreAnchorDialog::OnShareLink()
{

	QString encodeHls = encodeStringAddingEscape(sharedHlsUrl);
	QString encodeRtmp = encodeStringAddingEscape(sharedRtmpUrl);
	QString encodeID = encodeStringAddingEscape(m_pChatRoom->getRoomId());
	QString encodeStreamID = encodeStringAddingEscape(m_anchorStreamInfo->getStreamId());

	QString link("http://www.zego.im/share/index2?video=" + encodeHls + "&rtmp=" + encodeRtmp + "&id=" + encodeID + "&stream=" + encodeStreamID);
	ZegoShareDialog share(link);
	share.exec();

}

void ZegoMoreAnchorDialog::OnButtonShowFullScreen()
{
	//直播窗口总在最顶层
	ui.m_zoneLiveView_Inner->setWindowFlags(Qt::Dialog);
	ui.m_zoneLiveView_Inner->showFullScreen();
	m_isLiveFullScreen = true;
}

void ZegoMoreAnchorDialog::OnSnapshotPreview()
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

void ZegoMoreAnchorDialog::OnSnapshotWithStreamID(const QString &streamID)
{
	qDebug()<<LIVEROOM::TakeSnapshot(streamID.toStdString().c_str());
}

void ZegoMoreAnchorDialog::OnShowSnapShotImage(QImage *imageData)
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

void ZegoMoreAnchorDialog::OnUseDefaultAux(bool state)
{
	BeginAux();
	isUseDefaultAux = state;
	ui.m_bAux->setEnabled(true);
	ui.m_bAux->setText(QStringLiteral("关闭混音"));
}

#ifdef Q_OS_WIN
void ZegoMoreAnchorDialog::OnGetMusicAppPath(QString exePath)
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
		QMessageBox::warning(NULL, QStringLiteral("警告"), QStringLiteral("路径格式错误"));
		ui.m_bAux->setEnabled(true);
		ui.m_bAux->setText(QStringLiteral("开启混音"));
		return;
	}

	AUDIOHOOK::StartAudioRecord();
	LIVEROOM::EnableAux(true);

	ui.m_bAux->setEnabled(true);
	ui.m_bAux->setText(QStringLiteral("关闭混音"));
}
#endif

void ZegoMoreAnchorDialog::OnButtonAux()
{
	if (ui.m_bAux->text() == QStringLiteral("开启混音"))
	{
		ui.m_bAux->setText(QStringLiteral("开启中..."));
		ui.m_bAux->setEnabled(false);

#ifdef Q_OS_WIN

		hookDialog.searchMusicAppFromReg();
		if (hookDialog.exec() == QDialog::Rejected)
		{
			ui.m_bAux->setEnabled(true);
			ui.m_bAux->setText(QStringLiteral("开启混音"));
		}

#endif

#ifdef Q_OS_MAC

		BeginAux();
		ui.m_bAux->setEnabled(true);
		ui.m_bAux->setText(QStringLiteral("关闭混音"));
#endif

	}
	else
	{
		ui.m_bAux->setText(QStringLiteral("关闭中..."));
		ui.m_bAux->setEnabled(false);

#ifdef Q_OS_WIN
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
		ui.m_bAux->setText(QStringLiteral("开启混音"));
	}
}

void ZegoMoreAnchorDialog::OnSwitchAudioDevice(int id)
{
	if (id < 0)
		return;

	if (id < m_vecAudioDeviceIDs.size())
	{
		LIVEROOM::SetAudioDevice(AV::AudioDevice_Input, m_vecAudioDeviceIDs[id].toStdString().c_str());
		m_pAVSettings->SetMicrophoneId(m_vecAudioDeviceIDs[id]);
		ui.m_cbMircoPhone->setCurrentIndex(id);
		update();
	}
}

void ZegoMoreAnchorDialog::OnSwitchVideoDevice(int id)
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

			ui.m_cbCamera2->blockSignals(true);
			ui.m_cbCamera2->setCurrentIndex(curLastCameraIndex);
			ui.m_cbCamera2->blockSignals(false);

			LIVEROOM::SetVideoDevice(m_pAVSettings->GetCameraId().toStdString().c_str(), ZEGO::AV::PUBLISH_CHN_AUX);
		}

		LIVEROOM::SetVideoDevice(m_vecVideoDeviceIDs[id].toStdString().c_str());

		m_pAVSettings->SetCameraId(m_vecVideoDeviceIDs[id]);
		ui.m_cbCamera->blockSignals(true);
		ui.m_cbCamera->setCurrentIndex(id);
		ui.m_cbCamera->blockSignals(false);
		update();

		LIVEROOM::EnableCamera(true);
		LIVEROOM::EnableCamera(true, ZEGO::AV::PUBLISH_CHN_AUX);
		LIVEROOM::StartPreview();
		LIVEROOM::StartPreview(ZEGO::AV::PUBLISH_CHN_AUX);

		qDebug() << "[MoreAnchorDialog::VideoDevice_Changed_1]: current video device_main : " << m_pAVSettings->GetCameraId() << " video device_aux : " << m_pAVSettings->GetCameraId2();
	}
}

void ZegoMoreAnchorDialog::OnSwitchVideoDevice2(int id)
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

			ui.m_cbCamera->blockSignals(true);
			ui.m_cbCamera->setCurrentIndex(curLastCameraIndex);
			ui.m_cbCamera->blockSignals(false);
			LIVEROOM::SetVideoDevice(m_pAVSettings->GetCameraId2().toStdString().c_str());
		}

		LIVEROOM::SetVideoDevice(m_vecVideoDeviceIDs[id].toStdString().c_str(), ZEGO::AV::PUBLISH_CHN_AUX);
		m_pAVSettings->SetCameraId2(m_vecVideoDeviceIDs[id]);
		ui.m_cbCamera2->blockSignals(true);
		ui.m_cbCamera2->setCurrentIndex(id);
		ui.m_cbCamera2->blockSignals(false);
		update();

		LIVEROOM::EnableCamera(true);
		LIVEROOM::EnableCamera(true, ZEGO::AV::PUBLISH_CHN_AUX);
		LIVEROOM::StartPreview();
		LIVEROOM::StartPreview(ZEGO::AV::PUBLISH_CHN_AUX);

		qDebug() << "[MoreAnchorDialog::VideoDevice_Changed_2]: current video device_main : " << m_pAVSettings->GetCameraId() << " video device_aux : " << m_pAVSettings->GetCameraId2();
	}
}

void ZegoMoreAnchorDialog::mousePressEvent(QMouseEvent *event)
{
	mousePosition = event->pos();
	//只对标题栏范围内的鼠标事件进行处理

	if (mousePosition.y() <= pos_min_y)
		return;
	if (mousePosition.y() >= pos_max_y)
		return;
	isMousePressed = true;
}

void ZegoMoreAnchorDialog::mouseMoveEvent(QMouseEvent *event)
{
	if (isMousePressed == true)
	{
		QPoint movePot = event->globalPos() - mousePosition;
		move(movePot);
	}
}

void ZegoMoreAnchorDialog::mouseReleaseEvent(QMouseEvent *event)
{
	isMousePressed = false;
}

void ZegoMoreAnchorDialog::mouseDoubleClickEvent(QMouseEvent *event)
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
	}
	else
	{
		this->showMaximized();
		isMax = true;
	}

}

void ZegoMoreAnchorDialog::closeEvent(QCloseEvent *e)
{
	QDialog::closeEvent(e);
	GetOut();
	//this->close();
	emit sigSaveVideoSettings(m_pAVSettings);
	m_lastDialog->show();
}

bool ZegoMoreAnchorDialog::eventFilter(QObject *target, QEvent *event)
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
	else if (target == this)
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

	return QDialog::eventFilter(target, event);
}

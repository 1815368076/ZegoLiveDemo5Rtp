#include "ZegoLiveRoomDialog.h"
#include "ZegoSDKSignal.h"
#include <QMessageBox>
#include <QDebug>

ZegoLiveRoomDialog::ZegoLiveRoomDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	//UI的信号槽
	connect(ui.m_bMin, &QPushButton::clicked, this, &ZegoLiveRoomDialog::OnClickTitleButton);
	connect(ui.m_bMax, &QPushButton::clicked, this, &ZegoLiveRoomDialog::OnClickTitleButton);
	connect(ui.m_bClose, &QPushButton::clicked, this, &ZegoLiveRoomDialog::OnClickTitleButton);
}

ZegoLiveRoomDialog::ZegoLiveRoomDialog(SettingsPtr curSettings, RoomPtr room, QString curUserID, QString curUserName, bool isAnchor, int curMode, QDialog *lastDialog, QDialog *parent)
	: m_pAVSettings(curSettings),
	m_pChatRoom(room),
	m_strCurUserID(curUserID),
	m_strCurUserName(curUserName),
	m_bIsAnchor(isAnchor),
	m_liveMode(curMode),
	m_bCKEnableMic(true),
	m_bCKEnableSpeaker(true),
	m_lastDialog(lastDialog)
{
	ui.setupUi(this);


	//通过sdk的信号连接到本类的槽函数中
	connect(GetAVSignal(), &QZegoAVSignal::sigLoginRoom, this, &ZegoLiveRoomDialog::OnLoginRoom);
	connect(GetAVSignal(), &QZegoAVSignal::sigStreamUpdated, this, &ZegoLiveRoomDialog::OnStreamUpdated);
	connect(GetAVSignal(), &QZegoAVSignal::sigPublishStateUpdate, this, &ZegoLiveRoomDialog::OnPublishStateUpdate);
	connect(GetAVSignal(), &QZegoAVSignal::sigPlayStateUpdate, this, &ZegoLiveRoomDialog::OnPlayStateUpdate);
	connect(GetAVSignal(), &QZegoAVSignal::sigDisconnect, this, &ZegoLiveRoomDialog::OnDisconnect);
	connect(GetAVSignal(), &QZegoAVSignal::sigKickOut, this, &ZegoLiveRoomDialog::OnKickOut);
	connect(GetAVSignal(), &QZegoAVSignal::sigPublishQualityUpdate, this, &ZegoLiveRoomDialog::OnPublishQualityUpdate);
	connect(GetAVSignal(), &QZegoAVSignal::sigPlayQualityUpdate, this, &ZegoLiveRoomDialog::OnPlayQualityUpdate);
	//信号与槽同步执行
	connect(GetAVSignal(), &QZegoAVSignal::sigAuxInput, this, &ZegoLiveRoomDialog::OnAVAuxInput, Qt::DirectConnection);
	connect(GetAVSignal(), &QZegoAVSignal::sigSendRoomMessage, this, &ZegoLiveRoomDialog::OnSendRoomMessage);
	connect(GetAVSignal(), &QZegoAVSignal::sigRecvRoomMessage, this, &ZegoLiveRoomDialog::OnRecvRoomMessage);
	connect(GetAVSignal(), &QZegoAVSignal::sigJoinLiveRequest, this, &ZegoLiveRoomDialog::OnJoinLiveRequest);
	connect(GetAVSignal(), &QZegoAVSignal::sigJoinLiveResponse, this, &ZegoLiveRoomDialog::OnJoinLiveResponse);
	connect(GetAVSignal(), &QZegoAVSignal::sigUserUpdate, this, &ZegoLiveRoomDialog::OnUserUpdate);
	connect(GetAVSignal(), &QZegoAVSignal::sigMixStream, this, &ZegoLiveRoomDialog::OnMixStream);
	connect(GetAVSignal(), &QZegoAVSignal::sigAudioDeviceChanged, this, &ZegoLiveRoomDialog::OnAudioDeviceChanged);
	connect(GetAVSignal(), &QZegoAVSignal::sigVideoDeviceChanged, this, &ZegoLiveRoomDialog::OnVideoDeviceChanged);

	//UI的信号槽
	connect(ui.m_bMin, &QPushButton::clicked, this, &ZegoLiveRoomDialog::OnClickTitleButton);
	connect(ui.m_bMax, &QPushButton::clicked, this, &ZegoLiveRoomDialog::OnClickTitleButton);
	connect(ui.m_bClose, &QPushButton::clicked, this, &ZegoLiveRoomDialog::OnClickTitleButton);
	connect(ui.m_bClose, &QPushButton::clicked, this, &ZegoLiveRoomDialog::OnClose);
	connect(ui.m_bRequestJoinLive, &QPushButton::clicked, this, &ZegoLiveRoomDialog::OnButtonJoinLive);
	connect(ui.m_bSendMessage, &QPushButton::clicked, this, &ZegoLiveRoomDialog::OnButtonSendMessage);
#ifdef WIN32
	connect(ui.m_bCapture, &QPushButton::clicked, this, &ZegoLiveRoomDialog::OnButtonSoundCapture);
#endif
	connect(ui.m_bProgMircoPhone, &QPushButton::clicked, this, &ZegoLiveRoomDialog::OnButtonMircoPhone);
	connect(ui.m_bSound, &QPushButton::clicked, this, &ZegoLiveRoomDialog::OnButtonSound);
	connect(ui.m_bShare, &QPushButton::clicked, this, &ZegoLiveRoomDialog::OnShareLink);
	connect(ui.m_bAux, &QPushButton::clicked, this, &ZegoLiveRoomDialog::OnButtonAux);
	
	timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &ZegoLiveRoomDialog::OnProgChange);
	
	//混音数据参数
	m_pAuxData = NULL;
	m_nAuxDataLen = 0;
	m_nAuxDataPos = 0;

	this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏 

	//设置混流回调初始值
	m_mixStreamRequestSeq = 1;


}

ZegoLiveRoomDialog::~ZegoLiveRoomDialog()
{

}

//功能函数
void ZegoLiveRoomDialog::initDialog()
{
	if (m_bIsAnchor)
		ui.m_bRequestJoinLive->setVisible(false);

	initComboBox();

	//对话框模型初始化
	m_chatModel = new QStringListModel(this);
	ui.m_listChat->setModel(m_chatModel);
	ui.m_listChat->setItemDelegate(new NoFocusFrameDelegate(this));
	ui.m_listChat->setEditTriggers(QAbstractItemView::NoEditTriggers);


	//成员列表初始化
	m_memberModel = new QStringListModel(this);
	ui.m_listMember->setModel(m_memberModel);
	ui.m_listMember->setItemDelegate(new NoFocusFrameDelegate(this));
	ui.m_listMember->setEditTriggers(QAbstractItemView::NoEditTriggers);

	//读取标题内容
	QString strTitle;
    QString LiveMode[5] = { QStringLiteral("连麦模式"), QStringLiteral(""), QStringLiteral("混流模式"), QStringLiteral(""), QStringLiteral("单主播模式") };
	strTitle = QString(QStringLiteral("【%1】%2")).arg(LiveMode[m_liveMode]).arg(m_pChatRoom->getRoomName());
	ui.m_lbRoomName->setText(strTitle);
	
	//在观众模式下，如果此时观看的房间直播模式为"单主播模式"或"观众未连麦的连麦模式"，则麦克风下拉列表、摄像头下拉列表、混音、声卡采集这四个控件不可用,并且在单主播模式下，连麦按钮会被隐藏
	if (!m_bIsAnchor){
		if (m_liveMode == 4 || !m_bIsJoinLive)
			
			SetOperation(false);

		if (m_liveMode == 4)
			ui.m_bRequestJoinLive->setVisible(false);
	}

	//剩余能用的AVView
	for (int i = MAX_VIEW_COUNT; i >= 0; i--)
		m_avaliableView.push(i);
	//先写死，以后优化
	AVViews.push_back(ui.m_avLiveView);
	AVViews.push_back(ui.m_avLiveView2);
	AVViews.push_back(ui.m_avLiveView3);
	AVViews.push_back(ui.m_avLiveView4);
	AVViews.push_back(ui.m_avLiveView5);
	AVViews.push_back(ui.m_avLiveView6);
	AVViews.push_back(ui.m_avLiveView7);
	AVViews.push_back(ui.m_avLiveView8);
	AVViews.push_back(ui.m_avLiveView9);
	AVViews.push_back(ui.m_avLiveView10);
	AVViews.push_back(ui.m_avLiveView11);
	AVViews.push_back(ui.m_avLiveView12);

	//推流成功前不能开混音、声音采集、分享
	ui.m_bAux->setEnabled(false);
	ui.m_bCapture->setEnabled(false);
	ui.m_bShare->setEnabled(false);


	//允许使用麦克风
	LIVEROOM::EnableMic(m_bCKEnableMic);

	//枚举音视频设备
	EnumVideoAndAudioDevice();

	int role = m_bIsAnchor ? LIVEROOM::ZegoRoomRole::Anchor : LIVEROOM::ZegoRoomRole::Audience;
	if (!LIVEROOM::LoginRoom(m_pChatRoom->getRoomId().toStdString().c_str(), role, m_pChatRoom->getRoomName().toStdString().c_str()))
	{
		QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("进入房间失败"));
	}

}

void ZegoLiveRoomDialog::StartPublishStream()
{
	
	QTime currentTime = QTime::currentTime();
	//获取当前时间的毫秒
	int ms = currentTime.msec();
	QString strStreamId;
	strStreamId = QString(QStringLiteral("s-windows-%1-%2")).arg(m_strCurUserID).arg(ms);
	m_strPublishStreamID = strStreamId;
	m_myMixStreamID = "mix-" + m_strPublishStreamID;

	StreamPtr pPublishStream(new QZegoStreamModel(m_strPublishStreamID, m_strCurUserID, m_strCurUserName, "", true));

	m_pChatRoom->addStream(pPublishStream);
	
	if (m_avaliableView.size() > 0)
	{
		int nIndex = m_avaliableView.top();
		m_avaliableView.pop();
		pPublishStream->setPlayView(nIndex);
		qDebug() << "publish nIndex = " << nIndex;
		//配置View
		
		LIVEROOM::SetPreviewView((void *)AVViews[nIndex]->winId());
		LIVEROOM::SetPreviewViewMode(LIVEROOM::ZegoVideoViewModeScaleAspectFill);
		LIVEROOM::StartPreview();

		static int i = 0;
		/*QString cdnFlag;

		if (i++ % 2)
		{
			cdnFlag = "?zmcdn=ws1";
		}
		else
		{
			cdnFlag = "?zmcdn=aliyun1";
		}*/

		QString streamID = m_strPublishStreamID;
		qDebug() << "start publishing!";
		LIVEROOM::StartPublishing(m_pChatRoom->getRoomName().toStdString().c_str(), streamID.toStdString().c_str(), m_liveMode, "");
		m_bIsPublishing = true;
	}
}

void ZegoLiveRoomDialog::StopPublishStream(const QString& streamID)
{
	if (streamID.size() == 0){ return; }

	LIVEROOM::SetPreviewView(nullptr);
	LIVEROOM::StopPreview();
	LIVEROOM::StopPublishing();
	m_bIsPublishing = false;

	StreamPtr pStream = m_pChatRoom->removeStream(streamID);
	FreeAVView(pStream);
}

void ZegoLiveRoomDialog::StartPlayStream(StreamPtr stream)
{
	if (stream == nullptr) { return; }

	m_pChatRoom->addStream(stream);
	
	if (m_avaliableView.size() > 0)
	{
		int nIndex = m_avaliableView.top();
		qDebug() << "playStream nIndex = " << nIndex;
		m_avaliableView.pop();
		stream->setPlayView(nIndex);

		//配置View
		LIVEROOM::SetViewMode(LIVEROOM::ZegoVideoViewModeScaleAspectFill, stream->getStreamId().toStdString().c_str());
		LIVEROOM::StartPlayingStream(stream->getStreamId().toStdString().c_str(), (void *)AVViews[nIndex]->winId());
	}
}

void ZegoLiveRoomDialog::StopPlayStream(const QString& streamID)
{
	if (streamID.size() == 0) { return; }

	LIVEROOM::StopPlayingStream(streamID.toStdString().c_str());

	StreamPtr pStream = m_pChatRoom->removeStream(streamID);
	FreeAVView(pStream);
}

void ZegoLiveRoomDialog::GetOut()
{
	EndAux();
	for (auto& stream : m_pChatRoom->getStreamList())
	{
		if (stream->isCurUserCreated())
		{
			StopPublishStream(stream->getStreamId());
		}
		else
		{
			StopPlayStream(stream->getStreamId());
		}
	}

	roomMemberDelete(m_strCurUserName);
	LIVEROOM::LogoutRoom();
	timer->stop();
}

void ZegoLiveRoomDialog::initComboBox()
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

void ZegoLiveRoomDialog::EnumVideoAndAudioDevice()
{
	//设备数
	int nDeviceCount = 0;
	AV::DeviceInfo* pDeviceList(NULL);

	//获取音频设备
	int curSelectionIndex = 0;
	pDeviceList = LIVEROOM::GetAudioDeviceList(AV::AudioDeviceType::AudioDevice_Input, nDeviceCount);
	for (int i = 0; i < nDeviceCount; ++i)
	{
		insertStringListModelItem(m_cbMircoPhoneModel, QString::fromUtf8(pDeviceList[i].szDeviceName), m_MircoPhoneList.size());
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
		insertStringListModelItem(m_cbCameraModel, QString::fromUtf8(pDeviceList[i].szDeviceName), m_CameraList.size());
		m_vecVideoDeviceIDs.push_back(pDeviceList[i].szDeviceId);

		if (m_pAVSettings->GetCameraId() == QString(pDeviceList[i].szDeviceId))
			curSelectionIndex = i;
	}

	ui.m_cbCamera->setCurrentIndex(curSelectionIndex);
	LIVEROOM::FreeDeviceList(pDeviceList);
	pDeviceList = NULL;
}

void ZegoLiveRoomDialog::insertStringListModelItem(QStringListModel * model, QString name, int size)
{
	int row = size;
	model->insertRows(row, 1);
	QModelIndex index = model->index(row);
	model->setData(index, name);

}

void ZegoLiveRoomDialog::removeStringListModelItem(QStringListModel * model, QString name)
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

void ZegoLiveRoomDialog::FreeAVView(StreamPtr stream)
{
	if (stream == nullptr)
	{
		return;
	}

	int nIndex = stream->getPlayView();
	
	m_avaliableView.push(nIndex);

	//刷新可用的view页面
	update();
}

void ZegoLiveRoomDialog::SetOperation(bool state)
{
	ui.m_cbMircoPhone->setEnabled(state);
	ui.m_cbCamera->setEnabled(state);
	ui.m_bAux->setEnabled(state);
	ui.m_bCapture->setEnabled(state);
	ui.m_bProgMircoPhone->setEnabled(state);

	ui.m_lbMircoPhone->setEnabled(state);
	ui.m_lbCamera->setEnabled(state);

	
	ui.m_bProgMircoPhone->setMyEnabled(state);
	ui.m_bProgMircoPhone->update();

}

QString ZegoLiveRoomDialog::encodeStringAddingEscape(QString str)
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

void ZegoLiveRoomDialog::roomMemberAdd(QString userName)
{

	insertStringListModelItem(m_memberModel, userName, m_memberModel->rowCount());
	ui.m_tabCommonAndUserList->setTabText(1, QString(QStringLiteral("成员(%1)").arg(m_memberModel->rowCount())));
}

void ZegoLiveRoomDialog::roomMemberDelete(QString userName)
{
	removeStringListModelItem(m_memberModel, userName);
	ui.m_tabCommonAndUserList->setTabText(1, QString(QStringLiteral("成员(%1)").arg(m_memberModel->rowCount())));
}

bool ZegoLiveRoomDialog::isStreamExisted(QString streamID)
{
	bool isExisted = false;

	if (m_strPublishStreamID == streamID)
		return true;

	//获取房间流列表
	QVector<StreamPtr> streamList =  m_pChatRoom->getStreamList();
	for (auto streamInfo : streamList)
		if (streamInfo->getStreamId() == streamID)
			return true;

	return false;
}

void ZegoLiveRoomDialog::StartMixStream()
{
	int size = m_mixStreamInfos.size();
	int width = m_pAVSettings->GetResolution().cx;
	int height = m_pAVSettings->GetResolution().cy;

	AV::ZegoCompleteMixStreamConfig mixStreamConfig;
	mixStreamConfig.pInputStreamList = new AV::ZegoMixStreamConfig[size];

	for (int i = 0; i < size; i++)
	{
		strcpy(mixStreamConfig.pInputStreamList[i].szStreamID , m_mixStreamInfos[i]->szStreamID);
		mixStreamConfig.pInputStreamList[i].layout.top = m_mixStreamInfos[i]->layout.top;
		mixStreamConfig.pInputStreamList[i].layout.bottom = m_mixStreamInfos[i]->layout.bottom;
		mixStreamConfig.pInputStreamList[i].layout.left = m_mixStreamInfos[i]->layout.left;
		mixStreamConfig.pInputStreamList[i].layout.right = m_mixStreamInfos[i]->layout.right;
	}

	mixStreamConfig.nInputStreamCount = size;
	strcpy(mixStreamConfig.szOutputStream, m_myMixStreamID.toStdString().c_str());
	mixStreamConfig.bOutputIsUrl = false;
	mixStreamConfig.nOutputWidth = width;
	mixStreamConfig.nOutputHeight = height;
	mixStreamConfig.nOutputFps = m_pAVSettings->GetFps();
	mixStreamConfig.nOutputBitrate = m_pAVSettings->GetBitrate();

	qDebug() << "startMixStream!";
	LIVEROOM::MixStream(mixStreamConfig, m_mixStreamRequestSeq++);
}

void ZegoLiveRoomDialog::StopPlayMixStream(QVector<StreamPtr> vStreamList)
{
	//只有主播流退出了才会停止拉混流
	for (auto stream : vStreamList)
	{
		if (stream->getStreamId() == m_anchorStreamInfo->getStreamId())
		{

			LIVEROOM::StopPlayingStream(m_anchorMixStreamID.toStdString().c_str());
		    StreamPtr pStream = m_pChatRoom->removeStream(stream->getStreamId());
			FreeAVView(pStream);
			

		}
	}
}

void ZegoLiveRoomDialog::StartPlayMixStream(StreamPtr streamInfo)
{
	qDebug() << "startPlayMixStream!";
	/*if (isStreamExisted(mixStreamID, streamList))
	{
		QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("流已存在"));
		return;
	}*/
	if (streamInfo == nullptr) { return; }

	m_pChatRoom->addStream(streamInfo);

	//保存当前混流主播的流信息
	m_anchorStreamInfo = streamInfo;
	
	if (m_avaliableView.size() > 0)
	{
		int nIndex = m_avaliableView.top();
		qDebug() << "playMixStream index = " << nIndex;

		m_avaliableView.pop();
		streamInfo->setPlayView(nIndex);

		//配置View
		LIVEROOM::SetViewMode(LIVEROOM::ZegoVideoViewModeScaleAspectFill, m_anchorMixStreamID.toStdString().c_str());
		LIVEROOM::StartPlayingStream(m_anchorMixStreamID.toStdString().c_str(), (void *)AVViews[nIndex]->winId());
	}

}

void ZegoLiveRoomDialog::StartPlaySingleStream(QVector<StreamPtr> streamList)
{
	for (auto stream : streamList)
	{
		if (stream->getStreamId() != m_strPublishStreamID)
		StartPlayStream(stream);
	}
}

void ZegoLiveRoomDialog::StopPlaySingleStream()
{
	QVector<StreamPtr> roomStreamList = m_pChatRoom->getStreamList();
	qDebug() << "roomSize = " << roomStreamList.size();

	for (auto stream : roomStreamList)
	{
		if (stream->getStreamId() != m_strPublishStreamID)
		{
			m_mixStreamList.push_back(stream);
			StopPlayStream(stream->getStreamId());
		}
		
	}

}

void ZegoLiveRoomDialog::MixStreamAdd(QVector<StreamPtr> vStreamList, const QString& roomId)
{
	//主播端流增加，更新混流信息
	if (m_bIsAnchor){
		int width = m_pAVSettings->GetResolution().cx;
		int height = m_pAVSettings->GetResolution().cy;

		for (auto streamInfo : vStreamList)
		{
			StartPlayStream(streamInfo);

			if (m_mixStreamInfos.size() == 1)
			{
				AV::ZegoMixStreamConfig *mixStreamInfo = new AV::ZegoMixStreamConfig;
				strcpy(mixStreamInfo->szStreamID, streamInfo->getStreamId().toStdString().c_str());
				mixStreamInfo->layout.top = (int)(height * 2.0 / 3);
				mixStreamInfo->layout.bottom = height;
				mixStreamInfo->layout.left = (int)(width * 2.0 / 3) - 350;
				mixStreamInfo->layout.right = width - 350;

				m_mixStreamInfos.push_back(mixStreamInfo);
			}
			else if (m_mixStreamInfos.size() == 2)
			{
				AV::ZegoMixStreamConfig *mixStreamInfo = new AV::ZegoMixStreamConfig;
				strcpy(mixStreamInfo->szStreamID, streamInfo->getStreamId().toStdString().c_str());
				mixStreamInfo->layout.top = (int)(height * 2.0 / 3) + 10;
				mixStreamInfo->layout.bottom = height - 10;
				mixStreamInfo->layout.left = 30;
				mixStreamInfo->layout.right = (int)(width * 1.0 / 3)  - 30;

				m_mixStreamInfos.push_back(mixStreamInfo);
			}
		}

		StartMixStream();
	}
	
}

void ZegoLiveRoomDialog::MixStreamDelete(QVector<StreamPtr> vStreamList, const QString& roomId)
{
	for (auto bizStream : vStreamList)
	{
		StopPlayStream(bizStream->getStreamId());

		for (int i = 0; i < m_mixStreamInfos.size(); i++)
		{
			if (strcmp(m_mixStreamInfos[i]->szStreamID, bizStream->getStreamId().toStdString().c_str()) == 0)
				m_mixStreamInfos.removeAt(i);
			break;
		}
	}

	StartMixStream();
}

bool ZegoLiveRoomDialog::praseJsonData(QJsonDocument doc)
{
	QJsonObject obj = doc.object();

	QJsonValue isFirstAnchor = obj.take(m_FirstAnchor);
	QJsonValue hlsUrl = obj.take(m_HlsKey);
	QJsonValue rtmpUrl = obj.take(m_RtmpKey);

	sharedHlsUrl = hlsUrl.toString();
	sharedRtmpUrl = rtmpUrl.toString();

	return true;
}

bool ZegoLiveRoomDialog::praseMixJsonData(QJsonDocument doc)
{
	QJsonObject obj = doc.object();

	QJsonValue isFirstAnchor = obj.take(m_FirstAnchor);
	QJsonValue mixStreamId = obj.take(m_MixStreamID);
	QJsonValue hlsUrl = obj.take(m_HlsKey);
	QJsonValue rtmpUrl = obj.take(m_RtmpKey);

	if (isFirstAnchor.toBool() && !mixStreamId.toString().isEmpty())
	{
		m_anchorMixStreamID = mixStreamId.toString();
		sharedHlsUrl = hlsUrl.toString();
		sharedRtmpUrl = rtmpUrl.toString();
	}

	return true;
}

void ZegoLiveRoomDialog::BeginAux()
{
	QString filePath = QFileDialog::getOpenFileName(this,
		tr(QStringLiteral("请选择一个混音文件").toStdString().c_str()),
		"./Resources",
		tr(QStringLiteral("pcm文件(*.pcm)").toStdString().c_str()));
		

	if (!filePath.isEmpty())
	{
		/*QFile pcmFile(filePath);
		if (!pcmFile.open(QIODevice::ReadOnly | QIODevice::Text)){
			QMessageBox::warning(this, QStringLiteral("警告"), QStringLiteral("无法打开该文件: %1").arg(filePath));
			return;
		}

		//QTextStream in(&pcmFile);
		//QString pcmTest = in.readAll();
		m_nAuxDataLen = pcmFile.size();
		//qDebug() << "fileLen = " << m_nAuxDataLen<<"strLen = "<<pcmTest.size();
		
		qint64 length = 0;
		char *buffer = new char[1];
		int i = 0;
		
		if (m_nAuxDataLen > 0)
		{
			m_pAuxData = new unsigned char[m_nAuxDataLen];
			memset(m_pAuxData, 0, m_nAuxDataLen);
			//m_pAuxData = (unsigned char *)pcmTest.data();
			//QByteArray bytes = pcmTest.toLatin1();
			//m_pAuxData = (unsigned char *) bytes.data();
			
			while ((length = pcmFile.read(buffer, 2)) != 0)
			{
				
				
				qDebug()<<" char = " << (unsigned char *) *buffer;
				m_pAuxData[i++] = *buffer;
			}
		}

		qDebug() << "final len = " << i;*/

		FILE* fAux;
		fopen_s(&fAux, filePath.toStdString().c_str(), "rb");

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

void ZegoLiveRoomDialog::EndAux()
{
	LIVEROOM::EnableAux(false);

	ui.m_bAux->setText(QStringLiteral("开启混音"));
	delete[] m_pAuxData;
	m_nAuxDataLen = 0;
	m_nAuxDataPos = 0;
}

//SDK回调
void ZegoLiveRoomDialog::OnLoginRoom(int errorCode, const QString& strRoomID, QVector<StreamPtr> vStreamList)
{
	qDebug() << "Login Room!";
	if (errorCode != 0)
	{
		QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("登陆房间失败"));
		OnClose();
	}

	//加入房间列表
	roomMemberAdd(m_strCurUserName);

	if (m_liveMode == 2)
		for (auto stream : vStreamList)
			m_mixStreamList.push_back(stream);

	
	if (m_bIsAnchor)
	{
		StartPublishStream();
	}

	else{
		//如果当前房间的直播模式为单主播模式或者连麦模式，则直接拉多路流
		if (m_liveMode == 4 || m_liveMode == 0){
			
			for (auto& stream : vStreamList)
			{
				StartPlayStream(stream);
			}

			//将第一个流信息作为主播流信息
			if (m_pChatRoom->getStreamCount() > 0)
			{
				
				m_anchorStreamInfo = m_pChatRoom->getStreamList()[0];
				QByteArray jsonArray = m_anchorStreamInfo->getExtraInfo().toUtf8();

				QJsonParseError json_error;
				QJsonDocument doc = QJsonDocument::fromJson(jsonArray, &json_error);

				if (json_error.error != QJsonParseError::NoError){ return; }

				if (!doc.isObject()) { return; }

				praseJsonData(doc);
			}
		}
		//如果当前房间的直播模式为混流模式，则拉一条混流
		else if (m_liveMode == 2)
		{
			if (vStreamList.size() > 0){

				//遍历找出第一主播的流，找到extraInfo流附加消息并进行解析
				for (auto streamInfo : vStreamList)
				{
					QByteArray jsonArray = streamInfo->getExtraInfo().toUtf8();

					QJsonParseError json_error;
					QJsonDocument doc = QJsonDocument::fromJson(jsonArray, &json_error);

					if (json_error.error != QJsonParseError::NoError){ continue; }

					if (!doc.isObject()) { continue; }

					praseMixJsonData(doc);

					StartPlayMixStream(streamInfo);
					break;
				}
			}
		}
	}

	
}

void ZegoLiveRoomDialog::OnStreamUpdated(const QString& roomId, QVector<StreamPtr> vStreamList, LIVEROOM::ZegoStreamUpdateType type)
{
	//在单主播模式和连麦模式下，有流更新直接处理
	if (m_liveMode == 4 || m_liveMode == 0){
		for (auto& stream : vStreamList)
		{
			if (type == LIVEROOM::ZegoStreamUpdateType::StreamAdded)
			{
				StartPlayStream(stream);

			}
			else if (type == LIVEROOM::ZegoStreamUpdateType::StreamDeleted)
			{
				StopPlayStream(stream->getStreamId());
				if (m_pChatRoom->getStreamCount() > 0)
				{
					m_anchorStreamInfo = m_pChatRoom->getStreamList()[0];
					QByteArray jsonArray = m_anchorStreamInfo->getExtraInfo().toUtf8();

					QJsonParseError json_error;
					QJsonDocument doc = QJsonDocument::fromJson(jsonArray, &json_error);

					if (json_error.error != QJsonParseError::NoError){ return; }

					if (!doc.isObject()) { return; }

					praseJsonData(doc);
					
				}
			}
		}
	}
	//在混流模式下，有流更新时需要作混流处理(合并/删除)
	else if (m_liveMode == 2)
	{
		//主播模式下需要执行流变化的混流操作
		if (m_bIsAnchor){
			if (type == LIVEROOM::ZegoStreamUpdateType::StreamAdded)
			{

				MixStreamAdd(vStreamList, roomId);

			}
			else if (type == LIVEROOM::ZegoStreamUpdateType::StreamDeleted)
			{
				MixStreamDelete(vStreamList, roomId);
			}
		}
		//观众模式
		else{

			//观众看别人增减流,观众段需要变化房间的流列表
			if (!m_bIsPublishing && m_mixStreamList.size() > 0){
				if (type == LIVEROOM::ZegoStreamUpdateType::StreamAdded)
				{
					for (auto stream : vStreamList)
					{
						if (isStreamExisted(stream->getStreamId()))
							continue;

						m_mixStreamList.push_back(stream);
					}
				}
				else if (type == LIVEROOM::ZegoStreamUpdateType::StreamDeleted)
				{
					for (int i = 0; i < vStreamList.size(); i++)
					{
						if (!isStreamExisted(vStreamList[i]->getStreamId()))
							continue;

						m_mixStreamList.remove(i);
					}

					StopPlayMixStream(vStreamList);
				}
			}

		}
	}
}

void ZegoLiveRoomDialog::OnPublishStateUpdate(int stateCode, const QString& streamId, StreamPtr streamInfo)
{
	qDebug() << "Publish success!";
	if (stateCode == 0)
	{
		
		ui.m_bAux->setEnabled(true);
		ui.m_bCapture->setEnabled(true);
		ui.m_bShare->setEnabled(true);

			if (streamInfo != nullptr)
			{
				if (m_liveMode == 0 || m_liveMode == 4)
				{
					m_anchorStreamInfo = streamInfo;
					sharedHlsUrl = streamInfo->m_vecHlsUrls[0];
					sharedRtmpUrl = streamInfo->m_vecRtmpUrls[0];
				}

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

			//如果当前直播模式为混流模式，则将主播流加到混流中
			if (m_liveMode == 2 && m_bIsAnchor)
			{
				Size videoCaptureResolution = m_pAVSettings->GetResolution();
				int width = videoCaptureResolution.cx;
				int height = videoCaptureResolution.cy;

				AV::ZegoMixStreamConfig *mixStreamInfo = new AV::ZegoMixStreamConfig;
				strcpy(mixStreamInfo->szStreamID, m_strPublishStreamID.toStdString().c_str());
				mixStreamInfo->layout.top = 0;
				mixStreamInfo->layout.bottom = height;
				mixStreamInfo->layout.left = 0;
				mixStreamInfo->layout.right = width;
				m_mixStreamInfos.push_back(mixStreamInfo);

				StartMixStream();

			}
			//在单主播模式和连麦模式下，推流成功时需将流媒体地址存到流附加信息中
			else if ((m_liveMode == 0 || m_liveMode == 4) && m_bIsAnchor)
			{
				//封装存放分享地址的json对象
				if (sharedHlsUrl.size() > 0 && sharedRtmpUrl.size() > 0)
				{
					QMap<QString, QString> mapUrls = QMap<QString, QString>();

					mapUrls.insert(m_FirstAnchor, QStringLiteral("true"));
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
			}
			//观众端在混流模式下请求连麦时，需要断开混流改为拉单流
			else if (m_liveMode == 2 && !m_bIsAnchor)
			{
				//m_mixStreamList.push_back(streamInfo);

				//此时表明0号ViEW正在用于拉混流
				if (m_avaliableView.size() >= m_mixStreamList.size())
				{
					//停止拉混流
					//LIVEROOM::StopPlayingStream(m_mixStreamID.toStdString().c_str());
					//FreeAVView(streamInfo);

					//逐条拉单流
					StartPlaySingleStream(m_mixStreamList);
					m_mixStreamList.clear();
				}
			}
		
		//推流成功后启动计时器监听麦克风音量
		timer->start(0);

	}
	else
	{
		EndAux();
		// 停止预览, 回收view
		LIVEROOM::StopPreview();
		LIVEROOM::SetPreviewView(nullptr);
		StreamPtr pStream = m_pChatRoom->removeStream(streamId);
		FreeAVView(pStream);
	}
}

void ZegoLiveRoomDialog::OnPlayStateUpdate(int stateCode, const QString& streamId)
{
	qDebug() << "OnPlay! stateCode = "<<stateCode;

	ui.m_bShare->setEnabled(true);

	if (stateCode != 0)
	{
		// 回收view
		StreamPtr pStream = m_pChatRoom->removeStream(streamId);
		FreeAVView(pStream);
	}
}

void ZegoLiveRoomDialog::OnMixStream(unsigned int errorCode, const QString& hlsUrl, const QString& rtmpUrl, const QString& mixStreamID, int seq)
{
	qDebug() << "mixStream update!";

	if (m_bIsAnchor){
		if (errorCode == 0)
		{
			qDebug() << QStringLiteral("混流成功！ 其混流ID为：") << mixStreamID;
			qDebug() << "mix hls :" << hlsUrl;
			qDebug() << "mix rtmp :" << rtmpUrl;
			sharedHlsUrl = hlsUrl;
			sharedRtmpUrl = rtmpUrl;

			//封装存放分享地址的json对象
			if (hlsUrl.size() > 0 && rtmpUrl.size() > 0)
			{
				QMap<QString, QString> mapUrls = QMap<QString, QString>();

				mapUrls.insert(m_FirstAnchor, QStringLiteral("true"));
				mapUrls.insert(m_MixStreamID, mixStreamID);
				mapUrls.insert(m_HlsKey, hlsUrl);
				mapUrls.insert(m_RtmpKey, rtmpUrl);

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

		}
	}
}

void ZegoLiveRoomDialog::OnUserUpdate(QVector<QString> userIDs, QVector<QString> userNames, QVector<int> userFlags, QVector<int> userRoles, unsigned int userCount, LIVEROOM::ZegoUserUpdateType type)
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

void ZegoLiveRoomDialog::OnDisconnect(int errorCode, const QString& roomId)
{
	if (m_pChatRoom->getRoomId() == roomId)
	{
		QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("您已掉线"));
		OnClose();
	}
}

void ZegoLiveRoomDialog::OnKickOut(int reason, const QString& roomId)
{
	if (m_pChatRoom->getRoomId() == roomId)
	{
		QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("您已被踢出房间"));
		OnClose();
	}
}

void ZegoLiveRoomDialog::OnPlayQualityUpdate(const QString& streamId, int quality, double videoFPS, double videoKBS)
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

void ZegoLiveRoomDialog::OnPublishQualityUpdate(const QString& streamId, int quality, double videoFPS, double videoKBS)
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

void ZegoLiveRoomDialog::OnAVAuxInput(unsigned char *pData, int *pDataLen, int pDataLenValue, int *pSampleRate, int *pNumChannels)
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

void ZegoLiveRoomDialog::OnSendRoomMessage(int errorCode, const QString& roomID, int sendSeq, unsigned long long messageId)
{
	if (errorCode != 0) { return; }

	if (m_strLastSendMsg.isEmpty()) { return; }

	QString strTmpContent;
	strTmpContent = QString(QStringLiteral("我: %1")).arg(m_strLastSendMsg);
	insertStringListModelItem(m_chatModel, strTmpContent, m_chatModel->rowCount());
	//每次发送消息均显示最后一条
	ui.m_listChat->scrollToBottom();
	m_strLastSendMsg.clear();
}

void ZegoLiveRoomDialog::OnRecvRoomMessage(const QString& roomId, QVector<RoomMsgPtr> vRoomMsgList)
{
	for (auto& roomMsg : vRoomMsgList)
	{
		QString strTmpContent;
		strTmpContent = QString(QStringLiteral("%1: %2")).arg(roomMsg->getUserId()).arg(roomMsg->getContent());
		insertStringListModelItem(m_chatModel, strTmpContent, m_chatModel->rowCount());
		//每次接受消息均显示最后一条
		ui.m_listChat->scrollToBottom();
		
	}
}

void ZegoLiveRoomDialog::OnJoinLiveRequest(int seq, const QString& fromUserId, const QString& fromUserName, const QString& roomId)
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

void ZegoLiveRoomDialog::OnJoinLiveResponse(int result, const QString& fromUserId, const QString& fromUserName, int seq)
{
	if (seq == m_iRequestJoinLiveSeq)
	{

		if (result == 0)
		{
			ui.m_bRequestJoinLive->setText(QStringLiteral("停止连麦"));
			if (m_liveMode == 0 || m_liveMode == 4)
			StartPublishStream();
			else if (m_liveMode == 2)
			{
				StopPlayMixStream(m_mixStreamList);
				StartPublishStream();
			}
			m_bIsJoinLive = true;
			SetOperation(true);
		}
		else
		{
			ui.m_bRequestJoinLive->setText(QStringLiteral("请求连麦"));
			QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("连麦请求被拒绝"));
		}

	}
	ui.m_bRequestJoinLive->setEnabled(true);
}

void ZegoLiveRoomDialog::OnAudioDeviceChanged(AV::AudioDeviceType deviceType, const QString& strDeviceId, const QString& strDeviceName, AV::DeviceState state)
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

void ZegoLiveRoomDialog::OnVideoDeviceChanged(const QString& strDeviceId, const QString& strDeviceName, AV::DeviceState state)
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

//UI回调
void ZegoLiveRoomDialog::OnClickTitleButton()
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

void ZegoLiveRoomDialog::OnButtonJoinLive()
{
	//当前按钮文本为“开始连麦”
	if (ui.m_bRequestJoinLive->text() == QStringLiteral("请求连麦"))
	{
		ui.m_bRequestJoinLive->setText(QStringLiteral("请求中..."));
		ui.m_bRequestJoinLive->setEnabled(false);
		// 请求连麦
		m_iRequestJoinLiveSeq = LIVEROOM::RequestJoinLive();

	}
	//当前按钮文本为“停止连麦”
	else
	{
		m_bIsPublishing = false;
		if (m_liveMode == 0 || m_liveMode == 4)
		StopPublishStream(m_strPublishStreamID);
		else if (m_liveMode == 2)
		{
			StopPlaySingleStream();
			StopPublishStream(m_strPublishStreamID);
			StartPlayMixStream(m_anchorStreamInfo);
		}

		SetOperation(false);
		ui.m_bRequestJoinLive->setText(QStringLiteral("请求连麦"));
	}
}

void ZegoLiveRoomDialog::OnClose()
{
	GetOut();
	this->close();
	m_lastDialog->show();
}

void ZegoLiveRoomDialog::OnButtonSendMessage()
{
	QString strChat;
	strChat = ui.m_edInput->toPlainText();
	
	if (strChat.isEmpty())
	{
		return;
	}

	m_strLastSendMsg = strChat;

	LIVEROOM::SendRoomMessage(ROOM::ZegoMessageType::Text, ROOM::ZegoMessageCategory::Chat, ROOM::ZegoMessagePriority::Default, m_strLastSendMsg.toStdString().c_str());

	ui.m_edInput->setText(QStringLiteral(""));
	
}

void ZegoLiveRoomDialog::OnButtonSoundCapture()
{
	if (ui.m_bCapture->text() == QStringLiteral("声卡采集"))
	{
		LIVEROOM::EnableMixSystemPlayout(true);
		ui.m_bCapture->setText(QStringLiteral("停止采集"));
	}
	else
	{
		LIVEROOM::EnableMixSystemPlayout(false);
		ui.m_bCapture->setText(QStringLiteral("声卡采集"));
	}
}

void ZegoLiveRoomDialog::OnButtonMircoPhone()
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

void ZegoLiveRoomDialog::OnButtonSound()
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

void ZegoLiveRoomDialog::OnProgChange()
{
	ui.m_bProgMircoPhone->setProgValue(LIVEROOM::GetCaptureSoundLevel());
	ui.m_bProgMircoPhone->update();
}

void ZegoLiveRoomDialog::OnShareLink()
{
	
	QString encodeHls = encodeStringAddingEscape(sharedHlsUrl);
	QString encodeRtmp = encodeStringAddingEscape(sharedRtmpUrl);
	QString encodeID = encodeStringAddingEscape(m_pChatRoom->getRoomId());
	QString encodeStreamID = encodeStringAddingEscape(m_anchorStreamInfo->getStreamId());
	
	QString link("http://www.zego.im/share/index2?video=" + encodeHls + "&rtmp=" + encodeRtmp + "&id=" + encodeID + "&stream=" + encodeStreamID);
	ZegoShareDialog share(link);
	share.exec();

}

void ZegoLiveRoomDialog::OnButtonAux()
{
	if (ui.m_bAux->text() == QStringLiteral("开启混音"))
	{
		BeginAux();
	}
	else
	{
		EndAux();
	}
}

void ZegoLiveRoomDialog::mousePressEvent(QMouseEvent *event)
{
	mousePosition = event->pos();
	//只对标题栏范围内的鼠标事件进行处理
	
	if (mousePosition.y() <= pos_min_y)
		return;
	if (mousePosition.y() >= pos_max_y)
		return;
	isMousePressed = true;
}

void ZegoLiveRoomDialog::mouseMoveEvent(QMouseEvent *event)
{
	if (isMousePressed == true)
	{
		QPoint movePot = event->globalPos() - mousePosition;
		move(movePot);
	}
}

void ZegoLiveRoomDialog::mouseReleaseEvent(QMouseEvent *event)
{
	isMousePressed = false;
}

void ZegoLiveRoomDialog::mouseDoubleClickEvent(QMouseEvent *event)
{
	
	
}
//void ZegoLiveRoomDialog::keyPressedEvent(QKeyEvent  *event)
//{
//	if (event->key() == Qt::Key::Key_Enter)
//		OnButtonSendMessage();
//}

void ZegoLiveRoomDialog::paintEvent(QPaintEvent *event)
{

}

void ZegoLiveRoomDialog::closeEvent(QCloseEvent *e)
{
	GetOut();
	this->close();
}

#include "ZegoSingleAudienceDialog.h"
#include "ZegoSDKSignal.h"
#include <QMessageBox>
#include <QDebug>
#ifdef Q_OS_MAC
#include "ZegoAVDevice.h"
#endif
ZegoSingleAudienceDialog::ZegoSingleAudienceDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	//UI的信号槽
	connect(ui.m_bMin, &QPushButton::clicked, this, &ZegoSingleAudienceDialog::OnClickTitleButton);
	connect(ui.m_bMax, &QPushButton::clicked, this, &ZegoSingleAudienceDialog::OnClickTitleButton);
	connect(ui.m_bClose, &QPushButton::clicked, this, &ZegoSingleAudienceDialog::OnClickTitleButton);
}

ZegoSingleAudienceDialog::ZegoSingleAudienceDialog(qreal dpi, SettingsPtr curSettings, RoomPtr room, QString curUserID, QString curUserName, /*bool isAnchor, int curMode,*/ QDialog *lastDialog, QDialog *parent)
	:m_dpi(dpi),
	m_pAVSettings(curSettings),
	m_pChatRoom(room),
	m_strCurUserID(curUserID),
	m_strCurUserName(curUserName),
	m_bCKEnableMic(false),
	m_bCKEnableSpeaker(true),
	m_lastDialog(lastDialog)
{
	ui.setupUi(this);


	//通过sdk的信号连接到本类的槽函数中
	connect(GetAVSignal(), &QZegoAVSignal::sigLoginRoom, this, &ZegoSingleAudienceDialog::OnLoginRoom);
	connect(GetAVSignal(), &QZegoAVSignal::sigStreamUpdated, this, &ZegoSingleAudienceDialog::OnStreamUpdated);
	connect(GetAVSignal(), &QZegoAVSignal::sigPlayStateUpdate, this, &ZegoSingleAudienceDialog::OnPlayStateUpdate);
	connect(GetAVSignal(), &QZegoAVSignal::sigDisconnect, this, &ZegoSingleAudienceDialog::OnDisconnect);
	connect(GetAVSignal(), &QZegoAVSignal::sigKickOut, this, &ZegoSingleAudienceDialog::OnKickOut);
	connect(GetAVSignal(), &QZegoAVSignal::sigPlayQualityUpdate, this, &ZegoSingleAudienceDialog::OnPlayQualityUpdate);
	connect(GetAVSignal(), &QZegoAVSignal::sigSendRoomMessage, this, &ZegoSingleAudienceDialog::OnSendRoomMessage);
	connect(GetAVSignal(), &QZegoAVSignal::sigRecvRoomMessage, this, &ZegoSingleAudienceDialog::OnRecvRoomMessage);
	connect(GetAVSignal(), &QZegoAVSignal::sigUserUpdate, this, &ZegoSingleAudienceDialog::OnUserUpdate);
	connect(GetAVSignal(), &QZegoAVSignal::sigAudioDeviceChanged, this, &ZegoSingleAudienceDialog::OnAudioDeviceChanged);
	connect(GetAVSignal(), &QZegoAVSignal::sigVideoDeviceChanged, this, &ZegoSingleAudienceDialog::OnVideoDeviceChanged);
	connect(GetAVSignal(), &QZegoAVSignal::sigSnapshot, this, &ZegoSingleAudienceDialog::OnSnapshot, Qt::DirectConnection);

	//UI的信号槽
	connect(ui.m_bMin, &QPushButton::clicked, this, &ZegoSingleAudienceDialog::OnClickTitleButton);
	connect(ui.m_bMax, &QPushButton::clicked, this, &ZegoSingleAudienceDialog::OnClickTitleButton);
	connect(ui.m_bClose, &QPushButton::clicked, this, &ZegoSingleAudienceDialog::OnClickTitleButton);

	connect(ui.m_bSendMessage, &QPushButton::clicked, this, &ZegoSingleAudienceDialog::OnButtonSendMessage);
	connect(ui.m_bSound, &QPushButton::clicked, this, &ZegoSingleAudienceDialog::OnButtonSound);
	connect(ui.m_bShare, &QPushButton::clicked, this, &ZegoSingleAudienceDialog::OnShareLink);
	connect(ui.m_bFullScreen, &QPushButton::clicked, this, &ZegoSingleAudienceDialog::OnButtonShowFullScreen);
	connect(ui.m_cbMircoPhone, SIGNAL(currentIndexChanged(int)), this, SLOT(OnSwitchAudioDevice(int)));
	connect(ui.m_cbCamera, SIGNAL(currentIndexChanged(int)), this, SLOT(OnSwitchVideoDevice(int)));
	
	connect(this, &ZegoSingleAudienceDialog::sigShowSnapShotImage, this, &ZegoSingleAudienceDialog::OnShowSnapShotImage);

	this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏 

	ui.m_edInput->installEventFilter(this);
	this->installEventFilter(this);

	QGridLayout *gridLayout = new QGridLayout();
	gridLayout->setSpacing(0);
	gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
	ui.zoneLiveViewHorizontalLayout->addLayout(gridLayout);

	//单主播模式单画面设置
	m_mainLiveView = new QZegoAVView(ZEGODIALOG_SingleAudience);
	connect(m_mainLiveView, &QZegoAVView::sigSnapShotOnSingleAudienceWithStreamID, this, &ZegoSingleAudienceDialog::OnSnapshotWithStreamID);

	m_mainLiveView->setMinimumSize(QSize(960, 540));
	m_mainLiveView->setStyleSheet(QLatin1String("border: none;\n"
		"background-color: #383838;"));
	gridLayout->addWidget(m_mainLiveView, 0, 0, 1, 1);
}

ZegoSingleAudienceDialog::~ZegoSingleAudienceDialog()
{

}

//功能函数
void ZegoSingleAudienceDialog::initDialog()
{
	//在mac系统下不支持声卡采集
#ifdef Q_OS_MAC
	ui.m_bCapture->setVisible(false);
#endif

	//单主播模式下没有连麦功能
	ui.m_bRequestJoinLive->setVisible(false);

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
	QString strTitle = QString(QStringLiteral("【%1】%2")).arg(QStringLiteral("单主播模式")).arg(m_pChatRoom->getRoomName());
	ui.m_lbRoomName->setText(strTitle);

	//在观众模式下，如果此时观看的房间直播模式为"单主播模式"，则麦克风下拉列表、摄像头下拉列表、混音、声卡采集这四个控件不可用
	SetOperation(false);

	//剩余能用的AVView
	for (int i = MAX_VIEW_COUNT; i >= 0; i--)
		m_avaliableView.push_front(i);
	
	AVViews.push_back(m_mainLiveView);

	//推拉流成功前不能分享链接
	ui.m_bShare->setEnabled(false);

	//允许使用麦克风
	LIVEROOM::EnableMic(m_bCKEnableMic);

	//枚举音视频设备
	EnumVideoAndAudioDevice();

	int role = LIVEROOM::ZegoRoomRole::Audience;
	if (!LIVEROOM::LoginRoom(m_pChatRoom->getRoomId().toStdString().c_str(), role, m_pChatRoom->getRoomName().toStdString().c_str()))
	{
		QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("进入房间失败"));
	}

}

void ZegoSingleAudienceDialog::StartPlayStream(StreamPtr stream)
{
	if (stream == nullptr) { return; }

	m_pChatRoom->addStream(stream);

	if (m_avaliableView.size() > 0)
	{
		int nIndex = takeLeastAvaliableViewIndex();
		qDebug() << "playStream nIndex = " << nIndex;
		stream->setPlayView(nIndex);

		AVViews[nIndex]->setViewStreamID(stream->getStreamId());
		//配置View
		LIVEROOM::SetViewMode(LIVEROOM::ZegoVideoViewModeScaleAspectFit, stream->getStreamId().toStdString().c_str());
		LIVEROOM::StartPlayingStream(stream->getStreamId().toStdString().c_str(), (void *)AVViews[nIndex]->winId());
	}
}

void ZegoSingleAudienceDialog::StopPlayStream(const QString& streamID)
{
	if (streamID.size() == 0) { return; }

	LIVEROOM::StopPlayingStream(streamID.toStdString().c_str());

	StreamPtr pStream = m_pChatRoom->removeStream(streamID);
	FreeAVView(pStream);

	m_mainLiveView->setViewStreamID("");
}

void ZegoSingleAudienceDialog::GetOut()
{
	//EndAux();
	for (auto& stream : m_pChatRoom->getStreamList())
	{
		if (stream != nullptr)
		    StopPlayStream(stream->getStreamId());
	}

	roomMemberDelete(m_strCurUserName);
	LIVEROOM::LogoutRoom();
	
	//释放堆内存
	delete m_cbMircoPhoneListView;
	delete m_cbCameraListView;
	delete m_memberModel;
	delete m_chatModel;
	delete m_cbMircoPhoneModel;
	delete m_cbCameraModel;
	//指针置空
	m_cbMircoPhoneListView = nullptr;
	m_cbCameraListView = nullptr;
	m_memberModel = nullptr;
	m_chatModel = nullptr;
	m_cbMircoPhoneModel = nullptr;
	m_cbCameraModel = nullptr;
}

void ZegoSingleAudienceDialog::initComboBox()
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

void ZegoSingleAudienceDialog::EnumVideoAndAudioDevice()
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

void ZegoSingleAudienceDialog::insertStringListModelItem(QStringListModel * model, QString name, int size)
{
	if (model == nullptr)
		return;

	int row = size;
	model->insertRows(row, 1);
	QModelIndex index = model->index(row);
	model->setData(index, name);

}

void ZegoSingleAudienceDialog::removeStringListModelItem(QStringListModel * model, QString name)
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

int ZegoSingleAudienceDialog::takeLeastAvaliableViewIndex()
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

void ZegoSingleAudienceDialog::FreeAVView(StreamPtr stream)
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

void ZegoSingleAudienceDialog::SetOperation(bool state)
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

QString ZegoSingleAudienceDialog::encodeStringAddingEscape(QString str)
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

void ZegoSingleAudienceDialog::roomMemberAdd(QString userName)
{
	if (m_memberModel == nullptr)
		return;

	insertStringListModelItem(m_memberModel, userName, m_memberModel->rowCount());
	ui.m_tabCommonAndUserList->setTabText(1, QString(QStringLiteral("成员(%1)").arg(m_memberModel->rowCount())));
}

void ZegoSingleAudienceDialog::roomMemberDelete(QString userName)
{
	if (m_memberModel == nullptr)
		return;

	removeStringListModelItem(m_memberModel, userName);
	ui.m_tabCommonAndUserList->setTabText(1, QString(QStringLiteral("成员(%1)").arg(m_memberModel->rowCount())));
}


bool ZegoSingleAudienceDialog::praseJsonData(QJsonDocument doc)
{
	QJsonObject obj = doc.object();

	QJsonValue isFirstAnchor = obj.take(m_FirstAnchor);
	QJsonValue hlsUrl = obj.take(m_HlsKey);
	QJsonValue rtmpUrl = obj.take(m_RtmpKey);

	sharedHlsUrl = hlsUrl.toString();
	sharedRtmpUrl = rtmpUrl.toString();

	return true;
}


//SDK回调
void ZegoSingleAudienceDialog::OnLoginRoom(int errorCode, const QString& strRoomID, QVector<StreamPtr> vStreamList)
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


	//当前房间的直播模式为单主播模式，直接拉多路流
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

void ZegoSingleAudienceDialog::OnStreamUpdated(const QString& roomId, QVector<StreamPtr> vStreamList, LIVEROOM::ZegoStreamUpdateType type)
{
	//在单主播模式下，有流更新直接处理
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



void ZegoSingleAudienceDialog::OnPlayStateUpdate(int stateCode, const QString& streamId)
{
	qDebug() << "OnPlay! stateCode = " << stateCode;

	ui.m_bShare->setEnabled(true);

	if (stateCode != 0)
	{
		// 回收view
		StreamPtr pStream = m_pChatRoom->removeStream(streamId);
		FreeAVView(pStream);
	}
}

void ZegoSingleAudienceDialog::OnUserUpdate(QVector<QString> userIDs, QVector<QString> userNames, QVector<int> userFlags, QVector<int> userRoles, unsigned int userCount, LIVEROOM::ZegoUserUpdateType type)
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

void ZegoSingleAudienceDialog::OnDisconnect(int errorCode, const QString& roomId)
{
	if (m_pChatRoom->getRoomId() == roomId)
	{
		QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("您已掉线"));
		OnClose();
	}
}

void ZegoSingleAudienceDialog::OnKickOut(int reason, const QString& roomId)
{
	if (m_pChatRoom->getRoomId() == roomId)
	{
		QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("您已被踢出房间"));
		OnClose();
	}
}

void ZegoSingleAudienceDialog::OnPlayQualityUpdate(const QString& streamId, int quality, double videoFPS, double videoKBS)
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

void ZegoSingleAudienceDialog::OnSendRoomMessage(int errorCode, const QString& roomID, int sendSeq, unsigned long long messageId)
{
	if (errorCode != 0)
	{
		QMessageBox::warning(NULL, QStringLiteral("消息发送失败"), QStringLiteral("错误码: %1").arg(errorCode));
		return;
	}

	qDebug() << "message send success";
}

void ZegoSingleAudienceDialog::OnRecvRoomMessage(const QString& roomId, QVector<RoomMsgPtr> vRoomMsgList)
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

void ZegoSingleAudienceDialog::OnAudioDeviceChanged(AV::AudioDeviceType deviceType, const QString& strDeviceId, const QString& strDeviceName, AV::DeviceState state)
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

void ZegoSingleAudienceDialog::OnVideoDeviceChanged(const QString& strDeviceId, const QString& strDeviceName, AV::DeviceState state)
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

void ZegoSingleAudienceDialog::OnSnapshot(void *pImage, const QString &streamID)
{
	QImage *image = new QImage;

#ifdef Q_OS_WIN
	QPixmap pixmap = qt_pixmapFromWinHBITMAP((HBITMAP)pImage, 0);
	*image = pixmap.toImage();
#endif
	
	//发送信号切线程，不能阻塞当前线程
	emit sigShowSnapShotImage(image);
}


//UI回调
void ZegoSingleAudienceDialog::OnClickTitleButton()
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

void ZegoSingleAudienceDialog::OnClose()
{
	//GetOut();
	this->close();
	//m_lastDialog->show();
}

void ZegoSingleAudienceDialog::OnButtonSendMessage()
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

void ZegoSingleAudienceDialog::OnButtonSound()
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

void ZegoSingleAudienceDialog::OnShareLink()
{

	QString encodeHls = encodeStringAddingEscape(sharedHlsUrl);
	QString encodeRtmp = encodeStringAddingEscape(sharedRtmpUrl);
	QString encodeID = encodeStringAddingEscape(m_pChatRoom->getRoomId());
	QString encodeStreamID = encodeStringAddingEscape(m_anchorStreamInfo->getStreamId());

	QString link("http://www.zego.im/share/index2?video=" + encodeHls + "&rtmp=" + encodeRtmp + "&id=" + encodeID + "&stream=" + encodeStreamID);
	ZegoShareDialog share(link);
	share.exec();

}

void ZegoSingleAudienceDialog::OnButtonShowFullScreen()
{
	//直播窗口总在最顶层
	ui.m_zoneLiveView_Inner->setWindowFlags(ui.m_zoneLiveView_Inner->windowFlags() | Qt::WindowStaysOnTopHint);
	ui.m_zoneLiveView_Inner->setParent(NULL);
	ui.m_zoneLiveView_Inner->showFullScreen();
	m_isLiveFullScreen = true;
}

void ZegoSingleAudienceDialog::OnSwitchAudioDevice(int id)
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

void ZegoSingleAudienceDialog::OnSwitchVideoDevice(int id)
{
	if (id < 0)
		return;

	if (id < m_vecVideoDeviceIDs.size())
	{
		LIVEROOM::SetVideoDevice(m_vecVideoDeviceIDs[id].toStdString().c_str());
		m_pAVSettings->SetCameraId(m_vecVideoDeviceIDs[id]);
		ui.m_cbCamera->setCurrentIndex(id);
		update();
	}
}

void ZegoSingleAudienceDialog::OnSnapshotWithStreamID(const QString &streamID)
{
	LIVEROOM::TakeSnapshot(streamID.toStdString().c_str());
}

void ZegoSingleAudienceDialog::OnShowSnapShotImage(QImage *imageData)
{
	ZegoImageShowDialog imageShowDialog(imageData, imageData->width(), imageData->height(), m_pAVSettings);
	imageShowDialog.initDialog();
	imageShowDialog.exec();

}

void ZegoSingleAudienceDialog::mousePressEvent(QMouseEvent *event)
{
	mousePosition = event->pos();
	//只对标题栏范围内的鼠标事件进行处理

	if (mousePosition.y() <= pos_min_y)
		return;
	if (mousePosition.y() >= pos_max_y)
		return;
	isMousePressed = true;
}

void ZegoSingleAudienceDialog::mouseMoveEvent(QMouseEvent *event)
{
	if (isMousePressed == true)
	{
		QPoint movePot = event->globalPos() - mousePosition;
		move(movePot);
	}
}

void ZegoSingleAudienceDialog::mouseReleaseEvent(QMouseEvent *event)
{
	isMousePressed = false;
}

void ZegoSingleAudienceDialog::mouseDoubleClickEvent(QMouseEvent *event)
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

void ZegoSingleAudienceDialog::closeEvent(QCloseEvent *e)
{
	QDialog::closeEvent(e);
	GetOut();
	//this->close();
	emit sigSaveVideoSettings(m_pAVSettings);
	m_lastDialog->show();
}

bool ZegoSingleAudienceDialog::eventFilter(QObject *target, QEvent *event)
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
				return true;
			}
		}

		return QDialog::eventFilter(target, event);
	}
}
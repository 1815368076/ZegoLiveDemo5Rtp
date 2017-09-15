#include "ZegoMixStreamAudienceDialog.h"
#include "ZegoSDKSignal.h"
#include <QMessageBox>
#include <QDebug>

ZegoMixStreamAudienceDialog::ZegoMixStreamAudienceDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	//UI���źŲ�
	connect(ui.m_bMin, &QPushButton::clicked, this, &ZegoMixStreamAudienceDialog::OnClickTitleButton);
	connect(ui.m_bMax, &QPushButton::clicked, this, &ZegoMixStreamAudienceDialog::OnClickTitleButton);
	connect(ui.m_bClose, &QPushButton::clicked, this, &ZegoMixStreamAudienceDialog::OnClickTitleButton);
}

ZegoMixStreamAudienceDialog::ZegoMixStreamAudienceDialog(SettingsPtr curSettings, RoomPtr room, QString curUserID, QString curUserName, QDialog *lastDialog, QDialog *parent)
	: m_pAVSettings(curSettings),
	m_pChatRoom(room),
	m_strCurUserID(curUserID),
	m_strCurUserName(curUserName),
	m_bCKEnableMic(true),
	m_bCKEnableSpeaker(true),
	m_lastDialog(lastDialog)
{
	ui.setupUi(this);


	//ͨ��sdk���ź����ӵ�����Ĳۺ�����
	connect(GetAVSignal(), &QZegoAVSignal::sigLoginRoom, this, &ZegoMixStreamAudienceDialog::OnLoginRoom);
	connect(GetAVSignal(), &QZegoAVSignal::sigStreamUpdated, this, &ZegoMixStreamAudienceDialog::OnStreamUpdated);
	connect(GetAVSignal(), &QZegoAVSignal::sigPublishStateUpdate, this, &ZegoMixStreamAudienceDialog::OnPublishStateUpdate);
	connect(GetAVSignal(), &QZegoAVSignal::sigPlayStateUpdate, this, &ZegoMixStreamAudienceDialog::OnPlayStateUpdate);
	connect(GetAVSignal(), &QZegoAVSignal::sigDisconnect, this, &ZegoMixStreamAudienceDialog::OnDisconnect);
	connect(GetAVSignal(), &QZegoAVSignal::sigKickOut, this, &ZegoMixStreamAudienceDialog::OnKickOut);
	connect(GetAVSignal(), &QZegoAVSignal::sigPublishQualityUpdate, this, &ZegoMixStreamAudienceDialog::OnPublishQualityUpdate);
	connect(GetAVSignal(), &QZegoAVSignal::sigPlayQualityUpdate, this, &ZegoMixStreamAudienceDialog::OnPlayQualityUpdate);
	//�ź����ͬ��ִ��
	connect(GetAVSignal(), &QZegoAVSignal::sigAuxInput, this, &ZegoMixStreamAudienceDialog::OnAVAuxInput, Qt::DirectConnection);
	connect(GetAVSignal(), &QZegoAVSignal::sigSendRoomMessage, this, &ZegoMixStreamAudienceDialog::OnSendRoomMessage);
	connect(GetAVSignal(), &QZegoAVSignal::sigRecvRoomMessage, this, &ZegoMixStreamAudienceDialog::OnRecvRoomMessage);
	connect(GetAVSignal(), &QZegoAVSignal::sigJoinLiveResponse, this, &ZegoMixStreamAudienceDialog::OnJoinLiveResponse);
	connect(GetAVSignal(), &QZegoAVSignal::sigUserUpdate, this, &ZegoMixStreamAudienceDialog::OnUserUpdate);
	connect(GetAVSignal(), &QZegoAVSignal::sigMixStream, this, &ZegoMixStreamAudienceDialog::OnMixStream);
	connect(GetAVSignal(), &QZegoAVSignal::sigAudioDeviceChanged, this, &ZegoMixStreamAudienceDialog::OnAudioDeviceChanged);
	connect(GetAVSignal(), &QZegoAVSignal::sigVideoDeviceChanged, this, &ZegoMixStreamAudienceDialog::OnVideoDeviceChanged);
	connect(GetAVSignal(), &QZegoAVSignal::sigRecvEndJoinLiveCommand, this, &ZegoMixStreamAudienceDialog::OnRecvEndJoinLiveCommand);

	//UI���źŲ�
	connect(ui.m_bMin, &QPushButton::clicked, this, &ZegoMixStreamAudienceDialog::OnClickTitleButton);
	connect(ui.m_bMax, &QPushButton::clicked, this, &ZegoMixStreamAudienceDialog::OnClickTitleButton);
	connect(ui.m_bClose, &QPushButton::clicked, this, &ZegoMixStreamAudienceDialog::OnClickTitleButton);

	connect(ui.m_bRequestJoinLive, &QPushButton::clicked, this, &ZegoMixStreamAudienceDialog::OnButtonJoinLive);
	connect(ui.m_bSendMessage, &QPushButton::clicked, this, &ZegoMixStreamAudienceDialog::OnButtonSendMessage);
	connect(ui.m_bCapture, &QPushButton::clicked, this, &ZegoMixStreamAudienceDialog::OnButtonSoundCapture);
	connect(ui.m_bProgMircoPhone, &QPushButton::clicked, this, &ZegoMixStreamAudienceDialog::OnButtonMircoPhone);
	connect(ui.m_bSound, &QPushButton::clicked, this, &ZegoMixStreamAudienceDialog::OnButtonSound);
	connect(ui.m_bShare, &QPushButton::clicked, this, &ZegoMixStreamAudienceDialog::OnShareLink);
	connect(ui.m_bAux, &QPushButton::clicked, this, &ZegoMixStreamAudienceDialog::OnButtonAux);

	connect(ui.m_cbMircoPhone, SIGNAL(currentIndexChanged(int)), this, SLOT(OnSwitchAudioDevice(int)));
	connect(ui.m_cbCamera, SIGNAL(currentIndexChanged(int)), this, SLOT(OnSwitchVideoDevice(int)));

	timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &ZegoMixStreamAudienceDialog::OnProgChange);

	//�������ݲ���
	m_pAuxData = NULL;
	m_nAuxDataLen = 0;
	m_nAuxDataPos = 0;

	this->setWindowFlags(Qt::FramelessWindowHint);//ȥ�������� 

	ui.m_edInput->installEventFilter(this);
	//���û����ص���ʼֵ
	m_mixStreamRequestSeq = 1;

	gridLayout = new QGridLayout;
}

ZegoMixStreamAudienceDialog::~ZegoMixStreamAudienceDialog()
{

}

//���ܺ���
void ZegoMixStreamAudienceDialog::initDialog()
{
	//��macϵͳ�²�֧�������ɼ�
#ifdef APPLE
	ui.m_bCapture->setVisible(false);
#endif

	initComboBox();

	//�Ի���ģ�ͳ�ʼ��
	m_chatModel = new QStringListModel(this);
	ui.m_listChat->setModel(m_chatModel);
	ui.m_listChat->setItemDelegate(new NoFocusFrameDelegate(this));
	ui.m_listChat->setEditTriggers(QAbstractItemView::NoEditTriggers);


	//��Ա�б��ʼ��
	m_memberModel = new QStringListModel(this);
	ui.m_listMember->setModel(m_memberModel);
	ui.m_listMember->setItemDelegate(new NoFocusFrameDelegate(this));
	ui.m_listMember->setEditTriggers(QAbstractItemView::NoEditTriggers);

	//��ȡ��������
	QString strTitle = QString(QStringLiteral("��%1��%2")).arg(QStringLiteral("����ģʽ")).arg(m_pChatRoom->getRoomName());
	ui.m_lbRoomName->setText(strTitle);

	//�ڻ���ģʽ�£������ʱ����δ��������˷������б�����ͷ�����б������������ɼ����ĸ��ؼ�������
	if (!m_bIsJoinLive)
        SetOperation(false);

	//ʣ�����õ�AVView
	for (int i = MAX_VIEW_COUNT; i >= 0; i--)
		m_avaliableView.push_front(i);
	
	//�����ɹ�ǰ���ܷ�����������
	ui.m_bShare->setEnabled(false);
	ui.m_bRequestJoinLive->setEnabled(false);

	//����ʹ����˷�
	LIVEROOM::EnableMic(m_bCKEnableMic);

	//ö������Ƶ�豸
	EnumVideoAndAudioDevice();

	int role = LIVEROOM::ZegoRoomRole::Audience;
	if (!LIVEROOM::LoginRoom(m_pChatRoom->getRoomId().toStdString().c_str(), role, m_pChatRoom->getRoomName().toStdString().c_str()))
	{
		QMessageBox::information(NULL, QStringLiteral("��ʾ"), QStringLiteral("���뷿��ʧ��"));
	}

}

void ZegoMixStreamAudienceDialog::StartPublishStream()
{

	QTime currentTime = QTime::currentTime();
	//��ȡ��ǰʱ��ĺ���
	int ms = currentTime.msec();
	QString strStreamId;
	strStreamId = QString(QStringLiteral("s-windows-%1-%2")).arg(m_strCurUserID).arg(ms);
	m_strPublishStreamID = strStreamId;
	m_myMixStreamID = "mix-" + m_strPublishStreamID;

	StreamPtr pPublishStream(new QZegoStreamModel(m_strPublishStreamID, m_strCurUserID, m_strCurUserName, "", true));

	m_pChatRoom->addStream(pPublishStream);

	if (m_avaliableView.size() > 0)
	{
		int nIndex = takeLeastAvaliableViewIndex();
		pPublishStream->setPlayView(nIndex);
		addAVView(nIndex);
		qDebug() << "publish nIndex = " << nIndex <<"publish stream id is "<<pPublishStream->getStreamId();
		//����View

		LIVEROOM::SetPreviewView((void *)AVViews.last()->winId());
		LIVEROOM::SetPreviewViewMode(LIVEROOM::ZegoVideoViewModeScaleAspectFill);
		LIVEROOM::StartPreview();

		QString streamID = m_strPublishStreamID;
		qDebug() << "start publishing!";
		LIVEROOM::StartPublishing(m_pChatRoom->getRoomName().toStdString().c_str(), streamID.toStdString().c_str(), LIVEROOM::ZEGO_MIX_STREAM, "");
		m_bIsPublishing = true;
	}
}

void ZegoMixStreamAudienceDialog::StopPublishStream(const QString& streamID)
{
	if (streamID.size() == 0){ return; }

	StreamPtr curStream;
	for (auto stream : m_pChatRoom->getStreamList())
	{
		if (streamID == stream->getStreamId())
			curStream = stream;
	}

	qDebug() << "stop publish view index = " << curStream->getPlayView();
	removeAVView(curStream->getPlayView());

	LIVEROOM::SetPreviewView(nullptr);
	LIVEROOM::StopPreview();
	LIVEROOM::StopPublishing();
	m_bIsPublishing = false;

	StreamPtr pStream = m_pChatRoom->removeStream(streamID);
	FreeAVView(pStream);
}

void ZegoMixStreamAudienceDialog::StartPlayStream(StreamPtr stream)
{
	if (stream == nullptr) { return; }

	m_pChatRoom->addStream(stream);

	if (m_avaliableView.size() > 0)
	{
		//int nIndex = m_avaliableView.top();
		int nIndex = takeLeastAvaliableViewIndex();
		qDebug() << "playStream nIndex = " << nIndex << "play stream id is "<< stream->getStreamId();
		//m_avaliableView.pop();
		stream->setPlayView(nIndex);
		addAVView(nIndex);

		//����View
		LIVEROOM::SetViewMode(LIVEROOM::ZegoVideoViewModeScaleAspectFill, stream->getStreamId().toStdString().c_str());
		LIVEROOM::StartPlayingStream(stream->getStreamId().toStdString().c_str(), (void *)AVViews.last()->winId());
	}
}

void ZegoMixStreamAudienceDialog::StopPlayStream(const QString& streamID)
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

void ZegoMixStreamAudienceDialog::GetOut()
{
	//�뿪����ʱ�Ȱѻ������ܺ������ɼ��ر�
	EndAux();
	if (ui.m_bCapture->text() == QStringLiteral("ֹͣ�ɼ�"))
		LIVEROOM::EnableMixSystemPlayout(false);

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

	//�ͷŶ��ڴ�
	delete m_cbMircoPhoneListView;
	delete m_cbCameraListView;
	delete m_memberModel;
	delete m_chatModel;
	delete m_cbMircoPhoneModel;
	delete m_cbCameraModel;
	delete timer;
	delete gridLayout;
}

void ZegoMixStreamAudienceDialog::initComboBox()
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

void ZegoMixStreamAudienceDialog::EnumVideoAndAudioDevice()
{
	//�豸��
	int nDeviceCount = 0;
	AV::DeviceInfo* pDeviceList(NULL);

	//��ȡ��Ƶ�豸
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

	//��ȡ��Ƶ�豸
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
}

void ZegoMixStreamAudienceDialog::insertStringListModelItem(QStringListModel * model, QString name, int size)
{
	int row = size;
	model->insertRows(row, 1);
	QModelIndex index = model->index(row);
	model->setData(index, name);

}

void ZegoMixStreamAudienceDialog::removeStringListModelItem(QStringListModel * model, QString name)
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

int ZegoMixStreamAudienceDialog::takeLeastAvaliableViewIndex()
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

void ZegoMixStreamAudienceDialog::initAVView(QZegoAVView *view)
{
	view->setMinimumSize(QSize(240, 0));
	view->setStyleSheet(QLatin1String("border: none;\n"
		"background-color: #383838;"));
}

void ZegoMixStreamAudienceDialog::addAVView(int addViewIndex)
{
	QZegoAVView *newAVView = new QZegoAVView;
	initAVView(newAVView);
	newAVView->setViewIndex(addViewIndex);
	AVViews.push_back(newAVView);

	updateViewLayout(AVViews.size());
}

void ZegoMixStreamAudienceDialog::removeAVView(int removeViewIndex)
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

void ZegoMixStreamAudienceDialog::updateViewLayout(int viewCount)
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

void ZegoMixStreamAudienceDialog::FreeAVView(StreamPtr stream)
{
	if (stream == nullptr)
	{
		return;
	}

	int nIndex = stream->getPlayView();

	m_avaliableView.push_front(nIndex);

	//ˢ�¿��õ�viewҳ��
	update();
}

void ZegoMixStreamAudienceDialog::SetOperation(bool state)
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

QString ZegoMixStreamAudienceDialog::encodeStringAddingEscape(QString str)
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

void ZegoMixStreamAudienceDialog::roomMemberAdd(QString userName)
{

	insertStringListModelItem(m_memberModel, userName, m_memberModel->rowCount());
	ui.m_tabCommonAndUserList->setTabText(1, QString(QStringLiteral("��Ա(%1)").arg(m_memberModel->rowCount())));
}

void ZegoMixStreamAudienceDialog::roomMemberDelete(QString userName)
{
	removeStringListModelItem(m_memberModel, userName);
	ui.m_tabCommonAndUserList->setTabText(1, QString(QStringLiteral("��Ա(%1)").arg(m_memberModel->rowCount())));
}

bool ZegoMixStreamAudienceDialog::isStreamExisted(QString streamID)
{
	bool isExisted = false;

	if (m_strPublishStreamID == streamID)
		return true;

	//��ȡ�������б�
	QVector<StreamPtr> streamList = m_pChatRoom->getStreamList();
	for (auto streamInfo : streamList)
		if (streamInfo->getStreamId() == streamID)
			return true;

	return false;
}

void ZegoMixStreamAudienceDialog::StartMixStream()
{
	int size = m_mixStreamInfos.size();
	int width = m_pAVSettings->GetResolution().cx;
	int height = m_pAVSettings->GetResolution().cy;

	AV::ZegoCompleteMixStreamConfig mixStreamConfig;
	mixStreamConfig.pInputStreamList = new AV::ZegoMixStreamConfig[size];

	for (int i = 0; i < size; i++)
	{
		strcpy(mixStreamConfig.pInputStreamList[i].szStreamID, m_mixStreamInfos[i]->szStreamID);
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

void ZegoMixStreamAudienceDialog::StopPlayMixStream(QVector<StreamPtr> vStreamList)
{
	//ֻ���������˳��˲Ż�ֹͣ������
	for (auto stream : vStreamList)
	{
		if (stream->getStreamId() == m_anchorStreamInfo->getStreamId())
		{
			removeAVView(m_anchorStreamInfo->getPlayView());
			LIVEROOM::StopPlayingStream(m_anchorMixStreamID.toStdString().c_str());
			StreamPtr pStream = m_pChatRoom->removeStream(stream->getStreamId());
			FreeAVView(pStream);


		}
	}
}

void ZegoMixStreamAudienceDialog::StartPlayMixStream(StreamPtr streamInfo)
{
	qDebug() << "startPlayMixStream!";
	
	if (streamInfo == nullptr) { return; }

	m_pChatRoom->addStream(streamInfo);

	//���浱ǰ��������������Ϣ
	m_anchorStreamInfo = streamInfo;

	if (m_avaliableView.size() > 0)
	{
		
		int nIndex = takeLeastAvaliableViewIndex();
		qDebug() << "playMixStream index = " << nIndex;

		streamInfo->setPlayView(nIndex);
		addAVView(nIndex);

		//����View
		LIVEROOM::SetViewMode(LIVEROOM::ZegoVideoViewModeScaleAspectFill, m_anchorMixStreamID.toStdString().c_str());
		LIVEROOM::StartPlayingStream(m_anchorMixStreamID.toStdString().c_str(), (void *)AVViews.last()->winId());
	}

}

void ZegoMixStreamAudienceDialog::StartPlaySingleStream(QVector<StreamPtr> streamList)
{
	for (auto stream : streamList)
	{
		if (stream->getStreamId() != m_strPublishStreamID)
			StartPlayStream(stream);
	}
}

void ZegoMixStreamAudienceDialog::StopPlaySingleStream()
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

void ZegoMixStreamAudienceDialog::MixStreamAdd(QVector<StreamPtr> vStreamList, const QString& roomId)
{
	
}

void ZegoMixStreamAudienceDialog::MixStreamDelete(QVector<StreamPtr> vStreamList, const QString& roomId)
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


bool ZegoMixStreamAudienceDialog::praseMixJsonData(QJsonDocument doc)
{
	QJsonObject obj = doc.object();

	QJsonValue isFirstAnchor = obj.take(m_FirstAnchor);
	QJsonValue mixStreamId = obj.take(m_MixStreamID);
	QJsonValue hlsUrl = obj.take(m_HlsKey);
	QJsonValue rtmpUrl = obj.take(m_RtmpKey);
	
	QVariant tmpValue = isFirstAnchor.toString();
	bool isFirst = tmpValue.toBool();

	if ((isFirst || isFirstAnchor.toBool()) && !mixStreamId.toString().isEmpty())
	{
		m_anchorMixStreamID = mixStreamId.toString();
		sharedHlsUrl = hlsUrl.toString();
		sharedRtmpUrl = rtmpUrl.toString();
		return true;
	}

	return false;
}

void ZegoMixStreamAudienceDialog::BeginAux()
{
	QString filePath = QFileDialog::getOpenFileName(this,
		tr(QStringLiteral("��ѡ��һ�������ļ�").toStdString().c_str()),
		"./Resources",
		tr(QStringLiteral("pcm�ļ�(*.pcm)").toStdString().c_str()));


	if (!filePath.isEmpty())
	{
		FILE* fAux;
		fopen_s(&fAux, filePath.toStdString().c_str(), "rb");

		if (fAux == NULL)
		{
			QMessageBox::warning(this, QStringLiteral("����"), QStringLiteral("�ļ����ݴ���: %1").arg(filePath));
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

		ui.m_bAux->setText(QStringLiteral("�رջ���"));
	}
}

void ZegoMixStreamAudienceDialog::EndAux()
{
	LIVEROOM::EnableAux(false);

	ui.m_bAux->setText(QStringLiteral("��������"));
	delete[] m_pAuxData;
	m_nAuxDataLen = 0;
	m_nAuxDataPos = 0;
}

//SDK�ص�
void ZegoMixStreamAudienceDialog::OnLoginRoom(int errorCode, const QString& strRoomID, QVector<StreamPtr> vStreamList)
{
	qDebug() << "Login Room!";
	if (errorCode != 0)
	{
		QMessageBox::information(NULL, QStringLiteral("��ʾ"), QStringLiteral("��½����ʧ��"));
		OnClose();
		return;
	}

	//���뷿���б�
	roomMemberAdd(m_strCurUserName);

	
	for (auto stream : vStreamList)
		m_mixStreamList.push_back(stream);



	//��ǰ�����ֱ��ģʽΪ����ģʽ����һ������
	if (vStreamList.size() > 0){
		bool isSuccess = false;
		//�����ҳ���һ�����������ҵ�extraInfo��������Ϣ�����н���
		for (auto streamInfo : vStreamList)
		{
			QByteArray jsonArray = streamInfo->getExtraInfo().toUtf8();

			QJsonParseError json_error;
			QJsonDocument doc = QJsonDocument::fromJson(jsonArray, &json_error);

			if (json_error.error != QJsonParseError::NoError){ continue; }

			if (!doc.isObject()) { continue; }

			if (praseMixJsonData(doc))
			{
				StartPlayMixStream(streamInfo);
				isSuccess = true;
				break;
			}
		}

		if (!isSuccess)
		QMessageBox::warning(NULL, QStringLiteral("������ʧ��"), QStringLiteral("�����ڵ�һ����"));
	}
		
	


}

void ZegoMixStreamAudienceDialog::OnStreamUpdated(const QString& roomId, QVector<StreamPtr> vStreamList, LIVEROOM::ZegoStreamUpdateType type)
{
	
	
	//�ڻ���ģʽ�£���������ʱ��Ҫ����������(�ϲ�/ɾ��)
	//���ڿ�����������,���ڶ���Ҫ�仯��������б�
	if (!m_bIsPublishing && m_mixStreamList.size() > 0)
	{
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
	else if (m_bIsPublishing)
	{
		if (type == LIVEROOM::ZegoStreamUpdateType::StreamAdded)
		{
			for (auto stream : vStreamList)
			{
				if (isStreamExisted(stream->getStreamId()))
					continue;

				StartPlayStream(stream);
			}
		}
		else if (type == LIVEROOM::ZegoStreamUpdateType::StreamDeleted)
		{
			for (int i = 0; i < vStreamList.size(); i++)
			{
				if (!isStreamExisted(vStreamList[i]->getStreamId()))
					continue;

				StopPlayStream(vStreamList[i]->getStreamId());
			}
		}
	}
		
}

void ZegoMixStreamAudienceDialog::OnPublishStateUpdate(int stateCode, const QString& streamId, StreamPtr streamInfo)
{
	qDebug() << "Publish success!";
	if (stateCode == 0)
	{
		if (streamInfo != nullptr)
		{
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

		
		//���ڶ��ڻ���ģʽ����������ʱ����Ҫ�Ͽ�������Ϊ������
	
		//��ʱ����0��ViEW��������������
		if (m_avaliableView.size() >= m_mixStreamList.size())
		{
			//ֹͣ������
			//LIVEROOM::StopPlayingStream(m_mixStreamID.toStdString().c_str());
			//FreeAVView(streamInfo);

			//����������
			StartPlaySingleStream(m_mixStreamList);
			m_mixStreamList.clear();
		}
		
		ui.m_bAux->setEnabled(true);
		ui.m_bCapture->setEnabled(true);
		ui.m_bShare->setEnabled(true);

		//����ɹ�ʱ�����¿ؼ�����
		if (m_bIsJoinLive)
		{
			ui.m_bRequestJoinLive->setEnabled(true);
			ui.m_bRequestJoinLive->setText(QStringLiteral("ֹͣ����"));
			SetOperation(true);
		}

		//�����ɹ���������ʱ��������˷�����
		timer->start(0);

	}
	else
	{
		QMessageBox::warning(NULL, QStringLiteral("����ʧ��"), QStringLiteral("������: %1").arg(stateCode));
		ui.m_bRequestJoinLive->setText(QStringLiteral("��������"));
		ui.m_bRequestJoinLive->setEnabled(true);

		EndAux();
		// ֹͣԤ��, ����view
		LIVEROOM::StopPreview();
		LIVEROOM::SetPreviewView(nullptr);
		StreamPtr pStream = m_pChatRoom->removeStream(streamId);
		FreeAVView(pStream);
	}
}

void ZegoMixStreamAudienceDialog::OnPlayStateUpdate(int stateCode, const QString& streamId)
{
	qDebug() << "OnPlay! stateCode = " << stateCode;

	ui.m_bShare->setEnabled(true);
	ui.m_bRequestJoinLive->setEnabled(true);

	if (stateCode != 0)
	{
		// ����view
		StreamPtr pStream = m_pChatRoom->removeStream(streamId);
		FreeAVView(pStream);
	}
}

void ZegoMixStreamAudienceDialog::OnMixStream(unsigned int errorCode, const QString& hlsUrl, const QString& rtmpUrl, const QString& mixStreamID, int seq)
{
	qDebug() << "mixStream update!";
}

void ZegoMixStreamAudienceDialog::OnUserUpdate(QVector<QString> userIDs, QVector<QString> userNames, QVector<int> userFlags, QVector<int> userRoles, unsigned int userCount, LIVEROOM::ZegoUserUpdateType type)
{
	qDebug() << "onUserUpdate!";

	//ȫ������
	if (type == LIVEROOM::ZegoUserUpdateType::UPDATE_TOTAL){
		//removeAll
		m_memberModel->removeRows(0, m_memberModel->rowCount());

		insertStringListModelItem(m_memberModel, m_strCurUserName, 0);
		for (int i = 0; i < userCount; i++)
		{
			insertStringListModelItem(m_memberModel, userNames[i], m_memberModel->rowCount());
		}
	}
	//��������
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

	ui.m_tabCommonAndUserList->setTabText(1, QString(QStringLiteral("��Ա(%1)").arg(m_memberModel->rowCount())));
	ui.m_listMember->update();
}

void ZegoMixStreamAudienceDialog::OnDisconnect(int errorCode, const QString& roomId)
{
	if (m_pChatRoom->getRoomId() == roomId)
	{
		QMessageBox::information(NULL, QStringLiteral("��ʾ"), QStringLiteral("���ѵ���"));
		OnClose();
	}
}

void ZegoMixStreamAudienceDialog::OnKickOut(int reason, const QString& roomId)
{
	if (m_pChatRoom->getRoomId() == roomId)
	{
		QMessageBox::information(NULL, QStringLiteral("��ʾ"), QStringLiteral("���ѱ��߳�����"));
		OnClose();
	}
}

void ZegoMixStreamAudienceDialog::OnPlayQualityUpdate(const QString& streamId, int quality, double videoFPS, double videoKBS)
{
	StreamPtr pStream = m_pChatRoom->getStreamById(streamId);

	if (pStream == nullptr)
		return;

	int nIndex = pStream->getPlayView();

	if (nIndex < 0 || nIndex > 11)
		return;

	AVViews[nIndex]->setCurrentQuality(quality);

	//QVector<QString> q = { QStringLiteral("��"), QStringLiteral("��"), QStringLiteral("��"), QStringLiteral("��") };
	//qDebug() << QStringLiteral("��ǰ����") << nIndex << QStringLiteral("��ֱ������Ϊ") << q[quality];
}

void ZegoMixStreamAudienceDialog::OnPublishQualityUpdate(const QString& streamId, int quality, double videoFPS, double videoKBS)
{
	StreamPtr pStream = m_pChatRoom->getStreamById(streamId);

	if (pStream == nullptr)
		return;

	int nIndex = pStream->getPlayView();

	if (nIndex < 0 || nIndex > 11)
		return;

	AVViews[nIndex]->setCurrentQuality(quality);

	//QVector<QString> q = { QStringLiteral("��"), QStringLiteral("��"), QStringLiteral("��"), QStringLiteral("��") };
	//qDebug() << QStringLiteral("��ǰ����") << nIndex << QStringLiteral("��ֱ������Ϊ") << q[quality];

}

void ZegoMixStreamAudienceDialog::OnAVAuxInput(unsigned char *pData, int *pDataLen, int pDataLenValue, int *pSampleRate, int *pNumChannels)
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

void ZegoMixStreamAudienceDialog::OnSendRoomMessage(int errorCode, const QString& roomID, int sendSeq, unsigned long long messageId)
{
	if (errorCode != 0)
	{
		QMessageBox::warning(NULL, QStringLiteral("��Ϣ����ʧ��"), QStringLiteral("������: %1").arg(errorCode));
		return;
	}

	qDebug() << "message send success";
}

void ZegoMixStreamAudienceDialog::OnRecvRoomMessage(const QString& roomId, QVector<RoomMsgPtr> vRoomMsgList)
{
	for (auto& roomMsg : vRoomMsgList)
	{
		QString strTmpContent;
		strTmpContent = QString(QStringLiteral("%1: %2")).arg(roomMsg->getUserId()).arg(roomMsg->getContent());
		insertStringListModelItem(m_chatModel, strTmpContent, m_chatModel->rowCount());
		//ÿ�ν�����Ϣ����ʾ���һ��
		ui.m_listChat->scrollToBottom();

	}
}

void ZegoMixStreamAudienceDialog::OnJoinLiveResponse(int result, const QString& fromUserId, const QString& fromUserName, int seq)
{
	if (seq == m_iRequestJoinLiveSeq)
	{

		if (result == 0)
		{
			//ֹͣ������
			StopPlayMixStream(m_mixStreamList);
			StartPublishStream();
			
			m_bIsJoinLive = true;
			
		}
		else
		{
			ui.m_bRequestJoinLive->setText(QStringLiteral("��������"));
			QMessageBox::information(NULL, QStringLiteral("��ʾ"), QStringLiteral("�������󱻾ܾ�"));
			ui.m_bRequestJoinLive->setEnabled(true);
		}

	}
	
}

void ZegoMixStreamAudienceDialog::OnRecvEndJoinLiveCommand(const QString& userId, const QString& userName, const QString& roomId)
{
	//ֹͣ����ʱ��ֹͣ��������Ϊ������
	StopPlaySingleStream();
	StopPublishStream(m_strPublishStreamID);
	StartPlayMixStream(m_anchorStreamInfo);
	m_bIsJoinLive = false;
	SetOperation(false);
	QMessageBox::information(NULL, QStringLiteral("��ʾ"), QStringLiteral("���� %1 ����������������").arg(userName));
}

void ZegoMixStreamAudienceDialog::OnAudioDeviceChanged(AV::AudioDeviceType deviceType, const QString& strDeviceId, const QString& strDeviceName, AV::DeviceState state)
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
			//���currentCurl����i˵����ǰɾ�����豸�ǵ�ǰ����ʹ�õ��豸
			if (currentCurl == i)
			{
				//���ɾ��֮�����ܲ��ŵ��豸���ڣ���Ĭ��ѡ���һ����Ƶ�豸
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

void ZegoMixStreamAudienceDialog::OnVideoDeviceChanged(const QString& strDeviceId, const QString& strDeviceName, AV::DeviceState state)
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
			//���currentCurl����i˵����ǰɾ�����豸�ǵ�ǰ����ʹ�õ��豸
			if (currentCurl == i)
			{
				//Ĭ�ϲɼ���һ����Ƶ�豸
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

//UI�ص�
void ZegoMixStreamAudienceDialog::OnClickTitleButton()
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

void ZegoMixStreamAudienceDialog::OnButtonJoinLive()
{
	//��ǰ��ť�ı�Ϊ����ʼ����
	if (ui.m_bRequestJoinLive->text() == QStringLiteral("��������"))
	{
		ui.m_bRequestJoinLive->setText(QStringLiteral("������..."));
		ui.m_bRequestJoinLive->setEnabled(false);
		// ��������
		m_iRequestJoinLiveSeq = LIVEROOM::RequestJoinLive();

	}
	//��ǰ��ť�ı�Ϊ��ֹͣ����
	else
	{
		ui.m_bRequestJoinLive->setText(QStringLiteral("ֹͣ��..."));
		ui.m_bRequestJoinLive->setEnabled(false);
		//ֹͣ����ʱ��ֹͣ��������Ϊ������
		StopPlaySingleStream();
		StopPublishStream(m_strPublishStreamID);
		StartPlayMixStream(m_anchorStreamInfo);
		m_bIsJoinLive = false;
		SetOperation(false);
		ui.m_bRequestJoinLive->setText(QStringLiteral("��������"));
	}
}

void ZegoMixStreamAudienceDialog::OnClose()
{
	//GetOut();
	this->close();
	//m_lastDialog->show();
}

void ZegoMixStreamAudienceDialog::OnButtonSendMessage()
{
	QString strChat;
	strChat = ui.m_edInput->toPlainText();

	m_strLastSendMsg = strChat;
	m_strLastSendMsg = m_strLastSendMsg.trimmed();

	if (!m_strLastSendMsg.isEmpty())
		LIVEROOM::SendRoomMessage(ROOM::ZegoMessageType::Text, ROOM::ZegoMessageCategory::Chat, ROOM::ZegoMessagePriority::Default, m_strLastSendMsg.toStdString().c_str());

	ui.m_edInput->setText(QStringLiteral(""));

	QString strTmpContent;
	strTmpContent = QString(QStringLiteral("�ң�%1")).arg(m_strLastSendMsg);
	insertStringListModelItem(m_chatModel, strTmpContent, m_chatModel->rowCount());
	//ÿ�η�����Ϣ����ʾ���һ��
	ui.m_listChat->scrollToBottom();
	m_strLastSendMsg.clear();

}

void ZegoMixStreamAudienceDialog::OnButtonSoundCapture()
{
	if (ui.m_bCapture->text() == QStringLiteral("�����ɼ�"))
	{
#ifdef WIN32
		LIVEROOM::EnableMixSystemPlayout(true);
#endif
		ui.m_bCapture->setText(QStringLiteral("ֹͣ�ɼ�"));
	}
	else
	{
#ifdef WIN32
		LIVEROOM::EnableMixSystemPlayout(false);
#endif
		ui.m_bCapture->setText(QStringLiteral("�����ɼ�"));
	}
}

void ZegoMixStreamAudienceDialog::OnButtonMircoPhone()
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

	//ʹ����˷�
	LIVEROOM::EnableMic(m_bCKEnableMic);
}

void ZegoMixStreamAudienceDialog::OnButtonSound()
{


	if (ui.m_bSound->isChecked())
	{

		m_bCKEnableSpeaker = true;
	}
	else
	{

		m_bCKEnableSpeaker = false;
	}

	//ʹ��������
	LIVEROOM::EnableSpeaker(m_bCKEnableSpeaker);

}

void ZegoMixStreamAudienceDialog::OnProgChange()
{
	ui.m_bProgMircoPhone->setProgValue(LIVEROOM::GetCaptureSoundLevel());
	ui.m_bProgMircoPhone->update();
}

void ZegoMixStreamAudienceDialog::OnShareLink()
{

	QString encodeHls = encodeStringAddingEscape(sharedHlsUrl);
	QString encodeRtmp = encodeStringAddingEscape(sharedRtmpUrl);
	QString encodeID = encodeStringAddingEscape(m_pChatRoom->getRoomId());
	QString encodeStreamID = encodeStringAddingEscape(m_anchorStreamInfo->getStreamId());

	QString link("http://www.zego.im/share/index2?video=" + encodeHls + "&rtmp=" + encodeRtmp + "&id=" + encodeID + "&stream=" + encodeStreamID);
	ZegoShareDialog share(link);
	share.exec();

}

void ZegoMixStreamAudienceDialog::OnButtonAux()
{
	if (ui.m_bAux->text() == QStringLiteral("��������"))
	{
		BeginAux();
	}
	else
	{
		EndAux();
	}
}

void ZegoMixStreamAudienceDialog::OnSwitchAudioDevice(int id)
{
	qDebug() << "current audio id = " << id;
	if (id < m_vecAudioDeviceIDs.size())
	{
		LIVEROOM::SetAudioDevice(AV::AudioDevice_Input, m_vecAudioDeviceIDs[id].toStdString().c_str());
		m_pAVSettings->SetMicrophoneId(m_vecAudioDeviceIDs[id]);
		ui.m_cbMircoPhone->setCurrentIndex(id);
		update();
	}
}

void ZegoMixStreamAudienceDialog::OnSwitchVideoDevice(int id)
{
	qDebug() << "current video id = " << id;
	if (id < m_vecVideoDeviceIDs.size())
	{
		LIVEROOM::SetVideoDevice(m_vecVideoDeviceIDs[id].toStdString().c_str());
		m_pAVSettings->SetCameraId(m_vecVideoDeviceIDs[id]);
		ui.m_cbCamera->setCurrentIndex(id);
		update();
	}
}


void ZegoMixStreamAudienceDialog::mousePressEvent(QMouseEvent *event)
{
	mousePosition = event->pos();
	//ֻ�Ա�������Χ�ڵ�����¼����д���

	if (mousePosition.y() <= pos_min_y)
		return;
	if (mousePosition.y() >= pos_max_y)
		return;
	isMousePressed = true;
}

void ZegoMixStreamAudienceDialog::mouseMoveEvent(QMouseEvent *event)
{
	if (isMousePressed == true)
	{
		QPoint movePot = event->globalPos() - mousePosition;
		move(movePot);
	}
}

void ZegoMixStreamAudienceDialog::mouseReleaseEvent(QMouseEvent *event)
{
	isMousePressed = false;
}

void ZegoMixStreamAudienceDialog::mouseDoubleClickEvent(QMouseEvent *event)
{
	//˫��������ͬ�����ԷŴ���С

	mousePosition = event->pos();
	//ֻ�Ա�������Χ�ڵ�����¼����д���

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

void ZegoMixStreamAudienceDialog::closeEvent(QCloseEvent *e)
{
	//OnClose();
	GetOut();
	//this->close();
	emit sigSaveVideoSettings(m_pAVSettings);
	m_lastDialog->show();
}

bool ZegoMixStreamAudienceDialog::eventFilter(QObject *target, QEvent *event)
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

	return QDialog::eventFilter(target, event);
}
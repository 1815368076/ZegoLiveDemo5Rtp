#include "ZegoMoreAnchorDialog.h"
#include "Signal/ZegoSDKSignal.h"
//Objective-C Header
#ifdef Q_OS_MAC
#include "OSX_Objective-C/ZegoAVDevice.h"
#include "OSX_Objective-C/ZegoCGImageToQImage.h"
#endif
ZegoMoreAnchorDialog::ZegoMoreAnchorDialog(QWidget *parent)
	: ZegoBaseDialog(parent)
{
	//ui.setupUi(this);

}

ZegoMoreAnchorDialog::ZegoMoreAnchorDialog(qreal dpi, SettingsPtr curSettings, RoomPtr room, QString curUserID, QString curUserName, QDialog *lastDialog, QDialog *parent)
	:m_strCurUserID(curUserID),
	m_strCurUserName(curUserName),
	ZegoBaseDialog(dpi, curSettings, room, curUserID, curUserName, lastDialog, false, parent)
{
	//ui.setupUi(this);
	//通过sdk的信号连接到本类的槽函数中
	connect(GetAVSignal(), &QZegoAVSignal::sigLoginRoom, this, &ZegoMoreAnchorDialog::OnLoginRoom);
	connect(GetAVSignal(), &QZegoAVSignal::sigStreamUpdated, this, &ZegoMoreAnchorDialog::OnStreamUpdated);
	connect(GetAVSignal(), &QZegoAVSignal::sigPublishStateUpdate, this, &ZegoMoreAnchorDialog::OnPublishStateUpdate);
	connect(GetAVSignal(), &QZegoAVSignal::sigPlayStateUpdate, this, &ZegoMoreAnchorDialog::OnPlayStateUpdate);
	connect(GetAVSignal(), &QZegoAVSignal::sigJoinLiveRequest, this, &ZegoMoreAnchorDialog::OnJoinLiveRequest);

	connect(ui.m_bRequestJoinLive, &QPushButton::clicked, this, &ZegoMoreAnchorDialog::OnButtonSwitchPublish);

}

ZegoMoreAnchorDialog::~ZegoMoreAnchorDialog()
{

}

//功能函数
void ZegoMoreAnchorDialog::initDialog()
{
	//读取标题内容
	QString strTitle = QString(tr("【%1】%2")).arg(tr("连麦模式")).arg(m_pChatRoom->getRoomName());
	ui.m_lbRoomName->setText(strTitle);

	//连麦模式不需要第二个摄像头
	ui.m_lbCamera2->setVisible(false);
	ui.m_cbCamera2->setVisible(false);

	//在主播端，请求连麦的按钮变为直播开关
	ui.m_bRequestJoinLive->setText(tr("停止直播"));

	ZegoBaseDialog::initDialog();
}

void ZegoMoreAnchorDialog::StartPublishStream()
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
		addAVView(nIndex, ZEGODIALOG_MoreAnchor);
		AVViews.last()->setCurUser();
		connect(AVViews.last(), &QZegoAVView::sigSnapShotPreviewOnMoreAnchor, this, &ZegoBaseDialog::OnSnapshotPreview);

		qDebug() << "publish nIndex = " << nIndex << "publish stream id is" << pPublishStream->getStreamId();
		if (m_pAVSettings->GetSurfaceMerge())
		{
#if (defined Q_OS_WIN32) && (defined Q_PROCESSOR_X86_32) && (defined USE_SURFACE_MERGE) 
			SurfaceMergeController::getInstance().setSurfaceSize(m_pAVSettings->GetResolution().cx, m_pAVSettings->GetResolution().cy);
			SurfaceMergeController::getInstance().setSurfaceFps(m_pAVSettings->GetFps());
			SurfaceMergeController::getInstance().setSurfaceCameraId(m_pAVSettings->GetCameraId());
			SurfaceMergeController::getInstance().setRenderView(AVViews.last());
			SurfaceMergeController::getInstance().startSurfaceMerge();
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

void ZegoMoreAnchorDialog::StopPublishStream(const QString& streamID)
{
	if (streamID.size() == 0){ return; }

	
	if (m_pAVSettings->GetSurfaceMerge())
	{
#if (defined Q_OS_WIN32) && (defined Q_PROCESSOR_X86_32) && (defined USE_SURFACE_MERGE) 
		SurfaceMerge::SetRenderView(nullptr);
		SurfaceMerge::UpdateSurface(nullptr, 0);
#endif
	}
	else
	{
		LIVEROOM::SetPreviewView(nullptr);
		LIVEROOM::StopPreview();
	}

	qDebug() << "stop publish view index = " << m_anchorStreamInfo->getPlayView();
	removeAVView(m_anchorStreamInfo->getPlayView());
	LIVEROOM::StopPublishing();
	m_bIsPublishing = false;
	StreamPtr pStream = m_pChatRoom->removeStream(streamID);
	FreeAVView(pStream);
	m_strPublishStreamID = "";

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
		addAVView(nIndex, ZEGODIALOG_MoreAnchor);
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

void ZegoMoreAnchorDialog::GetOut()
{
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

	ZegoBaseDialog::GetOut();
}

//SDK回调
void ZegoMoreAnchorDialog::OnLoginRoom(int errorCode, const QString& strRoomID, QVector<StreamPtr> vStreamList)
{
	qDebug() << "Login Room!";
	if (errorCode != 0)
	{
		QMessageBox::information(NULL, tr("提示"), tr("登陆房间失败,错误码: %1").arg(errorCode));
        OnClose();
		return;
	}

	//加入房间列表
	roomMemberAdd(m_strCurUserName);

    StartPublishStream();
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
			jsonString = jsonString.simplified();
			//设置流附加消息，将混流信息传入
			LIVEROOM::SetPublishStreamExtraInfo(jsonString.toStdString().c_str());
		}
		
		SetOperation(true);
		ui.m_bRequestJoinLive->setText(tr("停止直播"));
		ui.m_bRequestJoinLive->setEnabled(true);

		//推流成功后启动计时器监听麦克风音量
		timer->start(200);

	}
	else
	{
		QMessageBox::warning(NULL, tr("推流失败"), tr("错误码: %1").arg(stateCode));
		ui.m_bRequestJoinLive->setText(tr("开始直播"));
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

void ZegoMoreAnchorDialog::OnJoinLiveRequest(int seq, const QString& fromUserId, const QString& fromUserName, const QString& roomId)
{
	QMessageBox box(QMessageBox::Warning, tr("提示"), QString(tr("%1正在请求连麦")).arg(fromUserId));
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

//UI回调
void ZegoMoreAnchorDialog::OnButtonSwitchPublish()
{
	//当前按钮文本为“开始直播”
	if (ui.m_bRequestJoinLive->text() == tr("开始直播"))
	{
		ui.m_bRequestJoinLive->setText(tr("开启中..."));
		ui.m_bRequestJoinLive->setEnabled(false);
		//开始推流
		StartPublishStream();

	}
	//当前按钮文本为“停止直播”
	else
	{
		ui.m_bRequestJoinLive->setText(tr("停止中..."));
		ui.m_bRequestJoinLive->setEnabled(false);
		StopPublishStream(m_strPublishStreamID);

		if (timer->isActive())
			timer->stop();
		ui.m_bProgMircoPhone->setMyEnabled(false);
		ui.m_bProgMircoPhone->update();

		if (ui.m_bAux->text() == tr("关闭混音"))
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
			ui.m_bAux->setText(tr("开启混音"));
		}

		//停止直播后不能混音、声音采集、分享
		ui.m_bAux->setEnabled(false);
		ui.m_bCapture->setEnabled(false);
		ui.m_bShare->setEnabled(false);
		ui.m_bProgMircoPhone->setEnabled(false);
		ui.m_bRequestJoinLive->setEnabled(true);
		ui.m_bRequestJoinLive->setText(tr("开始直播"));
	}
}


﻿#include "ZegoSingleAudienceDialog.h"
#include "Signal/ZegoSDKSignal.h"
//Objective-C Header
#ifdef Q_OS_MAC
#include "OSX_Objective-C/ZegoAVDevice.h"
#include "OSX_Objective-C/ZegoCGImageToQImage.h"
#endif
ZegoSingleAudienceDialog::ZegoSingleAudienceDialog(QWidget *parent)
	: ZegoBaseDialog(parent)
{

}

ZegoSingleAudienceDialog::ZegoSingleAudienceDialog(qreal dpi, SettingsPtr curSettings, RoomPtr room, QString curUserID, QString curUserName, QDialog *lastDialog, QDialog *parent)
	:
	m_strCurUserID(curUserID),
	m_strCurUserName(curUserName),
	ZegoBaseDialog(dpi, curSettings, room, curUserID, curUserName, lastDialog, false, parent)
{
	//通过sdk的信号连接到本类的槽函数中
	connect(GetAVSignal(), &QZegoAVSignal::sigLoginRoom, this, &ZegoSingleAudienceDialog::OnLoginRoom);
	connect(GetAVSignal(), &QZegoAVSignal::sigStreamUpdated, this, &ZegoSingleAudienceDialog::OnStreamUpdated);
	connect(GetAVSignal(), &QZegoAVSignal::sigPlayStateUpdate, this, &ZegoSingleAudienceDialog::OnPlayStateUpdate);
	
}

ZegoSingleAudienceDialog::~ZegoSingleAudienceDialog()
{

}

//功能函数
void ZegoSingleAudienceDialog::initDialog()
{
	//读取标题内容
	QString strTitle = QString(tr("【%1】%2")).arg(tr("单主播模式")).arg(m_pChatRoom->getRoomName());
	ui.m_lbRoomName->setText(strTitle);

	ui.m_bRequestJoinLive->setVisible(false);
	ui.m_lbCamera2->setVisible(false);
	ui.m_cbCamera2->setVisible(false);

	ZegoBaseDialog::initDialog();
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
		addAVView(nIndex, ZEGODIALOG_SingleAudience);
		connect(AVViews.last(), &QZegoAVView::sigSnapShotOnSingleAudienceWithStreamID, this, &ZegoBaseDialog::OnSnapshotWithStreamID);
		AVViews.last()->setViewStreamID(stream->getStreamId());

		m_anchorStreamInfo = stream;
		//配置View
		LIVEROOM::SetViewMode(LIVEROOM::ZegoVideoViewModeScaleAspectFit, stream->getStreamId().toStdString().c_str());
		LIVEROOM::StartPlayingStream(stream->getStreamId().toStdString().c_str(), (void *)AVViews[nIndex]->winId());
	}
}

void ZegoSingleAudienceDialog::StopPlayStream(const QString& streamID)
{
	if (streamID.size() == 0) { return; }

	removeAVView(m_anchorStreamInfo->getPlayView());
	LIVEROOM::StopPlayingStream(streamID.toStdString().c_str());

	StreamPtr pStream = m_pChatRoom->removeStream(streamID);
	FreeAVView(pStream);

	//m_mainLiveView->setViewStreamID("");
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

//SDK回调
void ZegoSingleAudienceDialog::OnLoginRoom(int errorCode, const QString& strRoomID, QVector<StreamPtr> vStreamList)
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
		removeAVView(m_anchorStreamInfo->getPlayView());
		StreamPtr pStream = m_pChatRoom->removeStream(streamId);
		FreeAVView(pStream);
	}
}


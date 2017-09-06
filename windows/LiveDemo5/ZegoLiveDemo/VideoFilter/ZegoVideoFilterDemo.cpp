#include "ZegoVideoFilterDemo.h"
#include <QDebug>

VideoFilterGlue::VideoFilterGlue()
{

}

VideoFilterGlue::~VideoFilterGlue()
{

}

void VideoFilterGlue::AllocateAndStart(Client* client) {
	client_ = client;
	qDebug() << "vf alloced!";
	/*m_oPendingCount = 0;
	m_nWritePtr = 0;
	m_nReadPtr = 0;
	m_bExit = FALSE;

	LPDWORD tid = 0;
	m_hVideoTimer = CreateThread(0, 0, &VideoFilterGlue::thread_proc, this, 0, tid);
	*/
}

void VideoFilterGlue::StopAndDeAllocate() {
	qDebug() << "vf dealloced!";
	/*m_bExit = TRUE;
	if (m_hVideoTimer) {
		WaitForSingleObject(m_hVideoTimer, INFINITE);
		CloseHandle(m_hVideoTimer);
		m_hVideoTimer = NULL;
	}
	*/
	client_->Destroy();
	client_ = NULL;
}

int VideoFilterGlue::DequeueInputBuffer(int width, int height, int stride) {
	qDebug() << "dequeueInput";

	/*if (m_oPendingCount >= MAX_FRAME) {
		return -1;
	}*/
	return m_nWritePtr;
}

void* VideoFilterGlue::GetInputBuffer(int index) {
	qDebug() << "getInput";

	//return m_aBuffers[m_nWritePtr].frame;
	return NULL;
}

void VideoFilterGlue::QueueInputBuffer(int index, int width, int height, int stride, unsigned long long timestamp_100n) {
	qDebug() << "queueInput";

	if (m_nWritePtr != index) {
		return;
	}

	/*m_aBuffers[index].width = width;
	m_aBuffers[index].height = height;
	m_aBuffers[index].timestamp_100n = timestamp_100n;

	m_nWritePtr = (m_nWritePtr + 1) % MAX_FRAME;
	InterlockedIncrement(&m_oPendingCount);
	*/
}

void VideoFilterGlue::OnVideoTimer() {
	/*while (!m_bExit) {
		while (m_oPendingCount > 0) {
			VideoBufferPool* pool = (VideoBufferPool*)client_->GetInterface();

			int index = pool->DequeueInputBuffer(m_aBuffers[m_nReadPtr].width, m_aBuffers[m_nReadPtr].height, m_aBuffers[m_nReadPtr].width * 4);

			if (index >= 0) {
				unsigned char* src = m_aBuffers[m_nReadPtr].frame;
				unsigned char* dst = (unsigned char*)pool->GetInputBuffer(index);

				for (int i = 0; i < m_aBuffers[m_nReadPtr].height; i++) {
					for (int j = 0; j < m_aBuffers[m_nReadPtr].width; j++, src += 4, dst += 4) {
						int grey = (*src * 38 + *(src + 1) * 75 + *(src + 2) * 15) >> 7;
						*dst = grey;
						*(dst + 1) = grey;
						*(dst + 2) = grey;
					}
				}

				pool->QueueInputBuffer(index, m_aBuffers[m_nReadPtr].width, m_aBuffers[m_nReadPtr].height, m_aBuffers[m_nReadPtr].width * 4, m_aBuffers[m_nReadPtr].timestamp_100n);

				m_nReadPtr = (m_nReadPtr + 1) % MAX_FRAME;
				InterlockedDecrement(&m_oPendingCount);
			}
			else {
				break;
			}
		}

		Sleep(m_nVideoTickPeriod);
	}
	*/
	return;
}
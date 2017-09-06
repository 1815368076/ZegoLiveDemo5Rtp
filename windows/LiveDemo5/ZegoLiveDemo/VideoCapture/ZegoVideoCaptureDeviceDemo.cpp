#include "ZegoVideoCaptureDeviceDemo.h"
#include <QDebug>

VideoCaptureDeviceGlue::VideoCaptureDeviceGlue()
{

}

VideoCaptureDeviceGlue::~VideoCaptureDeviceGlue()
{

}

void VideoCaptureDeviceGlue::AllocateAndStart(Client* client) {
	client_ = client;
	callback_ = (VideoCaptureCallback*)client->GetInterface();

	m_bExit = false;
	qDebug() << "vc alloced!";
	//LPDWORD tid = 0;
	//m_hVideoTimer = CreateThread(0, 0, &VideoCaptureDeviceGlue::thread_proc, this, 0, tid);
}

void VideoCaptureDeviceGlue::StopAndDeAllocate() {
	m_bExit = true;
	/*if (m_hVideoTimer) {
		WaitForSingleObject(m_hVideoTimer, INFINITE);
		CloseHandle(m_hVideoTimer);
		m_hVideoTimer = NULL;
	}
	*/
	qDebug() << "vc dealloced!";
	client_->Destroy();
	client_ = NULL;
}

int VideoCaptureDeviceGlue::StartCapture() {
	m_bCapture = true;
	qDebug() << "Start Capture!";
	return 0;
}

int VideoCaptureDeviceGlue::StopCapture() {
	m_bCapture = false;
	return 0;
}

void VideoCaptureDeviceGlue::OnVideoTimer() {
	while (!m_bExit) {
		if (m_bCapture) {
			/*int width, height;
			EnterCriticalSection(&cs_);
			width = new_width_;
			height = new_height_;
			LeaveCriticalSection(&cs_);

			if (width != width_ || height != height_) {
				if (data_) {
					free(data_);
					data_ = NULL;
				}
#if TEST_BGRA
				data_size_ = width * height * 4;
				data_ = (char*)malloc(data_size_);
				memset(data_, 0xFF, data_size_);
#else
				data_size_ = width * height * 3 / 2;
				data_ = (char*)malloc(data_size_);
				memset(data_, 0x46, width * height);
				memset(data_ + (width * height), 0xA2, width * height / 4);
				memset(data_ + (width * height * 5 / 4), 0xB1, width * height / 4);
#endif
				width_ = width;
				height_ = height;
			}

			AVE::VideoCaptureFormat format;
			format.width = width;
			format.height = height;
#if TEST_BGRA
			format.strides[0] = width * 4;
			format.pixel_format = AVE::PIXEL_FORMAT_BGRA32;
#else
			format.strides[0] = width;
			format.strides[1] = width / 2;
			format.strides[2] = width / 2;
			format.strides[3] = 0;
			format.pixel_format = AVE::PIXEL_FORMAT_I420;
#endif

			callback_->OnIncomingCapturedData(data_, data_size_, format, GetTickCount(), 1000);
			*/
		}

		//Sleep(m_nVideoTickPeriod);
	}

	return;
}
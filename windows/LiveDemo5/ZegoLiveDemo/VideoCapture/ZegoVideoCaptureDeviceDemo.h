#include "video_capture.h"
#include "stdlib.h"
#include "string.h"
#include <QTimer>

using namespace AVE;

class VideoCaptureDeviceGlue : public AVE::VideoCaptureDeviceBase {
public:
	VideoCaptureDeviceGlue();
	virtual ~VideoCaptureDeviceGlue();

	virtual void AllocateAndStart(Client* client) override;
	virtual void StopAndDeAllocate() override;
	virtual int StartCapture() override;
	virtual int StopCapture() override;

	virtual VideoPixelBufferType SupportBufferType() override {
		return VideoPixelBufferType::PIXEL_BUFFER_TYPE_MEM;
	}

	virtual void* GetInterface() override {
		return NULL;
	}

	void OnVideoTimer();

	Client *client_;
	VideoCaptureCallback *callback_;

private:
	bool m_bExit;
	bool m_bCapture;
	size_t data_size_;
	char* data_;
	int width_;
	int height_;
	QTimer *timer;
};
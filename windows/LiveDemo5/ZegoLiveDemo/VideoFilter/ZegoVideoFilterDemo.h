#include "video_capture.h"
#include "stdlib.h"

class VideoFilterGlue : public AVE::VideoFilter, public AVE::VideoBufferPool {
public:
	VideoFilterGlue();
	virtual ~VideoFilterGlue();
	virtual void AllocateAndStart(Client* client) override;
	virtual void StopAndDeAllocate() override;
	virtual int DequeueInputBuffer(int width, int height, int stride) override;
	virtual void* GetInputBuffer(int index) override;
	virtual void QueueInputBuffer(int index, int width, int height, int stride, unsigned long long timestamp_100n) override;

	AVE::VideoBufferType SupportBufferType() {
		return AVE::BUFFER_TYPE_MEM;
	}

	void* GetInterface() {
		return (AVE::VideoBufferPool*)this;
	}

	void OnVideoTimer();

	Client *client_;
	int m_nWritePtr;
};
//
//  ZegoAudioCapture.h
//  ZegoLiveRoom
//
//  Created by Strong on 2017/3/16.
//  Copyright © 2017年 zego. All rights reserved.
//

#ifndef ZegoAudioCapture_h
#define ZegoAudioCapture_h

#ifndef ZEGOAudioInOutput_h
#define ZEGOAudioInOutput_h

namespace AVE
{
    struct AudioFrame
    {
        int frameType;              //pcm:0x1001, only support pcm format
        int samples;                //number of samples in this frame
        int bytesPerSample;         //number of bytes per sample, only support 2 bytes per sample
        int channels;               //number of channels
        int sampleRate;             //sample rate
        void *buffer;               //data buffer, the caller is responsible for the allocate and release
    };
    
    class IAudioDataInOutput
    {
    public:
        virtual void startCapture() = 0;
        virtual void stopCapture() = 0;
        virtual void startRender() = 0;
        virtual void stopRender() = 0;
        virtual bool onRecordAudioFrame(AudioFrame& audioFrame) = 0;
        virtual bool onPlaybackAudioFrame(AudioFrame& audioFrame) = 0;
    };
}

#endif

#endif /* ZegoAudioCapture_h */

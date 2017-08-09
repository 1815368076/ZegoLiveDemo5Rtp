//
//  LiveRoomDefines-Publisher.h
//  zegoliveroom
//
//  Created by Randy Qiu on 2017/1/23.
//
//

#ifndef LiveRoomDefines_Publisher_h
#define LiveRoomDefines_Publisher_h

#include "./LiveRoomDefines.h"

namespace ZEGO
{
    namespace LIVEROOM
    {
        /** 发布直播的模式 */
        enum ZegoPublishFlag
        {
            ZEGO_JOIN_PUBLISH   = 0,        /**< 连麦模式 */
            ZEGO_MIX_STREAM     = 1 << 1,   /**< 混流模式 */
            ZEGO_SINGLE_ANCHOR  = 1 << 2,   /**< 单主播模式 */
        };
        
        struct ZegoPublishingStreamInfo
        {
            ZegoPublishingStreamInfo()
            {
                uiRtmpURLCount = 0;
                uiHlsURLCount = 0;
                uiFlvURLCount = 0;
            }
            const char* arrRtmpURLs[ZEGO_MAX_URL_COUNT];   /**< RTMP 播放 URL 列表 */
            unsigned int uiRtmpURLCount;                   /**< RTMP URL 个数 */
            
            const char* arrFlvURLs[ZEGO_MAX_URL_COUNT];
            unsigned int uiFlvURLCount;
            
            const char* arrHlsURLs[ZEGO_MAX_URL_COUNT];
            unsigned int uiHlsURLCount;
        };
        
    }

#ifndef ZegoAVDefines_h
    namespace AV
    {
        /** 音频设备模式 */
        enum ZegoAVAPIAudioDeviceMode
        {
            ZEGO_AUDIO_DEVICE_MODE_COMMUNICATION = 1,    /**< 开启硬件回声消除 */
            ZEGO_AUDIO_DEVICE_MODE_GENERAL = 2,          /**< 关闭硬件回声消除 */
            ZEGO_AUDIO_DEVICE_MODE_AUTO = 3              /**< 根据场景自动选择是否开启硬件回声消除 */
        };
        
        /** 延迟模式 */
        enum ZegoAVAPILatencyMode
        {
            ZEGO_LATENCY_MODE_NORMAL = 0,               /**< 普通延迟模式 */
            ZEGO_LATENCY_MODE_LOW,                      /**< 低延迟模式，无法用于 RTMP 流 */
            ZEGO_LATENCY_MODE_NORMAL2,                  /**< 普通延迟模式，最高码率可达192K */
        };
        
        /** 流量控制属性 */
        enum ZegoTrafficControlProperty
        {
            ZEGO_TRAFFIC_NONE = 0,                      /**< 无 */
            ZEGO_TRAFFIC_FPS = 1,                       /**< 帧率 */
            ZEGO_TRAFFIC_RESOLUTION = 1 << 1,           /**< 分辨率 */
        };
        
        struct ZegoStreamInfo
        {
            ZegoStreamInfo()
            {
                uiRtmpURLCount = 0;
                uiHlsURLCount = 0;
                uiFlvURLCount = 0;
                szStreamID[0] = '\0';
                szMixStreamID[0] = '\0';
            }
            
            char szStreamID[ZEGO_MAX_COMMON_LEN];       /**< 流 ID */
            char szMixStreamID[ZEGO_MAX_COMMON_LEN];    /**< 混流 ID */
            
            char* arrRtmpURLs[ZEGO_MAX_URL_COUNT];      /**< RTMP 播放 URL 列表 */
            unsigned int uiRtmpURLCount;                /**< RTMP URL 个数 */
            
            char* arrFlvRULs[ZEGO_MAX_URL_COUNT];
            unsigned int uiFlvURLCount;
            
            char* arrHlsURLs[ZEGO_MAX_URL_COUNT];
            unsigned int uiHlsURLCount;
        };
        
        /** 流量控制属性 */
        struct ZegoMixStreamConfig
        {
            char szStreamID[ZEGO_MAX_COMMON_LEN];       /**< 混流 ID */
            struct
            {
                int top;
                int left;
                int bottom;
                int right;
            } layout;
            
            /**
             *  原点在左上角，top/bottom/left/right 定义如下：
             *
             *  (left, top)-----------------------
             *  |                                |
             *  |                                |
             *  |                                |
             *  |                                |
             *  -------------------(right, bottom)
             */
        };
        
        
        /** 完整混流配置 */
        struct ZegoCompleteMixStreamConfig
        {
            char szOutputStream[ZEGO_MAX_COMMON_LEN];   /**< 输出流名或 URL，参见 bOutputIsUrl */
            bool bOutputIsUrl;                          /**< true: szOutputStream 为完整 RTMP URL，false: szOutputStream 为流名 */
            
            int nOutputFps;                             /**< 混流输出帧率 */
            int nOutputBitrate;                         /**< 混流输出码率 */
            
            int nOutputWidth;                           /**< 混流输出视频分辨率宽 */
            int nOutputHeight;                          /**< 混流输出视频分辨率高 */
            
            int nOutputAudioConfig;                     /**< 混流输出音频格式 */
            
            ZegoMixStreamConfig* pInputStreamList;      /**< 混流输入流列表 */
            int nInputStreamCount;                      /**< 混流输入流列表个数 */
            
            ZegoCompleteMixStreamConfig ()
            : bOutputIsUrl(false)
            , nOutputFps(0)
            , nOutputBitrate(0)
            , nOutputWidth(0)
            , nOutputHeight(0)
            , nOutputAudioConfig(0)
            , pInputStreamList(0)
            , nInputStreamCount(0)
            {
                szOutputStream[0] = '\0';
            }
        };
        
        /** 混流失败消息信息 */
        struct ZegoMixStreamResult
        {
            unsigned int uiErrorCode;   /**< 错误码，0 表示成功，此时 oStreamInfo 有效。150 表示输入流不存在，参考 nNonExistsStreamCount 和 ppNonExistsStreamIDList */
            
            int nNonExistsStreamCount;                                      /**< 不存在的输入流个数 */
            const char* ppNonExistsStreamIDList[ZEGO_MAX_MIX_INPUT_COUNT];  /**< 不存在的输入流 ID 列表 */
            
            ZegoStreamInfo oStreamInfo;
            
            ZegoMixStreamResult()
            : uiErrorCode(0)
            , nNonExistsStreamCount(0)
            {}
        };
    }
#endif
}
#endif /* LiveRoomDefines_Publisher_h */

//
//  ZegoLiveRoomDefines.h
//  zegoliveroom
//
//  Copyright © 2017年 ZEGO. All rights reserved.
//

#ifndef ZegoLiveRoomDefines_h
#define ZegoLiveRoomDefines_h

#include "./AVDefines.h"
#include "./RoomDefines.h"


namespace ZEGO
{
    namespace LIVEROOM
    {
        using namespace COMMON;
        using COMMON::ZEGONetType;
        
        using COMMON::ZegoRoomRole;
        
        /** 登录房间报错 */
        enum ZegoRoomError
        {
            LoginNetworkError   = 101,  /**< HTTP 连接错误 */
            LoginPushError      = 102,  /**< TCP 连接错误 */
            LoginServerError    = 103,  /**< 服务器错误 */
            LoginNetChangeError = 104,  /**< 网络切换临时状态，网络恢复后会自动重连 */
        };
        
        using COMMON::ZegoStreamInfo;
        
        using COMMON::ZegoStreamUpdateType;
        
        using COMMON::LiveRoomState;
        
        const int kInvalidSeq = -1;
        
        /** 本地预览视频视图的模式 */
        enum ZegoVideoViewMode
        {
            ZegoVideoViewModeScaleAspectFit = 0,    /**< 等比缩放，可能有黑边 */
            ZegoVideoViewModeScaleAspectFill = 1,   /**< 等比缩放填充整View，可能有部分被裁减 */
            ZegoVideoViewModeScaleToFill = 2,       /**< 填充整个View */
        };
        
        struct ZegoPublishQuality
        {
            double fps;             ///< 视频帧率
            double kbps;            ///< 视频码率(kb/s)
            double akbps;           ///< 音频码率(kb/s)
            int rtt;                ///< 延时(ms)
            int pktLostRate;        ///< 丢包率(0~255)
            
            int quality;            ///< 质量(0~3)
        };
        
        typedef ZegoPublishQuality ZegoPlayQuality;
    }
}

#endif /* ZegoLiveRoomDefines_h */

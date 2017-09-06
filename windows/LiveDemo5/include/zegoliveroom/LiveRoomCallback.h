//
//  ZegoLiveRoomCallback.h
//  ZegoRoom
//
//  Copyright © 2017年 ZEGO. All rights reserved.
//

#ifndef ZegoLiveRoomCallback_h
#define ZegoLiveRoomCallback_h

#include "./LiveRoomDefines.h"

namespace ZEGO
{
    namespace LIVEROOM
    {
        class IRoomCallback
        {
        public:
            /**
             登录房间成功回调

             @param errorCode 错误码，0 表示无错误
             @param pszRoomID 房间 ID
             @param pStreamInfo 直播流列表
             @param streamCount 直播流个数
             */
            virtual void OnLoginRoom(int errorCode, const char *pszRoomID, const ZegoStreamInfo *pStreamInfo, unsigned int streamCount) = 0;

            /**
             退出房间回调

             @param errorCode 错误码，0 表示无错误
             @param pszRoomID 房间 ID
             */
            virtual void OnLogoutRoom(int errorCode, const char *pszRoomID) {}
            
            /**
             因为使用同一个 UserId 登录，用户被挤出聊天室

             @param reason 原因
             @param pszRoomID 房间 ID
             @attention 可在该回调中处理用户被踢出房间后的下一步处理（例如报错、重新登录提示等）
             */
            virtual void OnKickOut(int reason, const char *pszRoomID) = 0;
            
            /**
             与 server 断开通知

             @param errorCode 错误码，0 表示无错误
             @param roomID 房间 ID
             @attention 建议开发者在此通知中进行重新登录、推/拉流、报错、友好性提示等其他恢复逻辑
             @note 与 server 断开连接后，SDK 会进行重试，重试失败抛出此错误。请注意，此时 SDK 与服务器的所有连接均会断开
             */
            virtual void OnDisconnect(int errorCode, const char *pszRoomID) = 0;
        
            /**
             流信息更新

             @param type 更新类型
             @param pStreamInfo 直播流列表
             @param streamCount 直播流个数
             @param pszRoomID 房间 ID
             @attention 房间内增加流、删除流，均会触发此更新
             @note 建议对流增加和流删除分别采取不同的处理
             */
            virtual void OnStreamUpdated(ZegoStreamUpdateType type, ZegoStreamInfo *pStreamInfo, unsigned int streamCount, const char *pszRoomID) = 0;
            
            /**
             流附加信息更新

             @param pStreamInfo 附加信息更新的流列表
             @param streamCount 流个数
             @param pszRoomID 房间 ID
             */
            virtual void OnStreamExtraInfoUpdated(ZegoStreamInfo *pStreamInfo, unsigned int streamCount, const char *pszRoomID) = 0;
            
            /**
             发送自定义信令结果

             @param errorCode 错误码，0 表示无错误
             @param requestSeq 请求 seq
             @param pszRoomID 房间 ID
             */
            virtual void OnCustomCommand(int errorCode, int requestSeq, const char *pszRoomID) = 0;

            /**
             收到自定义信令

             @param pszUserId 发送者 UserId
             @param pszUserName 发送者 UserName
             @param pszContent 收到的信令内容
             @param pszRoomID 房间 ID
             */
            virtual void OnRecvCustomCommand(const char *pszUserId, const char *pszUserName, const char *pszContent, const char *pszRoomID) = 0;
            
            virtual ~IRoomCallback() {}
        };
        
        class IAVEngineCallback
        {
        public:
            /**
             音视频引擎停止时回调
             */
            virtual void OnAVEngineStop() = 0;
            
            virtual ~IAVEngineCallback(){}
        };
    }

}

#endif /* ZegoLiveRoomCallback_h */

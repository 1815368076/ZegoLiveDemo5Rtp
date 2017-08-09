//
//  LiveRoomDefines-IM.h
//  zegoliveroom
//
//  Copyright © 2017年 Zego. All rights reserved.
//
//

#ifndef LiveRoomDefines_IM_h
#define LiveRoomDefines_IM_h

#include "./LiveRoomDefines.h"

namespace ZEGO
{
    namespace LIVEROOM
    {
        /** 用户更新类型 */
        enum ZegoUserUpdateType
        {
            UPDATE_TOTAL = 1,   /**< 全量更新 */
            UPDATE_INCREASE,    /**< 增量更新 */
        };
        
        /** 用户更新属性 */
        enum ZegoUserUpdateFlag
        {
            USER_ADDED = 1,     /**< 新增 */
            USER_DELETED,       /**< 删除 */
        };
        
        struct ZegoUserInfo
        {
            ZegoUserInfo()
            {
                szUserId[0] = '\0';
                szUserName[0] = '\0';
            }
            
            char szUserId[ZEGO_MAX_COMMON_LEN];
            char szUserName[ZEGO_MAX_COMMON_LEN];
            ZegoUserUpdateFlag udapteFlag;
            ZegoRoomRole role;
        };
        
    }
    
#ifndef ZegoRoomDefines_h
    namespace ROOM
    {
        struct ZegoUser
        {
            ZegoUser()
            {
                szUserId[0] = '\0';
                szUserName[0] = '\0';
            }
            
            char szUserId[ZEGO_MAX_COMMON_LEN];
            char szUserName[ZEGO_MAX_COMMON_LEN];
        };
        
        /** 消息类型 */
        enum ZegoMessageType
        {
            Text = 1,           /**< 文字 */
            Picture,            /**< 图片 */
            File,               /**< 文件 */
            OtherType = 100,    /**< 其他 */
        };
        
        /** 消息优先级 */
        enum ZegoMessagePriority
        {
            Default = 2,        /**< 默认优先级 */
            High = 3,           /**< 高优先级 */
        };
        
        /** 消息类别 */
        enum ZegoMessageCategory
        {
            Chat = 1,           /**< 聊天 */
            System,             /**< 系统 */
            Like,               /**< 点赞 */
            Gift,               /**< 送礼物 */
            OtherCategory = 100,/**< 其他 */
        };
        
        struct ZegoRoomMessage
        {
            ZegoRoomMessage()
            {
                szUserId[0] = '\0';
                szUserName[0] = '\0';
                szContent[0] = '\0';
                type = Text;
                priority = Default;
                category = Chat;
            }
            
            char szUserId[ZEGO_MAX_COMMON_LEN];
            char szUserName[ZEGO_MAX_COMMON_LEN];
            char szContent[ZEGO_MAX_COMMON_LEN];
            unsigned long long messageId;
            ZegoMessageType type;
            ZegoMessagePriority priority;
            ZegoMessageCategory category;
        };
        
        struct ZegoConversationMessage
        {
            ZegoConversationMessage()
            {
                szUserId[0] = '\0';
                szUserName[0] = '\0';
                szContent[0] = '\0';
                type = Text;
                sendTime = 0;
            }
            
            char szUserId[ZEGO_MAX_COMMON_LEN];
            char szUserName[ZEGO_MAX_COMMON_LEN];
            char szContent[ZEGO_MAX_COMMON_LEN];
            unsigned long long messageId;
            ZegoMessageType type;
            int sendTime;
        };
        
        struct ZegoConverInfo
        {
            char szConverName[ZEGO_MAX_COMMON_LEN];
            char szCreatorId[ZEGO_MAX_COMMON_LEN];
            int createTime;
        };
    }
#endif
}

#endif /* LiveRoomDefines_IM_h */

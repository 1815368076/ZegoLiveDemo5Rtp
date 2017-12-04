//
//  IncludeZegoLiveRoomApi.h
//  ZegoLiveDemo
//
//  Created by Randy Qiu on 2017/11/22.
//

#ifndef IncludeZegoLiveRoomApi_h
#define IncludeZegoLiveRoomApi_h



#if defined(Q_OS_WIN)

#include "LiveRoom.h"
#include "LiveRoom-IM.h"
#include "LiveRoom-Player.h"
#include "LiveRoom-Publisher.h"

#define USE_SURFACE_MERGE
#if defined(USE_SURFACE_MERGE)
#include "ZegoSurfaceMerge.h"
#endif

#elif defined(Q_OS_MAC)

#include "LiveRoom.h"
#include "LiveRoom-IM.h"
#include "LiveRoom-Player.h"
#include "LiveRoom-Publisher.h"

#else
static_assert(false, "Unkown Platform");
#endif


#endif /* IncludeZegoLiveRoomApi_h */

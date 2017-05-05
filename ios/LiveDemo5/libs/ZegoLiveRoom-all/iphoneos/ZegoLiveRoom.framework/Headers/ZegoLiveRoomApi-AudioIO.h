//
//  ZegoLiveRoomApi-AudioIO.h
//  ZegoLiveRoom
//
//  Created by Strong on 2017/3/16.
//  Copyright © 2017年 zego. All rights reserved.
//

#ifndef ZegoLiveRoomApi_AudioIO_h
#define ZegoLiveRoomApi_AudioIO_h

#import "ZegoLiveRoomApi.h"
#import "ZegoAudioCapture.h"

@interface ZegoLiveRoomApi (AudioIO)

+ (void)enableExternalAudioDevice:(bool)enable;
- (AVE::IAudioDataInOutput *)getIAudioDataInOutput;

@end

#endif /* ZegoLiveRoomApi_AudioIO_h */

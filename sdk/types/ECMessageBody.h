//
//  ECMessageBody.h
//  CCPiPhoneSDK
//
//  Created by ronglian on 14/11/17.
//  Copyright (c) 2014年 ronglian. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * 离线消息类型
 */
typedef NS_ENUM(NSInteger, ECOfflinePush) {
    
    /** 离线推送 */
    ECOfflinePush_On = 1,
    
    /** 不走离线推送 */
    ECOfflinePush_Off = 2,
    
    /** 不走离线推送，且用户不在线返回错误码570113 */
    ECOfflinePush_OffReturn = 3
};

/**
 * 消息体类型枚举
 */
typedef NS_ENUM(NSInteger, MessageBodyType) {
    
    /** 默认 */
    MessageBodyType_None=0,
    
    /** 文本消息 */
    MessageBodyType_Text=1,
    
    /** 多媒体消息 */
    
    /** 语音 */
    MessageBodyType_Voice=2,
    
    /** 视频 */
    MessageBodyType_Video=3,
    
    /** 图片 */
    MessageBodyType_Image=4,
    
    /** 位置 */
    MessageBodyType_Location=5,
    
    /** 文件 */
    MessageBodyType_File=6,
    
    /** 未收到的离线呼叫(只能收到该消息，不能发送) */
    MessageBodyType_Call=7,
    
    /** 预览消息 */
    MessageBodyType_Preview=8,
    
    /**艾特  历史消息*/
    MessageBodyType_At = 11,
    
    /** 用户状态消息 */
    MessageBodyType_UserState=12,
    
    /** 用户自定义命令消息 */
    MessageBodyType_Command=26
};

/**
 * 消息体基类
 */
@interface ECMessageBody : NSObject

/**
 @brief 消息体的类型
 */
@property (nonatomic,readonly) MessageBodyType messageBodyType;

@end

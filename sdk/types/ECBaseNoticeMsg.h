//
//  ECBaseNoticeMsg.h
//  CCPiPhoneSDK
//
//  Created by huangjue on 2017/9/1.
//  Copyright © 2017年 ronglian. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, ECBaseNoticeMsg_Type) {
    ECBaseNoticeMsg_Type_None,
    
    ECBaseNoticeMsg_Type_Group,
    
    ECBaseNoticeMsg_Type_Friend,
    
};

@interface ECBaseNoticeMsg : NSObject

@property (nonatomic, readonly) ECBaseNoticeMsg_Type baseType;

/**
 @brief 通知消息的时间
 */
@property (nonatomic, copy) NSString *dateCreated;

/**
 @brief 是否已读
 */
@property (nonatomic, assign) BOOL isRead;

@end

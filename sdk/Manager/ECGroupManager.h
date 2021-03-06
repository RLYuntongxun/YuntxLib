//
//  ECGroupManager.h
//  CCPiPhoneSDK
//
//  Created by ronglian on 14/11/6.
//  Copyright (c) 2014年 ronglian. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "ECManagerBase.h"
#import "ECGroup.h"
#import "ECGroupMatch.h"
#import "ECGroupMember.h"
#import "ECEnumDefs.h"
#import "ECGroupOption.h"

/**
 * 群组管理类
 * 包含有关群组操作函数
 */
@protocol ECGroupManager <ECManagerBase>


/**
 @brief 创建群组
 @param group 创建的群组信息 只需关注group中name、declared、type、mode
 @param completion 执行结果回调block
 */
-(void)createGroup:(ECGroup *)group completion:(void(^)(ECError *error ,ECGroup *group))completion;


/**
 @brief 修改群组
 @param group 修改的群组信息
 @param completion 执行结果回调block
 */
-(void)modifyGroup:(ECGroup *)group completion:(void(^)(ECError *error ,ECGroup *group))completion;


/**
 @brief 删除群组
 @param groupId 删除的群组id
 @param completion 执行结果回调block
 */
-(void)deleteGroup:(NSString*)groupId completion:(void(^)(ECError *error, NSString* groupId))completion;


/**
 @brief 按条件搜索公共群组
 @param match 需要匹配的条件
 @param completion 执行结果回调block
 */
-(void)searchPublicGroups:(ECGroupMatch *)match completion:(void(^)(ECError *error, NSArray* groups))completion;


/**
 @brief 获取群组属性
 @param groupId 获取信息的群组id
 @param completion 执行结果回调block
 */
-(void)getGroupDetail:(NSString *)groupId completion:(void(^)(ECError *error ,ECGroup *group))completion;


/**
 @brief 用户申请加入群组
 @param groupId 申请加入的群组Id
 @param reason 申请加入的理由
 @param completion 执行结果回调block
 */
-(void)joinGroup:(NSString*)groupId reason:(NSString*)reason completion:(void(^)(ECError *error, NSString* groupId))completion;


/**
 @brief 管理员邀请加入群组
 @param groupId 邀请加入的群组id
 @param reason 邀请理由
 @param members 邀请加入的人
 @param confirm 是否需要对方验证 1:直接加入(不需要验证) 2:需要对方验证
 @param completion 执行结果回调block
 */
-(void)inviteJoinGroup:(NSString *)groupId reason:(NSString*)reason members:(NSArray*)members confirm:(NSInteger)confirm completion:(void(^)(ECError *error, NSString* groupId, NSArray* members))completion;


/**
 @brief 管理员邀请加入群组
 @param members 邀请加入的人
 @param groupId 邀请加入的群组id
 @param reason 邀请理由
 @param confirm 是否需要对方验证 1:直接加入(不需要验证) 2:需要对方验证
 @param completion 执行结果回调block
 */
-(void)inviteMembers:(NSArray*)members joinGroup:(NSString *)groupId reason:(NSString*)reason confirm:(NSInteger)confirm completion:(void(^)(ECError *error, NSString* groupId, NSArray* failinfos))completion;


/**
 @brief 删除成员
 @param groupId 删除成员的群组id
 @param member 删除的成员
 @param completion 执行结果回调block
 */
-(void)deleteGroupMember:(NSString*)groupId member:(NSString*)member completion:(void(^)(ECError* error, NSString* groupId, NSString* member))completion;


/**
 @brief 批量删除群组成员

 @param groupId 群组id
 @param members 待删除的成员id数组
 @param completion 执行回调
 */
- (void)deleteGroupGroupMbers:(NSString*)groupId members:(NSArray*)members completion:(void(^)(ECError* error, NSString* groupId, NSArray* members))completion;

/**
 @brief 退出群组
 @param groupId 退出的群组id
 @param completion 执行结果回调block
 */
-(void)quitGroup:(NSString*)groupId completion:(void(^)(ECError* error, NSString* groupId))completion;


/**
 @brief 修改群组成员名片
 @param member 修改的成员名片
 @param completion 执行结果回调block
 */
-(void)modifyMemberCard:(ECGroupMember *)member completion:(void(^)(ECError *error, ECGroupMember* member))completion;


/**
 @brief 查询群组成员名片
 @param memberId 查询的成员id
 @param groupId 成员所属群组id
 @param completion 执行结果回调block
 */
-(void)queryMemberCard:(NSString *)memberId belong:(NSString*)groupId completion:(void(^)(ECError *error, ECGroupMember *member))completion;


/**
 @brief 查询群组成员
 @param groupId 查询的群组id
 @param completion 执行结果回调block
 */
-(void)queryGroupMembers:(NSString*)groupId completion:(void(^)(ECError *error, NSString* groupId, NSArray* members))completion;


/**
 @brief 分页查询群组成员
 @param groupId 查询的群组id
 @param borderMemberId 为nil时，从头查询
 @param pageSize 每页数量
 @param completion 执行结果回调block
 */
-(void)queryGroupMembers:(NSString*)groupId border:(NSString*)borderMemberId pageSize:(NSInteger)pageSize completion:(void(^)(ECError *error, NSString* groupId, NSArray* members))completion;


/**
 @brief 查询加入的群组 默认非讨论组
 @param completion 执行结果回调block
 */
-(void)queryOwnGroups:(void(^)(ECError *error, NSArray *groups))completion EC_DEPRECATED_IOS(5.0.1, 5.1.6, "Use - queryOwnGroupsWith:completion:");

/**
 @brief 查询加入的群组
 @param groupType 需要查询的群组类型
 @param completion 执行结果回调block
 */
-(void)queryOwnGroupsWith:(ECGroupType)groupType completion:(void(^)(ECError *error, NSArray *groups))completion;

/**
 @brief 分页查询加入的群组 默认非讨论组
 @param boarderGroupId 为nil时，从头查询
 @param pageSize 每页数量
 @param completion 执行结果回调block
 */
-(void)queryOwnGroupsWithBoarder:(NSString*)boarderGroupId pageSize:(NSInteger)pageSize completion:(void (^)(ECError *, NSArray *))completion EC_DEPRECATED_IOS(5.0.1, 5.1.6, "Use - queryOwnGroupsWithBoarder:pageSize:isDiscuss:completion:");

/**
 @brief 分页查询加入的群组
 @param boarderGroupId 为nil时，从头查询
 @param pageSize 每页数量
 @param groupType 需要查询的群组类型
 @param completion 执行结果回调block
 */
-(void)queryOwnGroupsWithBoarder:(NSString*)boarderGroupId pageSize:(NSInteger)pageSize groupType:(ECGroupType)groupType completion:(void (^)(ECError *error, NSArray *groups))completion;

/**
 @brief 管理员对成员禁言
 @param groupId 成员所属群组id
 @param memberId 成员id
 @param status 禁言状态
 @param completion 执行结果回调block
 */
-(void)forbidMemberSpeakStatus:(NSString*)groupId member:(NSString*)memberId speakStatus:(ECSpeakStatus)status completion:(void(^)(ECError *error, NSString* groupId, NSString* memberId))completion EC_DEPRECATED_IOS(5.0.1, 5.4.13, "Use - forbidMembersSpeakStatus:members:speakStatus:allForbid:");

/**
 @brief 管理员对成员批量禁言
 @param groupId 成员所属群组id
 @param members 成员id数组 allForbid为true时 members可不传
 @param status 禁言状态 必选
 @param allForbid 默认为false 开启后，根据status进行全员操作
 @param completion 执行结果回调block
 */
- (void)forbidMembersSpeakStatus:(NSString *)groupId members:(NSArray *)members speakStatus:(ECSpeakStatus)status allForbid:(BOOL)allForbid completion:(void(^)(ECError *error, NSString *groupId, NSArray *members))completion;

/**
 @brief 管理员验证用户申请加入群组
 @param groupId 申请加入的群组id
 @param memberId 申请加入的成员id
 @param type 是否同意
 @param completion 执行结果回调block
 */
-(void)ackJoinGroupRequest:(NSString *)groupId member:(NSString*)memberId ackType:(ECAckType)type completion:(void(^)(ECError *error, NSString* gorupId, NSString* memberId))completion;

/**
 @brief 管理员验证用户申请加入群组
 @param groupId 申请加入的群组id
 @param members 申请加入的成员id数组
 @param type 是否同意
 @param completion 执行结果回调block
 */
-(void)ackJoinGroupRequest:(NSString *)groupId members:(NSArray*)memberIds ackType:(ECAckType)type completion:(void(^)(ECError *error, NSString* gorupId, NSArray* memberIds))completion;

/**
 @brief 用户验证管理员邀请加入群组
 @param groupId 邀请加入的群组id
 @param invitor 邀请者id
 @param type 是否同意
 @param completion 执行结果回调block
 */
-(void)ackInviteJoinGroupRequest:(NSString*)groupId invitor:(NSString*)invitor ackType:(ECAckType)type completion:(void(^)(ECError *error, NSString* gorupId))completion;


/**
 @brief 成员设置群组消息规则
 @param option 群组消息规则
 @param completion 执行结果回调block
 */
-(void)setGroupMessageOption:(ECGroupOption*)option completion:(void(^)(ECError* error, NSString* groupId))completion EC_DEPRECATED_IOS(5.0.0, 5.4.0, "Use - ECDevice setMuteNotification:isMute:completion:");;

/**
 @brief 管理员修改用户角色权限
 @param groupId 群组id
 @param memberId 成员id
 @param role 2管理员 3普通成员
 @param completion 执行结果回调block
 */
- (void)setGroupMemberRole:(NSString*)groupId member:(NSString*)memberId role:(ECMemberRole)role completion:(void(^)(ECError *error,NSString *groupId,NSString *memberId))completion EC_DEPRECATED_IOS(5.0.1, 5.4.13, "Use - setGroupMembersRole:members:role:completion:");

/**
 @brief 管理员批量修改用户角色权限
 @param groupId 群组id
 @param members 群成员id数组
 @param role 2管理员 3普通成员
 @param completion 执行结果回调block
 */
- (void)setGroupMembersRole:(NSString *)groupId members:(NSArray *)members role:(ECMemberRole)role completion:(void(^)(ECError *error,NSString *groupId,NSArray *members))completion;


@end

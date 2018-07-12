//
//  UOADeviceManager.h
//  Pods
//
//  Created by 梁彬 on 2017/8/8.
//
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^success)(NSDictionary *jsonDictionary);

typedef void(^failer)(NSDictionary *jsonDictionary);

@interface UOADeviceManager : NSObject

+ (instancetype)manager;


/**
 获取设备组列表
 */
- (void)getDeviceGroupList;

- (void)getDeviceGroupListCallBack:(success)success failer:(failer)failer;

/**
 获取设备列表
 */
- (void)getDeviceList;

- (void)getDeviceListCallBack:(success)success failer:(failer)failer;
/**
 添加设备组

 @param groupName 组名
 */
- (void)addDeviceGroup:(NSString *)groupName;

- (void)addDeviceGroup:(NSString *)groupName CallBack:(success)success failer:(failer)failer;

/**
 删除设备组

 @param groupid 组名
 */
- (void)deleteDeviceGroup:(NSInteger)groupid;

- (void)deleteDeviceGroup:(NSInteger)groupid CallBack:(success)success failer:(failer)failer;

/**
 修改设备组名称

 @param groupid 设备组ID
 @param newGroupName 设备组名称
 */
- (void)updateDeviceGroupName:(NSInteger)groupid newGroupName:(NSString *)newGroupName;

- (void)updateDeviceGroupName:(NSInteger)groupid newGroupName:(NSString *)newGroupName  CallBack:(success)success failer:(failer)failer;
/**
 搜索设备
 */
- (void)searchDevice;

- (void)searchDeviceCallBack:(success)success failer:(failer)failer;

/**
 添加设备

 @param groupId 设备组id
 @param deviceId 设备id
 @param deviceName 设备名称
 @param gateway 网关标识
 */
- (void)addDevice:(NSInteger )groupId devcieId:(NSInteger )deviceId deviceName:(NSString *)deviceName gateway:(NSString *)gateway;

- (void)addDevice:(NSInteger )groupId devcieId:(NSInteger )deviceId deviceName:(NSString *)deviceName gateway:(NSString *)gateway CallBack:(success)success failer:(failer)failer;

/**
 删除设备

 @param deviceId 设备id
 @param gateway 网关标识
 */
- (void)deleteDevice:(NSInteger )deviceId gateway:(NSString *)gateway;

- (void)deleteDevice:(NSInteger )deviceId gateway:(NSString *)gateway CallBack:(success)success failer:(failer)failer;

/**
 修改设备名和分组

 @param groupId 设备组id
 @param deviceId 设备id
 @param deviceName 设备名称
 @param gateway 网关标识
 */
- (void)updateDeviceName:(NSInteger )groupId deviceId:(NSInteger )deviceId devcieName:(NSString *)deviceName gateway:(NSString *)gateway;

- (void)updateDeviceName:(NSInteger )groupId deviceId:(NSInteger )deviceId devcieName:(NSString *)deviceName gateway:(NSString *)gateway CallBack:(success)success failer:(failer)failer;

/**
 获取设备状态

 @param deviceId 设备id
 @param gateway 网关标识
 */
- (void)getDeviceStatus:(NSInteger )deviceId gateway:(NSString *)gateway;

- (void)getDeviceStatus:(NSInteger )deviceId gateway:(NSString *)gateway CallBack:(success)success failer:(failer)failer;


/**
 控制设备

 @param gateway 网关标识(ID)
 @param deviceID 设备ID
 @param commond 设备指令(字典格式 根据设备不同指令不同 参考文档3.3.11)
 */
- (void)controlDeviceWithGateway:(NSString *)gateway deviceID:(NSInteger )deviceID commond:(NSDictionary *)commond;

- (void)controlDeviceWithGateway:(NSString *)gateway deviceID:(NSInteger )deviceID commond:(NSDictionary *)commond callBack:(success)success failer:(failer)failer;

/**
 读取设备历史记录

 @param deviceID 设备ID
 @param gatewayID 网关标识
 @param start 记录起始条数,默认0开始
 @param cnt 一次获取的条数
 */
- (void)getDeviceRecordsWithDeviceID:(NSInteger )deviceID gatewayID:(NSString *)gatewayID start:(NSInteger )start cnt:(NSInteger )cnt;

- (void)getDeviceRecordsWithDeviceID:(NSInteger )deviceID gatewayID:(NSString *)gatewayID start:(NSInteger )start cnt:(NSInteger )cnt callBack:(success)success failer:(failer)failer;


/**
 添加新的撤布防组

 @param groupName 组名
 @param devices 安防设备数组 eg:  @[@{@"gateway":xxxx,@"id":11,@"zonetype":11},...]
                            其中gateway-网关标识 id-设备ID zonetype-设备zonetype
 */
- (void)addProtectionGroupWithName:(NSString *)groupName devices:(NSArray <NSDictionary *>*)devices;

- (void)addProtectionGroupWithName:(NSString *)groupName devices:(NSArray <NSDictionary *>*)devices callBack:(success)success failer:(failer)failer;

/**
 获取账号下所有撤布防组设备
 */
- (void)getAllInProtectionDevices;

- (void)getAllInProtectionDevicesCallBack:(success)success failer:(failer)failer;

/**
 撤布防组的控制(撤防/布防)

 @param groupID 撤布防组ID
 @param status 撤防/布防 (1/0)
 */
- (void)removalOrProtectionWithGroupID:(NSInteger )groupID status:(NSInteger )status;

- (void)removalOrProtectionWithGroupID:(NSInteger )groupID status:(NSInteger )status callBack:(success)success failer:(failer)failer;

/**
 删除撤布防分组

 @param groupID 撤布防分组组ID
 */
- (void)deleteProtectionGroup:(NSInteger )groupID;

- (void)deleteProtectionGroup:(NSInteger )groupID callBack:(success)success failer:(failer)failer;

/**
 修改撤布防分组

 @param groupName 撤布防分组名
 @param groupID 撤布防分组ID
 @param devices 分组下的设备
 */
- (void)editProtectionGroup:(NSString *)groupName groupID:(NSInteger )groupID devices:(NSArray <NSDictionary *>*)devices;

- (void)editProtectionGroup:(NSString *)groupName groupID:(NSInteger )groupID devices:(NSArray <NSDictionary *>*)devices callBack:(success)success failer:(failer)failer;

@end

NS_ASSUME_NONNULL_END

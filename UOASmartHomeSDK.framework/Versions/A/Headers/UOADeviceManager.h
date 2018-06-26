//
//  UOADeviceManager.h
//  Pods
//
//  Created by 梁彬 on 2017/8/8.
//
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class UOADevice;
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

 @param device 设备模型
 */
- (void)controlDevice:(UOADevice *)device;

- (void)controlDevice:(UOADevice *)device CallBack:(success)success failer:(failer)failer;

@end

NS_ASSUME_NONNULL_END

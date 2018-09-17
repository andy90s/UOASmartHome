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
 转换推送信息

 @param info 由极光推送的设备报警信息
 @return 转换后信息
 */
- (NSDictionary *)convertPushInformation:(NSDictionary *)info;

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
 获取账号下所有没有加入撤布防组的红外门磁设备
 */
- (void)getUnbindProtectionDevices;

- (void)getUnbindProtectionDevicesCallBack:(success)success failer:(failer)failer;

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


/**
 曼顿空开读取实时参数

 @param gateWay 网关ID
 @param device_id 设备ID
 */
- (void)mandun_ammeterInformationGateWay:(NSString*)gateWay device_id:(NSInteger )device_id;

- (void)mandun_ammeterInformationGateWay:(NSString*)gateWay device_id:(NSInteger )device_id callBack:(success)success failer:(failer)failer;

/**
 曼顿空开电量统计信息

 @param gateWay 网关ID
 @param device_id 设备ID
 */
- (void)mandun_ammeterStatisticsInformation:(NSString*)gateWay device_id:(NSInteger )device_id;

- (void)mandun_ammeterStatisticsInformation:(NSString*)gateWay device_id:(NSInteger )device_id callBack:(success)success failer:(failer)failer;

/**
 曼顿空开设置配置参数

 @param devid 设备ID
 @param gwid 网关ID
 @param name 设备名称
 @param addr 曼顿空开发生报警时的路数
 @param voltage_min 最小电压
 @param voltage_max 最大电压
 @param current_max 当前电压
 @param power_max 功率
 */
- (void)mandun_ammeterConfigurationParametersDevid:(NSInteger )devid gwid:(NSString *)gwid name:(NSString *)name addr:(NSInteger)addr voltage_min:(NSInteger)voltage_min voltage_max:(NSInteger)voltage_max current_max:(NSInteger)current_max power_max:(NSInteger )power_max;

- (void)mandun_ammeterConfigurationParametersDevid:(NSInteger )devid gwid:(NSString *)gwid name:(NSString *)name addr:(NSInteger)addr voltage_min:(NSInteger)voltage_min voltage_max:(NSInteger)voltage_max current_max:(NSInteger)current_max power_max:(NSInteger )power_max callBack:(success)success failer:(failer)failer;

/**
 曼顿空开自动检测

 @param devid 设备ID
 @param gwid 网关ID
 @param mode 检测模式
 @param time 时间间隔
 */
- (void)mandun_ammeterConfigurationParametersDevid:(NSInteger )devid gwid:(NSString *)gwid mode:(NSInteger )mode time:(NSInteger)time ;

- (void)mandun_ammeterConfigurationParametersDevid:(NSInteger )devid gwid:(NSString *)gwid mode:(NSInteger )mode time:(NSInteger)time callBack:(success)success failer:(failer)failer;

/**
 曼顿空开读取配置参数

 @param devid 设备ID
 @param gwid 网关ID
 */
- (void)mandun_readAmmeterConfigurationParameterDevid:(NSInteger )devid gwid:(NSString *)gwid;

- (void)mandun_readAmmeterConfigurationParameterDevid:(NSInteger )devid gwid:(NSString *)gwid callBack:(success)success failer:(failer)failer;

/**
 手动检测曼顿设备

 @param devid 设备ID
 @param gwid 网关ID
 */
- (void)mandun_manualTestDevid:(NSInteger )devid gwid:(NSString *)gwid;

- (void)mandun_manualTestDevid:(NSInteger )devid gwid:(NSString *)gwid callBack:(success)success failer:(failer)failer;

/**
 自动检测曼顿设备

 @param devid 设备ID
 @param gwid 网关ID
 */
- (void)mandun_autotamicTestDevid:(NSInteger )devid gwid:(NSString *)gwid;

- (void)mandun_autotamicTestDevid:(NSInteger )devid gwid:(NSString *)gwid callBack:(success)success failer:(failer)failer;


/**
 修改智能门锁密码(SOB门锁)

 @param deviceid 设备ID
 @param usertype 用户类型
 @param userid 用户ID
 @param gatewayid 网关ID
 @param newPasswrod 新的密码
 */
- (void)changePasswrodDoorlockDeviceid:(NSInteger )deviceid
                              usertype:(NSInteger)usertype
                                userid:(NSInteger )userid
                             gatewayid:(NSString *)gatewayid
                           newPassword:(NSString *)newPasswrod;

- (void)changePasswrodDoorlockDeviceid:(NSInteger )deviceid usertype:(NSInteger)usertype userid:(NSInteger )userid gatewayid:(NSString *)gatewayid newPassword:(NSString *)newPasswrod callBack:(success)success failer:(failer)failer;

/**
 获取门锁用户列表(SOB门锁)

 @param deviceid 设备ID
 @param gatewayid 网关标识
 */
- (void)getUserListDoorlockDeviceid:(NSInteger )deviceid
                          gatewayid:(NSString *)gatewayid;

- (void)getUserListDoorlockDeviceid:(NSInteger )deviceid
                          gatewayid:(NSString *)gatewayid
                           callBack:(success)success
                             failer:(failer)failer;

/**
 删除门锁用户

 @param deviceid 设备ID
 @param userid 用户ID
 @param usertype 用户类型
 @param gatewayid 网关标识
 */
- (void)deleteUserDoorlockDeviceid:(NSInteger )deviceid
                            userid:(NSInteger )userid
                          usertype:(NSInteger )usertype
                         gatewayid:(NSString *)gatewayid;


- (void)deleteUserDoorlockDeviceid:(NSInteger )deviceid
                            userid:(NSInteger )userid
                          usertype:(NSInteger )usertype
                         gatewayid:(NSString *)gatewayid
                          callBack:(success)success
                            failer:(failer)failer;

/**
 门锁记录(SOB)

 @param deviceid 设备ID
 @param gatewayid 网关标识
 */
- (void)getRecordsDoorlockDeviceid:(NSInteger )deviceid
                         gatewayid:(NSString *)gatewayid;

- (void)getRecordsDoorlockDeviceid:(NSInteger )deviceid
                         gatewayid:(NSString *)gatewayid
                          callBack:(success)success
                            failer:(failer)failer;
@end

NS_ASSUME_NONNULL_END

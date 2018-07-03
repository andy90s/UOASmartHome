//
//  UOAGatewayManager.h
//  Pods
//
//  Created by 梁彬 on 2017/8/8.
//
//

#import <Foundation/Foundation.h>



NS_ASSUME_NONNULL_BEGIN

typedef void(^success)(NSDictionary *jsonDictionary);

typedef void(^failer)(NSDictionary *jsonDictionary);


@interface UOAGatewayManager : NSObject

+ (instancetype)manager;

/**
 网关开网

 @param gateway 网关标识
 */
- (void)allowsScanGateway:(NSString *)gateway;


- (void)allowsScanGateway:(NSString *)gateway callBack:(success)success failer:(failer)falier;

/**
 搜索网关
 */
- (void)searchGateway;

- (void)searchGatewaycallBack:(success)success failer:(failer)falier;

/**
 绑定网关

 @param gateway 网关标识
 @param gatewayName 网关名称
 */
- (void)bindGateway:(NSString *)gateway gatewayName:(NSString *)gatewayName userName:(NSString *)userName;

- (void)bindGateway:(NSString *)gateway gatewayName:(NSString *)gatewayName userName:(NSString *)userName callBack:(success)success failer:(failer)falier;

/**
 获取网关列表
 */
- (void)getGatewayList;

- (void)getGatewayListCallBack:(success)success failer:(failer)falier;

/**
 检测唯一管理员

 @param gateway 网关标识
 */
- (void)checkUniqueAdmin:(NSString *)gateway;

- (void)checkUniqueAdmin:(NSString *)gateway callBack:(success)success failer:(failer)falier;



/**
 解除绑定网关

 @param gateway 网关标识
 @param userName 用户名
 */
- (void)unbindGateway:(NSString *)gateway userName:(NSString *)userName;

- (void)unbindGateway:(NSString *)gateway userName:(NSString *)userName callBack:(success)success failer:(failer)falier;

/**
 修改网关别名

 @param gatewayName 网关名称
 @param gatewaytid 网关ID
 */
- (void)updateGatewayName:(NSString *)gatewayName gatewayID:(NSString *)gatewaytid;

- (void)updateGatewayName:(NSString *)gatewayName gatewayID:(NSString *)gatewaytid callBack:(success)success failer:(failer)falier;


/**
 消除警告
 */
- (void)eliminateWarning;

- (void)eliminateWarningCallBack:(success)success failer:(failer)falier;

@end

NS_ASSUME_NONNULL_END

//
//  UOAUserManager.h
//  Pods
//
//  Created by 梁彬 on 2017/7/31.
//
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString *const kUMESmartHomeSpecialNotification; // 特殊的通知消息(单点登录)

typedef void(^success)(NSDictionary *jsonDictionary);

typedef void(^failer)(NSDictionary *jsonDictionary);

@interface UOAUserManager : NSObject

+ (instancetype)manager;

@property (nonatomic,readonly,copy) NSString *userName;

@property (nonatomic,readonly,copy) NSString *password;


/**
 获取注册短信验证码

 @param usrNumber 用户手机号
 */
- (void)getRegisterCode:(NSString *)usrNumber;

- (void)getRegisterCode:(NSString *)usrNumber callBack:(success)success failer:(failer)falier;


/**
 验证注册验证码

 @param usrNumber 用户手机号
 @param vCode 获取到的验证码
 */
- (void)checkRegisterCode:(NSString *)usrNumber verificationCode:(NSString *)vCode;

- (void)checkRegisterCode:(NSString *)usrNumber verificationCode:(NSString *)vCode callBack:(success)success failer:(failer)falier;

/**
 注册账号

 @param userName 用户手机号
 @param password 密码
 */
- (void)registerAccount:(NSString *)userName password:(NSString *)password;

- (void)registerAccount:(NSString *)userName password:(NSString *)password callBack:(success)success failer:(failer)falier;


/**
 登录

 @param userName 用户名
 @param password 密码
 */
- (void)loginUserName:(NSString *)userName password:(NSString *)password license:(NSString *)license;

- (void)loginUserName:(NSString *)userName password:(NSString *)password license:(NSString *)license callBack:(success)success failer:(failer)falier;


/**
 修改密码

 @param userName 用户名
 @param oldPassword 旧密码
 @param newPassword 新密码
 */
- (void)modifyPassword:(NSString *)userName oldPassword:(NSString *)oldPassword newPassword:(NSString *)newPassword;

- (void)modifyPassword:(NSString *)userName oldPassword:(NSString *)oldPassword newPassword:(NSString *)newPassword callBack:(success)success failer:(failer)falier;

/**
 获取忘记密码验证码

 @param userName 用户名
 */
- (void)getForgetPasswordCode:(NSString *)userName;

- (void)getForgetPasswordCode:(NSString *)userName callBack:(success)success failer:(failer)falier;

/**
 验证忘记密码验证码

 @param userName 用户名
 @param vcode 验证码
 */
- (void)checkForgetPasswordCode:(NSString *)userName vCode:(NSString *)vcode;

- (void)checkForgetPasswordCode:(NSString *)userName vCode:(NSString *)vcode callBack:(success)success failer:(failer)falier;

/**
 重置密码

 @param userName 用户名
 @param newPassword 新密码
 */
- (void)resetPassword:(NSString *)userName newPassword:(NSString *)newPassword;

- (void)resetPassword:(NSString *)userName newPassword:(NSString *)newPassword callBack:(success)success failer:(failer)falier;

/**
 退出登录

 @param userName 用户名    
 */
- (void)logout:(NSString *)userName;

- (void)logout:(NSString *)userName callBack:(success)success failer:(failer)falier;

/**
 获取用户信息

 @param username jsonString
 */
- (void)getUserInfoWithUserName:(NSString *)username;

- (void)getUserInfoWithUserName:(NSString *)username callBack:(success)success failer:(failer)falier;

/**
 获取用户天气

 @param city 城市
 */
- (void)getUserWeatherWithCity:(NSString *)city;

- (void)getUserWeatherWithCity:(NSString *)city callBack:(success)success failer:(failer)falier;

@end

NS_ASSUME_NONNULL_END

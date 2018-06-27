# 雍敏开放平台API说明文档（iOS）

----------

版本 | 日期 | 拟稿和修改 | 说明
---|---|---|---
1.0 | 2017-07-10 | 梁先华 | 初稿
1.1|2018-06-26|梁先华|修改
|||
|||
|||


## 1. 介绍

### 目标

本文档详细介绍了Open API的详细说明。

### 标识
UOA  Umeinfo Open API
### 文档概述

本文档主要分为三个部分，第一部分概要，第二部分为Open Api的详细说明。

## 2. 集成步骤

### 2.1 将framework直接拖入工程

添加系统库:

libicucore.tbd 、
CoreData.framework

工程配置:
Build Settings -> Other Linker Flags 中添加 `-ObjC`

如果项目支持cocoapods，在podfile文件中配置
```
pod 'UOASmartHomeSDK',:git => 'https://github.com/andy90s/UOASmartHome.git'
```
执行`podupdate`即可完成集成。
### 2.2 初始化SDK
在AppDelegate中导入头文件

添加SDK初始化方法

```
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    [UMInfoOpenAPI initWithAppKey:@"AppKey"];
    return YES;
}

```
**初始化只需要在程序启动时初始化一次即可。**

## 3. 接口说明
### 3.1 用户模块

#### 3.1.1 用户登录
#### 请求参数
```
/**
 登录

 @param userName 用户名
 @param password 密码
 */
- (void)loginUserName:(NSString *)userName password:(NSString *)password callBack:(success)success failer:(failer)falier;
```
#### 示例说明
```
[UOAUserManager.manager loginUserName:@"username" password:@"password" callBack:^(NSDictionary *jsonDictionary) {
   // 登录成功
} failer:^(NSDictionary *jsonDictionary) {
   // 登录失败
}];
```
#### 3.1.2 注销登录
```
/**
 退出登录

 @param userName 用户名    
 */

- (void)logout:(NSString *)userName callBack:(success)success failer:(failer)falier;
```

#### 3.1.3 获取注册验证码

```
/**
 获取注册短信验证码

 @param usrNumber 用户手机号
 */

- (void)getRegisterCode:(NSString *)usrNumber callBack:(success)success failer:(failer)falier;
```
#### 3.1.4 验证注册验证码
```
/**
 验证注册验证码

 @param usrNumber 用户手机号
 @param vCode 获取到的验证码
 */

- (void)checkRegisterCode:(NSString *)usrNumber verificationCode:(NSString *)vCode callBack:(success)success failer:(failer)falier;
```
#### 3.1.5 注册账号
```
/**
 注册账号

 @param userName 用户手机号
 @param password 密码
 */

- (void)registerAccount:(NSString *)userName password:(NSString *)password callBack:(success)success failer:(failer)falier;
```
#### 3.1.6 修改密码
```
/**
 修改密码

 @param userName 用户名
 @param oldPassword 旧密码
 @param newPassword 新密码
 */

- (void)modifyPassword:(NSString *)userName oldPassword:(NSString *)oldPassword newPassword:(NSString *)newPassword callBack:(success)success failer:(failer)falier;
```
#### 3.1.7 获取忘记密码验证码
```
/**
 获取忘记密码验证码

 @param userName 用户名
 */

- (void)getForgetPasswordCode:(NSString *)userName callBack:(success)success failer:(failer)falier;

```
#### 3.1.8 验证忘记密码验证码
```
/**
 验证忘记密码验证码

 @param userName 用户名
 @param vcode 验证码
 */

- (void)checkForgetPasswordCode:(NSString *)userName vCode:(NSString *)vcode callBack:(success)success failer:(failer)falier;
```
#### 3.1.9 重置密码
```
/**
 重置密码

 @param userName 用户名
 @param newPassword 新密码
 */

- (void)resetPassword:(NSString *)userName newPassword:(NSString *)newPassword callBack:(success)success failer:(failer)falier;
```
### 3.2 网关模块
#### 3.2.1 网关开网（允许被其他非管理员搜索绑定）
```
/**
 网关开网

 @param gateway 网关标识
 */

- (void)allowsScanGateway:(NSString *)gateway callBack:(success)success failer:(failer)falier;
```
#### 3.2.2 搜索网关
```
/**
 搜索网关（内网搜索,保持当前WiFi与网关WiFi一致）
 */
- (void)searchGatewaycallBack:(success)success failer:(failer)falier;

```
#### 3.2.3 绑定网关
```
/**
 绑定网关

 @param gateway 网关标识
 @param gatewayName 网关名称
 */
 - (void)bindGateway:(NSString *)gateway gatewayName:(NSString *)gatewayName userName:(NSString *)userName callBack:(success)success failer:(failer)falier;

```
#### 3.2.4 获取网关列表
```
/**
 获取网关列表
 */
- (void)getGatewayListCallBack:(success)success failer:(failer)falier;
```
#### 3.2.5 检测唯一管理员
```
/**
 检测唯一管理员

 @param gateway 网关标识
 */
- (void)checkUniqueAdmin:(NSString *)gateway callBack:(success)success failer:(failer)falier;
```
返回参数|类别|说明|备注
---|---|---|---
only_admin|int|是否管理员|1-是0-不是
#### 3.2.6 解除绑定网关
```
/**
 解除绑定网关

 @param gateway 网关标识
 @param userName 用户名
 */

- (void)unbindGateway:(NSString *)gateway userName:(NSString *)userName callBack:(success)success failer:(failer)falier;
```
#### 3.2.7 修改网关别名
```
/**
 修改网关别名

 @param gatewayName 网关名称
 @param gatewaytid 网关ID
 */
- (void)updateGatewayName:(NSString *)gatewayName gatewayID:(NSString *)gatewaytid callBack:(success)success failer:(failer)falier;
```

### 3.3 设备模块
#### 3.3.1 获取设备组列表
```
/**
 获取设备组列表
 */

- (void)getDeviceGroupListCallBack:(success)success failer:(failer)failer;
```
#### 3.3.2 添加设备组
```
/**
 添加设备组

 @param groupName 组名
 */

- (void)addDeviceGroup:(NSString *)groupName CallBack:(success)success failer:(failer)failer;
```
#### 3.3.3 删除设备组
```

/**
 删除设备组

 @param groupid 组名
 */

- (void)deleteDeviceGroup:(NSInteger)groupid CallBack:(success)success failer:(failer)failer;
```
#### 3.3.4 修改设备组名称
```
/**
 修改设备组名称

 @param groupid 设备组ID
 @param newGroupName 设备组名称
 */

- (void)updateDeviceGroupName:(NSInteger)groupid newGroupName:(NSString *)newGroupName  CallBack:(success)success failer:(failer)failer;
```
#### 3.3.5 获取设备列表
```
/**
 获取设备列表
 */

- (void)getDeviceListCallBack:(success)success failer:(failer)failer;
```
#### 3.3.6 搜索设备
```
/**
 搜索设备
 */

- (void)searchDeviceCallBack:(success)success failer:(failer)failer;
```
#### 3.3.7 添加设备
```
/**
 添加设备

 @param groupId 设备组id
 @param deviceId 设备id
 @param deviceName 设备名称
 @param gateway 网关标识
 */

- (void)addDevice:(NSInteger )groupId devcieId:(NSInteger )deviceId deviceName:(NSString *)deviceName gateway:(NSString *)gateway CallBack:(success)success failer:(failer)failer;
```
#### 3.3.8 删除设备
```
/**
 删除设备

 @param deviceId 设备id
 @param gateway 网关标识
 */

- (void)deleteDevice:(NSInteger )deviceId gateway:(NSString *)gateway CallBack:(success)success failer:(failer)failer;
```
#### 3.3.9 修改设备名和分组
```
/**
 修改设备名和分组

 @param groupId 设备组id
 @param deviceId 设备id
 @param deviceName 设备名称
 @param gateway 网关标识
 */

- (void)updateDeviceName:(NSInteger )groupId deviceId:(NSInteger )deviceId devcieName:(NSString *)deviceName gateway:(NSString *)gateway CallBack:(success)success failer:(failer)failer;
```
#### 3.3.10 获取设备状态
```
/**
 获取设备状态

 @param deviceId 设备id
 @param gateway 网关标识
 */

- (void)getDeviceStatus:(NSInteger )deviceId gateway:(NSString *)gateway CallBack:(success)success failer:(failer)failer;
```
#### 3.3.11 控制设备
```
/**
 控制设备

 @param device 设备模型
 */

- (void)controlDevice:(UOADevice *)device CallBack:(success)success failer:(failer)failer;
```
## 4.状态码
------------------

状态码 | 说明
----| ---
0x0| 成功
0x1| 密码错误
0x2| 用户不存在
0x3| SESSION过期
0x4| 用户已存在
0x5| 密码太短
0x6| 用户名不能为空
0x7| 头信息错误
0x8| Body信息错误
0x9| 无授权
0xA| 绑定错误
0xB| 没有手机号
0xC| 验证码不符合
0xD| 验证码过期
0xF| 超过绑定网关数量上限
0x11|没有用户信息
0x12| Session不符合
0x13| 旧密码错误
0x14| 用户已在别处登陆
0x15| 消息ukey不匹配
0x12C| 组已存在
0x12D| 组不存在
0x12E| 组控制参数错误
0x1F4| 设备不存在
0x1F5| 设备读取异常
0x1F6| 设备离线
0x1F7| 设备控制超时
0x1F8| 设备电量低
0x1F9| 设备控制参数错误
0x1FA| 未发现新设备
0x1FB| 设备已存在
0x1FC| PM2.5不存在
0x1FD| 温度传感器不存在
0x1FE| 烟雾探测不存在
0x1FF| 可燃气体不存在
0x200|水浸不存在
0x201|门磁不存在
0x202|红外不存在
0x203|SOS不存在
0x204|设备已添加
0x3e8|场景已存在
0x3e9|场景数量过多
0x3eA|场景不存在
0x3eB|场景参数错误
0x3eC|场景时间条件冲突
0x3eD|场景非法
0x7D0|不支持的命令
0x7D1|空对象
0x7D2|网关挂起，正在停止中
0x7D3|网关正在启动
0x7D5|验证码的session超时
0x7D6|修改分组错误
0x7D7|网关离线
0x7D8|没有网关
0x7D9|网关名已存在
0x7DA|设备名已存在
0x7DB|不支持的json协议版本
0x7DC|不支持的消息号
0x7DD|APP与网关版本不一致
0x7DE|已经绑定过该网关
-0x1|未知错误
65535|未知错误



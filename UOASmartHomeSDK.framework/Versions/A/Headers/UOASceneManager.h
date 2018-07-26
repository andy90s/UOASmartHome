//
//  UOASceneManager.h
//  Pods-UOASmartHomeSDK_Example
//
//  Created by 梁先华 on 2018/7/25.
//

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN
typedef void(^success)(NSDictionary *jsonDictionary);

typedef void(^failer)(NSDictionary *jsonDictionary);

@interface UOASceneManager : NSObject

+ (instancetype)manager;

/**
 获取场景列表
 */
- (void)getSceneList;

- (void)getSceneListCallBack:(success)success failer:(failer)failer;

/**
 添加场景

 @param name 场景名称
 @param conditions 启动条件
 @param results 结果条件
 @param recResults 执行条件
 */
- (void)addSceneWithName:(NSString *)name conditions:(NSDictionary *)conditions results:(NSDictionary *)results recResults:(NSDictionary *)recResults;

- (void)addSceneWithName:(NSString *)name conditions:(NSDictionary *)conditions results:(NSDictionary *)results recResults:(NSDictionary *)recResults callBack:(success)success failer:(failer)failer;

@end
NS_ASSUME_NONNULL_END

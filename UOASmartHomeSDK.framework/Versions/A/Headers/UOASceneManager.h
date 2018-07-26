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
- (void)addSceneWithName:(NSString *)name
              conditions:(NSDictionary *)conditions
                 results:(NSDictionary *)results
              recResults:(NSDictionary *)recResults;

- (void)addSceneWithName:(NSString *)name conditions:(NSDictionary *)conditions results:(NSDictionary *)results recResults:(NSDictionary *)recResults callBack:(success)success failer:(failer)failer;

/**
 删除场景

 @param sceneid 场景ID
 */
- (void)deleteSceneWithID:(NSInteger )sceneid;

- (void)deleteSceneWithID:(NSInteger )sceneid callBack:(success)success failer:(failer)failer;

/**
 控制场景

 @param sceneid 场景ID
 @param onoff 开关
 */
- (void)controlSceneWithID:(NSInteger )sceneid onoff:(NSInteger )onoff;

- (void)controlSceneWithID:(NSInteger )sceneid onoff:(NSInteger )onoff callBack:(success)success failer:(failer)failer;

/**
 修改场景

 @param name 场景名称
 @param sceneid 场景ID
 @param conditions 启动条件
 @param results 结束条件
 @param recResults 执行条件
 */
- (void)editSceneWithName:(NSString *)name
                  sceneid:(NSInteger )sceneid
               conditions:(NSDictionary *)conditions
                  results:(NSDictionary *)results
               recResults:(NSDictionary *)recResults;

- (void)editSceneWithName:(NSString *)name sceneid:(NSInteger )sceneid conditions:(NSDictionary *)conditions results:(NSDictionary *)results recResults:(NSDictionary *)recResults callBack:(success)success failer:(failer)failer;

@end
NS_ASSUME_NONNULL_END

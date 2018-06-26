//
//  UOASmartHomeSDK.h
//  Pods
//
//  Created by 梁彬 on 2017/7/26.
//  Copyright © 2017年 andy90s. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface UOASmartHomeSDK : NSObject

/**
 初始化SDK

 @param appKey 传入正确的申请到的AppKey
 */
+ (void)initWithAppKey:(NSString *)appKey;


@end

NS_ASSUME_NONNULL_END

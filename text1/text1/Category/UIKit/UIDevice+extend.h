//
//  UIDevice.h
//  NSObject+extend
//
//  Created by Steven on 14/12/8.
//  Copyright (c) 2014年 Neva. All rights reserved.
//

#import <UIKit/UIKit.h>
//ios系统版本
#define ios8x [[[UIDevice currentDevice] systemVersion] floatValue] >=8.0f
#define ios7x ([[[UIDevice currentDevice] systemVersion] floatValue] >= 7.0f) && ([[[UIDevice currentDevice] systemVersion] floatValue] < 8.0f)
#define ios6x [[[UIDevice currentDevice] systemVersion] floatValue] < 7.0f
#define iosNot6x [[[UIDevice currentDevice] systemVersion] floatValue] >= 7.0f


#define iphone4x_3_5 ([UIScreen mainScreen].bounds.size.height==480.0f)

#define iphone5x_4_0 ([UIScreen mainScreen].bounds.size.height==568.0f)

#define iphone6x_4_7 ([UIScreen mainScreen].bounds.size.height==667.0f)

#define iphone6xPlus_5_5 ([UIScreen mainScreen].bounds.size.height==736.0f || [UIScreen mainScreen].bounds.size.height==414.0f)
@interface UIDevice(UIDevice_extend)

/**
 *  获取设备版本信息
 *
 *  @return iPhone1,1
 */
+ (NSString*)platform;

/**
 *  获取设备版本名字
 *
 *  @return iPhone 1G
 */
+ (NSString *)platformString;

/**
 *  app版本
 *
 *  @return app版本
 */
+ (NSString *)appVersion;

/**
 *  app build版本
 *
 *  @return app build版本
 */
+ (NSString *)appBuildVersion;

/**
 *  app名称
 *
 *  @return app名称
 */
+ (NSString *)appName;

/**
 *  获取iOS系统版本号
 */
+ (float)iOSVersion;

@end

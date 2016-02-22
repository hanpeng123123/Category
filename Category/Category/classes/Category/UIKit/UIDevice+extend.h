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

/**
 *  从KeyChain中读取设备的UDID，如果没有，先创建保存，然后返回
 *
 *  @return UDID
 */
+ (NSString *)UDID;


#pragma mark - Device Information
///=============================================================================
/// @name Device Information
///=============================================================================

/// Device system version (e.g. 8.1)
+ (float)systemVersion;

/// Whether the device is iPad/iPad mini.
@property (nonatomic, readonly) BOOL isPad;

/// Whether the device is a simulator.
@property (nonatomic, readonly) BOOL isSimulator;

/// Whether the device is jailbroken.
@property (nonatomic, readonly) BOOL isJailbroken;

/// Wherher the device can make phone calls.
@property (nonatomic, readonly) BOOL canMakePhoneCalls NS_EXTENSION_UNAVAILABLE_IOS("");

/// The device's machine model.  e.g. "iPhone6,1" "iPad4,6"
/// @see http://theiphonewiki.com/wiki/Models
@property (nonatomic, readonly) NSString *machineModel;

/// The device's machine model name. e.g. "iPhone 5s" "iPad mini 2"
/// @see http://theiphonewiki.com/wiki/Models
@property (nonatomic, readonly) NSString *machineModelName;

/// The System's startup time.
@property (nonatomic, readonly) NSDate *systemUptime;


#pragma mark - Network Information
///=============================================================================
/// @name Network Information
///=============================================================================

/// WIFI IP address of this device (can be nil). e.g. @"192.168.1.111"
@property (nonatomic, readonly) NSString *ipAddressWIFI;

/// Cell IP address of this device (can be nil). e.g. @"10.2.2.222"
@property (nonatomic, readonly) NSString *ipAddressCell;


/**
 Network traffic type:
 
 WWAN: Wireless Wide Area Network.
 For example: 3G/4G.
 
 WIFI: Wi-Fi.
 
 AWDL: Apple Wireless Direct Link (peer-to-peer connection).
 For exmaple: AirDrop, AirPlay, GameKit.
 */
typedef NS_OPTIONS(NSUInteger, YYNetworkTrafficType) {
    YYNetworkTrafficTypeWWANSent     = 1 << 0,
    YYNetworkTrafficTypeWWANReceived = 1 << 1,
    YYNetworkTrafficTypeWIFISent     = 1 << 2,
    YYNetworkTrafficTypeWIFIReceived = 1 << 3,
    YYNetworkTrafficTypeAWDLSent     = 1 << 4,
    YYNetworkTrafficTypeAWDLReceived = 1 << 5,
    
    YYNetworkTrafficTypeWWAN = YYNetworkTrafficTypeWWANSent | YYNetworkTrafficTypeWWANReceived,
    YYNetworkTrafficTypeWIFI = YYNetworkTrafficTypeWIFISent | YYNetworkTrafficTypeWIFIReceived,
    YYNetworkTrafficTypeAWDL = YYNetworkTrafficTypeAWDLSent | YYNetworkTrafficTypeAWDLReceived,
    
    YYNetworkTrafficTypeALL = YYNetworkTrafficTypeWWAN |
    YYNetworkTrafficTypeWIFI |
    YYNetworkTrafficTypeAWDL,
};

/**
 Get device network traffic bytes.
 
 @discussion This is a counter since the device's last boot time.
 Usage:
 
 uint64_t bytes = [[UIDevice currentDevice] getNetworkTrafficBytes:YYNetworkTrafficTypeALL];
 NSTimeInterval time = CACurrentMediaTime();
 
 uint64_t bytesPerSecond = (bytes - _lastBytes) / (time - _lastTime);
 
 _lastBytes = bytes;
 _lastTime = time;
 
 
 @param type traffic types
 @return bytes counter.
 */
- (uint64_t)getNetworkTrafficBytes:(YYNetworkTrafficType)types;

#pragma mark - Disk Space
///=============================================================================
/// @name Disk Space
///=============================================================================

/// Total disk space in byte. (-1 when error occurs)
@property (nonatomic, readonly) int64_t diskSpace;

/// Free disk space in byte. (-1 when error occurs)
@property (nonatomic, readonly) int64_t diskSpaceFree;

/// Used disk space in byte. (-1 when error occurs)
@property (nonatomic, readonly) int64_t diskSpaceUsed;


#pragma mark - Memory Information
///=============================================================================
/// @name Memory Information
///=============================================================================

/// Total physical memory in byte. (-1 when error occurs)
@property (nonatomic, readonly) int64_t memoryTotal;

/// Used (active + inactive + wired) memory in byte. (-1 when error occurs)
@property (nonatomic, readonly) int64_t memoryUsed;

/// Free memory in byte. (-1 when error occurs)
@property (nonatomic, readonly) int64_t memoryFree;

/// Acvite memory in byte. (-1 when error occurs)
@property (nonatomic, readonly) int64_t memoryActive;

/// Inactive memory in byte. (-1 when error occurs)
@property (nonatomic, readonly) int64_t memoryInactive;

/// Wired memory in byte. (-1 when error occurs)
@property (nonatomic, readonly) int64_t memoryWired;

/// Purgable memory in byte. (-1 when error occurs)
@property (nonatomic, readonly) int64_t memoryPurgable;

#pragma mark - CPU Information
///=============================================================================
/// @name CPU Information
///=============================================================================

/// Avaliable CPU processor count.
@property (nonatomic, readonly) NSUInteger cpuCount;

/// Current CPU usage, 1.0 means 100%. (-1 when error occurs)
@property (nonatomic, readonly) float cpuUsage;

/// Current CPU usage per processor (array of NSNumber), 1.0 means 100%. (nil when error occurs)
@property (nonatomic, readonly) NSArray *cpuUsagePerProcessor;




#ifndef kSystemVersion
#define kSystemVersion [UIDevice systemVersion]
#endif

#ifndef kiOS6Later
#define kiOS6Later (kSystemVersion >= 6)
#endif

#ifndef kiOS7Later
#define kiOS7Later (kSystemVersion >= 7)
#endif

#ifndef kiOS8Later
#define kiOS8Later (kSystemVersion >= 8)
#endif

#ifndef kiOS9Later
#define kiOS9Later (kSystemVersion >= 9)
#endif

@end
@interface UIDevice (UIDevice_KeyChain)

/**
 *  保存数据到KeyChain
 *
 *  @param key      数据标识符key
 *  @param object   需要保存的对象
 */
+ (void)saveKey:(NSString *)key object:(id)object;

/**
 *  删除KeyChain中的数据
 *
 *  @param key      数据标识符key
 */
+ (void)deleteObjectWithKey:(NSString *)key;


/**
 *  获取KeyChain中的数据
 *
 *  @param key      数据标识符key
 *  @return         object
 */
+ (id)getObjectWithKey:(NSString *)key;


@end

//
//  NSException+extend.m
//  NSObject+extend
//
//  Created by Steven on 15/4/24.
//  Copyright (c) 2015年 Neva. All rights reserved.
//

#import "NSException+extend.h"
#import "NSDate+extend.h"
#import "NSObjectMacro.h"
#import <objc/runtime.h>
#import "NSObject+extend.h"

#define errorLogFile [NSString stringWithFormat:@"%@/Documents/error.log",NSHomeDirectory()]
#define errorLogName @"error.log"
/// 已处理的日志目录
#define LOG_FILE_DIR_NEW    @"catch_exception/new"
/// 未处理的日志目录
#define LOG_FILE_DIR_OLD    @"catch_exception/old"

/// 异常处理对象
@interface HandleExceptionObject: NSObject
@property (nonatomic, strong) UncatchExceptionHandlerBlock handlerBlock;
@end
@implementation HandleExceptionObject

LX_GTMOBJECT_SINGLETON_BOILERPLATE(HandleExceptionObject);

+ (NSString *)GetPathForCaches:(NSString *)filename {
    NSArray * Paths = NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES);
    NSString * path = [Paths objectAtIndex:0];
    return [path stringByAppendingPathComponent:filename];
}

// 处理异常
- (void)catchException:(NSException *)e {
    NSString * logString = e.logString;
    myLog(@"%@",e.logString);

    //保存到本地  --  当然你可以在下次启动的时候，上传这个log
    [logString writeToFile:errorLogFile  atomically:YES encoding:NSUTF8StringEncoding error:nil];

    //回到未处理的日志
    
    // TODO
    if ([HandleExceptionObject shared].handlerBlock) {
       [HandleExceptionObject shared].handlerBlock(e.logString);
    }
    
   
}

@end

void UncatchExceptionHandlerFunction(NSException *e) {
   [[HandleExceptionObject shared] catchException:e];
}
void UncatchExceptionHandlerWriteToFile(NSException *e)
{
    NSString * logString = e.logString;
    myLog(@"%@",e.logString);
    
    //保存到本地  --  当然你可以在下次启动的时候，上传这个log
    [logString writeToFile:[NSString stringWithFormat:@"%@/Documents/error.log",NSHomeDirectory()]  atomically:YES encoding:NSUTF8StringEncoding error:nil];
  
}
/// NSException扩展
@implementation NSException (NSException_extend)

- (NSString *)logString {
    NSString * format = @"Date: %@\n*** Terminating app due to uncaught exception '%@', reason: '%@'\n*** First throw call stack:\n%@";
    return [NSString stringWithFormat:format, [[NSDate date] toString],[self name], [self reason], [self callStackSymbols]];
}
#pragma mark - 及时处理
+ (void)startUncatchExceptionWithHandlerBlock:(UncatchExceptionHandlerBlock)block {
    // 设置回调块
    [HandleExceptionObject shared].handlerBlock = block;
   
    // 启动捕获
    NSSetUncaughtExceptionHandler(&UncatchExceptionHandlerFunction);
}
#pragma mark - 保存为文件，下次启动时处理
+ (NSString *)errorBackAndstartUncatchException;

{
    // 启动捕获
    NSSetUncaughtExceptionHandler(&UncatchExceptionHandlerWriteToFile);
    
    return  [NSString stringWithContentsOfFile:errorLogFile encoding:NSUTF8StringEncoding error:NULL];
}
+(void)clearErrorLog{
    NSFileManager *defaultManager = [NSFileManager defaultManager];
    
    [defaultManager removeItemAtPath:errorLogFile error:nil];

}
@end

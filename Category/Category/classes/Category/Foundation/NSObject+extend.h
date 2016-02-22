//
//  NSObject+extend.h
//  NSObject+extend
//
//  Created by Steven on 14/12/11.
//  Copyright (c) 2014年 Neva. All rights reserved.
//
//
#import <UIKit/UIKit.h>
@interface NSObject (NSObject_extend)

/**
 *  扩展属性，用于保存必要的信息，基本类型请转成对象
 */
@property (nonatomic, strong) id userInfoExtend;

/**
 *  保存某个状态，比如数据模型的选中状态
 */
@property (nonatomic, assign) NSInteger ss_status;

/**
 *  本地对象序列化成json字符串
 *
 *  @return json字符串
 */
- (NSString *)JSONString;

/**
 *  本地对象序列化成json数据流
 *
 *  @return json数据流
 */
- (NSData *)JSONData;

/**
 *  json格式的 NSData 或 NSString 解析成本地对象
 *
 *  @return 本地对象
 */
- (id)objectFromJSON;

/**
 *  获取程序编译时间
 *
 *  @return NSDate
 */
+ (NSDate *)buildDate;

/**
 *  检测测试包超时
 *
 *  *** 记得重新编译，避免编译缓存 ***
 *
 *  @param time           测试的时间长度（从编译日期开始）(单位s), 设置为0时可以永久使用
 *  @param timeoutTitle   超时后弹出UIAlertView的title
 *  @param timeoutMessage 超时后弹出UIAlertView的message
 *
 *  @return 测试包是否超时
 */
+ (BOOL)checkTestTime:(NSTimeInterval)time timeoutTitle:(NSString *)timeoutTitle timeoutMessage:(NSString *)timeoutMessage;


/**************** 
 
 只执行一次的扩展
 
 ****************/

/**
 *  获取当前函数名的字符串,（作为-do_once_with_key:block:的key使用）
 *  使用这个宏生成的key，可以确保块在调用的函数中只执行一次
 */
#define do_once_in_this_function_key [NSString stringWithFormat:@"%s", __FUNCTION__]

/**
 *  在本对象生命周期内，使用key区分，如果key一样，只有第一个调用的位置会被执行，并且只会执行一次
 *
 *  @param key   用于区分的key
 *  @param block 执行的代码块
 */
- (void)do_once_with_key:(NSString *)key block:(void(^)(void))block;


#pragma mark - Sending messages with variable parameters
///=============================================================================
/// @name Sending messages with variable parameters
///=============================================================================

/**
 Sends a specified message to the receiver and returns the result of the message.
 
 @param sel    A selector identifying the message to send. If the selector is
 NULL or unrecognized, an NSInvalidArgumentException is raised.
 
 @param ...    Variable parameter list. Parameters type must correspond to the
 selector's method declaration, or unexpected results may occur.
 It doesn't support union or struct which is larger than 256 bytes.
 
 @return       An object that is the result of the message.
 
 @discussion   The selector's return value will be wrap as NSNumber or NSValue
 if the selector's `return type` is not object. It always returns nil
 if the selector's `return type` is void.
 
 Sample Code:
 
 // no variable args
 [view performSelectorWithArgs:@selector(removeFromSuperView)];
 
 // variable arg is not object
 [view performSelectorWithArgs:@selector(setCenter:), CGPointMake(0, 0)];
 
 // perform and return object
 UIImage *image = [UIImage.class performSelectorWithArgs:@selector(imageWithData:scale:), data, 2.0];
 
 // perform and return wrapped number
 NSNumber *lengthValue = [@"hello" performSelectorWithArgs:@selector(length)];
 NSUInteger length = lengthValue.unsignedIntegerValue;
 
 // perform and return wrapped struct
 NSValue *frameValue = [view performSelectorWithArgs:@selector(frame)];
 CGRect frame = frameValue.CGRectValue;
 */
- (id)performSelectorWithArgs:(SEL)sel, ...;

/**
 Invokes a method of the receiver on the current thread using the default mode after a delay.
 
 @warning      It can't cancelled by previous request.
 
 @param sel    A selector identifying the message to send. If the selector is
 NULL or unrecognized, an NSInvalidArgumentException is raised immediately.
 
 @param delay  The minimum time before which the message is sent. Specifying
 a delay of 0 does not necessarily cause the selector to be
 performed immediately. The selector is still queued on the
 thread's run loop and performed as soon as possible.
 
 @param ...    Variable parameter list. Parameters type must correspond to the
 selector's method declaration, or unexpected results may occur.
 It doesn't support union or struct which is larger than 256 bytes.
 
 Sample Code:
 
 // no variable args
 [view performSelectorWithArgs:@selector(removeFromSuperView) afterDelay:2.0];
 
 // variable arg is not object
 [view performSelectorWithArgs:@selector(setCenter:), afterDelay:0, CGPointMake(0, 0)];
 */
- (void)performSelectorWithArgs:(SEL)sel afterDelay:(NSTimeInterval)delay, ...;

/**
 Invokes a method of the receiver on the main thread using the default mode.
 
 @param sel    A selector identifying the message to send. If the selector is
 NULL or unrecognized, an NSInvalidArgumentException is raised.
 
 @param wait   A Boolean that specifies whether the current thread blocks until
 after the specified selector is performed on the receiver on the
 specified thread. Specify YES to block this thread; otherwise,
 specify NO to have this method return immediately.
 
 @param ...    Variable parameter list. Parameters type must correspond to the
 selector's method declaration, or unexpected results may occur.
 It doesn't support union or struct which is larger than 256 bytes.
 
 @return       While @a wait is YES, it returns object that is the result of
 the message. Otherwise return nil;
 
 @discussion   The selector's return value will be wrap as NSNumber or NSValue
 if the selector's `return type` is not object. It always returns nil
 if the selector's `return type` is void, or @a wait is YES.
 
 Sample Code:
 
 // no variable args
 [view performSelectorWithArgsOnMainThread:@selector(removeFromSuperView), waitUntilDone:NO];
 
 // variable arg is not object
 [view performSelectorWithArgsOnMainThread:@selector(setCenter:), waitUntilDone:NO, CGPointMake(0, 0)];
 */
- (id)performSelectorWithArgsOnMainThread:(SEL)sel waitUntilDone:(BOOL)wait, ...;

/**
 Invokes a method of the receiver on the specified thread using the default mode.
 
 @param sel    A selector identifying the message to send. If the selector is
 NULL or unrecognized, an NSInvalidArgumentException is raised.
 
 @param thread The thread on which to execute aSelector.
 
 @param wait   A Boolean that specifies whether the current thread blocks until
 after the specified selector is performed on the receiver on the
 specified thread. Specify YES to block this thread; otherwise,
 specify NO to have this method return immediately.
 
 @param ...    Variable parameter list. Parameters type must correspond to the
 selector's method declaration, or unexpected results may occur.
 It doesn't support union or struct which is larger than 256 bytes.
 
 @return       While @a wait is YES, it returns object that is the result of
 the message. Otherwise return nil;
 
 @discussion   The selector's return value will be wrap as NSNumber or NSValue
 if the selector's `return type` is not object. It always returns nil
 if the selector's `return type` is void, or @a wait is YES.
 
 Sample Code:
 
 [view performSelectorWithArgs:@selector(removeFromSuperView) onThread:mainThread waitUntilDone:NO];
 
 [array  performSelectorWithArgs:@selector(sortUsingComparator:)
 onThread:backgroundThread
 waitUntilDone:NO, ^NSComparisonResult(NSNumber *num1, NSNumber *num2) {
 return [num2 compare:num2];
 }];
 */
- (id)performSelectorWithArgs:(SEL)sel onThread:(NSThread *)thread waitUntilDone:(BOOL)wait, ...;

/**
 Invokes a method of the receiver on a new background thread.
 
 @param sel    A selector identifying the message to send. If the selector is
 NULL or unrecognized, an NSInvalidArgumentException is raised.
 
 @param ...    Variable parameter list. Parameters type must correspond to the
 selector's method declaration, or unexpected results may occur.
 It doesn't support union or struct which is larger than 256 bytes.
 
 @discussion   This method creates a new thread in your application, putting
 your application into multithreaded mode if it was not already.
 The method represented by sel must set up the thread environment
 just as you would for any other new thread in your program.
 
 Sample Code:
 
 [array  performSelectorWithArgsInBackground:@selector(sortUsingComparator:),
 ^NSComparisonResult(NSNumber *num1, NSNumber *num2) {
 return [num2 compare:num2];
 }];
 */
- (void)performSelectorWithArgsInBackground:(SEL)sel, ...;

/**
 Invokes a method of the receiver on the current thread after a delay.
 
 @warning     arc-performSelector-leaks
 
 @param sel   A selector that identifies the method to invoke. The method should
 not have a significant return value and should take no argument.
 If the selector is NULL or unrecognized,
 an NSInvalidArgumentException is raised after the delay.
 
 @param delay The minimum time before which the message is sent. Specifying a
 delay of 0 does not necessarily cause the selector to be performed
 immediately. The selector is still queued on the thread's run loop
 and performed as soon as possible.
 
 @discussion  This method sets up a timer to perform the aSelector message on
 the current thread's run loop. The timer is configured to run in
 the default mode (NSDefaultRunLoopMode). When the timer fires, the
 thread attempts to dequeue the message from the run loop and
 perform the selector. It succeeds if the run loop is running and
 in the default mode; otherwise, the timer waits until the run loop
 is in the default mode.
 */
- (void)performSelector:(SEL)sel afterDelay:(NSTimeInterval)delay;


#pragma mark - Swap method (Swizzling)
///=============================================================================
/// @name Swap method (Swizzling)
///=============================================================================

/**
 Swap two instance method's implementation in one class. Dangerous, be careful.
 
 @param originalSel   Selector 1.
 @param newSel        Selector 2.
 @return              YES if swizzling succeed; otherwise, NO.
 */
+ (BOOL)swizzleInstanceMethod:(SEL)originalSel with:(SEL)newSel;

/**
 Swap two class method's implementation in one class. Dangerous, be careful.
 
 @param originalSel   Selector 1.
 @param newSel        Selector 2.
 @return              YES if swizzling succeed; otherwise, NO.
 */
+ (BOOL)swizzleClassMethod:(SEL)originalSel with:(SEL)newSel;


#pragma mark - Associate value
///=============================================================================
/// @name Associate value
///=============================================================================

/**
 Associate one object to `self`, as if it was a strong property (strong, nonatomic).
 
 @param value   The object to associate.
 @param key     The pointer to get value from `self`.
 */
- (void)setAssociateValue:(id)value withKey:(void *)key;

/**
 Associate one object to `self`, as if it was a weak property (week, nonatomic).
 
 @param value  The object to associate.
 @param key    The pointer to get value from `self`.
 */
- (void)setAssociateWeakValue:(id)value withKey:(void *)key;

/**
 Get the associated value from `self`.
 
 @param key The pointer to get value from `self`.
 */
- (id)getAssociatedValueForKey:(void *)key;

/**
 Remove all associated values.
 */
- (void)removeAssociatedValues;


#pragma mark - Others
///=============================================================================
/// @name Others
///=============================================================================

/**
 Returns the class name in NSString.
 */
+ (NSString *)className;

/**
 Returns the class name in NSString.
 
 @discussion Apple has implemented this method in NSObject(NSLayoutConstraintCallsThis),
 but did not make it public.
 */
- (NSString *)className;

/**
 Returns a copy of the instance with `NSKeyedArchiver` and ``NSKeyedUnarchiver``.
 Returns nil if an error occurs.
 */
- (id)deepCopy;

/**
 Returns a copy of the instance use archiver and unarchiver.
 Returns nil if an error occurs.
 
 @param archiver   NSKeyedArchiver class or any class inherited.
 @param unarchiver NSKeyedUnarchiver clsas or any class inherited.
 */
- (id)deepCopyWithArchiver:(Class)archiver unarchiver:(Class)unarchiver;


/**
 Registers a block to receive KVO notifications for the specified key-path
 relative to the receiver.
 
 @discussion The block and block captured objects are retained. Call
 `removeObserverBlocksForKeyPath:` or `removeObserverBlocks` to release.
 
 @param keyPath The key path, relative to the receiver, of the property to
 observe. This value must not be nil.
 
 @param block   The block to register for KVO notifications.
 */
- (void)addObserverBlockForKeyPath:(NSString*)keyPath block:(void (^)(__weak id obj, id oldVal, id newVal))block;

/**
 Stops all blocks (associated by `addObserverBlockForKeyPath:block:`) from
 receiving change notifications for the property specified by a given key-path
 relative to the receiver, and release these blocks.
 
 @param keyPath A key-path, relative to the receiver, for which blocks is
 registered to receive KVO change notifications.
 */
- (void)removeObserverBlocksForKeyPath:(NSString*)keyPath;

/**
 Stops all blocks (associated by `addObserverBlockForKeyPath:block:`) from
 receiving change notifications, and release these blocks.
 */
- (void)removeObserverBlocks;


@end
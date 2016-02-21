//
//  UIView+extend.h
//  NSObject+extend
//
//  Created by Steven on 14/12/10.
//  Copyright (c) 2014年 Neva. All rights reserved.
//

#import <UIKit/UIKit.h>
/**
 *  方向类型
 */

typedef enum{
    
    //上
    UIViewBorderDirectTop=0,
    
    //左
    UIViewBorderDirectLeft,
    
    //下
    UIViewBorderDirectBottom,
    
    //右
    UIViewBorderDirectRight,
    
    
}UIViewBorderDirect;
@interface UIView (UIView_extend)

@property (nonatomic, assign) CGFloat filletRadius;
@property (nonatomic, assign) CGFloat width;
@property (nonatomic, assign) CGFloat height;
@property (nonatomic, assign) CGFloat Y;
@property (nonatomic, assign) CGFloat X;
@property (assign, nonatomic) CGFloat centerX;

@property (nonatomic) CGFloat left;        ///< Shortcut for frame.origin.x.
@property (nonatomic) CGFloat top;         ///< Shortcut for frame.origin.y
@property (nonatomic) CGFloat right;       ///< Shortcut for frame.origin.x + frame.size.width
@property (nonatomic) CGFloat bottom;      ///< Shortcut for frame.origin.y + frame.size.height

@property (nonatomic) CGFloat centerY;     ///< Shortcut for center.y
@property (nonatomic) CGPoint origin;      ///< Shortcut for frame.origin.
@property (nonatomic) CGSize  size;        ///< Shortcut for frame.size.
/**
 *  所在控制器
 */
@property(nonatomic,readonly)id viewController;
/**
 *  中心位置
 */
- (void)centerInSuperView;
/**
 *  审美位置
 */
- (void)centerAestheticInSuperView;
/**
 *  清除所有subView
 */
-(void)clearAllSubView;

/**
 *  获取所有subView
 *
 *  @return UIView Array
 */
-(NSArray *)allSubViews;

/**
 *  遍历所有subView取消其焦点,收回键盘
 */
-(void)resignResponder;

/**
 *  获取UIView的截图
 *
 *  @return UIImage 图片的width和heigh，会乘以 [UIScreen mainScreen].scale
 */
- (UIImage *)imageSnapshot;

/**
 *  限制 UIView 的宽度，计算出autolayout后的高度
 *
 */
- (CGFloat)viewHeightWithLimitWidth:(CGFloat)limitWidth;
#pragma mark - 调试
/**
 *  调试
 */
-(void)debugWithColor:(UIColor *)color width:(CGFloat)width;

/**
 *  自动从xib创建视图
 */
+(instancetype)viewFromXIB;
/**
 *  添加边框：注给scrollView添加会出错
 *
 *  @param direct 方向
 *  @param color  颜色
 *  @param width  线宽
 */
-(void)addSingleBorder:(UIViewBorderDirect)direct color:(UIColor *)color width:(CGFloat)width;


#pragma mark  视图形状处理
/**
 *  添加边框
 */
-(void)setBorder:(UIColor *)color width:(CGFloat)width;

/**
 *  圆角
 */
-(void)setRadius:(CGFloat)r;



@end

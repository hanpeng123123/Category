//
//  UIImage-Extensions.h
//
//  Created by Hardy Macia on 7/1/09.
//  Copyright 2009 Catamount Software. All rights reserved.
//

#import <UIKit/UIKit.h>


/*
 *  水印方向
 */
typedef enum {
    
    //左上
    ImageWaterDirectTopLeft=0,
    
    //右上
    ImageWaterDirectTopRight,
    
    //左下
    ImageWaterDirectBottomLeft,
    
    //右下
    ImageWaterDirectBottomRight,
    
    //正中
    ImageWaterDirectCenter
    
}ImageWaterDirect;






@interface UIImage (UIImage_extend)


/*
 *  圆形图片
 */
@property (nonatomic,strong,readonly) UIImage *roundImage;
/**
*  使用颜色生成1*1的图像0
*
*  @param color UIColor
*
*  @return UIImage
*/


+ (UIImage *)imageWithColor:(UIColor *)color;
/**
 Rounds a new image with a given corner size.
 
 @param radius       The radius of each corner oval. Values larger than half the
 rectangle's width or height are clamped appropriately to
 half the width or height.
 
 @param borderWidth  The inset border line width. Values larger than half the rectangle's
 width or height are clamped appropriately to half the width
 or height.
 
 @param borderColor  The border stroke color. nil means clear color.
 */
- (UIImage *)imageByRoundCornerRadius:(CGFloat)radius
                          borderWidth:(CGFloat)borderWidth
                          borderColor:(UIColor *)borderColor;


/**
 *  截取部分图像，包括旋转
 *
 *  @param rect 截取区域
 *
 *  @return 截取出来的UIImage对象
 */
- (UIImage *)imageAtRect:(CGRect)rect;

/**
 *  生成重新调整大小的图像
 *
 *  @param reSize 新大小
 *
 *  @return UIImage
 */
- (UIImage *)imageResize:(CGSize)reSize;

/**
 *  生成等比例缩放图片
 *
 *  @param scale 缩放比例
 *
 *  @return 缩放后的UIImage对象
 */
- (UIImage *)imageToScale:(CGFloat)scale;


/**
 *  限制图片的最大长度,自动将最长边限制在maxLength之内，另一个边等比缩放
 *
 *  @param maxLength 最长边
 *
 *  @return UIImage
 */
- (UIImage *)autoScaleWithMaxLength:(CGFloat)maxLength;

/**
 *  保存UIImage对象到文件，jpg、png，通过路径文件后缀名保存格式
 *
 *  @param aPath 保存的绝对路径
 *
 *  @return 保存成功返回YES
 */
- (BOOL)writeToFile:(NSString *)aPath;


/**
 *  保存相册
 *
 *  @param completeBlock 成功回调
 *  @param completeBlock 出错回调
 */
-(void)savedPhotosAlbum:(void(^)())completeBlock failBlock:(void(^)())failBlock;
/**
 *图片方向矫正
 *
 *  @return 矫正后图片
 */
-(UIImage *)fixOrientation;


#pragma  mark - 水印

-(UIImage *)waterWithText:(NSString *)text direction:(ImageWaterDirect)direction fontColor:(UIColor *)fontColor fontPoint:(CGFloat)fontPoint marginXY:(CGPoint)marginXY;


-(UIImage *)waterWithWaterImage:(UIImage *)waterImage direction:(ImageWaterDirect)direction waterSize:(CGSize)waterSize  marginXY:(CGPoint)marginXY;

#pragma  mark - 图像拉伸

/**
 *  生成一个中心拉伸的图片
 *
 *  @param name 图片资源名字
 *
 *  @return UIImage
 */
+ (instancetype)imageStretchableCenterNamed:(NSString *)name;

/// 基于self，生成一个中心拉伸的图片
- (UIImage *)imageStretchableCenter;


#pragma mark - Image Effect
///=============================================================================
/// @name Image Effect
///=============================================================================

/**
 Tint the image in alpha channel with the given color.
 
 @param color  The color.
 */
- (UIImage *)imageByTintColor:(UIColor *)color;

/**
 Returns a grayscaled image.
 */
- (UIImage *)imageByGrayscale;

/**
 Applies a blur effect to this image. Suitable for blur any content.
 */
- (UIImage *)imageByBlurSoft;

/**
 Applies a blur effect to this image. Suitable for blur any content except pure white.
 (same as iOS Control Panel)
 */
- (UIImage *)imageByBlurLight;

/**
 Applies a blur effect to this image. Suitable for displaying black text.
 (same as iOS Navigation Bar White)
 */
- (UIImage *)imageByBlurExtraLight;

/**
 Applies a blur effect to this image. Suitable for displaying white text.
 (same as iOS Notification Center)
 */
- (UIImage *)imageByBlurDark;

/**
 Applies a blur and tint color to this image.
 
 @param tintColor  The tint color.
 */
- (UIImage *)imageByBlurWithTint:(UIColor *)tintColor;

/**
 Applies a blur, tint color, and saturation adjustment to this image,
 optionally within the area specified by @a maskImage.
 
 @param blurRadius     The radius of the blur in points, 0 means no blur effect.
 
 @param tintColor      An optional UIColor object that is uniformly blended with
 the result of the blur and saturation operations. The
 alpha channel of this color determines how strong the
 tint is. nil means no tint.
 
 @param tintBlendMode  The @a tintColor blend mode. Default is kCGBlendModeNormal (0).
 
 @param saturation     A value of 1.0 produces no change in the resulting image.
 Values less than 1.0 will desaturation the resulting image
 while values greater than 1.0 will have the opposite effect.
 0 means gray scale.
 
 @param maskImage      If specified, @a inputImage is only modified in the area(s)
 defined by this mask.  This must be an image mask or it
 must meet the requirements of the mask parameter of
 CGContextClipToMask.
 
 @return               image with effect, or nil if an error occurs (e.g. no
 enough memory).
 */
- (UIImage *)imageByBlurRadius:(CGFloat)blurRadius
                     tintColor:(UIColor *)tintColor
                      tintMode:(CGBlendMode)tintBlendMode
                    saturation:(CGFloat)saturation
                     maskImage:(UIImage *)maskImage;


@end


@interface UIImageView ( UIImageView_Stretchable )

/// 拉伸图片中心
- (void)stretchableImageCenter;


@end


@interface UIButton ( UIButton_Stretchable )

/// 中心拉伸所有状态下BackgroundImage
- (void)stretchableBackgroundImageCenter;

/// 中心拉伸指定状态下BackgroundImage
- (void)stretchableBackgroundImageCenterForState:(UIControlState)state;


@end
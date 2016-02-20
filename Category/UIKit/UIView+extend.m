//
//  UIView+extend.m
//  NSObject+extend
//
//  Created by Steven on 14/12/10.
//  Copyright (c) 2014年 Neva. All rights reserved.
//

#import "UIView+extend.h"
#import <QuartzCore/QuartzCore.h>

@implementation UIView (UIView_extend)

- (void)setFilletRadius:(CGFloat)filletRadius
{
    self.layer.cornerRadius = filletRadius;
    self.clipsToBounds = YES;
}

- (CGFloat)filletRadius {
    return self.layer.cornerRadius;
}

-(void)clearAllSubView{
    for (UIView * subView in [self subviews]) {
        if ([[subView subviews] count] > 0) {
            for (UIView * s in [subView subviews]) {
                [s clearAllSubView];
            }
        }
        [subView removeFromSuperview];
    }
}
-(NSArray *)allSubViews {
    NSMutableArray * items = [NSMutableArray array];
    for (UIView * v in [self subviews]) {
        [items addObject:v];
        if ([[v subviews] count] > 0) {
            [items addObjectsFromArray:[v allSubViews]];
        }
    }
    return [NSArray arrayWithArray:items];
}

-(void)resignResponder {
    if ([self isKindOfClass:[UITextField class]]) {
        [(UITextField *)self resignFirstResponder];
    }
    if ([self isKindOfClass:[UITextView class]]) {
        [(UITextView *)self resignFirstResponder];
    }
    if ([[self subviews] count] > 0) {
        for (UIView * v in [self subviews]) {
            [v resignResponder];
        }
    }
}

- (UIImage *)imageSnapshot
{
    UIGraphicsBeginImageContextWithOptions(CGSizeMake(self.bounds.size.width, self.bounds.size.height), NO, [UIScreen mainScreen].scale);
    [self.layer renderInContext:UIGraphicsGetCurrentContext()];
    UIImage *viewImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    UIImageWriteToSavedPhotosAlbum(viewImage, nil, nil, nil);
    return viewImage;
}

-(void)setHeight:(CGFloat)height {
    CGRect rect = [self frame];
    rect.size.height = height;
    [self setFrame:rect];
}
-(CGFloat)height {
    return self.frame.size.height;
}
-(void)setWidth:(CGFloat)width {
    CGRect rect = [self frame];
    rect.size.width = width;
    [self setFrame:rect];
}
-(CGFloat)width {
    return self.frame.size.width;
}
-(void)setX:(CGFloat)x {
    CGRect rect = [self frame];
    rect.origin.x = x;
    [self setFrame:rect];
}
-(CGFloat)X {
    return self.frame.origin.x;
}
-(void)setY:(CGFloat)y {
    CGRect rect = [self frame];
    rect.origin.y = y;
    [self setFrame:rect];
}
-(CGFloat)Y {
    return self.frame.origin.y;
}
-(CGFloat)centerX
{
    return self.center.x;
}
-(void)setCenterX:(CGFloat)centerX
{
    CGPoint center = self.center;
    center.x =centerX;
    self.center = center;
}


-(CGFloat)maxY
{
    return (self.height +self.Y);
    
}
-(void)setMaxY:(CGFloat)maxY
{
    if (self.Y && !self.height) {
        self.height = maxY - self.Y;
    }else if (!self.Y && self.height){
        self.Y = maxY - self.height;
    }
    
}

- (CGFloat)viewHeightWithLimitWidth:(CGFloat)limitWidth
{
    self.bounds = CGRectMake(0.0f, 0.0f, limitWidth, CGRectGetHeight(self.bounds));
    
    [self layoutIfNeeded];
    
    for (UILabel * lab in self.allSubViews)
    {
        if ([lab isKindOfClass:UILabel.class])
        {
            lab.preferredMaxLayoutWidth = lab.bounds.size.width;
        }
    }
    
    return [self systemLayoutSizeFittingSize:UILayoutFittingCompressedSize].height;
}


#pragma mark frame方法
/**
 *  中心位置
 */
- (void)centerInSuperView {
    double xPos = round((self.superview.frame.size.width - self.frame.size.width) / 2.0);
    double yPos = round((self.superview.frame.size.height - self.frame.size.height) / 2.0);
    self.X =xPos;
    self.Y =yPos;
    
}
/**
 *  审美位置
 */
- (void)centerAestheticInSuperView {
    self.X = round(([self.superview width] - [self width]) / 2.0);
    self.Y = round(([self.superview height] - [self height]) / 2.0) - ([self.superview height] / 8.0);
    
}
#pragma mark - 调试
/**
 *  调试
 */
-(void)debugWithColor:(UIColor *)color width:(CGFloat)width
{
    [self setBorder:color width:width];
}

#pragma mark - 视图控制

/**
 *  添加边框：注给scrollView添加会出错
 *
 *  @param direct 方向
 *  @param color  颜色
 *  @param width  线宽
 */
-(void)addSingleBorder:(UIViewBorderDirect)direct color:(UIColor *)color width:(CGFloat)width{
    
    UIView *line=[[UIView alloc] init];
    
    //设置颜色
    line.backgroundColor=color;
    
    //添加
    [self addSubview:line];
    
    //禁用ar
    line.translatesAutoresizingMaskIntoConstraints=NO;
    
    NSDictionary *views=NSDictionaryOfVariableBindings(line);
    NSDictionary *metrics=@{@"w":@(width),@"y":@(self.height - width),@"x":@(self.width - width)};
    
    
    NSString *vfl_H=@"";
    NSString *vfl_W=@"";
    
    //上
    if(UIViewBorderDirectTop==direct){
        vfl_H=@"H:|-0-[line]-0-|";
        vfl_W=@"V:|-0-[line(==w)]";
    }
    
    //左
    if(UIViewBorderDirectLeft==direct){
        vfl_H=@"H:|-0-[line(==w)]";
        vfl_W=@"V:|-0-[line]-0-|";
    }
    
    //下
    if(UIViewBorderDirectBottom==direct){
        vfl_H=@"H:|-0-[line]-0-|";
        vfl_W=@"V:[line(==w)]-0-|";
    }
    
    //右
    if(UIViewBorderDirectRight==direct){
        vfl_H=@"H:|-x-[line(==w)]";
        vfl_W=@"V:|-0-[line]-0-|";
    }
    
    
    [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:vfl_H options:0 metrics:metrics views:views]];
    [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:vfl_W options:0 metrics:metrics views:views]];
}


/**
 *  自动从xib创建视图
 */
+(instancetype)viewFromXIB{
    
    NSString *name=NSStringFromClass(self);
    
    UIView *xibView=[[[NSBundle mainBundle] loadNibNamed:name owner:nil options:nil] firstObject];
    
    if(xibView==nil){
        NSLog(@"CoreXibView：从xib创建视图失败，当前类是：%@",name);
    }
    
    return xibView;
}

-(id)controller {
    Class vcc = [UIViewController class];
    UIResponder *responder = self;
    while ((responder = [responder nextResponder]))
        if ([responder isKindOfClass: vcc])
            return (UIViewController *)responder;
    return nil;
}
#pragma mark  视图形状处理
/**
 *  添加边框
 */
-(void)setBorder:(UIColor *)color width:(CGFloat)width{
    CALayer *layer=self.layer;
    layer.borderColor=color.CGColor;
    layer.borderWidth=width;
}
/**
 *  圆角
 */
-(void)setRadius:(CGFloat)r{
    
    if(r<=0) r=self.frame.size.width * .5f;
    
    //圆角半径
    self.layer.cornerRadius=r;
    
    //强制
    self.layer.masksToBounds=YES;
}



@end

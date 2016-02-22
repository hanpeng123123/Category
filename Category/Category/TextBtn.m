//
//  TextBtn.m
//  Category
//
//  Created by hanpeng on 16-2-22.
//  Copyright (c) 2016年 hanpeng. All rights reserved.
//

#import "TextBtn.h"
#import "NSObjectExtend.h"
@implementation TextBtn

- (instancetype)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        UIButton * btn = [[UIButton alloc]initWithFrame:CGRectMake(0, 0, 50, 50)];
        [self addSubview:btn];
        [self setAssociateValue:btn withKey:@"btn1"];
    }
    return self;
}

-(void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{


}

@end

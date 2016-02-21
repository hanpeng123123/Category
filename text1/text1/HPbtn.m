//
//  HPbtn.m
//  text1
//
//  Created by hanpeng on 16-2-21.
//  Copyright (c) 2016年 hanpeng. All rights reserved.
//

#import "HPbtn.h"
#import "NSObjectExtend.h"
#import "ViewController.h"
@implementation HPbtn

- (instancetype)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        UIButton * btn = [UIButton buttonWithTitle:@"我是按钮" target:self touchUpInsideAction:@selector(didClickBtn)];
        btn.backgroundColor = [UIColor blackColor];
        btn.center = self.center;
        [self addSubview:btn];
           }
    return self;
}


-(void)didClickBtn
{
    self.contentScaleFactor = 0.5;
  
}
@end

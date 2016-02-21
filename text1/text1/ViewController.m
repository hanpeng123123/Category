//
//  ViewController.m
//  text1
//
//  Created by hanpeng on 16-2-21.
//  Copyright (c) 2016年 hanpeng. All rights reserved.
//

#import "ViewController.h"
#import "NSObjectExtend.h"
#import "HPbtn.h"
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
}

-(void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
    
    HPbtn * hp = [[HPbtn alloc]initWithFrame:CGRectMake(0, 0, 300, 300)];
    hp.backgroundColor =[ UIColor redColor];
    [self.view addSubview:hp];
}



@end

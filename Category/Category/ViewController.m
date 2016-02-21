//
//  ViewController.m
//  Category
//
//  Created by hanpeng on 16-2-20.
//  Copyright (c) 2016年 hanpeng. All rights reserved.
//

#import "ViewController.h"
#import "NSObjectExtend.h"
@interface ViewController ()
@property(nonatomic,weak)UIImageView * imageview;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    UIButton * btn = [[UIButton alloc]initWithFrame:CGRectMake(50, 50, 200, 200)];
    [btn addTarget:self action:@selector(click1) forControlEvents:UIControlEventTouchUpInside];
    btn.backgroundColor = [UIColor redColor];
     [btn setTarget:self action:@selector(click2) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:btn];
   
}

-(void)click1
{

    NSLog(@"1");
}
-(void)click2
{
    
    NSLog(@"2");
}

@end

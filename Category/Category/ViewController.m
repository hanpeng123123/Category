//
//  ViewController.m
//  Category
//
//  Created by hanpeng on 16-2-20.
//  Copyright (c) 2016年 hanpeng. All rights reserved.
//

#import "ViewController.h"
#import "NSObjectExtend.h"
#import "TextBtn.h"
#import "TextViewController.h"


@interface ViewController ()
@property(nonatomic,weak)UIImageView * imageview;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    
    TextBtn * btn = [[TextBtn alloc]initWithFrame:CGRectMake(50, 50, 200, 200)];
    btn.backgroundColor = rgba(254, 25, 23, 0.5);
    
   
    
    NSLog(@"%u",btn.backgroundColor.rgbaValue);
  
    [btn addObserverBlockForKeyPath:@"frame" block:^(__weak id obj, id oldVal, id newVal) {
      
        NSLog(@"%@----%@-----%@",obj,oldVal,newVal);
    }];
    
 
    
    
   [self setAssociateValue:btn withKey:@"btn"];
   
    
//    btn.backgroundColor = [UIColor redColor];
//    [btn setTarget:self action:@selector(click2:) forControlEvents:UIControlEventTouchUpInside];
//    
//    UITableView * tab = [[UITableView alloc]init];
//  NSLog(@"%@", [UITableView buildDate] );
//    [self addObserver:self forKeyPath:@"btnBan" options:NSKeyValueObservingOptionNew |NSKeyValueObservingOptionOld context:nil];
    
}

-(void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
    [[self getAssociatedValueForKey:@"btn"] setFrame:CGRectMake(250, 250, 50, 50)];

   

}
-(void)click2:(UIButton * )btn
{
   
   btn.backgroundColor = [UIColor blackColor];
}
-(void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary *)change context:(void *)context
{
    if ([keyPath  isEqual:@"btnBan"]) {
        NSLog(@"%@",change);
    }

}

@end

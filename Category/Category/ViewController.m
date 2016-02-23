//
//  ViewController.m
//  Category
//
//  Created by hanpeng on 16-2-20.
//  Copyright (c) 2016年 hanpeng. All rights reserved.
//

#import "ViewController.h"
#import "NSObjectExtend.h"
#import "TextViewController.h"
#import "singletonVIew.h"
#import <MessageUI/MFMailComposeViewController.h>
@interface ViewController ()<MFMailComposeViewControllerDelegate>
@property(nonatomic,weak)UIImageView * imageview;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    [self textBtn];
    
    
    
    
    
}
-(void)textview
{
    
    singletonVIew * view1 = [[singletonVIew alloc]init];
    [self.view addSubview:view1];
    view1.backgroundColor = rgb(100, 100, 100);
    view1.frame = CGRectMake(0, 0, 200, 200);
   [self.view addSubview:view1];
    [self setAssociateValue:view1 withKey:@"btn"];
    

}
-(void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
    NSLog(@"%@", [self getAssociatedValueForKey:@"btn"]);
 
    
    
    
}-(void)textBtn
{
    
    UIButton * btn = [UIButton buttonWithTitle:@"我是按钮" target:self touchUpInsideAction:@selector(click2:)];
    
    btn.frame =CGRectMake(50, 50, 200, 200);
    btn.backgroundColor = rgba(254, 25, 23, 0.5);
    btn.center = CGPointMake(250, 250);

    [self.view addSubview:btn];
    [btn setBorder:rgb(0, 0, 0) width:2];
    [btn setRadius:5];
    
    [btn addObserverBlockForKeyPath:@"frame" block:^(__weak id obj, id oldVal, id newVal) {
        
        NSLog(@"%@----%@-----%@",obj,oldVal,newVal);
    }];

    [self setAssociateValue:btn withKey:@"btn"];
    


}


-(void)click2:(UIButton * )btn
{
    
       

}
-(void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary *)change context:(void *)context
{
    if ([keyPath  isEqual:@"btnBan"]) {
        NSLog(@"%@",change);
    }

}

- (void)mailComposeController:(MFMailComposeViewController*)controller
          didFinishWithResult:(MFMailComposeResult)result
                        error:(NSError*)error;
{
    if (result == MFMailComposeResultSent) {
        NSLog(@"It's away!");
    }
    [controller dismissViewControllerAnimated:YES completion:nil];
} ;

@end

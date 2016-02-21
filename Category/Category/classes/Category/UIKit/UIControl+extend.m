//
//  UIControl+extend.m
//  Category
//
//  Created by hanpeng on 16-2-21.
//  Copyright (c) 2016年 hanpeng. All rights reserved.
//

#import "UIControl+extend.h"

@implementation UIControl (extend)

- (void)setTarget:(id)target action:(SEL)action forControlEvents:(UIControlEvents)controlEvents {
    if (!target || !action || !controlEvents) return;
    NSSet *targets = [self allTargets];
    for (id currentTarget in targets) {
        NSArray *actions = [self actionsForTarget:currentTarget forControlEvent:controlEvents];
        for (NSString *currentAction in actions) {
            [self removeTarget:currentTarget action:NSSelectorFromString(currentAction)
              forControlEvents:controlEvents];
        }
    }
    [self addTarget:target action:action forControlEvents:controlEvents];
}

@end

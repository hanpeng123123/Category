//
//  UIBarButtonItem+extend.h
//  Category
//
//  Created by hanpeng on 16-2-21.
//  Copyright (c) 2016年 hanpeng. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIBarButtonItem (extend)
/**
 The block that invoked when the item is selected. The objects captured by block
 will retained by the ButtonItem.
 
 @discussion This param is conflict with `target` and `action` property.
 Set this will set `target` and `action` property to some internal objects.
 */
@property (nonatomic, copy) void (^actionBlock)(id);
@end

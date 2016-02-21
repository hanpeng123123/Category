//
//  UITextField+extend.h
//  NSObject+extend
//
//  Created by Steven on 15/3/16.
//  Copyright (c) 2015年 Neva. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UITextField (UITextField_extend)

/// 左内边距
@property (nonatomic, assign) CGFloat paddingLeft;

/// 右内边距
@property (nonatomic, assign) CGFloat paddingRight;

/**
 Set all text selected.
 */
- (void)selectAllText;

/**
 Set text in range selected.
 
 @param range  The range of selected text in a document.
 */
- (void)setSelectedRange:(NSRange)range;
@end

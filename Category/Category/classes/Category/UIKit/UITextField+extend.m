//
//  UITextField+extend.m
//  NSObject+extend
//
//  Created by Steven on 15/3/16.
//  Copyright (c) 2015年 Neva. All rights reserved.
//

#import "UITextField+extend.h"

@implementation UITextField (UITextField_extend)

- (void)setPaddingLeft:(CGFloat)paddingLeft {
    CGRect frame = self.frame;
    frame.size.width = paddingLeft;
    UIView *leftview = [[UIView alloc] initWithFrame:frame];
    self.leftViewMode = UITextFieldViewModeAlways;
    self.leftView = leftview;
}
- (CGFloat)paddingLeft {
    return self.leftView.frame.size.width;
}


- (void)setPaddingRight:(CGFloat)paddingRight {
    CGRect frame = self.frame;
    frame.size.width = paddingRight;
    UIView *rightview = [[UIView alloc] initWithFrame:frame];
    self.leftViewMode = UITextFieldViewModeAlways;
    self.leftView = rightview;
}
- (CGFloat)paddingRight {
    return self.rightView.frame.size.width;
}
- (void)selectAllText {
    UITextRange *range = [self textRangeFromPosition:self.beginningOfDocument toPosition:self.endOfDocument];
    [self setSelectedTextRange:range];
}

- (void)setSelectedRange:(NSRange)range {
    UITextPosition *beginning = self.beginningOfDocument;
    UITextPosition *startPosition = [self positionFromPosition:beginning offset:range.location];
    UITextPosition *endPosition = [self positionFromPosition:beginning offset:NSMaxRange(range)];
    UITextRange *selectionRange = [self textRangeFromPosition:startPosition toPosition:endPosition];
    [self setSelectedTextRange:selectionRange];
}

@end

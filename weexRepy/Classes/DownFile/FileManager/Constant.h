//
//  constant.h
//  WeexEros
//
//  Created by ford Gao on 2018/7/11.
//  Copyright © 2018年 benmu. All rights reserved.
//

#import <Foundation/Foundation.h>


#define strIsEmpty(str)      (str==nil || [str length]==0 || [[str stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] length] == 0)
#define root [UIApplication sharedApplication].keyWindow.rootViewController

extern NSString * DocumentsDirectory();
extern NSString * CachesDirectory();
extern NSString *const contactFile;
extern NSString *const contactFlag;


//
//  ShareManager.h
//  WeexEros
//
//  Created by ford Gao on 2018/7/11.
//  Copyright © 2018年 benmu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface ShareManager : NSObject

+ (void)shareFile: (NSString *)filePath handler: (UIActivityViewControllerCompletionWithItemsHandler)handler;

@end

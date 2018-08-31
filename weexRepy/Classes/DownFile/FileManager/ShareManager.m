//
//  ShareManager.m
//  WeexEros
//
//  Created by ford Gao on 2018/7/11.
//  Copyright © 2018年 benmu. All rights reserved.
//

#import "ShareManager.h"

@implementation ShareManager

+ (void)shareFile: (NSString *)filePath handler: (UIActivityViewControllerCompletionWithItemsHandler)handler{
    
    //文件链接
    NSURL *urlToShare = [NSURL fileURLWithPath:filePath];
    //文件二进制数据
    NSData *data = [NSData dataWithContentsOfFile:filePath];
    
    NSArray *activityItems = @[data, urlToShare];
    UIActivityViewController *activityVC = [[UIActivityViewController alloc]initWithActivityItems:activityItems applicationActivities:nil];
    //不出现在活动项目
    activityVC.excludedActivityTypes = @[UIActivityTypePrint, UIActivityTypeCopyToPasteboard,UIActivityTypeAssignToContact,UIActivityTypeSaveToCameraRoll];
    [[UIApplication sharedApplication].delegate.window.rootViewController presentViewController:activityVC animated:YES completion:nil];
    // 分享之后的回调
    activityVC.completionWithItemsHandler = ^(UIActivityType  _Nullable activityType, BOOL completed, NSArray * _Nullable returnedItems, NSError * _Nullable activityError) {
        handler(activityType, completed, returnedItems, activityError);
    };
}


@end

//
//  BsFileManagerModule.m
//  WeexEros
//
//  Created by ford Gao on 2018/5/18.
//  Copyright © 2018年 benmu. All rights reserved.
//

#import "BsFileManagerModule.h"
#import "BsFileManager.h"
#import "PreviewViewController.h"
#import "Constant.h"
#import <WeexPluginLoader/WeexPluginLoader.h>

@implementation BsFileManagerModule
@synthesize weexInstance;
WX_PlUGIN_EXPORT_COMPONENT(fileManager, BsFileManager)
WX_EXPORT_METHOD(@selector(fileExist:callback:))
WX_EXPORT_METHOD(@selector(downloadFile:success:failure:progress:))
WX_EXPORT_METHOD(@selector(previewFile:))
WX_EXPORT_METHOD(@selector(clearCaches:))
WX_EXPORT_METHOD(@selector(getCachesSize:))
/*
 params: {
        url:   下载地址
        fileName:   存储名称
        param:  下载参数
 }
 */
- (void)downloadFile: (NSDictionary *)params  success: (WXModuleKeepAliveCallback)success failure: (WXModuleKeepAliveCallback)failure progress: (WXModuleKeepAliveCallback)progress{
    
    [BsFileManager downloadFile: params downloadSuccess:^(NSURLResponse *response, NSURL *filePath) {
        success(@{}, YES);
    } downloadFailure:^(NSError *error) {
        failure(error.userInfo, YES);
    } downloadProgress:^(NSProgress *downloadProgress) {
        dispatch_async(dispatch_get_main_queue(), ^{
            // 设置进度条的百分比
            progress(@{@"progress": [NSNumber numberWithFloat:1.0 * downloadProgress.completedUnitCount / downloadProgress.totalUnitCount]}, YES);
        });
    }];
    
}


/**
 文件是否存在

 @param params 文件信息
 @param callback 文件存在
 */
- (void)fileExist: (NSDictionary *)params callback:(WXModuleCallback)callback{
    
    BOOL isFileExist = [BsFileManager isFileExist: params];
    NSMutableDictionary *dict = [[NSMutableDictionary alloc] init];
    dict[@"result"] = [NSNumber numberWithBool:isFileExist];
    callback(dict);
}

- (void)previewFile: (NSDictionary *)params{
    
    [BsFileManager previewFile:params];
}

- (void)clearCaches: (WXModuleCallback)callback {
    [BsFileManager removeDirectoryPath:CachesDirectory()];
    [BsFileManager removeDirectoryPath:DocumentsDirectory()];
    [BsFileManager getFileSize:DocumentsDirectory() completion:^(NSInteger totalSize) {
        if (totalSize == 0) {
            callback(@{@"result": [NSNumber numberWithBool:YES]});
        }else{
            callback(@{@"result": [NSNumber numberWithBool:NO]});
        }
    }];
}

- (void)getCachesSize: (WXModuleCallback)callback {
    
    
    [BsFileManager getFileSize:CachesDirectory() completion:^(NSInteger totalSize) {
        NSInteger __block size = totalSize;
        [BsFileManager getFileSize:DocumentsDirectory() completion:^(NSInteger total) {
            size +=total;
            callback(@{@"size": [BsFileManager cacheSizeStr:size]});
        }];
    }];
}


@end

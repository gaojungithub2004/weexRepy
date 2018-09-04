//
//  BsFileManager.h
//  WeexEros
//
//  Created by ford Gao on 2018/5/18.
//  Copyright © 2018年 benmu. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BsFileManager : NSObject

+ (void)downloadFile:(NSDictionary *)params
            downloadSuccess:(void (^)(NSURLResponse *response, NSURL *filePath))success
            downloadFailure:(void (^)(NSError *error))failure
           downloadProgress:(void (^)(NSProgress *downloadProgress))progress;

+ (BOOL) isFileExist: (NSDictionary *)params;

+ (void)removeDirectoryPath:(NSString *)directoryPath;

+ (void)getFileSize:(NSString *)directoryPath completion:(void(^)(NSInteger totalSize))completion;
+ (NSString *)cacheSizeStr: (NSInteger)totalSize;

+ (void)previewFile: (NSDictionary *)params;

@end

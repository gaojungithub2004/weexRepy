//
//  constant.m
//  WeexEros
//
//  Created by ford Gao on 2018/7/11.
//  Copyright © 2018年 benmu. All rights reserved.
//

#import "Constant.h"

//DocumentsDirectory
inline NSString * DocumentsDirectory(){
    return [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0];
}

//CachesDirectory
inline NSString * CachesDirectory(){
    return [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) objectAtIndex:0];
}

NSString *const contactFile = @"ContactFile";
NSString *const contactFlag = @"CONTACTFLAG";

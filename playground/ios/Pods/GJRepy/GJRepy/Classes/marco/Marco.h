//
//  Marco.h
//  OC基础
//
//  Created by ford Gao on 2018/8/29.
//  Copyright © 2018年 ford Gao. All rights reserved.
//

#ifndef Header_h
#define Header_h

//
#define ScreenWidth [UIScreen mainScreen].bounds.size.width
#define ScreenHeight [UIScreen mainScreen].bounds.size.height

#define NOTIFYCENTER [NSNotificationCenter defaultCenter]

#define WeakSelf(type)  __weak typeof(type) weak##type = type;
#define StrongSelf(type)  __strong typeof(type) type = weak##type;


/*1. __OBJC_GC__ (Garbage Collection 垃圾回收机制， 在mac中支持， 在iPad和iPhone中不支持)

#ifdef __OBJC_GC__ 如果支持__OBJC_GC__宏定义
#endif

#if
#else
#endif

//区分真机和模拟器用    TARGET_IPHONE_SIMULATOR --------------------------------------

//模拟器sdk定义
#define TARGET_OS_IPHONE            1
#define TARGET_IPHONE_SIMULATOR     1

//真机sdk中的定义：
#define TARGET_OS_IPHONE            1
#define TARGET_IPHONE_SIMULATOR     0

// 判断是不是iOS系统，如果是iOS系统在真机和模拟器输出都是YES
#if TARGET_OS_IPHONE
#endif

#if (TARGET_IPHONE_SIMULATOR)
// 在模拟器的情况下
#else
// 在真机情况下
#endif
 */

//-------------------------------------------------------------------------------
//屏幕宽高
#define SCREEN_WIDTH   [UIScreen mainScreen].bounds.size.width
#define SCREENH_HEIGHT [UIScreen mainScreen].bounds.size.height
//-----------------------------------------------------------------------------------
//通知中心
#define GJNotificationCenter [NSNotificationCenter defaultCenter]
//-------------------------------------------------------------------------------
//随机颜色
#define GJRandomColor [UIColor colorWithRed:arc4random_uniform(256)/255.0 green:arc4random_uniform(256)/255.0 blue:arc4random_uniform(256)/255.0 alpha:1.0]

#define RGBColor(r, g, b) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1.0]
#define RGBAColor(r, g, b, a) [UIColor colorWithRed:(r)/255.0 green:(r)/255.0 blue:(r)/255.0 alpha:a]

// RGB颜色转换（16进制->10进制）
#define UICOLOR_HEX(hexString) [UIColor colorWithRed:((float)((hexString & 0xFF0000) >> 16))/255.0 green:((float)((hexString & 0xFF00) >> 8))/255.0 blue:((float)(hexString & 0xFF))/255.0 alpha:1.0]

// clear背景颜色
#define ClearColor [UIColor clearColor]

//-------------------------------------------------------------------------------
#ifdef DEBUG
#define NSLog(...) NSLog(@"%s 第%d行 \n %@\n\n",__func__,__LINE__,[NSString stringWithFormat:__VA_ARGS__])
#define debugMethod() NSLog(@"%s", __func__)
#else
#define NSLog(...)
#define debugMethod()
#endif

//-------------------------------------------------------------------------------
// Directory 目录
#define PATH_DIRECTORY [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0]
// Cache 目录
#define PATH_CACHE [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) objectAtIndex:0]
// 数据库 目录
#define PATH_DATABASE_CACHE [NSSearchPathForDirectoriesInDomains(NSApplicationSupportDirectory, NSUserDomainMask, YES) objectAtIndex:0]

//获取temp
#define kPathTemp NSTemporaryDirectory()

//-------------------------------------------------------------------------------
#define WeakSelf(type)  __weak typeof(type) weak##type = type;
#define StrongSelf(type)  __strong typeof(type) type = weak##type;

//-------------------------------------------------------------------------------
// View 圆角和加边框
#define ViewBorderRadius(View, Radius, Width, Color)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES];\
[View.layer setBorderWidth:(Width)];\
[View.layer setBorderColor:[Color CGColor]]

// View 圆角
#define ViewRadius(View, Radius)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES]


//-------------------------------------------------------------------------------
//角度转换弧度 由弧度转换角度
#define DegreesToRadian(x) (M_PI * (x) / 180.0)
#define RadianToDegrees(radian) (radian*180.0)/(M_PI)

//------------------------------------------------------------------------------
//获取图片资源
#define kGetImage(imageName) [UIImage imageNamed:[NSString stringWithFormat:@"%@",imageName]]
// 加载图片
#define PNGIMAGE(NAME)          [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:(NAME) ofType:@"png"]]
#define JPGIMAGE(NAME)          [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:(NAME) ofType:@"jpg"]]
#define IMAGE(NAME, EXT)        [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:(NAME) ofType:(EXT)]]

//-------------------------------------------------------------------------------
//GCD - 一次性执行
#define kDISPATCH_ONCE_BLOCK(onceBlock) static dispatch_once_t onceToken; dispatch_once(&onceToken, onceBlock);

//GCD - 在Main线程上运行
#define kDISPATCH_MAIN_THREAD(mainQueueBlock) dispatch_async(dispatch_get_main_queue(), mainQueueBlock);

//GCD - 开启异步线程
#define kDISPATCH_GLOBAL_QUEUE_DEFAULT(globalQueueBlock) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), globalQueueBlocl);

#define dispatch_main_sync_safe(block)\
if ([NSThread isMainThread]) {\
block();\
} else {\
dispatch_sync(dispatch_get_main_queue(), block);\
}

#define dispatch_main_async_safe(block)\
if ([NSThread isMainThread]) {\
block();\
} else {\
dispatch_async(dispatch_get_main_queue(), block);\
}

//------------------------------------------------------------------------------
// iPhoneX 相关 (add by 2017年09月22日10:53:06)
#define IS_iPhoneX ([UIScreen mainScreen].bounds.size.width == 375 && [UIScreen mainScreen].bounds.size.height == 812)
#define IPHONEX_MARGIN_TOP (88)
#define IPHONEX_MARGIN_BOTTOM (34)

//-------------------------------------------------------------------------------
/**
 方法替换
 
 @param c class
 @param orig 原函数
 @param new 新函数
 @return
 */
#define Swizzle(c, orig, new) {\
Method origMethod = class_getInstanceMethod(c, orig);\
Method newMethod = class_getInstanceMethod(c, new);\
if (class_addMethod(c,\
orig,\
method_getImplementation(newMethod),\
method_getTypeEncoding(newMethod)))\
{\
class_replaceMethod(c,\
new,\
method_getImplementation(origMethod),\
method_getTypeEncoding(origMethod));\
} else {\
method_exchangeImplementations(origMethod, newMethod);\
}\
}
//-------------------------------------------------------------------------------
// View 坐标(x,y)和宽高(width,height)
#define X(v)                    (v).frame.origin.x
#define Y(v)                    (v).frame.origin.y

#define WIDTH(v)                (v).frame.size.width
#define HEIGHT(v)               (v).frame.size.height

#define MinX(v)                 CGRectGetMinX((v).frame)
#define MinY(v)                 CGRectGetMinY((v).frame)

#define MidX(v)                 CGRectGetMidX((v).frame)
#define MidY(v)                 CGRectGetMidY((v).frame)

#define MaxX(v)                 CGRectGetMaxX((v).frame)
#define MaxY(v)                 CGRectGetMaxY((v).frame)

//-------------------------------------------------------------------------------
// 系统控件默认高度
#define StatusBarHeight        (20.f)
#define TopBarHeight           (44.f)
#define BottomBarHeight        (49.f)
#define CellDefaultHeight      (44.f)
#define EnglishKeyboardHeight  (216.f)
#define ChineseKeyboardHeight  (252.f)
//-------------------------------------------------------------------------------
// 当前语言
#define CURRENTLANGUAGE         ([[NSLocale preferredLanguages] objectAtIndex:0])
//------------------------------------------------------------------------------

// 本地化字符串
/** NSLocalizedString宏做的其实就是在当前bundle中查找资源文件名“Localizable.strings”(参数:键＋注释) */
#define LocalString(x, ...)     NSLocalizedString(x, nil)
/** NSLocalizedStringFromTable宏做的其实就是在当前bundle中查找资源文件名“xxx.strings”(参数:键＋文件名＋注释) */
#define AppLocalString(x, ...)  NSLocalizedStringFromTable(x, @"someName", nil)


//-------------------------------------------------------------------------------

// 时间间隔
#define kHUDDuration            (1.f)
// 一天的秒数
#define SecondsOfDay            (24.f * 60.f * 60.f)
// 秒数
#define Seconds(Days)           (24.f * 60.f * 60.f * (Days))
// 一天的毫秒数
#define MillisecondsOfDay       (24.f * 60.f * 60.f * 1000.f)
// 毫秒数
#define Milliseconds(Days)      (24.f * 60.f * 60.f * 1000.f * (Days))

//-------------------------------------------------------------------------------
// app 信息
#define VERSION             [[[NSBundle mainBundle] infoDictionary] valueForKey:@"CFBundleShortVersionString"]

//-------------------------------------------------------------------------------

//单例宏
#define SINGLETON_FOR_HEADER(className) \
\
+ (className *)shared##className;

#define SINGLETON_FOR_IMPLEMENTATION(className) \
\
+ (className *)shared##className { \
static className *shared##className = nil; \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
shared##className = [[self alloc] init]; \
}); \
return shared##className; \
}

/*#import <Foundation/Foundation.h>
 #import "Global.h"
 
 @interface Student : NSObject
 
 SINGLETON_FOR_HEADER(Student);
 
 @end
 
 
 
 #import "Student.h"
 
 @implementation Student
 
 SINGLETON_FOR_IMPLEMENTATION(Student);
 
 @end
 
 // 测试
 Student* stu1 = [Student sharedStudent];
 初始化的时候必须要调sharedClassName这个方法
 */

//-------------------------------------------------------------------------------

// 通知相关
#define ADD_OBSERVER(_selector,_name) \
ADD_OBSERVER_WITH_OBJECT(_selector, _name, nil)
//post
#define POST_NOTIFICATION_WITH_OBJECT_AND_INFO(_name, _object, _info) \
([[NSNotificationCenter defaultCenter] postNotificationName:_name object:_object userInfo:(_info)])
#define POST_NOTIFICATION(_name) \
POST_NOTIFICATION_WITH_OBJECT_AND_INFO(_name, nil, nil)
#define POST_NOTIFICATION_WITH_OBJECT(_name, _object) \
POST_NOTIFICATION_WITH_OBJECT_AND_INFO(_name, _object, nil)
#define POST_NOTIFICATION_WITH_INFO(_name, _info) \
POST_NOTIFICATION_WITH_OBJECT_AND_INFO(_name, nil, _info)
//remove
#define REMOVE_OBSERVER(_name) \
([[NSNotificationCenter defaultCenter] removeObserver:self name:_name object:nil])
#define REMOVE_ALL_OBSERVERS(_self) \
([[NSNotificationCenter defaultCenter] removeObserver:_self])

//-------------------------------------------------------------------------------

// 检查字符串是否为空(PS：这里认为nil," ", "\n"均是空)
#define strIsEmpty(str)      (str==nil || [str length]==0 || [[str stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] length] == 0)
// trim string
#define TRIM_STRING(_string) (\
(OBJECT_IS_EMPTY(_string) || NO == [_string isKindOfClass:[NSString class]]) ? \
@"" : [_string stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] \
)

//  检查空对象
#define OBJECT_IS_EMPTY(_object) (_object == nil \
|| [_object isKindOfClass:[NSNull class]] \
|| ([_object respondsToSelector:@selector(length)] && [(NSData *)_object length] == 0) \
|| ([_object respondsToSelector:@selector(count)]  && [(NSArray *)_object count] == 0))
#define OBJECT_ISNOT_EMPTY(_object) (NO == OBJECT_IS_EMPTY(_object))
#define RETURN_WHEN_OBJECT_IS_EMPTY(_object)        if (OBJECT_IS_EMPTY(_object)) { return ;    }
#define RETURN_NIL_WHEN_OBJECT_IS_EMPTY(_object)    if (OBJECT_IS_EMPTY(_object)) { return nil; }
#define RETURN_EMPTY_WHEN_OBJECT_IS_EMPTY(_object)  if (OBJECT_IS_EMPTY(_object)) { return @""; }
#define RETURN_YES_WHEN_OBJECT_IS_EMPTY(_object)    if (OBJECT_IS_EMPTY(_object)) { return YES; }
#define RETURN_NO_WHEN_OBJECT_IS_EMPTY(_object)     if (OBJECT_IS_EMPTY(_object)) { return NO; }
#define RETURN_ZERO_WHEN_OBJECT_IS_EMPTY(_object)   if (OBJECT_IS_EMPTY(_object)) { return 0; }

//字符串头尾去空格
#define DeleteHeaderBlank(str) [str stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]]
//字符串删除所有空格
#define DeleteBlank(str) [str stringByReplacingOccurrencesOfString:@" " withString:@""]
//-------------------------------------------------------------------------------

/** 快速查询一段代码的执行时间 */
/** 用法
 TICK
 do your work here
 TOCK
 */

#define TICK NSDate *startTime = [NSDate date];
#define TOCK NSLog(@"Time:%f", -[startTime timeIntervalSinceNow]);
//-------------------------------------------------------------------------------

/*
 *  根据当前view 找所在tableview 里的 indexpath
 */
#define INDEXPATH_SUBVIEW_TABLEVIEW(subview,tableview)\
({\
CGRect subviewFrame = [subview convertRect:subview.bounds toView:tableview];\
NSIndexPath *tabIndexPath = [tableview indexPathForRowAtPoint:subviewFrame.origin];\
tabIndexPath;\
})\

/*
 *   根据当前view 找所在collectionview 里的 indexpath
 */
#define INDEXPATH_SUBVIEW_COLLECTION(subview,collectionview)\
({\
CGRect subviewFrame = [subview convertRect:subview.bounds toView:collectionview];\
NSIndexPath *tabIndexPath = [collectionview indexPathForItemAtPoint:subviewFrame.origin];\
tabIndexPath;\
})\


/*
 *   根据当前view 找所在tableview 里的 tableviewcell
 */
#define CELL_SUBVIEW_TABLEVIEW(subview,tableview)\
({\
CGRect subviewFrame = [subview convertRect:subview.bounds toView:tableview];\
NSIndexPath *indexPath = [tableview indexPathForRowAtPoint:subviewFrame.origin];\
UITableViewCell *tabCell  = [tableview cellForRowAtIndexPath:indexPath];\
tabCell;\
})\

//-------------------------------------------------------------------------------
//property属性快速声明

#define PropertyString(s)@property(nonatomic,copy)NSString * s

#define PropertyNSInteger(s)@property(nonatomic,assign)NSIntegers

#define PropertyFloat(s)@property(nonatomic,assign)floats

#define PropertyLongLong(s)@property(nonatomic,assign)long long s

#define PropertyNSDictionary(s)@property(nonatomic,strong)NSDictionary * s

#define PropertyNSArray(s)@property(nonatomic,strong)NSArray * s

#define PropertyNSMutableArray(s)@property(nonatomic,strong)NSMutableArray * s

//-------------------------------------------------------------------------------
//字体

#define BOLDSYSTEMFONT(FONTSIZE)[UIFont boldSystemFontOfSize:FONTSIZE]

#define SYSTEMFONT(FONTSIZE)[UIFont systemFontOfSize:FONTSIZE]

#define FONT(NAME,FONTSIZE)[UIFont fontWithName:(NAME)size:(FONTSIZE)]


//-------------------------------------------------------------------------------

//数据验证

#define StrValid(f)(f!=nil &&[f isKindOfClass:[NSString class]]&& ![f isEqualToString:@""])

#define SafeStr(f)(StrValid(f)?f:@"")

#define HasString(str,eky)([str rangeOfString:key].location!=NSNotFound)

#define ValidStr(f)StrValid(f)

#define ValidDict(f)(f!=nil &&[f isKindOfClass:[NSDictionary class]])

#define ValidArray(f)(f!=nil &&[f isKindOfClass:[NSArray class]]&&[f count]>0)

#define ValidNum(f)(f!=nil &&[f isKindOfClass:[NSNumber class]])

#define ValidClass(f,cls)(f!=nil &&[f isKindOfClass:[cls class]])

#define ValidData(f)(f!=nil &&[f isKindOfClass:[NSData class]])


//-------------------------------------------------------------------------------

//自适应宽度
#define BoundingWidth(str,height,font) [str boundingRectWithSize:CGSizeMake(MAXFLOAT, height) options:NSStringDrawingUsesLineFragmentOrigin attributes:@{NSFontAttributeName:[UIFont systemFontOfSize:font]} context:nil]
//自适应高度
#define BoundingHeight(str,width,font) [str boundingRectWithSize:CGSizeMake(width, MAXFLOAT) options:NSStringDrawingUsesLineFragmentOrigin attributes:@{NSFontAttributeName:[UIFont systemFontOfSize:font]} context:nil]


//-------------------------------------------------------------------------------
//获取storyboard
#define StoryBoard(StoryboardName) [UIStoryboard storyboardWithName:StoryboardName bundle:[NSBundle mainBundle]];
//获取storyboard中的viewcontroller
#define VCFromeStoryboard(StoryboardName,VCName) \
[[UIStoryboard storyboardWithName:StoryboardName bundle:[NSBundle mainBundle]]instantiateViewControllerWithIdentifier:VCName]


//-------------------------------------------------------------------------------


#endif /* Header_h */

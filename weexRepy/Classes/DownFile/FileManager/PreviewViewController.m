//
//  PreviewViewController.m
//  WeexEros
//
//  Created by ford Gao on 2018/7/6.
//  Copyright © 2018年 benmu. All rights reserved.
//

#import "PreviewViewController.h"
#import <QuickLook/QuickLook.h>
#import "ShareManager.h"


@interface PreviewViewController ()<QLPreviewControllerDelegate, QLPreviewControllerDataSource>

@property (nonatomic, strong) QLPreviewController *qlVc;

@end

@implementation PreviewViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    UIBarButtonItem *item = [[UIBarButtonItem alloc] initWithTitle:@"分享" style:UIBarButtonItemStylePlain target:self action:@selector(shared)];
    self.navigationItem.rightBarButtonItem = item;
}

- (void)shared{
    [ShareManager shareFile:self.path handler:^(UIActivityType  _Nullable activityType, BOOL completed, NSArray * _Nullable returnedItems, NSError * _Nullable activityError) {
        
    }];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (QLPreviewController *)qlVc{
    if (!_qlVc) {
        _qlVc = [[QLPreviewController alloc] init];
        _qlVc.view.frame = CGRectMake(0, 50, self.view.bounds.size.width, self.view.bounds.size.height-50);
        _qlVc.delegate = self;
        _qlVc.dataSource = self;
    }
    return _qlVc;
}


- (void)setPath:(NSString *)path{
    _path = path;
    [self addChildViewController:self.qlVc];
    [self.view addSubview:self.qlVc.view];
    [self.qlVc reloadData];
}


#pragma mark QLPreviewControllerDataSource
//返回文件的个数
- (NSInteger)numberOfPreviewItemsInPreviewController:(QLPreviewController *)controller{
    if (self.path) {
        return 1;
    }else{
        return 0;
    }
}

//加载需要显示的文件
- (id<QLPreviewItem>)previewController:(QLPreviewController *)controller previewItemAtIndex:(NSInteger)index{
    
    return [NSURL fileURLWithPath: self.path];
}

- (BOOL)previewController:(QLPreviewController *)controller shouldOpenURL:(NSURL *)url forPreviewItem:(id <QLPreviewItem>)item{
    return YES;
}



@end

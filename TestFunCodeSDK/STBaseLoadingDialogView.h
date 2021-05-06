//
//  STBaseLoadingDialogView.h
//  InvoiceMonster
//
//  Created by Phoebe.Lin on 2021/5/3.
//  Copyright © 2021 Friendo. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DefConstants.h"
#import "DefDeviveType.h"
#import "Masonry.h"
#import "Lottie.h"

NS_ASSUME_NONNULL_BEGIN

@interface STBaseLoadingDialogView : UIView
//@property (nonatomic, weak) id<STBaseLoadingDialogViewDelegate> delegate;
@property (nonatomic, strong) UIView *maskView;
@property (nonatomic, strong) UIView *animationView;
@property (nonatomic, strong) UILabel *titleLabel;

- (void)showDialogTitle:(NSString *)title lottieName:(NSString *)name;
@end

NS_ASSUME_NONNULL_END

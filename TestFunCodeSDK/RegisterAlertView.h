//
//  RegisterAlertView.h
//  InvoiceMonster
//
//  Created by Phoebe.Lin on 2021/4/7.
//  Copyright © 2021 Friendo. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DefConstants.h"
#import "DefDeviveType.h"
#import "Masonry.h"
#import "Lottie.h"

NS_ASSUME_NONNULL_BEGIN
@class RegisterAlertView;
@protocol RegisterAlertViewDelegate <NSObject>
@optional
- (void)goStepTwoForRegiester;
@end

@interface RegisterAlertView : UIView
@property (nonatomic, weak) id<RegisterAlertViewDelegate> delegate;
@property (nonatomic, strong) UIView *maskView;
@property (nonatomic, strong) UIImageView *imageView;
@property (nonatomic, strong) UILabel *contentLabel;
@property (nonatomic, strong) UIButton *actionButton;

@property (nonatomic, strong) NSString *errorMessage;
@end

NS_ASSUME_NONNULL_END

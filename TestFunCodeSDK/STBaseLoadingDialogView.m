//
//  STBaseLoadingDialogView.m
//  InvoiceMonster
//
//  Created by Phoebe.Lin on 2021/5/3.
//  Copyright © 2021 Friendo. All rights reserved.
//

#import "STBaseLoadingDialogView.h"

@implementation STBaseLoadingDialogView

- (instancetype)initWithFrame:(CGRect)frame{
    if (self = [super initWithFrame:frame]) {
        [self createUI];
    }
    return self;
}

- (void)createUI{
    self.frame = [UIScreen mainScreen].bounds;
    self.backgroundColor = ZXColorRGBA(0, 0, 0, 0.5);
    
    [self addSubview:self.maskView];
    [self addSubview:self.titleLabel];
    [self addSubview:self.animationView];
}

- (void)layoutSubviews{
    
    CGFloat space = 28.f;
    CGFloat tempW = SCREEN_WIDTH - (space * 2);
    CGFloat tempH = 320.f;
    
    [self.maskView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.center.equalTo(self);
        make.width.mas_offset(tempW);
        make.height.mas_offset(tempH);
    }];
    
    [self.titleLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(self.maskView.mas_top).with.offset(28);
        make.left.equalTo(self.maskView.mas_left).with.offset(50);
        make.right.equalTo(self.maskView.mas_right).with.offset(-50);
        make.height.mas_equalTo(32);
    }];
    
    [self.animationView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.bottom.equalTo(self.maskView.mas_bottom).with.offset(-25);
        make.centerX.mas_equalTo(self.maskView);
        make.width.mas_equalTo(220);
        make.height.mas_equalTo(220);
    }];
}

#pragma mark - Public methods
- (void)showDialogTitle:(NSString *)title lottieName:(NSString *)name{
    
    self.titleLabel.text = title;
    
    LOTAnimationView *lottieView;
    lottieView = [LOTAnimationView animationNamed:name];
    lottieView.contentMode = UIViewContentModeScaleAspectFit;
    [self.animationView addSubview:lottieView];
    
    [lottieView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.center.equalTo(self.animationView);
        make.size.equalTo(self.animationView);
    }];
    
    lottieView.loopAnimation = YES;
    [lottieView play];
}

#pragma mark - Property
- (UIView *)maskView{
    if (!_maskView) {
        _maskView = [UIView new];
        _maskView.backgroundColor = ZXColor(255, 255, 255);
        _maskView.layer.cornerRadius = 10.f;
        _maskView.layer.masksToBounds = YES;
    }
    return _maskView;
}

- (UIView *)animationView{
    if (!_animationView) {
        _animationView = [UIView new];
        _animationView.backgroundColor = [UIColor clearColor];
    } 
    return _animationView;
}

- (UILabel *)titleLabel{
    if (!_titleLabel) {
        _titleLabel = [UILabel new];
        _titleLabel.font = [UIFont systemFontOfSize:22.f];
        _titleLabel.textColor = ZXColor(85, 85, 85);
//        _titleLabel.text = @"打卡驗證中...";
        _titleLabel.textAlignment = NSTextAlignmentCenter;
        _titleLabel.numberOfLines = 1;
    }
    return _titleLabel;
}
@end

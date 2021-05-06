//
//  RegisterAlertView.m
//  InvoiceMonster
//
//  Created by Phoebe.Lin on 2021/4/7.
//  Copyright © 2021 Friendo. All rights reserved.
//

#import "RegisterAlertView.h"

@implementation RegisterAlertView

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
    [self addSubview:self.imageView];
    [self addSubview:self.contentLabel];
    [self addSubview:self.actionButton];
}

- (void)layoutSubviews{
    [super layoutSubviews];

    [self.imageView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(self.maskView.mas_top).with.offset(39);
        make.centerX.equalTo(self.maskView);
        make.width.mas_equalTo(166);
        make.height.mas_equalTo(122);
    }];
    
    [self.contentLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(self.imageView.mas_bottom).with.offset(32);
        make.left.equalTo(self.maskView.mas_left).with.offset(22);
        make.right.equalTo(self.maskView.mas_right).with.offset(-22);
        make.height.greaterThanOrEqualTo(@23);
    }];
    
    CGFloat space = 22.f;
    CGFloat tempW = SCREEN_WIDTH - (space * 2);
    
    [self.maskView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.center.equalTo(self);
        make.width.mas_equalTo(tempW);
        make.bottom.equalTo(self.contentLabel).with.offset(89);
    }];
    
    [self.actionButton mas_makeConstraints:^(MASConstraintMaker *make) {
        make.bottom.equalTo(self.maskView.mas_bottom).with.offset(-19);
        make.left.equalTo(self.maskView.mas_left).with.offset(22);
        make.right.equalTo(self.maskView.mas_right).with.offset(-22);
        make.height.mas_equalTo(44);
    }];
}

#pragma mark - Button Action
- (void)clickActionButtonAction:(id)sender{
    [self removeFromSuperview];
    
    if ([self.delegate respondsToSelector:@selector(goStepTwoForRegiester)]) {
        [self.delegate goStepTwoForRegiester];
    }
}

#pragma mark - Set Model
- (void)setErrorMessage:(NSString *)errorMessage{
    _errorMessage = errorMessage;
    self.contentLabel.text = _errorMessage;
    
    [self layoutIfNeeded];
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

- (UIImageView *)imageView{
    if (!_imageView) {
        _imageView = [UIImageView new];
//        _imageView.backgroundColor = ZXColor(196, 196, 196);
        _imageView.image = [UIImage imageNamed:@"pic_cry"];
    }
    return _imageView;
}

- (UILabel *)contentLabel{
    if (!_contentLabel) {
        _contentLabel = [UILabel new];
//        _contentLabel.text = @"此邀請碼使用次數已達上限";
        _contentLabel.backgroundColor = [UIColor clearColor];
        _contentLabel.font = [UIFont systemFontOfSize:20.f];
        _contentLabel.textColor = ZXColor(111, 111, 111);
        _contentLabel.textAlignment = NSTextAlignmentCenter;
        _contentLabel.numberOfLines = 0;
    }
    return _contentLabel;
}

- (UIButton *)actionButton{
    if (!_actionButton) {
        _actionButton = [UIButton buttonWithType:UIButtonTypeCustom];
        _actionButton.backgroundColor = ZXColor( 78, 174, 255);
        [_actionButton setTitle:@"確認" forState:UIControlStateNormal];
        _actionButton.titleLabel.font = [UIFont italicSystemFontOfSize:18.f];
        [_actionButton addTarget:self action:@selector(clickActionButtonAction:) forControlEvents:UIControlEventTouchUpInside];
        _actionButton.layer.cornerRadius = 22.f;
        _actionButton.layer.masksToBounds = YES;
    }
    return _actionButton;
}
@end

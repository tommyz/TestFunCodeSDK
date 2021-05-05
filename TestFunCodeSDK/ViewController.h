//
//  ViewController.h
//  TestFunCodeSDK
//
//  Created by Tommy-mac on 2021/5/4.
//

#import <UIKit/UIKit.h>

#import "ProcessViewController.h"
#import "PhotoDecoderViewController.h"
#import "QRcodeDrawView.h"

@interface ViewController : UIViewController<FunDecodeDelegate>
{
    ProcessViewController *funcodeDecoder;
}
@property (nonatomic, strong) UILabel *messageLabel;
@property (nonatomic, strong) UIImageView *imageView;
@end


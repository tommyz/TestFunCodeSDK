//
//  QRcodeDrawView.h
//  TestCaller_withSDK
//
//  Created by Tommy-mac on 2019/11/28.
//  Copyright © 2019 ＦＵＮ ＦＵＮＣＯＤＥ. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface QRcodeDrawView : UIView
{
    
}
@property (nonatomic, strong) NSMutableArray *points;
- (void)setVertices:(float[])vertices;

@end

NS_ASSUME_NONNULL_END

//
//  QRcodeDrawView.m
//  TestCaller_withSDK
//
//  Created by Tommy-mac on 2019/11/28.
//  Copyright © 2019 ＦＵＮ ＦＵＮＣＯＤＥ. All rights reserved.
//

#import "QRcodeDrawView.h"

@implementation QRcodeDrawView

- (void)setVertices:(float[])vertices {
//    NSLog(@"vertices=%@",vertices.count);
//    NSLog(@"setVertices vertices[0]=%f",vertices[0]);
    if (self.points == nil)
    {
        self.points = [NSMutableArray new];
    }
    else
    {
        [self.points removeAllObjects];
    }
    
    [self.points addObject:[NSValue valueWithCGPoint:CGPointMake(vertices[0], vertices[1])]];
    [self.points addObject:[NSValue valueWithCGPoint:CGPointMake(vertices[2], vertices[3])]];
    [self.points addObject:[NSValue valueWithCGPoint:CGPointMake(vertices[4], vertices[5])]];
    [self.points addObject:[NSValue valueWithCGPoint:CGPointMake(vertices[6], vertices[7])]];
    
//    [self.points addObject:[NSValue valueWithCGPoint:CGPointMake(0, 0)]];
//    [self.points addObject:[NSValue valueWithCGPoint:CGPointMake(vertices[2], vertices[3])]];
//    [self.points addObject:[NSValue valueWithCGPoint:CGPointMake(vertices[4], vertices[5])]];
//    [self.points addObject:[NSValue valueWithCGPoint:CGPointMake(vertices[6], vertices[7])]];
    
//    NSLog(@"self.points=%@",self.points);

    self.layer.sublayers = nil;
    
    CAShapeLayer *shape = [CAShapeLayer layer];
    shape.lineCap = kCALineCapRound;
    shape.lineJoin = kCALineJoinMiter;
    shape.strokeColor = [UIColor orangeColor].CGColor;
    shape.fillColor = [UIColor grayColor].CGColor;
    shape.opacity = 0.5;
    shape.lineWidth = 2.0;
    [self.layer addSublayer:shape];
    
    UIBezierPath *path = [UIBezierPath bezierPath];
    
    [path moveToPoint:[self.points[0] CGPointValue]];
    [path addLineToPoint:[self.points[1] CGPointValue]];
    [path addLineToPoint:[self.points[2] CGPointValue]];
    [path addLineToPoint:[self.points[3] CGPointValue]];
    [path closePath];
    shape.path = path.CGPath;
}

// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
/*
- (void)drawRect:(CGRect)rect {
    // Drawing code
    
    
    
    
}
*/

@end

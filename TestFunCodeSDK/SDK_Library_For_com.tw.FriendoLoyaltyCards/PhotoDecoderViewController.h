#import <UIKit/UIKit.h>

@interface PhotoDecoderViewController : UIViewController
{
}

- (void) setBaseView:(UIView*) baseview;
- (NSString*) startPhotoDecode:(UIImage*) pickimg;
-(void) setTurbo:(int)turbo_v;
//-(int) getTurbo;

@property ( retain)  UIView *passinview;

@end



#import <UIKit/UIKit.h>
#import "CaptureSessionManager.h"

@protocol FunDecodeDelegate

- (void)FunDecodeResultCallBack:(char[] )s withString:(NSString*)res_str andMeta:(NSInteger)res_len andMeta:(NSInteger)center_x andMeta:(NSInteger)center_y andMeta:(NSInteger)img_width andMeta:(NSInteger)img_height andMeta:(float)fun_angle andMeta:(int[])meta_data andMeta:(float[])vertices withType:(int)type;

@end

@interface ProcessViewController : UIViewController <UIAlertViewDelegate, captureManagerDelegate> 
{

}

@property (retain) CaptureSessionManager *captureManager;
//@property (nonatomic, retain) IBOutlet CALayer *overlayLayer;
@property ( retain)  UIView *passinview;


- (void) setBaseView:(UIView*) baseview;
- (void) startVideo;
- (void) stopVideo;
- (void) startDecode;
- (void) stopDecode;
- (void) setZoom:(float)zoom_v;
-(float) getMaxZoom;
- (void) setScanRange:(int)x1 andMeta:(int)y1 andMeta:(int)x2 andMeta:(int)y2 andMeta:(CGSize)img_size;
- (void) setTurbo:(int)turbo_v;
-(int) getTurbo;
- (float *) getVertices; //2019/11/26

@property (nonatomic, retain) id  <FunDecodeDelegate> fundelegate;

@end


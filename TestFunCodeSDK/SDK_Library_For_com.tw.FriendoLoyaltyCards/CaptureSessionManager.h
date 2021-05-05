
#import <UIKit/UIKit.h>
#import <CoreMedia/CoreMedia.h>
#import <AVFoundation/AVFoundation.h>

@protocol captureManagerDelegate


//2019/06/10
- (void)DecodeResultCallBack:(char[] )s withString:(NSString*)res_str andMeta:(NSInteger)res_len andMeta:(NSInteger)center_x andMeta:(NSInteger)center_y andMeta:(NSInteger)img_width andMeta:(NSInteger)img_height andMeta:(float)fun_angle andMeta:(int[])meta_data andMeta:(float[])vertices withType:(int)type;

@end

@interface CaptureSessionManager : UIViewController <AVCaptureVideoDataOutputSampleBufferDelegate, UIAlertViewDelegate> {	
	  
	 
	AVCaptureSession *captureSession;  
	AVCaptureVideoPreviewLayer *previewLayer;
	AVCaptureConnection *videoConnection;
    
    NSString* res_s; 
    
    char res_char[4096];
    int meta_data[10];

    id <captureManagerDelegate> delegate; }

- (void) addVideoPreviewLayer;
- (void) addVideoInput;
- (void) addVideoDataOutput;
- (void) startDecode;
- (void) stopDecode;
- (void) setMyZoom:(float)zoom_v;
-(float) getMyMaxZoom;
- (void) setScanRange:(int)x1 andMeta:(int)y1 andMeta:(int)x2 andMeta:(int)y2 andMeta:(CGSize)img_size;
- (void) setMyTurbo:(int)turbo_v;
-(int) getMyTurbo;
- (float *) getVertices; //2019/11/26


@property (retain) AVCaptureVideoPreviewLayer *previewLayer;
@property (retain) AVCaptureSession *captureSession;

@property (nonatomic, retain) IBOutlet NSString* res_s; 


@property (nonatomic, retain) id  <captureManagerDelegate> delegate;  
@end

//
//  ViewController.m
//  TestFunCodeSDK
//
//  Created by Tommy-mac on 2021/5/4.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

int Decode_Mode = 2; // 1 for preview, 2 for photo
int videoon=1;
int in_process=0;

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor whiteColor];
    
    self.imageView = [UIImageView new];
    self.imageView.backgroundColor = [UIColor clearColor];
    self.imageView.frame = self.view.bounds;
    [self.view addSubview:self.imageView];
    
    self.messageLabel = [UILabel new];
    self.messageLabel.font = [UIFont systemFontOfSize:20.f];
    self.messageLabel.text = @"Results:";
    self.messageLabel.textColor = [UIColor redColor];
    self.messageLabel.numberOfLines = 0;
    self.messageLabel.frame = CGRectMake(10, 60, self.view.frame.size.width - (10*2), 120);
    [self.view addSubview:self.messageLabel];
    
    
    UIButton *btn = [UIButton buttonWithType:UIButtonTypeCustom];
    [btn setTitle:@"start or stop" forState:UIControlStateNormal];
    [btn addTarget:self action:@selector(go_start_stop) forControlEvents:UIControlEventTouchUpInside];
    btn.backgroundColor = [UIColor redColor];
    btn.frame = CGRectMake(10, 60 + 120 + 20, 100, 44);
    [self.view addSubview:btn];
    
    videoon=0;
}

- (void)FunDecodeResultCallBack:(char[] )res withString:(NSString*)res_string andMeta:(NSInteger)res_len andMeta:(NSInteger)center_x andMeta:(NSInteger)center_y andMeta:(NSInteger)img_width andMeta:(NSInteger)img_height andMeta:(float)fun_angle andMeta:(int[])meta_data andMeta:(float[])vertices withType:(int)type
{
    NSLog(@"type=%d", type);
    NSString* show_string;
    
    if (in_process==0)
    {
        in_process=1;
        [funcodeDecoder stopDecode];
        
        NSLog(@"result_str1: %@ \n", res_string);
        NSLog(@"res_len=%ld type:%d ",(long)res_len, (int)type);
        
        int go_on=0;
        if (type==1)
        {
            if (res_string != NULL)
            {
                go_on=1;
                
                NSLog(@"result_str2: %@ \n", res_string);
                show_string=res_string;
            }
            else
                go_on=0;
        }
        else
        {
            if (res!= NULL)
            {
                go_on=1;
                NSLog(@"input res1: %d %d %d %d %d \n", res[0],res[1],res[2],res[3],res[4]);
                
                NSString* res_s = [[NSString alloc] initWithCString:(char *)res encoding:CFStringConvertEncodingToNSStringEncoding(kCFStringEncodingUTF8)];
                
                if (res_s == nil)
                    res_s=[NSString stringWithCString:(char *)res encoding:CFStringConvertEncodingToNSStringEncoding(kCFStringEncodingBig5)];
                if (res_s == nil)
                    res_s = [[NSString alloc] initWithCString:(char *)res encoding:CFStringConvertEncodingToNSStringEncoding(kCFStringEncodingGB_18030_2000)];
                if (res_s == nil)
                    res_s = [[NSString alloc] initWithCString:(char *)res encoding:NSJapaneseEUCStringEncoding];
                if (res_s == nil)
                    res_s = [[NSString alloc] initWithCString:(char *)res encoding:CFStringConvertEncodingToNSStringEncoding(kCFStringEncodingMacKorean)];
                if (res_s == nil)
                    res_s = [[NSString alloc] initWithCString:(char *)res encoding:CFStringConvertEncodingToNSStringEncoding(kCFStringEncodingDOSRussian)];
                if (res_s == nil)
                    res_s = [[NSString alloc] initWithCString:(char *)res encoding:CFStringConvertEncodingToNSStringEncoding(kCFStringEncodingMacKorean)];
                if (res_s == nil)
                    res_s = [[NSString alloc] initWithCString:(char *)res encoding:CFStringConvertEncodingToNSStringEncoding(kCFStringEncodingASCII)];
                
                show_string=res_s;
                NSLog(@"input res2: %d %d %d %d %d \n", res[0],res[1],res[2],res[3],res[4]);
            }
            else
                go_on=0;
            
        }
        
        if (go_on==1)
        {
            [self.messageLabel setText:show_string];
            
            int meta[10];
            meta[0]=meta_data[0];
            meta[1]=meta_data[1];
            meta[2]=meta_data[2];
            meta[3]=meta_data[3];
            meta[4]=meta_data[4];
            meta[5]=meta_data[5];
            meta[6]=meta_data[6];
            meta[7]=meta_data[7];
            meta[8]=meta_data[8];
            meta[9]=meta_data[9];
            
            float ratio_w = 1080/self.imageView.bounds.size.width;
            float ratio_h = 1920/self.imageView.bounds.size.height;
            
            //NSLog(@"center: %d , %d", (int)center_x, (int)center_y);
            //NSLog(@"points: %d,%d,%d,%d,%d,%d,%d,%d,%d,%d,", meta[0], meta[1],meta[2],meta[3],meta[4],meta[5],meta[6],meta[7],meta[8],meta[9]);
            //NSLog(@"vertices: %f,%f,%f,%f,%f,%f,%f,%f", vertices[0], vertices[1],vertices[2],vertices[3],vertices[4],vertices[5],vertices[6],vertices[7]);
            
            vertices[0]=vertices[0]/ratio_w;
            vertices[1]=vertices[1]/ratio_h;
            vertices[2]=vertices[2]/ratio_w;
            vertices[3]=vertices[3]/ratio_h;
            vertices[4]=vertices[4]/ratio_w;
            vertices[5]=vertices[5]/ratio_h;
            vertices[6]=vertices[6]/ratio_w;
            vertices[7]=vertices[7]/ratio_h;
            
            [[self.imageView subviews] makeObjectsPerformSelector:@selector(removeFromSuperview)];
            
            QRcodeDrawView *testView = [QRcodeDrawView new];
            //testView.backgroundColor = [UIColor clearColor];
            testView.backgroundColor = [UIColor colorWithRed:0.0 green:0.0 blue:1.0 alpha:0.2];
            float t1=self.view.frame.size.width/2.f;
            float t2=self.view.frame.size.height/2.f;
            testView.frame = CGRectMake(0, 0, self.view.frame.size.width/2.f, self.view.frame.size.height/2.f);
            [self.imageView addSubview:testView];
            [testView setVertices:vertices];
            
            //Play sounds
            //just for demo, should ues anothre way to beep instead of using AudioServicesPlaySystemSound
            AudioServicesPlaySystemSound(1005);
            NSLog(@"show_string: %@ \n", show_string);
            
            if (type==2)
                NSLog(@"input res3: %d %d %d %d %d \n", res[0],res[1],res[2],res[3],res[4]);
            
        }
        else
            NSLog(@"res == NULL \n");
        
        [funcodeDecoder startDecode];
        in_process=0;
        
    }//end of if (in_process==0)
}




-(void) go_start_stop
{
//    self.photoimageView.hidden=TRUE;
//    self.imageView.hidden=FALSE;
    
    if (videoon==1)
    {
        //stop fundecode
        [funcodeDecoder stopVideo];
        videoon=0;
        
    }
    else
    {
        //First time to start funcodedecoder
        if (!funcodeDecoder)
        {
            funcodeDecoder = [[ProcessViewController alloc] init];
            //set delegate
            funcodeDecoder.fundelegate=self;
            
            //passin a view to funcodeDecoder for showing camera preview
            [funcodeDecoder setBaseView:self.imageView];
            //self.imageView.contentMode = UIViewContentModeScaleAspectFit;
            self.imageView.contentMode = UIViewContentModeScaleAspectFill;
            
            [funcodeDecoder viewDidLoad];
            [funcodeDecoder startVideo];
            [funcodeDecoder startDecode];
            [funcodeDecoder setTurbo:1]; //set turbo flag
            
            
        }
        else //restart  funcodedecoder
        {
            [funcodeDecoder startVideo];
            [funcodeDecoder startDecode];
            //[funcodeDecoder viewDidLoad];
            //                [funcodeDecoder setTurbo:1]; //set turbo flag
            
        }
        
        //code to set zoom
        //float maxZoom = funcodeDecoder.getMaxZoom;
        //if (maxZoom >= 1)
        //    [funcodeDecoder setZoom:1];
        
        //How to set Range Scan
        //CGSize img_size;
        
        //This is the sample to set range of top-left 1/4 corner
        
        //------ Please make sure the image width and height can be devided by 4 exactly.
        //            int tw= (self.imageView.bounds.size.width/4);
        //            int th=(self.imageView.bounds.size.height/4);
        //            img_size.width = tw*4; //need to come out that width and height can be devide by 4 exactly.
        //            img_size.height = th*4;
        //-----
        
        //Set range for scan
        //set x1,y1 , x2,y2 in the image view and the image size for rnage scan
        //this example set the top-left 1/4 corner of the image as the scan range.
        //[funcodeDecoder setScanRange:0 andMeta:0 andMeta:img_size.width/2 andMeta:img_size.height/2 andMeta:(CGSize)img_size];
        
        //Set full range scan
        //if you need full range scan, just set it to x1,y1,x2,y2 to 0,0,0,0 as the following
        //[funcodeDecoder setScanRange:0 andMeta:0 andMeta:0 andMeta:0 andMeta:(CGSize)img_size];
        
        //code to draw scan range
        
        //            //UIView *myBox  = [[UIView alloc] initWithFrame:CGRectMake(self.imageView.frame.origin.x , self.imageView.frame.origin.y, img_size.width/2, img_size.height/2)];
        //            int t1=self.imageView.frame.origin.x ;
        //            int t2=self.imageView.frame.origin.y;
        //            UIView *myBox  = [[UIView alloc] initWithFrame:CGRectMake(0 , 0, img_size.width/2, img_size.height/2)];
        //
        //            myBox.backgroundColor = [UIColor colorWithRed:0.0 green:1.0 blue:0.0 alpha:0.3];
        //            [self.view addSubview:myBox];
        
        
        
        /*
         self.myBox  = [[UIView alloc] initWithFrame:CGRectMake(self.imageView.frame.origin.x , self.imageView.frame.origin.y, img_size.width/2, img_size.height/2)];
         self.myBox.backgroundColor = [UIColor colorWithRed:0.0 green:1.0 blue:0.0 alpha:0.3];
         [self.view addSubview:self.myBox];
         */
        
        //            myBox1  = [[UIView alloc] initWithFrame:CGRectMake(self.imageView.frame.origin.x , self.imageView.frame.origin.y, 100, 100)];
        //            //myBox1.backgroundColor = [UIColor colorWithRed:1.0 green:0.0 blue:0.0 alpha:0.3];
        //            [self.view addSubview:myBox1];
        
        videoon=1;
        
    }
    
}



@end

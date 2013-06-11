//
//  BaseSampleViewController.h
//  Teamboard
//
// Copyright 2013, Joe Lemay, All Rights Reserved.  Confidential        \n7/20/12.

//

#import <UIKit/UIKit.h>

#import "SampleBase.h"
#import "SampleFacade.h"

typedef void (^TweetImageCompletionHandler)(); 
typedef void (^SaveImageCompletionHandler)(); 

#define kSaveImageActionTitle  @"Save image"
#define kComposeTweetWithImage @"Tweet image"

@interface BaseSampleViewController : UIViewController

@property (readonly) SampleFacade * currentSample;

- (void) configureView;
- (void) setSample:(SampleFacade*) sample;
- (void) tweetImage:(UIImage*) image withCompletionHandler: (TweetImageCompletionHandler) handler;
- (void) saveImage:(UIImage*) image  withCompletionHandler: (SaveImageCompletionHandler) handler;

@end

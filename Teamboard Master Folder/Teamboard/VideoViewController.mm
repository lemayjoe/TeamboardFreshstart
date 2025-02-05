//
//  VideoViewController.m
//  Teamboard
//
// Copyright 2013, Joe Lemay, All Rights Reserved.  Confidential        \n6/26/12.

//

#import "VideoViewController.h"
#import "UIImage2OpenCV.h"
#import "OptionsTableView.h"

#define kTransitionDuration	0.75

@interface VideoViewController ()
{
#if TARGET_IPHONE_SIMULATOR
    DummyVideoSource * videoSource;
#else
    VideoSource * videoSource;
#endif
    
    cv::Mat outputFrame;
}

@end

@implementation VideoViewController
@synthesize actionSheetButton;
@synthesize captureReferenceFrameButton;
@synthesize clearReferenceFrameButton;
@synthesize options;
@synthesize imageView;
@synthesize toggleCameraButton;
@synthesize containerView;
@synthesize optionsPopover;
@synthesize optionsView;
@synthesize optionsViewController;
@synthesize actionSheet;

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    // Init the default view (video view layer)
    self.imageView = [[GLESImageView alloc] initWithFrame:self.containerView.bounds];
    [self.imageView setAutoresizingMask:(UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight)];
    [self.containerView addSubview:self.imageView];
    
    // Init video source:
#if TARGET_IPHONE_SIMULATOR
    videoSource = [[DummyVideoSource alloc] initWithFrameSize:CGSizeMake(640, 480)];
#else
    videoSource = [[VideoSource alloc] init];
#endif
    
    videoSource.delegate = self;
    
    self.actionSheet = [[UIActionSheet alloc] initWithTitle:@"Actions"
                                                   delegate:self
                                          cancelButtonTitle:@"Cancel"
                                     destructiveButtonTitle:nil
                                          otherButtonTitles:kSaveImageActionTitle, kComposeTweetWithImage, nil];
    
}

- (void) viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    
    [videoSource startRunning];
    
    toggleCameraButton.enabled = [videoSource hasMultipleCameras];
    captureReferenceFrameButton.enabled = self.currentSample.isReferenceFrameRequired;
    clearReferenceFrameButton.enabled   = self.currentSample.isReferenceFrameRequired;
    
}

- (void) viewDidDisappear:(BOOL)animated
{
    [super viewDidDisappear:animated];
    [videoSource stopRunning];
}

- (void) configureView
{
    [super configureView];
    
    self.optionsView = [[OptionsTableView alloc] initWithFrame:containerView.frame
                                                         style:UITableViewStyleGrouped
                                                        sample:self.currentSample
                                         notificationsDelegate:nil];
    
    
    if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad)
    {
        UIViewController * viewController = [[UIViewController alloc] init];
        viewController.view = self.optionsView;
        viewController.title = @"Algorithm options";
        
        self.optionsViewController = [[UINavigationController alloc] initWithRootViewController:viewController];
        
        self.optionsPopover = [[UIPopoverController alloc] initWithContentViewController:self.optionsViewController];
    }
}

- (IBAction)toggleCameraPressed:(id)sender
{
    [videoSource toggleCamera];
}

- (IBAction)showActionSheet:(id)sender
{
    if ([self.actionSheet isVisible])
        [self.actionSheet dismissWithClickedButtonIndex:-1 animated:YES];
    else
        [self.actionSheet showFromBarButtonItem:self.actionSheetButton animated:YES];
}

- (void)viewDidUnload
{
    [self setToggleCameraButton:nil];
    [self setContainerView:nil];
    [self setOptions:nil];
    [self setActionSheetButton:nil];
    [self setCaptureReferenceFrameButton:nil];
    [self setClearReferenceFrameButton:nil];
    [super viewDidUnload];
}

- (IBAction)showOptions:(id)sender
{
    if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone)
    {
        if ([self.optionsView superview])
        {
            [UIView transitionFromView:self.optionsView
                                toView:imageView
                              duration:kTransitionDuration
                               options:UIViewAnimationOptionTransitionFlipFromLeft
                            completion:^(BOOL)
             {
             }];
        }
        else
        {
            [self.optionsView setFrame:self.containerView.frame];
            [self.optionsView setNeedsLayout];
            
            [UIView transitionFromView:self.imageView
                                toView:optionsView
                              duration:kTransitionDuration
                               options:UIViewAnimationOptionTransitionFlipFromLeft
                            completion:^(BOOL)
             {
                 [self.optionsView reloadData];
             }];
        }
    }
    else
    {
        if ([self.optionsPopover isPopoverVisible])
            [self.optionsPopover dismissPopoverAnimated:YES];
        else
            [self.optionsPopover presentPopoverFromBarButtonItem:options permittedArrowDirections:UIPopoverArrowDirectionAny animated:YES];
    }
}

#pragma mark - VideoSourceDelegate

- (void) frameCaptured:(cv::Mat) frame
{
    bool isMainQueue = dispatch_get_current_queue() == dispatch_get_main_queue();
    
    if (isMainQueue)
    {
        [self.currentSample processFrame:frame into:outputFrame];
        [imageView drawFrame:outputFrame];
    }
    else
    {
        dispatch_sync( dispatch_get_main_queue(),
                      ^{
                          [self.currentSample processFrame:frame into:outputFrame];
                          [imageView drawFrame:outputFrame];
                      }
                      );
    }
}

#pragma mark UIActionSheetDelegate implementation

- (void)actionSheet:(UIActionSheet *)senderSheet clickedButtonAtIndex:(NSInteger)buttonIndex
{
    NSString * title = [senderSheet buttonTitleAtIndex:buttonIndex];
    
    if ([title isEqual: kSaveImageActionTitle])
    {
        UIImage * image = [UIImage imageWithMat:outputFrame.clone() andDeviceOrientation:[[UIDevice currentDevice] orientation]];
        [self saveImage:image withCompletionHandler: ^{ [videoSource startRunning]; }];
    }
    else if ([title isEqual: kComposeTweetWithImage])
    {
        UIImage * image = [UIImage imageWithMat:outputFrame.clone() andDeviceOrientation:[[UIDevice currentDevice] orientation]];
        [self tweetImage:image withCompletionHandler:^{ [videoSource startRunning]; }];
    }
    else
    {
        [videoSource startRunning];
    }
}

- (void)willPresentActionSheet:(UIActionSheet *)actionSheet;  // before animation and showing view
{
    [videoSource stopRunning];
}

#pragma mark - Capture reference frame

- (IBAction) captureReferenceFrame:(id) sender
{    
    bool isMainQueue = dispatch_get_current_queue() == dispatch_get_main_queue();
    
    if (isMainQueue)
    {
        [self.currentSample setReferenceFrame:outputFrame];
    }
    else
    {
        dispatch_sync( dispatch_get_main_queue(),
                      ^{
                          [self.currentSample setReferenceFrame:outputFrame];
                      }
                      );
    }
}

#pragma mark - Clear reference frame

- (IBAction) clearReferenceFrame:(id) sender
{
    bool isMainQueue = dispatch_get_current_queue() == dispatch_get_main_queue();
    
    if (isMainQueue)
    {
        [self.currentSample resetReferenceFrame];
    }
    else
    {
        dispatch_sync( dispatch_get_main_queue(), 
                      ^{ 
                          [self.currentSample resetReferenceFrame];
                      }
                      );
    }
}

@end

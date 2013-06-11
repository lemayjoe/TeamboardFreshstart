//
//  DetailViewController.h
//  Teamboard
//
// Copyright 2013, Joe Lemay, All Rights Reserved.  Confidential        

//

#import <UIKit/UIKit.h>
#import "SampleFacade.h"

@interface DetailViewController : UIViewController <UISplitViewControllerDelegate>
{
  SampleFacade* currentSample;
  UIImagePickerController * imagePicker;
}

@property (weak, nonatomic) IBOutlet UIImageView *sampleIconView;
@property (weak, nonatomic) IBOutlet UITextView *sampleDescriptionTextView;
@property (weak, nonatomic) IBOutlet UIButton *runOnImageButton;
@property (weak, nonatomic) IBOutlet UIButton *runOnVideoButton;

- (void) setDetailItem:(SampleFacade*) sample;
- (void) configureView;

@end

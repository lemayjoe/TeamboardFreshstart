//
//  GLESView.h
//  Teamboard
//
// Copyright 2013, Joe Lemay, All Rights Reserved.  Confidential        \n6/26/12.

//

#import <UIKit/UIKit.h>

@interface GLESImageView : UIView

- (void)drawFrame:(const cv::Mat&) bgraFrame;


@end

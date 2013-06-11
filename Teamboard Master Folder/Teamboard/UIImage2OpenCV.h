//
//  UIImage_UIImage2OpenCV.h
//  Teamboard
//
// Copyright 2013, Joe Lemay, All Rights Reserved.  Confidential        \n6/25/12.

//


// This interface extension allows convert UIImage to cv::Mat representation and
// vice versa using full data copy in both directions.
@interface UIImage (OpenCV)

-(cv::Mat) toMat;

+(UIImage*) imageWithMat:(const cv::Mat&) image andImageOrientation: (UIImageOrientation) orientation;
+(UIImage*) imageWithMat:(const cv::Mat&) image andDeviceOrientation: (UIDeviceOrientation) orientation;

- (UIImage *)thumbnailWithSize:(int)thumbSize;

@end

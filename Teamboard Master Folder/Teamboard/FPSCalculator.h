//
//  FPSCalculator.h
//  Teamboard
//
// Copyright 2013, Joe Lemay, All Rights Reserved.  Confidential        \n7/4/12.

//

#import <Foundation/Foundation.h>

@interface FPSCalculator : NSObject

- (void) putTimeMark;

- (float) getFPS;

- (NSString*) getFPSAsText;

@end

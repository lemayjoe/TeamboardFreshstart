//
//  AppDelegate.h
//  Teamboard
//
// Copyright 2013, Joe Lemay, All Rights Reserved.  Confidential        \n6/23/12.

//

#import <UIKit/UIKit.h>
#import "SampleBase.h"
#import "SampleFacade.h"

@interface AppDelegate : UIResponder <UIApplicationDelegate>
{
@public
  std::vector<SampleFacade*> allSamples;
}
@property (strong, nonatomic) UIWindow *window;

@end

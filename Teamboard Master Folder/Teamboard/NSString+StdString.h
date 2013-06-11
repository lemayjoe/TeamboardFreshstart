//
//  NSString+StdString.h
//  Teamboard
//
// Copyright 2013, Joe Lemay, All Rights Reserved.  Confidential        \n7/9/12.

//

#import <Foundation/Foundation.h>

@interface NSString (StdString)

+ (NSString*) stringWithStdString: (const std::string&) str;

//- (std::string) toStdString;

@end

//
//  NSString+StdString.m
//  Teamboard
//
// Copyright 2013, Joe Lemay, All Rights Reserved.  Confidential        \n7/9/12.

//

#import "NSString+StdString.h"

@implementation NSString (StdString)

+ (NSString*) stringWithStdString: (const std::string&) str
{
  return [[NSString alloc] initWithCString:str.c_str() encoding:NSASCIIStringEncoding];
}

@end

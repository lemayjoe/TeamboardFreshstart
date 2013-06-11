//
//  OptionCell.h
//  Teamboard
//
// Copyright 2013, Joe Lemay, All Rights Reserved.  Confidential        \n7/11/12.

//

#import <UIKit/UIKit.h>
#import "SampleOptions.h"

@protocol OptionCellDelegate <NSObject>

- (void) optionDidChanged:(SampleOption*) option;

@end 


@interface OptionCell : UITableViewCell

@property (readonly) float cellHeight;
@property id<OptionCellDelegate> delegate;

@end

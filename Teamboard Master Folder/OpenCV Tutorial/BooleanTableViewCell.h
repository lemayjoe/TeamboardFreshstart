//
//  RangeValueTableViewCell.h
//  Teamboard
//
// Copyright 2013, Joe Lemay, All Rights Reserved.  Confidential        \n7/8/12.

//

#import <UIKit/UIKit.h>
#import "SampleOptions.h"
#import "OptionCell.h"

@interface BooleanTableViewCell : OptionCell

- (void) configureWithOption: (BooleanOption*) option;
- (IBAction)switchValueChanged:(id)sender;

@property BooleanOption * option;
@property (weak, nonatomic) IBOutlet UILabel *label;
@property (weak, nonatomic) IBOutlet UISwitch *switchValue;


@end

//
//  EnumTableViewCell.h
//  Teamboard
//
// Copyright 2013, Joe Lemay, All Rights Reserved.  Confidential        \n7/9/12.

//

#import <UIKit/UIKit.h>
#import "SampleOptions.h"
#import "OptionCell.h"

@interface EnumTableViewCell : OptionCell

@property StringEnumOption * option;

- (void) configureWithOption: (StringEnumOption*) option;

@property (weak, nonatomic) IBOutlet UILabel *label;
@property (weak, nonatomic) IBOutlet UISegmentedControl *segmentedControl;

- (IBAction)segmentedControlChanged:(id)sender;

@end

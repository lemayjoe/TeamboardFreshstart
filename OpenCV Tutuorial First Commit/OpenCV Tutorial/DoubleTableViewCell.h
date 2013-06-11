//
//  DoubleTableViewCell.h
//  Teamboard
//
// Copyright 2013, Joe Lemay, All Rights Reserved.  Confidential        \n7/30/12.

//

#import <UIKit/UIKit.h>
#import "SampleOptions.h"
#import "OptionCell.h"

@interface DoubleTableViewCell : OptionCell

@property (weak, nonatomic) IBOutlet UILabel *label;
@property (weak, nonatomic) IBOutlet UILabel *currentValue;
@property (weak, nonatomic) IBOutlet UISlider *sliderValue;

@property DoubleOption * option;

- (IBAction)sliderValueChanged:(id)sender;

- (void) configureWithOption: (DoubleOption*) option;


@end

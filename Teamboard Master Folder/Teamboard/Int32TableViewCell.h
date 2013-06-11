//
//  Int32TableViewCell.h
//  Teamboard
//
// Copyright 2013, Joe Lemay, All Rights Reserved.  Confidential        \n7/9/12.

//

#import <UIKit/UIKit.h>
#import "SampleOptions.h"
#import "OptionCell.h"

@interface Int32TableViewCell : OptionCell

@property (weak, nonatomic) IBOutlet UILabel *label;
@property (weak, nonatomic) IBOutlet UILabel *currentValue;
@property (weak, nonatomic) IBOutlet UISlider *sliderValue;

@property Int32Option * option;

- (IBAction)sliderValueChanged:(id)sender;

- (void) configureWithOption: (Int32Option*) option;

@end

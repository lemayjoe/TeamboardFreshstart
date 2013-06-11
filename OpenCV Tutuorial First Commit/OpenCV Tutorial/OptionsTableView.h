//
//  OptionsTableView.h
//  Teamboard
//
// Copyright 2013, Joe Lemay, All Rights Reserved.  Confidential        \n7/11/12.

//

#import <UIKit/UIKit.h>
#import "SampleFacade.h"
#import "OptionCell.h"

@interface OptionsTableView : UITableView

- (id) initWithFrame:(CGRect)frame 
               style:(UITableViewStyle)style 
              sample:(SampleFacade*) sample
notificationsDelegate:(id<OptionCellDelegate>) delegate;

@end

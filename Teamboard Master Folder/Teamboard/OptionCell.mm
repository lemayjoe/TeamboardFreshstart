//
//  OptionCell.m
//  Teamboard
//
// Copyright 2013, Joe Lemay, All Rights Reserved.  Confidential        \n7/11/12.

//

#import "OptionCell.h"

@implementation OptionCell
@synthesize delegate;
@synthesize cellHeight = _cellHeight;

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self) {
        // Initialization code
    }
    return self;
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated
{
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

- (void) awakeFromNib
{
  [super awakeFromNib];
  _cellHeight = self.bounds.size.height;
}


@end

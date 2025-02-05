//
//  SampleOptionsTableViewDelegate.h
//  Teamboard
//
// Copyright 2013, Joe Lemay, All Rights Reserved.  Confidential        \n7/9/12.

//

#import <Foundation/Foundation.h>

#import "SampleFacade.h"
#import "OptionCell.h"

@interface SampleOptionsTableViewDelegate : NSObject<UITableViewDelegate, UITableViewDataSource>

@property (readonly) SampleFacade * sample;
@property (readonly) id<OptionCellDelegate> delegate;

- (id) initWithSample:(SampleFacade*) sample notificationsDelegate:(id<OptionCellDelegate>) delegate;

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath;
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView;
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section;
- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section;

- (BOOL)tableView:(UITableView *)tableView canMoveRowAtIndexPath:(NSIndexPath *)indexPath;
- (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath;

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath;
- (NSIndexPath *)tableView:(UITableView *)tableView willSelectRowAtIndexPath:(NSIndexPath *)indexPath;

@end

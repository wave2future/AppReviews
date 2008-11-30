//
//  PSTitleValueCell.h
//  PSCommon
//
//  Created by Charles Gamble on 21/03/2008.
//  Copyright 2008 Charles Gamble. All rights reserved.
//

#import <UIKit/UIKit.h>


/**
 * UITableViewCell which displays a title and a value.
 * Maximum title width can be set using the titleWidth property.
 */
@interface PSTitleValueCell : UITableViewCell
{
	UILabel *titleLabel;
	UILabel *valueLabel;
	NSInteger titleWidth;
}

/**
 * Label for cell title.
 */
@property (nonatomic, retain) UILabel *titleLabel;

/**
 * Label for cell value.
 */
@property (nonatomic, retain) UILabel *valueLabel;

/**
 * Maximum title width.
 */
@property (nonatomic, assign) NSInteger titleWidth;

@end

//
//  PSAppStoreReviewsViewController.h
//  AppCritics
//
//  Created by Charles Gamble on 20/11/2008.
//  Copyright 2008 Charles Gamble. All rights reserved.
//

#import <UIKit/UIKit.h>


@class PSAppStoreApplicationDetails;


@interface PSAppStoreReviewsViewController : UITableViewController
{
	PSAppStoreApplicationDetails *appStoreDetails;
	NSArray *userReviews;
}

@property (nonatomic, retain) PSAppStoreApplicationDetails *appStoreDetails;
@property (nonatomic, retain) NSArray *userReviews;

@end

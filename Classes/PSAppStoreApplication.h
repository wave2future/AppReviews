//
//  PSAppStoreApplication.h
//  AppCritics
//
//  Created by Charles Gamble on 22/10/2008.
//  Copyright 2008 Charles Gamble. All rights reserved.
//

#import <Foundation/Foundation.h>


// Default to the US store as the apps "home store" (for looking up name, company, etc).
#define kDefaultStoreId	@"143441"


@class FMDatabase;


@interface PSAppStoreApplication : NSObject
{
	// Persistent members.
	NSString *appIdentifier;
	NSInteger position;
	// Persistent members (dehydrated).
	NSString *name;
	NSString *company;
	NSString *defaultStoreIdentifier;

    // Opaque reference to the underlying database.
    FMDatabase *database;
    // Primary key in the database.
    NSInteger primaryKey;
    // Hydrated tracks whether attribute data is in the object or the database.
    BOOL hydrated;
    // Dirty tracks whether there are in-memory changes to data which have no been written to the database.
    BOOL dirty;
}

@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *company;
@property (nonatomic, copy) NSString *appIdentifier;
@property (nonatomic, copy) NSString *defaultStoreIdentifier;
@property (nonatomic, assign) NSInteger position;
@property (nonatomic, assign, readonly) NSInteger primaryKey;

- (id)init;
- (id)initWithAppIdentifier:(NSString *)inAppIdentifier;
- (id)initWithName:(NSString *)inName appIdentifier:(NSString *)inAppIdentifier;
- (id)initWithName:(NSString *)inName company:(NSString *)inCompany appIdentifier:(NSString *)inAppIdentifier defaultStoreIdentifier:(NSString *)inStoreIdentifier;

// Creates the object with primary key and non-hydration members are brought into memory.
- (id)initWithPrimaryKey:(NSInteger)pk database:(FMDatabase *)db;
// Inserts the object into the database and stores its primary key.
- (void)insertIntoDatabase:(FMDatabase *)db;
// Write any changes to the database.
- (void)save;
// Brings the rest of the object data into memory. If already in memory, no action is taken (harmless no-op).
- (void)hydrate;
// Flushes all but the primary key and non-hydration members out to the database.
- (void)dehydrate;
// Remove the object completely from the database. In memory deletion to follow...
- (void)deleteFromDatabase;

@end

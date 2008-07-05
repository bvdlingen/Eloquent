/*	SwordBible.h - Sword API wrapper for Biblical Texts.

    Copyright 2008 Manfred Bergmann
    Based on code by Will Thimbleby

	This program is free software; you can redistribute it and/or modify it under the terms of the
	GNU General Public License as published by the Free Software Foundation version 2.

	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without
	even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
	General Public License for more details. (http://www.gnu.org/licenses/gpl.html)
*/

#import <Cocoa/Cocoa.h>
#import "SwordModule.h"

@class SwordModule, SwordManager;

typedef enum {
	OldTestament,
	NewTestament
}Testament;

@interface SwordBible : SwordModule <SwordModuleAccess> {
	NSMutableDictionary *bookData;
}

// ----------- class methods -------------
+ (void)decodeRef:(NSString *)ref intoBook:(NSString **)book chapter:(int *)chapter verse:(int *)verse;
+ (NSString *)firstRefName:(NSString *)abbr;
+ (NSString *)context:(NSString *)abbr;

// ----------- instance methods ------------
- (id)initWithName:(NSString *)name swordManager:(SwordManager *)aManager;
- (void)finalize;

- (BOOL)hasReference:(NSString *)ref;

// book names
- (NSArray *)bookNames;
- (NSArray *)engBookNames;

// some numbers
- (int)chaptersForBookName:(NSString *)bookName;
- (int)versesForChapter:(int)chapter bookName:(NSString *)bookName;
- (int)versesForBible;

// ------- SwordModuleAccess ---------
- (int)htmlForRef:(NSString *)reference html:(NSString **)htmlString;
- (long)entryCount;
- (void)writeEntry:(NSString *)value forRef:(NSString *)reference;

@end
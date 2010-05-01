//
//  HostableViewController.h
//  MacSword2
//
//  Created by Manfred Bergmann on 17.06.08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <CocoLogger/CocoLogger.h>
#import <ProtocolHelper.h>
#import <Indexer.h>

@class SearchTextFieldOptions;
@class WindowHostController;

@protocol HostViewDelegate

- (NSString *)title;
- (void)prepareContentForHost:(WindowHostController *)aHostController;

- (NSView *)topAccessoryView;
- (NSView *)rightAccessoryView;
- (BOOL)showsRightSideBar;
- (void)setShowingRSBPreferred:(BOOL)preferred;
- (void)searchTypeChanged:(SearchType)aSearchType withSearchString:(NSString *)aSearchString;
- (void)searchStringChanged:(NSString *)aSearchString;
- (void)forceReload;
- (SearchTextFieldOptions *)searchFieldOptions;
- (SearchType)preferedSearchType;
- (BOOL)enableReferenceSearch;
- (BOOL)enableIndexedSearch;
- (BOOL)enableAddBookmarks;
- (BOOL)enableForceReload;

@end

@interface HostableViewController : NSViewController <MouseTracking, HostViewDelegate, ContentSaving> {
    IBOutlet id delegate;
    IBOutlet WindowHostController *hostingDelegate;
    
    BOOL viewLoaded;    
    BOOL isLoadingComleteReported;
    BOOL showingRSBPreferred;
    
    SearchType searchType;
    NSString *searchString;
}

@property (assign, readwrite) id delegate;
@property (assign, readwrite) WindowHostController *hostingDelegate;
@property (readwrite) BOOL viewLoaded;
@property (readwrite) SearchType searchType;
@property (retain, readwrite) NSString *searchString;
@property (readwrite) BOOL showingRSBPreferred;

- (void)reportLoadingComplete;
- (void)removeFromSuperview;
- (void)adaptUIToHost;

// ContentSaving
- (BOOL)hasUnsavedContent;
- (void)saveContent;

// MouseTracking
- (void)mouseEntered:(NSView *)theView;
- (void)mouseExited:(NSView *)theView;

// HostViewDelegate
- (NSString *)title;
- (void)prepareContentForHost:(WindowHostController *)aHostController;
- (NSView *)topAccessoryView;
- (NSView *)rightAccessoryView;
- (BOOL)showsRightSideBar;
- (void)setShowingRSBPreferred:(BOOL)preferred;
- (void)searchTypeChanged:(SearchType)aSearchType withSearchString:(NSString *)aSearchString;
- (void)searchStringChanged:(NSString *)aSearchString;
- (void)forceReload;
- (SearchTextFieldOptions *)searchFieldOptions;
- (SearchType)preferedSearchType;
- (BOOL)enableReferenceSearch;
- (BOOL)enableIndexedSearch;
- (BOOL)enableAddBookmarks;
- (BOOL)enableForceReload;

@end

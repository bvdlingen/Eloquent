//
//  BibleTextViewController.h
//  MacSword2
//
//  Created by Manfred Bergmann on 14.06.08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <CocoLogger/CocoLogger.h>
#import <HostableViewController.h>
#import <ModuleViewController.h>
#import <ProtocolHelper.h>

@class SwordBible;
@class GradientCell;
@class SearchBookSetEditorController;

#define BIBLEVIEW_NIBNAME   @"BibleView"

@interface BibleViewController : ModuleViewController <NSCoding> {
    IBOutlet NSButton *closeBtn;
    IBOutlet NSPopUpButton *addPopBtn;
    IBOutlet NSPopUpButton *modulePopBtn;
    IBOutlet NSTextField *statusLine;
    
    IBOutlet NSView *sideBarView;
    IBOutlet NSOutlineView *entriesOutlineView;

    NSMenu *biblesMenu;
    NSMenu *commentariesMenu;
    
    // booksets controller
    SearchBookSetEditorController *searchBookSetsController;
    
    // gradient cell for outline view
    GradientCell *gradientCell;
    
    // nib name
    NSString *nibName;
        
    // bible book selection in right sidebar
    NSMutableArray *bookSelection;
    
    // text display context
    NSInteger textContext;
}

@property (retain, readwrite) NSString *nibName;
@property (retain, readwrite) NSMutableArray *bookSelection;
@property (readwrite) NSInteger textContext;

// ---------- initializers ---------
- (id)initWithModule:(SwordBible *)aModule;
- (id)initWithModule:(SwordBible *)aModule delegate:(id)aDelegate;
- (id)initWithDelegate:(id)aDelegate;

// ----------- methods -------------
// searchBookSetsController
- (SearchBookSetEditorController *)searchBookSetsController;

// pass further the scrollview
- (NSScrollView *)scrollView;

- (void)setStatusText:(NSString *)aText;
- (void)populateAddPopupMenu;

// selector called by menuitems
- (void)moduleSelectionChanged:(id)sender;

// actions
- (IBAction)addModule:(id)sender;
- (IBAction)closeButton:(id)sender;

@end

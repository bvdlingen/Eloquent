//
//  HostableViewController.h
//  MacSword2
//
//  Created by Manfred Bergmann on 17.06.08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <CocoLogger/CocoLogger.h>

@interface HostableViewController : NSViewController {
    // the delegate
    IBOutlet id delegate;
    
    // is view loaded?
    BOOL viewLoaded;    
}

// properties
@property (assign, readwrite) id delegate;
@property (readwrite) BOOL viewLoaded;

/** report the loading of the view is completed */
- (void)reportLoadingComplete;
- (void)removeFromSuperview;

@end

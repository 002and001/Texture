//
//  ASContextTransitioning.h
//  AsyncDisplayKit
//
//  Created by Levi McCallum on 2/4/16.
//  Copyright © 2016 Facebook. All rights reserved.
//

#import <AsyncDisplayKit/ASDisplayNode.h>

@protocol ASContextTransitioning <NSObject>

/**
 @abstreact Defines if the given transition is animated
 */
- (BOOL)isAnimated;

/**
 * @abstract The destination layout being transitioned to
 */
- (ASLayout *)layout;

/**
 * @abstrat The destination constrainedSize being transitioned to
 */
- (ASSizeRange)constrainedSize;

/**
 * @abstract Subnodes in the new layout
 */
- (NSArray<ASDisplayNode *> *)subnodes;

/**
 * @abstract Subnodes that have been inserted in the layout transition
 */
- (NSArray<ASDisplayNode *> *)insertedSubnodes;

/**
 * @abstract Subnodes that will be removed in the layout transition
 */
- (NSArray<ASDisplayNode *> *)removedSubnodes;

/**
 @abstract The frame for the given node before the transition began.
 @discussion Returns CGRectNull if the node was not in the hierarchy before the transition.
 */
- (CGRect)initialFrameForNode:(ASDisplayNode *)node;

/**
 @abstract The frame for the given node when the transition completes.
 @discussion Returns CGRectNull if the node is no longer in the hierarchy after the transition.
 */
- (CGRect)finalFrameForNode:(ASDisplayNode *)node;

/**
 @abstract Invoke this method when the transition is completed in `animateLayoutTransition:`
 @discussion Passing NO to `didComplete` will set the original layout as the new layout.
 */
- (void)completeTransition:(BOOL)didComplete;

@end

//
//  ASVideoPlayerNode.h
//  AsyncDisplayKit
//
//  Created by Erekle on 5/6/16.
//  Copyright © 2016 Facebook. All rights reserved.
//

#if TARGET_OS_IOS
#import <AsyncDisplayKit/AsyncDisplayKit.h>
//#import <AsyncDisplayKit/ASThread.h>
//#import <AsyncDisplayKit/ASVideoNode.h>
//#import <AsyncDisplayKit/ASDisplayNode+Subclasses.h>

@class AVAsset;
@protocol ASVideoPlayerNodeDelegate;

typedef enum {
  ASVideoPlayerNodeControlTypePlaybackButton,
  ASVideoPlayerNodeControlTypeElapsedText,
  ASVideoPlayerNodeControlTypeDurationText,
  ASVideoPlayerNodeControlTypeScrubber,
  ASVideoPlayerNodeControlTypeFlexGrowSpacer,
} ASVideoPlayerNodeControlType;

NS_ASSUME_NONNULL_BEGIN

@interface ASVideoPlayerNode : ASDisplayNode

@property (nullable, atomic, weak, readwrite) id<ASVideoPlayerNodeDelegate> delegate;

@property (nonatomic,assign,readonly) CGFloat duration;

- (instancetype)initWithUrl:(NSURL*)url;
- (instancetype)initWithAsset:(AVAsset*)asset;

#pragma mark - Public API
-(void)seekToTime:(CGFloat)percentComplete;

@end

@protocol ASVideoPlayerNodeDelegate <NSObject>
@optional
/**
 * @abstract Delegate method invoked before creating controlbar controls
 * @param videoPlayer
 */
- (NSArray *)videoPlayerNodeNeededControls:(ASVideoPlayerNode*)videoPlayer;
- (UIColor *)videoPlayerNodeScrubberMaximumTrackTint:(ASVideoPlayerNode*)videoPlayer;
- (UIColor *)videoPlayerNodeScrubberMinimumTrackTint:(ASVideoPlayerNode*)videoPlayer;
- (UIColor *)videoPlayerNodeScrubberThumbTint:(ASVideoPlayerNode*)videoPlayer;
@end
NS_ASSUME_NONNULL_END
#endif

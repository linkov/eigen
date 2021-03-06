#import "ARModelCollectionViewModule.h"
#import "ARCollectionViewMasonryLayout.h"

typedef NS_ENUM(NSInteger, ARArtworkMasonryLayout){
    ARArtworkMasonryLayout1Row,
    ARArtworkMasonryLayout2Row,
    ARArtworkMasonryLayout1Column,
    ARArtworkMasonryLayout2Column,
    ARArtworkMasonryLayout3Column,
    ARArtworkMasonryLayout4Column
};

@class ARArtworkMasonryModule;

// A protocol to standardize the way we provide different layout styles to the module.
@protocol ARArtworkMasonryLayoutProvider <NSObject>
- (enum ARArtworkMasonryLayout)masonryLayoutForPadWithOrientation:(UIInterfaceOrientation)orientation;
@end

@interface ARArtworkMasonryModule : ARModelCollectionViewModule <ARCollectionViewMasonryLayoutDelegate>

/// Create a masonry based module, uses the presentation style of artwork only
+ (instancetype)masonryModuleWithLayout:(enum ARArtworkMasonryLayout)layout;

/// Designated initializer. Creates a masonry module with a specific artwork style
+ (instancetype)masonryModuleWithLayout:(enum ARArtworkMasonryLayout)layout andStyle:(enum AREmbeddedArtworkPresentationStyle)style;

/// Get the height of the collection view for a horizontal layout
+ (CGFloat)intrinsicHeightForHorizontalLayout:(ARArtworkMasonryLayout)layout;

/// Gets the intrinsic property from an existing instance
- (CGSize)intrinsicSize;

/// The module layout provided and managed by this class
/// for use in a AREmbeddedModelsViewController
@property (nonatomic, readonly) ARCollectionViewMasonryLayout *moduleLayout;

/// The specific layout
@property (nonatomic, assign, readwrite) enum ARArtworkMasonryLayout layout;

@property (nonatomic, weak, readwrite) id<ARArtworkMasonryLayoutProvider> layoutProvider;

/// The artwork presentation style
@property (nonatomic, assign, readonly) enum AREmbeddedArtworkPresentationStyle style;

@property (nonatomic, assign) BOOL showTrailingLoadingIndicator;

@end

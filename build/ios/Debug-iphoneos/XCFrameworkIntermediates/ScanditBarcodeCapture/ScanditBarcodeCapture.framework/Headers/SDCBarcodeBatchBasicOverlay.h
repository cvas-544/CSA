/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCDataCaptureOverlay.h>

@class SDCBarcodeBatch;
@class SDCBrush;
@class SDCTrackedBarcode;
@class SDCBarcodeBatchBasicOverlay;
@class SDCDataCaptureView;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 7.0.0
 *
 * The style of the SDCBarcodeBatchBasicOverlay
 */
typedef NS_CLOSED_ENUM(NSUInteger, SDCBarcodeBatchBasicOverlayStyle) {
/**
     * Added in version 7.0.0
     *
     * Style that draws the highlights as a rectangular frame and adds an animation for when a code newly appears.
     */
    SDCBarcodeBatchBasicOverlayStyleFrame NS_SWIFT_NAME(frame),
/**
     * Added in version 7.0.0
     *
     * Style that draws the highlights as a dot and adds an animation for when a code newly appears.
     */
    SDCBarcodeBatchBasicOverlayStyleDot NS_SWIFT_NAME(dot)
} NS_SWIFT_NAME(BarcodeBatchBasicOverlayStyle);

/**
 * Added in version 7.0.0
 *
 * Returns the string representation of the overlay style.
 */
SDC_EXTERN NSString *_Nonnull NSStringFromBarcodeBatchBasicOverlayStyle(SDCBarcodeBatchBasicOverlayStyle overlayStyle)
    NS_SWIFT_NAME(getter:SDCBarcodeBatchBasicOverlayStyle.jsonString(self:));

/**
 * Added in version 7.0.0
 */
NS_SWIFT_NAME(BarcodeBatchBasicOverlayDelegate)
@protocol SDCBarcodeBatchBasicOverlayDelegate <NSObject>

/**
 * Added in version 7.0.0
 *
 * Callback method that can be used to set a SDCBrush for a tracked barcode. It is called when a new tracked barcode appears. Called from the rendering thread.
 * If the callback returns nil, then no visualization will be drawn for the tracked barcode. Additionally, tapping on the barcode will have no effect - the action defined by barcodeBatchBasicOverlay:didTapTrackedBarcode: callback will not be performed.
 */
- (nullable SDCBrush *)barcodeBatchBasicOverlay:(nonnull SDCBarcodeBatchBasicOverlay *)overlay
                         brushForTrackedBarcode:(nonnull SDCTrackedBarcode *)trackedBarcode;

/**
 * Added in version 7.0.0
 *
 * Callback method that can be used to define an action that should be performed once a tracked barcode is tapped. Called from the main thread.
 *
 * If you are adding a UIGestureRecognizer to the data capture view, ensure that the cancelsTouchesInView property is set to NO as otherwise tap gestures will be cancelled instead of successfully completing.
 */
- (void)barcodeBatchBasicOverlay:(nonnull SDCBarcodeBatchBasicOverlay *)overlay
            didTapTrackedBarcode:(nonnull SDCTrackedBarcode *)trackedBarcode;

@end

/**
 * Added in version 7.0.0
 *
 * An overlay for SDCDataCaptureView that shows a simple augmentation over each tracked barcode.
 *
 * To display the augmentations, this overlay must be attached to a SDCDataCaptureView. This may be done either by creating it with overlayWithBarcodeBatch:forDataCaptureView: with a non-null view parameter or by passing this overlay to SDCDataCaptureView.addOverlay:.
 *
 * A user of this class may configure the appearance of the augmentations by implementing  SDCBarcodeBatchBasicOverlayDelegate or by calling setBrush:forTrackedBarcode:.
 *
 * For additional information about using this overlay, refer to MatrixScan Get Started guide.
 */
NS_SWIFT_NAME(BarcodeBatchBasicOverlay)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeBatchBasicOverlay : NSObject <SDCDataCaptureOverlay>

/**
 * Added in version 7.0.0
 *
 * The delegate which is called whenever a new TrackedBarcode is newly tracked or newly recognized.
 *
 * @remark Using this delegate requires the MatrixScan AR add-on.
 */
@property (nonatomic, weak, nullable) id<SDCBarcodeBatchBasicOverlayDelegate> delegate;
/**
 * Added in version 7.0.0
 *
 * The brush applied to recognized tracked barcodes if SDCBarcodeBatchBasicOverlayDelegate is not implemented.
 *
 * By default the value is set to defaultBrushForStyle:.
 *
 * Setting this brush to nil hides all tracked barcodes, unless setBrush:forTrackedBarcode: is called.
 */
@property (nonatomic, strong, nullable) SDCBrush *brush;
/**
 * Added in version 7.0.0
 *
 * The overlay style. Defaults to Frame.
 */
@property (nonatomic, readonly) SDCBarcodeBatchBasicOverlayStyle style;
/**
 * Added in version 7.0.0
 *
 * When set to YES, this overlay will visualize the active scan area used for BarcodeBatch. This is useful to check margins defined on the SDCDataCaptureView are set correctly. This property is meant for debugging during development and is not intended for use in production.
 *
 * By default this property is NO.
 */
@property (nonatomic, assign) BOOL shouldShowScanAreaGuides;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 7.0.0
 *
 * Constructs a new Barcode Batch basic overlay for the Barcode Batch instance. For the overlay to be displayed on screen, it must be added to a SDCDataCaptureView.
 */
+ (instancetype)overlayWithBarcodeBatch:(nonnull SDCBarcodeBatch *)barcodeBatch;
/**
 * Added in version 7.0.0
 *
 * Constructs a new Barcode Batch basic overlay for the Barcode Batch instance. The overlay is automatically added to the view.
 */
+ (instancetype)overlayWithBarcodeBatch:(nonnull SDCBarcodeBatch *)barcodeBatch
                     forDataCaptureView:(nullable SDCDataCaptureView *)view
    NS_SWIFT_NAME(init(barcodeBatch:view:));
;

/**
 * Added in version 7.0.0
 *
 * Constructs a new Barcode Batch basic overlay for the Barcode Batch instance with the specified style. For the overlay to be displayed on screen, it must be added to a SDCDataCaptureView.
 */
+ (instancetype)overlayWithBarcodeBatch:(nonnull SDCBarcodeBatch *)barcodeBatch
                              withStyle:(SDCBarcodeBatchBasicOverlayStyle)style;
/**
 * Added in version 7.0.0
 *
 * Constructs a new Barcode Batch basic overlay for the Barcode Batch instance with the specified style. The overlay is automatically added to the view.
 */
+ (instancetype)overlayWithBarcodeBatch:(nonnull SDCBarcodeBatch *)barcodeBatch
                     forDataCaptureView:(nullable SDCDataCaptureView *)view
                              withStyle:(SDCBarcodeBatchBasicOverlayStyle)style
    NS_SWIFT_NAME(init(barcodeBatch:view:style:));

/**
 * Added in version 7.0.0
 *
 * Constructs a new Barcode Batch basic overlay with the provided JSON serialization.
 *
 * For the overlay to be displayed on screen, it must be added to a SDCDataCaptureView.
 */
+ (nullable instancetype)barcodeBatchBasicOverlayFromJSONString:(nonnull NSString *)JSONString
                                                              mode:(nonnull SDCBarcodeBatch *)mode
                                                             error:(NSError *_Nullable *_Nullable)error
    NS_SWIFT_NAME(init(jsonString:barcodeBatch:));

/**
 * Added in version 7.0.0
 *
 * Returns the default brush for the given style.
 */
+ (nonnull SDCBrush *)defaultBrushForStyle:(SDCBarcodeBatchBasicOverlayStyle)style
    NS_SWIFT_NAME(defaultBrush(forStyle:));

/**
 * Added in version 7.0.0
 *
 * Updates the overlay according to a JSON serialization.
 */
- (BOOL)updateFromJSONString:(nonnull NSString *)JSONString
                       error:(NSError *_Nullable *_Nullable)error;

/**
 * Added in version 7.0.0
 *
 * The method can be called to change the visualization style of a tracked barcode. This method is thread-safe, it can be called from any thread.
 * If the brush is nil, then no visualization will be drawn for the tracked barcode. Additionally, tapping on the barcode will have no effect - the action defined by SDCBarcodeBatchBasicOverlayDelegate.barcodeBatchBasicOverlay:didTapTrackedBarcode: callback will not be performed.
 *
 * @remark Using this function requires the MatrixScan AR add-on.
 */
- (void)setBrush:(nullable SDCBrush *)brush
    forTrackedBarcode:(nonnull SDCTrackedBarcode *)trackedBarcode;

/**
 * Added in version 7.0.0
 *
 * Clears all currently displayed visualizations for the tracked barcodes.
 *
 * This only applies to the currently tracked barcodes, the visualizations for the new ones will still appear.
 */
- (void)clearTrackedBarcodeBrushes;

@end

NS_ASSUME_NONNULL_END

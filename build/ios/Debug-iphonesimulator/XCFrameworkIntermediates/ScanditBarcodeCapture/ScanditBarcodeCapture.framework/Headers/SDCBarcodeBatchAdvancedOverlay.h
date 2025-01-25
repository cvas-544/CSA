/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <UIKit/UIKit.h>

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCDataCaptureOverlay.h>
#import <ScanditCaptureCore/SDCAnchor.h>
#import <ScanditCaptureCore/SDCMeasureUnit.h>

@class SDCBarcodeBatch;
@class SDCDataCaptureView;
@class SDCTrackedBarcode;
@class SDCBarcodeBatchAdvancedOverlay;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 7.0.0
 */
NS_SWIFT_NAME(BarcodeBatchAdvancedOverlayDelegate)
@protocol SDCBarcodeBatchAdvancedOverlayDelegate <NSObject>

/**
 * Added in version 7.0.0
 *
 * View to be drawn corresponding to the given SDCTrackedBarcode.
 * This method will be called before barcodeBatchAdvancedOverlay:anchorForTrackedBarcode: and barcodeBatchAdvancedOverlay:offsetForTrackedBarcode:.
 * Beware that this view can be overridden with SDCBarcodeBatchAdvancedOverlay.setView:forTrackedBarcode: method.
 * This method will only be called for new tracked barcodes that do not have a view yet, e.g. a view set by a call to SDCBarcodeBatchAdvancedOverlay.setView:forTrackedBarcode:.
 *
 * Called from the main thread.
 *
 * @remark Requires a special license key to support rendering any kind of images since this feature is available only in limited countries. Please contact support@scandit.com for details
 */
- (nullable UIView *)barcodeBatchAdvancedOverlay:(nonnull SDCBarcodeBatchAdvancedOverlay *)overlay
                           viewForTrackedBarcode:(nonnull SDCTrackedBarcode *)trackedBarcode;

/**
 * Added in version 7.0.0
 *
 * Anchor point that should be used for the view corresponding to the given SDCTrackedBarcode.
 * This method will be called after barcodeBatchAdvancedOverlay:viewForTrackedBarcode: and before barcodeBatchAdvancedOverlay:offsetForTrackedBarcode:.
 * Beware that this anchor can be overridden with SDCBarcodeBatchAdvancedOverlay.setAnchor:forTrackedBarcode: method.
 * This method will only be called for new tracked barcodes that do not have an anchor yet, e.g. an anchor set by a call to SDCBarcodeBatchAdvancedOverlay.setAnchor:forTrackedBarcode:.
 *
 * Called from the main thread.
 */
- (SDCAnchor)barcodeBatchAdvancedOverlay:(nonnull SDCBarcodeBatchAdvancedOverlay *)overlay
                 anchorForTrackedBarcode:(nonnull SDCTrackedBarcode *)trackedBarcode;

/**
 * Added in version 7.0.0
 *
 * Offset to be set to the view corresponding to the given SDCTrackedBarcode. The offset is relative to the anchor point of the tracked barcode.
 * This method will be called after barcodeBatchAdvancedOverlay:viewForTrackedBarcode: and barcodeBatchAdvancedOverlay:anchorForTrackedBarcode:.
 * Beware that this offset can be overridden with SDCBarcodeBatchAdvancedOverlay.setOffset:forTrackedBarcode: method.
 * This method will only be called for new tracked barcodes that do not have an offset yet, e.g. an offset set by a call to SDCBarcodeBatchAdvancedOverlay.setOffset:forTrackedBarcode:.
 *
 * Called from the main thread.
 */
- (SDCPointWithUnit)barcodeBatchAdvancedOverlay:(nonnull SDCBarcodeBatchAdvancedOverlay *)overlay
                        offsetForTrackedBarcode:(nonnull SDCTrackedBarcode *)trackedBarcode;

@end

/**
 * Added in version 7.0.0
 *
 * An overlay for SDCDataCaptureView that allows anchoring a single user-provided View to each tracked barcode.
 *
 * The provided view is visible on the top of the camera preview as long as its tracked barcode is and for all this time retains its relative position to it. This is useful when an additional information should be provided to tracked barcodes in real time. For instance, a user may overlay the price of an item or its expiry date for each corresponding barcode.
 *
 * To display the views, this overlay must be attached to a SDCDataCaptureView. This may be done either by creating it with overlayWithBarcodeBatch:forDataCaptureView: with a non-null view parameter or by passing this overlay to SDCDataCaptureView.addOverlay:.
 *
 * A user of this class may configure what view is displayed for the given barcode and the relative position between the two by implementing SDCBarcodeBatchAdvancedOverlayDelegate or by calling setView:forTrackedBarcode:, setAnchor:forTrackedBarcode: or setOffset:forTrackedBarcode:.
 *
 * For additional information about using this overlay, refer to Adding AR Overlays .
 */
NS_SWIFT_NAME(BarcodeBatchAdvancedOverlay)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeBatchAdvancedOverlay : UIView <SDCDataCaptureOverlay>

/**
 * Added in version 7.0.0
 */
@property (nonatomic, weak, nullable) id<SDCBarcodeBatchAdvancedOverlayDelegate> delegate;
/**
 * Added in version 7.0.0
 *
 * Whether to show scan area guides on top of the preview. This property is useful during development to visualize the current scan areas on screen. It is not meant to be used for production. By default this property is NO.
 */
@property (nonatomic, assign) BOOL shouldShowScanAreaGuides;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;
- (instancetype)initWithCoder:(NSCoder *)decoder NS_UNAVAILABLE;

/**
 * Added in version 7.0.0
 *
 * Constructs a new Barcode Batch advanced overlay for the Barcode Batch instance. The overlay is automatically added to the view.
 */
+ (instancetype)overlayWithBarcodeBatch:(nonnull SDCBarcodeBatch *)barcodeBatch
                     forDataCaptureView:(nullable SDCDataCaptureView *)view
    NS_SWIFT_NAME(init(barcodeBatch:view:));

/**
 * Added in version 7.0.0
 *
 * Constructs a new Barcode Batch advanced overlay with the provided JSON serialization.
 *
 * For the overlay to be displayed on screen, it must be added to a SDCDataCaptureView.
 */
+ (nullable instancetype)barcodeBatchAdvancedOverlayFromJSONString:(nonnull NSString *)JSONString
                                                                 mode:(nonnull SDCBarcodeBatch *)mode
                                                                error:(NSError *_Nullable *_Nullable)error NS_SWIFT_NAME(init(jsonString:barcodeBatch:));

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
 * The method can be called to change the view drawn for the given tracked barcode. Setting the view to nil will unset the view from the tracked barcode and will effectively remove it from the overlay.
 * This method is thread-safe, it can be called from any thread.
 * The view set via this method will take precedence over the one set via SDCBarcodeBatchAdvancedOverlayDelegate.barcodeBatchAdvancedOverlay:viewForTrackedBarcode:: in case a view is set before SDCBarcodeBatchAdvancedOverlayDelegate.barcodeBatchAdvancedOverlay:viewForTrackedBarcode: got called, no call to SDCBarcodeBatchAdvancedOverlayDelegate.barcodeBatchAdvancedOverlay:viewForTrackedBarcode: will happen.
 *
 * @remark Requires a special license key to support rendering any kind of images since this feature is available only in limited countries. Please contact support@scandit.com for details
 */
- (void)setView:(nullable UIView *)view
    forTrackedBarcode:(nonnull SDCTrackedBarcode *)trackedBarcode;
/**
 * Added in version 7.0.0
 *
 * The method can be called to change the anchor point for the view associated with the given tracked barcode. This method is thread-safe, it can be called from any thread.
 * The anchor set via this method will take precedence over the one set via SDCBarcodeBatchAdvancedOverlayDelegate.barcodeBatchAdvancedOverlay:anchorForTrackedBarcode:: in case a view is set before SDCBarcodeBatchAdvancedOverlayDelegate.barcodeBatchAdvancedOverlay:anchorForTrackedBarcode: got called, no call to SDCBarcodeBatchAdvancedOverlayDelegate.barcodeBatchAdvancedOverlay:anchorForTrackedBarcode: will happen.
 */
- (void)setAnchor:(SDCAnchor)anchor forTrackedBarcode:(nonnull SDCTrackedBarcode *)trackedBarcode;
/**
 * Added in version 7.0.0
 *
 * The method can be called to change the offset for the view associated with the given tracked barcode. This method is thread-safe, it can be called from any thread.
 * The offset set via this method will take precedence over the one set via SDCBarcodeBatchAdvancedOverlayDelegate.barcodeBatchAdvancedOverlay:offsetForTrackedBarcode:: in case a view is set before SDCBarcodeBatchAdvancedOverlayDelegate.barcodeBatchAdvancedOverlay:offsetForTrackedBarcode: got called, no call to SDCBarcodeBatchAdvancedOverlayDelegate.barcodeBatchAdvancedOverlay:offsetForTrackedBarcode: will happen.
 * If the SDCMeasureUnit of the offset is SDCMeasureUnitFraction, the offset is calculated relative to view’s dimensions.
 */
- (void)setOffset:(SDCPointWithUnit)offset
    forTrackedBarcode:(nonnull SDCTrackedBarcode *)trackedBarcode;
/**
 * Added in version 7.0.0
 *
 * Clears all the views for the currently tracked barcodes from this overlay.
 * This method is thread-safe, it can be called from any thread.
 */
- (void)clearTrackedBarcodeViews;

@end

NS_ASSUME_NONNULL_END

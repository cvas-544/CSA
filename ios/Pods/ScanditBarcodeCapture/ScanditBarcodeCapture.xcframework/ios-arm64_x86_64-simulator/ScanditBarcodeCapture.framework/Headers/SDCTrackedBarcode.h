/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCQuadrilateral.h>
#import <ScanditCaptureCore/SDCAnchor.h>
#import <ScanditBarcodeCapture/SDCSymbology.h>

@class SDCTrackedBarcodeInfo;
@class SDCBarcode;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.0.0
 *
 * A barcode tracked over the course of multiple frames.
 *
 * The state of a SDCTrackedBarcode can be observed using a SDCBarcodeBatchListener.
 *
 * The SDCBarcodeBatchListener.barcodeBatch:didUpdate:frameData: callback will be invoked every time a new frame is processed and at least one of the following events took place:
 *
 *   1. A track is established.
 *
 *   2. A track location has changed.
 *
 *   3. A track is lost and can no longer be tracked.
 */
NS_SWIFT_NAME(TrackedBarcode)
SDC_EXPORTED_SYMBOL
@interface SDCTrackedBarcode : NSObject

/**
 * Added in version 6.4.0
 *
 * The location of the code. The coordinates are in image-space, meaning that the coordinates correspond to actual pixels in the image. For display, the coordinates need first to be converted into screen-space using the data capture view.
 *
 * The meaning of the values of SDCQuadrilateral.topLeft is such that the top left point corresponds to the top left corner of the barcode, independent of how the code is oriented in the image. Same for the other conrners.
 *
 * @remark Using this property requires the MatrixScan AR add-on. In case the feature is not licensed, a quadrilateral with all corners set to 0, 0 is returned.
 */
@property (nonatomic, readonly) SDCQuadrilateral location;
/**
 * Added in version 6.0.0
 *
 * The unique identifier for the tracked barcode. The identifier is unique for each barcode. The same identifier may be reused once the barcode is lost for another barcode.
 */
@property (nonatomic, readonly) NSInteger identifier;
/**
 * Added in version 6.0.0
 *
 * The barcode associated to this track.
 */
@property (nonatomic, nonnull, readonly) SDCBarcode *barcode;
/**
 * Added in version 6.2.0
 *
 * Returns the JSON representation of the tracked barcode.
 */
@property (nonatomic, nonnull, readonly) NSString *JSONString;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.10.0
 *
 * Constructs a TrackedBarcode instance using the specified information. Can be used to create mocks for unit testing
 */
+ (instancetype)trackedBarcodeWithTrackedBarcodeInfo:(SDCTrackedBarcodeInfo *)trackedBarcodeInfo
    NS_SWIFT_UNAVAILABLE("Use initializer instead");

/**
 * Added in version 6.13.0
 *
 * Constructs a TrackedBarcode instance using the specified information. Can be used to create mocks for unit testing
 */
- (instancetype)initWithTrackedBarcodeInfo:(SDCTrackedBarcodeInfo *)trackedBarcodeInfo;

/**
 * Added in version 6.4.0
 *
 * The position of an anchor point of the tracked barcode.
 */
- (CGPoint)anchorPosition:(SDCAnchor)anchor;

@end

NS_ASSUME_NONNULL_END

/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCDataCaptureMode.h>

@class SDCDataCaptureContext;
@class SDCBarcodeBatch;
@class SDCBarcodeBatchSettings;
@class SDCBarcodeBatchSession;
@class SDCCameraSettings;
@class SDCBarcodeBatchLicenseInfo;
@protocol SDCFrameData;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 7.0.0
 *
 * The BarcodeBatch delegate is the main way for hooking into BarcodeBatch. It provides a callback that is invoked when the state of tracked barcodes changes.
 */
NS_SWIFT_NAME(BarcodeBatchListener)
@protocol SDCBarcodeBatchListener <NSObject>

@required

/**
 * Added in version 7.0.0
 *
 * Invoked after Barcode Batch has completed to process a frame.
 */
- (void)barcodeBatch:(nonnull SDCBarcodeBatch *)barcodeBatch
           didUpdate:(nonnull SDCBarcodeBatchSession *)session
           frameData:(nonnull id<SDCFrameData>)frameData;

@optional

/**
 * Added in version 7.0.0
 *
 * Called when the listener starts observing the BarcodeBatch instance.
 */
- (void)didStartObservingBarcodeBatch:(nonnull SDCBarcodeBatch *)barcodeBatch;

/**
 * Added in version 7.0.0
 *
 * Called when the listener stops observing the BarcodeBatch instance.
 */
- (void)didStopObservingBarcodeBatch:(nonnull SDCBarcodeBatch *)barcodeBatch;

@end

/**
 * Added in version 6.0.0
 *
 * Data capture mode that implements MatrixScan (Barcode Batch).
 *
 * Learn more on how to use Barcode Batch in our Get Started guide.
 *
 * Same as applySettings:completionHandler: with the second argument set to nil.
 */
NS_SWIFT_NAME(BarcodeBatch)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeBatch : NSObject <SDCDataCaptureMode>

/**
 * Added in version 7.0.0
 *
 * Returns the recommended camera settings for use with Barcode Batch.
 */
@property (class, nonatomic, nonnull, readonly) SDCCameraSettings *recommendedCameraSettings;
/**
 * Added in version 7.0.0
 *
 * Implemented from SDCDataCaptureMode. See SDCDataCaptureMode.context.
 */
@property (nonatomic, nullable, readonly) SDCDataCaptureContext *context;
/**
 * Added in version 7.0.0
 *
 * Implemented from SDCDataCaptureMode. See SDCDataCaptureMode.enabled.
 */
@property (nonatomic, assign, getter=isEnabled) BOOL enabled;
/**
 * Added in version 7.0.0
 *
 * The object containing information about Barcode Batch licensing.
 *
 * @remark This value is available with a small delay. To make sure it is available, set a SDCDataCaptureContextListener and, as soon as SDCDataCaptureContextListener.context:didAddMode: is called, this license object is available.
 */
@property (nonatomic, nullable, readonly) SDCBarcodeBatchLicenseInfo *barcodeBatchLicenseInfo;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 7.0.0
 *
 * Constructs a new Barcode Batch mode with the provided context and settings. When the context is not nil, the capture mode is automatically added to the context.
 */
+ (instancetype)barcodeBatchWithContext:(nullable SDCDataCaptureContext *)context
                               settings:(nonnull SDCBarcodeBatchSettings *)settings;

/**
 * Added in version 7.0.0
 *
 * Constructs a new Barcode Batch mode with the provided JSON serialization. The capture mode is automatically added to the context.
 */
+ (nullable instancetype)barcodeBatchFromJSONString:(nonnull NSString *)JSONString
                                            context:(nonnull SDCDataCaptureContext *)context
                                              error:(NSError *_Nullable *_Nullable)error
    NS_SWIFT_NAME(init(jsonString:context:));

/**
 * Added in version 7.0.0
 *
 * Asynchronously applies the new settings to the barcode scanner. If the scanner is currently running, the task will complete when the next frame is processed, and will use the new settings for that frame. If the scanner is currently not running, the task will complete as soon as the settings have been stored and won’t wait until the next frame is going to be processed.
 */
- (void)applySettings:(nonnull SDCBarcodeBatchSettings *)settings
    completionHandler:(nullable void (^)(void))completionHandler;
/**
 * Added in version 7.0.0
 *
 * Adds the listener to observe this barcode capture instance.
 *
 * In case the same listener is already observing this instance, calling this method will not add the listener again. The listener is stored using a weak reference and must thus be retained by the caller for it to not go out of scope.
 */
- (void)addListener:(nonnull id<SDCBarcodeBatchListener>)listener NS_SWIFT_NAME(addListener(_:));
/**
 * Added in version 7.0.0
 *
 * Removes a previously added listener from this Barcode Batch instance.
 *
 * In case the listener is not currently observing this instance, calling this method has no effect.
 */
- (void)removeListener:(nonnull id<SDCBarcodeBatchListener>)listener
    NS_SWIFT_NAME(removeListener(_:));

/**
 * Added in version 7.0.0
 *
 * Updates the mode according to a JSON serialization.
 */
- (BOOL)updateFromJSONString:(nonnull NSString *)JSONString
                       error:(NSError *_Nullable *_Nullable)error;

@end

NS_ASSUME_NONNULL_END

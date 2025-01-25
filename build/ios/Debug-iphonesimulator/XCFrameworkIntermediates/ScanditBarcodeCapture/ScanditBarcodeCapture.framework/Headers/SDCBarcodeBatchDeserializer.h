/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCDataCaptureModeDeserializer.h>
#import <ScanditCaptureCore/SDCBase.h>

@class SDCBarcodeBatch;
@class SDCDataCaptureContext;
@class SDCBarcodeBatchSettings;
@class SDCBarcodeBatchBasicOverlay;
@class SDCBarcodeBatchAdvancedOverlay;
@protocol SDCBarcodeBatchDeserializerDelegate;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 7.0.0
 *
 * A deserializer to construct Barcode Batch from JSON. For most use cases it is enough to use SDCBarcodeBatch.barcodeBatchFromJSONString:context:error: which internally uses this deserializer. Using the deserializer gives the advantage of being able to listen to the deserialization events as they happen and potentially influence them. Additionally warnings can be read from the deserializer that would otherwise not be available.
 */
NS_SWIFT_NAME(BarcodeBatchDeserializer)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeBatchDeserializer : NSObject <SDCDataCaptureModeDeserializer>

/**
 * Added in version 7.0.0
 *
 * The object informed about deserialization events.
 */
@property (nonatomic, weak, nullable) id<SDCBarcodeBatchDeserializerDelegate> delegate;
/**
 * Added in version 7.0.0
 *
 * The warnings produced during deserialization, for example which properties were not used during deserialization.
 */
@property (nonatomic, readonly) NSArray<NSString *> *warnings;

/**
 * Added in version 7.0.0
 *
 * Creates a new deserializer object.
 */
+ (instancetype)barcodeBatchDeserializer;

/**
 * Added in version 7.0.0
 *
 * Deserializes Barcode Batch from JSON.
 *
 * An error is set if the provided JSON does not contain required properties or contains properties of the wrong type.
 */
- (nullable SDCBarcodeBatch *)modeFromJSONString:(NSString *)JSONString
                                     withContext:(SDCDataCaptureContext *)context
                                           error:(NSError *_Nullable *_Nullable)error;
/**
 * Added in version 7.0.0
 *
 * Takes an existing Barcode Batch and updates it by deserializing new or changed properties from JSON.
 *
 * An error is set if the provided JSON does not contain required properties or contains properties of the wrong type.
 */
- (nullable SDCBarcodeBatch *)updateMode:(SDCBarcodeBatch *)barcodeBatch
                          fromJSONString:(NSString *)JSONString
                                   error:(NSError *_Nullable *_Nullable)error;

/**
 * Added in version 7.0.0
 *
 * Deserializes Barcode Batch settings from JSON.
 *
 * An error is set if the provided JSON does not contain required properties or contains properties of the wrong type.
 */
- (nullable SDCBarcodeBatchSettings *)settingsFromJSONString:(NSString *)JSONString
                                                       error:(NSError *_Nullable *_Nullable)error;
/**
 * Added in version 7.0.0
 *
 * Takes existing Barcode Batch settings and updates them by deserializing new or changed properties from JSON.
 *
 * An error is set if the provided JSON does not contain required properties or contains properties of the wrong type.
 */
- (nullable SDCBarcodeBatchSettings *)updateSettings:(SDCBarcodeBatchSettings *)settings
                                      fromJSONString:(NSString *)JSONString
                                               error:(NSError *_Nullable *_Nullable)error;

/**
 * Added in version 7.0.0
 *
 * Deserializes a Barcode Batch basic overlay from JSON.
 *
 * An error is set if the provided JSON does not contain required properties or contains properties of the wrong type.
 */
- (nullable SDCBarcodeBatchBasicOverlay *)basicOverlayFromJSONString:(NSString *)JSONString
                                                               withMode:(SDCBarcodeBatch *)mode
                                                                  error:(NSError *_Nullable *_Nullable)error;
/**
 * Added in version 7.0.0
 *
 * Takes an existing Barcode Batch basic overlay and updates it by deserializing new or changed properties from JSON.
 *
 * An error is set if the provided JSON does not contain required properties or contains properties of the wrong type.
 */
- (nullable SDCBarcodeBatchBasicOverlay *)updateBasicOverlay:(SDCBarcodeBatchBasicOverlay *)overlay
                                                 fromJSONString:(NSString *)JSONString
                                                          error:(NSError *_Nullable *_Nullable)error;

/**
 * Added in version 7.0.0
 *
 * Deserializes a Barcode Batch advanced overlay from JSON.
 *
 * An error is set if the provided JSON does not contain required properties or contains properties of the wrong type.
 */
- (nullable SDCBarcodeBatchAdvancedOverlay *)advancedOverlayFromJSONString:(NSString *)JSONString
                                                               withMode:(SDCBarcodeBatch *)mode
                                                                  error:(NSError *_Nullable *_Nullable)error  API_AVAILABLE(ios(10.0));
/**
 * Added in version 7.0.0
 *
 * Takes an existing Barcode Batch advanced overlay and updates it by deserializing new or changed properties from JSON.
 *
 * An error is set if the provided JSON does not contain required properties or contains properties of the wrong type.
 */
- (nullable SDCBarcodeBatchAdvancedOverlay *)updateAdvancedOverlay:(SDCBarcodeBatchAdvancedOverlay *)overlay
                                                 fromJSONString:(NSString *)JSONString
                                                          error:(NSError *_Nullable *_Nullable)error  API_AVAILABLE(ios(10.0));

@end

NS_ASSUME_NONNULL_END

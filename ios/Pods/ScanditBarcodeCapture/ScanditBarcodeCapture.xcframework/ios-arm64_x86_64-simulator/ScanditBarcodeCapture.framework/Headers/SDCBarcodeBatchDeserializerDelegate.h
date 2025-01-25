/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

@class SDCBarcodeBatchDeserializer;
@class SDCBarcodeBatch;
@class SDCBarcodeBatchSettings;
@class SDCBarcodeBatchBasicOverlay;
@class SDCJSONValue;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 7.0.0
 *
 * The listener for the barcode capture deserializer.
 */
NS_SWIFT_NAME(BarcodeBatchDeserializerDelegate)
@protocol SDCBarcodeBatchDeserializerDelegate <NSObject>

/**
 * Added in version 7.0.0
 *
 * Called before the deserialization of Barcode Batch started. This is the point to overwrite defaults before the deserialization is performed.
 */
- (void)barcodeBatchDeserializer:(SDCBarcodeBatchDeserializer *)deserializer
       didStartDeserializingMode:(SDCBarcodeBatch *)mode
                   fromJSONValue:(SDCJSONValue *)JSONValue;
/**
 * Added in version 7.0.0
 *
 * Called when the deserialization of Barcode Batch finished. This is the point to do additional deserialization.
 */
- (void)barcodeBatchDeserializer:(SDCBarcodeBatchDeserializer *)deserializer
      didFinishDeserializingMode:(SDCBarcodeBatch *)mode
                   fromJSONValue:(SDCJSONValue *)JSONValue;

/**
 * Added in version 7.0.0
 *
 * Called before the deserialization of the Barcode Batch settings started. This is the point to overwrite defaults before the deserialization is performed.
 */
- (void)barcodeBatchDeserializer:(SDCBarcodeBatchDeserializer *)deserializer
    didStartDeserializingSettings:(SDCBarcodeBatchSettings *)settings
                    fromJSONValue:(SDCJSONValue *)JSONValue;
/**
 * Added in version 7.0.0
 *
 * Called when the deserialization of the Barcode Batch settings finished. This is the point to do additional deserialization.
 */
- (void)barcodeBatchDeserializer:(SDCBarcodeBatchDeserializer *)deserializer
    didFinishDeserializingSettings:(SDCBarcodeBatchSettings *)settings
                     fromJSONValue:(SDCJSONValue *)JSONValue;

/**
 * Added in version 7.0.0
 *
 * Called before the deserialization of the Barcode Batch basic overlay started. This is the point to overwrite defaults before the deserialization is performed.
 */
- (void)barcodeBatchDeserializer:(SDCBarcodeBatchDeserializer *)deserializer
    didStartDeserializingBasicOverlay:(SDCBarcodeBatchBasicOverlay *)overlay
                        fromJSONValue:(SDCJSONValue *)JSONValue;
/**
 * Added in version 7.0.0
 *
 * Called when the deserialization of the Barcode Batch basic overlay finished. This is the point to do additional deserialization.
 */
- (void)barcodeBatchDeserializer:(SDCBarcodeBatchDeserializer *)deserializer
    didFinishDeserializingBasicOverlay:(SDCBarcodeBatchBasicOverlay *)overlay
                         fromJSONValue:(SDCJSONValue *)JSONValue;

/**
 * Added in version 7.0.0
 *
 * Called before the deserialization of the Barcode Batch advanced overlay started. This is the point to overwrite defaults before the deserialization is performed.
 */
- (void)barcodeBatchDeserializer:(SDCBarcodeBatchDeserializer *)deserializer
    didStartDeserializingAdvancedOverlay:(SDCBarcodeBatchAdvancedOverlay *)overlay
                           fromJSONValue:(SDCJSONValue *)JSONValue;
/**
 * Added in version 7.0.0
 *
 * Called when the deserialization of the Barcode Batch advanced overlay finished. This is the point to do additional deserialization.
 */
- (void)barcodeBatchDeserializer:(SDCBarcodeBatchDeserializer *)deserializer
    didFinishDeserializingAdvancedOverlay:(SDCBarcodeBatchAdvancedOverlay *)overlay
                            fromJSONValue:(SDCJSONValue *)JSONValue;

@end

NS_ASSUME_NONNULL_END

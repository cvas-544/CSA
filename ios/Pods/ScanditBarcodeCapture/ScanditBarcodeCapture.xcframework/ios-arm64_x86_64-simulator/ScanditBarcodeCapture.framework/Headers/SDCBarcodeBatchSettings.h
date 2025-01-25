/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditBarcodeCapture/SDCSymbology.h>

NS_ASSUME_NONNULL_BEGIN

SDC_EXTERN NSString *_Nonnull const SDCBarcodeBatchSettingsErrorDomain NS_SWIFT_NAME(BarcodeBatchSettingsErrorDomain);

@class SDCFrameSaveTrigger;
@class SDCSymbologySettings;
@class SDCArucoDictionary;

/**
 * Added in version 7.0.0
 */
NS_SWIFT_NAME(BarcodeBatchSettings)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeBatchSettings : NSObject <NSCopying>

/**
 * Added in version 7.0.0
 *
 * Returns the set of enabled symbologies.
 */
@property (nonatomic, nonnull, readonly) NSSet<NSNumber *> *enabledSymbologies NS_REFINED_FOR_SWIFT;
/**
 * Added in version 7.0.0
 *
 * Declares whether or not the barcodes to be tracked are expected to be unique. If enabled optimizations can be used to improve Barcode Batch.
 *
 * @remark Do not enable this if you are expecting to scan multiple barcodes with the same content within one batch.
 */
@property (nonatomic, assign) BOOL expectsOnlyUniqueBarcodes;

/**
 * Added in version 7.0.0
 *
 * Creates a new Barcode Batch settings instance. All symbologies are disabled. Make sure to enable the symbologies required by your app before applying the settings to SDCBarcodeBatch with SDCBarcodeBatch.applySettings:completionHandler:.
 */
+ (instancetype)settings NS_SWIFT_UNAVAILABLE("Use initializer instead");

/**
 * Added in version 7.0.0
 *
 * Get SDCSymbologySettings specific for the given SDCSymbology.
 *
 * Note that modifying the returned object doesn’t automatically apply the changes to SDCBarcodeBatch. After you made changes to the symbology settings,
 *
 * call SDCBarcodeBatch.applySettings:completionHandler:
 *
 * with these SDCBarcodeBatchSettings to apply them.
 */
- (nonnull SDCSymbologySettings *)settingsForSymbology:(SDCSymbology)symbology;

/**
 * Added in version 7.0.0
 *
 * Sets property to the provided value. Use this method to set properties that are not yet part of a stable API. Properties set through this method may or may not be used or change in a future release.
 */
- (void)setValue:(id)value forProperty:(NSString *)property NS_SWIFT_NAME(set(value:forProperty:));

/**
 * Added in version 7.0.0
 *
 * Retrieves the value of a previously set property. In case the property does not exist, -1 is returned.
 */
- (nullable id)valueForProperty:(NSString *)property;

/**
 * Added in version 7.0.0
 *
 * This function provides a convenient shortcut to enabling decoding of particular symbologies without having to go through SDCSymbologySettings.
 * By default, all symbologies are turned off and symbologies need to be explicitly enabled.
 */
- (void)enableSymbologies:(nonnull NSSet<NSNumber *> *)symbologies NS_REFINED_FOR_SWIFT;

/**
 * Added in version 7.0.0
 *
 * This function provides a convenient shortcut to enabling/disabling decoding of a particular symbology without having to go through SDCSymbologySettings.
 *
 * @remark Some 1d barcode symbologies allow you to encode variable-length data. By default, the Scandit Data Capture SDK only scans barcodes in a certain length range.
 *
 * If your application requires scanning of one of these symbologies, and the length is falling outside the default range, you may need to adjust the active symbol counts for the symbology in addition to enabling it.
 */
- (void)setSymbology:(SDCSymbology)symbology
             enabled:(BOOL)enabled NS_SWIFT_NAME(set(symbology:enabled:));

/**
 * Added in version 7.0.0
 *
 * Sets the SDCArucoDictionary to be used while scanning ArUco codes.
 * When the symbology is enabled the dictionary SDCArucoDictionaryPreset_5X5_1000 is loaded as default.
 */
- (void)setArucoDictionary:(SDCArucoDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END

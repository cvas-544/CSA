/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 7.0.0
 *
 * This class contains the license text and attributions for all third party software used by the Scandit SDK.
 */
NS_SWIFT_NAME(OpenSourceSoftwareLicenseInfo)
SDC_EXPORTED_SYMBOL
@interface SDCOpenSourceSoftwareLicenseInfo : NSObject

/**
 * Added in version 7.0.0
 *
 * The license text for all third party software used by the Scandit SDK.
 */
@property (nonatomic, strong, readonly) NSString *licenseText;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

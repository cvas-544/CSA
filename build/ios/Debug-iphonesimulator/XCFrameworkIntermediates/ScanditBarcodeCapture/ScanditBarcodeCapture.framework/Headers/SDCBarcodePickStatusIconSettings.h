/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN
/**
 * Added in version 6.25.0
 *
 * Use this class to customize the status icons in styles that support it.
 */
SDC_EXPORTED_SYMBOL
NS_SWIFT_NAME(BarcodePickStatusIconSettings)
@interface SDCBarcodePickStatusIconSettings : NSObject

/**
 * Added in version 6.25.0
 *
 * The ratio between the shortest highlight dimension and the base size for the status icon.
 * This base size will then be clamped between minSize and maxSize.
 * For example, for a highlight with a size of 90x60 dp, a ratio of 0.6 means the base size for the status icon will be calculated as 60 (shortest dimension) * 0.6 = 36 dp, before being clamped between the minimum and maximum allowed sizes.
 *
 * Default is 0.5.
 */
@property (nonatomic, assign) CGFloat ratioToHighlightSize;
/**
 * Added in version 6.25.0
 *
 * The minimum size allowed for status icons.
 *
 * Default is 20 dp.
 */
@property (nonatomic, assign) NSInteger minSize;
/**
 * Added in version 6.25.0
 *
 * The maximum size allowed for status icons.
 *
 * Default is no maximum, INT_MAX.
 */
@property (nonatomic, assign) NSInteger maxSize;

@end

NS_ASSUME_NONNULL_END

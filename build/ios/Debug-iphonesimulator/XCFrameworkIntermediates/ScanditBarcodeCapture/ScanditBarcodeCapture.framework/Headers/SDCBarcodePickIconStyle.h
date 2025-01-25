/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <ScanditCaptureCore/SDCBase.h>

/**
 * Added in version 6.19.0
 *
 * The possible icon styles for the highlight styles that support it.
 */
typedef NS_CLOSED_ENUM(NSUInteger, SDCBarcodePickIconStyle) {
/**
     * Added in version 6.19.0
     *
     * Default icon style. The items to pick will be marked with a “cart” icon. The picked items will be marked with a checkmark.
     */
    SDCBarcodePickIconStylePreset1,
/**
     * Added in version 6.19.0
     *
     * The items to pick will be marked with a “plus” icon. The picked items will be marked with a checkmark.
     */
    SDCBarcodePickIconStylePreset2
} NS_SWIFT_NAME(BarcodePickIconStyle);

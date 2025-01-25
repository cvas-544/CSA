/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <ScanditCaptureCore/SDCBase.h>

/**
 * Added in version 6.15.0
 *
 * The type of highlight applied to the filtered barcodes.
 */
typedef NS_CLOSED_ENUM(NSUInteger, SDCBarcodeFilterHighlightType) {
/**
     * Added in version 6.15.0
     *
     * A quadrilateral filled with a solid color will be drawn over filtered barcodes.
     */
    SDCBarcodeFilterHighlightTypeBrush
};

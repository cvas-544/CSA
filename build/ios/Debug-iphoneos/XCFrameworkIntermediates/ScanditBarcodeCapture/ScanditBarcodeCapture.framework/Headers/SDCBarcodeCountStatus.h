/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <ScanditCaptureCore/SDCBase.h>

/**
 * Added in version 6.17.0
 *
 * A status for a SDCBarcode
 */
typedef NS_CLOSED_ENUM(NSUInteger, SDCBarcodeCountStatus) {
/**
     * Added in version 6.17.0
     *
     * No status.
     */
    SDCBarcodeCountStatusNone,
/**
     * Added in version 6.17.0
     *
     * Status that indicates an error retrieving the status.
     */
    SDCBarcodeCountStatusNotAvailable,
/**
     * Added in version 7.0.0
     *
     * Status that indicates an item that will expire soon.
     */
    SDCBarcodeCountStatusExpiringSoon,
/**
     * Added in version 6.17.0
     *
     * Status that indicates an expired item.
     */
    SDCBarcodeCountStatusExpired,
/**
     * Added in version 6.17.0
     *
     * Status that indicates a fragile item.
     */
    SDCBarcodeCountStatusFragile,
/**
     * Added in version 6.17.0
     *
     * Status that indicates a quality check is needed.
     */
    SDCBarcodeCountStatusQualityCheck,
/**
     * Added in version 6.17.0
     *
     * Status that indicates low stock of an item.
     */
    SDCBarcodeCountStatusLowStock,
/**
     * Added in version 6.17.0
     *
     * Status that indicates a wrong item.
     */
    SDCBarcodeCountStatusWrong,
} NS_SWIFT_NAME(BarcodeCountStatus);

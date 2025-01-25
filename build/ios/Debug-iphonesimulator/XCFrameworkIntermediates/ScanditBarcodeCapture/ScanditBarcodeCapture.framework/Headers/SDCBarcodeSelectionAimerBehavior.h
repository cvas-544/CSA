/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

/**
 * Added in version 6.17.0
 *
 * Enum used to specify what happens when the user aims a barcode.
 */
typedef NS_CLOSED_ENUM(NSUInteger, SDCBarcodeSelectionAimerBehavior) {
/**
     * Added in version 6.17.0
     *
     * Aiming and tapping an unselected barcode select it. Aiming and tapping an already selected barcode unselect it. The behavior does not apply when using SDCBarcodeSelectionAutoSelectionStrategy. In this case, SDCBarcodeSelectionAimerBehaviorRepeatSelection is always in used.
     */
    SDCBarcodeSelectionAimerBehaviorToggleSelection,
/**
     * Added in version 6.17.0
     *
     * Aiming an unselected barcode selects it. Aiming on an already selected barcode will increment the count returned by SDCBarcodeSelectionSession.countForBarcode:.
     */
    SDCBarcodeSelectionAimerBehaviorRepeatSelection
} NS_SWIFT_NAME(BarcodeSelectionAimerBehavior);

/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

/**
 * Added in version 7.0.0
 *
 * The view state of SDCSparkScanView.
 */
typedef NS_ENUM(NSInteger, SDCSparkScanViewState) {
/**
     * Added in version 7.0.0
     *
     * The initial view state for a few moments after SparkScanView is created.
     */
    SDCSparkScanViewStateInitial,
/**
     * Added in version 7.0.0
     *
     * SparkScan is displaying only the collapsed capture button.
     */
    SDCSparkScanViewStateIdle,
/**
     * Added in version 7.0.0
     *
     * SparkScan is displaying an expanded capture button, and if the SDCSparkScanPreviewBehavior of the current SparkScanScanningMode is SDCSparkScanPreviewBehaviorPersistent, we are also displaying camera feed through the mini preview but no actual scanning is taking place. This state is reachable after scanning or after a SDCSparkScanViewSettings.inactiveStateTimeout timeout.
     */
    SDCSparkScanViewStateInactive,
/**
     * Added in version 7.0.0
     *
     * We are actively recognising barcodes, mini preview and expanded capture button are visible.
     */
    SDCSparkScanViewStateActive,
/**
     * Added in version 7.0.0
     *
     * User returns SparkScanBarcodeFeedback.Error from the SDCSparkScanView.feedbackDelegate. Mini preview is visible with a frozen frame and expanded capture button is visible. If capture button is tapped or after a SDCSparkScanBarcodeErrorFeedback.resumeCapturingDelay timeout is reached we move to SDCSparkScanViewStateActive state.
     */
    SDCSparkScanViewStateError
} NS_SWIFT_NAME(SparkScanViewState);

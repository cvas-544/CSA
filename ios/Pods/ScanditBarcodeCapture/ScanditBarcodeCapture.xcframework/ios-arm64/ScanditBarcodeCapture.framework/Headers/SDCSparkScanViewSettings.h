/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <ScanditCaptureCore/SDCCamera.h>
#import <ScanditBarcodeCapture/SDCSparkScanToastSettings.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.15.0
 *
 * The capture mode type of the SDCSparkScanView.
 */
typedef NS_CLOSED_ENUM(NSInteger, SDCSparkScanScanningBehavior) {
/**
     * Added in version 6.15.0
     *
     * Barcode capturing session is stopped after each scan.
     */
    SDCSparkScanScanningBehaviorSingle,
/**
     * Added in version 6.15.0
     *
     * Keeps the barcode capturing session active for longer time.
     */
    SDCSparkScanScanningBehaviorContinuous
} NS_SWIFT_NAME(SparkScanScanningBehavior);

/**
 * Added in version 6.23.0
 *
 * The preview behavior type of the SDCSparkScanView.
 */
typedef NS_CLOSED_ENUM(NSInteger, SDCSparkScanPreviewBehavior) {
/**
     * Added in version 6.23.0
     *
     * After a scan with scanning behavior SDCSparkScanScanningBehaviorSingle, or stopping scanning with scanning behavior SDCSparkScanScanningBehaviorContinuous, camera moves to standby state and preview is hidden for maximum efficiency.
     */
    SDCSparkScanPreviewBehaviorDefault,
/**
     * Added in version 6.23.0
     *
     * After a scan with scanning behavior SDCSparkScanScanningBehaviorSingle, or stopping scanning with scanning behavior SDCSparkScanScanningBehaviorContinuous, camera stays active and preview is visible for maximum precision.
     */
    SDCSparkScanPreviewBehaviorPersistent
} NS_SWIFT_NAME(SparkScanPreviewBehavior);

/**
 * Added in version 7.0.0
 *
 * The size of the mini preview in SDCSparkScanView. Used in SDCSparkScanViewSettings.defaultMiniPreviewSize.
 */
typedef NS_CLOSED_ENUM(NSInteger, SDCSparkScanMiniPreviewSize) {
/**
     * Added in version 7.0.0
     *
     * Regular, smaller size of the mini preview.
     */
    SDCSparkScanMiniPreviewSizeRegular,
/**
     * Added in version 7.0.0
     *
     * Expanded, larger size of the mini preview.
     */
    SDCSparkScanMiniPreviewSizeExpanded
} NS_SWIFT_NAME(SparkScanMiniPreviewSize);

/**
 * Added in version 6.16.0
 *
 * The base class for setting a default scanning mode to SDCSparkScanViewSettings. Can be either SDCSparkScanScanningModeTarget or SDCSparkScanScanningModeDefault.
 */
NS_SWIFT_NAME(SparkScanScanningMode)
@protocol SDCSparkScanScanningMode <NSObject>
/**
 * Added in version 6.16.0
 *
 * Returns the JSON representation.
 */
@property (nonatomic, nonnull, readonly) NSString *JSONString;
@end

/**
 * Added in version 6.16.0
 *
 * This is the standard scanning mode for SparkScan.
 */
NS_SWIFT_NAME(SparkScanScanningModeDefault)
SDC_EXPORTED_SYMBOL
@interface SDCSparkScanScanningModeDefault : NSObject <SDCSparkScanScanningMode>
/**
 * Added in version 6.16.0
 *
 * Returns the JSON representation.
 */
@property (nonatomic, nonnull, readonly) NSString *JSONString;
/**
 * Added in version 6.16.0
 *
 * The scanning mode provided in the constructor.
 */
@property (nonatomic, assign, readonly) SDCSparkScanScanningBehavior scanningBehavior;
/**
 * Added in version 6.23.0
 *
 * The preview behavior provided in the constructor.
 */
@property (nonatomic, assign, readonly) SDCSparkScanPreviewBehavior previewBehavior;

/**
 * Added in version 6.23.0
 *
 * Constructs a new default scanning mode with the provided capture mode and preview behavior.
 */
- (instancetype)initWithScanningBehavior:(SDCSparkScanScanningBehavior)scanningBehavior
                         previewBehavior:(SDCSparkScanPreviewBehavior)previewBehavior;
@end

/**
 * Added in version 6.16.0
 *
 * Target scanning mode. This is meant and optimized to scan codes further away.
 */
NS_SWIFT_NAME(SparkScanScanningModeTarget)
SDC_EXPORTED_SYMBOL
@interface SDCSparkScanScanningModeTarget : NSObject <SDCSparkScanScanningMode>
/**
 * Added in version 6.16.0
 *
 * Returns the JSON representation.
 */
@property (nonatomic, nonnull, readonly) NSString *JSONString;
/**
 * Added in version 6.16.0
 *
 * The scanning mode provided in the constructor.
 */
@property (nonatomic, assign, readonly) SDCSparkScanScanningBehavior scanningBehavior;
/**
 * Added in version 6.23.0
 *
 * The preview behavior provided in the constructor.
 */
@property (nonatomic, assign, readonly) SDCSparkScanPreviewBehavior previewBehavior;

/**
 * Added in version 6.23.0
 *
 * Constructs a new target scanning mode with the provided capture mode and preview behavior.
 */
- (instancetype)initWithScanningBehavior:(SDCSparkScanScanningBehavior)scanningBehavior
                         previewBehavior:(SDCSparkScanPreviewBehavior)previewBehavior;
@end

/**
 * Added in version 6.15.0
 *
 * The hand mode type of the SDCSparkScanView.
 *
 * Deprecated since version 7.0: Hand mode is no longer supported. The trigger button can now be placed anywhere on the screen.
 */
typedef NS_CLOSED_ENUM(NSInteger, SDCSparkScanViewHandMode) {
/**
     * Added in version 6.15.0
     *
     * Optimizes the layout for right-hand use of the SDCSparkScanView.
     */
    SDCSparkScanViewHandModeRight,
/**
     * Added in version 6.15.0
     *
     * Optimizes the layout for left-hand use of the SDCSparkScanView.
     */
    SDCSparkScanViewHandModeLeft
} NS_SWIFT_NAME(SparkScanViewHandMode) DEPRECATED_MSG_ATTRIBUTE("There is no hand mode anymore.");

/**
 * Added in version 6.15.0
 *
 * @warning Changing the values of SparkScanViewSettings instance after the creation of SDCSparkScanView does not result in applying the changed settings to the corresponding view.
 */
NS_SWIFT_NAME(SparkScanViewSettings)
SDC_EXPORTED_SYMBOL
@interface SDCSparkScanViewSettings : NSObject

/**
 * Added in version 6.15.0
 *
 * The timeout to automatically switch to idle state. When set to negative value timeout is infinite.
 *
 * Default is 5 seconds.
 */
@property (nonatomic, assign) NSTimeInterval triggerButtonCollapseTimeout;
/**
 * Added in version 6.23.0
 *
 * The timeout to automatically stop capturing.
 *
 * Default is 10 seconds.
 */
@property (nonatomic, assign) NSTimeInterval inactiveStateTimeout;

/**
 * Added in version 6.15.0
 *
 * Sets the default torch state of the camera.
 *
 * Default is SDCTorchStateOff.
 */
@property (nonatomic, assign) SDCTorchState defaultTorchState;
/**
 * Added in version 6.24.0
 *
 * Sets the default camera position.
 *
 * Default is SDCCameraPositionWorldFacing.
 *
 * @remark This API is still in beta and may change in future versions of Scandit Data Capture SDK.
 */
@property (nonatomic, assign) SDCCameraPosition defaultCameraPosition;
/**
 * Added in version 7.0.0
 *
 * Sets the default size of the mini preview.
 *
 * Default is SDCSparkScanMiniPreviewSizeRegular.
 */
@property (nonatomic, assign) SDCSparkScanMiniPreviewSize defaultMiniPreviewSize;
/**
 * Added in version 6.16.0
 *
 * Sets the default scanning mode of the view.
 *
 * Default is SDCSparkScanScanningModeDefault.
 */
@property (nonatomic, strong) id<SDCSparkScanScanningMode> defaultScanningMode;
/**
 * Added in version 6.16.0
 *
 * Indicates whether the feedback should have sound enabled.
 *
 * Default is YES.
 */
@property (nonatomic, assign, getter=isSoundEnabled) BOOL soundEnabled;
/**
 * Added in version 6.16.0
 *
 * Indicates whether the feedback should have haptics enabled.
 *
 * Default is YES.
 */
@property (nonatomic, assign, getter=isHapticEnabled) BOOL hapticEnabled;
/**
 * Added in version 6.16.0
 *
 * Indicates whether the visual feedback on scan should be displayed.
 *
 * Default is YES.
 */
@property (nonatomic, assign, getter=isVisualFeedbackEnabled) BOOL visualFeedbackEnabled;
/**
 * Added in version 6.16.0
 *
 * Indicates whether to keep scanning as long as the scan button is pressed.
 *
 * Default is YES.
 */
@property (nonatomic, assign, getter=isHoldToScanEnabled) BOOL holdToScanEnabled;
/**
 * Added in version 6.15.0
 *
 * Sets the default hand mode of the view.
 *
 * Default is SDCSparkScanViewHandModeRight.
 *
 * Deprecated since version 7.0: Hand mode is no longer supported. The trigger button can now be placed anywhere on the screen.
 */
@property (nonatomic, assign) SDCSparkScanViewHandMode defaultHandMode DEPRECATED_MSG_ATTRIBUTE(
    "There is no hand mode anymore.");

/**
 * Added in version 6.16.0
 *
 * Sets whether the SDCSparkScanView should react to clicks of the volume button. Disabled by default.
 */
@property (nonatomic, assign, getter=isHardwareTriggerEnabled) BOOL hardwareTriggerEnabled;

/**
 * Added in version 6.23.0
 *
 * The zoom factor to use for the camera.
 *
 * Default is 1.
 */
@property (nonatomic, assign) CGFloat zoomFactorOut;
/**
 * Added in version 6.23.0
 *
 * The zoom factor to move to when the zoom switch control was tapped.
 *
 * Default is 2.
 */
@property (nonatomic, assign) CGFloat zoomFactorIn;

/**
 * Added in version 6.18.0
 *
 * Sets the toast settings. See SDCSparkScanToastSettings for details.
 */
@property (nonatomic, strong) SDCSparkScanToastSettings *toastSettings;

/**
 * Added in version 6.16.0
 *
 * Returns the JSON representation of the spark scan settings.
 */
@property (nonatomic, nonnull, readonly) NSString *JSONString;

@end

NS_ASSUME_NONNULL_END

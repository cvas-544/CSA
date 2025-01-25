/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditBarcodeCapture/SDCSparkScanViewState.h>

#import <UIKit/UIKit.h>

@class SDCBarcode;
@class SDCBrush;
@class SDCDataCaptureContext;
@class SDCSparkScan;
@class SDCSparkScanBarcodeFeedback;
@class SDCSparkScanViewSettings;
@class SDCSparkScanView;
@protocol SDCSparkScanScanningMode;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 7.0.0
 *
 * Serialize the SparkScan view state in a JSON string.
 */
SDC_EXTERN NSString *_Nonnull NSStringFromSDCSparkScanViewState(SDCSparkScanViewState viewState)
    NS_SWIFT_NAME(getter:SparkScanViewState.jsonString(self:));

/**
 * Added in version 6.23.0
 *
 * Feedback delegate protocol for SparkScan. This can be used to customize the emitted feedback for each detected barcode. See SDCSparkScanView.feedbackDelegate.
 */
NS_SWIFT_NAME(SparkScanFeedbackDelegate)
@protocol SDCSparkScanFeedbackDelegate <NSObject>

/**
 * Added in version 6.23.0
 *
 * Invoked for each detected barcode. The implementation should return SparkScanBarcodeFeedback.Success, SparkScanBarcodeFeedback.Error, or nil. If nil is returned, the default brush is used to visualize the barcode and no other feedback (visual, sound, or haptic) is emitted. By default returns SparkScanBarcodeFeedback.Success.
 *
 * Note that this method is executed on a background thread.
 */
- (nullable SDCSparkScanBarcodeFeedback *)feedbackForBarcode:(SDCBarcode *)barcode;

@end

/**
 * Added in version 6.16.0
 */
NS_SWIFT_NAME(SparkScanViewUIDelegate)
@protocol SDCSparkScanViewUIDelegate <NSObject>

@optional

/**
 * Added in version 6.16.0
 *
 * Callback method that can be used to define an action that should be performed when barcode count button is tapped from the toolbar. Called from the main thread.
 */
- (void)barcodeCountButtonTappedInView:(nonnull SDCSparkScanView *)view;
/**
 * Added in version 7.0.0
 *
 * Callback method that can be used to define an action that should be performed when label capture button is tapped from the toolbar. Called from the main thread.
 */
- (void)labelCaptureButtonTappedInView:(nonnull SDCSparkScanView *)view;
/**
 * Added in version 6.26.0
 *
 * Callback method that can be used to define an action that should be performed when barcode find button is tapped from the toolbar. Called from the main thread.
 */
- (void)barcodeFindButtonTappedInView:(nonnull SDCSparkScanView *)view;
/**
 * Added in version 6.20.0
 *
 * Callback method that will be called when the currently used SparkScanScanningMode changes. Called from the main thread.
 */
- (void)sparkScanView:(nonnull SDCSparkScanView *)view
    didChangeScanningMode:(nonnull id<SDCSparkScanScanningMode>)scanningMode;
/**
 * Added in version 7.0.0
 *
 * Callback method that will be called when SDCSparkScanViewState changes. Called from the main thread.
 */
- (void)sparkScanView:(nonnull SDCSparkScanView *)view
       didChangeState:(SDCSparkScanViewState)viewState;

@end

/**
 * Added in version 6.15.0
 *
 * SDCSparkScan comes with a ready-to-use UI and scanning modes that are purpose-built to tackle high-volume scanning at close range.
 * The SparkScanView integrates with any app without requiring app redesign or customization.
 * It includes:
 *
 *   • camera preview screen
 *
 *   • large-sized scan button
 *
 *   • quick access toolbar to adjust scanning settings
 */
NS_SWIFT_NAME(SparkScanView)
SDC_EXPORTED_SYMBOL
@interface SDCSparkScanView : UIView

/**
 * Added in version 6.16.0
 *
 * Returns the default brush used by the overlay.
 */
@property (class, nonatomic, strong, nonnull, readonly) SDCBrush *defaultBrush;

/**
 * Added in version 6.20.0
 *
 * Returns the currently used SparkScanScanningMode.
 */
@property (nonatomic, strong, readonly) id<SDCSparkScanScanningMode> scanningMode;
/**
 * Added in version 6.16.0
 *
 * Sets the delegate which is called whenever a barcode find button or barcode count button is tapped from the toolbar.
 */
@property (nonatomic, weak, nullable) id<SDCSparkScanViewUIDelegate> UIDelegate;

/**
 * Added in version 6.16.0
 *
 * Indicates whether the barcode count button should be shown to the user.
 *
 * Default is NO.
 */
@property (nonatomic, assign, getter=isBarcodeCountButtonVisible) BOOL barcodeCountButtonVisible;
/**
 * Added in version 7.0.0
 *
 * Indicates whether the label capture button should be shown to the user.
 *
 * Default is NO.
 */
@property (nonatomic, assign, getter=isLabelCaptureButtonVisible) BOOL labelCaptureButtonVisible;
/**
 * Added in version 6.26.0
 *
 * Indicates whether the barcode find button should be shown to the user.
 *
 * Default is NO.
 */
@property (nonatomic, assign, getter=isBarcodeFindButtonVisible) BOOL barcodeFindButtonVisible;
/**
 * Added in version 6.16.0
 *
 * Indicates whether the target mode button should be shown to the user.
 *
 * Default is NO.
 */
@property (nonatomic, assign, getter=isTargetModeButtonVisible) BOOL targetModeButtonVisible;
/**
 * Added in version 6.15.0
 *
 * Indicates whether the scanning behavior button should be shown to the user.
 *
 * Default is NO.
 */
@property (nonatomic, assign, getter=isScanningBehaviorButtonVisible) BOOL scanningBehaviorButtonVisible;
/**
 * Added in version 6.15.0
 *
 * Indicates whether the torch button should be shown to the user.
 *
 * Default is YES.
 *
 * Deprecated since version 7.0: The torch button has been moved to the mini preview. Use torchControlVisible instead.
 */
@property (nonatomic, assign, getter=isTorchButtonVisible) BOOL torchButtonVisible DEPRECATED_MSG_ATTRIBUTE("Use torchControlVisible instead.");
/**
 * Added in version 6.24.0
 *
 * Indicates whether the camera switch button should be shown to the user.
 *
 * Default is NO.
 *
 * @remark This API is still in beta and may change in future versions of Scandit Data Capture SDK.
 */
@property (nonatomic, assign, getter=isCameraSwitchButtonVisible) BOOL cameraSwitchButtonVisible;
/**
 * Added in version 6.15.0
 *
 * Indicates whether the hand mode button should be shown to the user.
 *
 * Default is NO.
 *
 * Deprecated since version 7.0: Hand mode is no longer supported. The trigger button can now be placed anywhere on the screen.
 */
@property (nonatomic, assign, getter=isHandModeButtonVisible) BOOL handModeButtonVisible DEPRECATED_MSG_ATTRIBUTE("There is no hand mode anymore.");
/**
 * Added in version 7.0.0
 *
 * Indicates whether the trigger button should be shown to the user.
 *
 * Default is YES.
 */
@property (nonatomic, assign, getter=isTriggerButtonVisible) BOOL triggerButtonVisible;
/**
 * Added in version 6.18.0
 *
 * Indicates whether the zoom switch control should be shown to the user.
 *
 * Default is YES.
 */
@property (nonatomic, assign, getter=isZoomSwitchControlVisible) BOOL zoomSwitchControlVisible;
/**
 * Added in version 6.23.0
 *
 * Indicates whether the mini preview size control should be shown to the user.
 *
 * Default is YES.
 */
@property (nonatomic, assign, getter=isPreviewSizeControlVisible) BOOL previewSizeControlVisible;
/**
 * Added in version 7.0.0
 *
 * Indicates whether the mini preview close control should be shown to the user.
 *
 * Default is YES.
 */
@property (nonatomic, assign, getter=isPreviewCloseControlVisible) BOOL previewCloseControlVisible;
/**
 * Added in version 7.0.0
 *
 * Indicates whether the torch control should be shown to the user.
 *
 * Default is YES.
 *
 * @remark If SDCSparkScanViewSettings.defaultTorchState is set to SDCTorchStateAuto, torch control is hidden.
 */
@property (nonatomic, assign, getter=isTorchControlVisible) BOOL torchControlVisible;

/**
 * Added in version 7.0.0
 *
 * The image displayed in the trigger button.
 */
@property (nonatomic, strong, nullable) UIImage *triggerButtonImage;
/**
 * Added in version 6.15.0
 *
 * Sets the background color of the capture button.
 *
 * Default is #12161999.
 *
 * Deprecated since version 7.0: Use triggerButtonCollapsedColor and triggerButtonExpandedColor instead.
 */
@property (nonatomic, strong, nullable) UIColor *captureButtonBackgroundColor DEPRECATED_MSG_ATTRIBUTE("Use triggerButtonCollapsedColor and triggerButtonExpandedColor instead.");
/**
 * Added in version 6.16.0
 *
 * Sets the background color of the capture button when scanning.
 *
 * Default is #12161966.
 *
 * Deprecated since version 7.0: This property is not relevant anymore.
 */
@property (nonatomic, strong, nullable) UIColor *captureButtonActiveBackgroundColor DEPRECATED_MSG_ATTRIBUTE("No longer relevant");
/**
 * Added in version 6.16.0
 *
 * Sets the capture button icon and text color.
 *
 * Default is #FFFFFF.
 *
 * Deprecated since version 7.0: Use triggerButtonTintColor instead.
 */
@property (nonatomic, strong, nullable) UIColor *captureButtonTintColor DEPRECATED_MSG_ATTRIBUTE("Use triggerButtonTintColor instead.");
/**
 * Added in version 7.0.0
 *
 * Sets the background color of the trigger button when button is collapsed.
 */
@property (nonatomic, strong, nullable) UIColor *triggerButtonCollapsedColor;
/**
 * Added in version 7.0.0
 *
 * Sets the background color of the trigger button when button is expanded.
 */
@property (nonatomic, strong, nullable) UIColor *triggerButtonExpandedColor;
/**
 * Added in version 7.0.0
 *
 * Sets the color of the pulsing animation around the trigger button, which is shown when the scanner is active.
 */
@property (nonatomic, strong, nullable) UIColor *triggerButtonAnimationColor;
/**
 * Added in version 7.0.0
 *
 * Sets the trigger button tint color.
 */
@property (nonatomic, strong, nullable) UIColor *triggerButtonTintColor;
/**
 * Added in version 6.16.0
 *
 * Sets the toolbar background color.
 *
 * Default is #121619CC.
 */
@property (nonatomic, strong, nullable) UIColor *toolbarBackgroundColor;
/**
 * Added in version 6.16.0
 *
 * Sets the toolbar icon active color.
 *
 * Default is #FBC02C.
 */
@property (nonatomic, strong, nullable) UIColor *toolbarIconActiveTintColor;
/**
 * Added in version 6.16.0
 *
 * Sets the toolbar icon inactive color.
 *
 * Default is #FFFFFF.
 */
@property (nonatomic, strong, nullable) UIColor *toolbarIconInactiveTintColor;

/**
 * Added in version 6.15.0
 *
 * Sets the default text to display in the button for the stop capturing action.
 *
 * When scanning using hold-to-scan interaction default is “RELEASE TO STOP SCANNING” otherwise default is “STOP SCANNING”
 *
 * Deprecated since version 7.0: The trigger button no longer displays text.
 */
@property (nonatomic, strong, nullable) NSString *stopCapturingText DEPRECATED_MSG_ATTRIBUTE("The trigger button no longer displays text.");
/**
 * Added in version 6.15.0
 *
 * Sets the default text to display in the button for the start capturing action.
 *
 * When SDCSparkScanViewSettings.holdToScanEnabled is enabled then default is “TAP OR HOLD TO SCAN” otherwise default is “TAP TO SCAN”
 *
 * Deprecated since version 7.0: The trigger button no longer displays text.
 */
@property (nonatomic, strong, nullable) NSString *startCapturingText DEPRECATED_MSG_ATTRIBUTE("The trigger button no longer displays text.");
/**
 * Added in version 6.15.0
 *
 * Sets the default text to display in the button for the resume capturing action.
 *
 * Default is “RESUME SCANNING”
 *
 * Deprecated since version 7.0: The trigger button no longer displays text.
 */
@property (nonatomic, strong, nullable) NSString *resumeCapturingText DEPRECATED_MSG_ATTRIBUTE("The trigger button no longer displays text.");
/**
 * Added in version 6.16.0
 *
 * Sets the default text to display in the button when scanning in SDCSparkScanScanningBehaviorSingle.
 *
 * Default is nil.
 *
 * Deprecated since version 7.0: The trigger button no longer displays text.
 */
@property (nonatomic, strong, nullable) NSString *scanningCapturingText DEPRECATED_MSG_ATTRIBUTE("The trigger button no longer displays text.");

/**
 * Added in version 6.23.0
 *
 * Sets the feedback delegate. If no delegate is set, the default SparkScanBarcodeFeedback.Success feedback is emitted.
 */
@property (nonatomic, weak, nullable) id<SDCSparkScanFeedbackDelegate> feedbackDelegate;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithCoder:(NSCoder *)coder NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
 * Added in version 6.15.0
 *
 * Constructs a new SparkScan view and adds it to the provided parentView. When the settings are provided, those will be used to set the default behaviour and look of the view.
 *
 * @code
 * sparkScanView = SparkScanView(parentView: view, // For example the view controller's view property.
 *                               context: context,
 *                               sparkScan: sparkScan,
 *                               settings: viewSettings)
 * @endcode
 */
- (instancetype)initWithParentView:(nonnull UIView *)parentView
                           context:(nonnull SDCDataCaptureContext *)context
                         sparkScan:(nonnull SDCSparkScan *)sparkScan
                          settings:(nonnull SDCSparkScanViewSettings *)settings;

/**
 * Added in version 6.16.0
 *
 * Method to call for preparing the mode for scanning. For instance, it can be called when the view controller containing SparkScanView is presented (i.e., UIViewController’s viewWillAppear).
 *
 * This method must be called before using the SparkScanView for scanning.
 */
- (void)prepareScanning;
/**
 * Added in version 6.16.0
 *
 * Method to call for stopping the mode. For instance, it can be called when the view controller containing SparkScanView is about to disappear (i.e., UIViewController’s viewWillDisappear).
 *
 * This method must be called to ensure that all resources used by SparkScanView are released. If your workflow involves using other Scandit modes, call this method before switching to another mode.
 */
- (void)stopScanning;
/**
 * Added in version 6.15.0
 *
 * Starts the scanning process. You can call this method if you want to trigger the scanning process without any user interaction.
 */
- (void)startScanning;
/**
 * Added in version 6.15.0
 *
 * Pauses the scanning process. You can call this method if you want to trigger pausing the scanning process without any user interaction.
 */
- (void)pauseScanning;
/**
 * Added in version 6.18.0
 *
 * Shows a toast with text inside the mini preview.
 */
- (void)showToast:(NSString *)text;

@end

NS_ASSUME_NONNULL_END

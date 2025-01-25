/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2023- Scandit AG. All rights reserved.
 */

import Foundation
import ScanditCaptureCore

struct EncodableLaserlineViewFinder: DefaultsEncodable {
    let size: SizeWithUnit
    let style: String
    let enabledColor: String
    let disabledColor: String

    init(size: SizeWithUnit,
         style: String,
         enabledColor: String,
         disabledColor: String) {
        self.size = size
        self.style = style
        self.enabledColor = enabledColor
        self.disabledColor = disabledColor
    }

    func toEncodable() -> [String: Any?] {
        [
            "width": size.width.jsonString,
            "style": style,
            "enabledColor": enabledColor,
            "disabledColor": disabledColor
        ]
    }
}

extension RectangularViewfinderStyle: CaseIterable {
    public static var allCases: [RectangularViewfinderStyle] {
        [ .rounded, .square]
    }
}

struct RectangularViewfinderDefaults: DefaultsEncodable {
    func toEncodable() -> [String: Any?] {
        let allViewFinders = Dictionary(uniqueKeysWithValues: RectangularViewfinderStyle.allCases.map {
            ($0.jsonString, EncodableRectangularViewfinder(viewfinder: RectangularViewfinder(style: $0)).toEncodable())
        })
        
        return [
            "defaultStyle": RectangularViewfinderStyle.rounded.jsonString,
            "styles": allViewFinders
        ]
    }
}

extension CameraPosition: CaseIterable {
    public static var allCases: [CameraPosition] {
        [.worldFacing, .userFacing, .unspecified]
    }
}

struct CoreDefaults: DefaultsEncodable {
    private let cameraDefaults: CameraDefaults
    private let dataCaptureViewDefaults: DataCaptureViewDefaults
    private let rectangularViewfinderDefaults: RectangularViewfinderDefaults
    private let aimerViewfinderDefauls: EncodableAimerViewfinder
    private let brushDefaults: EncodableBrush

    init(cameraDefaults: CameraDefaults,
         dataCaptureViewDefaults: DataCaptureViewDefaults,
         rectangularViewfinderDefaults: RectangularViewfinderDefaults,
         aimerViewfinderDefauls: EncodableAimerViewfinder,
         brushDefaults: EncodableBrush) {
        self.cameraDefaults = cameraDefaults
        self.dataCaptureViewDefaults = dataCaptureViewDefaults
        self.rectangularViewfinderDefaults = rectangularViewfinderDefaults
        self.aimerViewfinderDefauls = aimerViewfinderDefauls
        self.brushDefaults = brushDefaults
    }

    func toEncodable() -> [String: Any?] {
        [
            "Version": DataCaptureVersion.version(),
            "deviceID": DataCaptureContext.deviceID,
            "Camera": cameraDefaults.toEncodable(),
            "DataCaptureView": dataCaptureViewDefaults.toEncodable(),
            "RectangularViewfinder": rectangularViewfinderDefaults.toEncodable(),
            "AimerViewfinder": aimerViewfinderDefauls.toEncodable(),
            "Brush": brushDefaults.toEncodable(),
        ]
    }

    static let shared: CoreDefaults = {
        let cameraDefaults = CameraDefaults(cameraSettingsDefaults: EncodableCameraSettings(cameraSettings: CameraSettings()),
                                            defaultPosition: Camera.default?.position,
                                            availablePositions: CameraPosition.allCases.compactMap { Camera(position: $0)?.position })
        let rectangularViewfinderDefaults = RectangularViewfinderDefaults()
        return CoreDefaults(cameraDefaults: cameraDefaults,
                            dataCaptureViewDefaults: DataCaptureViewDefaults(view: DataCaptureView(frame: .zero)),
                            rectangularViewfinderDefaults: rectangularViewfinderDefaults,
                            aimerViewfinderDefauls: EncodableAimerViewfinder(viewfinder: AimerViewfinder()),
                            brushDefaults: EncodableBrush(brush: .transparent))
    }()
}

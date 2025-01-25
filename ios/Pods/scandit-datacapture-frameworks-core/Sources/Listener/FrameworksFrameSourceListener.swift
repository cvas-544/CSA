/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2023- Scandit AG. All rights reserved.
 */

import ScanditCaptureCore

open class FrameworksFrameSourceListener: NSObject {
    private let eventEmitter: Emitter
    private let frameSourceStateChangedEvent = Event(.frameSourceStateChanged)
    private let torchStateChangedEvent = Event(.torchStateChanged)

    private var isEnabled = AtomicBool()

    public init(eventEmitter: Emitter) {
        self.eventEmitter = eventEmitter
    }

    public func enable() {
        isEnabled.value = true
    }

    public func disable() {
        isEnabled.value = false
    }
}

extension FrameworksFrameSourceListener: FrameSourceListener {
    public func frameSource(_ source: FrameSource, didChange newState: FrameSourceState) {
        guard isEnabled.value, eventEmitter.hasListener(for: frameSourceStateChangedEvent) else { return }
        frameSourceStateChangedEvent.emit(on: eventEmitter, payload: ["state": newState.jsonString])
    }

    public func frameSource(_ source: FrameSource, didOutputFrame frame: FrameData) {}
}

extension FrameworksFrameSourceListener: TorchListener {
    public func didChangeTorch(to torchState: TorchState) {
        guard isEnabled.value, eventEmitter.hasListener(for: torchStateChangedEvent) else { return }
        torchStateChangedEvent.emit(on: eventEmitter, payload: ["state": torchState.jsonString])
    }
}

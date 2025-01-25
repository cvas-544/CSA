/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2024- Scandit AG. All rights reserved.
 */

public extension Dictionary {
    func encodeToJSONString() -> String? {
        do {
            let data = try JSONSerialization.data(withJSONObject: self, options: [])
            return String(data: data, encoding: .utf8)
        } catch {
            print("Error encoding dictionary to JSON: \(error)")
            return nil
        }
    }
}

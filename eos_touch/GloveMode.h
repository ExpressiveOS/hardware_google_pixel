/*
 * SPDX-FileCopyrightText: 2026 The ExpressiveOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <aidl/vendor/expressiveos/touch/BnGloveMode.h>

namespace aidl {
namespace vendor {
namespace expressiveos {
namespace touch {

class GloveMode : public BnGloveMode {
  public:
    ndk::ScopedAStatus getEnabled(bool* _aidl_return) override;
    ndk::ScopedAStatus setEnabled(bool enabled) override;
};

}  // namespace touch
}  // namespace expressiveos
}  // namespace vendor
}  // namespace aidl

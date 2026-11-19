/*
 * SPDX-FileCopyrightText: 2026 The ExpressiveOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <aidl/vendor/expressiveos/powershare/BnPowerShare.h>

namespace aidl {
namespace vendor {
namespace expressiveos {
namespace powershare {

class PowerShare : public BnPowerShare {
  public:
    ndk::ScopedAStatus isEnabled(bool* _aidl_return) override;
    ndk::ScopedAStatus setEnabled(bool enable) override;

    ndk::ScopedAStatus getMinBattery(int32_t* _aidl_return) override;
    ndk::ScopedAStatus setMinBattery(int32_t minBattery) override;
};

}  // namespace powershare
}  // namespace expressiveos
}  // namespace vendor
}  // namespace aidl

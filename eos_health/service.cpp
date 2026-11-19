/*
 * SPDX-FileCopyrightText: 2026 The ExpressiveOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#define LOG_TAG "vendor.expressiveos.health-service.default"

#include "ChargingControl.h"

#include <android-base/logging.h>
#include <android/binder_manager.h>
#include <android/binder_process.h>

using ::aidl::vendor::expressiveos::health::ChargingControl;

int main() {
    ABinderProcess_setThreadPoolMaxThreadCount(0);
    std::shared_ptr<ChargingControl> cc = ndk::SharedRefBase::make<ChargingControl>();

    const std::string instance = std::string(ChargingControl::descriptor) + "/default";
    binder_status_t status =
            AServiceManager_addService(cc->asBinder().get(), instance.c_str());
    CHECK_EQ(status, STATUS_OK) << "Failed to add service " << instance << " " << status;

    ABinderProcess_joinThreadPool();
    return EXIT_FAILURE;  // should not reach
}

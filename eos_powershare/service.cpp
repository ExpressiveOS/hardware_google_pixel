/*
 * SPDX-FileCopyrightText: 2026 The ExpressiveOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#define LOG_TAG "vendor.expressiveos.powershare-service.default"

#include "PowerShare.h"

#include <android-base/logging.h>
#include <android/binder_manager.h>
#include <android/binder_process.h>

using ::aidl::vendor::expressiveos::powershare::PowerShare;

int main() {
    ABinderProcess_setThreadPoolMaxThreadCount(0);
    std::shared_ptr<PowerShare> powershare = ndk::SharedRefBase::make<PowerShare>();

    const std::string instance = std::string(PowerShare::descriptor) + "/default";
    binder_status_t status =
            AServiceManager_addService(powershare->asBinder().get(), instance.c_str());
    CHECK_EQ(status, STATUS_OK) << "Failed to add service " << instance << " " << status;

    ABinderProcess_joinThreadPool();
    return EXIT_FAILURE;  // should not reach
}

/*
 * SPDX-FileCopyrightText: 2026 The ExpressiveOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#define LOG_TAG "vendor.expressiveos.touch-service.pixel"

#include "GloveMode.h"

#include <android-base/logging.h>
#include <android/binder_manager.h>
#include <android/binder_process.h>

using ::aidl::vendor::expressiveos::touch::GloveMode;

int main() {
    ABinderProcess_setThreadPoolMaxThreadCount(0);
    std::shared_ptr<GloveMode> glovemode = ndk::SharedRefBase::make<GloveMode>();

    const std::string instance = std::string(GloveMode::descriptor) + "/default";
    binder_status_t status =
            AServiceManager_addService(glovemode->asBinder().get(), instance.c_str());
    CHECK_EQ(status, STATUS_OK) << "Failed to add service " << instance << " " << status;

    ABinderProcess_joinThreadPool();
    return EXIT_FAILURE;  // should not reach
}

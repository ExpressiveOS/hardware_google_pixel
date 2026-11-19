#
# SPDX-FileCopyrightText: 2026 The ExpressiveOS Project
# SPDX-License-Identifier: Apache-2.0
#

# ExpressiveOS PowerShare
$(call soong_config_set,eos_powershare,powershare_path,/sys/class/power_supply/wireless/device/rtx)

PRODUCT_PACKAGES += \
    vendor.expressiveos.powershare-service.default

BOARD_SEPOLICY_DIRS += hardware/google/pixel-sepolicy/eos_powershare

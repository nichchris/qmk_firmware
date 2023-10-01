// Copyright 2023 kilipan (@kilipan)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

//* also configured in info.json
#define MATRIX_ROW_PINS { GP26, GP27, GP28, GP29, GP6, GP7 }
#define MATRIX_COL_PINS { GP0, GP1, GP2, GP4, GP3 }
#define DIODE_DIRECTION ROW2COL
// */
#define MATRIX_ROWS 6
#define MATRIX_COLS 5

#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET              // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U // Timeout window in ms in which the double tap can occur.
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17     // Specify a optional status led by GPIO number which blinks when entering the bootloader

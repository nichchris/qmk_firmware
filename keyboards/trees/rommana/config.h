#pragma once

//* also configured in info.json
// #define MATRIX_COL_PINS { GP26, GP27, GP28, GP29, GP6 }
// #define MATRIX_ROW_PINS { GP2, GP4, GP3}
// #define DIODE_DIRECTION COL2ROW
// */
#define MATRIX_COLS 5
#define MATRIX_ROWS 6 // ROWS ARE DOUBLED UP

// #define MASTER_LEFT
#define EE_HANDS
// #define SPLIT_USB_DETECT
// #define SPLIT_HAND_PIN GP12
// #define USE_SERIAL

/* Serial settings */
/* Serial communication */
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1
#define SERIAL_USART_PIN_SWAP

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET              // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U // Timeout window in ms in which the double tap can occur.
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17     // Specify a optional status led by GPIO number which blinks when entering the bootloader

/* Top left key on left half */
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0
/* Top right key on right half */
#define BOOTMAGIC_LITE_ROW_RIGHT 3
#define BOOTMAGIC_LITE_COLUMN_RIGHT 5

#pragma once

//* also configured in info.json
// #define MATRIX_COL_PINS { GP26, GP27, GP28, GP29, GP6 }
// #define MATRIX_ROW_PINS { GP2, GP4, GP3}
// #define DIODE_DIRECTION COL2ROW
// */
#define MATRIX_COLS 5
#define MATRIX_ROWS 8 // ROWS ARE DOUBLED UP

//#define MASTER_LEFT
#define EE_HANDS
//#define SPLIT_USB_DETECT
//#define SPLIT_HAND_PIN GP12
//#define USE_SERIAL

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
#define BOOTMAGIC_LITE_ROW_RIGHT 4
#define BOOTMAGIC_LITE_COLUMN_RIGHT 4

// #define EE_HANDS
// #define SPLIT_USB_DETECT
// #define USE_SERIAL

// // #define SOFT_SERIAL_PIN GP13
// // #define SERIAL_PIO_USE_PIO1

// #define SERIAL_USART_FULL_DUPLEX
// #define SERIAL_USART_TX_PIN GP12
// #define SERIAL_USART_RX_PIN GP13
// #define SERIAL_USART_PIN_SWAP

// #define MATRIX_ROW_PINS { GP0, GP1, GP2, GP3 }
// #define MATRIX_COL_PINS { GP14, GP15, GP26, GP27, GP28, GP29, GP11, GP10, GP9 }

// #define ENCODERS_PAD_A { GP8 }
// #define ENCODERS_PAD_B { GP7 }

// #define MATRIX_ROW_PINS_RIGHT { GP0, GP1, GP8, GP14 }
// #define MATRIX_COL_PINS_RIGHT { GP7, GP6, GP5, GP4, GP3, GP2, GP10, GP11, GP9 }

// #define ENCODERS_PAD_A_RIGHT { GP15 }
// #define ENCODERS_PAD_B_RIGHT { GP26 }

// #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
// #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

// #define TAPPING_TERM 190
// // #define IGNORE_MOD_TAP_INTERRUPT

// Not yet available in `info.json`
// #ifdef BOOTMAGIC_ENABLE
// // Top left key on left half
// #define BOOTMAGIC_LITE_ROW 0
// #define BOOTMAGIC_LITE_COLUMN 0
// // Top right key on right half
// #define BOOTMAGIC_LITE_ROW_RIGHT 6
// #define BOOTMAGIC_LITE_COLUMN_RIGHT 0
// #endif

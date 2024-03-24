#pragma once

#define TAPPING_TERM 230

// Prevent normal rollover on alphas from accidentally triggering mods.
// #define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// Tap other key while mod held to register held key
#define PERMISSIVE_HOLD

// Auto Shift
// #define NO_AUTO_SHIFT_ALPHA
// #define AUTO_SHIFT_TIMEOUT TAPPING_TERM
// #define AUTO_SHIFT_NO_SETUP

// #undef LOCKING_SUPPORT_ENABLE
// #undef LOCKING_RESYNC_ENABLE
// #define NO_ACTION_ONESHOT

#define CAPS_WORD_IDLE_TIMEOUT 3000 // 3 seconds.
#define COMBO_ONLY_FROM_LAYER 0
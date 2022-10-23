/* Copyright 2022 @nichchris
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "quantum.h"
#include "keymap_norwegian.h"
// #include "oneshot.h"

enum layers {
    _ENGRAMISH,
    // _HALMAK,
    // _COLEMAKDH,
    _SYM,
    _NUM,
    _MOU,
    _NAV,
    _BUTTON,
    _QWERTY,
    _SYS,
    // _TMUX,
    // _MISC,
};

enum custom_keycodes {
    ENGRAMISH = SAFE_RANGE,
    QWERTY,
    L_SYM,
    L_NUM,
    L_NAV,
    L_MOU,
    LL_BUT,
    LR_BUT,
    SYS,
};

// Shortcut to make keymap more readable

#define L_SYM LT(_SYM, KC_ENT)
#define L_NUM LT(_NUM, KC_SPC)
#define L_NAV LT(_NAV, KC_ESC)
#define L_MOU LT(_MOU, KC_BSPC)
#define LL_BUT LT(_BUTTON, KC_G)
#define LR_BUT LT(_BUTTON, KC_P)

#define SYS MO(_SYS)

#define QWERTY DF(_QWERTY)
#define ENGRAMISH DF(_ENGRAMISH)

// Norwegian aliases for readability
// #define NO_MINS KC_SLSH
// #define NO_PLUS KC_MINS
// #define NO_QUOT KC_NUHS
// #define NO_AE KC_QUOT
// #define NO_AA KC_LBRC
// #define NO_OE KC_SCLN
// #define NO_LCBR ALGR(NO_7) // {
// #define NO_LBRC ALGR(NO_8) // [
// #define NO_RBRC ALGR(NO_9) // ]
// #define NO_RCBR ALGR(NO_0) // }

// TAP DANCES

enum tap_dance_indexes {
    TD_B_TAB = 0,
    TD_V_BSPC,
    TD_EQL,
    TD_L,
    TD_D,
    TD_W,
    TD_BRC,
    TD_CBR,
    TD_BSPC,
    TD_ENT,
    TD_SPC,
    TD_SLSH,
    TD_MPS,
    TD_MFB,
};

// #define TD_B_TAB TD(KC_B, KC_TAB)
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_B_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_B, KC_TAB),
    [TD_V_BSPC] = ACTION_TAP_DANCE_DOUBLE(KC_V, KC_BSPC),
    [TD_EQL] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, S(NO_0)),
    [TD_L] = ACTION_TAP_DANCE_DOUBLE(KC_L, NO_AE),
    [TD_D] = ACTION_TAP_DANCE_DOUBLE(KC_D, NO_OSTR),
    [TD_W] = ACTION_TAP_DANCE_DOUBLE(KC_W, NO_ARNG),
    [TD_BRC] = ACTION_TAP_DANCE_DOUBLE(NO_LBRC, NO_RBRC),
    [TD_CBR] = ACTION_TAP_DANCE_DOUBLE(NO_LCBR, NO_RCBR),
    [TD_BSPC] = ACTION_TAP_DANCE_DOUBLE(KC_BSPC, KC_DEL),
    [TD_SPC] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_ENT),
    [TD_SLSH] = ACTION_TAP_DANCE_DOUBLE(NO_SLSH, NO_BSLS),
    [TD_MPS] = ACTION_TAP_DANCE_DOUBLE(KC_MPLY, KC_MSTP),
    [TD_MFB] = ACTION_TAP_DANCE_DOUBLE(KC_MNXT, KC_MPRV),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_ENGRAMISH] = LAYOUT(
TD(TD_B_TAB),      KC_Y,       KC_O,       KC_U,       KC_Z,       KC_Q,   TD(TD_L),   TD(TD_D),   TD(TD_W),TD(TD_V_BSPC),
 GUI_T(KC_C),ALT_T(KC_I),CTL_T(KC_E),SFT_T(KC_A),   NO_QUOT,    KC_COMM,SFT_T(KC_H),CTL_T(KC_T),ALT_T(KC_S),GUI_T(KC_N),
      LL_BUT,      KC_X,       KC_J,       KC_K,    NO_MINS,     KC_DOT,       KC_R,       KC_M,       KC_F,     LR_BUT,
                                          L_NAV,      L_NUM,      L_SYM,      L_MOU
    ),

    [_NUM] = LAYOUT(
        KC_1,      KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,
        KC_4,      KC_5,       KC_6, TD(TD_BRC),    NO_QUOT,    KC_COMM,SFT_T(KC_4),CTL_T(KC_5),ALT_T(KC_6),GUI_T(NO_PLUS),
        KC_7,      KC_8,       KC_9, TD(TD_CBR),    NO_MINS,     KC_DOT,       KC_1,       KC_2,       KC_3, TD(TD_EQL),
                                        KC_RSFT,      L_NUM, TD(TD_ENT), TD(TD_BSPC)
    ),

    [_SYM] = LAYOUT(
     NO_LBRC,    NO_LCBR,    NO_DQUO,    NO_RBRC,    NO_RCBR,    NO_PERC,     NO_GRV,    NO_SLSH,   NO_BSLS,  S(NO_0),
     NO_CIRC,    NO_LPRN,    NO_HASH,    NO_RPRN,    NO_PLUS,    NO_AMPR,SFT_T(NO_PIPE),CTL_T(S(NO_PIPE)),ALT_T(ALGR(NO_5)),GUI_T(ALGR(NO_3)),
     NO_TILD,    NO_LABK,      NO_AT,TD(TD_SLSH),    NO_MINS,    NO_EXLM,    NO_QUES,    NO_MICR,   XXXXXXX,   XXXXXXX,
                                      TD(TD_ENT),TD(TD_BSPC),      L_SYM,    XXXXXXX
    ),

    [_NAV] = LAYOUT(
         KC_ESC,    XXXXXXX,     KC_DEL,    KC_BSPC,   XXXXXXX, C(S(KC_C)),    C(KC_V),    C(KC_C),    C(KC_X),    C(KC_Z),
        KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,     KC_UP,    KC_CAPS,    KC_LEFT,    KC_DOWN,      KC_UP,    KC_RGHT,
        XXXXXXX,     KC_ENT,    KC_LEFT,    KC_RGHT,   KC_DOWN,     KC_INS,    KC_HOME,    KC_PGDN,    KC_PGUP,     KC_END,
                                              L_NAV,   XXXXXXX, TD(TD_ENT), TD(TD_BSPC)
    ),

    [_MOU] = LAYOUT(
        XXXXXXX,    XXXXXXX,    XXXXXXX,     XXXXXXX,     KC_MUTE,     XXXXXXX,     KC_WH_L,     KC_WH_D,     KC_WH_U,     KC_WH_R,
        KC_LGUI,    KC_LALT,    KC_LCTL,     KC_LSFT,     KC_VOLU,     XXXXXXX,     KC_MS_L,     KC_MS_D,     KC_MS_U,     KC_MS_R,
        XXXXXXX,    KC_ALGR,    XXXXXXX,     XXXXXXX,     KC_VOLD,     KC_BTN2,     KC_BTN1,     KC_BTN3,     XXXXXXX,     XXXXXXX, 
                                          TD(TD_MFB),  TD(TD_MPS),     XXXXXXX,       L_MOU
    ),
    [_BUTTON] = LAYOUT(
        KC_UNDO,       KC_CUT,   KC_COPY,    KC_PSTE,    KC_AGIN,   C(S(KC_C)),    C(KC_V),    C(KC_C),    C(KC_X),    C(KC_Z), 
        KC_LGUI,      KC_LALT,   KC_LCTL,    KC_LSFT,    XXXXXXX,      XXXXXXX,    KC_LSFT,    KC_LCTL,    KC_LALT,    KC_LGUI,        
        KC_UNDO,       KC_CUT,   KC_COPY,    KC_PSTE,    KC_AGIN,   C(S(KC_C)),    C(KC_V),    C(KC_C),    C(KC_X),    C(KC_Z), 
                                   L_NAV,      L_NUM,      L_SYM,      L_MOU
    ),

    [_QWERTY] = LAYOUT(
        KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,
        KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN,
        KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH,
                                L_NAV,      L_NUM,      L_SYM,      L_MOU
    ),

    [_SYS] = LAYOUT(
        KC_F12,       KC_F7,    KC_F8,      KC_F9,    KC_PSCR,   XXXXXXX,   QWERTY, ENGRAMISH,  DF(_NAV),    RESET,  
        KC_F11,       KC_F4,    KC_F5,      KC_F6,    KC_SLCK,   XXXXXXX,   KC_LSFT,    KC_LCTL,      KC_LALT,      KC_LGUI,
        KC_F10,       KC_F1,    KC_F2,      KC_F3,    KC_PAUS,   XXXXXXX,   DF(_SYM),  DF(_NUM),  KC_ALGR,   XXXXXXX, 
                                L_NAV,      L_NUM,      L_SYM,     L_MOU
    ),

    // [_LAYER] = LAYOUT(
    //        _______,       _______,       _______,       _______,       _______,       _______,       _______,       _______,       _______,       _______,
    //        _______,       _______,       _______,       _______,       _______,       _______,       _______,       _______,       _______,       _______,
    //        _______,       _______,       _______,       _______,       _______,       _______,       _______,       _______,       _______,       _______,
    //                                    L_NAV,      L_NUM,      L_SYM,     L_MOU
    // ),

};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NAV, _MOU, _SYS);
}

bool     muse_mode      = false;
uint8_t  last_muse_note = 0;
uint16_t muse_counter   = 0;
uint8_t  muse_offset    = 70;
uint16_t muse_tempo     = 70;
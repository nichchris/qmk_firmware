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
    _BASE,
    _SYM,
    _MOU,
    _NAV,
    _SYS,
};

enum custom_keycodes {
    BASE = SAFE_RANGE, 
    L_SYM,
    L_MOU,
    L_NAV,
    SYS,
};

// Shortcut to make keymap more readable

#define L_SYM LT(_SYM, KC_BSPC)
#define L_MOU LT(_MOU, KC_SPC)
#define L_NAV LT(_NAV, KC_ENT)

#define SYS MO(_SYS)

// COMBOS

enum combo_events { 
    EM_EMAIL, 
    PY_DEF,
    BSPC_LSFT_CLEAR, 
    COMBO_LENGTH };
uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM email_combo[]        = {KC_S, KC_W, COMBO_END};
const uint16_t PROGMEM pydef_combo[]        = {KC_P, KC_Y, KC_T, COMBO_END};

const uint16_t PROGMEM nordic_oe_combo[]    = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM nordic_ae_combo[]    = {KC_L, KC_Y, COMBO_END};
const uint16_t PROGMEM nordic_ae_combo[]    = {KC_B, KC_J, COMBO_END};
const uint16_t PROGMEM q_combo[]            = {KC_W, KC_P, COMBO_END};
const uint16_t PROGMEM z_combo[]            = {KC_C, KC_G, COMBO_END};
const uint16_t PROGMEM v_combo[]            = {KC_W, KC_F, COMBO_END};

const uint16_t PROGMEM squiggly_l_combo[]   = {KC_W, ALT_T(KC_S), COMBO_END};
const uint16_t PROGMEM square_l_combo[]     = {KC_F, CTL_T(KC_T), COMBO_END};
const uint16_t PROGMEM para_l_combo[]       = {KC_P, SFT_T(KC_H), COMBO_END};
const uint16_t PROGMEM para_r_combo[]       = {KC_L, RSFT_T(KC_N), COMBO_END};
const uint16_t PROGMEM square_r_combo[]     = {KC_U, CTL_T(KC_A), COMBO_END};
const uint16_t PROGMEM squiggly_r_combo[]   = {KC_Y, ALT_T(KC_I), COMBO_END};

const uint16_t PROGMEM redo_combo[]         = {KC_P, NO_MINS, COMBO_END};
const uint16_t PROGMEM undo_combo[]         = {SFT_T(KC_H), KC_COMM, COMBO_END};
const uint16_t PROGMEM esc_combo[]          = {KC_BSPC, KC_LSFT, COMBO_END};
const uint16_t PROGMEM ent_combo[]          = {KC_BSPC, KC_LSFT, COMBO_END};
const uint16_t PROGMEM bspc_combo[]         = {KC_BSPC, KC_LSFT, COMBO_END};
const uint16_t PROGMEM caps_combo[]         = {KC_BSPC, KC_LSFT, COMBO_END};
const uint16_t PROGMEM caps_word_combo[]    = {KC_BSPC, KC_LSFT, COMBO_END};
const uint16_t PROGMEM bspc_combo[]         = {KC_BSPC, KC_LSFT, COMBO_END};
const uint16_t PROGMEM delete_combo[]       = {KC_BSPC, KC_LSFT, COMBO_END};
const uint16_t PROGMEM delete_word_combo[]  = {KC_BSPC, KC_LSFT, COMBO_END};
const uint16_t PROGMEM clear_line_combo[]   = {KC_BSPC, KC_LSFT, COMBO_END};

combo_t key_combos[] = {
    [EM_EMAIL]        = COMBO_ACTION(email_combo),
    [PY_DEF]          = COMBO_ACTION(pydef_combo),
    [BSPC_LSFT_CLEAR] = COMBO_ACTION(clear_line_combo),
};
/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case EM_EMAIL:
            if (pressed) {
                SEND_STRING("nich.h.chris@gmail.com");
            }
            break;
        case BSPC_LSFT_CLEAR:
            if (pressed) {
                tap_code16(KC_END);
                tap_code16(S(KC_HOME));
                tap_code16(KC_BSPC);
            }
            break;
        case DELETE_WORD:
            if (pressed) {
                tap_code16(C(KC_RIGHT));
                tap_code16(S(C(KC_LEFT));
                tap_code16(KC_BSPC);
            }
            break;
        case PY_DEF:
            if (pressed) {
                SEND_STRING("nich.h.chris@gmail.com");
            }
            break;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(
// ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
        KC_K,    KC_W,    KC_F,    KC_P, XXXXXXX,    XXXXXXX,    KC_L,    KC_U,    KC_Y,    KC_X,
// ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
    GUI_T(KC_R),ALT_T(KC_S),CTL_T(KC_T),SFT_T(KC_H), NO_MINS, KC_QUOT, RSFT_T(KC_N), CTL_T(KC_A), ALT_T(KC_I), GUI_T(KC_O),
// ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
     XXXXXXX,    KC_C,    KC_G,    KC_D,  NO_COMM,   KC_DOT,    KC_M,    KC_B,    KC_J,  XXXXXXX,
// ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                                L_NAV,   L_MOU,     KC_E,    L_SYM
//                   ╰───────────────────────────╯ ╰──────────────────╯
),

[_SYM]= LAYOUT(
// ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
     S(NO_0),    KC_9,    KC_8,    KC_7, XXXXXXX,    XXXXXXX,    KC_L,    KC_U,    KC_Y,KC_RIGHT,
// ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
        KC_3,    KC_2,    KC_1,    KC_0,  NO_MINS,    KC_QUOT, KC_LEFT, KC_DOWN,   KC_UP,  KC_END,
// ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
     XXXXXXX,    KC_6,    KC_5,    KC_4,  NO_PLUS,    KC_DOT,  NO_EXLM, NO_QUES, KC_PGUP, XXXXXXX,
// ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                                L_NAV,   L_MOU,     KC_E,    L_SYM
//                   ╰───────────────────────────╯ ╰──────────────────╯
//     [_SYM] = LAYOUT(?
//         NO_LBRC, KC_9, KC_8, KC_7, XXXXXXX, XXXXXXX, NO_GRV, NO_SLSH, NO_BSLS, S(NO_0), 
//         NO_CIRC, KC_3, KC_2, KC_1, KC_0, NO_AMPR, SFT_T(NO_PIPE), CTL_T(S(NO_PIPE)), ALT_T(ALGR(NO_5)), GUI_T(ALGR(NO_3)), 
//         XXXXXXX, KC_6, KC_5, KC_4, NO_MINS, NO_EXLM, NO_QUES, NO_MICR, XXXXXXX, XXXXXXX, 
//         XXXXXXX, XXXXXXX, L_SYM, XXXXXXX),

[_NAV]= LAYOUT(
// ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
        KC_V,    KC_W,    KC_B,    KC_K, XXXXXXX,    XXXXXXX,    KC_L,    KC_U,    KC_Y,KC_RIGHT,
// ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
    KC_R, ALT_T(KC_S), CTL_T(KC_T), KC_H, NO_MINS,    KC_QUOT, KC_LEFT, KC_DOWN,   KC_UP,  KC_END,
// ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
     XXXXXXX,    KC_C,    KC_G,    KC_D,  NO_COMM,    KC_DOT, KC_HOME, KC_PGDN, KC_PGUP, XXXXXXX,
// ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                                L_NAV,   L_MOU,     KC_E,    L_SYM
//                   ╰───────────────────────────╯ ╰──────────────────╯
),

[_MOU] = LAYOUT(
// ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
     XXXXXXX,  KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    KC_L,    KC_U,    KC_Y,    KC_X,
// ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
        KC_0,  KC_VOLU, KC_BTN5, KC_BTN4, NO_MINS, KC_QUOT, SFT_T(KC_N), CTL_T(KC_A), ALT_T(KC_I), GUI_T(KC_O),
// ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
     XXXXXXX,  KC_VOLD, KC_WH_D, KC_WH_U, NO_COMM, KC_DOT, KC_M, KC_F, KC_J, XXXXXXX,
// ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                                _______,  _______,  XXXXXXX, _______
//                   ╰───────────────────────────╯ ╰──────────────────╯
),
//  = LAYOUT(
//         XXXXXXX, XXXXXXX, KC_DEL, KC_BSPC, XXXXXXX, C(S(KC_C)), C(KC_V), C(KC_C), C(KC_X), C(KC_Z), 
//         KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_UP, KC_CAPS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, 
//         XXXXXXX, KC_ENT, KC_LEFT, KC_RGHT, KC_DOWN, KC_INS, KC_HOME, KC_PGDN, KC_PGUP, 
//         XXXXXXX, L_NAV, XXXXXXX, TD(TD_ENT), TD(TD_BSPC)),

//     // [_MOU] = LAYOUT(
//     //     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, 
//     //     KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_VOLU, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, 
//     //     XXXXXXX, KC_ALGR, XXXXXXX, XXXXXXX, KC_VOLD, KC_BTN2, KC_BTN1, KC_BTN3, XXXXXXX, XXXXXXX, 
//     //                             TD(TD_MFB), TD(TD_MPS), XXXXXXX, L_MOU),

//     // [_MOU] = LAYOUT(
//     //     KC_1,      KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,
//     //     KC_4,      KC_5,       KC_6, TD(TD_BRC),    NO_QUOT,    KC_COMM,SFT_T(KC_4),CTL_T(KC_5),ALT_T(KC_6),GUI_T(NO_PLUS),
//     //     KC_7,      KC_8,       KC_9, TD(TD_CBR),    NO_MINS,     KC_DOT,       KC_1,       KC_2,       KC_3, TD(TD_EQL),
//     //                                     KC_RSFT,      L_MOU, TD(TD_ENT), TD(TD_BSPC)
//     // ),

// [_SYM] = LAYOUT(
// // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
//         KC_V,    KC_9,    KC_8,    KC_7, XXXXXXX,    XXXXXXX,    KC_L,    KC_U,    KC_Y,    KC_X,
// // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
//         KC_0,    KC_3,    KC_2,    KC_1, NO_MINS, KC_QUOT, SFT_T(KC_N), CTL_T(KC_A), ALT_T(KC_I), GUI_T(KC_O),
// // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
//      XXXXXXX,    KC_6,    KC_5,    KC_4, NO_COMM, KC_DOT, KC_M, KC_F, KC_J, XXXXXXX,
// // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
//                                 _______,  _______,  XXXXXXX, _______
// //                   ╰───────────────────────────╯ ╰──────────────────╯
// ),
// // NO_LBRC, NO_GRV, NO_SLSH, NO_BSLS, S(NO_0), NO_CIRC, NO_AMPR, SFT_T(NO_PIPE), CTL_T(S(NO_PIPE)), ALT_T(ALGR(NO_5)), GUI_T(ALGR(NO_3)) NO_MINS, NO_EXLM, NO_QUES, NO_MICR,, L_SYM,),


    // [_BUTTON] = LAYOUT(
    //     KC_UNDO,       KC_CUT,   KC_COPY,    KC_PSTE,    KC_AGIN,   C(S(KC_C)),    C(KC_V),    C(KC_C),    C(KC_X),    C(KC_Z),
    //     KC_LGUI,      KC_LALT,   KC_LCTL,    KC_LSFT,    XXXXXXX,      XXXXXXX,    KC_LSFT,    KC_LCTL,    KC_LALT,    KC_LGUI,
    //     KC_UNDO,       KC_CUT,   KC_COPY,    KC_PSTE,    KC_AGIN,   C(S(KC_C)),    C(KC_V),    C(KC_C),    C(KC_X),    C(KC_Z),
    //                                L_NAV,      L_MOU,      L_SYM,      L_MOU
    // ),

    // [_SYS] = LAYOUT(
    //     KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR, XXXXXXX, QWERTY, ENGRAMISH, DF(_NAV), RESET, 
    //     KC_F11, KC_F4, KC_F5, KC_F6, KC_SLCK, XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, 
    //     KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS, XXXXXXX, DF(_SYM), DF(_MOU), KC_ALGR, XXXXXXX, 
    //     L_NAV, L_MOU, L_SYM, L_MOU),

    // [_LAYER] = LAYOUT(
    //        _______,       _______,       _______,       _______,       XXXXXXX,       XXXXXXX,       _______,       _______,       _______,       _______,
    //        _______,       _______,       _______,       _______,       _______,       _______,       _______,       _______,       _______,       _______,
    //        XXXXXXX,       _______,       _______,       _______,       _______,       _______,       _______,       _______,       _______,       XXXXXXX,
    //                                    L_NAV,      L_MOU,      L_SYM,     L_MOU
    // ),

};

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _NAV, _SYM, _SYS);
    state = update_tri_layer_state(state, _NAV, _MOU, _SYM);
    return state;
}

bool     muse_mode      = false;
uint8_t  last_muse_note = 0;
uint16_t muse_counter   = 0;
uint8_t  muse_offset    = 70;
uint16_t muse_tempo     = 70;
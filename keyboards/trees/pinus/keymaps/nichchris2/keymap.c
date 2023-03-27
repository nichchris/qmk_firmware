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
    _NAV,
    _MOU,
    _SYM,
    _SYS,
    _SYM_COPY,
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
#include "combos.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(
// ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
        KC_K,    KC_W,    KC_F,    KC_P, XXXXXXX,    XXXXXXX,    KC_L,    KC_U,    KC_Y,    KC_X,
// ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
    GUI_T(KC_R),ALT_T(KC_S),CTL_T(KC_T),SFT_T(KC_H), KC_NUHS, NO_MINS, RSFT_T(KC_N), CTL_T(KC_A), ALT_T(KC_I), GUI_T(KC_O),
// ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
     XXXXXXX,    KC_C,    KC_G,    KC_D,  NO_COMM,   KC_DOT,    KC_M,    KC_B,    KC_J,  XXXXXXX,
// ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                                L_NAV,   L_MOU,     KC_E,    L_SYM
//                   ╰───────────────────────────╯ ╰──────────────────╯
),

[_SYM]= LAYOUT(
// ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
      NO_EQL,    KC_9,    KC_8,    KC_7, XXXXXXX,    XXXXXXX, NO_AMPR, NO_TILD, NO_PIPE, QK_GESC,
// ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
        KC_3,    KC_2,    KC_1,    KC_0,  NO_MINS,   NO_CIRC, RSFT_T(NO_DQUO), CTL_T(NO_HASH), ALGR_T(NO_DLR),  GUI_T(NO_PERC),
// ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
     XXXXXXX,    KC_6,    KC_5,    KC_4,  NO_PLUS,    KC_DOT, NO_EXLM, NO_QUES,ALGR(NO_2), XXXXXXX,
// ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                                L_NAV,   L_MOU,     KC_E,    L_SYM
//                   ╰───────────────────────────╯ ╰──────────────────╯
),

[_SYM_COPY]= LAYOUT(
// ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
      NO_EQL,    KC_9,    KC_8,    KC_7, XXXXXXX,    XXXXXXX, NO_AMPR, NO_TILD, NO_PIPE, QK_GESC,
// ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
        KC_3,    KC_2,    KC_1,    KC_0,  NO_MINS,   NO_CIRC, RSFT_T(NO_DQUO), CTL_T(NO_HASH), ALGR_T(NO_DLR),  GUI_T(NO_PERC),
// ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
     XXXXXXX,    KC_6,    KC_5,    KC_4,  NO_PLUS,    KC_DOT, NO_EXLM, NO_QUES,ALGR(NO_2), XXXXXXX,
// ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                                L_NAV,   L_MOU,     KC_E,    L_SYM
//                   ╰───────────────────────────╯ ╰──────────────────╯
),
[_NAV]= LAYOUT(
// ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
     KC_TAB,  KC_ENT, KC_BSPC, KC_ENT, XXXXXXX,    XXXXXXX,   KC_F2,   KC_F5,   KC_F9,KC_RIGHT,
// ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,  KC_ESC, C(KC_BSPC), KC_LEFT, KC_DOWN,   KC_UP,  KC_END,
// ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
     XXXXXXX,C(KC_X), C(KC_C), C(KC_V),  KC_ENT,    KC_DEL, KC_HOME, KC_PGDN, KC_PGUP, XXXXXXX,
// ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                                L_NAV,   L_MOU,     KC_E,    L_SYM
//                   ╰───────────────────────────╯ ╰──────────────────╯
),

[_MOU] = LAYOUT(
// ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
      KC_ESC,  KC_MUTE, KC_MPRV, KC_MNXT, XXXXXXX,    XXXXXXX,    KC_L,    KC_U,  KC_DEL, KC_BSPC,
// ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
     KC_MPLY,  KC_VOLU, KC_BTN4, KC_BTN5, KC_BTN3,C(KC_BSPC), NO_AE,  NO_OSTR,  NO_ARNG, KC_ENT,
// ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
     XXXXXXX,  KC_VOLD, KC_WH_D, KC_WH_U, NO_COMM, KC_DEL, KC_M, KC_F, KC_J, XXXXXXX,
// ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                                _______,  _______,  XXXXXXX, _______
//                   ╰───────────────────────────╯ ╰──────────────────╯
),

[_SYS] = LAYOUT(
// ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
     XXXXXXX,  KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_F2,    KC_F5,    KC_F9,    KC_X,
// ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
        KC_0,  KC_VOLU, KC_BTN5, KC_BTN4, NO_MINS, KC_QUOT, SFT_T(KC_N), CTL_T(KC_A), ALT_T(KC_I), GUI_T(KC_O),
// ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
     XXXXXXX,  KC_VOLD, KC_WH_D, KC_WH_U, NO_COMM, KC_DOT, KC_M, KC_F, KC_J, XXXXXXX,
// ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                                _______,  _______,  XXXXXXX, _______
//                   ╰───────────────────────────╯ ╰──────────────────╯
),
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

};

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _NAV, _SYM, _SYS);
    state = update_tri_layer_state(state, _NAV, _MOU, _SYM_COPY);
    return state;
}

bool     muse_mode      = false;
uint8_t  last_muse_note = 0;
uint16_t muse_counter   = 0;
uint8_t  muse_offset    = 70;
uint16_t muse_tempo     = 70;
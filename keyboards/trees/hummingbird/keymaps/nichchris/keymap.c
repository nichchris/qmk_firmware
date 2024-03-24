#include QMK_KEYBOARD_H

#include "keymap_norwegian.h"

//// definitions
// layers
enum layers {
    _BASE,
    _NAV,
    _MOU,
    _SYM,
    _SYS,
    _SYM_COPY,
};
// custom keycodes
enum custom_keycodes
{
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

// global
#define SCRNSHT C(A(S(KC_P)))
#define WRKFLW1 A(C(S(G(KC_K))))
#define WRKFLW2 A(C(S(G(KC_Y))))

// layers
#define MO_NAV MO(1)
#define MO_SYM MO(2)
#define MO_NAVW MO(4)
#define MO_SYMW MO(5)

// mac
// #define PST G(KC_V)
// #define CPY G(KC_C)
// #define CUT G(KC_X)
// #define SALL G(KC_A)
// #define DWRD A(KC_BSPC)
// #define QUIT G(KC_Q)

// windows
#define PSTW C(KC_V)
#define CPYW C(KC_C)
#define CUTW C(KC_X)
#define SALLW C(KC_A)
#define DWRDW C(KC_BSPC)
#define QUITW A(KC_F4)

// LEFT HAND HOME ROW MODS
#define SHT_H MT(MOD_LSFT, KC_H)
#define CRTL_T MT(MOD_LCTL, KC_T)
#define ALT_S MT(MOD_LALT, KC_S)
#define GUI_R MT(MOD_LGUI, KC_R)
#define RALT_C MT(MOD_RALT, KC_C)
// RIGHT HAND HOME ROW MODS
#define SHT_N MT(MOD_RSFT, KC_N)
#define CRTL_A MT(MOD_LCTL, KC_A)
#define ALT_I MT(MOD_LALT, KC_I)
#define GUI_O MT(MOD_LGUI, KC_O)
#define RALT_J MT(MOD_RALT, KC_J)

// OTHER
#define KC_MDOT LSFT(RALT(KC_SCLN))
// combos


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┐┌───┬───┬───┬───┬───┐
     * │ Q │ W │ F │ P │ B ││ J │ L │ U │ Y │ ; │
     * ├───┼───┼───┼───┼───┤├───┼───┼───┼───┼───┤
     * │ A │ R │ S │ T │ G ││ M │ N │ E │ I │ O │
     * └───┼───┼───┼───┼───┘└───┼───┼───┼───┼───┘
     *     │ X │ C │ D │        │ H │ , │ . │
     *     └───┴───┼───┼───┐┌───┼───┼───┴───┘
     *             │ESC│SPC││RET│BSP│
     *             └───┴───┘└───┴───┘
     */
    [_BASE] = LAYOUT_23332_2(
        KC_K,    KC_W,    KC_F,    KC_P,   NO_MINS, KC_NUHS,   KC_L,    KC_U,    KC_Y,   KC_X,
       GUI_R,   ALT_S,   CRTL_T,   SHT_H,   NO_COMM,  KC_DOT,  SHT_N,   CRTL_A,   ALT_I,   GUI_O,  
               RALT_C,    KC_G,    KC_D,                       KC_M,    KC_B,  RALT_J,
                                  L_NAV,     L_MOU,    KC_E,  L_SYM
    ),
[_SYM]= LAYOUT_23332_2(
// ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
      NO_EQL,    KC_9,    KC_8,    KC_7, NO_MINS, RALT(NO_4), NO_HASH, NO_PERC, NO_AMPR, NO_DQUO,//QK_GESC,
// ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
        KC_3,    KC_2,    KC_1,    KC_0,  NO_PLUS,    KC_DOT, KC_LSFT, KC_LCTL, KC_LALT,  KC_LGUI,
// ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
                 KC_6,    KC_5,    KC_4,                      NO_EXLM, NO_QUES,ALGR_T(NO_PIPE),
// ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                                L_NAV,   L_MOU,     QK_GESC,    L_SYM
//                   ╰───────────────────────────╯ ╰──────────────────╯
),

[_SYM_COPY]= LAYOUT_23332_2(
// ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
      NO_EQL,    KC_9,    KC_8,    KC_7, NO_MINS,   S(NO_4), NO_HASH, NO_PERC, NO_AMPR, NO_DQUO,//QK_GESC,
// ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
        KC_3,    KC_2,    KC_1,    KC_0,  NO_PLUS,    KC_DOT, KC_LSFT, KC_LCTL, KC_LALT,  KC_LGUI,
// ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
                 KC_6,    KC_5,    KC_4,                      NO_EXLM, NO_QUES,ALGR_T(NO_PIPE), 
// ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                                L_NAV,   L_MOU,     QK_GESC,    L_SYM
//                   ╰───────────────────────────╯ ╰──────────────────╯
),
[_NAV]= LAYOUT_23332_2(
// ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
     KC_ESC,   KC_F2,   KC_F5,  KC_TAB,  KC_DEL,    C(KC_BSPC), KC_PGUP,   KC_UP, KC_PGDN,  KC_ENT,
// ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, C(KC_Z),    KC_BTN4, KC_LEFT, KC_DOWN, KC_RIGHT, KC_BTN5,
// ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
             C(KC_X), C(KC_C), C(KC_V),                  KC_HOME,  KC_END, KC_TAB, 
// ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                                L_NAV,   L_MOU,     KC_E,    L_SYM
//                   ╰───────────────────────────╯ ╰──────────────────╯
),

[_MOU] = LAYOUT_23332_2(
// ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
      KC_ESC,  KC_WH_U, KC_BTN5,  KC_TAB, XXXXXXX,C(KC_BSPC), KC_MPRV,  KC_MPLY,  KC_MNXT, KC_ENT,
// ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
      KC_TAB,  KC_WH_D, KC_BTN4, KC_LSFT,KC_DEL,    KC_DEL, KC_VOLD,  KC_MUTE,  KC_VOLU, KC_ESC,
// ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
               C(KC_TAB),G(KC_TAB),A(KC_TAB),                 NO_AT,  NO_TILD,  NO_DIAE,
// ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                                _______,  _______,  XXXXXXX, _______
//                   ╰───────────────────────────╯ ╰──────────────────╯
),

[_SYS] = LAYOUT_23332_2(
// ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
     KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,    KC_F8,    KC_F9,    KC_F10,
// ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
     KC_TAB,  KC_PSCR,  KC_INS, KC_SLEP,  KC_F11, KC_F12, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
// ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
              KC_MPLY, KC_MPRV,  KC_MNXT,                 KC_HOME,  KC_END, KC_ALGR, 
// ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                                _______,  _______,  XXXXXXX, _______
//                   ╰───────────────────────────╯ ╰──────────────────╯
),
// [_SYM] = LAYOUT_23332_2(
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

layer_state_t layer_state_set_user(layer_state_t state)
{
    state = update_tri_layer_state(state, _NAV, _SYM, _SYS);
    state = update_tri_layer_state(state, _NAV, _MOU, _SYM_COPY);
    return state;
}

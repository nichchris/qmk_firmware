#pragma once

#include "keymap.h"
#include "keymap_norwegian.h"

enum combo_events {
    // EM_EMAIL,
    // PY_DEF,
    // BSPC_LSFT_CLEAR,
    NORDIC_AE,
    NORDIC_OE,
    NORDIC_AA,
    MISSING_Q,
    MISSING_Z,
    MISSING_V,
    SQUIGGLY_LEFT,
    SQUIGGLY_RIGHT,
    PARA_LEFT,
    PARA_RIGHT,
    SQUARE_LEFT,
    SQUARE_RIGHT,
    LESS_THAN,
    LARGER_THAN,
    FORWARD_SLASH,
    BACKWARD_SLASH,
    REDO,
    UNDO,
    ESC,
    ENT,
    TENT,
    BACKSPC,
    CAPS,
    CPS_WORD,
    // add: tab combo
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM nordic_ae_combo[] = {KC_L, KC_Y, COMBO_END};
const uint16_t PROGMEM nordic_oe_combo[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM nordic_aa_combo[] = {KC_B, KC_J, COMBO_END};
const uint16_t PROGMEM q_combo[]         = {KC_W, KC_P, COMBO_END};
const uint16_t PROGMEM z_combo[]         = {KC_C, KC_G, COMBO_END};
const uint16_t PROGMEM v_combo[]         = {KC_W, KC_F, COMBO_END};

const uint16_t PROGMEM para_l_combo[]     = {KC_P, SFT_T(KC_H), COMBO_END};
const uint16_t PROGMEM para_r_combo[]     = {KC_L, RSFT_T(KC_N), COMBO_END};
const uint16_t PROGMEM square_l_combo[]   = {KC_F, CTL_T(KC_T), COMBO_END};
const uint16_t PROGMEM square_r_combo[]   = {KC_U, CTL_T(KC_A), COMBO_END};
const uint16_t PROGMEM squiggly_l_combo[] = {KC_W, ALT_T(KC_S), COMBO_END};
const uint16_t PROGMEM squiggly_r_combo[] = {KC_Y, ALT_T(KC_I), COMBO_END};
const uint16_t PROGMEM forward_slash_combo[]    = {KC_U, RSFT_T(KC_N), COMBO_END};
const uint16_t PROGMEM backwards_slash_combo[] = {KC_U, ALT_T(KC_I), COMBO_END};
const uint16_t PROGMEM less_than_combo[]        = {KC_F, ALT_T(KC_S), COMBO_END};
const uint16_t PROGMEM larger_than_combo[]      = {KC_F, SFT_T(KC_H), COMBO_END};

const uint16_t PROGMEM redo_combo[]        = {KC_P, NO_MINS, COMBO_END};
const uint16_t PROGMEM undo_combo[]        = {SFT_T(KC_H), KC_COMM, COMBO_END};
const uint16_t PROGMEM esc_combo[]         = {KC_D, L_NAV, COMBO_END};
const uint16_t PROGMEM ent_combo[]         = {KC_X, GUI_T(KC_O), COMBO_END};
const uint16_t PROGMEM ent_thumb_combo[]   = {KC_E, KC_M, COMBO_END};
const uint16_t PROGMEM bspc_combo[]        = {KC_BSPC, KC_LSFT, COMBO_END};
const uint16_t PROGMEM caps_combo[]        = {NO_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM cps_word_combo[]   = {L_MOU, KC_E, COMBO_END};
// const uint16_t PROGMEM sleep_combo[]       = {L_MOU, KC_E, COMBO_END};

// const uint16_t PROGMEM bspc_combo[]        = {KC_BSPC, KC_LSFT, COMBO_END};
// const uint16_t PROGMEM delete_combo[]      = {KC_BSPC, KC_LSFT, COMBO_END};
// const uint16_t PROGMEM delete_word_combo[] = {KC_BSPC, KC_LSFT, COMBO_END};
// const uint16_t PROGMEM clear_line_combo[]  = {KC_BSPC, KC_LSFT, COMBO_END};

combo_t key_combos[] = {
    // [EM_EMAIL]        = COMBO_ACTION(email_combo),
    // [BSPC_LSFT_CLEAR] = COMBO_ACTION(clear_line_combo),
    [NORDIC_AE]         = COMBO(nordic_ae_combo, NO_AE),
    [NORDIC_OE]         = COMBO(nordic_oe_combo, NO_OSTR),
    [NORDIC_AA]         = COMBO(nordic_aa_combo, NO_ARNG),
    [MISSING_Q]         = COMBO(q_combo, KC_Q),
    [MISSING_Z]         = COMBO(z_combo, KC_Z),
    [MISSING_V]         = COMBO(v_combo, KC_V),
    [PARA_LEFT]         = COMBO(para_l_combo, NO_LPRN),
    [PARA_RIGHT]        = COMBO(para_r_combo, NO_RPRN),
    [SQUARE_LEFT]       = COMBO(square_l_combo, ALGR(NO_8)),
    [SQUARE_RIGHT]      = COMBO(square_r_combo, ALGR(NO_9)),
    [SQUIGGLY_LEFT]     = COMBO(squiggly_l_combo, ALGR(NO_7)),
    [SQUIGGLY_RIGHT]    = COMBO(squiggly_r_combo, ALGR(NO_0)),
    [FORWARD_SLASH]     = COMBO(forward_slash_combo, S(NO_7)),
    [BACKWARD_SLASH]    = COMBO(backwards_slash_combo, NO_BSLS),
    [LESS_THAN]         = COMBO(less_than_combo, NO_LABK),
    [LARGER_THAN]       = COMBO(larger_than_combo, S(NO_LABK)),
    [REDO]              = COMBO(redo_combo, C(KC_Y)),
    [UNDO]              = COMBO(undo_combo, C(KC_Z)),
    [ESC]               = COMBO(esc_combo, ALGR(NO_9)),
    [ENT]               = COMBO(ent_combo, KC_ENT),
    [TENT]              = COMBO(ent_thumb_combo, KC_ENT),
    [BACKSPC]           = COMBO(bspc_combo, KC_BSPC),
    [CAPS]              = COMBO(caps_combo, KC_CAPS),
    [CPS_WORD]         = COMBO_ACTION(cps_word_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case CPS_WORD:
            if (pressed) {
                caps_word_on(); // Activate Caps Word!
            }
            break;
    }
}
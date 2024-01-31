#include QMK_KEYBOARD_H

#include "keymap_uk.h"
#include "sendstring_uk.h"

#include "keycodes.h"
#include "numword.h"

#include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
    UK_Q,    UK_W,    UK_F,    UK_P,    UK_B,            UK_J,    UK_L,  UK_U,    UK_Y,   UK_QUOT,
    UK_A,    UK_R,    UK_S,    UK_T,    UK_G,            UK_M,    UK_N,  UK_E,    UK_I,   UK_O,
    UK_Z,    UK_X,    UK_C,    UK_D,    UK_V,            UK_K,    UK_H,  UK_COMM, UK_DOT, UK_SLSH,
                               LT_OT,   LT_HM,           RT_HM,   RT_OT
  ),

  [SYM] = LAYOUT(
    UK_HASH, UK_BSLS, UK_AMPR, UK_ASTR, xxxxxxx,      xxxxxxx, UK_EQL,  UK_MINS, UK_PLUS, UK_PERC,
    UK_CIRC, UK_LCBR, UK_RCBR, UK_DLR,  UK_NOT,       UK_GRV,  UK_UNDS, UK_LPRN, UK_RPRN, UK_SCLN,
    UK_EXLM, UK_LBRC, UK_RBRC, UK_DQUO, UK_PND,       UK_PIPE, UK_TILD, UK_LABK, UK_RABK, UK_COLN,
                               KC_TRNS, KC_TRNS,      KC_SPC,  KC_ENT
  ),

  // [NUM] = LAYOUT(
  //   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,      KC_TRNS, UK_4,    UK_5,    UK_6,    UK_DOT,
  //   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_TRNS,      KC_0,    UK_1,    UK_2,    UK_3,    UK_MINS,
  //   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_TRNS,      KC_TRNS, UK_7,    UK_8,    UK_9,    KC_TRNS,
  //                              KC_ENT,  KC_SPC,       KC_TRNS, KC_TRNS
  // ),

  [NUM] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, UK_EQL,  UK_MINS, UK_PLUS, UK_PERC,
    UK_6,    UK_4,    UK_0,    UK_2,    NUM_G,        KC_TRNS, UK_3,    UK_1,    UK_5,    UK_7,
    KC_TRNS, KC_TRNS, KC_TRNS, UK_8,    KC_TRNS,      KC_TRNS, UK_9,    KC_TRNS, KC_TRNS, KC_TRNS,
                               KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS
  ),

  [FUN] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_F6,   KC_F4,   KC_F10,  KC_F2,   KC_F12,       KC_F11,  KC_F3,   KC_F1,   KC_F5,   KC_F7,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_F8,   KC_TRNS,      KC_TRNS, KC_F9,   KC_TRNS, KC_TRNS, KC_TRNS,
                               KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS
  ),

  [NAV] = LAYOUT(
    KC_TRNS,  TB_PREV, KC_UP,   TB_NEXT, KC_VOLU,     KC_TRNS, WS_PREV, ALT_TAB, WS_NEXT, KC_PSCR,
    KC_TRNS,  KC_LEFT, KC_DOWN, KC_RGHT, KC_MPLY,     KC_TRNS, KC_LCTL, KC_LALT, KC_LGUI, KC_TRNS,
    KC_HOME,  KC_PGDN, KC_PGUP, KC_END,  KC_VOLD,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(GAME),
                                KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS
  ),

  [GAME] = LAYOUT(
    KC_ESC,   UK_Q,    UK_W,    UK_E,    UK_R,        KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS,
    KC_LSFT,  UK_A,    UK_S,    UK_D,    UK_F,        KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS,
    KC_LCTL,  UK_Z,    UK_X,    UK_C,    UK_V,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(GAME),
                                KC_ENT,  KC_SPC,      KC_TRNS, KC_TRNS
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_num_word(keycode, record)) {
        return false;
    }

    switch (keycode) {
        case NUMWORD:
            if (record->event.pressed) {
                enable_num_word();
            }
            return false;
        case NUM_G:
            if (record->event.pressed) {
                tap_code16(S(UK_G));
            }
            return false;
    }

    return true;
}

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    /* disable combos on gaming layer */
    if (layer_state_is(GAME)) {
        return false;
    }

    return true;
}

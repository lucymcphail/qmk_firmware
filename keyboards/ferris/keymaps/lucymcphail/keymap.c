#include QMK_KEYBOARD_H

#include "keymap_uk.h"
#include "sendstring_uk.h"

#include "g/keymap_combo.h"

#define LT_OT LT(NAV, KC_BSPC)
#define LT_HM LT(SYM, KC_SPC)
#define RT_HM OSM(MOD_LSFT)
#define RT_OT LT(NUM, KC_ENT)

#define TB_PREV LCTL(LSFT(KC_TAB))
#define TB_NEXT LCTL(KC_TAB)
#define WS_PREV LGUI(KC_PGUP)
#define WS_NEXT LGUI(KC_PGDN)
#define ALT_TAB LALT(KC_TAB)

enum layers { BASE, SYM, NUM, FUN, NAV, GAME };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
    UK_Q,    UK_W,    UK_F,    UK_P,    UK_B,            UK_J,    UK_L,  UK_U,    UK_Y,   UK_QUOT,
    UK_A,    UK_R,    UK_S,    UK_T,    UK_G,            UK_M,    UK_N,  UK_E,    UK_I,   UK_O,
    UK_Z,    UK_X,    UK_C,    UK_D,    UK_V,            UK_K,    UK_H,  UK_COMM, UK_DOT, UK_SLSH,
                               LT_HM,   LT_OT,           RT_OT,   RT_HM
  ),

  [SYM] = LAYOUT(
    KC_NO,   UK_HASH, UK_LABK, UK_RABK, UK_PND,       UK_PLUS, UK_LBRC, UK_RBRC, UK_TILD, UK_SCLN,
    UK_CIRC, UK_AMPR, UK_LCBR, UK_RCBR, UK_PERC,      UK_UNDS, UK_LPRN, UK_RPRN, UK_ASTR, UK_DLR,
    KC_NO,   UK_DQUO, UK_PIPE, UK_EXLM, UK_NOT,       UK_GRV,  UK_EQL,  UK_MINS, UK_BSLS, UK_COLN,
                               KC_TRNS, KC_TRNS,      KC_ENT,  KC_SPC
  ),

  [NUM] = LAYOUT(
    KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,      KC_TRNS, UK_4,    UK_5,    UK_6,    UK_DOT,
    KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_TRNS,      KC_0,    UK_1,    UK_2,    UK_3,    UK_MINS,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_TRNS,      KC_TRNS, UK_7,    UK_8,    UK_9,    KC_TRNS,
                               KC_SPC,  KC_ENT,       KC_TRNS, KC_TRNS
  ),

  [NAV] = LAYOUT(
    KC_TRNS,  TB_PREV, KC_UP,   TB_NEXT, KC_VOLU,     KC_TRNS, WS_PREV, ALT_TAB, WS_NEXT, KC_TRNS,
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

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    /* disable combos on gaming layer */
    if (layer_state_is(GAME)) {
        return false;
    }

    return true;
}

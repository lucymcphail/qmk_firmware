#pragma once

#include QMK_KEYBOARD_H

#include "keymap_uk.h"

enum layers { BASE, SYM, NUM, FUN, NAV, GAME };

enum my_keycodes {
    NUMWORD = QK_USER,
    NUM_G,
};

#define xxxxxxx KC_NO

#define LT_OT LT(NAV, KC_BSPC)
#define LT_HM LT(SYM, KC_SPC)
#define RT_HM OSM(MOD_LSFT)
#define RT_OT LT(FUN, KC_ENT)

#define TB_PREV LCTL(LSFT(KC_TAB))
#define TB_NEXT LCTL(KC_TAB)
#define WS_PREV LGUI(KC_PGUP)
#define WS_NEXT LGUI(KC_PGDN)
#define ALT_TAB LALT(KC_TAB)

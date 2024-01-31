#include "keycodes.h"

#include "keymap_uk.h"

static bool _num_word_enabled = false;

bool num_word_enabled(void) {
    return _num_word_enabled;
}

void enable_num_word(void) {
    _num_word_enabled = true;
    layer_on(NUM);
}

void disable_num_word(void) {
    _num_word_enabled = false;
    layer_off(NUM);
}

bool process_num_word(uint16_t keycode, const keyrecord_t *record) {
    if (!_num_word_enabled) return true;

    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            if (record->tap.count == 0)
                return true;
            keycode = keycode & 0xFF;
    }

    switch (keycode) {
        case UK_1 ... UK_0:
        case UK_PERC:
        case UK_COMM:
        case UK_DOT:
        case UK_SLSH:
        case UK_MINS:
        case UK_ASTR:
        case UK_PLUS:
        case UK_COLN:
        case UK_EQL:
        case UK_UNDS:
        case KC_BSPC:
        case KC_X:
        case KC_ENT:
            // Don't disable for above keycodes
            break;
        default:
            if (record->event.pressed) {
                disable_num_word();
            }
    }
    return true;
}

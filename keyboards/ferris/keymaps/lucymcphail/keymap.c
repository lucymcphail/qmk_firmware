#include QMK_KEYBOARD_H

#define HM_R LGUI_T(KC_R)
#define HM_S LALT_T(KC_S)
#define HM_T LCTL_T(KC_T)
#define HM_N RCTL_T(KC_N)
#define HM_E LALT_T(KC_E)
#define HM_I RGUI_T(KC_I)

#define LT_OT LT(NAV, KC_BSPC)
#define LT_HM LT(SYM, KC_SPC)
#define RT_HM OSM(MOD_LSFT)
#define RT_OT LT(NUM, KC_ENT)

#define UK_HASH KC_NUHS
#define UK_TILD LSFT(KC_NUHS)
#define UK_BSLS KC_NUBS
#define UK_PIPE LSFT(KC_NUBS)
#define UK_PND  KC_HASH
#define UK_DQUO KC_AT
#define UK_AT   KC_DQUO
#define UK_NOT  KC_TILD

#define TB_PREV LCTL(LSFT(KC_TAB))
#define TB_NEXT LCTL(KC_TAB)
#define WS_PREV LGUI(KC_PGUP)
#define WS_NEXT LGUI(KC_PGDN)
#define ALT_TAB LALT(KC_TAB)

enum layers { BASE, SYM, NUM, FUN, NAV, GAME };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,            KC_J,    KC_L,  KC_U,    KC_Y,   KC_QUOT,
    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,            KC_M,    KC_N,  KC_E,    KC_I,   KC_O,
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,            KC_K,    KC_H,  KC_COMM, KC_DOT, KC_SLSH,
                               LT_HM,   LT_OT,           RT_OT,   RT_HM
  ),

  [SYM] = LAYOUT(
    KC_NO,   UK_HASH, KC_LT,   KC_GT,   UK_PND,       KC_PLUS, KC_LBRC, KC_RBRC, UK_TILD, KC_SCLN,
    KC_CIRC, KC_AMPR, KC_LCBR, KC_RCBR, KC_PERC,      KC_UNDS, KC_LPRN, KC_RPRN, KC_ASTR, KC_DLR,
    KC_NO,   UK_DQUO, UK_PIPE, KC_EXLM, UK_NOT,       KC_GRV,  KC_EQL,  KC_MINS, UK_BSLS, KC_COLN,
                               KC_TRNS, KC_TRNS,      KC_ENT,  KC_SPC
  ),

  [NUM] = LAYOUT(
    KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,      KC_TRNS, KC_4,    KC_5,    KC_6,    KC_DOT,
    KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_TRNS,      KC_0,    KC_1,    KC_2,    KC_3,    KC_MINS,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_TRNS,      KC_TRNS, KC_7,    KC_8,    KC_9,    KC_TRNS,
                               KC_SPC,  KC_ENT,       KC_TRNS, KC_TRNS
  ),

  [NAV] = LAYOUT(
    KC_TRNS,  TB_PREV, KC_UP,   TB_NEXT, KC_VOLU,     KC_TRNS, WS_PREV, ALT_TAB, WS_NEXT, KC_TRNS,
    KC_TRNS,  KC_LEFT, KC_DOWN, KC_RGHT, KC_MPLY,     KC_TRNS, KC_LCTL, KC_LALT, KC_LGUI, KC_TRNS,
    KC_HOME,  KC_PGDN, KC_PGUP, KC_END,  KC_VOLD,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(GAME),
                                KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS
  ),

  [GAME] = LAYOUT(
    KC_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,        KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS,
    KC_LSFT,  KC_A,    KC_S,    KC_D,    KC_F,        KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS,
    KC_LCTL,  KC_Z,    KC_X,    KC_C,    KC_V,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(GAME),
                                KC_ENT,  KC_SPC,      KC_TRNS, KC_TRNS
  ),
};

enum combos {
    COMBO_ESC,
    COMBO_TAB,
    COMBO_DEL,

    COMBO_LGUI,
    COMBO_LALT,
    COMBO_LCTL,
    COMBO_LCTLALT,
    COMBO_RCTLALT,
    COMBO_RCTL,
    COMBO_RALT,
    COMBO_RGUI,

    COMBO_CAPSWORD,

    COMBO_LENGTH // nifty trick to avoid manually specifying how many combos you have
};

uint16_t COMBO_LEN = COMBO_LENGTH; // nifty trick continued

const uint16_t PROGMEM fp_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM lu_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM uy_combo[] = {KC_U, KC_Y, COMBO_END};

const uint16_t PROGMEM ar_combo[] = {KC_A, KC_R, COMBO_END};
const uint16_t PROGMEM rs_combo[] = {KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM st_combo[] = {KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM rst_combo[] = {KC_R, KC_S, KC_T, COMBO_END};

const uint16_t PROGMEM nei_combo[] = {KC_N, KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM ne_combo[] = {KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM ei_combo[] = {KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};

const uint16_t PROGMEM sftspc_combo[] = {LT_HM, RT_HM, COMBO_END};

combo_t key_combos[] = {
    [COMBO_ESC] = COMBO(fp_combo, KC_ESC),
    [COMBO_TAB] = COMBO(lu_combo, KC_TAB),
    [COMBO_DEL] = COMBO(uy_combo, KC_DEL),

    [COMBO_LGUI] = COMBO(ar_combo, OSM(MOD_LGUI)),
    [COMBO_LALT] = COMBO(rs_combo, OSM(MOD_LALT)),
    [COMBO_LCTL] = COMBO(st_combo, OSM(MOD_LCTL)),
    [COMBO_LCTLALT] = COMBO(rst_combo, OSM(MOD_LCTL | MOD_LALT)),
    [COMBO_RCTLALT] = COMBO(nei_combo, OSM(MOD_LCTL | MOD_LALT)),
    [COMBO_RCTL] = COMBO(ne_combo, OSM(MOD_LCTL)),
    [COMBO_RALT] = COMBO(ei_combo, OSM(MOD_LALT)),
    [COMBO_RGUI] = COMBO(io_combo, OSM(MOD_LGUI)),

    [COMBO_CAPSWORD] = COMBO(sftspc_combo, CW_TOGG),
};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    /* disable combos on gaming layer */
    if (layer_state_is(GAME)) {
        return false;
    }

    return true;
}

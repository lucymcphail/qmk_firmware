COMBO_ENABLE = yes
CAPS_WORD_ENABLE = yes
RGBLIGHT_ENABLE = no

# allow easier combo definitions
VPATH += keyboards/gboards

# disable extra features I don't use
WPM_ENABLE = no
MOUSEKEY_ENABLE = no
KEY_OVERRIDE_ENABLE = no
LEADER_ENABLE = no
TAP_DANCE_ENABLE = no
RGB_MATRIX_ENABLE = no

SRC += numword.c

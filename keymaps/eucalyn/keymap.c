#include "kb.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _EUCALYN 0
#define _QWERTY 1
#define _LOWER 2
#define _RAISE 4
#define _ARROW 6
#define _MOUSE 8
#define _ADJUST 16

#define KC_____ KC_TRNS
#define KC_RESET RESET
#define KC_B_BK LALT(KC_LEFT) //ブラウザバック
#define KC_ADJUST MO(_ADJUST)
#define ____ KC_NO
#define KC_MOUSE MO(_MOUSE)
#define KC_ARROW MO(_ARROW)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_EUCALYN] = LAYOUT( \
          KC_TAB,  KC_Q, KC_W, KC_COMM, KC_DOT, KC_MINUS,       KC_M, KC_Y, KC_K, KC_R, KC_P, KC_BSPC,
          LCTL_T(KC_ESC), KC_A, KC_O, KC_E, KC_I, KC_U,         KC_N, KC_H, KC_J, KC_L, KC_G, KC_ENT,
          KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_F,                KC_S, KC_T, KC_D, KC_B, KC_SLSH, KC_RSFT,
          LCTL_T(KC_ESC), KC_LGUI, KC_LALT, LT(_MOUSE, LCTL(KC_SPC)), LT(_LOWER, KC_TAB), LT(_LOWER, KC_SPC),    
                LT(_RAISE, KC_ENT), KC_BSPC, LCTL(KC_ESC), KC_DOWN, KC_UP, KC_RIGHT
),

[_QWERTY] = LAYOUT_kc( \
            ____, Q, W, E, R, T, Y, U, I, O, P, ____,
            ____, A, S, D, F, G, H, J, K, L, MINUS, ____,
            ____, Z, X, C, V, B, N, M, COMM, DOT, SLSH, ____,
            ____, ____, ____, ____, ____, ____,    ____, ____, ____, ____, ____, ____
),

[_LOWER] = LAYOUT_kc( \
            MOUSE, EXLM, AT,   HASH, DLR,  PERC,    CIRC, AMPR, ASTR, LPRN, RPRN, DEL,
            ____,       1,    2,    3,    4,    5,       6,    7,    8,    9,    0,    ____,
            ARROW, ____, ____, ____, ____, ____,    ____, ____, ____, ____, ____, ____,
            ____,       ____, ____, ____, ____, ____,    ADJUST,END, ____, ____, ____, ____
),

[_RAISE] = LAYOUT_kc( \
            LALT, NO,   ESC,  TILD, PLUS, LCBR,    RCBR, COLN, DQUO, QUES, PIPE, ____,
            LCTL, NO,   NO,   GRV,  EQL,  LBRC,    RBRC, SCLN, QUOT, SLSH, BSLS, ____,
            LSFT, ____, ____, ____, ____, ____,    ____, ____, ____, ____, ____, ____,
            LCTL, LGUI, ____, ____, ____, ADJUST,  ____, ____, ____, ____, ____, ____
),

[_ARROW] = LAYOUT_kc( \
            LALT, F1,   F2,   F3,   F4,  ____,     ____, ____, UP,   ____,  VOLU, ____,
            LCTL, F5,   F6,   F7,   F8,  ____,     LEFT, LEFT, DOWN, RIGHT, BSLS,____,
            LSFT, F9,   F10,  F11,  F12, ____,     HOME, PGDN, PGUP, END,   VOLD, ____,
            ____, ____, ____, ____, ____, ____,    ____, ____, ____, ____,  ____, ____
),

[_MOUSE] = LAYOUT_kc( \
            LALT, ____, ____, ____, ____, ____,    B_BK, WH_U, MS_U, NO,   ____, VOLU,
            LCTL, ____, ____, ____, ____, ____,    MS_L, MS_L, MS_D, MS_R, ____, PSCR,
            LSFT, ____, ____, ____, ____, ____,    MS_BTN1, WH_D, MS_BTN2, ____, ____, VOLD,
            ____, ____, ____, ____, ____, ____,    MS_BTN1, MS_BTN2, ____, ____, ____, ____
),

[_ADJUST] = LAYOUT( \
            ____, DF(_QWERTY), ____, DF(_EUCALYN), ____, ____,    ____, ____, ____, ____, ____, RESET,
            ____, ____, ____, DF(_EUCALYN), ____, ____,    ____, ____, ____, ____, ____, ____,
            ____, ____, ____, ____, ____, ____,    ____, ____, ____, ____, ____, ____,
            ____, ____, ____, ____, ____, ____,    ____, ____, ____, ____, ____, ____
)
};

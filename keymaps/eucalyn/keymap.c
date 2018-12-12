#include "kb.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _EUCALYN 0
#define _QWERTY 1
#define _TRANS 2
#define _LOWER 3
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
#define KC_DF2 TO(_TRANS)
#define KC_CTL_L LM(_TRANS, KC_LCTL)

//Tap Dance Declarations
enum {
    TD_ALT_GUI = 0,
    TD_IME,
    TD_RSHIFT_MOUSE
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  //[TD_ESC_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS)
  [TD_ALT_GUI]  = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_LGUI),
  [TD_IME] = ACTION_TAP_DANCE_DOUBLE( LCTL(KC_ESC), LCTL(KC_SPC) ),
  [TD_RSHIFT_MOUSE] = ACTION_TAP_DANCE_DUAL_ROLE( KC_RSFT, _MOUSE )
// Other declarations would go here, separated by commas, if you have them
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_EUCALYN] = LAYOUT( \
          KC_TAB,  KC_Q, KC_W, KC_COMM, KC_DOT, KC_MINUS,       KC_M, KC_Y, KC_K, KC_R, KC_P, KC_BSPC,
          LCTL_T(KC_ESC), KC_A, KC_O, KC_E, KC_I, KC_U,         KC_N, KC_H, KC_J, KC_L, KC_G, KC_ENT,
          KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_F,                KC_S, KC_T, KC_D, KC_B, KC_SLSH, TD(TD_RSHIFT_MOUSE),
          LCTL_T(KC_ESC), KC_LEFT, KC_DOWN, LT(_ARROW, LCTL(KC_SPC)), LT(_LOWER, KC_TAB), LT(_LOWER, KC_SPC),    
                LT(_RAISE, KC_ENT), KC_BSPC, TD(TD_IME), KC_UP, KC_RIGHT, TD(TD_ALT_GUI)
),

[_QWERTY] = LAYOUT_kc( \
            ____, Q, W, E, R, T, Y, U, I, O, P, ____,
            ____, A, S, D, F, G, H, J, K, L, MINUS, ____,
            ____, Z, X, C, V, B, N, M, COMM, DOT, SLSH, ____,
            ____, ____, ____, ____, ____, ____,    ____, ____, ____, ____, ____, ____
),

[_TRANS] = LAYOUT_kc( \
            ____, ____, ____, ____, ____, ____,    ____, ____, ____, ____, ____, ____,
            ____, ____, ____, ____, ____, ____,    ____, ____, ____, ____, ____, ____,
            ____, ____, ____, ____, ____, ____,    ____, ____, ____, ____, ____, ____,
            ____, ____, ____, ____, ____, ____,    ____, ____, ____, ____, ____, ____
),

[_LOWER] = LAYOUT_kc( \
            MOUSE, EXLM, AT,   HASH, DLR,  PERC,    CIRC, AMPR, ASTR, LPRN, RPRN, DEL,
            ____,     1,    2,    3,    4,    5,       6,    7,    8,    9,    0, ____,
            ARROW, ____, ____, ____, ____, ____,    ____, ____, ____, ____, ____, ____,
            ____,  ____, ____, ____, ____, ____,    ADJUST,END, ____, ____, ____, ____
),

[_RAISE] = LAYOUT_kc( \
            ____, NO,   ESC,  TILD, PLUS, LCBR,    RCBR, COLN, DQUO, QUES, PIPE, ____,
            ____, NO,   NO,   GRV,  EQL,  LBRC,    RBRC, SCLN, QUOT, SLSH, BSLS, ____,
            ____, ____, ____, ____, ____, ____,    ____, ____, ____, ____, ____, ____,
            ____, LGUI, LALT, ____, ____, ADJUST,  ____, ____, ____, RALT, RGUI, ____
),

[_ARROW] = LAYOUT_kc( \
            ____, F1,   F2,   F3,   F4,  ____,     ____, ____, UP,   ____,  VOLU, ____,
            ____, F5,   F6,   F7,   F8,  ____,     LEFT, LEFT, DOWN, RIGHT, BSLS,____,
            ____, F9,   F10,  F11,  F12, ____,     HOME, PGDN, PGUP, END,   VOLD, ____,
            ____, ____, ____, ____, ____, ____,    ____, ____, ____, ____,  ____, ____
),

[_MOUSE] = LAYOUT_kc( \
            ____, ____, ____, ____, ____, ____,    B_BK, WH_U, MS_U, NO,   ____, ____,
            ____, ____, ____, ____, ____, ____,    MS_L,  MS_L, MS_D, MS_R, ____, ____,
            ____, ____, ____, ____, ____, ____,    MS_BTN1, WH_D, MS_BTN2, ____, ____, ____,
            ____, ____, ____, ARROW, ____, ____,    MS_BTN1, MS_BTN2, ____, ____, ____, DF2
),

[_ADJUST] = LAYOUT( \
            ____, DF(_QWERTY), ____, DF(_EUCALYN), ____, ____,    ____, ____, ____, KC_PSCR, KC_VOLU, RESET,
            ____, ____, ____, DF(_EUCALYN), ____, ____,    ____, ____, ____, ____, KC_VOLD, ____,
            ____, ____, ____, ____, ____, ____,    ____, ____, ____, ____, ____, ____,
            ____, ____, ____, ____, ____, ____,    ____, ____, ____, ____, ____, ____
)
};

 

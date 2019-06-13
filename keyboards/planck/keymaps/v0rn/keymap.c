#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum layers {
    _QWERTY,
    _GAME,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum tap_dance_codes {
    TD_ESC_TAB = 0,
};

#define XX       KC_NO               /* Replace XXXXXXX */
#define __       KC_TRNS             /* Replace _______ */

/* Default layer keys */
#define QWERTY   DF(_QWERTY)
#define GAME     DF(_GAME)

/* Momentary layers keys */
#define LOWER    MO(_LOWER)
#define RAISE    TT(_RAISE)

/* Mod-Tap keys */
#define CTL_ESC  LCTL_T(KC_ESC)      /* Hold: L Ctrl,  Tap: Esc   */
#define SFT_NUBS LSFT_T(KC_NUBS)     /* Hold: L Shift, Tap: NUBS  */
#define SFT_ENT  RSFT_T(KC_ENT)      /* Hold: R Shift, Tap: Enter */

/* Tab Dance keys */
#define ESC_TAB TD(TD_ESC_TAB)

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_TAB),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_planck_grid(
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
        CTL_ESC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
        SFT_NUBS, KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  SFT_ENT,
        XX,       GAME,     XX,       KC_LGUI,  KC_LALT,  LOWER,    KC_SPC,   RAISE,    KC_RALT,  KC_RGUI,  XX,       XX
    ),

    [_LOWER] = LAYOUT_planck_grid(
        KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC,
        KC_LCTL,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_BSLS,
        KC_LSFT,  KC_LBRC,  KC_LCBR,  KC_PLUS,  KC_EQL,   KC_TILD,  XX,       KC_MINS,  KC_UNDS,  KC_RCBR,  KC_RBRC,  KC_RSFT,
        XX,       XX,       XX,       __,       __,       __,       __,       __,       __,       XX,       XX,       XX
    ),

    [_RAISE] = LAYOUT_planck_grid(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_DEL,
        KC_LCTL,  KC_F11,   KC_F12,   XX,       XX,       XX,       KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  XX,       XX,
        KC_LSFT,  XX,       XX,       XX,       XX,       XX,       KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   XX,       __,
        XX,       XX,       XX,       __,       __,       __,       __,       __,       __,       KC_MUTE,  KC_VOLD,  KC_VOLU
    ),

    [_GAME] = LAYOUT_planck_grid(
        ESC_TAB,  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  SFT_ENT,
        KC_LCTL,  QWERTY,   KC_7,     KC_LALT,  KC_SPC,   KC_3,     KC_4,     KC_5,     KC_6,     KC_MUTE,  KC_VOLD,  KC_VOLU
    ),

    [_ADJUST] = LAYOUT_planck_grid(
        XX,       XX,       XX,       XX,       RESET,    XX,       XX,       XX,       XX,       XX,       XX,       XX,
        XX,       XX,       XX,       DEBUG,    XX,       XX,       XX,       XX,       XX,       XX,       XX,       XX,
        XX,       XX,       XX,       XX,       XX,       XX,       XX,       XX,       XX,       XX,       XX,       XX,
        XX,       XX,       XX,       XX,       XX,       __,       __,       XX,       XX,       XX,       XX,       XX
    )
};

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

/* vim: set expandtab shiftwidth=0 tabstop=4: */


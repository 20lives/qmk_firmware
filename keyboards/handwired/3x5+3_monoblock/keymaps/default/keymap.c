#include QMK_KEYBOARD_H

// Layer definitions
enum layers {
    _DVORAK = 0,
    _QWERTY,
    _RAISE,
    _LOWER
};

// Custom keycodes for layer management
enum custom_keycodes {
    DVORAK = SAFE_RANGE,
    QWERTY
};

// Homerow mod aliases for cleaner keymap
#define HM_A    LSFT_T(KC_A)
#define HM_O    LALT_T(KC_O)
#define HM_E    LGUI_T(KC_E)
#define HM_U    LCTL_T(KC_U)
#define HM_H    RCTL_T(KC_H)
#define HM_T    RGUI_T(KC_T)
#define HM_N    LALT_T(KC_N)
#define HM_S    RSFT_T(KC_S)

// QWERTY homerow mods
#define QHM_A   LSFT_T(KC_A)
#define QHM_S   LALT_T(KC_S)
#define QHM_D   LGUI_T(KC_D)
#define QHM_F   LCTL_T(KC_F)
#define QHM_J   RCTL_T(KC_J)
#define QHM_K   RGUI_T(KC_K)
#define QHM_L   LALT_T(KC_L)
#define QHM_SCLN RSFT_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base (Dvorak)
 * ,---------------------------------------,                                  ,---------------------------------------,
 * |   '   |   ,   |   .   |   p   |   y   |                                  |   f   |   g   |   c   |   r   |   l   | 
 * |-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------|
 * |   a   |   o   |   e   |   u   |   i   |                                  |   d   |   h   |   t   |   n   |   s   |
 * |-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------|
 * |   ;   |   q   |   j   |   k   |   x   |                                  |   b   |   m   |   w   |   v   |   z   |
 * '-------------------------------------------------------,  ,-------------------------------------------------------'
 *                                 |  ESC  |  BS   | RAISE |  | LOWER | SPACE | ENTER |
 *                                 '-----------------------'  '-----------------------'
 */
    [_DVORAK] = LAYOUT_split_3x5_3(
        KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,
        HM_A,    HM_O,    HM_E,    HM_U,    KC_I,    KC_D,    HM_H,    HM_T,    HM_N,    HM_S,
        KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,
                          KC_ESC,  KC_BSPC, MO(_RAISE), MO(_LOWER), KC_SPC, KC_ENT
    ),

/* QWERTY
 * ,---------------------------------------,                                  ,---------------------------------------,
 * |   q   |   w   |   e   |   r   |   t   |                                  |   y   |   u   |   i   |   o   |   p   |
 * |-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------|
 * |   a   |   s   |   d   |   f   |   g   |                                  |   h   |   j   |   k   |   l   |   ;   |
 * |-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------|
 * |   z   |   x   |   c   |   v   |   b   |                                  |   n   |   m   |   ,   |   .   |   /   |
 * '-------------------------------------------------------,  ,-------------------------------------------------------'
 *                                 |       |       |       |  |       |       |       |
 *                                 '-----------------------'  '-----------------------'
 */
    [_QWERTY] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        QHM_A,   QHM_S,   QHM_D,   QHM_F,   KC_G,    KC_H,    QHM_J,   QHM_K,   QHM_L,   QHM_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

/* Raise
 * ,---------------------------------------,                                  ,---------------------------------------,
 * |   F1  |  F2   |  F3   |  F4   |  F5   |                                  |  PGUP |  HOME |  up   |  END  |  DEL  | 
 * |-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------|
 * |   F6  |  F7   |  F8   |  F9   |  F10  |                                  |  PGDN |  left |  down | right |  TAB  |
 * |-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------|
 * |  F11  |  F12  |       |       |       |                                  |   {   |   [   |   ?   |   ]   |   }   |
 * '-------------------------------------------------------,  ,-------------------------------------------------------'
 *                                 |       |       |       |  |       |       |       |
 *                                 '-----------------------'  '-----------------------'
 */
    [_RAISE] = LAYOUT_split_3x5_3(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_DEL,
        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_TAB,
        KC_F11,  KC_F12,  KC_TRNS, KC_TRNS, KC_TRNS, KC_LCBR, KC_LBRC, KC_QUES, KC_RBRC, KC_RCBR,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

/* Lower
 * ,---------------------------------------,                                   ,---------------------------------------,
 * |   =   |   +   |   -   |   _   |   |   |                                   |   /   |   \   |   `   |   ~   |       | 
 * |-------+-------+-------+-------+-------|                                   |-------+-------+-------+-------+-------|
 * |   1   |   2   |   3   |   4   |   5   |                                   |   6   |   7   |   8   |   9   |   0   |
 * |-------+-------+-------+-------+-------|                                   |-------+-------+-------+-------+-------|
 * |   !   |   @   |   #   |   $   |   %   |                                   |   ^   |   &   |   *   |   (   |   )   |
 * '-------------------------------------------------------,  ,--------------------------------------------------------'
 *                                 |       |       |       |  |       |       |       |
 *                                 '-----------------------'  '-----------------------'
 */
    [_LOWER] = LAYOUT_split_3x5_3(
        KC_EQL,  KC_PLUS, KC_MINS, KC_UNDS, KC_PIPE, KC_SLSH, KC_BSLS, KC_GRV,  KC_TILD, KC_TRNS,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};

// Layer switching logic
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DVORAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_DVORAK);
            }
            return false;
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
    }
    return true;
}

// Combos implementation (QMK equivalent of ZMK combos)
const uint16_t PROGMEM combo_qwerty[] = {KC_G, KC_C, KC_R, COMBO_END};
const uint16_t PROGMEM combo_dvorak[] = {KC_H, KC_T, KC_N, COMBO_END};
const uint16_t PROGMEM combo_reset[] = {KC_QUOT, KC_L, COMBO_END};      // Top corners: ' + l
const uint16_t PROGMEM combo_bootloader[] = {KC_SCLN, KC_Z, COMBO_END}; // Bottom corners: ; + z

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_qwerty, TG(_QWERTY)),
    COMBO(combo_dvorak, TG(_DVORAK)),
    COMBO(combo_reset, QK_RBT),         // Reset (soft reset)
    COMBO(combo_bootloader, QK_BOOT),   // Bootloader (for flashing)
};

// Per-key tap-hold configuration
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Pinkies get longer timing (harder to press precisely)
        case LSFT_T(KC_A):    // HM_A / QHM_A
        case RSFT_T(KC_S):    // HM_S  
        case RSFT_T(KC_SCLN): // QHM_SCLN
            return TAPPING_TERM + 50;
            
        // Index fingers can be faster (easier to control)
        case LCTL_T(KC_U):    // HM_U
        case RCTL_T(KC_H):    // HM_H
        case LCTL_T(KC_F):    // QHM_F
        case RCTL_T(KC_J):    // QHM_J
            return TAPPING_TERM - 25;
            
        // Middle fingers standard timing
        case LGUI_T(KC_E):    // HM_E
        case RGUI_T(KC_T):    // HM_T
        case LGUI_T(KC_D):    // QHM_D
        case RGUI_T(KC_K):    // QHM_K
            return TAPPING_TERM;
            
        // Ring fingers slightly longer
        case LALT_T(KC_O):    // HM_O
        case LALT_T(KC_N):    // HM_N
        case LALT_T(KC_S):    // QHM_S (different from Dvorak S)
        case LALT_T(KC_L):    // QHM_L
            return TAPPING_TERM + 25;
            
        default:
            return TAPPING_TERM;
    }
}
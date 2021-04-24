/* 
 * Rino: my personal keymap
 */
#include "keymap_common.h"


#ifdef KEYMAP_SECTION_ENABLE
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] __attribute__ ((section (".keymap.keymaps"))) = {
#else
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
#endif
    /* Layer 0: Default Layer
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|  `|
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Backs|
     * |-----------------------------------------------------------|
     * |Contro|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Enter   |
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Fn2|
     * `-----------------------------------------------------------'
     *       |Fn1|Gui  |         Space         |Gui  |Alt|
     *       `-------------------------------------------'
     */
    KEYMAP(ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSLS,GRV,   \
           TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSPC,       \
           LCTL,A,   S,   D,   F,   G, FN8, FN9,FN10,FN11,   FN6 ,QUOT,ENT,             \
           FN7 ,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,FN1,             \
                FN1 ,FN4 ,          SPC,                FN5 ,LALT),

    /* Layer 1: HHKB mode (HHKB Fn) HJKL
     * ,-----------------------------------------------------------.
     * |Esc| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Ins|Del|
     * |-----------------------------------------------------------|
     * |Caps |   |   |   |   |   |   |   |   |   |   |Up |Psc|Backs|
     * |-----------------------------------------------------------|
     * |      |   |   |   |   |   |Lef|Dow|Up |Rig|Lef|Rig|Enter   |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |   |   |   |   |Dow|      |   |
     * `-----------------------------------------------------------'
     *       |   |     |                       |     |   |
     *       `-------------------------------------------'
     */
    KEYMAP(ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, INS, DEL,   \
           CAPS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, UP, PSCR, BSPC,      \
           LCTL,TRNS,TRNS,TRNS,TRNS,TRNS,LEFT,DOWN, UP ,RGHT,LEFT,RGHT,PENT,            \
           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,DOWN,TRNS,TRNS,            \
                TRNS,TRNS,          TRNS,               TRNS,TRNS),

    /* Layer 2: Mouse mode
     * ,-----------------------------------------------------------.
     * |Esc| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Ins|Del|
     * |-----------------------------------------------------------|
     * |Tab  |   |   |   |   |   |MwL|MwD|MwU|MwR|   |   |   |Backs|
     * |-----------------------------------------------------------|
     * |Contro|   |   |   |   |   |McL|McD|McU|McR|   |   |Return  |
     * |-----------------------------------------------------------|
     * |Shift   |   |   |   |   |Mb3|Mb2|Mb1|   |   |   |Shift |   |
     * `-----------------------------------------------------------'
     *      |Gui |Alt  |          Mb1          |Alt  |Gui|
     *      `--------------------------------------------'
     * Mc: Mouse Cursor / Mb: Mouse Button / Mw: Mouse Wheel 
     */
    KEYMAP(GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, INS, DEL, \
           TAB, NO,  NO,  NO,  NO,  NO,  NO,  WH_D,WH_U,RGHT,NO,  NO,  NO,  BSPC, \
           LCTL,NO,  NO,  NO,  NO,  NO,  MS_L,MS_D,MS_U,MS_R,NO  ,NO  ,ENT, \
           LSFT,NO,  NO,  NO,  NO,  BTN3,BTN2,BTN1,NO,  NO,  NO,  RSFT,TRNS, \
                TRNS,TRNS,          BTN1,               TRNS,TRNS),
};

/*
 * user defined action function
 */

enum function_id {
    ARROW_H,
    ARROW_J,
    ARROW_K,
    ARROW_L,
    ARROW_HOME,
    ARROW_END,
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
#   define MAGIC_MOD        MOD_BIT(KC_LCTL)
    static uint8_t isMagicModPressed;

    switch (id) {
        case ARROW_H:
            isMagicModPressed = get_mods() & MAGIC_MOD;

            if (record->event.pressed) {
                if (isMagicModPressed) {
                    del_mods(MAGIC_MOD);
                    send_keyboard_report();
                    add_key(KC_LEFT);
                    send_keyboard_report();
                    add_mods(MAGIC_MOD);
                }
                else {
                    add_key(KC_H);
                    send_keyboard_report();
                }
            }
            else {
                if (isMagicModPressed) {
                    del_mods(MAGIC_MOD);
                    del_key(KC_LEFT);
                    del_key(KC_H);
                    send_keyboard_report();
                    add_mods(MAGIC_MOD);
                }
                else {
                    del_key(KC_LEFT);
                    del_key(KC_H);
                    send_keyboard_report();
                }
            }
            break;

        case ARROW_J:
            isMagicModPressed  = get_mods() & MAGIC_MOD;

            if (record->event.pressed) {
                if (isMagicModPressed) {
                    del_mods(MAGIC_MOD);
                    send_keyboard_report();
                    add_key(KC_DOWN);
                    send_keyboard_report();
                    add_mods(MAGIC_MOD);
                }
                else {
                    add_key(KC_J);
                    send_keyboard_report();
                }
            }
            else {
                if (isMagicModPressed) {
                    del_mods(MAGIC_MOD);
                    del_key(KC_DOWN);
                    del_key(KC_J);
                    send_keyboard_report();
                    add_mods(MAGIC_MOD);
                }
                else {
                    del_key(KC_DOWN);
                    del_key(KC_J);
                    send_keyboard_report();
                }
            }
            break;

        case ARROW_K:
            isMagicModPressed = get_mods() & MAGIC_MOD;

            if (record->event.pressed) {
                if (isMagicModPressed) {
                    del_mods(MAGIC_MOD);
                    send_keyboard_report();
                    add_key(KC_UP);
                    send_keyboard_report();
                    add_mods(MAGIC_MOD);
                }
                else {
                    add_key(KC_K);
                    send_keyboard_report();
                }
            }
            else {
                if (isMagicModPressed) {
                    del_mods(MAGIC_MOD);
                    del_key(KC_UP);
                    del_key(KC_K);
                    send_keyboard_report();
                    add_mods(MAGIC_MOD);
                }
                else {
                    del_key(KC_UP);
                    del_key(KC_K);
                    send_keyboard_report();
                }
            }
            break;

        case ARROW_L:
            isMagicModPressed = get_mods() & MAGIC_MOD;

            if (record->event.pressed) {
                if (isMagicModPressed) {
                    del_mods(MAGIC_MOD);
                    send_keyboard_report();
                    add_key(KC_RIGHT);
                    send_keyboard_report();
                    add_mods(MAGIC_MOD);
                }
                else {
                    add_key(KC_L);
                    send_keyboard_report();
                }
            }
            else {
                if (isMagicModPressed) {
                    del_mods(MAGIC_MOD);
                    del_key(KC_RIGHT);
                    del_key(KC_L);
                    send_keyboard_report();
                    add_mods(MAGIC_MOD);
                }
                else {
                    del_key(KC_RIGHT);
                    del_key(KC_L);
                    send_keyboard_report();
                }
            }
            break;

        case ARROW_HOME:
            isMagicModPressed = get_mods() & MAGIC_MOD;

            if (record->event.pressed) {
                if (isMagicModPressed) {
                    del_mods(MAGIC_MOD);
                    send_keyboard_report();
                    add_key(KC_HOME);
                    send_keyboard_report();
                    add_mods(MAGIC_MOD);
                }
                else {
                    add_key(KC_A);
                    send_keyboard_report();
                }
            }
            else {
                if (isMagicModPressed) {
                    del_mods(MAGIC_MOD);
                    del_key(KC_HOME);
                    del_key(KC_A);
                    send_keyboard_report();
                    add_mods(MAGIC_MOD);
                }
                else {
                    del_key(KC_HOME);
                    del_key(KC_A);
                    send_keyboard_report();
                }
            }
            break;
    
        case ARROW_END:
            isMagicModPressed = get_mods() & MAGIC_MOD;

            if (record->event.pressed) {
                if (isMagicModPressed) {
                    del_mods(MAGIC_MOD);
                    send_keyboard_report();
                    add_key(KC_END);
                    send_keyboard_report();
                    add_mods(MAGIC_MOD);
                }
                else {
                    add_key(KC_E);
                    send_keyboard_report();
                }
            }
            else {
                if (isMagicModPressed) {
                    del_mods(MAGIC_MOD);
                    del_key(KC_END);
                    del_key(KC_E);
                    send_keyboard_report();
                    add_mods(MAGIC_MOD);
                }
                else {
                    del_key(KC_END);
                    del_key(KC_E);
                    send_keyboard_report();
                }
            }
            break;
    }
}

/*
 * Fn action definition
 */
#ifdef KEYMAP_SECTION_ENABLE
const action_t fn_actions[] __attribute__ ((section (".keymap.fn_actions"))) = {
#else
const action_t fn_actions[] PROGMEM = {
#endif
    [ 0] = ACTION_DEFAULT_LAYER_SET(0),                // Default layer (not used)
    [ 1] = ACTION_LAYER_MOMENTARY(1),                  // HHKB
    [ 2] = ACTION_LAYER_TOGGLE(2),                     // Mouse key
    [ 3] = ACTION_LAYER_TOGGLE(0),                     // Default
    [ 4] = ACTION_MODS_TAP_KEY(MOD_LGUI, KC_LANG2),
    [ 5] = ACTION_MODS_TAP_KEY(MOD_RGUI, KC_LANG1),
    [ 6] = ACTION_LAYER_TAP_KEY(1, KC_SCLN),
    [ 7] = ACTION_MODS_ONESHOT(MOD_LSFT),              // Oneshot shift
    [ 8] = ACTION_FUNCTION(ARROW_H),
    [ 9] = ACTION_FUNCTION(ARROW_J),
    [10] = ACTION_FUNCTION(ARROW_K),
    [11] = ACTION_FUNCTION(ARROW_L),
    [12] = ACTION_FUNCTION(ARROW_HOME),
    [13] = ACTION_FUNCTION(ARROW_END),
};



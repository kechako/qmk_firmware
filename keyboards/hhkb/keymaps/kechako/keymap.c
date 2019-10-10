/*  -*-  eval: (turn-on-orgtbl); -*-
 * kechako HHKB Layout
 */
#include QMK_KEYBOARD_H

#define MAC_BASE 0
#define MAC_HHKB 1
#define WIN_BASE 2
#define WIN_HHKB 3

#define JP_MKANA KC_LANG1  // kana on macOS
#define JP_MEISU KC_LANG2  // eisu on macOS
#define JP_WKANA KC_F17    // F17 on Windows
#define JP_WEISU KC_F18    // F18 on Windows

#define SANDS    MT(MOD_LSFT, KC_SPC)
#define RGUI_MKANA MT(MOD_RGUI, JP_MKANA)
#define LGUI_MEISU MT(MOD_LGUI, JP_MEISU)
#define RGUI_WKANA MT(MOD_RGUI, JP_WKANA)
#define LGUI_WEISU MT(MOD_LGUI, JP_WEISU)

#define MOD_LCTRL MOD_BIT(KC_LCTL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* MAC_BASE Level: Mac Default Layer
     |-----------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Esc     | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | -     | =   | \     | ` |
     |---------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Tab     | Q | W | E | R | T | Y | U | I | O | P | [     | ]   | Backs |   |
     |---------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Control | A | S | D | F | G | H | J | K | L | ; | '     | Ent |       |   |
     |---------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Shift   | Z | X | C | V | B | N | M | , | . | / | Shift | Fn0 |       |   |
     |---------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|

      |------+------------+-----------------------+------------+------|
      | LAlt | LGUI_MEISU | ******* SANDS ******* | RGUI_MKANA | RAlt |
      |------+------------+-----------------------+------------+------|
    */

    [MAC_BASE] = LAYOUT( //  default layer
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_GRV,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, MO(MAC_HHKB),
        KC_LALT, LGUI_MEISU, /*        */ SANDS, RGUI_MKANA, KC_RALT),

    /* Layer MAC_HHKB: Mac HHKB mode (HHKB Fn)
      |------+------------+------------+-------------+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      | Pwr  |     F1     |     F2     |     F3      | F4 | F5 | F6 | F7 | F8  | F9  | F10 | F11 | F12   | Ins   | Del |
      |------+------------+------------+-------------+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      | Caps | Wheel Down |  Mouse Up  |  Wheel Up   |    |    |    |    | Psc | Slk | Pus | Up  |       | Backs |     |
      |------+------------+------------+-------------+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      | Mouse Left | Mouse Down | Mouse Right |    |    | *  | /  | Hom | PgU | Lef | Rig | Enter |       |     |
      |------+------------+------------+-------------+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |     VoD    |     VoU    |     Mut     |    |    | +  | -  | End | PgD | Dow |     |       |       |     |
      |-------+------------+------------+-------------+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|

               |----------+-------+----------------------+-------+------+
               | WIN_BASE | ***** | ** Mouse Button 1 ** |  MB2  | **** |
               |----------+-------+----------------------+-------+------+

     */

    [MAC_HHKB] = LAYOUT(
        KC_PWR, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_INS, KC_DEL,
        KC_CAPS, KC_WH_D, KC_MS_U, KC_WH_U, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP, KC_TRNS, KC_BSPC,
        KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, KC_PENT,
        KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS, KC_PPLS, KC_PMNS, KC_END, KC_PGDN, KC_DOWN, KC_TRNS, KC_TRNS,
        DF(WIN_BASE), KC_TRNS, KC_BTN1, KC_BTN2, KC_TRNS),



    /* Layer WIN_BASE : Windows Base Layer
     |---------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Esc     | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | -     | =   | \     | ` |
     |---------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Tab     | Q | W | E | R | T | Y | U | I | O | P | [     | ]   | Backs |   |
     |---------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Control | A | S | D | F | G | H | J | K | L | ; | '     | Ent |       |   |
     |---------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Shift   | Z | X | C | V | B | N | M | , | . | / | Shift | Fn0 |       |   |
     |---------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|

      |------+------------+-----------------------+------------+------|
      | LAlt | LGUI_WEISU | ******* SANDS ******* | RGUI_WKANA | RAlt |
      |------+------------+-----------------------+------------+------|
    */

    [WIN_BASE] = LAYOUT( //  default layer
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_GRV,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, MO(WIN_HHKB),
        KC_LALT, LGUI_WEISU, /*        */ SANDS, RGUI_WKANA, KC_RALT),

    /* Layer WIN_HHKB: Windows HHKB mode (HHKB Fn)
      |------+------------+------------+-------------+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      | Pwr  |     F1     |     F2     |     F3      | F4 | F5 | F6 | F7 | F8  | F9  | F10 | F11 | F12   | Ins   | Del |
      |------+------------+------------+-------------+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      | Caps | Wheel Down |  Mouse Up  |  Wheel Up   |    |    |    |    | Psc | Slk | Pus | Up  |       | Backs |     |
      |------+------------+------------+-------------+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      | Mouse Left | Mouse Down | Mouse Right |    |    | *  | /  | Hom | PgU | Lef | Rig | Enter |       |     |
      |------+------------+------------+-------------+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |     VoD    |     VoU    |     Mut     |    |    | +  | -  | End | PgD | Dow |     |       |       |     |
      |-------+------------+------------+-------------+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|

               |------+-------+----------------------+-------+----------+
               | **** | ***** | ** Mouse Button 1 ** |  MB2  | MAC_BASE |
               |------+-------+----------------------+-------+----------+

     */

    [WIN_HHKB] = LAYOUT(
        KC_PWR, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_INS, KC_DEL,
        KC_CAPS, KC_WH_D, KC_MS_U, KC_WH_U, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP, KC_TRNS, KC_BSPC,
        KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, KC_PENT,
        KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS, KC_PPLS, KC_PMNS, KC_END, KC_PGDN, KC_DOWN, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2, DF(MAC_BASE))};

inline void disable_ime(void) {
    if (layer_state_is(MAC_BASE) || layer_state_is(MAC_HHKB)) {
        // mac
        dprint("disable_ime: mac");
        tap_code(JP_MEISU);
    } else if (layer_state_is(WIN_BASE) || layer_state_is(WIN_HHKB)) {
        // win
        dprint("disable_ime: win");
        tap_code(JP_WEISU);
    }
}

inline bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_ESC:
            if (record->event.pressed && get_mods() == 0) {
                disable_ime();
            }
            return true;
        case KC_LBRC:
            // CTRL-[ to ESC
            if ((get_mods() & MOD_LCTRL) != 0 && record->event.pressed) {
                unregister_mods(MOD_LCTRL);
                tap_code(KC_ESC);
                disable_ime();

                return false;
            }

            return true;
    }

    return true;
}

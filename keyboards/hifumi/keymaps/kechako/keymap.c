/* Copyright 2019 zk-phi
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layers {
    DEFAULT,
    DELVE,
    XCODE,
    VSCODE,
    SPACE,
    LAYERS,
    ARROWS,
};

enum custom_keycodes {
  DLV_CONT = SAFE_RANGE,
  DLV_NEXT,
  DLV_STPI,
  DLV_STPO,
};

#define XCD_BREK LGUI(KC_BSLS)
#define XCD_CONT LGUI(LCTL(KC_Y))
#define XCD_NEXT KC_F6
#define XCD_STPI KC_F7
#define XCD_STPO KC_F8

#define VSC_BREK KC_F9
#define VSC_CONT KC_F5
#define VSC_NEXT KC_F10
#define VSC_STPI KC_F11
#define VSC_STPO S(KC_F11)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEFAULT] = LAYOUT(
        KC_NO,   KC_UP,   MO(LAYERS),
        KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    [DELVE] = LAYOUT(
        KC_NO,    DLV_CONT, MO(ARROWS),
        DLV_NEXT, DLV_STPI, DLV_STPO
    ),
    [XCODE] = LAYOUT(
        XCD_BREK, XCD_CONT, MO(ARROWS),
        XCD_NEXT, XCD_STPI, XCD_STPO
    ),
    [VSCODE] = LAYOUT(
        VSC_BREK, VSC_CONT, MO(ARROWS),
        VSC_NEXT, VSC_STPI, VSC_STPO
    ),
    [SPACE] = LAYOUT(
        KC_SPC, KC_SPC, MO(ARROWS),
        KC_SPC, KC_SPC, KC_SPC
    ),
    [LAYERS] = LAYOUT(
        DF(SPACE), KC_NO,     KC_TRNS,
        DF(DELVE), DF(XCODE), DF(VSCODE)
    ),
    [ARROWS] = LAYOUT(
        DF(DEFAULT), KC_UP,   KC_TRNS,
        KC_LEFT,     KC_DOWN, KC_RIGHT
    )
};

inline bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DLV_CONT:
            if (record->event.pressed) {
                SEND_STRING("c\n");
            }
            return true;
        case DLV_NEXT:
            if (record->event.pressed) {
                SEND_STRING("n\n");
            }
            return true;
        case DLV_STPI:
            if (record->event.pressed) {
                SEND_STRING("s\n");
            }
            return true;
        case DLV_STPO:
            if (record->event.pressed) {
                SEND_STRING("so\n");
            }
            return true;
    }

    return true;
}

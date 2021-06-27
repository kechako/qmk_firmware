#include "kechako.h"

inline void send_disable_ime(int mode) {
    uint8_t temp_mods = get_mods();
    clear_mods();
    clear_oneshot_mods();

    switch (mode) {
        // mac
        case 0:
            tap_code(JP_MEISU);
            break;
        // windows
        case 1:
            tap_code(JP_WEISU);
        // linux
        case 2:
            tap_code(JP_WEISU);
            break;
    }

    set_mods(temp_mods);
}

inline void replace_keycode(uint8_t mods, uint16_t keycode, bool pressed) {
    uint8_t temp_mods = get_mods();
    clear_mods();
    clear_oneshot_mods();

    if (pressed) {
        register_code16(keycode);
    } else {
        unregister_code16(keycode);
    }

    set_mods(temp_mods);
}
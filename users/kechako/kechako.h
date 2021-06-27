#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

// EISU and KANA key for macOS
#define JP_MKANA KC_LANG1
#define JP_MEISU KC_LANG2
// EISU and KANA key for Windows
#define JP_WKANA KC_F17
#define JP_WEISU KC_F18

// Keycode macros
#define SANDS    MT(MOD_LSFT, KC_SPC)  // SandS (Space and Shift)

// Modifires macro
#define MOD_LCTRL MOD_BIT(KC_LCTL)


//enum custom_keycodes {
//};

// Send keycode to disable IME
// 
// mode  0: mac, 1: win, 2: linux
void send_disable_ime(int mode);

void replace_keycode(uint8_t mods, uint16_t keycode, bool pressed);

#endif
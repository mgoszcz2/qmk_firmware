/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
#include "keymap_colemak.h"
#include "sendstring_colemak.h"

// Hold Left Command and Left Ctrl and press kc.
#define CCMD(_kc) LCTL(LCMD(_kc))

// Needed since LT() does not support quantum keycodes.
#define KC_OSM_LSFT KC_FN31

#define LT_NAV_SPC LT(_NAV, KC_SPC)
#define LT_FN_BSPC LT(_FN, KC_BSPC)
#define LT_SYM_ENT LT(_SYM, KC_ENT)
#define LT_NUM_OSS LT(_NUM, KC_OSM_LSFT)

enum layers {
    _COLEMAK,
    _NUM,
    _NAV,
    _SYM,
    _FN,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Colemak
 *
 * Note we use LALT on the right half.
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   Q  |   W  |   F  |   P  |   G  |                              |   J  |   L  |   U  |   Y  | ;  : |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   A  |   R  |  S   |   T  |   D  |                              |   H  |   N  |   E  |   I  |   O  |  ' "   |
 * |        | Ctrl | Alt  | Shift| Cmd  | Meh  |                              | Meh  | Cmd  | Shift| Alt  | Ctrl |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |Screen| Lock |  | Emoji| Play |   K  |   M  | ,  < | . >  | /  ? |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      | Esc  | Space| Bscp |  | Enter| Shift| Tab  |      |      |
 *                        |      |      |      | Nav  | Fn   |  | Sym  | Num  |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_COLEMAK] = LAYOUT(
      XXXXXXX, CM_Q,         CM_W,         CM_F,         CM_P,         CM_G,                                                          CM_J,        CM_L,         CM_U,         CM_Y,         CM_SCLN,      XXXXXXX,
      XXXXXXX, LCTL_T(CM_A), LALT_T(CM_R), LSFT_T(CM_S), LCMD_T(CM_T), MEH_T(CM_D),                                                   MEH_T(CM_H), RCMD_T(CM_N), RSFT_T(CM_E), LALT_T(CM_I), RCTL_T(CM_O), CM_QUOT,
      XXXXXXX, CM_Z,         CM_X,         CM_C,         CM_V,         CM_B,        SCMD(CM_3), CCMD(CM_Q),  CCMD(KC_SPC), KC_MPLY,   CM_K,        CM_M,         CM_COMM,      CM_DOT,       CM_SLSH,      XXXXXXX,
                                           XXXXXXX,      XXXXXXX,      KC_ESC,      LT_NAV_SPC,  LT_FN_BSPC, LT_SYM_ENT,  LT_NUM_OSS, KC_TAB,      XXXXXXX,      XXXXXXX
    ),
/*
 * Num Layer: Number and number-related symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  `   |  7   |  8   |  9   |  *   |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  %   |  4   |  5   |  6   |  _   |                              | Meh  | Cmd  | Shift| Alt  | Ctrl |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  \   |  1   |  2   |  3   |  +   |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |  0   |  '   |  |      | XXXX |      |      |      |
 *                        |      |      |      |      |      |  |      | XXXX |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NUM] = LAYOUT(
      _______, CM_GRV,  CM_7, CM_8, CM_9, CM_ASTR,                                     _______, _______, _______, _______, _______, _______,
      _______, CM_PERC, CM_4, CM_5, CM_6, CM_UNDS,                                     KC_MEH,  KC_RCMD, KC_RSFT, KC_LALT, KC_RCTL, _______,
      _______, CM_BSLS, CM_1, CM_2, CM_3, CM_PLUS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                        _______, _______, _______, CM_0,    CM_QUOT, _______, _______, _______, _______, _______
    ),
/*
 * Sym Layer: Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  ^   |  $   |  [   |  ]   |  |   |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  !   |  =   |  (   |  )   |  ~   |                              | Meh  | Cmd  | Shift| Alt  | Ctrl |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  &   |  @   |  {   |  }   |  #   |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |  -   |  "   |  | XXXX |      |      |      |      |
 *                        |      |      |      |      |      |  | XXXX |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT(
      _______, CM_CIRC, CM_DLR, CM_LBRC, CM_RBRC, CM_PIPE,                                     _______, _______, _______, _______, _______, _______,
      _______, CM_EXLM, CM_EQL, CM_LPRN, CM_RPRN, CM_TILD,                                     KC_MEH,  KC_RCMD, KC_RSFT, KC_LALT, KC_RCTL, _______,
      _______, CM_AMPR, CM_AT,  CM_LCBR, CM_RCBR, CM_HASH, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                _______, _______, _______, CM_MINS, CM_DQUO, _______, _______, _______, _______, _______
    ),
/*
 * Nav Layer: Navigation and media
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              | Mute |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | Ctrl | Alt  | Shift| Cmd  | Meh  |                              | VolUp| Left | Down | Up   | Right|        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      | VolDn| Prev | Play | Next |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      | XXXX |      |  |      |      |      |      |      |
 *                        |      |      |      | XXXX |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     KC_MUTE, _______, _______, _______, _______, _______,
      _______, KC_LCTL, KC_LALT, KC_LSFT, KC_LCMD, KC_MEH,                                      KC_VOLU, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Fn Layer: Function keys, RGB
 *
 * Note we assume 'natural scrolling' here.
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | F1   |  F2  | F3   | F4   | F5   |                              |      |      |Bottom| Top  |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | TOG  | SAI  | HUI  | VAI  | MOD  |                              |      | MLeft| MDown| MUp  |MRight|        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      | SAD  | HUD  | VAD  | RMOD |      |      |  |      |      |      |WRight| WUp  | WDown| WLeft|        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      | XXXX |  |RClick|LClick|MClick|      |      |
 *                        |      |      |      |      | XXXX |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FN] = LAYOUT(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       _______, _______, LCMD(KC_DOWN), LCMD(KC_UP), _______, _______,
      _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                     _______, KC_MS_L, KC_MS_D,       KC_MS_U,     KC_MS_R, _______,
      _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,_______, _______, _______, _______, _______, KC_WH_R, KC_WH_U,       KC_WH_D,     KC_WH_L, _______,
                                 _______, _______, _______, _______, _______, KC_BTN2, KC_BTN1, KC_BTN3, _______, _______
    ),
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYER] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    const bool pressed = record->event.pressed;
    const uint8_t taps = record->tap.count;
    switch (keycode) {
        case LT_NUM_OSS:
            if (pressed && taps > 0) {
                if (get_oneshot_mods() & MOD_LSFT) {
                    del_oneshot_mods(MOD_LSFT);
                } else {
                    add_oneshot_mods(MOD_LSFT);
                }
                return false;
            }
            break;
    }
    return true;
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT_NAV_SPC:
        case LT_FN_BSPC:
        case LT_SYM_ENT:
        case LT_NUM_OSS:
            // Repeat thumb keys.
            return false;
        default:
            // Do not repeat home mods.
            return true;
    }
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK:
            oled_write_P(PSTR("Colemak\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Nav\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Num\n"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("Sym\n"), false);
            break;
        case _FN:
            oled_write_P(PSTR("Fn\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_kyria_logo();
    }
}
#endif

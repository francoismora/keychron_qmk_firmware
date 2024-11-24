/* Copyright 2024 @ Keychron (https://www.keychron.com)
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
#include "keychron_common.h"

enum layers{
        WIN_BASE,
        WIN_FN1,
        FN2,
        PCN_L,
        PCN_R,
        DIGIT,
        CNTRL
};

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCL RGUI_T(KC_SCLN)

// Space upper level
#define SPC_L LT(PCN_R, KC_SPC)
#define SPC_R LT(PCN_L, KC_SPC)
#define FN_L  LT(CNTRL, KC_TAB)
#define FN_R  LT(DIGIT, KC_ENT)
#define UNDO  LCTL(KC_Z)
#define CUT   LCTL(KC_X)
#define COPY  LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define ALT_ESC LALT_T(KC_ESC)
#define ALT_DEL LALT_T(KC_DEL)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [WIN_BASE] = LAYOUT_69_ansi(
        KC_ESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
        KC_CAPS, HOME_A,   HOME_S,   HOME_D,  HOME_F,  KC_G,    KC_H,     HOME_J,  HOME_K,  HOME_L,  HOME_SCL, KC_QUOT,  KC_ENT,                     KC_HOME,
        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,     KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, KC_UP,
        KC_LCTL, KC_LWIN,  ALT_ESC,           SPC_L,            FN_L,     FN_R,    SPC_R,            ALT_DEL,            KC_LEFT, KC_DOWN, KC_RGHT),

    [WIN_FN1] = LAYOUT_69_ansi(
        KC_GRV,  KC_BRID,  KC_BRIU,  KC_TASK, KC_FILE, RGB_VAD, RGB_VAI,  KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,          RGB_TOG,
        _______, BT_HST1,  BT_HST2,  BT_HST3, P2P4G,   _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          KC_INS,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI,           _______, _______, _______, _______,  _______,  _______,  _______,          KC_END,
        _______,           RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD,  _______, NK_TOGG, _______, _______,  _______,  _______,  _______, KC_PGUP,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, KC_PGDN, _______),

    [FN2] = LAYOUT_69_ansi(
        KC_TILD, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,          _______,
        _______, _______,  _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, _______,  _______,  _______, _______, _______,           _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______,           _______,  _______, _______, _______, BAT_LVL,  BAT_LVL, _______, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______),

    [PCN_L] = LAYOUT_69_ansi(
        _______, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,    _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, KC_PLUS,  KC_AMPR,  KC_ASTR, KC_UNDS, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, KC_EQUAL, KC_DLR,   KC_PERC, KC_CIRC, _______,           _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______,           KC_MINUS, KC_EXLM, KC_AT,   KC_HASH, _______,  _______, _______, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______),

    [PCN_R] = LAYOUT_69_ansi(
        _______, _______,  _______,  _______, _______, _______, _______,  KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,          _______,
        _______, _______,  _______,  _______, _______, _______, _______,  KC_LCBR, KC_RCBR, KC_DQT,  KC_PIPE,  _______,  _______,  _______,          _______,
        _______, _______,  _______,  _______, _______, _______,           _______, KC_LPRN, KC_RPRN, KC_QUOTE, KC_BSLS,  _______,  _______,          _______,
        _______,           UNDO,     CUT,     COPY,    PASTE,   KC_ENT,   _______, _______, KC_LBRC, KC_RBRC,  KC_GRV,   KC_TILD,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______),

    [DIGIT] = LAYOUT_69_ansi(
        _______, _______,  _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, _______,  KC_7,     KC_8,    KC_9,    _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, _______,  KC_4,     KC_5,    KC_6,    _______,           _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______,           _______,  KC_1,    KC_2,    KC_3,    _______,  _______, _______, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           KC_0,             _______,  _______,          _______,           _______,            _______, _______, _______),


    [CNTRL] = LAYOUT_69_ansi(
        _______, _______,  _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, BT_HST1,  BT_HST2,  BT_HST3, P2P4G,   _______, _______,  KC_BSPC, KC_DEL,  KC_ENT,  KC_INS,   _______,  _______,  _______,          _______,
        _______, _______,  _______,  _______, _______, _______,           _______, KC_LEFT, KC_DOWN, KC_UP,    KC_RGHT,	 _______,  _______,          _______,
        _______,           _______,  _______, _______, _______, _______,  _______, _______, KC_HOME, KC_PGDN,  KC_PGUP,  KC_END,   _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______)

};

#if defined(ENCODER_MAP_ENABLE)
        const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
                [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
                [WIN_FN1]  = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
                [FN2]      = {ENCODER_CCW_CW(_______, _______)},
                [PCN_L]    = {ENCODER_CCW_CW(_______, _______)},
                [PCN_R]    = {ENCODER_CCW_CW(_______, _______)},
                [DIGIT]    = {ENCODER_CCW_CW(_______, _______)},
                [CNTRL]    = {ENCODER_CCW_CW(_______, _______)},
        };
#endif // ENCODER_MAP_ENABLE

// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
    return true;
}

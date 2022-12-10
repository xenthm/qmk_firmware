/* Copyright 2021 wuquestudio
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT_all(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC,    KC_INS, KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,             KC_DEL, KC_PGDN,
        LT(2, KC_CAPS),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RSFT,             KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,          KC_SPC,           KC_SPC,           KC_SPC,           MO(2) ,  MO(3)  , KC_RCTL,             KC_LEFT, KC_DOWN, KC_RGHT
    ),
    LAYOUT_all(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______,
        _______, KC_NO  , _______,          _______,          _______,          _______,          _______, _______, _______,             _______, _______, _______
    ),
	LAYOUT_all(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,    _______, KC_HOME,
        _______, KC_HOME, KC_UP  , KC_END , _______, _______, _______, KC_HOME, KC_UP  , KC_END , KC_PGUP, KC_PGDN, KC_SLCK, KC_PSCR,             _______, KC_END ,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS , KC_PAUS,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,             _______,
        _______, _______, _______,          _______,          _______,          _______,          _______, _______, _______,             _______, _______, _______
    ),
    LAYOUT_all(
        MAGIC_TOGGLE_NKRO, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______,
        _______, RGB_TOG,RGB_RMOD, RGB_MOD, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET  ,             _______, _______,
        _______, RGB_SPD, RGB_SPI, RGB_HUD, RGB_HUI, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, RGB_VAD, RGB_VAI, RGB_SAD, RGB_SAI, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______,             _______,
        _______, TG(1)  , _______,          _______,          _______,          _______,          _______, _______, _______,             _______, _______, _______
    ),
};

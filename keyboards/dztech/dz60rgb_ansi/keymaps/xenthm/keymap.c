#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_60_ansi(
        KC_ESC,        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        LT(2,KC_CAPS), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,                 KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
        KC_LCTL,        KC_LGUI, KC_LALT,                            KC_SPC,                             MO(2), MO(3), KC_RALT,   KC_RCTL
    ),
    [1] = LAYOUT_60_ansi(
        _______, _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,  _______,  _______,  _______,
        _______, _______, _______,   _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,          _______,
        _______, KC_NO  , _______,                            _______,                            _______, _______, _______, _______
    ),
    [2] = LAYOUT_60_ansi(
        KC_GRV , KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, KC_HOME, KC_UP  , KC_END , _______, _______, _______, KC_HOME, KC_UP  , KC_END , KC_PGUP, KC_PGDN, KC_SCRL, KC_PSCR,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS , KC_PAUS,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT,          _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______
    ),
	[3] = LAYOUT_60_ansi(
        _______, RGB_M_P,   RGB_M_B,   RGB_M_R,  RGB_M_SW,  RGB_M_SN,   RGB_M_K,   RGB_M_X,   RGB_M_G,   _______,   _______,  _______,  _______,  _______,
        _______, RGB_TOG, RGB_RMOD,   RGB_MOD, _______, _______, _______, _______, _______,  _______, _______, _______, _______, QK_BOOT,
        _______, RGB_SPD, RGB_SPI, RGB_HUD, RGB_HUI, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          RGB_VAD, RGB_VAI, RGB_SAD, RGB_SAI, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE,          _______,
        _______, TG(1)  , _______,                            _______,                            _______, _______, _______, _______
    )
};

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (layer_state_is(1)) {
        RGB_MATRIX_INDICATOR_SET_COLOR(59, 255, 0, 0); // WIN key turns red when winlock active
    }
	
	if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(60, 0xFF, 0xFF, 0xFF);
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_TOG:
            // When toggling matrix, keep it on but disable the LEDs through flags.
            // This allows to keep using some of them as indicators.
            if (record->event.pressed) {
                if (rgb_matrix_is_enabled()) {
                    switch (rgb_matrix_get_flags()) {
                        case LED_FLAG_NONE:
                            rgb_matrix_set_flags(LED_FLAG_ALL);
                            rgb_matrix_disable_noeeprom();
                            break;
                        case LED_FLAG_ALL:
                            rgb_matrix_set_flags(LED_FLAG_NONE);
                            rgb_matrix_disable_noeeprom();
                            break;
                    }
                }
            }
            break;
        case RGB_MOD:
        case RGB_RMOD:
        case RGB_HUI:
        case RGB_HUD:
        case RGB_SAI:
        case RGB_SAD:
        case RGB_VAI:
        case RGB_VAD:
        case RGB_SPI:
        case RGB_SPD:
            // Ignore RGB setting keys if RGB is off (this is needed as RGB is never truly off,
            // just disabled through flags)
            if (record->event.pressed) {
                if (rgb_matrix_get_flags() != LED_FLAG_ALL) {
                    return false;
                }
            }
            break;
    }

    return true;
}

/**
 * Called after RBG effect render.
 */
bool rgb_matrix_indicators_kb(void) {
    if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
        rgb_matrix_set_color_all(0x0, 0x0, 0x0);
    }
	return false;
}

#endif // RGB_MATRIX_ENABLE
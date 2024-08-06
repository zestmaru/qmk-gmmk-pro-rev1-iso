/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>
   Copyright 2022 subhead @subhead
   Copyright 2024 zestmaru

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "rgb_matrix_map.h"

#ifdef RGB_MATRIX_ENABLE
static uint8_t l_base_functions[] = {LED_F1, LED_F2, LED_F3, LED_F4, LED_F5, LED_F6, LED_F7, LED_F8, LED_F9, LED_F10, LED_F11, LED_1, LED_W, LED_S, LED_X, LED_N, LED_K, 94, 80, 98, 96}; //94, 80, 98, 96 - arrows
static uint8_t l_game_mode[] = {LED_W, LED_A, LED_S, LED_D, LED_R, LED_FN, LED_1, LED_2, LED_3, LED_4, LED_5, LED_Q, LED_Z, LED_X, LED_C, LED_LCTL, LED_LSFT, LED_LALT, LED_G, LED_E, LED_B, LED_SPC, LED_TAB, LED_CAPS, 94, 80, 98, 96};
#define SIZE_OF_BASE_FUNCTIONS (sizeof(l_base_functions) / sizeof(l_base_functions[0]))
#define SIZE_OF_GAME_MODE (sizeof(l_game_mode) / sizeof(l_game_mode[0]))
#endif

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt                        Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc                    Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]                                   PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "        #        Enter                      PgDn
//      Sh_L     /        Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up                Home
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the QK_BOOT key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backspace. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,                           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,                           KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,                                    KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,                            KC_PGDN,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,        KC_UP,             KC_HOME,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_RCTL,        KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT(
        _______, KC_MYCM, KC_WHOM, KC_CALC, KC_MSEL, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,                           _______,
        _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                           _______,
        _______, _______, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                                    _______,
        _______, _______, RGB_VAD, _______, _______, _______, _______, _______, KX_CATG, _______, _______, _______, _______, _______,                           _______,
        _______, _______, _______, RGB_HUI, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______,        RGB_MOD,           _______,
        _______, _______, _______,                            _______,                            _______, _______, _______,        RGB_SPD, RGB_RMOD, RGB_SPI
    ),


};
// clang-format on

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {[0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}, [1] = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS)}};
#endif

#ifdef RGB_MATRIX_ENABLE
bool is_in_list(uint8_t value, const uint8_t *list, size_t list_size) {
    for (size_t i = 0; i < list_size; i++) {
        if (list[i] == value) {
            return true;
        }
    }
    return false;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    static uint32_t cycle_led_timer    = 0;
    static uint8_t  current_value      = 0;
    if (timer_elapsed32(cycle_led_timer) > 500) {
        current_value   = current_value == 0 ? 255 : 0;
        cycle_led_timer = timer_read32();
    }
    HSV tempHSV = {.h = 0, .s = 255, .v = current_value};
    RGB tempRGB = hsv_to_rgb(tempHSV);

    static uint8_t  left_side_leds[8]  = {68, 71, 74, 77, 81, 84, 88, 92};
    static uint8_t  right_side_leds[8] = {69, 72, 75, 78, 82, 85, 89, 93};

    if (host_keyboard_led_state().caps_lock) {
        // flash side panels
        for (uint8_t i = 0; i < sizeof(left_side_leds) / sizeof(left_side_leds[0]); i++) {
            rgb_matrix_set_color(left_side_leds[i], tempRGB.r, tempRGB.g, tempRGB.b);
            rgb_matrix_set_color(right_side_leds[i], tempRGB.r, tempRGB.g, tempRGB.b);
        }

        // flash all keys
        for (uint8_t i = led_min; i < led_max; i++) {
            rgb_matrix_set_color(i, tempRGB.r, tempRGB.g, tempRGB.b);
        }

        return false;
    }

    // kinda game mode. 
    for (uint8_t i = led_min; i < led_max; i++) {
        if (key_cancellation_is_enabled()) {
            if (is_in_list(i, l_game_mode, SIZE_OF_GAME_MODE)) {
                RGB_MATRIX_INDICATOR_SET_COLOR(i, 255, 0, 0); // only game mode keys
            } else {
                RGB_MATRIX_INDICATOR_SET_COLOR(i, 0, 0, 0); // do not light others keys
            }
        }
    }

    // fn keys
    switch (get_highest_layer(layer_state)) {
        case 1:
            for (uint8_t i = led_min; i < led_max; i++) {
                if (is_in_list(i, l_base_functions, SIZE_OF_BASE_FUNCTIONS)) {
                    RGB_MATRIX_INDICATOR_SET_COLOR(i, tempRGB.r, tempRGB.g, tempRGB.b); // only fn keys
                } else {
                    RGB_MATRIX_INDICATOR_SET_COLOR(i, 0, 0, 0); // do not light others keys
                }
            }
            break;
        default:
            break;
    }
    return false;
}
#endif // RGB_MATRIX_ENALBED

#if defined(KEY_CANCELLATION_ENABLE)
const key_cancellation_t PROGMEM key_cancellation_list[] = {
    // on key down
    //       |    key to be released
    //       |     |
    [0] = {KC_D, KC_A},
    [1] = {KC_A, KC_D},
    [2] = {KC_W, KC_S},
    [3] = {KC_S, KC_W},
};
#endif //KEY_CANCELLATION_ENABLE
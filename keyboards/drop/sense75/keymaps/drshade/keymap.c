// Copyright 2022 Massdrop, Inc.
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum my_keycodes {
    _MOD_UP = SAFE_RANGE,
    _MOD_DN,
    _SPD_UP,
    _SPD_DN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
     * ┌───┐┌───┬───┬───┬───┐┌───┬───┬───┬───┐┌───┬───┬───┬───┐┌───┐┌───┐
     * │Esc││F1 │F2 │F3 │F4 ││F5 │F6 │F7 │F8 ││F9 │F10│F11│F12││PSc││   │
     * └───┘└───┴───┴───┴───┘└───┴───┴───┴───┴└───┴───┴───┴───┘└───┘└───┘
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐┌───┐
     * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp││Del│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤├───┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  ││PgU│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤├───┤
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter ││PgD│
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┘└───┘
     * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ Shift│┌───┐
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┘│ ↑ │
     * │Ctrl│GUI │Alt │                        │Alt│GUI│Ctl│┌───┼───┼───┐
     * └────┴────┴────┴────────────────────────┴───┴───┴───┘│ ← │ ↓ │ → │
     *                                                      └───┴───┴───┘
     */
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  DM_PLY1,          _______,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        MO(2),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,          _______,
        _______, RGB_TOG, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, _______, _______, _______, _______, _______, _______, _______, _______,          KC_HOME,
        _______, RGB_MOD, RGB_VAD, RGB_SPD, RGB_HUD, RGB_SAD, _______, _______, _______, _______, _______, _______,          _______,          KC_END,
        _______,          RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,_______, NK_TOGG, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,                            EE_CLR,                             _______, _______, _______, _______, _______, _______
    ),
    [2] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, DM_REC1,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _SPD_UP,
        _______, LAG_NRM, LAG_SWP,                            _______,                            _______, _______, _______, _MOD_DN, _SPD_DN, _MOD_UP
    ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D) },
    [1] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [2] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT)},
};
#endif

void rgb_matrix_indicators_user(void) {
    if (get_highest_layer(layer_state) == 2) {
        // rgb_matrix_set_color_all(RGB_OFF);

        if (keymap_config.swap_lalt_lgui) {
            rgb_matrix_set_color(94, RGB_RED);
        } else {
            rgb_matrix_set_color(93, RGB_RED);
        }

        // To remind MACRO mode is available
        //
        rgb_matrix_set_color(26, RGB_RED);

        // To remind RGB modes are available at F keys
        if (get_highest_layer(layer_state) == 2) {
            rgb_matrix_set_color(rgb_matrix_get_mode() + 14, RGB_GREEN);
            // rgb_matrix_set_color(14, RGB_RED);
            // rgb_matrix_set_color(15, RGB_RED);
            // rgb_matrix_set_color(16, RGB_RED);
            // rgb_matrix_set_color(17, RGB_RED);
            
            // rgb_matrix_set_color(18, RGB_BLUE);
            // rgb_matrix_set_color(19, RGB_BLUE);
            // rgb_matrix_set_color(20, RGB_GREEN);
            // rgb_matrix_set_color(21, RGB_GREEN);
            // rgb_matrix_set_color(22, RGB_RED);
            // rgb_matrix_set_color(23, RGB_RED);
        }


    }


    // 14 = f1
    // 26 = print
    // 85 = ","
    // 95 = "space"
    if (get_highest_layer(layer_state) == 2) {
        // rgb_matrix_set_color(25, RGB_RED);
        // rgb_matrix_set_color(26, RGB_GREEN);
        // rgb_matrix_set_color(27, RGB_BLUE);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        switch (keycode) {
            case _MOD_UP:
                rgb_matrix_step();
                return false; // Don't process the key further
            case _MOD_DN:
                rgb_matrix_step_reverse();
                return false; // Don't process the key further
            case _SPD_UP:
                rgb_matrix_increase_speed();
                return false;
            case _SPD_DN:
                rgb_matrix_decrease_speed();
                return false;
        }
    }
    return true;
};

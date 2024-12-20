/* Copyright 2022 Jose Pablo Ramirez <jp.ramangulo@gmail.com>
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

enum custom_keycodes {
    TG_FEAT_1 = SAFE_RANGE, // SAFE_RANGE ensures no overlap with QMK default keycodes
    TG_FEAT_2
};

static bool keyboard_feature_enabled = false;
static uint32_t keyboard_feature_delay = 60000;

static bool mouse_feature_enabled = false;
static uint32_t mouse_feature_delay = 60000;
static int mouse_direction = 0;
static int mouse_amplitude = 0;

static uint32_t keyboard_last_timer = 0;
static uint32_t mouse_last_timer = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
                                    LT(1,_______),
      TG_FEAT_1,    _______,        _______,
      TG_FEAT_2,    _______,        _______,
      _______,      _______,        _______,
      _______,      _______,        _______
  ),
  [1] = LAYOUT(
                        _______,
      _______, _______, _______,
      _______, _______, _______,
      _______, _______, _______,
      _______, _______, _______
  ),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(_______, _______) },
  [1] = { ENCODER_CCW_CW(_______, _______) },
};
#endif

void keyboard_post_init_user(void) {
    // Disable matrix effects
    //
    rgb_matrix_mode(RGB_MATRIX_NONE);
}

bool rgb_matrix_indicators_user(void) {
    // Clear all LEDs
    //
    rgb_matrix_set_color_all(0, 0, 0);

    if (keyboard_feature_enabled) {
        rgb_matrix_set_color(0, 255, 0, 0);
    } else {
        rgb_matrix_set_color(0, 0, 0, 0);
    }

    if (mouse_feature_enabled) {
        rgb_matrix_set_color(3, 255, 0, 0);
    } else {
        rgb_matrix_set_color(3, 0, 0, 0);
    }

    return true;
}

bool oled_task_user(void) {
    oled_set_cursor(0, 1);
    oled_write_P(PSTR("Jigglypuff!"), false);
    
    oled_set_cursor(0, 2);
    if (keyboard_feature_enabled) {
        oled_write_P(PSTR("KEYBOARD: on "), false);
    } else {
        oled_write_P(PSTR("KEYBOARD: off"), false);
    }

    oled_set_cursor(0, 3);
    if (mouse_feature_enabled) {
        oled_write_P(PSTR("MOUSE: on "), false);
    } else {
        oled_write_P(PSTR("MOUSE: off"), false);
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TG_FEAT_1:
            if (record->event.pressed) {
                keyboard_feature_enabled = !keyboard_feature_enabled;
            }
            return false;
        case TG_FEAT_2:
            if (record->event.pressed) {
                mouse_feature_enabled = !mouse_feature_enabled;
            }
            return false;
    }
    return true;
}

void move_mouse(uint32_t direction) {
    mousekey_on(direction);
    mousekey_send();
    mousekey_off(direction);
}

void matrix_scan_user(void) {
    if (keyboard_feature_enabled) {
        if (timer_elapsed(keyboard_last_timer) > keyboard_feature_delay) {
            // Send Shift key
            tap_code(KC_LSFT);

            // Reset the timer
            keyboard_last_timer = timer_read();
        }
    }

    if (mouse_feature_enabled) {
        if (timer_elapsed(mouse_last_timer) > mouse_feature_delay) {
            switch (mouse_direction) {
                case 0:
                    move_mouse(KC_MS_RIGHT);
                    break;
                case 1:
                    move_mouse(KC_MS_DOWN);
                    break;
                case 2:
                    move_mouse(KC_MS_LEFT);
                    break;
                case 3:
                    move_mouse(KC_MS_UP);
                    break;
            }

            mouse_direction = (mouse_direction + 1) % 4;
            mouse_amplitude = (mouse_amplitude + 10) % 200;

            // Reset the timer
            mouse_last_timer = timer_read();
        }
    }
}


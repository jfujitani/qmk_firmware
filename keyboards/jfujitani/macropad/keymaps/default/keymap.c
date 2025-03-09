/* Copyright 2025 revere521
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
//#include "stdio.h"
//#include "stdbool.h"
//#include "stdint.h"

#define _BASE     0
#define _SUB      1
#define _SUB2     2

// Layer Maps - change your key bindings here
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP,
    KC_NUM, KC_PSLS, KC_PAST, KC_PMNS, KC_MUTE,
    KC_P7, KC_P8, KC_P9,
    KC_P4, KC_P5, KC_P6, KC_PPLS,
    KC_P1, KC_P2, KC_P3,
    KC_P0, KC_PDOT, KC_PENT, TT(1), TT(2)
  ),
  [_SUB] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, QK_RBT, KC_TRNS, KC_TRNS
  ),
  [_SUB2] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, QK_RBT, KC_TRNS, KC_TRNS
  ),
};

void keyboard_post_init_user() {
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

// OLED Screen Settings

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_180;
}

bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
  oled_write_P(PSTR("Layer:"), false);
  switch (get_highest_layer(layer_state)) {
    case _BASE:
      oled_write_ln_P(PSTR(" Numberpad"), false);
      break;
    case _SUB:
      oled_write_ln_P(PSTR(" Function"), false);
      break;
    case _SUB2:
      oled_write_ln_P(PSTR(" Alternate"), false);
      break;
    default:
      oled_write_ln_P(PSTR(" UNDEFINED"), false);
  }

  led_t led_state = host_keyboard_led_state();
  oled_write_P(PSTR("--------------------\n"), false);
  oled_write_P(PSTR("Lock Key:"), false);
  oled_write_P(led_state.num_lock ? PSTR(" NUM") : PSTR("    "), false);
  oled_write_P(led_state.caps_lock ? PSTR(" CAP") : PSTR("    "), false);
  oled_write_P(led_state.scroll_lock ? PSTR(" SCR") : PSTR("    "), false);
  oled_write_P(PSTR("--------------------\n"), false);

  oled_write_P(PSTR("Underglow Setting:\n"), false);
  static char led_buf[30];
  snprintf(led_buf, sizeof(led_buf) - 1, "Mod:%2d Hue:%2d\nSat:%2d Val:%2d",
      (uint8_t)rgblight_get_mode(),
      (uint8_t)(rgblight_get_hue() / RGBLIGHT_HUE_STEP),
      (uint8_t)(rgblight_get_sat() / RGBLIGHT_SAT_STEP),
      (uint8_t)(rgblight_get_val() / RGBLIGHT_VAL_STEP));
  oled_write(led_buf, false);

  return false;
}
#endif

// Rotary Encoder Configurations


bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {
    switch (biton32(layer_state)) {
      case _BASE:
      case _SUB:
      case _SUB2:
      default:
        if (clockwise) {
          tap_code(KC_VOLU);
        } else {
          tap_code(KC_VOLD);
        }
        break;
    }
  }
  return true;
}


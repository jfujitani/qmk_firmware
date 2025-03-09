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

#pragma once

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
*/

//#define MATRIX_ROWS 6
//#define MATRIX_COLS 6
//#define MATRIX_ROW_PINS { B4, B5, F4, F5, F6, F7 }
//#define MATRIX_COL_PINS { D3, D2, D4, C6, D7, E6 }

/* COL2ROW, ROW2COL*/
//#define DIODE_DIRECTION COL2ROW

/* Rotary encoder */
#define ENCODER_A_PINS { B1 }
#define ENCODER_B_PINS { B3 }


/* Bootmagic - hold down rotary encoder pushbutton while plugging in to enter bootloader */
#define BOOTMAGIC_LITE_ROW 4
#define BOOTMAGIC_LITE_COLUMN 1

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* My OLED Config */
#define OLED_IC OLED_IC_SH1106
#define OLED_COLUMN_OFFSET 2
#define OLED_DISPLAY_128X64
#define OLED_BRIGHTNESS 128

/* My RGB Config */
#define WS2812_DI_PIN B6
#ifdef WS2812_DI_PIN
  #define RGBLED_NUM 5 // CHANGE THIS TO THE NUMBER OF LEDS YOU WANT TO USE
  #define RGBLIGHT_LED_COUNT RGBLED_NUM // This alias is essential
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
  #define RGBLIGHT_LIMIT_VAL 255 /* The maximum brightness level */
  #define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
//  #define RGBLIGHT_ANIMATIONS // Enable all animation modes - this appears to be defunct now
  #define RGBLIGHT_BREATHE_TABLE_SIZE 256 // 256(default) or 128 or 64

#endif


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

#pragma once

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
#endif

#ifdef RGBLIGHT_ENABLE
  // Enable only particual RGB animations.
  #define RGBLIGHT_EFFECT_RAINBOW_MOOD
  #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
  #define RGBLIGHT_EFFECT_STATIC_GRADIENT
  // Limit max brightness to prevent brownouts.
  #define RGBLIGHT_LIMIT_VAL 128
#endif

// Not sure why Kyria enables Mechanical Locking support.
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

// Free up ~512 bytes.
#define LAYER_STATE_8BIT

// Mod tap tweaks.
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD_PER_KEY
#define TAPPING_TERM_PER_KEY

// Mouse keys settings.
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_MAX_SPEED 7
#define MOUSEKEY_TIME_TO_MAX 40
#define MOUSEKEY_DELAY 100

// Mosue-wheel keys settings.
#define MOUSEKEY_WHEEL_INTERVAL 50
#define MOUSEKEY_WHEEL_MAX_SPEED 7
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40
#define MOUSEKEY_WHEEL_DELAY 100

/* Copyright 2021 Gigahawk
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


#define DRIVER_1_LED_TOTAL 66
#define DRIVER_2_LED_TOTAL 32
#define RGB_MATRIX_LED_COUNT (DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL)

#ifdef RGB_MATRIX_ENABLE
  // 20 minutes (20 * 60 * 1000ms)
  #define RGB_MATRIX_TIMEOUT 1200000

  // Below added per: https://beta.docs.qmk.fm/using-qmk/hardware-features/lighting/feature_rgb_matrix#suspended-state-id-suspended-state
  #define RGB_DISABLE_WHEN_USB_SUSPENDED

  // Effects
  #define RGB_MATRIX_FRAMEBUFFER_EFFECTS  // Heatmap, Rain
  #define RGB_MATRIX_KEYPRESSES           // REACTIVE, SPLASH modes
#endif
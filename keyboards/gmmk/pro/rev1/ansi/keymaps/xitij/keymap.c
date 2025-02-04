/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

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
#ifdef CONSOLE_ENABLE
#include "print.h"
#endif // CONSOLE_ENABLE

#ifdef RGB_MATRIX_ENABLE
  #ifndef RGB_CONFIRMATION_BLINKING_TIME
    #define RGB_CONFIRMATION_BLINKING_TIME 2000 // 2 seconds
  #endif
#endif // RGB_MATRIX_ENABLE

enum my_keycodes {
  LED_TLDE = SAFE_RANGE,
  LED_1,
  LED_2,
  LED_3,
  LED_4,
  LED_5,
  LED_6,
  LED_7,
  LED_8,
  LED_9,
  LED_0,
  LED_MINS,
  LED_EQL
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  //      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
  //      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
  //      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
  //      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
  //      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
  //      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right

  // The FN key by default maps to a momentary toggle to layer 1 to provide access to the QK_BOOT key (to put the board into bootloader mode). Without
  // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
  // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
  // if that's your preference.
  //
  // To put the keyboard in bootloader mode, use FN+Left Shit. If you accidentally put it into bootloader, you can just unplug the USB cable and
  // it'll be back to normal when you plug it back in.
  //
  // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
  // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
  // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
  [0] = LAYOUT(
    KC_ESC,   KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_DEL,            KC_MPLY,
    KC_GRV,   KC_1,    KC_2,    KC_3,     KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC,           KC_HOME,
    KC_TAB,   KC_Q,    KC_W,    KC_E,     KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC, KC_BSLS,           KC_END,
    KC_CAPS,  KC_A,    KC_S,    KC_D,     KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,           KC_ENT,            KC_PGUP,
    KC_LSFT,           KC_Z,    KC_X,     KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,           KC_RSFT, KC_UP,    KC_PGDN,
    KC_LCTL,  KC_LALT, KC_LGUI,                             KC_SPC,                             MO(1),   KC_RALT,  KC_RCTL, KC_LEFT, KC_DOWN,  KC_RGHT
  ),
  [1] = LAYOUT(
    EE_CLR,   KC_BRID, KC_BRIU, KC_MCTL,  KC_LPAD, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, _______, _______, _______,  _______, KC_EJCT,           KC_MUTE,
    LED_TLDE, LED_1,   LED_2,   LED_3,    LED_4,   LED_5,   LED_6,   LED_7,   LED_8,   LED_9,   LED_0,   LED_MINS, LED_EQL, _______,           KC_PSCR,
    _______,  RGB_HUI, RGB_VAI, RGB_SAI,  _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,           _______,
    DB_TOGG,  RGB_HUD, RGB_VAD, RGB_SAD,  _______, _______, _______, _______, _______, _______, _______, _______,           _______,           _______,
    QK_BOOT,           _______, _______,  _______, _______, _______, NK_TOGG, _______, _______, _______, _______,           _______, RGB_MOD,  RGB_TOG,
    _______,  _______, _______,                             _______,                            _______, _______,  _______, RGB_SPD, RGB_RMOD, RGB_SPI
  )
  // This was the default layout before I edited onlibe at https://config.qmk.fm/#/gmmk/pro/rev1/ansi/LAYOUT
  // Use qmk json2c FILE_TODOWNLOADED JSON -o PATH_TO_OUTPUT to create this file...
  // [0] = LAYOUT(
  //     KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MUTE,
  //     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
  //     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
  //     KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
  //     KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
  //     KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
  // ),
  // [1] = LAYOUT(
  //     _______, KC_MYCM, KC_WHOM, KC_CALC, KC_MSEL, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,          _______,
  //     _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
  //     _______, _______, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,            _______,
  //     _______, _______, RGB_VAD, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
  //     _______,          _______, RGB_HUI, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______, RGB_MOD, _______,
  //     _______, _______, _______,                            _______,                            _______, _______, _______, RGB_SPD, RGB_RMOD, RGB_SPI
  // ),
};
// clang-format on

/////////////////////////////////////////////////////////////////////////////////////
// Encoder (rotary knob) enabled
/////////////////////////////////////////////////////////////////////////////////////
#ifdef ENCODER_ENABLE
// Called when the knob is turned (allows user to handle)
bool encoder_update_user(uint8_t index, bool clockwise) {
  // https://beta.docs.qmk.fm/using-qmk/simple-keycodes/feature_advanced_keycodes#alt-escape-for-alt-tab-id-alt-escape-for-alt-tab
  if (get_mods() & MOD_MASK_CTRL) { // If CTRL is held
    uint8_t mod_state = get_mods(); // Store all  modifiers that are held
    unregister_mods(MOD_MASK_CTRL); // Immediately unregister the CRTL key (don't send CTRL-PgDn) - del_mods doesn't work here (not immediate)
    if (clockwise) {
      rgblight_increase_hue();
    } else {
      rgblight_decrease_hue();
    }
    set_mods(mod_state); // Add back in the CTRL key - so ctrl-key will work if ctrl was never released after paging.
  } else if (get_mods() & MOD_MASK_ALT) {
    uint8_t mod_state = get_mods();
    unregister_mods(MOD_MASK_ALT);
    if (clockwise) {
      rgblight_increase_sat();
    } else {
      rgblight_decrease_sat();
    }
    set_mods(mod_state);
  } else if (get_mods() & MOD_MASK_GUI) {
    uint8_t mod_state = get_mods();
    unregister_mods(MOD_MASK_GUI);
    if (clockwise) {
      rgblight_increase_val();
    } else {
      rgblight_decrease_val();
    }
    set_mods(mod_state);
  } else if (get_mods() & MOD_MASK_SHIFT) {
    uint8_t mod_state = get_mods();
    unregister_mods(MOD_MASK_SHIFT);
    if (clockwise) {
      rgblight_increase_speed();
    } else {
      rgblight_decrease_speed();
    }
    set_mods(mod_state);
  } else if (clockwise) { // All else volume.
    tap_code(KC_VOLU);
  } else {
    tap_code(KC_VOLD);
  }
  //return true; //set to return false to counteract enabled encoder in pro.c
  return false;
}
#endif //ENCODER_ENABLE

/////////////////////////////////////////////////////////////////////////////////////
// RGB Matrix (rgb key leds) enabled
/////////////////////////////////////////////////////////////////////////////////////
#ifdef RGB_MATRIX_ENABLE
// Renaming these to make the purpose on this keymap clearer
#define LED_FLAG_CAPS LED_FLAG_NONE
#define LED_FLAG_EFFECTS LED_FLAG_INDICATOR
static void set_rgb_caps_leds_on(void);

#if RGB_CONFIRMATION_BLINKING_TIME > 0
static uint16_t effect_started_time = 0;
static uint8_t r_effect = 0x0, g_effect = 0x0, b_effect = 0x0;
// static void start_effects(void);

// The higher this is, the slower the blinking will be
#ifndef TIME_SELECTED_BIT
  #define TIME_SELECTED_BIT 8
#endif
#if TIME_SELECTED_BIT < 0 || TIME_SELECTED_BIT >= 16
  #error "TIME_SELECTED_BIT must be a positive integer smaller than 16"
#endif
#define effect_red() r_effect = 0xFF, g_effect = 0x0, b_effect = 0x0
#define effect_green() r_effect = 0x0, g_effect = 0xFF, b_effect = 0x0
#endif // RGB_CONFIRMATION_BLINKING_TIME > 0

// Called on powerup and is the last _init that is run.
void keyboard_post_init_user(void) {
#ifdef CONSOLE_ENABLE
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=false;
  debug_keyboard=false;
#endif // CONSOLE_ENABLE
  int mods[35] = {0,2,3,4,5,11,17,33,49,55,65,95,97,79,94,85,93,96,90,69,92,67,76,80,91,75,86,68,77,81,92,28,34,39,44};
  int j;

  /* output each array element's value */
  for (j = 0; j < 35; j++ ) {
    g_led_config.flags[mods[j]] = LED_FLAG_MODIFIER;
  }

  if (!rgb_matrix_is_enabled()) {
    rgb_matrix_enable();
#ifdef CONSOLE_ENABLE
    uprintf("ERROR! RGB Matrix Enabled and wrote to EEPROM! - How was the RGB Matrix Disabled?");
#endif // CONSOLE_ENABLE
  }
}

// Called when the lighting layer is updated. led is single color per key.
bool led_update_user(led_t led_state) {
  if (led_state.caps_lock) {
    if (!rgb_matrix_is_enabled()) {
      // Turn ON the RGB Matrix for CAPS LOCK.
      rgb_matrix_set_flags(LED_FLAG_CAPS);
      rgb_matrix_enable();
    }
  } else if (rgb_matrix_get_flags() == LED_FLAG_CAPS) {
    // RGB Matrix was only ON because of CAPS LOCK. Turn it OFF.
    rgb_matrix_set_flags(LED_FLAG_ALL);
    rgb_matrix_disable();
  }
  return true; // Continue other processing.
}

// Called when any key is pressed.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // LED quick preset keys assignments.
    case LED_TLDE:
      rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR); // Can use RGB_M_P built-in keycode instead.
      break;
    case LED_1:
      rgb_matrix_mode(RGB_MATRIX_ALPHAS_MODS);
      break;
    case LED_2:
      rgb_matrix_mode(RGB_MATRIX_GRADIENT_UP_DOWN);
      break;
    case LED_3:
      rgb_matrix_mode(RGB_MATRIX_JELLYBEAN_RAINDROPS);
      break;
    case LED_4:
      rgb_matrix_mode(RGB_MATRIX_BAND_SAT);
      break;
    case LED_5:
      rgb_matrix_mode(RGB_MATRIX_BAND_VAL);
      break;
    case LED_6:
      rgb_matrix_mode(RGB_MATRIX_BAND_SPIRAL_VAL);
      break;
    case LED_7:
      rgb_matrix_mode(RGB_MATRIX_CYCLE_LEFT_RIGHT); // Can use RGB_M_R built-in keycode instead.
      break;
    case LED_8:
      rgb_matrix_mode(RGB_MATRIX_CYCLE_PINWHEEL); // Can use RGB_M_SW built-in keycode instead.
      break;
    case LED_9:
        rgb_matrix_mode(RGB_MATRIX_BREATHING); // Can use RGB_M_B built-in keycode instead.
      break;

#ifdef RGB_MATRIX_KEYPRESSES // Reactive effects require RGB_MATRIX_KEYPRESSES in config.h
    case LED_0:
      rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_WIDE);
      break;
#endif //RGB_MATRIX_KEYPRESSES

#ifdef RGB_MATRIX_FRAMEBUFFER_EFFECTS // Heatmap and Rain require #define RGB_MATRIX_FRAMEBUFFER_EFFECTS in config.h
    case LED_MINS:
      rgb_matrix_mode(RGB_MATRIX_DIGITAL_RAIN);
      break;
    case LED_EQL:
      rgb_matrix_mode(RGB_MATRIX_TYPING_HEATMAP);
      break;
#endif //RGB_MATRIX_FRAMEBUFFER_EFFECTS
    case RGB_MOD:   // Next RGB Mode
    case RGB_RMOD:  // Previous RGB Mode
    case RGB_HUI:   // Hue Increase
    case RGB_HUD:   // Hue Decrease
    case RGB_VAI:   // Brightness Increase
    case RGB_VAD:   // Brightness Decrease
    case RGB_SPI:   // Speed Increase
    case RGB_SPD:   // Speed Decrease
      if (record->event.pressed) {
        if (rgb_matrix_get_flags() != LED_FLAG_ALL) {
          // Ignore changes to RGB settings while only it's supposed to be OFF.
          return false;  // Skip all further processing.
        }
      }
      break;
    case RGB_TOG:   // RGB Toggle ON or OFF
      if (record->event.pressed) {
#ifdef CONSOLE_ENABLE
        xprintf("[process_record_user] RGB TOGGLE - Enabled[%d] / FLAGS[%x]\n", rgb_matrix_is_enabled(), rgb_matrix_get_flags());
#endif // CONSOLE_ENABLE
        if (rgb_matrix_is_enabled()) {
          switch (rgb_matrix_get_flags()) {
#if RGB_CONFIRMATION_BLINKING_TIME > 0
            case LED_FLAG_EFFECTS:
#endif // RGB_CONFIRMATION_BLINKING_TIME > 0
            case LED_FLAG_CAPS:
              // Turned ON because of EFFECTS or CAPS, is actually OFF.
              // Change to LED_FLAG_ALL to signal it's really ON.
              rgb_matrix_set_flags(LED_FLAG_ALL);
              // Will be re-enabled by the processing of the RGB toggle.
              rgb_matrix_disable_noeeprom();
              break;
            case LED_FLAG_ALL:
              // Is actually ON.
#if RGB_CONFIRMATION_BLINKING_TIME > 0
              if (effect_started_time > 0) {
                // Signal EFFECTS.
                rgb_matrix_set_flags(LED_FLAG_EFFECTS);
                // Will be re-enabled by the processing of the RGB toggle.
                rgb_matrix_disable_noeeprom();
              } else
#endif // RGB_CONFIRMATION_BLINKING_TIME > 0
              if (host_keyboard_led_state().caps_lock) {
                // Signal CAPS.
                rgb_matrix_set_flags(LED_FLAG_CAPS);
                // Will be re-enabled by the processing of the RGB toggle.
                rgb_matrix_disable_noeeprom();
              }
              break;
          }
        }
      }
      break;
  }
  return true; // Continue implementations
}

// Called when the rgb layer is updated. rgb is all colors per key.
bool rgb_matrix_indicators_user(void) {
#if RGB_CONFIRMATION_BLINKING_TIME > 0
  if (effect_started_time > 0) {
    // Render blinking EFFECTS.
    uint16_t deltaTime = sync_timer_elapsed(effect_started_time);
    if (deltaTime <= RGB_CONFIRMATION_BLINKING_TIME) {
      uint8_t led_state = ((~deltaTime) >> TIME_SELECTED_BIT) & 0x01;
      uint8_t val_r = led_state * r_effect;
      uint8_t val_g = led_state * g_effect;
      uint8_t val_b = led_state * b_effect;
      rgb_matrix_set_color_all(val_r, val_g, val_b);
      if (host_keyboard_led_state().caps_lock) {
        set_rgb_caps_leds_on();
      }
      return false;
    } else {
      // EFFECTS duration is finished.
      effect_started_time = 0;
      if (rgb_matrix_get_flags() == LED_FLAG_EFFECTS) {
        // It was turned ON because of EFFECTS.
        if (host_keyboard_led_state().caps_lock) {
          // CAPS is still ON. Demote to CAPS.
          rgb_matrix_set_flags(LED_FLAG_CAPS);
        } else {
          // There is nothing else keeping RGB enabled. Reset flags and turn if off.
          rgb_matrix_set_flags(LED_FLAG_ALL);
          rgb_matrix_disable_noeeprom();
        }
      }
    }
  }
#endif // RGB_CONFIRMATION_BLINKING_TIME > 0
  if (rgb_matrix_get_flags() == LED_FLAG_CAPS) {
    rgb_matrix_set_color_all(0x0, 0x0, 0x0);
  }
  if (host_keyboard_led_state().caps_lock) {
    set_rgb_caps_leds_on();
  }
  return false;
}

#if RGB_CONFIRMATION_BLINKING_TIME > 0
// static void start_effects(void) {
//   effect_started_time = sync_timer_read();
//   if (!rgb_matrix_is_enabled()) {
//     // Turn it ON, signal the cause (EFFECTS).
//     rgb_matrix_set_flags(LED_FLAG_EFFECTS);
//     rgb_matrix_enable_noeeprom();
//   } else if (rgb_matrix_get_flags() == LED_FLAG_CAPS) {
//     // It's already ON, promote the cause from CAPS to EFFECTS.
//     rgb_matrix_set_flags(LED_FLAG_EFFECTS);
//   }
// }
#endif // RGB_CONFIRMATION_BLINKING_TIME > 0

//  67, led 01   0, ESC    6, F1      12, F2      18, F3   23, F4   28, F5      34, F6   39, F7   44, F8      50, F9   56, F10   61, F11    66, F12    69, Prt       Rotary(Mute)   68, led 12
//  70, led 02   1, ~      7, 1       13, 2       19, 3    24, 4    29, 5       35, 6    40, 7    45, 8       51, 9    57, 0     62, -_     78, (=+)   85, BackSpc   72, Home       71, led 13
//  73, led 03   2, Tab    8, Q       14, W       20. E    25, R    30, T       36, Y    41, U    46, I       52, O    58, P     63, [{     89, ]}     93, \|        75, PgUp       74, led 14
//  76, led 04   3, Caps   9, A       15, S       21, D    26, F    31, G       37, H    42, J    47, K       53, L    59, ;:    64, '"                96, Enter     86, PgDn       77, led 15
//  80, led 05   4, Sh_L   10, Z      16, X       22, C    27, V    32, B       38, N    43, M    48, ,<      54, .<   60, /?               90, Sh_R   94, Up        82, End        81, led 16
//  83, led 06   5, Ct_L   11,Win_L   17, Alt_L                     33, SPACE                     49, Alt_R   55, FN             65, Ct_R   95, Left   97, Down      79, Right      84, led 17
//  87, led 07                                                                                                                                                                      88, led 18
//  91, led 08
static void set_rgb_caps_leds_on() {
  // Set alpha and capslock to red
  rgb_matrix_set_color( 3, 0xFF, 0x0, 0x0);	// Caps

  rgb_matrix_set_color( 0, 0xFF, 0x0, 0x0); // ESC
  rgb_matrix_set_color( 6, 0xFF, 0x0, 0x0); // F1
  rgb_matrix_set_color(12, 0xFF, 0x0, 0x0); // F2
  rgb_matrix_set_color(18, 0xFF, 0x0, 0x0); // F3
  rgb_matrix_set_color(23, 0xFF, 0x0, 0x0); // F4
  rgb_matrix_set_color(28, 0xFF, 0x0, 0x0); // F5
  rgb_matrix_set_color(34, 0xFF, 0x0, 0x0); // F6
  rgb_matrix_set_color(39, 0xFF, 0x0, 0x0); // F7
  rgb_matrix_set_color(44, 0xFF, 0x0, 0x0); // F8
  rgb_matrix_set_color(50, 0xFF, 0x0, 0x0); // F9
  rgb_matrix_set_color(56, 0xFF, 0x0, 0x0); // F10
  rgb_matrix_set_color(61, 0xFF, 0x0, 0x0); // F11
  rgb_matrix_set_color(66, 0xFF, 0x0, 0x0); // F12
  rgb_matrix_set_color(69, 0xFF, 0x0, 0x0); // Delete

  rgb_matrix_set_color(67, 0xFF, 0x0, 0x0); // Left side LED 1
  rgb_matrix_set_color(68, 0xFF, 0x0, 0x0); // Right side LED 1
  rgb_matrix_set_color(70, 0xFF, 0x0, 0x0); // Left side LED 2
  rgb_matrix_set_color(71, 0xFF, 0x0, 0x0); // Right side LED 2
  rgb_matrix_set_color(73, 0xFF, 0x0, 0x0); // Left side LED 3
  rgb_matrix_set_color(74, 0xFF, 0x0, 0x0); // Right side LED 3
  rgb_matrix_set_color(76, 0xFF, 0x0, 0x0); // Left side LED 4
  rgb_matrix_set_color(77, 0xFF, 0x0, 0x0); // Right side LED 4
  rgb_matrix_set_color(80, 0xFF, 0x0, 0x0); // Left side LED 5
  rgb_matrix_set_color(81, 0xFF, 0x0, 0x0); // Right side LED 5
  rgb_matrix_set_color(83, 0xFF, 0x0, 0x0); // Left side LED 6
  rgb_matrix_set_color(84, 0xFF, 0x0, 0x0); // Right side LED 6
  rgb_matrix_set_color(87, 0xFF, 0x0, 0x0); // Left side LED 7
  rgb_matrix_set_color(88, 0xFF, 0x0, 0x0); // Right side LED 7
  rgb_matrix_set_color(91, 0xFF, 0x0, 0x0); // Left side LED 8
  rgb_matrix_set_color(92, 0xFF, 0x0, 0x0); // Right side LED 8

  rgb_matrix_set_color( 1, 0xFF, 0x0, 0x0); // `
  rgb_matrix_set_color( 7, 0xFF, 0x0, 0x0); // 1
  rgb_matrix_set_color(13, 0xFF, 0x0, 0x0); // 2
  rgb_matrix_set_color(19, 0xFF, 0x0, 0x0); // 3
  rgb_matrix_set_color(24, 0xFF, 0x0, 0x0); // 4
  rgb_matrix_set_color(29, 0xFF, 0x0, 0x0); // 5
  rgb_matrix_set_color(35, 0xFF, 0x0, 0x0); // 6
  rgb_matrix_set_color(40, 0xFF, 0x0, 0x0); // 7
  rgb_matrix_set_color(45, 0xFF, 0x0, 0x0); // 8
  rgb_matrix_set_color(51, 0xFF, 0x0, 0x0); // 9
  rgb_matrix_set_color(57, 0xFF, 0x0, 0x0); // 0
  rgb_matrix_set_color(62, 0xFF, 0x0, 0x0); // -
  rgb_matrix_set_color(78, 0xFF, 0x0, 0x0); // =
  rgb_matrix_set_color(85, 0xFF, 0x0, 0x0); // Backspace

  rgb_matrix_set_color( 8, 0xFF, 0x0, 0x0);	// Q
  rgb_matrix_set_color(14, 0xFF, 0x0, 0x0);	// W
  rgb_matrix_set_color(20, 0xFF, 0x0, 0x0);	// E
  rgb_matrix_set_color(25, 0xFF, 0x0, 0x0);	// R
  rgb_matrix_set_color(30, 0xFF, 0x0, 0x0);	// T
  rgb_matrix_set_color(36, 0xFF, 0x0, 0x0);	// Y
  rgb_matrix_set_color(41, 0xFF, 0x0, 0x0);	// U
  rgb_matrix_set_color(46, 0xFF, 0x0, 0x0);	// I
  rgb_matrix_set_color(52, 0xFF, 0x0, 0x0);	// O
  rgb_matrix_set_color(58, 0xFF, 0x0, 0x0);	// P
  rgb_matrix_set_color(63, 0xFF, 0x0, 0x0);	// [
  rgb_matrix_set_color(89, 0xFF, 0x0, 0x0);	// ]
  rgb_matrix_set_color(93, 0xFF, 0x0, 0x0);	// ?

  rgb_matrix_set_color( 9, 0xFF, 0x0, 0x0);	// A
  rgb_matrix_set_color(15, 0xFF, 0x0, 0x0);	// S
  rgb_matrix_set_color(21, 0xFF, 0x0, 0x0);	// D
  rgb_matrix_set_color(26, 0xFF, 0x0, 0x0);	// F
  rgb_matrix_set_color(31, 0xFF, 0x0, 0x0);	// G
  rgb_matrix_set_color(37, 0xFF, 0x0, 0x0);	// H
  rgb_matrix_set_color(42, 0xFF, 0x0, 0x0);	// J
  rgb_matrix_set_color(47, 0xFF, 0x0, 0x0);	// K
  rgb_matrix_set_color(53, 0xFF, 0x0, 0x0);	// L
  rgb_matrix_set_color(59, 0xFF, 0x0, 0x0);	// ;
  rgb_matrix_set_color(64, 0xFF, 0x0, 0x0);	// '

  rgb_matrix_set_color(10, 0xFF, 0x0, 0x0);	// Z
  rgb_matrix_set_color(16, 0xFF, 0x0, 0x0);	// X
  rgb_matrix_set_color(22, 0xFF, 0x0, 0x0);	// C
  rgb_matrix_set_color(27, 0xFF, 0x0, 0x0);	// V
  rgb_matrix_set_color(32, 0xFF, 0x0, 0x0);	// B
  rgb_matrix_set_color(38, 0xFF, 0x0, 0x0);	// N
  rgb_matrix_set_color(43, 0xFF, 0x0, 0x0);	// M
  rgb_matrix_set_color(48, 0xFF, 0x0, 0x0);	// ,
  rgb_matrix_set_color(54, 0xFF, 0x0, 0x0);	// .
  rgb_matrix_set_color(60, 0xFF, 0x0, 0x0);	// /
}
#endif // RGB_MATRIX_ENABLE

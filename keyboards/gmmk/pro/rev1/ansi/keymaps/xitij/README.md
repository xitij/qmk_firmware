# GMMK Pro Standard Layout for macOS by Xitij

This is my personalized keyboard. CAPS_LOCKS turns on red RGB for most of the keyboard (overriding other RGB settings) to signal that it is toggled on. Then I took keys from Apple's Magic Keyboard, also referencing code from other community keymaps (mainly this [one](https://github.com/xitij/qmk_firmware/blob/master/keyboards/gmmk/pro/rev1/ansi/keymaps/macos/readme.md)).

## Keymap
Layer 0
<img width="1092" alt="Layer0" src="https://i.postimg.cc/d1S4Jk39/Layer-0.png">

Layer 1 (Hold <kbd>Fn</kbd>)
<img width="1088" alt="Layer1" src="https://i.postimg.cc/T1LQ1dWv/Layer-1.png">


## Notable differences from stock key layout for Windows:
- <kbd>Eject</kbd> key for the last key in function row: Needed for macOS native global "Sleep" hotkey (<kbd>⌘</kbd><kbd>⌥</kbd><kbd>Eject</kbd>)

## Notable Features
- Rotary Encoder support (Defaults to stock behavior Volume Up/Down) with some additional rotary function.
  * Increase/Decrease RGB Hue: <kbd>⌃ Control</kbd> + Rotary Knob
  * Increase/Decrease RGB Saturation: <kbd>⌥ Option</kbd> + Rotary Knob
  * Increase/Decrease RGB Brightness: <kbd>⌘ Command</kbd> + Rotary Knob
  * Increase/Decrease RGB Speed: <kbd>Shift</kbd> + Rotary Knob
- Modified Order for macOS modifier keys: 
    * Left: <kbd>⌃ Control</kbd><kbd>⌥ Option</kbd><kbd>⌘ Command</kbd> 
    * Right: <kbd>Fn</kbd><kbd>⌥ Option</kbd><kbd>⌃ Control</kbd>
- Apple Magic Keyboard-like Function Row Mode (Toggle with <kbd>Fn</kbd>)
    * <kbd>F1</kbd>: Decrease display brightness
    * <kbd>F2</kbd>: Increase display brightness
    * <kbd>F3</kbd>: Mission Control
    * <kbd>F4</kbd>: Launchpad
    * <kbd>F5</kbd>: Media Previous
    * <kbd>F6</kbd>: Media Next
    * <kbd>F7</kbd>: Media Play/Pause
    * <kbd>F8</kbd>: Media Stop
    * <kbd>F9</kbd>: (none)
    * <kbd>F10</kbd>: (none)
    * <kbd>F11</kbd>: (none)
    * <kbd>F12</kbd>: (none)

> #### NOTE
> - Media key mappings mostly follow Apple Magic Keyboard (<kbd>F1</kbd> thru <kbd>F8</kbd>) except <kbd>F9</kbd> thru <kbd>F12</kbd>, where keys have been disabled. The GMMK Pro has the more convenient rotary knob for volume control.
> - <kbd>F1</kbd> - <kbd>F12</kbd> act as standard function keys (on the first layer).

## RGB Lighting
- Retains Glorious stock firmware key mappings for control
    * <kbd>Fn</kbd><kbd>Up</kbd> / <kbd>Fn</kbd><kbd>Down</kbd>: Cycle presets
    * <kbd>Fn</kbd><kbd>Left</kbd> / <kbd>Fn</kbd><kbd>Right</kbd>: Adjust speed
    * <kbd>Fn</kbd><kbd>W</kbd> / <kbd>Fn</kbd><kbd>S</kbd>: Adjust brightness
- Quickly switch to popular presets:
    * <kbd>Fn</kbd><kbd>`</kbd> : Solid color (no animation)
    * <kbd>Fn</kbd><kbd>1</kbd> : Solid duotone (no animation) - <kbd>⌃ Control</kbd><kbd>Knob</kbd> to change secondary color.
    * <kbd>Fn</kbd><kbd>2</kbd> : Vertical gradient - <kbd>⌃ Control</kbd><kbd>Knob</kbd> to change secondary color.
    * <kbd>Fn</kbd><kbd>3</kbd> : "Jellybean Raindrops"
    * <kbd>Fn</kbd><kbd>4</kbd> : Horizontal wipe with white backlight
    * <kbd>Fn</kbd><kbd>5</kbd> : Horizontal wipe
    * <kbd>Fn</kbd><kbd>6</kbd> : Single color pinwheel
    * <kbd>Fn</kbd><kbd>7</kbd> : Horizontal rainbow
    * <kbd>Fn</kbd><kbd>8</kbd> : Rainbow pinwheel
    * <kbd>Fn</kbd><kbd>9</kbd> : Breathing
    * <kbd>Fn</kbd><kbd>0</kbd> : Reactive (light up on keypress)
    * <kbd>Fn</kbd><kbd>-</kbd> : "Digital Rain"
    * <kbd>Fn</kbd><kbd>=</kbd> : "Heatmap"
- RGB turns off after 20 minutes of inactivity
- RGB turns off when USB is suspended / enters sleep
- <kbd>Caps Lock</kbd> toggle indicator (<kbd>Caps Lock</kbd> key, alphanumeric keys, and side lights will turn red)
- Easy RGB control using Rotary Encoder
    - <kbd>Control</kbd>+<kbd>Rotate Knob</kbd>: Adjust hue
    - <kbd>Option</kbd>+<kbd>Rotate Knob</kbd>: Adjust saturation
    - <kbd>Command</kbd>+<kbd>Rotate Knob</kbd>: Adjust brightness

> All latest QMK effects [(41 as of now)](https://beta.docs.qmk.fm/using-qmk/hardware-features/lighting/feature_rgb_matrix#rgb-matrix-effects-id-rgb-matrix-effects) are enabled by default and will apply in order when cycling through using <kbd>Fn</kbd><kbd>Up</kbd> / <kbd>Fn</kbd><kbd>Down</kbd>. You can disable specific effects by uncommenting (remove the `//` at the beginning of line) respective lines (ex: `#define DISABLE_RGB_MATRIX_BREATHING`) in `qmk_firmware/keyboards/gmmk/pro/ansi/keymaps/zvuc/config.h` then recompiling the firmware.

## Other Features
- NKRO toggle (<kbd>Fn</kbd>+<kbd>N</kbd>)

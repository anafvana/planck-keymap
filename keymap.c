/* Copyright 2015-2021 Jack Humbert
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

enum planck_layers {
  _COLEMAK,
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  BACKLIT = SAFE_RANGE,
};

// Left-hand home row mods
// #define HOME_A LSFT_T(KC_A)
// #define HOME_R LCTL_T(KC_R)
// #define HOME_S LALT_T(KC_S)
// #define HOME_T LGUI_T(KC_T)

// Right-hand home row mods
// #define HOME_N RGUI_T(KC_N)
// #define HOME_E LALT_T(KC_E)
// #define HOME_I RCTL_T(KC_I)
// #define HOME_O RSFT_T(KC_O)

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define COLEMAK DF(_COLEMAK)
#define QWERTY DF(_QWERTY)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  | Alt  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | Ctrl | Cmd  |    Space    |Raise |Lower |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,	   KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LGUI,
    _______, _______, _______, KC_LCTL, KC_LALT, KC_SPC,  KC_SPC,  RAISE,   LOWER,   _______, _______, _______
),

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   N  |   J  |   K  |   L  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Alt  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | Ctrl | Cmd  |    Space    |Raise |Lower |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_LGUI,
    _______, _______, _______, KC_LCTL, KC_LALT, KC_SPC,  KC_SPC,  RAISE,   LOWER,   _______, _______, _______
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |      |      |MBtn1 |MBtn2 |      | Acl2 |      |  
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |Qwerty|MouseL|MouseD|MouseU|MouseR| Acl1 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |      |WheelL|WheelD|WheelU|WheelR| Acl0 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |   QWERTY    |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, KC_BTN1, KC_BTN2, _______, KC_ACL0, _______,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_ACL1, _______,
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_ACL2, _______,
    _______, _______, _______, _______, _______, QWERTY,  QWERTY,  _______, _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |  0   |  1 ! |  2 @ |  3 # |  ` ~ |      | Home | End  |      |PrtScr|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  - _ |  4 $ |  5 % |  6 ^ |  ' " | Left | Down | Up   | Rght |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  = + |  7 & |  8 * |  9   |  \ | |      |  (   |  [ { |  ] } |  )   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------' 
 */
[_RAISE] = LAYOUT_planck_grid(
    _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_GRV,  _______, KC_HOME, KC_END,  _______, KC_PSCR, KC_DEL, 
    _______, KC_MINS, KC_4,    KC_5,    KC_6,    KC_QUOT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
    _______, KC_EQL,  KC_7,    KC_8,    KC_9,    KC_BSLS, _______, KC_LPRN, KC_LBRC, KC_RBRC, KC_RPRN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 * v-------------RGB CONTROL------------v    v-------------MEDIA CONTROL------------v
 * ,-----------------------------------------------------------------------------------.
 * | Reset|Debug |      | HUE- | HUE+ |      |      | PgDn | PgUp |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |AGnorm|AGswap|BRGTH-|BRGTH+|      | Rwd  | Prev | Next | Fwd  | Bri+ |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |RGBTog|RGBMOD| SAT- | SAT+ |      | Mute | Vol- | Vol+ | Play | Bri- |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |   Colemak   |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    QK_BOOT, DB_TOGG, _______, RGB_HUD, RGB_HUI, _______, _______, KC_PGDN, KC_PGUP, _______, _______, _______,
    _______, AG_NORM, AG_SWAP, RGB_VAD, RGB_VAI, _______, KC_MRWD, KC_MPRV, KC_MNXT, KC_MFFD, KC_BRIU, _______,
    _______, RGB_TOG, RGB_MOD, RGB_SAD, RGB_SAI, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, KC_BRID, _______,
    _______, _______, _______, _______, _______, COLEMAK, COLEMAK, _______, _______, _______, _______, _______
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
  }
  return true;
}
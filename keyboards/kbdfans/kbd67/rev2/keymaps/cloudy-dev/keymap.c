/* Copyright 2018 'mechmerlin'
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

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

enum unicode_names {
    AE_SMALL,
    AE_BIG,
    OE_SMALL,
    OE_BIG,
    UE_SMALL,
    UE_BIG,
    SZ_SMALL,
    EURO_SIGN
};

const uint32_t PROGMEM unicode_map[] = {
    [AE_SMALL]  = 0x00E4,  // ä
    [AE_BIG] = 0x00C4,  // Ä
    [OE_SMALL]  = 0x00F6,
    [OE_BIG] = 0x00D6,
    [UE_SMALL] = 0x00FC,
    [UE_BIG] = 0x00DC,
    [SZ_SMALL] = 0x00DF,
    [EURO_SIGN] = 0x20AC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp | ~ `|
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |Caps   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |Home|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|End |
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |        Space          | FN|Alt|Ctrl|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[0] = LAYOUT_65_ansi(
  KC_ESC,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_GRV,
  KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
  KC_CAPS, KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT, KC_HOME,
  KC_LSFT, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_END,
  KC_LCTL, KC_LGUI, KC_LALT,                KC_SPC,                          MO(1),   KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

  /* Keymap Fn Layer
   * ,----------------------------------------------------------------.
   * |~ `|F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |UCMD|
   * |----------------------------------------------------------------|
   * |     |   |€  |   |   |   |Ü  |   |Ö  |   |7  |8  |9  |PSc  |Ins |
   * |----------------------------------------------------------------|
   * |      |Ä  |ß  |   |   |   |   |   |   |   |4  |5  |6       |PUp |
   * |----------------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |1  |2  |3     |PUp|PDn |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |0  |NLCK|Hom|PDn|End |
   * `----------------------------------------------------------------'
   */
[1] = LAYOUT_65_ansi(
   KC_GRV,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12,          KC_DEL,UC_MOD,
   _______,_______,  _______,X(EURO_SIGN),_______,_______,_______,XP(UE_SMALL, UE_BIG),_______,XP(OE_SMALL, OE_BIG),KC_P7,  KC_P8,KC_P9,     KC_PSCR,KC_INS,
   _______,XP(AE_SMALL, AE_BIG),X(SZ_SMALL),_______,_______,_______,_______,_______,_______,_______,KC_P4,KC_P5, KC_P6,KC_PGUP,
           _______,_______,_______,_______,_______,_______,_______,_______, _______,KC_P1,KC_P2,       KC_P3,KC_PGUP,KC_PGDN,
    _______,  _______,  _______,                     _______,                     _______,KC_P0,KC_NLCK,KC_HOME,KC_PGDN, KC_END),


[2] = LAYOUT_65_ansi(
  _______, _______,   _______, _______,   _______, _______,   _______, _______,   _______, _______,   _______, _______,  _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
  _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______,                            _______,                   _______, _______, _______, _______, _______, _______
), 

[3] = LAYOUT_65_ansi(
  _______, _______,   _______, _______,   _______, _______,   _______, _______,   _______, _______,   _______, _______,  _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
  _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______,                            _______,                   _______, _______, _______, _______, _______, _______
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

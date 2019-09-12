/* Copyright 2019 Maarten Dekkers <maartenwut@gmail.com>
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

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define AT RALT(KC_2)
#define MENUWIN RGUI_T(KC_APP)
#define NUMCAPS LT(2, KC_CAPS)

enum custom_keycodes {
  M_LBRC = SAFE_RANGE,
  M_RBRC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME, KC_PGUP, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, XXXXXXX,          KC_END,  KC_PGDN, \
    NUMCAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,                             \
    KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, XXXXXXX,          KC_UP,            \
    KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             MO(1),   KC_RGUI, KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT  \
    ),

  [1] = LAYOUT(
    A(KC_F4),KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_INS,  KC_MPRV, \
    _______, _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, M_LBRC,  M_RBRC,  _______,          KC_DEL,  KC_MNXT, \
    _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, _______, AT,      _______, _______,                            \
    _______, KC_GRV,  _______, _______, _______, _______, _______, _______, _______, _______, _______, S(KC_7), _______, _______,          KC_VOLU,          \
    _______, _______, _______,                            _______,                            _______, MENUWIN, _______,          KC_MUTE, KC_VOLD, KC_MPLY  \
  ),

  [2] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   _______, _______, _______, _______,          _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   _______, KC_PPLS, _______, _______,          _______, _______, \
    _______, KC_NLCK, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   _______, _______, _______, KC_PENT,                            \
    _______, _______, _______, _______, _______, _______, _______, KC_P0,   KC_PDOT, _______, _______, KC_PMNS, _______, _______,          _______,          \
    _______, _______, _______,                            _______,                            _______, _______, _______,          _______, _______, _______  \
  ),

  [3] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                            \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          \
    _______, _______, _______,                            _______,                            _______, _______, _______,          _______, _______, _______  \
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case M_LBRC:
    case M_RBRC:
      if (record->event.pressed) {
        if(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)) {
          unregister_code(KC_LSFT);
		      unregister_code(KC_RSFT);
          if(keycode = M_LBRC) {
					  register_code(RALT(KC_7));
          }
          if(keycode = M_RBRC) {
					  register_code(RALT(KC_0));
          }
        }
        else {
          if(keycode = M_LBRC) {
					  register_code(RALT(KC_8));
          }
          if(keycode = M_RBRC) {
					  register_code(RALT(KC_9));
          }
        }
      }
      return false;
  }
	return true;
};




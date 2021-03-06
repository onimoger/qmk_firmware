/*
This is the keymap for the keyboard

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2017 Art Ortenburger

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

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define LS__SPC MT(MOD_LSFT, KC_SPC)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT( \
    KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
    KC_ESC,     KC_A,    KC_S,    KC_D,    KC_F,    KC_G,          KC_LGUI, TG(_LOWER),       TG(_RAISE), KC_DEL,       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    LOWER,   KC_LSFT, KC_LCTL,           KC_RALT, KC_SPC, RAISE,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT \
  ),

  [_LOWER] = LAYOUT( \
    KC_TILD, KC_EXLM, KC_AT,   KC_UNDS, KC_LPRN,  KC_RPRN,                                                                KC_PLUS,    KC_7,    KC_8,   KC_9, KC_MINUS, _______, \
    KC_HASH, KC_DLR,  KC_PERC, KC_PIPE, KC_LCBR,  KC_RCBR,        _______, _______,             _______, _______,         KC_EQL,     KC_4,    KC_5,   KC_6, KC_ASTR,  XXXXXXX, \
    KC_CIRC, KC_AMPR, KC_ASTR, KC_BSLS, KC_LBRC,  KC_RBRC,  _______, _______, _______,        _______, _______, _______,  KC_0,       KC_1,    KC_2,   KC_3, _______,  _______ \
  ),

  [_RAISE] = LAYOUT( \
    KC_MNXT, KC_MPLY,  KC_HOME, KC_UP,    KC_END,   KC_PGUP,                                                                 KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, \
    KC_VOLD, KC_VOLU,  KC_LEFT, KC_DOWN,  KC_RIGHT, KC_PGDN,           _______, _______,          _______, _______,          KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX, \
    XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  _______, _______, _______,          _______, _______, _______, KC_F11,   KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, _______ \
  ),

  [_ADJUST] =  LAYOUT( \
    _______, RESET,   _______, _______, _______, _______,                                                                _______, _______, _______, _______, _______, KC_DEL,  \
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM,          _______, _______,          _______, _______,          AG_SWAP, QWERTY , _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY  \
  )


};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QWERTY:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_QWERTY);
    }
    return false;
    break;
  }
  return true;
}

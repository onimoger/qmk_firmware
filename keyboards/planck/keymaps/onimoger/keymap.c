/* Copyright 2015-2017 Jack Humbert
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

#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  BACKLIT,
  EXT_PLV
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Gui  |      | Alt  | Lower| Shift| Spc  | Raise| Del  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_TAB,  KC_Q,    KC_W,      KC_E,    KC_R,   KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,      KC_P,    KC_BSPC},
  {KC_ESC,  KC_A,    KC_S,      KC_D,    KC_F,   KC_G,    KC_H,    KC_J,    KC_K,    KC_L,      KC_SCLN, KC_QUOT},
  {KC_NO,   KC_Z,    KC_X,      KC_C,    KC_V,   KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,    KC_SLSH, KC_ENT },
  {KC_LCTL, KC_LGUI, TG(_LOWER), KC_LALT, LOWER,  KC_LSFT, KC_SPC,  RAISE,   KC_DEL,  TG(_RAISE), KC_NO,   KC_NO  }
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   (  |   )  |  _   |   @  |  +   |   7  |   8  |   9  |  =   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   #  |   $  |   {  |   }  |  |   |  %   |  -   |   4  |   5  |   6  |  *   |  .   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ^  |   &  |   [  |   ]  |   `  |  \   |  0   |   1  |   2  |   3  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_TILD, KC_EXLM, KC_LPRN, KC_RPRN, KC_UNDS, KC_AT,   KC_PLUS, KC_7,    KC_8,    KC_9,    KC_EQL,  _______},
  {KC_HASH, KC_DLR,  KC_LCBR, KC_RCBR, KC_PIPE, KC_PERC, KC_MINS, KC_4,    KC_5,    KC_6,    KC_ASTR, KC_DOT },
  {KC_CIRC, KC_AMPR, KC_LBRC, KC_RBRC, KC_GRV,  KC_BSLS, KC_0,    KC_1,    KC_2,    KC_3,    _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | Next | Play | Home |  Up  | End  | PgUp |  F1  |  F2  |  F3  |  F4  |  F5  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Vol- | Vol+ | Left | Down | Right| PgDn |  F6  |  F7  |  F8  |  F9  |  F10 |      |
 * |------+------+------+------+------+------+-----+------+------+------+-------+------|
 * |      |      |      |      |      |      |  F11 |  F12 |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_MNXT, KC_MPLY, KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_F1,   KC_F2,    KC_F3,   KC_F4,   KC_F5,   _______},
  {KC_VOLD, KC_VOLU, KC_LEFT, KC_DOWN, KC_RIGHT,KC_PGDN, KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_NO  },
  {_______, _______, _______, _______, _______, _______, _______, KC_F11,   KC_F12,  KC_NO,   _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL },
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______, _______, _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}


};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        unregister_code(KC_RSFT);
      }
      return false;
      break;
  }
  return true;
}
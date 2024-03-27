/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney <drashna@live.com> (@drashna)
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
#include "keymap_danish.h"
#include "keymap_german.h"

enum layers {
    _QWERTY, 
    _LOWER, 
    _RAISE, 
    _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  BACKLIT,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_moonlander(
        KC_TAB         , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , _______,          _______ , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P            , KC_BSPC,
        LCTL_T(KC_ESC) , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , _______,          _______ , KC_H   , KC_J   , KC_K   , KC_L   , KC_MEH          , KC_ENTER,
        KC_LSFT        , KC_GRV , KC_X   , KC_C   , KC_V   , KC_B   , _______,          _______ , KC_N   , KC_M   , KC_COMM, KC_DOT , RCTL_T(KC_SLSH) , KC_RSFT,
        _______        , _______, _______, KC_LCMD, LOWER  , KC_SPACE,                             KC_SPACE, RAISE , KC_RALT, _______, _______         , _______,
        _______        , _______, _______, _______, _______,          _______,          _______,           _______, _______, _______, _______         , _______, 
                                                    _______, _______, _______,          _______, _______, _______
    ),
    [_LOWER] = LAYOUT_moonlander(
        _______, _______, DK_DQUO, _______, _______, DK_ACUT, _______, _______, DK_AMPR, DK_SLSH, DK_LPRN, DK_RPRN, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, _______, DK_CIRC, RALT(DK_SLSH), DK_LBRC, DK_RBRC, _______, DK_TILD,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, S(DK_LBRC), S(DK_RBRC), DK_PLUS,_______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,_______,
                                        _______, _______, _______, _______, _______, _______
    ),
    [_RAISE] = LAYOUT_moonlander(
        _______, DK_EXLM, DK_QUOT, DK_HASH, _______, DK_PERC, _______, _______, _______, _______, RALT(KC_I) , _______ ,_______    , DK_ARNG, 
        _______, RALT(KC_BSLS), DK_ASTR  , RALT(RSFT(KC_3)), DK_EQL, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, DK_AE, DK_OSTR,
        _______, KC_Z, _______, _______, DK_QUES, DK_GRV, _______, _______, _______, _______, _______,_______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                        _______, _______, _______, _______, _______, _______
    ),
    [_ADJUST] = LAYOUT_moonlander(
        _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , _______, _______, KC_6   , KC_7   , KC_8   , KC_9    , KC_0  , _______,
        _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , _______, _______, KC_F6  , KC_F7  , KC_F8  , KC_F9   , KC_F10 , KC_VOLU,
        _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_MPLY, KC_MPRV, KC_MNXT, _______, KC_VOLD,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,

        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
                                        _______, _______, _______, _______, _______, _______
    ),


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
       
      switch (keycode) {
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
        default:
          break;
    }

    return true;
};

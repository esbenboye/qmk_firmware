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

#include QMK_KEYBOARD_H
#include "muse.h"
#include "keymap_danish.h"
#include "keymap_german.h"

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
};

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // Enables RGB, without saving settings
  rgblight_sethsv_noeeprom(HSV_PURPLE);
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {



/* Qwerty
 * ,--------------------------------------------------------------------------------------.
 * |         |      |      |      |      |      |      |      |      |      |      |      |
 * |---------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab     |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |---------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc/Ctrl|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |      | Enter|
 * |---------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift   |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   -  | Shift|
 * |---------+------+------+------+------+------+------+------+------+------+------+------|
 * |         |      |      | Cmd  |Lower |    Space    |Raise | Ralt |      |      |      |
 * `--------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid( \
  KC_TAB,           KC_Q,       KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPACE,  \
  LCTL_T(KC_ESC),   KC_A,       KC_S,    KC_D,    KC_F,    KC_G,    KC_H,     KC_J,    KC_K,    KC_L,    KC_MEH, KC_ENTER, \
  KC_LSFT,          KC_GRV,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,  \
  _______,          _______,    _______, KC_LCMD, LOWER,KC_SPACE,RAISE, KC_RALT, _______, _______, _______,    KC_TRNS  \
),


/* Lower
 * ,--------------------------------------------------------------------------------------.
 * |         |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid( \
  _______, _______, DK_DQUO, _______, _______, DK_ACUT, DK_AMPR, DK_SLSH,       DK_LPRN,    DK_RPRN,       DK_EQL,  DK_QUES,  \
  _______, _______, _______, _______, _______, _______,DK_CIRC , RALT(DK_SLSH), DK_LBRC,    DK_RBRC,       _______, DK_TILD, \
  _______, _______, _______, _______, _______, _______, _______, _______,       S(DK_LBRC), S(DK_RBRC),    DK_PLUS, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______,       _______,    _______,       _______, KC_TRNS \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid( \
  RALT(RSFT(KC_3)), DK_EXLM,        DK_QUOT, DK_HASH, _______, DK_PERC, _______, _______, RALT(KC_I), _______, _______, DK_ARNG, \
  _______,          RALT(KC_BSLS),  DK_ASTR, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,      KC_RIGHT, DK_AE,  DK_OSTR, \
  _______,          KC_Z,           _______, _______, _______, DK_GRV,  _______, _______, _______,    _______, _______, _______, \
  _______,          _______,        _______, _______, _______, _______, _______, _______, _______,    _______, _______, KC_TRNS \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid( \
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_VOLU, \
  _______, _______, _______, _______, _______, _______, _______, KC_MPLY, KC_MPRV, KC_MNXT, _______, KC_VOLD,  \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_TRNS  \
)



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
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}


// Modify if custom stuff needs to be done
//uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
//    switch (keycode) {
//        case SFT_T(KC_SPC):
//            return TAPPING_TERM + 1250;
//        case LT(1, KC_GRV):
//            return 130;
//        default:
//            return TAPPING_TERM;
//    }
//}

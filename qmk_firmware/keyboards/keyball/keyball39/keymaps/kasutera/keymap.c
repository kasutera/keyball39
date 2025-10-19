/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_right_ball(
    KC_Q                , KC_W      , KC_E                  , KC_R          , KC_T              ,                             KC_Y          , KC_U    , KC_I    , KC_O    , KC_P                    ,
    MT(MOD_LCTL,KC_A)   , KC_S      , MT(MOD_LGUI,KC_D)     , LT(2,KC_F)    , KC_G              ,                             KC_H          , KC_J    , KC_K    , KC_L    , S(KC_SCLN)              ,
    MT(MOD_LSFT,KC_Z)   , KC_X      , KC_C                  , KC_V          , KC_B              ,                             KC_N          , KC_M    , KC_COMM , KC_DOT  , MT(MOD_RSFT,KC_SLSH)    ,
    MT(MOD_LALT,KC_LNG2), KC_LCTL   , MT(MOD_LCTL,KC_MINS)  , LT(2,KC_ESC)  ,MT(MOD_LGUI,KC_SPC), KC_TAB    , LT(3,KC_BSPC) , LT(1,KC_ENT)  ,                               MT(MOD_RSFT,KC_LNG1)
  ),

  [1] = LAYOUT_right_ball(
    S(KC_1)             , S(KC_2)   , S(KC_3)               , S(KC_4)   , S(KC_5)   ,                         S(KC_6)   , S(KC_7)   , S(KC_8)  , S(KC_9)  , S(KC_0)             ,
    MT(MOD_LCTL,KC_1)   , KC_2      , MT(MOD_LGUI,KC_3)     , LT(2,KC_4), KC_5      ,                         KC_6      , KC_7      , KC_8     , KC_9     , KC_0                ,
    MT(MOD_LSFT,KC_SCLN), KC_EQL    , KC_GRV                , KC_QUOT   , KC_BSLS   ,                         KC_LBRC   , KC_RBRC   , KC_COMM  , KC_DOT   , MT(MOD_RSFT,KC_SLSH) ,
    KC_LCTL             , KC_LALT   , KC_LGUI               , _______   , _______   , _______   , _______   , _______   ,                                   KC_RSFT
  ),

  [2] = LAYOUT_right_ball(
    _______ , KC_BRMD           , KC_BRMU           , _______       , KC_PGUP   ,                         LCS(KC_TAB) , G(KC_LBRC), A(KC_TAB)  , G(KC_RBRC), C(KC_TAB) ,
    _______ , KC_KB_VOLUME_DOWN , KC_KB_VOLUME_UP   , KC_KB_MUTE    , KC_PGDN   ,                         KC_BSPC     , KC_BTN1   , KC_BTN3    , KC_BTN2   , KC_PGUP   ,
    _______ , _______           , _______           , _______       , _______   ,                         KC_DEL      , KC_ENT    , C(KC_LEFT) , C(KC_RGHT), KC_PGDN   ,
    _______ , _______           , _______           , _______       , _______   , _______   , LCA(KC_TAB) , _______   ,                                      _______
  ),

  [3] = LAYOUT_right_ball(
    KC_F1   , KC_F2     , KC_F3     , KC_F4     ,  KC_F5    ,                         KC_F6     , KC_F7     , KC_F8     , KC_F9     , KC_F10    ,
    KC_F11  , KC_F12    , RGB_SAI   , RGB_VAI   ,  SCRL_DVI ,                         KC_LEFT   , KC_DOWN   , KC_UP     , KC_RGHT   , _______   ,
    KC_LSFT , RGB_HUD   , RGB_SAD   , RGB_VAD   ,  SCRL_DVD ,                         _______   , CPI_D100  , CPI_I100  , _______   , KBC_SAVE  ,
    RGB_TOG , KBC_RST   , _______   , _______   ,  _______  , _______  , _______    , _______   ,                                     QK_BOOT
  )
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif

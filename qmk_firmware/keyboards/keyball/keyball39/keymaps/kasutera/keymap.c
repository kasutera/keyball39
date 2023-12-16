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
  // keymap for default (VIA)
  [0] = LAYOUT_universal(
    KC_Q            , KC_W      , KC_E              , KC_R          , KC_T              ,                                         KC_Y          , KC_U    , KC_I    , KC_O    , LT(2,KC_P)          ,
    LT(KC_LCTL,KC_A), KC_S      , LT(KC_LGUI,KC_D)  , LT(2,KC_F)    , KC_G              ,                                         KC_H          , KC_J    , KC_K    , KC_L    , S(KC_SCLN)          ,
    LT(KC_LSFT,KC_Z), KC_X      , KC_C              , KC_V          , KC_B              ,                                         KC_N          , KC_M    , KC_COMM , KC_DOT  , LT(KC_RSFT,KC_SLSH) ,
    KC_LCTL         , KC_LALT   ,LT(KC_LGUI,KC_MINS), LT(2,KC_LNG2) , LT(KC_LGUI,KC_SPC), LT(KC_LCTL,KC_TAB)    ,LT(1,KC_LNG1)  , LT(3,KC_ESC)  , _______ , _______ , _______ , KC_RSFT
  ),

  [1] = LAYOUT_universal(
    S(KC_1)             , S(KC_2)   , S(KC_3)   , S(KC_4)   , S(KC_5)   ,                         S(KC_6)   , S(KC_7)   , S(KC_8)  , S(KC_9)  , S(KC_0)             ,
    LT(KC_LCTL,KC_1)    , KC_2      , KC_3      , KC_4      , KC_5      ,                         KC_6      , KC_7      , KC_8     , KC_9     , KC_0                ,
    LT(KC_LSFT,KC_SCLN) , KC_EQL    , KC_GRV    , KC_QUOT   , KC_BSLS   ,                         KC_LBRC   , KC_RBRC   , KC_COMM  , KC_DOT   , LT(KC_RSFT,KC_SLSH) ,
    KC_LCTL             , KC_LALT   , KC_LGUI   , _______   , _______   , _______   , _______   , _______   , _______   , _______  , _______  , _______
  ),

  [2] = LAYOUT_universal(
    _______ , KC_BRMD   , KC_BRMU   , _______   , KC_PGUP   ,                         _______   , G(KC_LBRC), KC_MINUS    , G(KC_RBRC)  , KC_ESC    ,
    _______ , KC_VOLD   , KC_VOLU   , KC_MUTE   , KC_PGDN   ,                         KC_BSPC   , KC_BTN1   , KC_BTN3     , KC_BTN2     , _______   ,
    _______ , _______   , _______   , _______   , _______   ,                         _______   , KC_ENT    , C(KC_LEFT)  , C(KC_RGHT)  , _______   ,
    _______ , _______   , _______   , _______   , _______   , _______   , _______   , _______   , _______   , _______     , _______     , _______
  ),

  [3] = LAYOUT_universal(
    KC_F1   , KC_F2     , KC_F3     , KC_F4     ,  KC_F5    ,                         KC_F6     , KC_F7     , KC_F8     , KC_F9     , KC_F10    ,
    RGB_MOD , RGB_HUI   , RGB_SAI   , RGB_VAI   ,  SCRL_DVI ,                         KC_LEFT   , KC_DOWN   , KC_UP     , KC_RGHT   , _______   ,
    RGB_RMOD, RGB_HUD   , RGB_SAD   , RGB_VAD   ,  SCRL_DVD ,                         _______   , CPI_D100  , CPI_I100  , _______   , KBC_SAVE  ,
    QK_BOOT , KBC_RST   , _______   , _______   ,  _______  , _______  , _______    , _______   , _______   , _______   , KBC_RST   , QK_BOOT
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    switch(get_highest_layer(remove_auto_mouse_layer(state, true))) {
        case 2:
            // Auto enable scroll mode when the highest layer is 2
            // remove_auto_mouse_target must be called to adjust state *before* setting enable
            state = remove_auto_mouse_layer(state, false);
            set_auto_mouse_enable(false);
            keyball_set_scroll_mode(true);
            break;
        default:
            set_auto_mouse_enable(true);
            keyball_set_scroll_mode(false);
            break;
    }
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

#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
void pointing_device_init_user(void) {
    set_auto_mouse_enable(true);
}
#endif

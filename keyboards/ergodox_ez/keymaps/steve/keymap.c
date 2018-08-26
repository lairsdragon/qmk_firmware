#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"

// A 'transparent' key code (that falls back to the layers below it).
#define ___ KC_TRANSPARENT

// A 'blocking' key code. Does nothing but prevent falling back to another layer.
#define XXX KC_NO

#define BASE 0
#define SYMB 1
#define GERM 2
#define MEDI 3

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  RGB_LAY,
  NAME,
  MAIL,
  WORK,
};

uint16_t showlayer = 1;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
  {
  
  [BASE] = LAYOUT_ergodox
  ( /* Left Hand */
   KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    ___,
   MO(GERM),KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
   KC_LSFT, DE_Y,    KC_X,    KC_C,    KC_V,    KC_B,    ALL_T(KC_NO),
   KC_LCTL, KC_LGUI, KC_LALT, TT(1),   TT(3),
			  
            ___,     ___,
                     ___,
   KC_SPC,  KC_BSPC, ___,
   
   /* Right Hand */
   KC_7,    KC_8,    KC_9,    KC_0,    DE_SS,   DE_ACUT, KC_BSPACE,
   ___,     DE_Z,    KC_U,    KC_I,    KC_O,    KC_P,    LT(GERM,DE_PLUS),
            KC_H,    KC_J,    KC_K,    KC_L,    DE_HASH, KC_ENTER,
   MEH_T(KC_NO), KC_N,    KC_M,    KC_COMMA,KC_DOT,  KC_UP,   KC_RSHIFT,
   KC_RALT,LT(1,DE_MINS),KC_LEFT,KC_DOWN,KC_RIGHT,
		       
   KC_PGUP,CTL_T(KC_ESCAPE),
   KC_PGDOWN,
   KC_DEL,  KC_DEL, KC_SPACE
   ),

  [SYMB] = LAYOUT_ergodox
  (
   KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
   ___,     DE_EXLM, DE_AT,   DE_LCBR, DE_RCBR, DE_PIPE, ___,
   ___,     DE_HASH, DE_DLR,  DE_LPRN, DE_RPRN, DE_GRV,
   ___,     DE_PERC, DE_CIRC, DE_LBRC, DE_RBRC, DE_TILD,___,
   ___,     ___,     ___,     ___,     ___,
   
   RGB_MOD, RGB_LAY,
   ___,
   RGB_VAD, RGB_VAI, ___,

   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   ___,
   ___,     KC_UP,   KC_7,    KC_8,    KC_9,    DE_ASTR,  ___,
            KC_DOWN, KC_4,    KC_5,    KC_6,    DE_PLUS,  ___,
   ___,     DE_AMPR, KC_1,    KC_2,    KC_3,    DE_BSLS,  ___,
                     ___,     DE_DOT,  KC_0,    DE_EQL,   ___,

   RGB_TOG,RGB_SLD,
   ___,
   ___,RGB_HUD,RGB_HUI
   ),

  [GERM] = LAYOUT_ergodox
  (
   DE_CIRC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,
   ___,     DE_AT,   NAME,    DE_EURO, MAIL,    ___,      ___,
   ___,     DE_AE,   DE_SS,   ___,     WORK,    ___,
   ___,     DE_LESS, DE_PIPE, DE_MORE, ___,     ___,      ___,
   ___,     ___,     ___,     ___,     ___,
		       
   ___,     ___,
   ___,
   ___,     ___,     ___,

   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   KC_DELETE,
   ___,     ___,     DE_UE,   ___,     DE_OE,   ___,      ___,
            ___,     ___,     ___,     ___,     ___,      ___,
   ___,     ___,     ___,     ___,     ___,     KC_PGUP,  ___,
   ___,     ___,     ___,     KC_PGDOWN,___,

   ___,     ___,
   ___,
   ___,     ___,     ___
   ),

  [MEDI] = LAYOUT_ergodox
  (
   ___,     ___,     ___,     ___,     ___,     ___,      ___,
   ___,     ___,     KC_MS_UP,___,  KC_MS_WH_UP,KC_MS_ACCEL0,___,
   ___,   KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,KC_MS_WH_DOWN,KC_MS_ACCEL1,
   ___,  KC_MS_BTN1,KC_MS_BTN3,KC_MS_BTN2, ___, KC_MS_ACCEL2,___,
   ___,     ___,     ___,     ___,     ___,
		       
   ___,     ___,
   ___,
   ___,     ___,     ___,

   VRSN,    ___,     ___,     ___,     ___, KC_AUDIO_MUTE,KC_AUDIO_VOL_UP,
   RESET,   ___,     ___,     ___,     ___,     ___,      KC_AUDIO_VOL_DOWN,
   ___,     ___,     ___,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_MEDIA_PLAY_PAUSE,
   ___,     ___,     ___,     ___,     ___,     KC_PGUP,  ___,
   ___,     ___,     ___,     KC_PGDOWN,___,
   ___,     ___,
   ___,
   ___,     KC_WFWD, KC_WWW_BACK
   ),
  };

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
  case 0:
    if (record->event.pressed) {
      SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
    }
    break;
  }
  return MACRO_NONE;
};

void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
  case EPRM:
    if (record->event.pressed) {
      eeconfig_init();
    }
    return false;
    break;
  case VRSN:
    if (record->event.pressed) {
      SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
    }
    return false;
    break;
  case NAME:
    if (record->event.pressed) {
      SEND_STRING ("Steffen Weinreich");
    }
    return false;
    break;
  case MAIL:
    if (record->event.pressed) {
      SEND_STRING ("steve"SS_RALT("q")"weinreich.org");
    }
    return false;
    break;
  case WORK:
    if (record->event.pressed) {
      SEND_STRING ("steffen.weinreich"SS_RALT("q")"mdex.de");
    }
    return false;
    break;
  case RGB_SLD:
    if (record->event.pressed) {
      rgblight_mode(1);
    }
    return false;
    break;
  case RGB_LAY:
    if (record->event.pressed) {
      showlayer ^= 1;
    }
    return false;
    break;  
  }
  return true;
}

void dim_rgblight_setrgb(uint8_t r, uint8_t g, uint8_t b)
{
  uint8_t val = rgblight_get_val();
  
  rgblight_setrgb((r*val)/256,(g*val)/256,(b*val)/256);
}

uint32_t layer_state_set_user(uint32_t state)
{  
  uint8_t layer = biton32(state);
  
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
  case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
    if (showlayer && rgblight_get_mode() == 1) {
      dim_rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
    }
#endif
    break;
  case 1:
    ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
    if (showlayer && rgblight_get_mode() == 1) {
      dim_rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
    }
#endif
    break;
  case 2:
    ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
    if (showlayer && rgblight_get_mode() == 1) {
      dim_rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
    }					      
#endif
    break;
  case 3:
    ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
    if (showlayer && rgblight_get_mode() == 1) {
      dim_rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
    }
#endif
    break;
  case 4:
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
    if (showlayer && rgblight_get_mode() == 1) {    
      dim_rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
    }					       
#endif
    break;
  case 5:
    ergodox_right_led_1_on();
    ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
    if (showlayer && rgblight_get_mode() == 1) {
      dim_rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
    }
#endif
    break;
  case 6:
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
    if (showlayer && rgblight_get_mode() == 1) {
      dim_rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
    }
#endif
    break;
  case 7:
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
    if (showlayer && rgblight_get_mode() == 1) {
      dim_rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
    }
#endif
    break;
  default:
    break;
  }
  return state;
};

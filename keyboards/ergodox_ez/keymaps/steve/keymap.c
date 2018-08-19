#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"


#include "keymap_german.h"

#include "keymap_nordic.h"



enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = KEYMAP(DE_CIRC,          KC_1,    KC_2,   KC_3,       KC_4,    KC_5,    KC_6,
	       LT(1,KC_TAB),     KC_Q,    KC_W,   KC_E,       KC_R,    KC_T,    KC_ESCAPE,
	       LT(1,KC_ESCAPE),  KC_A,    KC_S,   KC_D,       KC_F,    KC_G,
	       KC_RSHIFT,        DE_Y,    KC_X,   KC_C,       KC_V,    KC_B,    KC_TAB,
	       KC_LCTL,          KC_LALT, KC_END, KC_LGUI,    KC_LALT,
	                                          KC_ENTER,   KC_LGUI,
	                                                      KC_LALT,
	                   LT(1,KC_SPACE),   LT(4,KC_ESCAPE), KC_LCTL,
	        
	       KC_7,             KC_8,    KC_9,    KC_0,      DE_SS,   DE_ACUT, KC_DELETE,
	       KC_GRAVE,         DE_Z,    KC_U,    KC_I,      KC_O,    KC_P,    DE_PLUS,
	                         KC_H,    KC_J,    KC_K,      KC_L,    DE_HASH, KC_ENTER,
	       ALT_T(KC_ESCAPE), KC_N,    KC_M,    KC_COMMA,  KC_DOT,  DE_MINS, KC_RSHIFT,
	                                  KC_LCTL, KC_LALT,   KC_PGUP, KC_PGDOWN, TT(3),
	       KC_RGUI, KC_RALT,
	       KC_RALT,
	       KC_DELETE,MO(2),KC_BSPACE),

  [1] = KEYMAP(
	       KC_ESCAPE, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
	       KC_TRNS,   DE_AT,   KC_TRNS, DE_EURO, KC_TRNS, KC_TRNS, KC_TRNS,
	       KC_TRNS,   DE_AE,   DE_SS,   KC_TRNS, KC_TRNS, KC_TRNS,
	       KC_TRNS,   DE_PIPE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	       KC_LCTL,   KC_LGUI, KC_TRNS, KC_TRNS, KC_LALT, KC_TRNS, KC_TRNS,
	       KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,

	       KC_F7,     KC_F8,   KC_F9,     KC_F10,  KC_F11,   KC_F12,  KC_TRNS,
	       KC_TRNS,   KC_TRNS, DE_UE,     KC_TRNS, DE_OE,    KC_TRNS, KC_TRNS,
	                  KC_LEFT, KC_DOWN,   KC_UP,   KC_RIGHT, KC_TRNS, KC_TRNS,
	       KC_TRNS,   KC_HOME, KC_PGDOWN, KC_PGUP, KC_END,   KC_TRNS, KC_TRNS,
	       KC_TRNS,   KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
	       KC_TRNS,   KC_TRNS, KC_TRNS,   KC_TRNS),

  [2] = KEYMAP(
	       KC_TRNS, KC_F1,     KC_F2,          KC_F3,                KC_F4,      KC_F5,      KC_F6,
	       KC_TRNS, RALT(KC_Q),KC_NONUS_BSLASH,LSFT(KC_NONUS_BSLASH),LSFT(KC_6), KC_PLUS,    KC_TRNS,
	       KC_TRNS, LSFT(KC_RBRACKET),KC_0,    RALT(KC_NONUS_BSLASH),KC_GRAVE,   LSFT(KC_0), KC_TRNS,
	       KC_NONUS_BSLASH,LSFT(KC_5),RALT(KC_MINUS),KC_QUES,KC_RBRACKET,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_MS_BTN5,LSFT(KC_4),RALT(KC_MINUS),KC_MS_BTN4,
	       
	       KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,KC_F12,KC_TRNS,
	       KC_TRNS,KC_UNDS,LSFT(KC_7),LSFT(KC_8),LSFT(KC_9),RALT(KC_RBRACKET),KC_TRNS,
	       LSFT(KC_4),RALT(KC_MINUS),RALT(KC_7),RALT(KC_0),LSFT(KC_0),KC_TRNS,
	       KC_TRNS,RALT(KC_Q),KC_QUES,RALT(KC_8),RALT(KC_9),KC_GRAVE,
	       KC_TRNS,RALT(KC_NONUS_BSLASH),KC_NONUS_BSLASH,LSFT(KC_NONUS_BSLASH),KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS),

  [3] = KEYMAP(
	       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
	       KC_TRNS,KC_SCOLON,KC_EQUAL,KC_COMMA,KC_MINUS,KC_DOT,KC_TRNS,KC_TRNS,KC_SLASH,KC_GRAVE,KC_LBRACKET,KC_BSLASH,KC_RBRACKET,KC_TRNS,KC_QUOTE,KC_NONUS_HASH,KC_NONUS_BSLASH,KC_EXLM,KC_AT,KC_TRNS,KC_TRNS,KC_LCBR,KC_RCBR,KC_PIPE,KC_HASH,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_DLR,KC_LPRN,KC_RPRN,KC_PERC,KC_CIRC,KC_TRNS,KC_AMPR,KC_ASTR,KC_PLUS,KC_TILD,KC_PLUS,KC_TRNS,KC_TRNS,KC_TILD,KC_COLN,KC_UNDS,KC_DQUO,KC_LABK,KC_TRNS,KC_RABK,KC_QUES,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS),

  [4] = KEYMAP(KC_TRNS,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_F6,KC_TRNS,KC_TRNS,KC_MS_UP,KC_TRNS,KC_MS_WH_UP,KC_TRNS,KC_TRNS,KC_TRNS,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,KC_MS_WH_DOWN,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_MS_BTN1,KC_TRNS,KC_TRNS,KC_F7,KC_TRNS,KC_TRNS,KC_KP_SLASH,KC_KP_ASTERISK,KC_KP_MINUS,KC_TRNS,KC_TRNS,KC_0,KC_7,KC_8,KC_9,KC_KP_PLUS,KC_TRNS,KC_0,KC_4,KC_5,KC_6,KC_KP_PLUS,KC_TRNS,KC_TRNS,KC_0,KC_1,KC_2,KC_3,KC_KP_ENTER,KC_TRNS,KC_0,KC_0,KC_COMMA,KC_KP_ENTER,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_MS_BTN1,KC_MS_BTN2),

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
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;
    
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
	ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }
    return state;

};

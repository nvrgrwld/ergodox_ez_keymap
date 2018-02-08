#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define ALT_TAB   M(KC_ALT_TAB)   // macro for alt-tab
#define ALT_STAB  M(KC_ALT_STAB) // macro for alt-shift-tab
#define CTL_TAB   M(KC_CTL_TAB)   // macro ctrl tab
#define CTL_STAB  M(KC_CTL_STAB)  // macro ctrl shift tab
#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define WNAV 3 // window navigation
enum custom_keycodes {
  CUSTOM_P1 = SAFE_RANGE, // can always be here
  CUSTOM_P2,
  CUSTOM_P3,
  CUSTOM_EMAIL,
  EPRM,
  VRSN,
  RGB_SLD,
  DYNAMIC_MACRO_RANGE,
};
enum {
 TD_ESC_AS_JJ = 0
};
#include "dynamic_macro.h"

enum macro_keycodes{
    KC_ALT_TAB,
    KC_ALT_STAB,
    KC_CTL_TAB,
    KC_CTL_STAB,
};
// Tap Dance
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_AS_JJ] = ACTION_TAP_DANCE_DOUBLE(KC_J, KC_ESC)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ESC  |   1  |   2  |   3  |   4  |   5  | To 1 |           | To 2 |   6  |   7  |   8  |   9  |   0  | BKSPC  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   Q  |   W  |   E  |   R  |   T  | VolU |           | Next |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |A/Ctrl| S/L3 |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |    ; | Enter  |-
 * |--------+------+------+------+------+------| VolD |           | PLAY |------+------+------+------+------+--------|
 * | LCtrl  |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1| LCtrl|  Win | LCtrl| Alt  |                                       |[/L1  |   ]  |  '"  |   -  |   =  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Del  |SysRq |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Space |
 *                                 |/L1   |ace   | End  |       | PgDn | /L2    |/L1   |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default

// left hand
        KC_ESCAPE,         KC_1,           KC_2,     KC_3,      KC_4,          KC_5,        TG(SYMB),
        KC_TAB,            KC_Q,           KC_W,     KC_E,      KC_R,          KC_T,        KC_VOLU,
        KC_LSFT,           CTL_T(KC_A), LT(WNAV,KC_S),KC_D,     KC_F,          KC_G,
        KC_LCTL,           CTL_T(KC_Z),    KC_X,     KC_C,      KC_V,          KC_B,        KC_VOLD,
        LT(SYMB,KC_GRV),   KC_LCTL,        KC_LGUI,  KC_LCTL,   KC_LALT,

																				KC_DEL, KC_PSCR,
																				KC_HOME,
																				LT(SYMB,KC_SPC), KC_BSPC,KC_END,

        // right hand
        TG(MDIA),          KC_6,           KC_7,     KC_8,      KC_9,          KC_0,             KC_BSPC,
        KC_MNXT,           KC_Y,           KC_U,     KC_I,      KC_O,          KC_P,             KC_BSLS,
                           KC_H,   TD(TD_ESC_AS_JJ), KC_K,      KC_L,          KC_SCLN,          KC_ENT,
        KC_MPLY,           KC_N,           KC_M,     KC_COMM,   KC_DOT,        CTL_T(KC_SLSH),   KC_RSFT,
                               LT(SYMB,KC_LBRC),     KC_RBRC,   KC_QUOT,       KC_MINS,          KC_EQL,

        KC_LALT,CTL_T(KC_ESC),
        KC_PGUP,
        KC_PGDN,LT(SYMB,KC_TAB), LT(SYMB,KC_SPC)
),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |  _   |   -  |   (  |   )  |   |  |      |           |      |   ~  |  `   |Alt/TB|SHf/TB|      |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |  +   |   =  |   {  |   }  |   `  |------|           |------|      | Left | Down |  UP  |Right |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |  "   |   '  |   [  |   ]  |   ~  |      |           |      |      |      | Left | Down |Right |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      | To 2 |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      | To 0 |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
        KC_TRNS,      KC_F1,     KC_F2,     KC_F3,     KC_F4,       KC_F5,       KC_TRNS, 
        KC_TRNS,      KC_UNDS,   KC_MINS,   KC_LPRN,   KC_RPRN,     KC_PIPE,     KC_TRNS,
        KC_TRNS,      KC_PLUS,   KC_EQL,    KC_LCBR,   KC_RCBR,     KC_GRV,
        KC_TRNS,      KC_DQT ,   KC_QUOT,   KC_LBRC,   KC_RBRC,     KC_TILD,     KC_TRNS,
        KC_TRNS,      KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   


																  KC_TRNS,   TO(MDIA),   
																  KC_TRNS
																  KC_TRNS,   KC_TRNS,   TO(BASE),

        // right hand
        KC_TRNS,    KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,     KC_F11,   
        KC_TRNS,    KC_TILD,   KC_GRV     KC_EQL,    KC_TRNS,   KC_TRNS,    KC_F12,   
        KC_TRNS,    KC_LEFT,   KC_DOWN,   KC_UP,     KC_RIGHT,  KC_TRNS,   
        KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_LEFT,   KC_DOWN,   KC_RIGHT,   KC_TRNS,   
        KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,


        KC_TRNS,    KC_TRNS,   
        KC_TRNS,   
        KC_TRNS,    KC_TRNS,    KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        | CST1 | CST2 | CST3 | CST4 |      |      |           |      |PLYMC1|PLYMC1|      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |RCDMC1|RCDMC2|RCDSTP|      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      | MsSd | MsSd | MsSd |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |  Lclk|      |  Rclk|      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
*                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | To 1 |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      | To 0 |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
 KC_TRNS,   CUSTOM_P1,    CUSTOM_P2,     CUSTOM_P3,    CUSTOM_EMAIL, KC_TRNS, KC_TRNS,
 KC_TRNS,   KC_TRNS,      KC_TRNS,       KC_MS_U,      KC_TRNS,      KC_TRNS, KC_TRNS,
 KC_TRNS,   KC_TRNS,      KC_MS_L,       KC_MS_D,      KC_MS_R,      KC_TRNS,
 KC_TRNS,   KC_TRNS,      KC_TRNS,       KC_TRNS,      KC_TRNS,      KC_TRNS, KC_TRNS,
 KC_TRNS,   KC_TRNS,      KC_TRNS,       KC_BTN1,      KC_BTN2,
																		 KC_TRNS, KC_TRNS,
																				  TO(SYMB),
																KC_TRNS, KC_TRNS, TO(BASE),
    
    // right hand
 KC_TRNS,   DYN_MACRO_PLAY1,DYN_MACRO_PLAY2, KC_TRNS,       KC_TRNS,      KC_TRNS, KC_TRNS,
 KC_TRNS,   DYN_REC_START1, DYN_REC_START2,  DYN_REC_STOP,  KC_TRNS,      KC_TRNS, KC_TRNS,
 KC_TRNS,   KC_ACL0,        KC_ACL1,         KC_ACL2,       KC_TRNS,      KC_MPLY,
 KC_TRNS,   KC_TRNS,        KC_TRNS,         KC_MPRV,       KC_MNXT,      KC_TRNS, KC_TRNS,
                            KC_VOLU,         KC_VOLD,       KC_MUTE,      KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK,
),
/* Keymap 4: Window Navigation
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |CTRSTB|CTR_TB|      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |ALTSTB|ALT_TB|      |------|           |------|      |  <   |  \/  |  /\  |   >  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | To 1 |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      | To 0 |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[WNAV] = LAYOUT_ergodox(
       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,         KC_TRNS,       KC_TRNS,       KC_TRNS,
       KC_TRNS,       KC_TRNS,       KC_TRNS,       CTL_STAB,CTL_TAB,KC_TRNS,       KC_TRNS,
       KC_TRNS,       KC_TRNS,       KC_TRNS,       ALT_STAB,ALT_TAB,KC_TRNS,
       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,         KC_TRNS,       KC_TRNS,       KC_TRNS,
       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,         KC_TRNS,
																			       KC_TRNS,       KC_TRNS,
																						          TO(SYMB),
																	  KC_TRNS,     KC_TRNS,      TO(BASE),
    // right hand
       KC_TRNS,        KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
       KC_TRNS,        KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
       KC_TRNS,        KC_LEFT,       KC_DOWN,       KC_UP,         KC_RIGHT,      KC_TRNS,
       KC_TRNS,        KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
                                      KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
       KC_TRNS,       KC_TRNS,
       KC_TRNS,
       KC_TRNS,       KC_TRNS,       KC_TRNS
)
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case KC_ALT_TAB:
        return (record->event.pressed ? MACRO( D(LALT), D(TAB), END) : MACRO( U(TAB), END) );
      break;
    case KC_ALT_STAB:
        return (record->event.pressed ? MACRO( D(LALT), D(LSFT), D(TAB), END) : MACRO( U(LSFT), U(TAB), END) );
      break;
    case KC_CTL_TAB:
        return (record->event.pressed ? MACRO( D(LCTRL), D(TAB), END) : MACRO( U(TAB), END) );
      break;
    case KC_CTL_STAB:
        return (record->event.pressed ? MACRO( D(LCTRL), D(LSFT), D(TAB), END) : MACRO( U(LSFT), U(TAB), END) );

  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  if(!process_record_dynamic_macro(keycode, record)){
    return false;
  }

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
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
    case CUSTOM_P1:
      if (record->event.pressed) {
        SEND_STRING ("greg.netland@realityengineering.com" );
      }
      return false;
      break; 
    case CUSTOM_P2:
      if (record->event.pressed) {
        SEND_STRING ("yetAnotherCannedString");
      }
      return false;
      break;
    case CUSTOM_P3:
      if (record->event.pressed) {
        SEND_STRING ("yetAnotherCannedString" );
      }
      return false;
      break;
    case CUSTOM_EMAIL:
      if (record->event.pressed) {
        SEND_STRING ("yetAnotherCannedString");
      }
      return false;
      break;
  }
  return true;
}



// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
          rgblight_init();
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

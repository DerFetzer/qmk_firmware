#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"

#define KC_UNDO LCTL(KC_Z)
#define KC_CUT LCTL(KC_X)
#define KC_COPY LCTL(KC_C)
#define KC_PASTE LCTL(KC_V)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define MOON_LED_LEVEL LED_LEVEL

// Shorter codes
#define KC_MUTE KC_AUDIO_MUTE 
#define KC_V_D KC_AUDIO_VOL_DOWN
#define KC_V_U KC_AUDIO_VOL_UP
#define KC_BR_D KC_BRIGHTNESS_DOWN
#define KC_BR_U KC_BRIGHTNESS_UP
#define KC_PREV KC_MEDIA_PREV_TRACK
#define KC_NEXT KC_MEDIA_NEXT_TRACK
#define KC_PLAY KC_MEDIA_PLAY_PAUSE
#define T_L_COL TOGGLE_LAYER_COLOR

// colors
#define PETROL 136,204,163
#define ORANGE 25,255,237
#define GREEN 63,156,208
#define BLUE 154,255,255
#define RED 0,239,185

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  DE_LSPO,
  DE_RSPC,
};

enum layer_names {
  BONE,
  SYMBOLS,
  CONTROLS,
  MEDIA,
  QWERTZ,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BONE]     = LAYOUT_moonlander(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           WEBUSB_PAIR,             _______,        KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           _______,        
    KC_TAB,         KC_J,           KC_D,           KC_U,           KC_A,           KC_X,           DE_GRV,                  TG(3),          KC_P,           KC_H,           KC_L,           KC_M,           KC_W,           DE_SS,          
    MO(1),          KC_C,           KC_T,           KC_I,           KC_E,           KC_O,           DE_ACUT,                 TG(4),          KC_B,           KC_N,          KC_R,           KC_S,           KC_G,           LT(1,KC_Q),     
    KC_LSHIFT,      KC_F,           KC_V,           DE_UDIA,        DE_ADIA,        DE_ODIA,                                                 DE_Y,           LT(0,DE_Z),     LT(0,KC_COMMA), LT(0,KC_DOT),   KC_K,           KC_RSHIFT,      
    KC_LCTRL,       KC_LGUI,        LALT(KC_LCTRL), KC_LALT,        TT(2),                          KC_PLAY,                 _______,                        TT(2),          KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       
                                                                    KC_SPACE,       KC_DELETE,      _______,                 KC_RCTRL,       KC_BSPACE,      KC_ENTER
  ),
  [SYMBOLS]  = LAYOUT_moonlander(
    _______,        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          _______,                 KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         
    _______,        DE_DEG,         DE_UNDS,        DE_LBRC,        DE_RBRC,        DE_CIRC,        _______,                 _______,        DE_EXLM,        DE_LABK,        DE_RABK,        DE_EQL,         DE_AMPR,        DE_AT,          
    _______,        DE_BSLS,        DE_SLSH,        DE_LCBR,        DE_RCBR,        DE_ASTR,        _______,                 _______,        DE_QUES,        DE_LPRN,        DE_RPRN,        DE_MINS,        DE_COLN,        _______,        
    _______,        DE_HASH,        DE_DLR,         DE_PIPE,        DE_TILD,        DE_GRV,                                                  DE_PLUS,        DE_PERC,        DE_DQUO,        DE_QUOT,        DE_SCLN,        DE_EURO,        
    _______,        _______,        _______,        _______,        _______,                        _______,                 _______,                        _______,        _______,        _______,        _______,        _______,        
                                                                    _______,        _______,        _______,                 _______,        _______,        _______
  ),
  [CONTROLS] = LAYOUT_moonlander(
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                 _______,        _______,        _______,        DE_SLSH,        DE_ASTR,        _______,        _______,        
    _______,        KC_PGUP,        KC_BSPACE,      KC_UP,          KC_DELETE,      KC_PGDOWN,      _______,                 _______,        _______,        KC_7,           KC_8,           KC_9,           DE_PLUS,        DE_MINS,        
    _______,        KC_HOME,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_END,         _______,                 _______,        _______,        KC_4,           KC_5,           KC_6,           KC_COMMA,       KC_DOT,         
    _______,        _______,        _______,        _______,        KC_ENTER,       _______,                                                 KC_0,           KC_1,           KC_2,           KC_3,           DE_SCLN,        DE_SLSH,        
    _______,        _______,        _______,        _______,        _______,                        _______,                 _______,                        _______,        KC_0,           KC_KP_DOT,      _______,        _______,        
                                                                    _______,        _______,        _______,                 _______,        _______,        _______
  ),
  [MEDIA]    = LAYOUT_moonlander(
    AU_TOG,         KC_MUTE,        KC_V_D,         KC_V_U,         KC_BR_D,        KC_BR_U,        _______,                 _______,        RGB_HUI,        RGB_VAI,        RGB_SPI,        RGB_SAI,        _______,        RESET,          
    MU_TOG,         _______,        KC_MS_BTN2,     KC_MS_UP,       KC_MS_BTN1,     _______,        _______,                 _______,        RGB_HUD,        RGB_VAD,        RGB_SPD,        RGB_SAD,        _______,        _______,        
    MU_MOD,         _______,        KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    _______,        _______,                 _______,        _______,        KC_MS_BTN1,     KC_MS_BTN2,     _______,        _______,        _______,        
    _______,        _______,        _______,        KC_MS_WH_UP,    KC_MS_BTN3,     _______,                                                 _______,        KC_PREV,        KC_NEXT,        _______,        _______,        _______,        
    _______,        _______,        KC_MS_WH_LEFT,  KC_MS_WH_DOWN,  KC_MS_WH_RIGHT,                 _______,                 T_L_COL,        _______,        _______,        _______,        _______,        _______,        
                                                                    _______,        _______,        _______,                 RGB_TOG,        RGB_MOD,        RGB_SLD
  ),
  [QWERTZ]   = LAYOUT_moonlander(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_INT1,                 KC_INT8,        KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           _______,        
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_INT2,                 KC_INT9,        DE_Z,           KC_U,           KC_I,           KC_O,           KC_P,           DE_UDIA,          
    KC_CAPSLOCK,    KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_INT3,                 _______,        KC_H,           KC_J,           KC_K,           KC_L,           DE_ODIA,        DE_ADIA,          
    KC_LSHIFT,      DE_Y,           KC_X,           KC_C,           KC_V,           KC_B,                                                    KC_N,           KC_M,           KC_COMMA,       KC_DOT,         RSFT_T(DE_MINS),KC_RSHIFT,      
    KC_LCTRL,       KC_LGUI,        KC_LALT,        KC_RALT,        KC_RCTRL,                       KC_INT4,                 KC_INT7,                        KC_NUMLOCK,     KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       
                                                                    KC_ENTER,       KC_DELETE,      KC_INT5,                 KC_INT6,        KC_BSPACE,      KC_SPACE
  ),
};

/*
g_led_config

left
{   0,  5, 10, 15, 20, 25, 29 },
{   1,  6, 11, 16, 21, 26, 30 },
{   2,  7, 12, 17, 22, 27, 31 },
{   3,  8, 13, 18, 23, 28, __ },
{   4,  9, 14, 19, 24, __, __ },
{  32, 33, 34, 35, __, __, __ }

right
{  65, 61, 56, 51, 46, 41, 36 },
{  66, 62, 57, 52, 47, 42, 37 },
{  67, 63, 58, 53, 48, 43, 38 },
{  __, 64, 59, 54, 49, 44, 39 },
{  __, __, 60, 55, 50, 45, 40 },
{  __, __, __, 71, 70, 69, 68 },
*/

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

void set_led_color(int i, int h, int s, int v) {
  HSV hsv = {
    .h = h,
    .s = s,
    .v = v,
  };
  RGB rgb = {
    .r = 0,
    .g = 0,
    .b = 0,    
  };
  float f = 0.0;
  if (hsv.h || hsv.s || hsv.v) {
    rgb = hsv_to_rgb( hsv );
    f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
  }
  if (i < 0) {
    rgb_matrix_set_color_all( f * rgb.r, f * rgb.g, f * rgb.b );
  } else {
    rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
  }
}

void rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_led_color(-1, PETROL);
      break;
    case 1:
      set_led_color(-1, ORANGE);
      break;
    case 2:
      set_led_color(-1, 0, 0, 0);
      // Arrows
      set_led_color(12, RED);
      set_led_color(16, RED);
      set_led_color(17, RED);
      set_led_color(22, RED);
      // Num
      set_led_color(57, BLUE);
      set_led_color(52, BLUE);
      set_led_color(47, BLUE);
      set_led_color(58, BLUE);
      set_led_color(53, BLUE);
      set_led_color(48, BLUE);
      set_led_color(59, BLUE);
      set_led_color(54, BLUE);
      set_led_color(49, BLUE);
      set_led_color(55, BLUE);
      break;
    case 3:
      set_led_color(-1, RED);
      // Mouse
      set_led_color(12, GREEN);
      set_led_color(16, GREEN);
      set_led_color(17, GREEN);
      set_led_color(22, GREEN);
      // Wheel
      set_led_color(14, BLUE);
      set_led_color(18, BLUE);
      set_led_color(19, BLUE);
      set_led_color(24, BLUE);
      break;
    case 4:
      set_led_color(-1, GREEN);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // ORYX
    case DE_LSPO:
      perform_space_cadet(record, keycode, KC_LSFT, KC_LSFT, KC_8);
      return false;
    case DE_RSPC:
      perform_space_cadet(record, keycode, KC_LSFT, KC_LSFT, KC_9);
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    // custom
    case LT(0,KC_DOT):
      if (record->tap.count && record->event.pressed) {
        tap_code16(KC_DOT);
      } else if (record->event.pressed) {
        tap_code16(C(KC_X)); // Intercept hold function to send Ctrl-X
      }
      return false;
    case LT(0,DE_Z):
      if (record->tap.count && record->event.pressed) {
        tap_code16(DE_Z);
      } else if (record->event.pressed) {
        tap_code16(C(KC_C)); // Intercept hold function to send Ctrl-C
      }
      return false;
    case LT(0,KC_COMMA):
      if (record->tap.count && record->event.pressed) {
        tap_code16(KC_COMMA);
      } else if (record->event.pressed) {
        tap_code16(C(KC_V)); // Intercept hold function to send Ctrl-V
      }
      return false;
  }
  return true;
}



#include QMK_KEYBOARD_H

enum {
    COLEMAK = 0,
    QWERTY,
    GAME,
    MACRO
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
		[COLEMAK] = LAYOUT(
			KC_GESC,		KC_1,		KC_2,		KC_3,		KC_4,		KC_5,		KC_6,		KC_7,		KC_8,		KC_9,		KC_0,		KC_MINS,	KC_EQL,		KC_BSPC,	RGB_TOG,
		    KC_TAB,			KC_Q,		KC_W,		KC_F,		KC_P,		KC_G,		KC_J,		KC_L,		KC_U,		KC_Y,		KC_SCLN,	KC_LBRC,	KC_RBRC,	KC_BSLASH,	KC_MEDIA_PLAY_PAUSE,
			MO(3),			KC_A,		KC_R,		KC_S,		KC_T,		KC_D,		KC_H,		KC_N,		KC_E,		KC_I,		KC_O,		KC_QUOT,	KC_ENT,					TG(1),
		    KC_LSFT,		KC_Z,		KC_X,		KC_C,		KC_V,		KC_B,		KC_B,		KC_K,		KC_M,		KC_COMM,	KC_DOT,		KC_SLSH,	TO(2),		KC_UP,
		    KC_LGUI,					KC_LCTL,	LT(3, KC_SPC),			KC_LALT,    			LT(3, KC_SPC),			KC_RALT,            				KC_LEFT,	KC_DOWN,	KC_RIGHT
		),
		[QWERTY] = LAYOUT(
			KC_GESC,		KC_1,		KC_2,		KC_3,  		KC_4,  		KC_5,		KC_6, 		KC_7,  		KC_8,		KC_9,		KC_0,		KC_MINS,	KC_EQL,		KC_BSPC,	RGB_TOG,
		    KC_TRNS,		KC_Q,		KC_W,		KC_E,  		KC_R,  		KC_T,		KC_Y,		KC_U,  		KC_I,		KC_O,		KC_P,		KC_LBRC,	KC_RBRC,	KC_BSLASH,	KC_MEDIA_PLAY_PAUSE,
			KC_LCTL,		KC_A,		KC_S,		KC_D,  		KC_F,  		KC_G,		KC_H,		KC_J,  		KC_K,		KC_L,		KC_SCLN,	KC_QUOT,	KC_ENT,					TG(1),
		    KC_TRNS,		KC_Z,		KC_X,		KC_C,  		KC_V,		KC_B,		KC_B,		KC_N,  		KC_M,		KC_COMM,	KC_DOT,		KC_SLSH,	TO(2),		KC_UP, 
		    KC_GRAVE,					KC_LGUI,	LT(3, KC_SPC),			KC_LALT,				LT(3, KC_SPC),			KC_RALT, 							KC_LEFT,	KC_DOWN,	KC_RIGHT
		),
		[GAME] = LAYOUT(
			KC_GESC,		KC_1,		KC_2,		KC_3,  		KC_4,  		KC_5,		KC_6, 		KC_7,  		KC_8,		KC_9,		KC_0,		KC_MINS,	KC_EQL,		KC_BSPC,	RGB_TOG,
		    KC_TRNS,		KC_Q,		KC_W,		KC_E,  		KC_R,  		KC_T,		KC_Y,		KC_U,  		KC_I,		KC_O,		KC_P,		KC_LBRC,	KC_RBRC,	KC_BSLASH,	KC_MEDIA_PLAY_PAUSE,
			KC_NO,			KC_A,		KC_S,		KC_D,  		KC_F,  		KC_G,		KC_H,		KC_J,  		KC_K,		KC_L,		KC_SCLN,	KC_QUOT,	KC_ENT,					TO(0),
		    KC_TRNS,		KC_Z,		KC_X,		KC_C,  		KC_V,		KC_B,		KC_B,		KC_N,  		KC_M,		KC_COMM,	KC_DOT,		KC_SLSH,	TO(1),		KC_UP, 
		    KC_LALT,					KC_LCTL,	KC_SPC,					KC_TRNS,				KC_SPC,					KC_RALT, 							KC_LEFT,	KC_DOWN,	KC_RIGHT
		),
		[MACRO] = LAYOUT(
			KC_TRNS,		KC_F1,		KC_F2,		KC_F3,  	KC_F4,   	KC_F5,		KC_F6, 		KC_F7,		KC_F8,		KC_F9,		KC_F10,		KC_F11,		KC_F12,		KC_TRNS,	KC_TRNS,
		    KC_TRNS,		KC_TRNS,	KC_TRNS,	KC_TRNS,  	KC_TRNS,  	KC_TRNS,	KC_TRNS,	KC_TRNS,	RGB_SPI,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_MEDIA_PLAY_PAUSE,
			KC_CAPSLOCK,	KC_TRNS,	RGB_SAI,	KC_TRNS,  	KC_TRNS,  	KC_TRNS,	RGB_HUI,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,				KC_MUTE,
		    KC_TRNS,		KC_TRNS,	KC_TRNS,	KC_CALC,	RGB_VAI,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	TO(1),					KC_AUDIO_VOL_UP, 
		    KC_TRNS,					KC_TRNS,	KC_TRNS,				KC_TRNS,				KC_TRNS,				KC_TRNS, 							KC_MEDIA_PREV_TRACK,	KC_AUDIO_VOL_DOWN,		KC_MEDIA_NEXT_TRACK
		)
 };

void rgb_matrix_indicators_user(void) {
    uint8_t layer = biton32(layer_state);

    switch (layer) {
        case 0:           
			rgb_matrix_set_color(14, 240, 70, 240);  
			rgb_matrix_set_color(29, 240, 70, 240);      
			rgb_matrix_set_color(43, 240, 70, 240); 
            break;
        case 1:
            rgb_matrix_set_color(14, 0,	255, 127); 
			rgb_matrix_set_color(29, 0,	255, 127); 
            rgb_matrix_set_color(43, 0,	255, 127); 
            break;
		case 2:
            rgb_matrix_set_color(14, 255, 0, 55); 
			rgb_matrix_set_color(29, 255, 0, 55); 
            rgb_matrix_set_color(43, 255, 0, 55); 
            break;
        case 3:
		 	rgb_matrix_set_color_all(0, 0, 0);
			for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
				for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
					uint8_t index = g_led_config.matrix_co[row][col];

					if (index >= 13 && index <= 66 && index != NO_LED && keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
						rgb_matrix_set_color(index, 255, 255, 0);
					}
				}
			}
			break;   
	}
	if (host_keyboard_led_state().caps_lock) {
		rgb_matrix_set_color(30, 255, 0, 0); 
	}
}

// uint8_t g_key_hit[DRIVER_LED_TOTAL];
// void rgb_matrix_solid_reactive(void) {
// 	for ( int i=0; i<DRIVER_LED_TOTAL; i++ ) {
// 		uint16_t offset2 = g_key_hit[i]<<2;
// 		offset2 = (offset2<=130) ? (130-offset2) : 0;

// 		HSV hsv = { .h = 160+offset2, .s = 255, .v = RGB_MATRIX_STARTUP_VAL };
// 		RGB rgb = hsv_to_rgb( hsv );
// 		rgb_matrix_set_color( i, rgb.r, rgb.g, rgb.b );
// 	}
// }

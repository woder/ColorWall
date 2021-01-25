/*
 * UserSettings.h
 *
 *  Created on: Jan. 24, 2021
 *      Author: raphael
 */

#ifndef USERSETTINGS_H_
#define USERSETTINGS_H_

// LED settings
#define DATA_PIN    4
//#define CLK_PIN   4
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB

//Strip/panel settings
#define NUM_LEDS    252
#define NUM_PANELS 6
#define NUM_LEDS_PER_PANEL 42

//Master brightness control - usually no reason to change
#define BRIGHTNESS          255

//The draw rate, do not change unless you know what you are doing!
#define DRAW_DELAY   20




#endif /* USERSETTINGS_H_ */

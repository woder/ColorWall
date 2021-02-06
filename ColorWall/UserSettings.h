/*
 * UserSettings.h
 *
 *  Created on: Jan. 24, 2021
 *      Author: raphael
 */

#ifndef USERSETTINGS_H_
#define USERSETTINGS_H_

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// LED settings
#define DATA_PIN    4
//#define CLK_PIN   4
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB

//Strip/panel settings
#define NUM_LEDS    252
#define NUM_PANELS 6
#define NUM_LEDS_PER_PANEL 42

//The draw rate, do not change unless you know what you are doing!
#define DRAW_DELAY   20

static const char *ssid =  "Banana";     // replace with your wifi ssid and wpa2 key
static const char *pass =  "fruit4336";
const IPAddress ip(192, 168, 3, 6);  //the IP address of the device
const IPAddress gateway(192, 168, 1, 1); //the gateway
const IPAddress subnet(255, 255, 0, 0); //the subnet

#endif /* USERSETTINGS_H_ */

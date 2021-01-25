/*
 * Solid.cpp
 *
 *  Created on: Jan. 24, 2021
 *      Author: raphael
 */

#include "Solid.h"

Solid::Solid(Panel** panels, CRGB* leds){
	this->panels = panels;
	this->leds = leds;
};

void Solid::run(){
	for(int i = 0; i < NUM_PANELS; i++) {
		CRGB solid;
		CHSV hsv(panels[i]->getHue(), 255, 255);
		hsv2rgb_rainbow(hsv, solid);
		panels[i]->setSolid(solid);
	}
}

//no settings to get for this one
void Solid::getSettings(DynamicJsonDocument& root) {}


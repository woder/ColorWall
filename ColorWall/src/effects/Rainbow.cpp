/*
 * Rainbow.cpp
 *
 *  Created on: Jan. 26, 2021
 *      Author: raphael
 */

#include "Rainbow.h"

Rainbow::Rainbow(Panel** panels, CRGB* leds, EffectSettings& set) {
	this->leds = leds;
	this->panels = panels;
	this->effSet = &set;
	this->speed = effSet->value1;
}

void Rainbow::run() {
	uint8_t initialHue = (initialHue16 / 16);
	uint8_t deltaHue = (deltaHue16 / 16);

	uint8_t resetPoint = 255;
	int delta = speed;
	if(effSet->value2 == 1) {
		resetPoint = 0;
		delta = delta * -1;
	}

	if(initialHue == resetPoint) {
		initialHue16 = 0;
		deltaHue16 += 1;

		if(deltaHue16 > (40*16)) {
			deltaHue16 = 7;
		}
	}

	fill_rainbow(leds, NUM_LEDS, initialHue, deltaHue);

	initialHue16 += delta;
}

void Rainbow::updateSettings(DynamicJsonDocument& root, EffectSettings& set) {
	JsonObjectConst values = root["settings"];
	if(!values.isNull()) {
		set.value1 = values["speed"];
		set.value2 = values["direction"]; //0 = forward 1 = backwards
	}
}

void Rainbow::setDefaults(EffectSettings& settings) {
	settings.value1 = DEFAULT_SPEED;
	settings.value2 = DEFAULT_DIRECTION;
}

void Rainbow::getSettings(DynamicJsonDocument& root) {
	JsonObject sets = root.createNestedObject("settings");
	sets["speed"] = effSet->value1;
	sets["direction"] = effSet->value2;
}





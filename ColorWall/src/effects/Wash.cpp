/*
 * Wash.cpp
 *
 *  Created on: Jan. 24, 2021
 *      Author: raphael
 */

#include "Wash.h"

Wash::Wash(Panel** panels, CRGB* leds, EffectSettings& set) {
	this->panels = panels;
	this->leds = leds;
	this->effSet = &set;
	baseHue16 = effSet->value2;
	speed = effSet->value1;
}

void Wash::run() {
	memset8( leds, 0, NUM_LEDS * sizeof(CRGB));

	for(int i = 0; i < NUM_PANELS; i++) {
		if(pos16 >= (NUM_LEDS_PER_PANEL * 16)) {
			pos16 = 0; //reset if we hit the end
			baseHue16 = (baseHue16 + effSet->value3) % (4080); //increment the base hue
		}
		// 4080 = 255 (number of hues) * 16 (increments)
		int currentHue = (baseHue16 + i*4*16) % (4080);
		int nextHue = (baseHue16 + (i+1)*4*16) % (4080);
		panels[i]->drawWash(pos16, currentHue, nextHue, 255);
	}

	pos16 += speed;
}

void Wash::updateSettings(DynamicJsonDocument& root, EffectSettings& set) {
	JsonObjectConst values = root["settings"];
	if(!values.isNull()) {
		set.value1 = values["speed"];
		set.value2 = values["baseHue"];
		set.value3 = values["deltaHue"];
	}
}

void Wash::setDefaults(EffectSettings& settings) {
	settings.value1 = DEFAULT_SPEED;
	settings.value2 = DEFAULT_BASE_HUE;
	settings.value3 = DEFAULT_DELTA_HUE;
}

void Wash::getSettings(DynamicJsonDocument& root) {
	JsonObject sets = root.createNestedObject("settings");
	sets["speed"] = effSet->value1;
	sets["baseHue"] = effSet->value2;
	sets["deltaHue"] = effSet->value3;
}



/*
 * Colory.cpp
 *
 *  Created on: Jan. 24, 2021
 *      Author: raphael
 */

#include "Colory.h"

Colory::Colory(Panel** panels, CRGB* leds, EffectSettings& set) {
	this->panels = panels;
	this->leds = leds;
	this->effSet = &set;
}

void Colory::run() {
	memset8( leds, 0, NUM_LEDS * sizeof(CRGB));
	for(int i = 0; i < NUM_PANELS; i++) {
		uint32_t future = panels[i]->getCurrentPixel()+effSet->value1;
		if(future >= (NUM_LEDS_PER_PANEL * 16)) {
			future = 0;
		}
		panels[i]->setCurrentPixel(future);

		panels[i]->drawMovingColors(future, panels[i]->getHue());
	}
}

void Colory::updateSettings(DynamicJsonDocument& root, EffectSettings& set) {
	JsonObjectConst values = root["settings"];
	if(!values.isNull()) {
		set.value1 = values["speed"];
	}
}

void Colory::setDefaults(EffectSettings& settings) {
	settings.value1 = DEFAULT_SPEED;
}

void Colory::getSettings(DynamicJsonDocument& root) {
	JsonObject sets = root.createNestedObject("settings");
	sets["speed"] = effSet->value1;
}


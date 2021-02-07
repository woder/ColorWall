<<<<<<< HEAD
/*
 * Smooth.cpp
 *
 *  Created on: Jan. 24, 2021
 *      Author: raphael
 */

#include "Smooth.h"

Smooth::Smooth(Panel** panels, CRGB* leds, EffectSettings& set) {
	this->panels = panels;
	this->leds = leds;
	this->effSet = &set;
}

void Smooth::run() {
	memset8( leds, 0, NUM_LEDS * sizeof(CRGB));
	for(int i = 0; i < NUM_PANELS; i++) {
		uint32_t future = panels[i]->getCurrentPixel()+effSet->value1;
		if(future >= (NUM_LEDS_PER_PANEL * 16)) {
			future = 0;
		}
		panels[i]->setCurrentPixel(future);

		panels[i]->drawAABar(future, effSet->value2, panels[i]->getHue(), panels[i]->getBrightness());
	}
}

/**
 * value1 = speed
 * value2 = width
 */
void Smooth::updateSettings(DynamicJsonDocument& root, EffectSettings& set) {
	JsonObjectConst values = root["settings"];
	if(!values.isNull()) {
		set.value1 = values["speed"];
		set.value2 = values["width"];
	}
}

void Smooth::setDefaults(EffectSettings& settings) {
	settings.value1 = DEFAULT_SPEED;
	settings.value2 = DEFAULT_WIDTH;
}

void Smooth::getSettings(DynamicJsonDocument& root) {
	JsonObject sets = root.createNestedObject("settings");
	sets["speed"] = effSet->value1;
	sets["width"] = effSet->value2;
}

=======
/*
 * Smooth.cpp
 *
 *  Created on: Jan. 24, 2021
 *      Author: raphael
 */

#include "Smooth.h"

Smooth::Smooth(Panel** panels, CRGB* leds, EffectSettings& set) {
	this->panels = panels;
	this->leds = leds;
	this->effSet = &set;
}

void Smooth::run() {
	memset8( leds, 0, NUM_LEDS * sizeof(CRGB));
	for(int i = 0; i < NUM_PANELS; i++) {
		uint32_t future = panels[i]->getCurrentPixel()+effSet->value1;
		if(future >= (NUM_LEDS_PER_PANEL * 16)) {
			future = 0;
		}
		panels[i]->setCurrentPixel(future);

		panels[i]->drawAABar(future, effSet->value2, panels[i]->getHue(), panels[i]->getBrightness());
	}
}

/**
 * value1 = speed
 * value2 = width
 */
void Smooth::updateSettings(DynamicJsonDocument& root, EffectSettings& set) {
	JsonObjectConst values = root["settings"];
	if(!values.isNull()) {
		set.value1 = values["speed"];
		set.value2 = values["width"];
	}
}

void Smooth::setDefaults(EffectSettings& settings) {
	settings.value1 = DEFAULT_SPEED;
	settings.value2 = DEFAULT_WIDTH;
}

void Smooth::getSettings(DynamicJsonDocument& root) {
	JsonObject sets = root.createNestedObject("settings");
	sets["speed"] = effSet->value1;
	sets["width"] = effSet->value2;
}

>>>>>>> f921643cc5b9ef1872189451b63dd200ab91528d

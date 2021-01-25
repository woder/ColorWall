/*
 * Bpm.cpp
 *
 *  Created on: Jan. 24, 2021
 *      Author: raphael
 */

#include "Bpm.h"

Bpm::Bpm(Panel** panels, CRGB* leds, EffectSettings& set) {
	this->panels = panels;
	this->leds = leds;
	this->effSet = &set;
}

void Bpm::run() {
	  //CRGBPalette16 palette = PartyColors_p;
	  CRGBPalette16 palette = RainbowColors_p;
	  uint8_t beat = beatsin8(effSet->value1, 64, 255);
	  for( int i = 0; i < NUM_LEDS; i++) { //9948
	    leds[i] = ColorFromPalette(palette, gHue+(i*2), beat-gHue+(i*10));
	  }
}

void Bpm::updateSettings(DynamicJsonDocument& root, EffectSettings& set) {
	JsonObjectConst values = root["settings"];
	if(!values.isNull()) {
		set.value1 = values["bpm"];
	}
}

void Bpm::setDefaults(EffectSettings& settings) {
	settings.value1 = DEFAULT_BPM;
}

void Bpm::getSettings(DynamicJsonDocument& root) {
	JsonObject sets = root.createNestedObject("settings");
	sets["bpm"] = effSet->value1;
}

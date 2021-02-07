<<<<<<< HEAD
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
	  if(effSet->value2 == 1) {
		  palette = PartyColors_p;
	  } else if(effSet->value2 == 2) {
		  palette = HeatColors_p;
	  } else if(effSet->value2 == 3) {
		  palette = OceanColors_p;
	  }

	  uint8_t beat = beatsin8(effSet->value1, 64, 255);
	  for( int i = 0; i < NUM_LEDS; i++) { //9948
	    leds[i] = ColorFromPalette(palette, gHue+(i*2), beat-gHue+(i*10));
	  }
}

void Bpm::updateSettings(DynamicJsonDocument& root, EffectSettings& set) {
	JsonObjectConst values = root["settings"];
	if(!values.isNull()) {
		set.value1 = values["bpm"];
		set.value2 = values["style"];
	}
}

void Bpm::setDefaults(EffectSettings& settings) {
	settings.value1 = DEFAULT_BPM;
	settings.value2  = DEFAULT_STYLE;
}

void Bpm::getSettings(DynamicJsonDocument& root) {
	JsonObject sets = root.createNestedObject("settings");
	sets["bpm"] = effSet->value1;
	sets["style"] = effSet->value2;
}
=======
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
	  if(effSet->value2 == 1) {
		  palette = PartyColors_p;
	  } else if(effSet->value2 == 2) {
		  palette = HeatColors_p;
	  } else if(effSet->value2 == 3) {
		  palette = OceanColors_p;
	  }

	  uint8_t beat = beatsin8(effSet->value1, 64, 255);
	  for( int i = 0; i < NUM_LEDS; i++) { //9948
	    leds[i] = ColorFromPalette(palette, gHue+(i*2), beat-gHue+(i*10));
	  }
}

void Bpm::updateSettings(DynamicJsonDocument& root, EffectSettings& set) {
	JsonObjectConst values = root["settings"];
	if(!values.isNull()) {
		set.value1 = values["bpm"];
		set.value2 = values["style"];
	}
}

void Bpm::setDefaults(EffectSettings& settings) {
	settings.value1 = DEFAULT_BPM;
	settings.value2  = DEFAULT_STYLE;
}

void Bpm::getSettings(DynamicJsonDocument& root) {
	JsonObject sets = root.createNestedObject("settings");
	sets["bpm"] = effSet->value1;
	sets["style"] = effSet->value2;
}
>>>>>>> f921643cc5b9ef1872189451b63dd200ab91528d

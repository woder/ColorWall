/*
 * Settings.cpp
 *
 *  Created on: Jan. 22, 2021
 *      Author: raphael
 */
#include "Settings.h"

Settings::Settings() {
	//calculate the size of our settings using the maximums specified in the header file
	//!!!!  this is critical for settings to work correctly! "size" must be exactly the correct number of bytes used by the structs or it won't work
	unsigned int size = 6 + (MAX_EFFECTS*8) + (MAX_PANELS*4);
	EEPROM.begin(size);

	settings.effects.setStorage(effectStorage, MAX_EFFECTS);
	settings.panels.setStorage(panelStorage, MAX_PANELS);
}

void Settings::loadSettings() {
	StoredSettings loaded;

	EEPROM.get(addr, loaded);

	Serial.print("Version: ");
	Serial.println(loaded.version, DEC);
	if(loaded.version != VERSION) {
		//either an older version or invalid data but in any case we can't use it
		setDefaults();
		saveSettings();
		return;
	}

	settings.panelNum = loaded.panelNum;
	if(loaded.powered == 1) {
		settings.powered = true;
	} else {
		settings.powered = false;
	}
	settings.brightness = loaded.brightness;
	settings.currentEffect = loaded.currentEffect;
	memcpy(effectStorage, loaded.effects, sizeof(loaded.effects));
	memcpy(panelStorage, loaded.panels, sizeof(loaded.panels));

	//if the second stored effect's ID is not 1 then the values are wrong and must be initialized
	if(settings.effects.at(1).effectId != 1) {
		Serial.println("Setting defaults!");
		setDefaults();
	}

}


void Settings::saveSettings() {
	//copy data from live settings into the store struct
	StoredSettings saved;

	saved.version = settings.version;
	saved.panelNum = settings.panelNum;
	if(settings.powered) {
		saved.powered = 1;
	} else {
		saved.powered = 0;
	}
	saved.powered = settings.powered;
	saved.brightness = settings.brightness;
	saved.currentEffect = settings.currentEffect;
	memcpy(saved.effects, effectStorage, sizeof(effectStorage));
	memcpy(saved.panels, panelStorage, sizeof(panelStorage));

	EEPROM.put(addr, saved);
	EEPROM.commit();
}

void Settings::setDefaults() {
	for(int i = 0; i != static_cast<uint8_t>(Effects::Last); i++) {
		EffectSettings *effSet = &settings.effects.at(i);
		effSet->effectId = i;
		EffectManager::setDefaults(i, *effSet);
	}
}

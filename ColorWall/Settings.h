/*
 * Settings.h
 *
 *  Created on: Jan. 22, 2021
 *      Author: raphael
 */

#ifndef SETTINGS_H_
#define SETTINGS_H_

#include <Arduino.h>
#include <Vector.h>
#include <EEPROM.h>
#include <ArduinoJson.h>
#include "effects/Effects.h"
#include "effects/EffectManager.h"
#include "UserSettings.h"


#define VERSION 2

#define MAX_EFFECTS 10
#define MAX_PANELS 20

class Settings {
	private:
		struct StoredSettings {
			uint16_t version;
			uint8_t panelNum;
			uint8_t currentEffect;
			uint8_t effectSize = MAX_EFFECTS;
			EffectSettings effects[MAX_EFFECTS];
			uint8_t panelsSize = MAX_PANELS;
			PanelSettings panels[MAX_PANELS];
		};
		struct LiveSettings {
			uint16_t version = VERSION;
			uint8_t panelNum = MAX_PANELS;
			uint8_t currentEffect = 0;
			Vector<EffectSettings> effects;
			Vector<PanelSettings> panels;
		};
		EffectSettings effectStorage[MAX_EFFECTS];
		PanelSettings panelStorage[MAX_PANELS];
		LiveSettings settings;
		uint addr = 0; //the EPPROM address
		void setDefaults();

	public:
		Settings();
		void loadSettings();
		void saveSettings();

		uint16_t getVersion() {
			return settings.version;
		}

		uint8_t getPanelNum() {
			return settings.panelNum;
		}

		void setCurrentEffect(uint8_t currentEffect) {
			settings.currentEffect = currentEffect;
		}

		uint8_t getCurrentEffect() {
			return settings.currentEffect;
		}

		Vector<EffectSettings> getEffects() {
			return settings.effects;
		}

		Vector<PanelSettings> getPanels() {
			return settings.panels;
		}

};



#endif /* SETTINGS_H_ */
/*
 * EffectManager.cpp
 *
 *  Created on: Jan. 24, 2021
 *      Author: raphael
 */

#include "EffectManager.h"

void EffectManager::setDefaults(uint8_t effectId, EffectSettings& settings) {
	switch(static_cast<Effects>(effectId)) {
		case Effects::Smooth:
			Smooth::setDefaults(settings);
			break;
		case Effects::Wash:
			Wash::setDefaults(settings);
			break;
		case Effects::Colory:
			Colory::setDefaults(settings);
			break;
		case Effects::Bpm:
			Bpm::setDefaults(settings);
	}
}

void EffectManager::updateSettings(uint8_t effectId, DynamicJsonDocument& root, EffectSettings& set) {
	switch(static_cast<Effects>(effectId)) {
		case Effects::Smooth:
			Smooth::updateSettings(root, set);
			break;
		case Effects::Wash:
			Wash::updateSettings(root, set);
			break;
		case Effects::Colory:
			Colory::updateSettings(root, set);
			break;
		case Effects::Bpm:
			Bpm::updateSettings(root, set);
			break;
	}
}


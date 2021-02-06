/*
 * Effects.h
 *
 *  Created on: Jan. 24, 2021
 *      Author: raphael
 */

#ifndef EFFECTS_EFFECTS_H_
#define EFFECTS_EFFECTS_H_

#include <Arduino.h>


enum class Effects : uint8_t {
	Smooth,
	Bpm,
	Solid,
	Colory,
	Wash,
	Rainbow,
	Last
};

struct PanelSettings {
	uint8_t panelId;
	uint8_t hue;
	uint8_t sat;
	uint8_t brightness;
};
struct EffectSettings {
	uint16_t effectId;
	uint16_t value1;
	uint16_t value2;
	uint16_t value3;
};


#endif /* EFFECTS_EFFECTS_H_ */

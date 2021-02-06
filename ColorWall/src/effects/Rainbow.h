/*
 * Rainbow.h
 *
 *  Created on: Jan. 26, 2021
 *      Author: raphael
 */

#ifndef EFFECTS_RAINBOW_H_
#define EFFECTS_RAINBOW_H_

#include "Effect.h"

#define DEFAULT_SPEED 2
#define DEFAULT_DIRECTION 0

class Rainbow : public Effect {
	private:
		Panel** panels;
		CRGB* leds;
		uint32_t initialHue16 = 0;
		uint32_t deltaHue16 = 112;
	public:
		Rainbow(Panel** panels, CRGB* leds, EffectSettings& set);
		~Rainbow(){}
		void run();
		static void updateSettings(DynamicJsonDocument& root, EffectSettings& set);
		static void setDefaults(EffectSettings& settings);
		void getSettings(DynamicJsonDocument& root);
};



#endif /* EFFECTS_RAINBOW_H_ */

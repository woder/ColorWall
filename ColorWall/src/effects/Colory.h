/*
 * Colory.h
 *
 *  Created on: Jan. 24, 2021
 *      Author: raphael
 */

#ifndef EFFECTS_COLORY_H_
#define EFFECTS_COLORY_H_

#include "Effect.h"

#define DEFAULT_SPEED 2

class Colory : public Effect {
	private:
		Panel** panels;
		CRGB* leds;
	public:
		Colory(Panel** panels, CRGB* leds, EffectSettings& set);
		~Colory(){}
		void run();
		static void updateSettings(DynamicJsonDocument& root, EffectSettings& set);
		static void setDefaults(EffectSettings& settings);
		void getSettings(DynamicJsonDocument& root);
};



#endif /* EFFECTS_COLORY_H_ */

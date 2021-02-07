<<<<<<< HEAD
/*
 * Wash.h
 *
 *  Created on: Jan. 24, 2021
 *      Author: raphael
 */

#ifndef EFFECTS_WASH_H_
#define EFFECTS_WASH_H_

#include "Effect.h"

#define DEFAULT_BASE_HUE 0
#define DEFAULT_DELTA_HUE 16
#define DEFAULT_SPEED 5

class Wash : public Effect {
	private:
		Panel** panels;
		CRGB* leds;
		uint32_t baseHue16 = 0;
		uint32_t pos16 = 0;
	public:
		Wash(Panel** panels, CRGB* leds, EffectSettings& set);
		~Wash(){}
		void run();
		static void updateSettings(DynamicJsonDocument& root, EffectSettings& set);
		static void setDefaults(EffectSettings& settings);
		void getSettings(DynamicJsonDocument& root);
};



#endif /* EFFECTS_WASH_H_ */
=======
/*
 * Wash.h
 *
 *  Created on: Jan. 24, 2021
 *      Author: raphael
 */

#ifndef EFFECTS_WASH_H_
#define EFFECTS_WASH_H_

#include "Effect.h"

#define DEFAULT_BASE_HUE 0
#define DEFAULT_DELTA_HUE 16
#define DEFAULT_SPEED 5

class Wash : public Effect {
	private:
		Panel** panels;
		CRGB* leds;
		uint32_t baseHue16 = 0;
		uint32_t pos16 = 0;
	public:
		Wash(Panel** panels, CRGB* leds, EffectSettings& set);
		~Wash(){}
		void run();
		static void updateSettings(DynamicJsonDocument& root, EffectSettings& set);
		static void setDefaults(EffectSettings& settings);
		void getSettings(DynamicJsonDocument& root);
};



#endif /* EFFECTS_WASH_H_ */
>>>>>>> f921643cc5b9ef1872189451b63dd200ab91528d

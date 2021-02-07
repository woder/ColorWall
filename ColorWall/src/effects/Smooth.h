<<<<<<< HEAD
/*
 * Smooth.h
 *
 *  Created on: Jan. 24, 2021
 *      Author: raphael
 */

#ifndef EFFECTS_SMOOTH_H_
#define EFFECTS_SMOOTH_H_

#include "Effect.h"

#define DEFAULT_SPEED 2
#define DEFAULT_WIDTH 10

class Smooth : public Effect {
	private:
		Panel** panels;
		CRGB* leds;
	public:
		Smooth(Panel** panels, CRGB* leds, EffectSettings& set);
		~Smooth(){}
		void run();
		static void updateSettings(DynamicJsonDocument& root, EffectSettings& set);
		static void setDefaults(EffectSettings& settings);
		void getSettings(DynamicJsonDocument& root);
};



#endif /* EFFECTS_SMOOTH_H_ */
=======
/*
 * Smooth.h
 *
 *  Created on: Jan. 24, 2021
 *      Author: raphael
 */

#ifndef EFFECTS_SMOOTH_H_
#define EFFECTS_SMOOTH_H_

#include "Effect.h"

#define DEFAULT_SPEED 2
#define DEFAULT_WIDTH 10

class Smooth : public Effect {
	private:
		Panel** panels;
		CRGB* leds;
	public:
		Smooth(Panel** panels, CRGB* leds, EffectSettings& set);
		~Smooth(){}
		void run();
		static void updateSettings(DynamicJsonDocument& root, EffectSettings& set);
		static void setDefaults(EffectSettings& settings);
		void getSettings(DynamicJsonDocument& root);
};



#endif /* EFFECTS_SMOOTH_H_ */
>>>>>>> f921643cc5b9ef1872189451b63dd200ab91528d

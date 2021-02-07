<<<<<<< HEAD
/*
 * Bpm.h
 *
 *  Created on: Jan. 24, 2021
 *      Author: raphael
 */

#ifndef EFFECTS_BPM_H_
#define EFFECTS_BPM_H_

#include "Effect.h"

#define DEFAULT_BPM 62
#define DEFAULT_STYLE 0

class Bpm : public Effect {
	private:
		Panel** panels;
		CRGB* leds;
		uint8_t gHue = 0;
	public:
		Bpm(Panel** panels, CRGB* leds, EffectSettings& set);
		~Bpm(){}
		void run();
		static void updateSettings(DynamicJsonDocument& root, EffectSettings& set);
		static void setDefaults(EffectSettings& settings);
		void getSettings(DynamicJsonDocument& root);
};



#endif /* EFFECTS_BPM_H_ */
=======
/*
 * Bpm.h
 *
 *  Created on: Jan. 24, 2021
 *      Author: raphael
 */

#ifndef EFFECTS_BPM_H_
#define EFFECTS_BPM_H_

#include "Effect.h"

#define DEFAULT_BPM 62
#define DEFAULT_STYLE 0

class Bpm : public Effect {
	private:
		Panel** panels;
		CRGB* leds;
		uint8_t gHue = 0;
	public:
		Bpm(Panel** panels, CRGB* leds, EffectSettings& set);
		~Bpm(){}
		void run();
		static void updateSettings(DynamicJsonDocument& root, EffectSettings& set);
		static void setDefaults(EffectSettings& settings);
		void getSettings(DynamicJsonDocument& root);
};



#endif /* EFFECTS_BPM_H_ */
>>>>>>> f921643cc5b9ef1872189451b63dd200ab91528d

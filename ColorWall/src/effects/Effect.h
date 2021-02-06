/*
 * Effect.h
 *
 * Defines an effect interface that will be implemented by each effect
 *
 *  Created on: Jan. 24, 2021
 *      Author: raphael
 */

#ifndef EFFECT_H_
#define EFFECT_H_

#include <FastLED.h>
#include "Effects.h"
#include "../../Panel.h"
#include <ArduinoJson.h>
#include "../../UserSettings.h"

class Effect {
	protected:
		uint32_t speed = 0;
		EffectSettings* effSet = 0;
	public:
		Effect(){}
		virtual ~Effect(){}
		virtual void run() = 0;
		virtual void getSettings(DynamicJsonDocument& root) = 0;

		uint32_t getSpeed() const {
			return speed;
		}

		void setSpeed(uint32_t speed = 0) {
			this->speed = speed;
		}
};



#endif /* EFFECT_H_ */

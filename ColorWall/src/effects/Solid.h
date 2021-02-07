<<<<<<< HEAD
/*
 * Solid.h
 *
 *  Created on: Jan. 24, 2021
 *      Author: raphael
 */

#ifndef EFFECTS_SOLID_H_
#define EFFECTS_SOLID_H_

#include "Effect.h"

class Solid : public Effect {
	private:
		Panel** panels;
		CRGB* leds;
	public:
		Solid(Panel** panels, CRGB* leds);
		~Solid(){}
		void run();
		void getSettings(DynamicJsonDocument& root);
};



#endif /* EFFECTS_SOLID_H_ */
=======
/*
 * Solid.h
 *
 *  Created on: Jan. 24, 2021
 *      Author: raphael
 */

#ifndef EFFECTS_SOLID_H_
#define EFFECTS_SOLID_H_

#include "Effect.h"

class Solid : public Effect {
	private:
		Panel** panels;
		CRGB* leds;
	public:
		Solid(Panel** panels, CRGB* leds);
		~Solid(){}
		void run();
		void getSettings(DynamicJsonDocument& root);
};



#endif /* EFFECTS_SOLID_H_ */
>>>>>>> f921643cc5b9ef1872189451b63dd200ab91528d

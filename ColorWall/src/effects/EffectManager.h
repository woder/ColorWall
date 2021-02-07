<<<<<<< HEAD
/*
 * EffectManager.h
 *
 *  Created on: Jan. 24, 2021
 *      Author: raphael
 */

#ifndef EFFECTS_EFFECTMANAGER_H_
#define EFFECTS_EFFECTMANAGER_H_

#include <ArduinoJson.h>
#include "Effects.h"
#include "Smooth.h"
#include "Wash.h"
#include "Solid.h"
#include "Wash.h"
#include "Bpm.h"
#include "Colory.h"
#include "Rainbow.h"

class EffectManager {
	public:
		static void setDefaults(uint8_t effectId, EffectSettings& settings);
		static void updateSettings(uint8_t effectId, DynamicJsonDocument& root, EffectSettings& set);
};



#endif /* EFFECTS_EFFECTMANAGER_H_ */
=======
/*
 * EffectManager.h
 *
 *  Created on: Jan. 24, 2021
 *      Author: raphael
 */

#ifndef EFFECTS_EFFECTMANAGER_H_
#define EFFECTS_EFFECTMANAGER_H_

#include <ArduinoJson.h>
#include "Effects.h"
#include "Smooth.h"
#include "Wash.h"
#include "Solid.h"
#include "Wash.h"
#include "Bpm.h"
#include "Colory.h"
#include "Rainbow.h"

class EffectManager {
	public:
		static void setDefaults(uint8_t effectId, EffectSettings& settings);
		static void updateSettings(uint8_t effectId, DynamicJsonDocument& root, EffectSettings& set);
};



#endif /* EFFECTS_EFFECTMANAGER_H_ */
>>>>>>> f921643cc5b9ef1872189451b63dd200ab91528d

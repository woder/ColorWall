/*
 * Panel.h
 *
 *  Created on: Jan. 20, 2021
 *      Author: raphael
 */

#ifndef PANEL_H_
#define PANEL_H_

#include <Arduino.h>
#include <FastLED.h>

class Panel {
  private:
	int pin;
    int startNum;
    int endNum;
    CRGB* leds;
    uint32_t currentPixel = 0;
    uint8_t hue = 0;
    uint8_t sat = 255;
    uint8_t brightness = 255;


  public:
    Panel(int pin, int startNum, int endNum, CRGB* leds);
    void init();
    void setSolid(CRGB& color);
    void setNextPixel(CRGB& color);
    void setPixel(CRGB& color, int pixel);
    void clock();
    int getLEDNum();
    void drawAABar(int pos16, int width, uint8_t hue, uint8_t brightness = 255);
    void drawMovingColors(int pos16, uint8_t hue);
    void drawWash(int pos16, uint32_t hue, uint32_t nextHue, uint8_t brightness);

	uint32_t getCurrentPixel() const {
		return currentPixel;
	}

	void setCurrentPixel(uint32_t currentPixel = 0) {
		this->currentPixel = currentPixel;
	}

	uint8_t getHue() const {
		return hue;
	}

	void setHue(uint8_t hue) {
		this->hue = hue;
	}

	uint8_t getBrightness() const {
		return brightness;
	}

	void setBrightness(uint8_t brightness = 255) {
		this->brightness = brightness;
	}

	uint8_t getSat() const {
		return sat;
	}

	void setSat(uint8_t sat = 255) {
		this->sat = sat;
	}
};


#endif /* PANEL_H_ */

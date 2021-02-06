/*
 * Panel.cpp
 *
 *  Created on: Jan. 20, 2021
 *      Author: raphael
 */

#include "Panel.h"

Panel::Panel(int pin, int startNum, int endNum, CRGB* leds) {
	this->pin = pin;
	this->startNum = startNum;
	this->endNum = endNum;
	this->leds = leds;
}


void Panel::init() {

}

int32_t Panel::getLEDNum() {
	// the counting system starts at led 1 so we must add 1 since normal math starts at 0
	int ledNum = endNum - startNum;
	return ledNum;
}

void Panel::setSolid(CRGB& color) {
	for(int32_t i = startNum; i < endNum; i++) {
		this->leds[i] = color;
	}
}

void Panel::setNextPixel(CRGB& color) {
	this->leds[startNum + currentPixel] = color;
	currentPixel = (currentPixel + 1) % getLEDNum();
}

void Panel::setPixel(CRGB& color, int pixel) {
	this->leds[startNum + pixel] = color;
}

void Panel::drawAABar(int pos16, int width, uint8_t hue, uint8_t brightness) {
	int b = (pos16 / 16) + startNum;
	uint8_t fraction = pos16 & 0x0F;

	uint8_t firstPixBrightness = brightness - (fraction * 16);
	uint8_t lastPixBrightness = brightness - firstPixBrightness;

	uint8_t bright;
	for(int i = 0; i <= width; i++) {
		if(i == 0) {
			//the first pixel
			bright = firstPixBrightness;
		} else if(i == width) {
			//the last pixel
			bright = lastPixBrightness;
		} else {
			//a pixel in the middle
			bright = brightness;
		}

		// kind of a hack to prevent the AA logic from turning LEDs on while the brightness is 0
		if(brightness < 3) {
			bright = brightness;
		}

		this->leds[b] += CHSV(hue, sat, bright);
		b++;
		if(b == (getLEDNum()+startNum)) {
			b = startNum;
		}
	}
}

void Panel::drawMovingColors(int pos16, uint8_t hue) {
	int p = (pos16 / 16);
	int b = p + startNum;
	uint8_t fraction = pos16 & 0x0F;

	uint8_t firstPixel = hue - (fraction * 16);
	uint8_t lastPixel = hue - firstPixel;

	uint8_t fhue;
	for(int i = 0; i <= getLEDNum(); i++) {
		int val = (p-i)*2;
		fhue = hue + val;

		this->leds[b] += CHSV(fhue, 255, this->brightness);
		b++;
		if(b == (getLEDNum()+startNum)) {
			b = startNum;
		}
	}
}

void Panel::drawWash(int pos16, uint32_t hue, uint32_t nextHue, uint8_t brightness) {
	int p = (pos16 / 16);
	uint8_t fraction = pos16 & 0x0F;

	uint8_t firstPixBrightness = brightness - (fraction * 16);
	uint8_t lastPixBrightness = brightness - firstPixBrightness;

	uint8_t fhue;
	uint8_t bright;
	for(int i = 0; i <= getLEDNum(); i++) {
		bright = brightness;
		if(i < p) {
			fhue = (nextHue / 16);
		} else {
			fhue = (hue / 16);
		}

		this->leds[i + startNum] = CHSV(fhue, 255, this->brightness);
	}

}

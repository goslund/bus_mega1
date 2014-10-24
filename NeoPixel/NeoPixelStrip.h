#ifndef NEOPIXELSTRIP_H
#define NEOPIXELSTRIP_H

#include <Adafruit_NeoPixel.h>
#include <MemoryFree.h>

//#include "NeoPixel.h"

class NeoPixelStrip {
private:
	Adafruit_NeoPixel* strip;
	uint8_t pin_num;
	uint8_t num_pixels;
public: 
	NeoPixelStrip() {

	}


	void init(uint16_t num_pixels, uint8_t pin_num, uint8_t t=NEO_GRB + NEO_KHZ800) {
		this->strip = new Adafruit_NeoPixel(num_pixels, pin_num, t);
		this->pin_num = pin_num;
		this->num_pixels = num_pixels;
		strip->begin();
		strip->show();
		strip->setBrightness(255);
		//rainbow(1);
	}

	void rainbow(uint8_t wait);
	void colorWipe(uint32_t c, uint8_t wait);
	uint32_t Wheel(byte WheelPos);
	void setPixelColor(uint8_t i, uint8_t r, uint8_t g, uint8_t b);
	uint8_t getSize();

};
#endif /* NEOPIXELSTRIP_H */ 
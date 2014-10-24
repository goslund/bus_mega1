#ifndef NEOPIXEL_H
#define NEOPIXEL_H

#include "NeoPixelStrip.h"

class NeoPixelStrip;

class NeoPixel {
private:
	NeoPixelStrip* strip;
	int pixel_num;
	byte r;
	byte g;
	byte b;
	int wait;
	int last_change;

public:
	NeoPixel() {
		this->strip = NULL;
		this->pixel_num = 0;
		this->wait = 1000;
		this->last_change = 0;
	}

	void setPixelNum(uint8_t pixel_num) {
		this->pixel_num = pixel_num;
	}

	void setStrip(NeoPixelStrip* strip) {
		this->strip = strip;
	}

	char* getStatus() {
		return "helloworld";
	}

	NeoPixel(NeoPixelStrip* strip, int pixel_num) {
		this->strip = strip;
		this->pixel_num = pixel_num;
		this->wait = 10;
		this->last_change = 0;
		r=0, g=0, b=0;
		//strip->rainbow(1);
	}

	void check() {
		Serial.print("Strip: ");
		Serial.println((char*) strip);
		Serial.println(strip->getSize());
		Serial.println("----------");
	}

	void setPixelColor(int r, int g, int b) {
		// Serial.print("pixel_num: ");
		// Serial.println(pixel_num);
		this->r = r;
		this->g = g;
		this->b = b;
		strip->setPixelColor(pixel_num, this->r, this->g, this->b);
	}

	int getR() {
		return r;
	}

	int getG() {
		return g;
	}

	int getB() {
		return b;
	}

	int getPixelNum() {
		return pixel_num;
	}

	void progressiveLoop();
};

#endif /* NEOPIXEL_H */


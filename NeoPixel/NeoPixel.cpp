#include "NeoPixel.h"

void NeoPixel::progressiveLoop() {
	int now = millis();
	int delay = now - last_change;

	//delay(1000);
	if (delay >= wait) {
		this->r = (r++) % 255;
		this->g = (g++) % 255;
		this->b = (b++) % 255;
		strip->setPixelColor(pixel_num, this->r, this->g, this->b);
		last_change = millis();
	}	
}
#include "NeoPixelStrip.h"

void NeoPixelStrip::rainbow(uint8_t wait) {
  uint16_t i, j;

  	for(j=0; j<256; j++) {
	    for(i=0; i<strip->numPixels(); i++) {
	      this->strip->setPixelColor(i, Wheel((i+j) & 255));
	    }
    	this->strip->show();
    	delay(wait);
  	}
}

void NeoPixelStrip::colorWipe(uint32_t c, uint8_t wait) {
		for(uint16_t i=0; i<strip->numPixels(); i++) {
	    	strip->setPixelColor(i, c);
	      	strip->show();
	      	delay(wait);
	  	}
	}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t NeoPixelStrip::Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
   return strip->Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else if(WheelPos < 170) {
    WheelPos -= 85;
   return strip->Color(0, WheelPos * 3, 255 - WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip->Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }

}

void NeoPixelStrip::setPixelColor(uint8_t i, uint8_t r, uint8_t g, uint8_t b) {
 	strip->setPixelColor(i, r, g, b);	
	strip->show();
}

uint8_t NeoPixelStrip::getSize() {
	return num_pixels;
}
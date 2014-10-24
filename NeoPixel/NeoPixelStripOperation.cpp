#include "NeoPixelStripOperation.h"
#include <MemoryFree.h>

void NeoPixelStripRainbow::loop() {
	int now = millis();
	int delay = now - last_color_change;
	
	if (delay >= wait) {
		for (i=1; i<strip->numPixels(); i++) {
			this->strip->setPixelColor(i, Wheel((i+j) & 255));
		}
		strip->show();
		this->last_color_change = millis();
	j = (j++) & 255;
	}
}

uint32_t NeoPixelStripOperation::Wheel(byte WheelPos) {
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
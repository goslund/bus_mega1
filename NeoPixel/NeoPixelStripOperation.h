#include <Adafruit_NeoPixel.h>

#ifndef NEOPIXELSTRIPOPERATION_H
#define NEOPIXELSTRIPOPERATION_H

class NeoPixelStripOperation {
public:
	NeoPixelStripOperation(Adafruit_NeoPixel* strip_) {
		this->strip = strip_;
	}
	uint32_t Wheel(byte wheelPos);
protected:
	Adafruit_NeoPixel* strip;
};


#define STATE_WAITING 0
#define STATE_CHANGE_COLOR 1

class NeoPixelStripRainbow : public NeoPixelStripOperation {
public:
	typedef NeoPixelStripOperation super;
	NeoPixelStripRainbow(Adafruit_NeoPixel* strip_, int wait):super(strip_) {
		i = 0;
		j = 0;
		this->wait = wait;
		state = STATE_WAITING;
		last_color_change = millis();
	}

	

	void loop();
	
private:
	int wait;
	int last_color_change;
	int state;
	int i, j;
	

};	

#endif /* NEOPIXELSTRIPOPERATION_H */
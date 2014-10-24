#ifndef NEOPIXELSTRIPS_H
#define NEOPIXELSTRIPS_H
#include "NeoPixelStrip.h"

class NeoPixelStrips {
public:
	
	static NeoPixelStrips* getInstance();

private:
	NeoPixelStrips() {};
	NeoPixelStrip* strips[];
	static NeoPixelStrips* instance;
};

#endif /* NEOPIXELSTRIPS_H */
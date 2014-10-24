#include "NeoPixelStrips.h"

NeoPixelStrips* NeoPixelStrips::getInstance() {
	if (!instance) {
		instance = new NeoPixelStrips;
	}
	return instance;
}
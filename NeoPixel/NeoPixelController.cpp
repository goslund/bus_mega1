#include "NeoPixelController.h"


NeoPixelController* NeoPixelController::instance = NULL;

NeoPixelController* NeoPixelController::getInstance() {
	if (!instance) {
		instance = new NeoPixelController;
	}
	return instance;
}


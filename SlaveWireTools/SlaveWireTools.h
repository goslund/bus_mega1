#ifndef SLAVEWIRETOOLS_H
#define SLAVEWIRETOOLS_H
#include <SPI.h>
#include <Wire.h>
#include "../constants.h"
#include "../NeoPixel/NeoPixelStrips.h"

class SlaveWireTools {
public:
	
	//static singleton was the only way to get this to work as a callback...
	static void receiveEvent(int howMany);
	
	//singleton method
	static SlaveWireTools* getInstance();
	
private:

	SlaveWireTools() {
		//start twi
		Wire.begin(TWI_DEVICE_NUMBER);

		//register callback
		Wire.onReceive(SlaveWireTools::receiveEvent);
	}

	//the singleton instance
	static SlaveWireTools* instance;

	//the message buffer
	char message[128];

	void parseMessage();
};

#endif /* SLAVEWIRETOOLS_H */
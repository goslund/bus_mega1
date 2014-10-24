#include <Arduino.h>
#include <Stream.h>
#include <SPI.h>
#include <string.h>
#include <Adafruit_NeoPixel.h>
#include "constants.h"
#include <Wire.h>
#include "SlaveWireTools/SlaveWireTools.h"
#include "NeoPixel/NeoPixelStrips.h"

SlaveWireTools* wire;
void setup() {
	//start wire for our TWI/I2C work.
	wire = SlaveWireTools::getInstance();

	//start serial for our computer connection
	Serial.begin(9600);

	#ifdef DEBUG
		Serial.println("Initializing...");
	#endif
}



void loop() {
	
}

int main(void)
{
	
	init();

#if defined(USBCON)
	USBDevice.attach();
#endif
	
	setup();
    
	for (;;) {
		loop();
		if (serialEventRun) serialEventRun();
	}
        
	return 0;
}


#include "SlaveWireTools.h"

//initialize (at runtime) the instance to be null
SlaveWireTools* SlaveWireTools::instance = NULL;

// the first time this is run, it will start TWI,
// else it returns the instance (singleton pattern)
SlaveWireTools* SlaveWireTools::getInstance() {
	if (!instance) {
		instance = new SlaveWireTools;
	}
	return instance;
}

/*
Write the information into the buffer and parse
*/
void SlaveWireTools::receiveEvent(int howMany) {
	SlaveWireTools* instance = getInstance();

	//clear out the message buffer
	for (int i=0; i < 128; i++) {
		instance->message[i] = 0;
	}

	//read message into buffer
	int i=0;
	while(Wire.available() > 0) {
		char c = Wire.read();
		instance->message[i] = c;
		i++;
	}

	//parse the message and do something!! :)
	instance->parseMessage();
}

/*
Parse message content and decide what to do
*/
void SlaveWireTools::parseMessage() {
	#ifdef DEBUG
		Serial.println(this->message);
	#endif

	
	char* module = strtok(message, ":");

	#ifdef DEBUG
		Serial.println(module);
	#endif

	if (strcmp(module, "NEOPIXELSTRIP") == 0) {
		int num_pixels = atoi(strtok(NULL, ":"));
		#ifdef DEBUG
			Serial.println(num_pixels);
		#endif

		int pin_num = atoi(strtok(NULL, ":"));
		#ifdef DEBUG
			Serial.println(pin_num);
		#endif

		char* command = strtok(NULL, ":");
		#ifdef DEBUG
			Serial.println(command);
		#endif

		

		if(strcmp(command, "INIT") == 0) {
			NeoPixelStrips* strips = NeoPixelStrips::getInstance();
		} 
		else if (strcmp(command, "RAINBOW") == 0) {
		
		}

		
	}
	


}	
#ifndef NEOPIXEL_CONTROLLER_H
#define NEOPIXEL_CONTROLLER_H
#include "NeoPixel.h"
#include "NeoPixelStripOperation.h"

class NeoPixelController { 
private:
	
	NeoPixelStrip* strips;
	NeoPixel* pixels;
	static NeoPixelController* instance;

	NeoPixelController() {
		
		//strip for lamp 1
		strips = new NeoPixelStrip[1];
		pixels = new NeoPixel[12];
		strips[0].init(12, 9);

		for(int i = 0; i< strips[0].getSize(); i++) {
			pixels[i].setPixelNum(i);
      		pixels[i].setStrip(&strips[0]);
		}

	}

	NeoPixelController(NeoPixelController const&) {};

public:

	static NeoPixelController* getInstance();

	void parseCommand(char* command) {
		
		
		int pixel = atoi(strtok(command, ":"));

		Serial.print("pixel: ");
		Serial.println(pixel);

		char* cmd = strtok(NULL, ":");

		Serial.print("cmd: ");
		Serial.println(cmd);

		if (strcmp(cmd, "ON") == 0) {
			// 1:ON:255:255:255

			int r = atoi(strtok(NULL, ":"));
			int g = atoi(strtok(NULL, ":"));
			int b = atoi(strtok(NULL, ":"));

			pixels[pixel].setPixelColor(r,g,b);

			// Serial.print("r: ");
			// Serial.println(r);

			// Serial.print("g: ");
			// Serial.println(g);

			// Serial.print("b: ");
			// Serial.println(b);
		}	

	}

	NeoPixel* getPixel(uint8_t pixel_num) {
		return &pixels[pixel_num % 12];
	}

	void loop() {

		
	}
};

#endif /* NEOPIXEL_CONTROLLER_H */
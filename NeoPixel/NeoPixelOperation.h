#ifndef NEOPIXELOPERATION_H
#define NEOPIXELOPERATION_H
class NeoPixelOperation {
protected:
	NeoPixel* pixel;
	int wait;
	char* status_str;

public:
	NeoPixelOperation(NeoPixel* pixel_in) {
		this->pixel = pixel_in;
	}

	NeoPixelOperation() {
		// pixel = 0;
		status_str = "hello world";
	}

	void setPixel(NeoPixel* pixel_in) {
		this->pixel = pixel_in;
	}

	int getWait() {
		return wait;
	}	

	NeoPixel* getNeoPixel() {
		return this->pixel;
	}

	void setWait(int wait) {
		this->wait = wait;		
	}

	void getStatus() {
		//Serial.println(status_str);
	}

	char* getStatusStr() {
		return status_str;
	}

	virtual void loop() {}
};


#define DIRECTION_DOWN 0
#define DIRECTION_UP 1


class NeoPixelProgressiveLoop : public NeoPixelOperation {
private:
	boolean direction_r;
	boolean direction_g;
	boolean direction_b;
	
	int last_change;


public:
	typedef NeoPixelOperation super;

	NeoPixelProgressiveLoop(NeoPixel* pixel_in, int wait_in):super(pixel_in) {
		pixel = pixel_in;
		direction_r = DIRECTION_UP;
		direction_g = DIRECTION_UP;
		direction_b = DIRECTION_UP;
		wait = 10;
		last_change = 0;
		
	};

	NeoPixelProgressiveLoop():super() {
		direction_r = DIRECTION_UP;
		direction_g = DIRECTION_UP;
		direction_b = DIRECTION_UP;
		wait = 10;
		last_change = 0;
	}

	

	void loop() {
		//Serial.println("here");
		int now = millis();
		int delay = now - last_change;

	// //delay(1000);
		if (delay >= wait) {

			/*
			* R
			*/
			int r = pixel->getR();
			
			//check to see if R is at min or max
			if (r == 255) {
				direction_r = DIRECTION_DOWN;
			} else if (r == 0) {
				direction_r = DIRECTION_UP;
			}

			//if direction_r == DIRECTION_UP
			if (direction_r == DIRECTION_UP) {
				r+=1;
			} else {
				r-=1;
			}



			/*
			* G
			*/
			int g = pixel->getG();
			
			//check to see if G is at min or max
			if (g == 255) {
				direction_g = DIRECTION_DOWN;
			} else if (g == 0) {
				direction_g = DIRECTION_UP;
			}

			//if direction_g == DIRECTION_UP
			if (direction_g == DIRECTION_UP) {
				g+=1;
			} else {
				g-=1;
			}			


			/*
			* B
			*/

			int b = pixel->getB();
			
			//check to see if B is at min or max
			if (b == 255) {
				direction_b = DIRECTION_DOWN;
			} else if (b == 0) {
				direction_b = DIRECTION_UP;
			}

			//if direction_g == DIRECTION_UP
			if (direction_b == DIRECTION_UP) {
				b+=1;
			} else {
				b-=1;
			}
			
			// Serial.print("Pixel #: ");
			// Serial.println(pixel->getPixelNum());
			pixel->setPixelColor(r, g, b);
			last_change = millis();
		}	
	}
};
#endif /* NEOPIXELOPERATION_H */


# Arduino Make file. Refer to https://github.com/sudar/Arduino-Makefile

BOARD_TAG = mega2560

ARDUINO_LIBS = \
	Wire SPI \
	Adafruit_NeoPixel \
	EthernetV2_0 \
	MemoryFree

ARDUINO_DIR = /home/geoff/arduino-1.0.5

ARDMK_DIR = /home/geoff/projects/arduino_makefile

MONITOR_PORT = /dev/ttyACM2

AVR_TOOLS_DIR = /usr/

LOCAL_CPP_SRCS = \
	$(wildcard *.cpp) \
	$(wildcard SlaveWireTools/*.cpp) \
	$(wildcard NeoPixel/*.cpp)



include $(ARDMK_DIR)/Arduino.mk
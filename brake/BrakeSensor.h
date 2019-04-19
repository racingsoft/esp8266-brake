// Brake.h

#ifndef _BRAKE_h
#define _BRAKE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <HX711.h>
#include "Logger.h"

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = D3;
const int LOADCELL_SCK_PIN = D4;

// HX711 manual calibration
const long LOADCELL_MINVALUE = 180000;
const long LOADCELL_MAXVALUE = 3100000;

class BrakeSensorClass
{
 protected:

 public:
	void init();
	void doCalibration();
	bool isCalibrated();
	uint16_t read();

private:
	long minValue;
	long maxValue;
	long currentValue;
	uint16_t currentMappedValue;
	bool calibrationDone;
};

extern BrakeSensorClass BrakeSensor;

#endif


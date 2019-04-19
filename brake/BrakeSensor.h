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
	double currentDoubleValue;
	double previousDoubleValue;
	uint16_t currentValue;
	uint16_t previousValue;
	bool calibrationDone;
};

extern BrakeSensorClass BrakeSensor;

#endif


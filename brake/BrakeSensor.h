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
#include "Average.h"

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = D3;
const int LOADCELL_SCK_PIN = D4;

const int MAX_READS = 50;
const float DELTA_PERCENT = 0.20;

const long MIN_CALIBRATION_DEFAULT_VALUE = 0;
const long MAX_CALIBRATION_DEFAULT_VALUE = 0;

typedef enum { NOT_INITIALIZED, NOT_FOUND, READY } SensorStates;

class BrakeSensorClass
{
 protected:

 public:
	void Init();
	void DoMinCalibration();
	bool IsMinCalibrated();
	bool IsMinCalibratedOk();
	void DoMaxCalibration();
	bool IsMaxCalibrated();
	bool IsMaxCalibratedOk();
	void ResetCalibration();
	long Read();
	long MinValue();
	long MaxValue();

private:
	SensorStates _sensorState;
	long _minValue;
	long _maxValue;
	long _currentValue;
	bool _minCalibrationDone;
	bool _maxCalibrationDone;
	int _maxReads;
	long _MapValue(long value);
};

extern BrakeSensorClass BrakeSensor;

#endif


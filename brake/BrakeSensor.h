// MIT License
//
// Copyright(c) 2019 Rubén Castro
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this softwareand associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright noticeand this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

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

typedef enum { NOT_INITIALIZED, NOT_FOUND, READY } SensorStates;

class BrakeSensor
{
 protected:

 public:
	BrakeSensor(uint8_t cs, uint8_t sck, Logger* logger);
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
	const int _MAX_CALIBRATION_READS = 50;
	const float _DELTA_PERCENT = 0.20;
	const long _MIN_CALIBRATION_DEFAULT_VALUE = 0;
	const long _MAX_CALIBRATION_DEFAULT_VALUE = 0;
	const int _MAX_OUTPUT_READS = 10;

	uint8_t _cs;
	uint8_t _sck;

	HX711* _presionSensor;
	Average<long>* _calibrationBuffer;
	Average<long>* _outputBuffer;
	Logger* _logger;

	SensorStates _sensorState;

	long _minValue;
	long _maxValue;
	long _currentValue;
	bool _minCalibrationDone;
	bool _maxCalibrationDone;
	int _maxReads;
	long _MapValue(long value);
};

#endif


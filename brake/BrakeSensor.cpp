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

// 
// 
//

#include "BrakeSensor.h"

HX711 presionSensor;
Average<long> average(MAX_READS);

void BrakeSensorClass::Init()
{
	_sensorState = NOT_INITIALIZED;
	presionSensor.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);

	if (presionSensor.wait_ready_timeout(1000))
	{
		_sensorState = READY;
		_currentValue = presionSensor.read();
		ResetCalibration();
	}
	else
	{
		_sensorState = NOT_FOUND;
		Logger.error("Brake sensor not found");
	}
}

void BrakeSensorClass::DoMinCalibration()
{
	// Min Calibration
	if (_sensorState == READY )
	{
		if (average.getCount() < MAX_READS)
		{
			// Read sensor average
			_currentValue = presionSensor.read_average(10);

			// Mean & Delta
			long mean = (long)average.mean();
			long delta = (long)((float)mean * DELTA_PERCENT);

			if (mean == 0 || (mean !=0 && abs(_currentValue - mean) < delta ))
			{
				average.push(_currentValue);
			}
		}
		else
		{
			// End Min Calibration
			_minValue = (long)average.mean();
			average.clear();
			_minCalibrationDone = true;
		}
	}
	else
	{
		Logger.error("Sensor not ready");
	}
}

bool BrakeSensorClass::IsMinCalibrated()
{
	return _minCalibrationDone;
}

bool BrakeSensorClass::IsMinCalibratedOk()
{
	return (_sensorState == READY && _minCalibrationDone && _minValue != MIN_CALIBRATION_DEFAULT_VALUE);
}

void BrakeSensorClass::DoMaxCalibration()
{
	// Max Calibration
	if (_sensorState == READY)  
	{
		if (_maxReads < MAX_READS)
		{
			// Read sensor average
			_currentValue = presionSensor.read_average(10);
			long delta = (long)((float)_minValue * DELTA_PERCENT);
			int count = average.getCount();
			
			if (count == 0)
			{
				if (abs(_currentValue - _minValue) > delta)
				{
					average.push(_currentValue);
				}
			}
			else
			{
				long previous = average.get(count - 1);
				if (_currentValue > previous)
				{
					// Store value
					average.push(_currentValue);
				}
				else
				{
					if (abs(_currentValue - _minValue) < delta)
					{
						_maxReads++;
					}
				}
			}
		}
		else
		{
			// End Max Calibration
			_maxValue = average.maximum();
			average.clear();
			_maxReads = 0;
			_maxCalibrationDone = true;
		}
	}
	else
	{
		Logger.error("Sensor not ready");
	}
}

bool BrakeSensorClass::IsMaxCalibrated()
{
	return _maxCalibrationDone;
}

bool BrakeSensorClass::IsMaxCalibratedOk()
{
	return (_sensorState == READY && _maxCalibrationDone && _maxValue != MAX_CALIBRATION_DEFAULT_VALUE);
}

void BrakeSensorClass::ResetCalibration()
{
	_minValue = MIN_CALIBRATION_DEFAULT_VALUE;
	_minCalibrationDone = false;
	_maxValue = MAX_CALIBRATION_DEFAULT_VALUE;
	_maxCalibrationDone = false;
	_maxReads = 0;
}

long BrakeSensorClass::Read()
{
	// Reading uint16_t value
	_currentValue = presionSensor.read();
	return _MapValue(_currentValue);
}

long BrakeSensorClass::MinValue()
{
	return 0;
}

long BrakeSensorClass::MaxValue()
{
	return (_maxValue - _minValue);
}

long BrakeSensorClass::_MapValue(long value)
{
	long mappedValue = value - _minValue;
	long min = 0;
	long max = _maxValue - _minValue;

	if (mappedValue < min)
		return min;

	if (mappedValue > max)
		return max;

	return mappedValue;
}

BrakeSensorClass BrakeSensor;

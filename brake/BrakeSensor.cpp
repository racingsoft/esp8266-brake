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

BrakeSensor::BrakeSensor(uint8_t cs, uint8_t sck, Logger* logger)
{
	_cs = cs;
	_sck = sck;
	_logger = logger;
	_presionSensor = new HX711();
	_average = new Average<long>(_MAX_READS);
}

void BrakeSensor::Init()
{
	_sensorState = NOT_INITIALIZED;
	_presionSensor->begin(_cs, _sck);

	if (_presionSensor->wait_ready_timeout(1000))
	{
		_sensorState = READY;
		_currentValue = _presionSensor->read();
		ResetCalibration();
	}
	else
	{
		_sensorState = NOT_FOUND;
		_logger->error("Brake sensor not found");
	}
}

void BrakeSensor::DoMinCalibration()
{
	// Min Calibration
	if (_sensorState == READY )
	{
		if (_average->getCount() < _MAX_READS)
		{
			// Read sensor average
			_currentValue = _presionSensor->read_average(10);

			// Mean & Delta
			long mean = (long)_average->mean();
			long delta = (long)((float)mean * _DELTA_PERCENT);

			if (mean == 0 || (mean !=0 && abs(_currentValue - mean) < delta ))
			{
				_average->push(_currentValue);
			}
		}
		else
		{
			// End Min Calibration
			_minValue = (long)_average->mean();
			_average->clear();
			_minCalibrationDone = true;
		}
	}
	else
	{
		_logger->error("Sensor not ready");
	}
}

bool BrakeSensor::IsMinCalibrated()
{
	return _minCalibrationDone;
}

bool BrakeSensor::IsMinCalibratedOk()
{
	return (_sensorState == READY && _minCalibrationDone && _minValue != _MIN_CALIBRATION_DEFAULT_VALUE);
}

void BrakeSensor::DoMaxCalibration()
{
	// Max Calibration
	if (_sensorState == READY)  
	{
		if (_maxReads < _MAX_READS)
		{
			// Read sensor average
			_currentValue = _presionSensor->read_average(10);
			long delta = (long)((float)_minValue * _DELTA_PERCENT);
			int count = _average->getCount();
			
			if (count == 0)
			{
				if (abs(_currentValue - _minValue) > delta)
				{
					_average->push(_currentValue);
				}
			}
			else
			{
				long previous = _average->get(count - 1);
				if (_currentValue > previous)
				{
					// Store value
					_average->push(_currentValue);
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
			_maxValue = _average->maximum();
			_average->clear();
			_maxReads = 0;
			_maxCalibrationDone = true;
		}
	}
	else
	{
		_logger->error("Sensor not ready");
	}
}

bool BrakeSensor::IsMaxCalibrated()
{
	return _maxCalibrationDone;
}

bool BrakeSensor::IsMaxCalibratedOk()
{
	return (_sensorState == READY && _maxCalibrationDone && _maxValue != _MAX_CALIBRATION_DEFAULT_VALUE);
}

void BrakeSensor::ResetCalibration()
{
	_minValue = _MIN_CALIBRATION_DEFAULT_VALUE;
	_minCalibrationDone = false;
	_maxValue = _MAX_CALIBRATION_DEFAULT_VALUE;
	_maxCalibrationDone = false;
	_maxReads = 0;
}

long BrakeSensor::Read()
{
	// Reading uint16_t value
	_currentValue = _presionSensor->read();
	return _MapValue(_currentValue);
}

long BrakeSensor::MinValue()
{
	return 0;
}

long BrakeSensor::MaxValue()
{
	return (_maxValue - _minValue);
}

long BrakeSensor::_MapValue(long value)
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

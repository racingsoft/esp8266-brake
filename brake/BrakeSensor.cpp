// 
// 
// 

#include "BrakeSensor.h"

HX711 presionSensor;

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
	// Time
	if (_minCalibrationStartTime == 0)
		_minCalibrationStartTime = millis();

	// Min Calibration
	if (_sensorState == READY)
	{
		_currentValue = presionSensor.read_average(10);
		_minValue = (_minValue == MIN_CALIBRATION_DEFAULT_VALUE) ? _currentValue : (_minValue + _currentValue) / 2;
	}

	// End Min Calibration
	unsigned long currentTime = millis();
	unsigned long elapsedTime = abs(currentTime - _minCalibrationStartTime);
	if (elapsedTime > MIN_CALIBRATION_TIME)
	{
		_minCalibrationStartTime = 0;
		_minCalibrationDone = true;
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
	// Time
	if (_maxCalibrationStartTime == 0)
		_maxCalibrationStartTime = millis();

	// Max Calibration
	if (_sensorState == READY)
	{
		_currentValue = presionSensor.read_average(10);
		_maxValue = (_maxValue == MAX_CALIBRATION_DEFAULT_VALUE) ? _currentValue : (_maxValue + _currentValue) / 2;
	}

	// End Max Calibration
	unsigned long currentTime = millis();
	unsigned long elapsedTime = abs(currentTime - _maxCalibrationStartTime);
	if (elapsedTime > MAX_CALIBRATION_TIME)
	{
		_maxCalibrationStartTime = 0;
		_maxCalibrationDone = true;
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
	_minCalibrationStartTime = 0;
	_maxValue = MAX_CALIBRATION_DEFAULT_VALUE;
	_maxCalibrationDone = false;
	_maxCalibrationStartTime = 0;
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

// 
// 
// 

#include "BrakeSensor.h"

HX711 presionSensor;

void BrakeSensorClass::init()
{
	presionSensor.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
	minValue = 180000;
	maxValue = 3100000;
	calibrationDone = false;	
}

void BrakeSensorClass::doCalibration()
{
	// Check sensor
	if (!presionSensor.wait_ready_timeout(1000))
	{
		Logger.error("Brake sensor not found");
		return;
	}

	// Calibration
	presionSensor.set_scale();
	presionSensor.tare();
	
	long offset = presionSensor.get_offset();
	Logger.info("Calibration value (offset): " + String(offset));
	long scale = presionSensor.get_scale();
	Logger.info("Calibration value (scale): " + String(scale));
	double value = presionSensor.get_units(10);
	Logger.info("Calibration value (units): " + String(value));
	calibrationDone = true;
}

bool BrakeSensorClass::isCalibrated()
{
	return calibrationDone;
}

uint16_t BrakeSensorClass::read()
{
	// Check sensor
	if (!presionSensor.wait_ready_timeout(1000))
	{
		Logger.error("Brake sensor not found");
		return 0;
	}

	// Check calibration
	if (!calibrationDone)
	{
		Logger.error("Brake sensor not calibrated");
		return 0;
	}

	// Reading uint16_t value
	currentValue = presionSensor.read_average(10);
	if (currentValue != previousValue)
	{
		previousValue = currentValue;
		Logger.info("Current value: " + String(currentValue));
	}
	
	// Mapping value to 0 254 range
	currentMappedValue = (uint16_t)map(currentValue, minValue, maxValue, 0, 254);

	if (currentMappedValue < 0)
		currentMappedValue = 0;

	if (currentMappedValue > 254)
		currentMappedValue = 254;

	if (currentMappedValue != previousMappedValue)
	{
		previousMappedValue = currentMappedValue;
		Logger.info("Mapped value: " + String(currentMappedValue));
	}

	return currentValue;
}

BrakeSensorClass BrakeSensor;


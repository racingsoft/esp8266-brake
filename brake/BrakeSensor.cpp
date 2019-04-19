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

	// Reading Double value
	currentDoubleValue = presionSensor.get_value(10);
	if (previousDoubleValue != currentDoubleValue)
	{
		previousDoubleValue = currentDoubleValue;
		Logger.info("Double value: " + String(currentDoubleValue));
	}

	// Reading uint16_t value
	long value = presionSensor.read_average(10);
	
	// Mapping value to 0 254 range
	currentValue = (uint16_t)map(value, minValue, maxValue, 0, 254);

	if (currentValue < 0)
		currentValue = 0;

	if (currentValue > 254)
		currentValue = 254;

	if (currentValue != previousValue)
	{
		previousValue = currentValue;
		Logger.info("Mapped value: " + String(currentValue));
	}

	return currentValue;
}

BrakeSensorClass BrakeSensor;


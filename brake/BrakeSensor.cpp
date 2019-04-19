// 
// 
// 

#include "BrakeSensor.h"

HX711 presionSensor;

void BrakeSensorClass::init()
{
	presionSensor.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
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

	long value = presionSensor.read_average(10);
	Logger.info("Value: " + String(value));

	minValue = LOADCELL_MINVALUE;
	maxValue = LOADCELL_MAXVALUE;
	Logger.info("Min value: " + String(minValue));
	Logger.info("Max value: " + String(maxValue));
	

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
	currentValue = presionSensor.read();
		
	// Mapping value to 0 254 range
	currentMappedValue = (uint16_t)map(currentValue, minValue, maxValue, 0, 254);

	if (currentMappedValue < 0)
		currentMappedValue = 0;

	if (currentMappedValue > 254)
		currentMappedValue = 254;

	return currentMappedValue;
}

BrakeSensorClass BrakeSensor;


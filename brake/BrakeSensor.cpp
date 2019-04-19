// 
// 
// 

#include "BrakeSensor.h"

HX711 presionSensor;

void BrakeSensorClass::init()
{
	presionSensor.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
	currentValue = LOADCELL_MINVALUE;
	calibrationDone = false;	
}

void BrakeSensorClass::doCalibration()
{
	// Calibration
	if (presionSensor.wait_ready_timeout(1000))
	{
		currentValue = presionSensor.read_average(10);
		Logger.info("Value: " + String(currentValue));

		minValue = LOADCELL_MINVALUE;
		maxValue = LOADCELL_MAXVALUE;
		Logger.info("Min value: " + String(minValue));
		Logger.info("Max value: " + String(maxValue));

		calibrationDone = true;
	}
	else
	{
		Logger.error("Brake sensor not found");
	}
}

bool BrakeSensorClass::isCalibrated()
{
	return calibrationDone;
}

uint16_t BrakeSensorClass::read()
{
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


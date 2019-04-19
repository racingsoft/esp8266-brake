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
	// presionSensor.set_scale();
	// presionSensor.tare();
	
	/*long offset = presionSensor.get_offset();
	Logger.info("Calibration value (offset): " + String(offset));
	long scale = presionSensor.get_scale();
	Logger.info("Calibration value (scale): " + String(scale));
	double value = presionSensor.get_units(10);
	Logger.info("Calibration value (units): " + String(value));*/

	long value = presionSensor.read_average(10);

	minValue = value + ((LOADCELL_MAXVALUE - LOADCELL_MINVALUE) / 10);
	maxValue = LOADCELL_MAXVALUE;

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
	currentValue = presionSensor.read_average(3);
		
	// Mapping value to 0 254 range
	currentMappedValue = (uint16_t)map(currentValue, minValue, maxValue, 0, 254);

	if (currentMappedValue < 0)
		currentMappedValue = 0;

	if (currentMappedValue > 254)
		currentMappedValue = 254;

	return currentValue;
}

BrakeSensorClass BrakeSensor;


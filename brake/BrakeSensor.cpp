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
	double value = presionSensor.get_value(10);
	Logger.info("Calibration value: " + String(value));
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
	double v = presionSensor.get_value(10);
	Logger.info("Double value: " + String(v));

	// Reading uint16_t value
	long value = presionSensor.read_average(10);
	
	// Mapping value to 0 254 range
	uint16_t mapValue = (uint16_t)map(value, minValue, maxValue, 0, 254);

	if (mapValue < 0)
		mapValue = 0;

	if (mapValue > 254)
		mapValue = 254;
		
	Logger.info("Mapped value: " + String(mapValue));

	return mapValue;
}

BrakeSensorClass BrakeSensor;


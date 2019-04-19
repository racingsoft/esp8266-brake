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
	if (presionSensor.wait_ready_timeout(1000))
	{
		presionSensor.set_scale();
		presionSensor.tare();
		double value = presionSensor.get_value(10);
		Logger.info("Calibration value: " + String(value));
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
	if (calibrationDone && presionSensor.is_ready())
	{
		double v = presionSensor.get_value(10);
		Logger.info("Double value: " + String(v));

		long value = presionSensor.read_average(10);
		uint16_t mapValue = (uint16_t)map(value, minValue, maxValue, 0, 254);

		if (mapValue < 0)
			mapValue = 0;

		if (mapValue > 254)
			mapValue = 254;
		
		Logger.info("Uint16_t value: " + String(mapValue));

		return mapValue;
	}

	return 0;
}

BrakeSensorClass BrakeSensor;


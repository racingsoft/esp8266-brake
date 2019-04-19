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
	calibrationDone = true;
}

void BrakeSensorClass::doCalibration()
{
	if (presionSensor.is_ready())
	{
		// TODO: pending
		calibrationDone = true;
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
		long value = presionSensor.read();
		uint16_t mapValue = (uint16_t)map(value, minValue, maxValue, 0, 254);

		if (mapValue < 0)
			mapValue = 0;

		if (mapValue > 254)
			mapValue = 254;

		return mapValue;
	}

	return 0;
}

BrakeSensorClass BrakeSensor;


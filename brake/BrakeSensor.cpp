// 
// 
// 

#include "BrakeSensor.h"

void BrakeSensorClass::init()
{
	presionSensor.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
	minValue = 180000;
	maxValue = 3100000;
	previousValue = currentValue = 0;
	calibrationDone = true;
	calibrationTime = 0;
}

void BrakeSensorClass::doCalibration()
{
	if (presionSensor.is_ready())
	{
		currentValue = presionSensor.get_value();
		Serial.printf("Current value: %d\n", currentValue);

		minValue = min(minValue, currentValue);
		Serial.printf("Min value: %d\n", minValue);
		maxValue = max(maxValue, currentValue);
		Serial.printf("Max value: %d\n", maxValue);

		if (minValue != maxValue && currentValue == minValue)
		{
			unsigned long currentTime = millis();
			if (calibrationTime == 0)
			{
				calibrationTime = currentTime;
			}
			else
			{
				if ((currentTime - calibrationTime) > 1000)
				{
					calibrationDone = true;
				}
			}
		}
		else
		{
			calibrationTime = 0;
		}
		previousValue = currentValue;
	}
}

bool BrakeSensorClass::isCalibrated()
{
	return calibrationDone;
}

long BrakeSensorClass::read()
{
	if (calibrationDone && presionSensor.is_ready())
	{
		long value = presionSensor.read();
		long mapValue = map(value, minValue, maxValue, 0, 100);

		if (mapValue < 0)
			mapValue = 0;

		if (mapValue > 100)
			mapValue = 100;

		return mapValue;
	}

	return 0;
}

BrakeSensorClass BrakeSensor;


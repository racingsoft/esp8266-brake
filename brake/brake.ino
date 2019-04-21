/*
 Name:		brake.ino
 Created:	17/04/2019 19:55:58
 Author:	Ruben Castro
*/

#include "Logger.h"
#include "BrakeOutput.h"
#include "BrakeSensor.h"
#include "Graphic.h"
#include "Display.h"

typedef enum { MIN_CALIBRATION, MAX_CALIBRATION, CALIBRATION_ERROR, CALIBRATION_OK, WORKING } states;

states brakeState;

void setup() {
	
	Logger.init();

	Logger.info("INITIALIZING DISPLAY");
	Display.Init();
	Display.ShowWellcome();
	
	Logger.info("INITIALIZING BRAKESENSOR");
	BrakeSensor.Init();

	Logger.info("INITIALIZING BRAKEOUTPUT");
	BrakeOutput.Init();

	Logger.info("MIN CALIBRATION");
	brakeState = MIN_CALIBRATION;
	Display.ForceRefresh();
}

void loop() {
	
	switch (brakeState)
	{
	case MIN_CALIBRATION:
		
		BrakeSensor.DoMinCalibration();
		if (BrakeSensor.IsMinCalibrated())
		{
			if (BrakeSensor.IsMinCalibratedOk())
			{
				Logger.info("MAX CALIBRATION");
				brakeState = MAX_CALIBRATION;
				Display.ForceRefresh();
			}
			else
			{
				Logger.info("CALIBRATION ERROR");
				brakeState = CALIBRATION_ERROR;
				Display.ForceRefresh();
			}
		}
		break;

	case MAX_CALIBRATION:

		BrakeSensor.DoMaxCalibration();
		if (BrakeSensor.IsMaxCalibrated())
		{
			if (BrakeSensor.IsMaxCalibratedOk())
			{
				Logger.info("CALIBRATION OK");
				brakeState = CALIBRATION_OK;
				Display.ForceRefresh();
			}
			else
			{
				Logger.info("CALIBRATION ERROR");
				brakeState = CALIBRATION_ERROR;
				Display.ForceRefresh();
			}
		}
		break;

	case CALIBRATION_ERROR:
		
		delay(3000);
		Logger.info("MIN CALIBRATION");
		brakeState = MIN_CALIBRATION;
		Display.ForceRefresh();
		break;

	case CALIBRATION_OK:

		delay(3000);
		Logger.info("WORKING");
		brakeState = WORKING;
		Display.ForceRefresh();
		break;
	
	case WORKING:

		long brakeSensorValue = BrakeSensor.Read();
		long brakeOutputValue = map(brakeSensorValue, BrakeSensor.MinValue(), BrakeSensor.MaxValue(),0,254);
		BrakeOutput.SetOutput((uint16_t)brakeOutputValue);
		Logger.info("Brake Sensor Value: " + String(brakeSensorValue));
		Logger.info("Brake Output Value: " + String((uint16_t)brakeOutputValue));
		break;
	}

	// Display update
	Display.Refresh();

}

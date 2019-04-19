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

typedef enum { CALIBRATING, WORKING } states;
states brakeState;

void setup() {
	
	Logger.init();

	Logger.info("INITIALIZING DISPLAY");
	Display.init();
	Display.showWellcome();
	
	Logger.info("INITIALIZING BRAKESENSOR");
	BrakeSensor.init();

	Logger.info("INITIALIZING BRAKEOUTPUT");
	BrakeOutput.init();

	brakeState = CALIBRATING;
}

void loop() {
	
	switch (brakeState)
	{
	case CALIBRATING:
		Logger.info("CALIBRATING");
		BrakeSensor.doCalibration();
		if (BrakeSensor.isCalibrated())
		{
			Logger.info("WORKING");
			brakeState = WORKING;
		}
		break;
	
	case WORKING:
		uint16_t brakeValue = BrakeSensor.read();
		BrakeOutput.setOutput(brakeValue);
		break;
	}
}

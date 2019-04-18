/*
 Name:		brake.ino
 Created:	17/04/2019 19:55:58
 Author:	Ruben Castro
*/

#include "BrakeOutput.h"
#include "BrakeSensor.h"
#include "Graphic.h"
#include "Display.h"

typedef enum { INITIALIZING, CALIBRATING, WORKING } states;
states brakeState;

void setup() {
	
	brakeState = INITIALIZING;

	Serial.begin(115200);
	
	Display.init();
	Display.showWellcome();
	
	BrakeSensor.init();
	BrakeOutput.init();

	brakeState = WORKING;
}

void loop() {
	
	switch (brakeState)
	{
	case CALIBRATING:
		Serial.printf("Calibrando... %d\n", millis());
		BrakeSensor.doCalibration();
		break;
	
	case WORKING:
		Serial.printf("Lectura de sensor...\n");
		int brakeValue = BrakeSensor.read();
		Serial.printf("Sensor: %d\n", brakeValue);
		BrakeOutput.setOutput(brakeValue);
		break;
	}

	if (BrakeSensor.isCalibrated())
	{
		brakeState = WORKING;
	}

	delay(100);
}

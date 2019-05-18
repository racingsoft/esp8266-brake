// MIT License
//
// Copyright(c) 2019 Rubén Castro
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this softwareand associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright noticeand this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

/*
 Name:		brake.ino
 Created:	17/04/2019 19:55:58
 Author:	Ruben Castro
*/

#include "Average.h"
#include "logger.h"
#include "BrakeOutput.h"
#include "BrakeSensor.h"
#include "Graphic.h"
#include "display.h"

typedef enum { MIN_CALIBRATION, MAX_CALIBRATION, CALIBRATION_ERROR, CALIBRATION_OK, WORKING } states;

// WIRE CONFIGURATION
const uint8_t BRAKESENSOR_CS_PIN = D3;
const uint8_t BRAKESENSOR_SCK_PIN = D4;
const uint8_t BRAKEOUTPUT_CS_PIN = D8;
const uint8_t DISPLAY_ADDRESS = 0x3c;
const uint8_t DISPLAY_SDA = D2;
const uint8_t DISPLAY_SCL = D1;
const OLEDDISPLAY_GEOMETRY DISPLAY_GEOMETRY = GEOMETRY_128_64;

// Logger
Logger logger(115200);
// Display
Display display(DISPLAY_ADDRESS, DISPLAY_SDA, DISPLAY_SCL, DISPLAY_GEOMETRY);
// Brake sensor
BrakeSensor brakeSensor(BRAKESENSOR_CS_PIN, BRAKESENSOR_SCK_PIN, &logger);
// Brake output
BrakeOutput brakeOutput(BRAKEOUTPUT_CS_PIN);

states brakeState;

void setup() {
	
	logger.init();

	logger.info("INITIALIZING DISPLAY");
	display.Init();
	display.ShowWellcome();
	
	logger.info("INITIALIZING BRAKESENSOR");
	brakeSensor.Init();

	logger.info("INITIALIZING BRAKEOUTPUT");
	brakeOutput.Init();

	logger.info("MIN CALIBRATION");
	brakeState = MIN_CALIBRATION;
	display.ForceRefresh();
}

void loop() {
	
	switch (brakeState)
	{
	case MIN_CALIBRATION:
		
		brakeSensor.DoMinCalibration();
		if (brakeSensor.IsMinCalibrated())
		{
			if (brakeSensor.IsMinCalibratedOk())
			{
				logger.info("MAX CALIBRATION");
				brakeState = MAX_CALIBRATION;
				display.ForceRefresh();
			}
			else
			{
				logger.info("CALIBRATION ERROR");
				brakeState = CALIBRATION_ERROR;
				display.ForceRefresh();
			}
		}
		break;

	case MAX_CALIBRATION:

		brakeSensor.DoMaxCalibration();
		if (brakeSensor.IsMaxCalibrated())
		{
			if (brakeSensor.IsMaxCalibratedOk())
			{
				logger.info("CALIBRATION OK");
				brakeState = CALIBRATION_OK;
				display.ForceRefresh();
			}
			else
			{
				logger.info("CALIBRATION ERROR");
				brakeState = CALIBRATION_ERROR;
				display.ForceRefresh();
			}
		}
		break;

	case CALIBRATION_ERROR:
		
		delay(3000);
		brakeSensor.ResetCalibration();
		logger.info("MIN CALIBRATION");
		brakeState = MIN_CALIBRATION;
		display.ForceRefresh();
		break;

	case CALIBRATION_OK:

		delay(3000);
		logger.info("WORKING");
		brakeState = WORKING;
		display.ForceRefresh();
		break;
	
	case WORKING:

		long brakeSensorValue = brakeSensor.Read();
		long brakeOutputValue = map(brakeSensorValue, 
			brakeSensor.MinValue(), brakeSensor.MaxValue(),
			brakeOutput.MinValue(),brakeOutput.MaxValue());
		brakeOutput.SetOutput((uint16_t)brakeOutputValue);
		logger.info("Brake Sensor Value: " + String(brakeSensorValue));
		logger.info("Brake Output Value: " + String((uint16_t)brakeOutputValue));
		break;
	}

	// display update
	display.Refresh();
}

/*
 Name:		brake.ino
 Created:	17/04/2019 19:55:58
 Author:	Ruben Castro
*/

#include "Graphic.h"
#include "Display.h"
#include <MCP41xxx.h>
#include <HX711.h>

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = D3;
const int LOADCELL_SCK_PIN = D4;
// MCP41xxx wiring
const int SS_MCP41010_PIN = D8;

HX711 scale;
MCP41xxx dac(SS_MCP41010_PIN);

void setup() {
	Serial.begin(57600);
	Display.init();
	Display.showWellcome();
	scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
	dac.begin();
}

void loop() {
	if (scale.is_ready()) {
		long reading = scale.read();
		Serial.print("HX711 reading: ");
		Serial.println(reading);
	}
	else {
		Serial.println("HX711 not found.");
	}

	Serial.println("MCP41010: 0");
	dac.analogWrite(0);
	delay(5000);
	Serial.println("MCP41010: 100");
	dac.analogWrite(100);
	delay(5000);
	Serial.println("MCP41010: 150");
	dac.analogWrite(150);
	delay(5000);
	Serial.println("MCP41010: 200");
	dac.analogWrite(200);
	delay(5000);
	Serial.println("MCP41010: 255");
	dac.analogWrite(255);
	delay(5000);
	Serial.println("MCP41010: 270");
	dac.analogWrite(270);
	delay(5000);
}

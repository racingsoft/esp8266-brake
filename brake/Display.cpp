// 
// 
// 

#include "Display.h"

const uint8_t SDA_PIN = D2;
const uint8_t SCL_PIN = D1;

SH1106Wire display(0x3c, SDA_PIN, SCL_PIN, GEOMETRY_128_64);

void DisplayClass::init()
{
	// Initialising the UI will init the display too.
	display.init();
	display.flipScreenVertically();
	display.setFont(ArialMT_Plain_10);
	display.clear();
}

void DisplayClass::showWellcome()
{
	display.clear();
	display.drawXbm(0, 0, 128, 64, GRAPH_RACINGSOFT);
	display.display();
}

DisplayClass Display;


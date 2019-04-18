// 
// 
// 

#include "Display.h"

SH1106Wire display(0x3c, D2, D1, GEOMETRY_128_64);

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


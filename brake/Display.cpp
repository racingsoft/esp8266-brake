// 
// 
// 

#include "Display.h"

const uint8_t SDA_PIN = D2;
const uint8_t SCL_PIN = D1;

SH1106Wire display(0x3c, SDA_PIN, SCL_PIN, GEOMETRY_128_64);

void DisplayClass::Init()
{
	// Initialising the UI will init the display too.
	display.init();
	display.flipScreenVertically();
	display.setFont(ArialMT_Plain_10);
	display.clear();

	_forceUpdate = false;
	_lastUpdate = millis();
}

void DisplayClass::ShowWellcome()
{
	display.clear();
	display.drawXbm(0, 0, 128, 64, GRAPH_RACINGSOFT);
	display.display();

	_forceUpdate = false;
	_lastUpdate = millis();
}

void DisplayClass::ForceRefresh()
{
	_forceUpdate = true;
}

void DisplayClass::Refresh()
{
	unsigned long currentTime = millis();
	unsigned long elapsedTime = abs(currentTime - _lastUpdate);

	if (_forceUpdate || elapsedTime > REFRESH_TIME)
	{
		// Dibujamos pantalla

		_forceUpdate = false;
		_lastUpdate = millis();
	}
}

DisplayClass Display;


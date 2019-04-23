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


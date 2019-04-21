// Display.h

#ifndef _DISPLAY_h
#define _DISPLAY_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Wire.h>
#include <SH1106Wire.h>
#include <OLEDDisplayUi.h>
#include <OLEDDisplayFonts.h>
#include <OLEDDisplay.h>
#include "Graphic.h"

const unsigned long REFRESH_TIME = 50;

class DisplayClass
{
 protected:
	 bool _forceUpdate;
	 unsigned long _lastUpdate;

 public:
	void Init();
	void ShowWellcome();
	void ForceRefresh();
	void Refresh();
};

extern DisplayClass Display;

#endif


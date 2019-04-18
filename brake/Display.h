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

class DisplayClass
{
 protected:


 public:
	void init();
	void showWellcome();
};

extern DisplayClass Display;

#endif


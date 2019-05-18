// AD5231.h

#ifndef _AD5231_h
#define _AD5231_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <SPI.h>

class AD5231
{
private:
	uint8_t _cs;
 
protected:

public:
	AD5231(uint8_t cs);
	void begin();
	void digitalPotWrite(uint16_t value);
	void digitalPotWrite(uint8_t gate, uint16_t value);
};

#endif


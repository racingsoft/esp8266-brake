// BrakeOutput.h

#ifndef _BRAKEOUTPUT_h
#define _BRAKEOUTPUT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <MCP41xxx.h>

// MCP41xxx wiring
const uint8_t SS_MCP41010_PIN = D8;

class BrakeOutputClass
{
 protected:


 public:
	void init();
	void setOutput(uint16_t value);
	void shutdownOutput();

private:

};

extern BrakeOutputClass BrakeOutput;

#endif


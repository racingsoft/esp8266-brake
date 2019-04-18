// 
// 
// 

#include "BrakeOutput.h"

MCP41xxx outputDac(SS_MCP41010_PIN);

void BrakeOutputClass::init()
{
	outputDac.begin();
	shutdownOutput();
}

void BrakeOutputClass::setOutput(int value)
{
	int valueOk = 0;
	
	if (value < 0)
		valueOk = 0;
	
	if (value > 100)
		valueOk = 100;

	uint16_t mapValue = map(valueOk, 0, 100, 0, 254);
	outputDac.analogWrite(mapValue);
}

void BrakeOutputClass::shutdownOutput()
{
	outputDac.analogWrite(DAC_SHUTDOWN);
}

BrakeOutputClass BrakeOutput;


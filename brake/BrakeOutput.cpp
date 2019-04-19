// 
// 
// 

#include "BrakeOutput.h"

MCP41xxx outputDac(SS_MCP41010_PIN);

void BrakeOutputClass::init()
{
	outputDac.begin();
	setOutput(0);
}

void BrakeOutputClass::setOutput(uint16_t value)
{	
	outputDac.analogWrite(value);
}

void BrakeOutputClass::shutdownOutput()
{
	outputDac.analogWrite(DAC_SHUTDOWN);
}

BrakeOutputClass BrakeOutput;


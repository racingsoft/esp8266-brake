// 
// 
// 

#include "BrakeOutput.h"

MCP41xxx outputDac(SS_MCP41010_PIN);

void BrakeOutputClass::Init()
{
	outputDac.begin();
	SetOutput(0);
}

void BrakeOutputClass::SetOutput(uint16_t value)
{	
	outputDac.analogWrite(value);
	delayMicroseconds(1);	
}

void BrakeOutputClass::ShutdownOutput()
{
	SetOutput(DAC_SHUTDOWN);
}

BrakeOutputClass BrakeOutput;


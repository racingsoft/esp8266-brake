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
	uint16_t output = value;

	if (output < 0)
		output = 0;

	if (output > 254)
		output = 254;

	outputDac.analogWrite(output);
	delayMicroseconds(1);	
}

void BrakeOutputClass::ShutdownOutput()
{
	SetOutput(DAC_SHUTDOWN);
}

BrakeOutputClass BrakeOutput;


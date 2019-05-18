// 
// 
// 

#include "AD5231.h"

AD5231::AD5231(uint8_t cs)
{
	_cs = cs;
}

void AD5231::begin()
{
	// Prepare SPI hardware.
	SPI.begin();

	// Prepare SPI CS line
	digitalWrite(_cs, HIGH);
	pinMode(_cs, OUTPUT);
}

void AD5231::digitalPotWrite(uint16_t value)
{
	digitalPotWrite(0, value);
}

void AD5231::digitalPotWrite(uint8_t gate, uint16_t value)
{
	// Prepare command
	uint8_t command = 0xB0; //0xB0 = 10110000 
	command += gate;

	// Assert SPI bus
	digitalWrite(_cs, LOW);

	// Perform SPI Transfer
	SPI.beginTransaction(SPISettings(10000000, MSBFIRST, SPI_MODE0));

	// Transfer command
	SPI.transfer(command);

	// Transfer value
	SPI.transfer16(value);
	
	// End SPI Transfer
	SPI.endTransaction();
	
	// Deassert SPI bus
	digitalWrite(_cs, HIGH);

	delayMicroseconds(2);
}

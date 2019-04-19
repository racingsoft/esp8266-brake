// 
// 
// 

#include "Logger.h"

void LoggerClass::init()
{
	Serial.begin(115200);
}

void LoggerClass::info(String info)
{
	if (Serial.isTxEnabled())
	{
		Serial.println("[INFO]: " + info);
	}
}

void LoggerClass::warn(String warn)
{
	if (Serial.isTxEnabled())
	{
		Serial.println("[WARN]: " + warn);
	}
}

void LoggerClass::error(String error)
{
	if (Serial.isTxEnabled())
	{
		Serial.println("[ERROR]: " + error);
	}
}

LoggerClass Logger;

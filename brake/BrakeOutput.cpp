// MIT License
//
// Copyright(c) 2019 Rubén Castro
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this softwareand associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright noticeand this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

// 
// 
// 

#include "BrakeOutput.h"

BrakeOutput::BrakeOutput(uint8_t cs)
{
	outputDac = new AD5231(cs);
}

void BrakeOutput::Init()
{
	outputDac->begin();
	SetOutput(0);
}

void BrakeOutput::SetOutput(uint16_t value)
{
	uint16_t output = value;

	if (output < _MIN_VALUE)
		output = _MIN_VALUE;

	if (output > _MAX_VALUE)
		output = _MAX_VALUE;

	outputDac->digitalPotWrite(output);
	delayMicroseconds(1);	
}

void BrakeOutput::ShutdownOutput()
{
	SetOutput(0);
}

long BrakeOutput::MinValue()
{
	return (long)_MIN_VALUE;
}

long BrakeOutput::MaxValue()
{
	return (long)_MAX_VALUE;
}

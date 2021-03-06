// MIT License
//
// Copyright(c) 2019 Rub�n Castro
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

// Graphic.h

#ifndef _GRAPHIC_h
#define _GRAPHIC_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

	// Racingsoft 128x64

	const uint8_t GRAPH_RACINGSOFT[] PROGMEM = {
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0xFC, 0x07, 0xF0,
		0x1F, 0xC0, 0x7F, 0x00, 0xFF, 0x01, 0xFC, 0x07, 0x00, 0x00, 0x80, 0xFF, 0x01, 0xFC, 0x07, 0xF0, 0x1F, 0xC0, 0x7F, 0x00, 0xFF,
		0x01, 0xFC, 0x07, 0x00, 0x00, 0x80, 0xFF, 0x01, 0xFC, 0x07, 0xF0, 0x1F, 0xC0, 0x7F, 0x00, 0xFF, 0x01, 0xFC, 0x07, 0x00, 0x00,
		0x80, 0xFF, 0x01, 0xFC, 0x07, 0xF0, 0x1F, 0xC0, 0x7F, 0x00, 0xFF, 0x01, 0xFC, 0x07, 0x00, 0x00, 0x80, 0xFF, 0x01, 0xFC, 0x07,
		0xF0, 0x1F, 0xC0, 0x7F, 0x00, 0xFF, 0x01, 0xFC, 0x07, 0x00, 0x00, 0x80, 0xFF, 0x01, 0xFC, 0x07, 0xF0, 0x1F, 0xC0, 0x7F, 0x00,
		0xFF, 0x01, 0xFC, 0x07, 0x00, 0x00, 0x80, 0xFF, 0x01, 0xFC, 0x07, 0xF0, 0x1F, 0xC0, 0x7F, 0x00, 0xFF, 0x01, 0xFC, 0x07, 0x00,
		0x00, 0x80, 0xFF, 0x01, 0xFC, 0x07, 0xF0, 0x1F, 0xC0, 0x7F, 0x00, 0xFF, 0x01, 0xFC, 0x07, 0x00, 0x00, 0x80, 0x01, 0xFE, 0x03,
		0xF8, 0x0F, 0xE0, 0x3F, 0x80, 0xFF, 0x00, 0xFE, 0x03, 0x00, 0x00, 0x00, 0x80, 0x01, 0xFE, 0x03, 0xF8, 0x0F, 0xE0, 0x3F, 0x80,
		0xFF, 0x00, 0xFE, 0x03, 0x00, 0x00, 0x00, 0x80, 0x01, 0xFE, 0x03, 0xF8, 0x0F, 0xE0, 0x3F, 0x80, 0xFF, 0x00, 0xFE, 0x03, 0x00,
		0x00, 0x00, 0x80, 0x01, 0xFE, 0x03, 0xF8, 0x0F, 0xE0, 0x3F, 0x80, 0xFF, 0x00, 0xFE, 0x03, 0x00, 0x00, 0x00, 0x80, 0x01, 0xFE,
		0x03, 0xF8, 0x0F, 0xE0, 0x3F, 0x80, 0xFF, 0x00, 0xFE, 0x03, 0x00, 0x00, 0x00, 0x80, 0x01, 0xFE, 0x03, 0xF8, 0x0F, 0xE0, 0x3F,
		0x80, 0xFF, 0x00, 0xFE, 0x03, 0x00, 0x00, 0x00, 0x80, 0x01, 0xFE, 0x03, 0xF8, 0x0F, 0xE0, 0x3F, 0x80, 0xFF, 0x00, 0xFE, 0x03,
		0x00, 0x00, 0x00, 0x80, 0x01, 0xFE, 0x03, 0xF8, 0x0F, 0xE0, 0x3F, 0x80, 0xFF, 0x00, 0xFE, 0x03, 0x00, 0x00, 0x00, 0x80, 0x01,
		0xFE, 0x03, 0xF8, 0x0F, 0xE0, 0x3F, 0x80, 0xFF, 0x00, 0xFE, 0x03, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x01, 0xFC, 0x07, 0xF0, 0x1F,
		0xC0, 0x7F, 0x00, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
		0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x81, 0xFF, 0xC3, 0xFF, 0xF0, 0xDF, 0xF7, 0xF1, 0xF9, 0x1F,
		0x00, 0x00, 0x00, 0xF0, 0x8F, 0x87, 0x81, 0xFF, 0xE7, 0xFF, 0xF9, 0xDF, 0xF7, 0xF1, 0xFC, 0x3F, 0x00, 0x00, 0x00, 0xF0, 0xCF,
		0x87, 0x81, 0xC7, 0xE7, 0xF1, 0x79, 0xC0, 0xF3, 0xF1, 0x3C, 0x3E, 0x00, 0x00, 0x00, 0xF8, 0xC0, 0x83, 0x81, 0xC7, 0xE7, 0xF1,
		0x79, 0xC0, 0xF3, 0xF9, 0x3C, 0x3E, 0xFF, 0xE3, 0x7F, 0xFE, 0xF7, 0x8F, 0xC1, 0xC7, 0xF3, 0xF1, 0x7C, 0xE0, 0xFB, 0xFB, 0x3E,
		0x80, 0xFF, 0xF3, 0x7F, 0xFE, 0xF3, 0x8F, 0xC1, 0xC7, 0xF3, 0xF1, 0x7C, 0xE0, 0xFB, 0xFB, 0x3E, 0x80, 0xC7, 0xF3, 0x79, 0x78,
		0xC0, 0x83, 0xC1, 0xE7, 0xF3, 0xF9, 0x7C, 0xE0, 0xFB, 0x7B, 0x3E, 0x80, 0xC7, 0xF3, 0x78, 0x78, 0xE0, 0x83, 0xC1, 0xE3, 0xF3,
		0xF8, 0x3C, 0xE0, 0x79, 0x7F, 0x1E, 0x80, 0xFF, 0xF1, 0x7C, 0x7C, 0xE0, 0x81, 0xC1, 0xFF, 0xF3, 0xFF, 0x3C, 0xE0, 0x79, 0x7F,
		0xDE, 0x9F, 0xFF, 0xF1, 0x3C, 0x3C, 0xE0, 0x81, 0xE1, 0xFF, 0xF9, 0x7F, 0x3E, 0xF0, 0x7D, 0x7F, 0xDF, 0x0F, 0xE0, 0xF9, 0x3C,
		0x3C, 0xE0, 0x81, 0xE1, 0xFB, 0xF8, 0x78, 0x3E, 0xF0, 0x7D, 0x3E, 0x1F, 0xCF, 0xE3, 0x79, 0x3C, 0x3C, 0xE0, 0x81, 0xE1, 0xFB,
		0xF8, 0x7C, 0x1E, 0xF0, 0x7D, 0x3E, 0x8F, 0xCF, 0xF3, 0x79, 0x3E, 0x3E, 0xF0, 0x80, 0xE1, 0xF1, 0x78, 0x7C, 0xFE, 0xF3, 0x3C,
		0x3E, 0xFF, 0xCF, 0xFF, 0xF8, 0x1F, 0x1E, 0xF0, 0x83, 0xE1, 0xF1, 0x78, 0x7C, 0xFE, 0xFB, 0x3C, 0x3E, 0xFF, 0xC7, 0x7F, 0xF8,
		0x0F, 0x1E, 0xE0, 0x83, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0xFC, 0x07, 0xF0, 0x1F, 0xC0, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
		0xFF, 0x01, 0xFC, 0x07, 0xF0, 0x1F, 0xC0, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x01, 0xFC, 0x07, 0xF0,
		0x1F, 0xC0, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x01, 0xFC, 0x07, 0xF0, 0x1F, 0xC0, 0x7F, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0xFE, 0x03, 0xF8, 0x0F, 0xE0, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x80, 0x01, 0xFE, 0x03, 0xF8, 0x0F, 0xE0, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0xFE, 0x03, 0xF8,
		0x0F, 0xE0, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0xFE, 0x03, 0xF8, 0x0F, 0xE0, 0x3F, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0xFE, 0x03, 0xF8, 0x0F, 0xE0, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x80, 0x01, 0xFE, 0x03, 0xF8, 0x0F, 0xE0, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0xFE, 0x03,
		0xF8, 0x0F, 0xE0, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0xFE, 0x03, 0xF8, 0x0F, 0xE0, 0x3F, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0xFE, 0x03, 0xF8, 0x0F, 0xE0, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x80, 0xFF, 0x01, 0xFC, 0x07, 0xF0, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x01,
		0xFC, 0x07, 0xF0, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x01, 0xFC, 0x07, 0xF0, 0x1F, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x01, 0xFC, 0x07, 0xF0, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x80, 0xFF, 0x01, 0xFC, 0x07, 0xF0, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF,
		0x01, 0xFC, 0x07, 0xF0, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x01, 0xFC, 0x07, 0xF0, 0x1F,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x01, 0xFC, 0x07, 0xF0, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x01, 0xFC, 0x07, 0xF0, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
	};

#endif


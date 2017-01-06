#ifndef _CONSTANTS_h
#define _CONSTANTS_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

// Number of RGB LEDs in strand:
const int nLEDs = 32;

// Chose 2 pins for output; can be any valid output pins:
const int dataPin = 2;
const int clockPin = 3;

// distance between LEDs in cm
const int spacing = 0;

// length of the LED strip in cm
const int stripLength = spacing * nLEDs;

// radius of the wheel in cm
const int radius = 1;
// circumference of the wheel in cm
const int circumference = TWO_PI * radius;

// number of HAL Effect Sensors on the wheel (we assume they are all equally spaced)
const unsigned int nHAL = 1;

#endif
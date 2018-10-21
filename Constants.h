#ifndef _CONSTANTS_h
#define _CONSTANTS_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

/*
 * This can be considered the main configuration file for this program. Set
 * the following values based on how the longboard and Arduino are configured.
 */

/************************************************
 * Options
 ************************************************/

#define DEBUG true

/************************************************
 * Pins
 ************************************************/

// Choose 2 pins for output; can be any valid output pins:
const byte dataPin = 4;
const byte clockPin = 5;

// The pin where the HAL effect sensor's output is connected
const byte interuptPin = 2;

// debug LED pin
const byte debugPin = LED_BUILTIN;

/************************************************
 * Distances
 ************************************************/

// distance between LEDs in cm
const double spacing = 3.125;

// Number of RGB LEDs in strand:
const uint16_t nLEDs = 32;

// length of the LED strip in cm
const double stripLength = nLEDs * spacing;

// diameter of the wheel in cm
const double diameter = 7.0;

// circumference of the wheel in cm
const double circumference = PI * diameter;

/************************************************
 * Timing
 ************************************************/

// number of HAL Effect Sensors on the wheel (we assume they are all equally spaced)
const byte nHAL = 1;

// the number of previous times differences to keep track of and average
// together when calculating the longboard speed.
const byte numSamples = 3;

// if an interupt does not occur after this amount of time (in miliseconds)
// then we assume the board is not moving (and reset the speed)
const unsigned long maxWaitTime = 10000UL;

#endif
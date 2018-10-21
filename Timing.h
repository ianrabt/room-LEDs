#ifndef _TIMING_h
#define _TIMING_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif
class Timer {
	public:
		explicit Timer(byte numHall, byte numSamples, unsigned long maxWaitTime);
		double LED_offset(unsigned int deltaTime);
		double updateSpeed(unsigned int deltaInteruptTime);
	private:
		byte m_numHall;
		unsigned long m_maxWaitTime;
		byte m_numSamples;
		/** previous speeds of the board in cm / milisecond */
		double *m_speed;
};

#endif
#include "Timing.h"

Timer::Timer(byte numHall, byte numSamples, unsigned long maxWaitTime)
	: m_numHall(numHall),
	  m_numSamples(numSamples),
	  m_maxWaitTime(maxWaitTime) 
{
	m_speed = new double[m_numSamples];
}

double Timer::LED_offset(unsigned int deltaTime) {
	return 0.0;
}

double Timer::updateSpeed(unsigned int deltaInteruptTime) {
	return 0.0;
}

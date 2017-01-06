// Animation.h

#ifndef _ANIMATION_h
#define _ANIMATION_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class AnimationClass
{
 protected:


 public:
	void init();
};

extern AnimationClass Animation;

#endif


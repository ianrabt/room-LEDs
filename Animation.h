// Animation.h
#include "LPD8806_wrapper.h"
#include "Constants.h"

#ifndef _ANIMATION_h
#define _ANIMATION_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

/************************************************
* Abstract Animation Class
************************************************/

class AnimationClass {

	public:
		/**
		 * Constructs a new animation that will control the LED strip passed as
		 * an argument. This assumes the strip has already been initialized and set
		 * up.
		 */
		explicit AnimationClass(LPD8806 *strip = nullptr);

		/**
		 * Changes the strip being animated, returns the old strip that was
		 * was previously in use. Note that this does not initialize the new strip or
		 * deactivate the old strip.
		 */
		LPD8806 * setStrip(LPD8806 *strip);

		/**
		  update should be called every loop (in the main ino file). update is
		  responsible for updating the LEDs based on how much time has passed and
		  how much the board has moved since update was last called
		 
		  \param displacement is a double representing how many "LEDs" the board has
		  moved forward.
		 
		  \param delay is the amount of time that has passed since the last call to
		  update in miliseconds
		 */
		virtual void update(double displacement, unsigned int delay) = 0;

		uint16_t indexLED(uint16_t index);

		static bool reverse;

	protected:
		/**
		  A pointer to the LED strip currently being used
		 */
		LPD8806 *m_strip;
};

/************************************************
 * Additional Animations
 ************************************************/

//! Rainbow pattern (updates based on movement)
/**
  This pattern displays a continuous spectrum that updates based on the
  movement of the longboard. Each pixel contains a unique color value, allowing
  this animation to fully demonstrate the color range of the LED strip.
 */
class RainbowRoad : public AnimationClass {
	public:
		/** see AnimationClass */
		explicit RainbowRoad(LPD8806 *strip) : AnimationClass(strip) {}
		
		/** see AnimationClass */
		void update(double displacement, unsigned int delay);
	
	protected:
		/**
		* Input a value 0 to 384 to get a color value.
		* The colours are a transition r - g -b - back to r
		*/
		uint32_t Wheel(uint16_t WheelPos);

	private:
		/** the current position of the wheel */
		int m_position;
};

class TheaterChase : public AnimationClass {
	public:
		/**
		 * Constructs a TheaterChase animation, which consists of Theatre-style
		 * crawling lights of a specified color which update based on time.
		 *
		 * Arguments:
		 *     strip is the strip that will be animated. This assumes the strip
		 *     has already been initialized and set up.
		 *
		 *     color - see LPD8806.Color
		 */
		explicit TheaterChase(LPD8806 *strip, uint32_t color, unsigned int animationDuration = 1000);

		/** see AnimationClass */
		void update(double displacement, unsigned int delay);
	protected:
		/** the color of the animation */
		uint32_t m_color;
	private:
		/**
		  updates the LEDs based on the stage of the animation

		  \param status is the stage of animation, and should be > 0 and < m_numStages
		 */
		void update(uint8_t status);

		/** length of one full animation cycle in miliseconds */
		unsigned int m_animationDuration;

		/** the time from the last time update was called in miliseconds */
		unsigned int m_pastTime;

		/**
		  number of LEDs before the pattern starts to repeat (i.e.
		  n_numStanges - 1 is the number of off LEDs between each on LED)
		 */
		uint8_t m_numStages = 3;
};

#endif
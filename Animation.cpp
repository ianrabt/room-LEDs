#include "Animation.h"

/************************************************
 * AnimationClass
 ************************************************/

AnimationClass::AnimationClass(LPD8806 *strip) : m_strip(strip) { }

LPD8806 * AnimationClass::setStrip(LPD8806 * strip) {
	LPD8806 *oldStrip = m_strip;
	m_strip = strip;
	return oldStrip;
}

uint16_t AnimationClass::indexLED(uint16_t index) {
	if (reverse)
		return m_strip->numPixels() - index - 1;
	else
		return index;
}

bool AnimationClass::reverse = false;




/************************************************
* RainbowRoad
*************************************************/

void RainbowRoad::update(double displacement, unsigned int delay)
{ }

uint32_t RainbowRoad::Wheel(uint16_t WheelPos) {
	byte r, g, b;
	switch (WheelPos / 128) {
		case 0:
			r = 127 - WheelPos % 128;   //Red down
			g = WheelPos % 128;      // Green up
			b = 0;                  //blue off
			break;
		case 1:
			g = 127 - WheelPos % 128;  //green down
			b = WheelPos % 128;      //blue up
			r = 0;                  //red off
			break;
		case 2:
			b = 127 - WheelPos % 128;  //blue down 
			r = WheelPos % 128;      //red up
			g = 0;                  //green off
			break;
	}
	return(m_strip->Color(r, g, b));
}

/************************************************
* TheaterChase
*************************************************/

TheaterChase::TheaterChase(LPD8806 * strip, uint32_t color,
	unsigned int animationDuration)
	: AnimationClass(strip),
	  m_color(color),
	  m_animationDuration(animationDuration),
	  m_pastTime(0)
{ }

void TheaterChase::update(double displacement, unsigned int delay) {
	m_pastTime += delay;
	m_pastTime = m_pastTime % m_animationDuration;

	uint8_t status = (uint8_t)(m_pastTime / (m_animationDuration / m_numStages));
	update(status);
}

void TheaterChase::update(uint8_t status) {
	for (byte i = 0; i < m_strip->numPixels(); i++) {
		if (i % m_numStages == status) {
			m_strip->setPixelColor(indexLED(i), m_color);
		} else {
			m_strip->setPixelColor(indexLED(i), 0);
		}
	}
}

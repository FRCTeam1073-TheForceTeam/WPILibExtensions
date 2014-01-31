#ifndef LED_STRING_H
#define LED_STRING_H
#include "../OI/LEDColor.h"
#include "WPILib.h"
class LEDString {
public:
	LEDString(int one, int two, int three);
	void Set(LEDColor* color);
	void Off();
private:
	// take Digital Input Pointers
	DigitalOutput* one;
	DigitalOutput* two;
	DigitalOutput* three;
};
#endif

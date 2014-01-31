#include "LEDString.h"
LEDString::LEDString(int one, int two, int three) {
	this->one = new DigitalOutput(one);
	this->two = new DigitalOutput(two);
	this->three = new DigitalOutput(three);
}

void LEDString::Set(LEDColor* color) {
	// TODO: keenan code
}

void LEDString::Off(){
	// TODO: keenan code
}

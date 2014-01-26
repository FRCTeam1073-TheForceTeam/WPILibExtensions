#ifndef SMART_TALON_H
#define SMART_TALON_H
#include "WPILib.h"

/* So here's the deal with this:
 * We want **every** class that extends SpeedController to have Inversion,
 * but since we can't modify WPILib source (we want teams to just git clone
 * WPILibExtensions and have it working right out of the box, there's no easy
 * way to do this short of doing complicated things with std::shared_ptr and virtual
 * deconstructors that I do not fully understand. So until then, enjoy the double code.
 */


class SmartTalon : public Talon {
public:
	SmartTalon(int module, int channel);
	bool IsInverted();
	void Invert();
private:
	bool isInverted;
};
#endif

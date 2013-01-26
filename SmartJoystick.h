#ifndef SMART_JOYSTICK_H
#define SMART_JOYSTICK_H
#include "WPILib.h"
class SmartJoystick : public Joystick{
public:
	SmartJoystick(int port, bool invertYAxis);
	SmartJoystick(int port);
	float GetY();
	bool IsYAxisInverted();
private:
	bool invertYAxis;
};
#endif

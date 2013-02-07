#ifndef SMART_JOYSTICK_H
#define SMART_JOYSTICK_H
#define DEAD_ZONE 0.05
#include "WPILib.h"
#include <math.h>
class SmartJoystick : public Joystick{
public:
	SmartJoystick(int port, bool invertYAxis);
	SmartJoystick(int port);
	float GetX();
	float GetY();
	float GetRawX();
	float GetRawY();
	bool IsXAxisInverted();
	bool IsYAxisInverted();
	void ToggleInvertXAxis();
	void ToggleInvertYAxis();
	enum JoystickMode{normal, extreme, cubic};
	void SetJoystickMode(JoystickMode mode);
private:
	bool invertXAxis, invertYAxis;
	enum Axis{xAxis, yAxis};
	JoystickMode mode;
	float Get(Axis axis);
};
#endif

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
	float GetZ();
	float GetRawX();
	float GetRawY();
	float GetRawZ();
	//what a hat is http://marsxplr.com/_upl/aviatorlogitechjse-orig.jpg
	float GetHatX();
	float GetHatY();
	bool IsXAxisInverted();
	bool IsYAxisInverted();
	bool IsZAxisInverted();
	void ToggleInvertXAxis();
	void ToggleInvertYAxis();
	enum JoystickMode{normal, extreme, cubic};
	void SetJoystickMode(JoystickMode mode);
private:
	bool invertXAxis, invertYAxis, invertZAxis;
	enum Axis{xAxis, yAxis, zAxis};
	JoystickMode mode;
	float Get(Axis axis);
};
#endif

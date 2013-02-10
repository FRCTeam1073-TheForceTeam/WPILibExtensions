#ifndef SMART_JOYSTICK_H
#define SMART_JOYSTICK_H
#define DEAD_ZONE 0.05
#define CUBIC_CONSTANT 0.1
#include "WPILib.h"
#include <math.h>
class SmartJoystick : public Joystick{
public:
	enum JoystickMode{normal = 0, extreme = 1, cubic = 2};
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
	void ToggleInvertZAxis();
	void SetJoystickMode(int mode);
	int GetJoystickMode();
private:
	bool invertXAxis, invertYAxis, invertZAxis;
	enum Axis{xAxis, yAxis, zAxis};
	JoystickMode mode;
	float Get(Axis axis);
};
#endif

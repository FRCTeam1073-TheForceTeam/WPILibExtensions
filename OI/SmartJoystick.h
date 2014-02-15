#ifndef SMART_JOYSTICK_H
#define SMART_JOYSTICK_H
#define DEAD_ZONE 0.075
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
	void SetJoystickMode(JoystickMode newMode);
	JoystickMode GetJoystickMode();
	float GetCubicConstnat();
	void SetCubicConstant(float cubicConstant);
private:
	bool invertXAxis, invertYAxis, invertZAxis;
	float cubicConstant;
	enum Axis{xAxis, yAxis, zAxis};
	JoystickMode mode;
	float Get(Axis axis);
	void Initialize(bool invertYAxis);
};
#endif

#include "SmartJoystick.h"
SmartJoystick::SmartJoystick(int port) : Joystick (port){
	Initialize(false);
}
SmartJoystick::SmartJoystick(int port, bool invertYAxis) : Joystick (port){
	Initialize(invertYAxis);
}
void SmartJoystick::Initialize(bool invertYAxis) {
	invertXAxis = false;
	this->invertYAxis = invertYAxis;
	invertZAxis = false;
	cubicConstant = 0.1;	
}
float SmartJoystick::GetX(){return Get(xAxis);}
float SmartJoystick::GetY(){return Get(yAxis);}
float SmartJoystick::GetZ(){return Get(zAxis);} 
float SmartJoystick::GetRawX() {return Joystick::GetX();}
float SmartJoystick::GetRawY() {return Joystick::GetY();}
float SmartJoystick::GetRawZ() {return Joystick::GetZ();}
float SmartJoystick::GetHatX() {return GetRawAxis(5);}
float SmartJoystick::GetHatY() {return GetRawAxis(6) * -1;}	//1 is up
void SmartJoystick::ToggleInvertXAxis(){invertXAxis = !invertXAxis;}
void SmartJoystick::ToggleInvertYAxis(){invertYAxis = !invertYAxis;}
void SmartJoystick::ToggleInvertZAxis(){invertZAxis = !invertZAxis;}
bool SmartJoystick::IsXAxisInverted(){return invertXAxis;}
bool SmartJoystick::IsYAxisInverted(){return invertYAxis;}
bool SmartJoystick::IsZAxisInverted(){return invertZAxis;}
void SmartJoystick::SetJoystickMode(JoystickMode newMode) {mode = newMode;}
SmartJoystick::JoystickMode SmartJoystick::GetJoystickMode() {return mode;}
float SmartJoystick::Get(Axis axis){
	float value = 0.0f;
	switch(axis){
		case xAxis: 
			value = Joystick::GetX(); if(invertXAxis) value *= -1;	break;
		case yAxis: 
			value = Joystick::GetY(); if(invertYAxis) value *= -1;	break;
		case zAxis:
			value = Joystick::GetZ(); if(invertZAxis) value *= -1; break;
		default: return value;
	}
	switch(mode){
		if(fabs(value) < DEAD_ZONE) value = 0.0f;
		case normal: break;
		case extreme:
			if (value > 0) value = 1.0f;
			else if (value < 0) value = -1.0f;
			break;
		case cubic:
			value = (value * cubicConstant) + (1 - cubicConstant) * (value * value * value);
			break;
		default: break;
	}
	return value;
}

float SmartJoystick::GetCubicConstant() { return cubicConstant; }
void SmartJoystick::SetCubicConstant(float cubicConstant) {this->cubicConstant = cubicConstant;}

#include "SmartJoystick.h"
SmartJoystick::SmartJoystick(int port) : Joystick (port){
	invertXAxis = false;
	invertYAxis = false;
	invertZAxis = false;
}
SmartJoystick::SmartJoystick(int port, bool invertYAxis) : Joystick (port){
	invertXAxis = false;
	this->invertYAxis = invertYAxis;
	invertZAxis = false;
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
bool SmartJoystick::IsXAxisInverted(){return invertXAxis;}
bool SmartJoystick::IsYAxisInverted(){return invertYAxis;}
bool SmartJoystick::IsZAxisInverted(){return invertZAxis;}
void SmartJoystick::SetJoystickMode(JoystickMode mode) {this->mode = mode;}
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
			//TODO: write cubic
			break;
		default: break;
	}
	return value;
}

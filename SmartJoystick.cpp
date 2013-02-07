#include "SmartJoystick.h"
SmartJoystick::SmartJoystick(int port) : Joystick (port){
	invertXAxis = false;
	invertYAxis = false;
}
float SmartJoystick::GetX(){return Get(xAxis);}
float SmartJoystick::GetY(){return Get(yAxis);}
float SmartJoystick::GetRawX() {return Joystick::GetX();}
float SmartJoystick::GetRawY() {return Joystick::GetY();}
void SmartJoystick::ToggleInvertXAxis(){invertXAxis = !invertXAxis;}
void SmartJoystick::ToggleInvertYAxis(){invertYAxis = !invertYAxis;}
bool SmartJoystick::IsXAxisInverted(){return invertXAxis;}
bool SmartJoystick::IsYAxisInverted(){return invertYAxis;}
void SmartJoystick::SetJoystickMode(JoystickMode mode) {this->mode = mode;}
float SmartJoystick::Get(Axis axis){
	float value = 0.0f;
	switch(axis){
		case xAxis: 
			value = Joystick::GetX(); if(invertXAxis) value *= -1;	break;
		case yAxis: 
			value = Joystick::GetY(); if(invertYAxis) value *= -1;	break;
		default: return value;
	}
	switch(mode){
		case normal:
			if(fabs(value) < DEAD_ZONE) value = 0.0f;
			break;
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

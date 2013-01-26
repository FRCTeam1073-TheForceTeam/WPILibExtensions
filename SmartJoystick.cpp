#include "SmartJoystick.h"
SmartJoystick::SmartJoystick(int port) : Joystick (port){ invertYAxis = false; }
SmartJoystick::SmartJoystick(int port, bool invertYAxis) : Joystick(port){
	this->invertYAxis = invertYAxis;
}
float SmartJoystick::GetY(){
	float y = Joystick::GetY();
	return invertYAxis ? y * -1 : y;
	//erase later for test
}
bool SmartJoystick::IsYAxisInverted(){
	return invertYAxis;
}

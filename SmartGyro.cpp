#include "SmartGyro.h"
SmartGyro::SmartGyro(UINT32 channel) : Gyro(channel){gyroMode = radiansOverPi;}
void SmartGyro::SetGyroMode(GyroMode gyroMode){this->gyroMode = gyroMode;}
SmartGyro::GyroMode SmartGyro::GetGyroMode(){return gyroMode;}
float SmartGyro::GetAngle(){
	float angle = Gyro::GetAngle();
	float radian = angle * PI;
	switch(gyroMode){
	case radiansOverPi:return angle;
	case radians: return radian;
	case degrees: return RadiansToDegrees(radian);
	default: return angle;
	}
}

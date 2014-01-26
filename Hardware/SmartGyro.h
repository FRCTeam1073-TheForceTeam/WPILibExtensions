#ifndef SMART_GYRO_H
#define SMART_GYRO_H
#include "WPILib.h"
#include "../Common/CommonFunctions.h"
class SmartGyro : public Gyro{
public:
	SmartGyro(UINT32 channel);
	SmartGyro(UINT32 module, UINT32 channel);
	//radians OverPi is the default that Gyro.h returns.
	typedef enum {radiansOverPi, radians, degrees} GyroMode;
	void SetGyroMode(GyroMode gyroMode);
	GyroMode GetGyroMode();
	float GetAngle();
private:
	GyroMode gyroMode;
};
#endif

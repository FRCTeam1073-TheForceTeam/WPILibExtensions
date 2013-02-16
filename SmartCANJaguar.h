#ifndef SMART_CAN_JAGUAR_H
#define SMART_CAN_JAGUAR_H
#include "WPILib.h"
class SmartCANJaguar : public CANJaguar{
public:
	SmartCANJaguar(UINT8 deviceNumber);
	void Invert();
	bool IsInverted();
	void Set(float value);
private:
	bool isInverted;
};
#endif

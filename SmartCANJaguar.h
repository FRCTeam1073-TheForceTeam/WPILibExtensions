#ifndef SMART_CAN_JAGUAR_H
#define SMART_CAN_JAGUAR_H
#include "WPILib.h"
#include "Stallable.h"
#define CAN_TIMEOUT -44087	//The 2CAN will give this error if it does not see a CANJaguar at the specified CAN ID.
class SmartCANJaguar : public CANJaguar, Stallable{
public:
	SmartCANJaguar(UINT8 deviceNumber);
	void Invert();
	bool IsInverted();
	void Set(float value);
	void ConfigureSpeedMode();
	void ConfigureVoltageMode();
	bool ExistsOn2CANBus();
private:
	bool isInverted;
protected:
	float GetVoltageSource();
};
#endif

#ifndef SMART_CAN_JAGUAR_H
#define SMART_CAN_JAGUAR_H
#include "WPILib.h"
#include "Stallable.h"
#define CAN_TIMEOUT -44087	//The 2CAN will give this error if it does not see a CANJaguar at the specified CAN ID.
class SmartCANJaguar : public CANJaguar, public Stallable{
public:
	SmartCANJaguar(UINT8 deviceNumber, int syncGroup = 0);
	SmartCANJaguar(UINT8 deviceNumber, bool isInverted, int syncGroup = 0);
	void Invert();
	bool IsInverted();
	void Set(float value);
	void ConfigureSpeedMode();
	void ConfigureVoltageMode();
	bool ExistsOnBus();
	int GetSyncGroup();
	void SetSyncGroup(int syncGroup);
private:
	bool isInverted;
	int syncGroup;
	void Initialize(int syncGroup, bool isInverted);
protected:
	float GetVoltageSource();
};
#endif

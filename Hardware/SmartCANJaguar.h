#ifndef SMART_CAN_JAGUAR_H
#define SMART_CAN_JAGUAR_H
#include "WPILib.h"
#include "Stallable.h"
#include "Invertable.h"
#include "../Common/CommonFunctions.h"
#define CAN_TIMEOUT -44087 //The 2CAN will give this error if it does not see a CANJaguar at the specified CAN ID.
class SmartCANJaguar : public CANJaguar, public Stallable, public Invertable{
public:
	SmartCANJaguar(UINT8 deviceNumber, bool isInverted = false);
	typedef enum {
		kGroupNone = 0x00000000,
		kGroup1 = 0x00000001,
		kGroup2 = 0x00000010,
		kGroup3 = 0x00000100,
		kGroup4 = 0x00001000,
		kGroup5 = 0x00010000,
		kGroup6 = 0x00100000,
		kGroup7 = 0x01000000,
		kGroup8 = 0x10000000
	} SyncMask;
	void Set(float value, SyncMask bitMask );
	void Set(float value, uint8_t bitMask = 0);
	void ConfigureSpeedMode();
	void ConfigureVoltageMode();
	bool ExistsOnBus();
	static uint8_t CombineSyncGroups(uint8_t bitmasks[]);
	static uint8_t CombineSyncGroups(SyncMask bitmasks[]);
private:
protected:
	float GetVoltageSource();
};
#endif

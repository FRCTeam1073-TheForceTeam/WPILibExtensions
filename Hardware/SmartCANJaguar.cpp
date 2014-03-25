#include "SmartCANJaguar.h"
SmartCANJaguar::SmartCANJaguar(UINT8 deviceNumber, bool isInverted, ControlMode controlMode) : CANJaguar(deviceNumber, controlMode),
																								Stallable(), Invertable(isInverted)
{}
void SmartCANJaguar::Set(float value, SyncMask bitMask){
	SmartCANJaguar::Set(value, (uint8_t)bitMask);
}
void SmartCANJaguar::Set(float value, uint8_t bitMask) {
	if (IsInverted()) value *= -1;
	CANJaguar::Set(value, bitMask);
}
float SmartCANJaguar::GetVoltageSource(){return GetOutputVoltage();}
void SmartCANJaguar::ConfigureSpeedMode(){
	DisableControl();
	ChangeControlMode(kSpeed);
	SetSpeedReference(kSpeedRef_Encoder);
	ConfigEncoderCodesPerRev(360);
	EnableControl();
}
void SmartCANJaguar::ConfigureVoltageMode(){
	DisableControl();
	ChangeControlMode(kVoltage);
	EnableControl();
}
bool SmartCANJaguar::ExistsOnBus(){
	if(GetError().GetCode() == CAN_TIMEOUT)
	{
		ClearError();
		return false;
	}
	return true;
}

uint8_t SmartCANJaguar::CombineSyncGroups(SyncMask bitmasks[]) {
	int len = ARRAY_LEN(bitmasks);
	uint8_t raw[len];
	for (int i = 0; i < len; i++) {
		raw[i] = (uint8_t)bitmasks[i];
	}
	return CombineSyncGroups(raw);
}

uint8_t SmartCANJaguar::CombineSyncGroups(uint8_t bitmasks[]) {
	int len = ARRAY_LEN(bitmasks);
	if (len == 0) return (uint8_t) kGroupNone;
	else if( len == 1) return bitmasks[0];
	else {
		uint8_t val = bitmasks[0];
		for (int i = 1; i < len; i++) {
			val |= bitmasks[i];
		}
		return val;
	}
}

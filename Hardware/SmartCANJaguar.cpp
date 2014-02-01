#include "SmartCANJaguar.h"
SmartCANJaguar::SmartCANJaguar(UINT8 deviceNumber, bool isInverted) : CANJaguar(deviceNumber), Stallable(){
	this->isInverted = isInverted;
}
void SmartCANJaguar::Invert() {isInverted = !isInverted;}
bool SmartCANJaguar::IsInverted(){return isInverted;}
void SmartCANJaguar::Set(float value, SyncMask bitMask){
	SmartCANJaguar::Set(value, (uint8_t)bitMask);
}
void SmartCANJaguar::Set(float value, uint8_t bitMask) {
	if (isInverted) value *= -1;
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
	uint8_t val;
	for (int i = 0; i < (len - 1); i++) {
		val = bitmasks[i] | bitmasks[i + 1];
	}
	return val;
}








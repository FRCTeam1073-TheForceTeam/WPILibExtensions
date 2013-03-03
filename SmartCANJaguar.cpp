#include "SmartCANJaguar.h"
SmartCANJaguar::SmartCANJaguar(UINT8 deviceNumber) : CANJaguar(deviceNumber), Stallable(){isInverted = false;}
void SmartCANJaguar::Invert() {isInverted = !isInverted;}
bool SmartCANJaguar::IsInverted(){return isInverted;}
void SmartCANJaguar::Set(float value){
	if(isInverted)value*=-1;
	CANJaguar::Set(value);
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
bool SmartCANJaguar::ExistsOn2CANBus(){
	if(jag->GetError().GetCode() == CAN_TIMEOUT)
	{
		jag->ClearError();
		return false;
	}
	return true;
}
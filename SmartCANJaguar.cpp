#include "SmartCANJaguar.h"
SmartCANJaguar::SmartCANJaguar(UINT8 deviceNumber) : CANJaguar(deviceNumber), Stallable(){isInverted = false;}
void SmartCANJaguar::Invert() {isInverted = !isInverted;}
bool SmartCANJaguar::IsInverted(){return isInverted;}
void SmartCANJaguar::Set(float value){
	if(isInverted)value*=-1;
	CANJaguar::Set(value);
}
float SmartCANJaguar::GetVoltageSource(){return GetOutputVoltage();}

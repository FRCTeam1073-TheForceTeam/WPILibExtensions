#include"StallableJaguar.h"
StallableJaguar::StallableJaguar(UINT8 deviceNumber) : Stallable(),
		CANJaguar(deviceNumber){}
float StallableJaguar::GetVoltage(){
	return GetOutputVoltage();
}

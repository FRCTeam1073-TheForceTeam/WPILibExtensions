#include "StallableAnalogEncoder.h"
StallableAnalogEncoder::StallableAnalogEncoder(UINT32 channel) 
	: Stallable(),
	AnalogChannel(channel){}
StallableAnalogEncoder::StallableAnalogEncoder(UINT32 moduleNumber, UINT32 channel) : Stallable(),
	AnalogChannel(moduleNumber, channel){}
float StallableAnalogEncoder::GetVoltageSource(){
	return AnalogChannel::GetVoltage();
}

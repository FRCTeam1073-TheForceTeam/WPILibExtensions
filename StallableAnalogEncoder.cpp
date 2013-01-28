#include "StallableAnalogEncoder.h"
StallableAnalogEncoder::StallableAnalogEncoder(UINT32 moduleNumber, UINT32 channel) : Stallable(),
	AnalogChannel(moduleNumber, channel){}
float StallableAnalogEncoder::GetVoltage(){
	return AnalogChannel::GetVoltage();
}

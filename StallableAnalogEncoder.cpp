#include "StallableAnalogEncoder.h"
StallableAnalogEncoder::StallableAnalogEncoder() : Stallable() {}
float StallableAnalogEncoder::GetVoltage(){
	return GetAnalogEncoder()->GetVoltage();
}

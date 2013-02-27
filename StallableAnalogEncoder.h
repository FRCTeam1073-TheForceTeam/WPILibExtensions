#ifndef STALLABLE_ANALOG_ENCODER
#define STALLABLE_ANALOG_ENCODER
#include "Stallable.h"
#include "WPILib.h"
class StallableAnalogEncoder : public Stallable, AnalogChannel{
public:
	StallableAnalogEncoder(UINT32 channel);
	StallableAnalogEncoder(UINT32 moduleNumber, UINT32 channel);
	float GetVoltage(){return AnalogChannel::GetVoltage();}
protected:
	float GetVoltageSource();
};
#endif

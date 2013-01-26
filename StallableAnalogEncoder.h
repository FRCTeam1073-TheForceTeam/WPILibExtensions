#ifndef STALLABLE_ANALOG_ENCODER
#define STALLABLE_ANALOG_ENCODER
#include "Stallable.h"
#include "WPILib.h"
class StallableAnalogEncoder : public Stallable{
public:
	StallableAnalogEncoder();
protected:
	float GetVoltage();
	virtual AnalogChannel* GetAnalogEncoder() = 0;
};
#endif

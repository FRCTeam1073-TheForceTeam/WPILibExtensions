#ifndef STALLABLE_JAGUAR_H
#define STALLABLE_JAGUAR_H
#include "WPILib.h"
#include "Stallable.h"
class StallableJaguar : public Stallable, CANJaguar{
public:
	StallableJaguar(UINT8 deviceNumber);
protected:
	float GetVoltageSource();
};
#endif

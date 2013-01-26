#ifndef STALLABLE_JAGUAR_H
#define STALLABLE_JAGUAR_H
#include "WPILib.h"
#include "Stallable.h"
class StallableJaguar : public Stallable{
public:
	StallableJaguar();
private:
	float GetVoltage();
protected:
	virtual CANJaguar* GetJaguar() = 0;
};
#endif

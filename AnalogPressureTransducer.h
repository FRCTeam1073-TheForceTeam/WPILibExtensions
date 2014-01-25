#ifndef ANALOG_PRESSURE_TRANSDUCER
#define ANALOG_PRESSURE_TRANSDUCER
#include "WPILib.h"

class AnalogPressureTransducer : public AnalogChannel {
public:
	AnalogPressureTransducer(uint8_t moduleNumber, uint32_t channel);
	float GetPressurePSI();
	bool IsValidVoltage(float voltage);
};

#endif

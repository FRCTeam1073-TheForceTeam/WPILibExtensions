#ifndef CURRENT_SENSOR_H
#define CURRENT_SENSOR_H
#include "WPILib.h"
#define AMPS_CONSTANT (71.43)
class CurrentSensor : public AnalogChannel {
public:
	CurrentSensor(UINT32 channel);
	CurrentSensor(UINT32 moduleNumber, UINT32 channel);
	float GetCurrentAmps();
};
#endif

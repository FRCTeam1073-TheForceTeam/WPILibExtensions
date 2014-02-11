#include "CurrentSensor.h"

CurrentSensor::CurrentSensor(UINT32 channel) : AnalogChannel(channel) {}
CurrentSensor::CurrentSensor(UINT32 moduleNumber, UINT32 channel) : AnalogChannel(moduleNumber, channel) {}
float CurrentSensor::GetCurrentAmps() {
	return (GetVoltage() - 2.5) * AMPS_CONSTANT;
}

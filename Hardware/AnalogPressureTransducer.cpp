#include "AnalogPressureTransducer.h"

#define LOW_VOLT 0.5
#define SLOPE 0.04
#define HIGH_VOLT 4.5
AnalogPressureTransducer::AnalogPressureTransducer(uint8_t moduleNumber, uint32_t channel) :
	AnalogChannel(moduleNumber, channel){
	
}

float AnalogPressureTransducer::GetPressurePSI(){ 
	return (GetVoltage() - LOW_VOLT) / SLOPE; 
}

bool AnalogPressureTransducer::IsValidVoltage(float voltage){
	return LOW_VOLT <= voltage <= HIGH_VOLT; // Voltage should always be from 0.5 volts to 4.5 volts
}

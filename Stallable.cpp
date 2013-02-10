#include "Stallable.h"
#define NONEXISTANT -1
Stallable::Stallable(){	
	ResetData();
}
void Stallable::PrintVoltages(){printf("Prior Voltage:\t%f\nNew Voltage:\t%f\n\n", priorVoltage, currentVoltage);}
bool Stallable::IsStall(){
	if(priorVoltage == NONEXISTANT || currentVoltage == NONEXISTANT) return false;
	return fabs(currentVoltage - priorVoltage) < StallDetectLimit();
}
float Stallable::StallDetectLimit() {return 0.3f;}

void Stallable::ProcessVoltageData(){
	priorVoltage = currentVoltage;
	currentVoltage = GetVoltageSource();
}
void Stallable::ResetData(){
	priorVoltage = NONEXISTANT;
	currentVoltage = NONEXISTANT;
}

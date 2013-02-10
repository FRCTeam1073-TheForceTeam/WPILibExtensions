#include "Stallable.h"
#define NONEXISTANT -1
Stallable::Stallable(){	
	ResetData();
}
void Stallable::PrintVoltages(){printf("Old:\t%f\nNew:\t%f\n\n", old, current);}
bool Stallable::IsStall(){
	if(old == NONEXISTANT || current == NONEXISTANT) return false;
	return fabs(current - old) < StallDetectLimit();
}
float Stallable::StallDetectLimit() {return 0.3f;}
void Stallable::ProcessVoltageData(){
	float voltage = GetVoltageSource();
	if(onOld) old = voltage;
	else current = voltage;
}
void Stallable::ResetData(){
	onOld = true;
	old = NONEXISTANT;
	current = NONEXISTANT;
}

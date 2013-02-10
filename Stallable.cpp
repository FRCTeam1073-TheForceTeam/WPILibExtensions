#include "Stallable.h"
#define NONEXISTANT -1
Stallable::Stallable(){	
	ResetData();
}
void Stallable::PrintVoltages(){
	for (int i = 0; i < VOLT_HISTORY_LEN; i++){
		printf("Voltage History at index %d is %f\n", i, voltageHistArray[i]);
	}
}

bool Stallable::IsStall(){
	float currentMinVoltage = voltageHistArray[0];
	float currentMaxVoltage = currentMinVoltage;

	for (int i = 0; i < VOLT_HISTORY_LEN; i++){
		if (voltageHistArray[i] == NONEXISTANT)
			return (false);
	}
		
	for (int i = 1; i < VOLT_HISTORY_LEN; i++){
		if ((fabs(voltageHistArray[i] - currentMinVoltage) > StallDetectLimit()) ||
			(fabs(voltageHistArray[i] - currentMaxVoltage) > StallDetectLimit()))
			return (false);
		if (voltageHistArray[i] < currentMinVoltage)
			currentMinVoltage = voltageHistArray[i];
		if (voltageHistArray[i] > currentMaxVoltage)
			currentMaxVoltage = voltageHistArray[i];
	}
	return true;
}
float Stallable::StallDetectLimit() {return stallDetectLimitVal;}

void Stallable::ProcessVoltageData(){
	for (int i = 1; i < VOLT_HISTORY_LEN; i++){
		voltageHistArray[VOLT_HISTORY_LEN-i] = voltageHistArray[VOLT_HISTORY_LEN-i-1];
	}
	voltageHistArray[0] = GetVoltageSource();
}
void Stallable::ResetData(){
	int i;
	for (i = 0; i < VOLT_HISTORY_LEN; i++)
		voltageHistArray[i] = NONEXISTANT;
}

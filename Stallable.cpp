#include "Stallable.h"
Stallable::Stallable(){
	voltages = new float[BUFFER];
	hasArrayInit = false;
	index = 0;
}
void Stallable::PrintVoltages(){
	float sum = 0.0f;
	for(int i = 0; i < BUFFER; i++){
		printf("%d:\t%f\n", i, voltages[i]);
		sum += voltages[i];
	}
	printf("Average:\t%f\n", (sum/BUFFER));
}
bool Stallable::IsStall(){
	if(!hasArrayInit) return false;
	float current = voltages[index];
	float previous = voltages[index == BUFFER - 1? 0 : index - 1];	
	return fabs(current - previous) < StallDetectLimit();
}
float Stallable::StallDetectLimit() {return 0.3f;}
void Stallable::FillStallArray(){
	voltages[index] = GetVoltage();	//implemented in subclass
	index++;
	if (index == BUFFER){
		index = 0;
		hasArrayInit = true;
	}
}
void Stallable::ResetArray(){
	for(int i = 0; i < BUFFER; i++){
		voltages[i] = 0.0f;
	}
	index = 0;
	hasArrayInit = false;
}

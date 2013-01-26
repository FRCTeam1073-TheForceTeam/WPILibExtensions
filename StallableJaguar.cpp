#include"StallableJaguar.h"
StallableJaguar::StallableJaguar() : Stallable() {}
float StallableJaguar::GetVoltage(){
	return GetJaguar()->GetOutputVoltage();
}

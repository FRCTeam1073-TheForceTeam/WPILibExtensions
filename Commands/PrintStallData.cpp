#include "PrintStallData.h"
PrintStallData::PrintStallData(Stallable *stallable) 
	: InterruptCallsEndCommand() {
	this->stallable = stallable;
}
void PrintStallData::Initialize() {stallable->PrintVoltages();}
void PrintStallData::Execute() {}
void PrintStallData::End() {}
bool PrintStallData::IsFinished() {return true;}

#include "PrintStallData.h"
PrintStallData::PrintStallData(Stallable *stallable) {this->stallable = stallable;}
void PrintStallData::Initialize() {stallable->PrintVoltages();}
bool PrintStallData::IsFinished() {return true;}

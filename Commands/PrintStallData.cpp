#include "PrintStallData.h"
PrintStallData::PrintStallData(Stallable *stallable) {stallable->PrintVoltages();}
bool PrintStallData::IsFinished() {return true;}

#ifndef PRINT_STALL_DATA_H
#define PRINT_STALL_DATA_H
#include "../Robot.h"
#include "Commands/Subsystem.h"
class PrintStallData : public Command{
public:
	PrintStallData(Stallable* stallable);
	bool IsFinished();
};
#endif

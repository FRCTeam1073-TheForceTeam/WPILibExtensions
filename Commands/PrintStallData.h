#ifndef PRINT_STALL_DATA_H
#define PRINT_STALL_DATA_H
#include "WPILib.h"
#include "Commands/Subsystem.h"
#include "../Hardware/Stallable.h"
#include "InterruptCallsEndCommand.h"
class PrintStallData : public InterruptCallsEndCommand{
public:
	PrintStallData(Stallable* stallable);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
private:
	Stallable* stallable;
};
#endif

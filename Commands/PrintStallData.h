#ifndef PRINT_STALL_DATA_H
#define PRINT_STALL_DATA_H
#include "WPILib.h"
#include "Commands/Subsystem.h"
#include "../Hardware/Stallable.h"
class PrintStallData : public Command{
public:
	PrintStallData(Stallable* stallable);
	void Initialize();
	void Execute(){}
	bool IsFinished();
	void End(){}
	void Interrupted(){}
private:
	Stallable* stallable;
};
#endif

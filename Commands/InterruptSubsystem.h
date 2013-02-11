#ifndef INTERRUPT_SUBSYSTEM_H
#define INTERRUPT_SUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
class InterruptSubsystem : public Command{
public:
	InterruptSubsystem(Subsystem* subsystem);
	bool IsFinished();
};
#endif

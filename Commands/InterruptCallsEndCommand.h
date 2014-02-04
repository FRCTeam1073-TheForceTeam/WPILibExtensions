#ifndef INTERRUPT_CALLS_END_COMMAND_H
#define INTERRUPT_CALLS_END_COMMAND_H
#include "WPIlib.h"
class InterruptCallsEndCommand : public Command {
public:
	InterruptCallsEndCommand();
	virtual void Initalize() = 0;
	virtual void Execute() = 0;
	virtual bool IsFinished() = 0;
	virtual void End() = 0;
	virtual void Interrupted();
};
#endif

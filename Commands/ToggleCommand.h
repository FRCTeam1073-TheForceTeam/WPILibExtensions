#ifndef TOGGLE_COMMAND_H
#define TOGGLE_COMMAND_H
#include "WPILib.h"
#include "Commands/Subsystem.h"
class ToggleCommand : public Command {
public:
	ToggleCommand(Command* onCommand, Command* offCommand);
	ToggleCommand(Command* onCommand, Command* offCommand, bool isOn);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	bool IsOn();
	Command* GetOnCommand();
	Command* GetOffCommand();
protected:
	Command* onCommand;
	Command* offCommand;
private:
	void InitializeMembers(Command* onCommand, Command* offCommand, bool isOn);
	bool isOn;
};
#endif

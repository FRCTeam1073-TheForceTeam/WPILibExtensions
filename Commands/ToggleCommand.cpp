#include "ToggleCommand.h"
ToggleCommand::ToggleCommand(Command* onCommand, Command* offCommand): Command() {
	InitializeMembers(onCommand, offCommand, true);
}

ToggleCommand::ToggleCommand(Command* onCommand, Command* offCommand, bool isOn) : Command() {
	InitializeMembers(onCommand, offCommand, isOn);
}

void ToggleCommand::InitializeMembers(Command* onCommand, Command* offCommand, bool isOn) {
	this->onCommand = onCommand;
	this->offCommand = offCommand;
	this->isOn = isOn;
}

void ToggleCommand::Initialize() {
	(isOn? onCommand : offCommand)->Start();
	isOn = !isOn;
}

void ToggleCommand::Execute() {}

bool ToggleCommand::IsFinished() {return true;}

void ToggleCommand::End() {}
void ToggleCommand::Interrupted() {}

bool ToggleCommand::IsOn() {return isOn;}
Command* ToggleCommand::GetOnCommand() {return onCommand;}
Command* ToggleCommand::GetOffCommand() {return offCommand;}

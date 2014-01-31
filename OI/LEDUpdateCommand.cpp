#include "LEDUpdateCommand.h"

LEDUpdateCommand::LEDUpdateCommand(LEDSubsystemManager* managerSubsystem) : Command() {
	this->managerSubsystem = managerSubsystem;
	Requires(managerSubsystem);
}

void LEDUpdateCommand::Initialize() {}
void LEDUpdateCommand::Execute() { 
	managerSubsystem->InterfaceLEDSubsystems();
}

bool LEDUpdateCommand::IsFinished() {
	return false;
}

void LEDUpdateCommand::End() {}
void LEDUpdateCommand::Interrupted() { End(); }

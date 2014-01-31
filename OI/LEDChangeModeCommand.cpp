#include "LEDChangeModeCommand.h"

LEDChangeModeCommand::LEDChangeModeCommand(LEDSubsystemManager* manager, LEDSubsystemManager::kLightMode mode) 
	: Command () 
{
	this->manager = manager;
	this->mode = mode;
}

void LEDChangeModeCommand::Initialize() {
	manager->SetMode(mode);
}

void LEDChangeModeCommand::Execute() {}
bool LEDChangeModeCommand::IsFinished() { return true; }
void LEDChangeModeCommand::End() {}
void LEDChangeModeCommand::Interrupted() { End(); }

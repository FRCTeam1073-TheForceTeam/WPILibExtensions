#include "ChangeJoystickModeCommand.h"

ChangeJoystickModeCommand::ChangeJoystickModeCommand(SmartJoystick::JoystickMode mode, SmartJoystick* joystick) {
	this->mode = mode;
	joysticks.push_back(joystick);
}

ChangeJoystickModeCommand::ChangeJoystickModeCommand(SmartJoystick::JoystickMode mode, vector<SmartJoystick*> joysticks) {
	this->mode = mode;
	this->joysticks = joysticks;
}

void ChangeJoystickModeCommand::Initialize() {
	int size = (int)joysticks.size();
	for (int i = 0; i < size; i++) {
		joysticks.at(i)->SetJoystickMode(mode);
	}
}

void ChangeJoystickModeCommand::End() {} //no need to clear the joysticks vector because WPILib will take care of that when this Command dies.
void ChangeJoystickModeCommand::Interrupted() {} //should never get called

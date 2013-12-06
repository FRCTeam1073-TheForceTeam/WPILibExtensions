#include "ChangeJoystickModeCommand.h"

vector<SmartJoystick*>* ChangeJoystickModeCommand::joysticks = new vector<SmartJoystick*>();
ChangeJoystickModeCommand::ChangeJoystickModeCommand(SmartJoystick::JoystickMode mode) {
	this->mode = mode;
}


void ChangeJoystickModeCommand::Initialize() {
	int size = (int)joysticks->size();
	for (int i = 0; i < size; i++) {
		joysticks->at(i)->SetJoystickMode(mode);
	}
}

void ChangeJoystickModeCommand::Execute() {}
bool ChangeJoystickModeCommand::IsFinished() {return true;}

void ChangeJoystickModeCommand::End() {} //no need to clear the joysticks vector because WPILib will take care of that when this Command dies.
void ChangeJoystickModeCommand::Interrupted() {} //should never get called

void ChangeJoystickModeCommand::AddSmartJoystickPointers(int num, ...) {
	va_list list;
	va_start(list, num);
	for (int i = 0; i < num; i++) {
		joysticks->push_back(va_arg(list, SmartJoystick*));
	}
	va_end(list);
}

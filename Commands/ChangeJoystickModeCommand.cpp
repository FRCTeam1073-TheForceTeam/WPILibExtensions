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
	printf("In joystick mode:\t");
	if (mode == SmartJoystick::normal) puts("nomral");
	else if (mode == SmartJoystick::extreme) puts ("extreme");
	else puts ("cubic");
}

void ChangeJoystickModeCommand::Execute() {}
bool ChangeJoystickModeCommand::IsFinished() {return true;}

void ChangeJoystickModeCommand::End() {}
void ChangeJoystickModeCommand::Interrupted() {} //should never get called

void ChangeJoystickModeCommand::AddSmartJoystickPointers(int num, ...) {
	va_list list;
	va_start(list, num);
	for (int i = 0; i < num; i++) {
		joysticks->push_back(va_arg(list, SmartJoystick*));
	}
	va_end(list);
}

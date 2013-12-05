#ifndef CHAGNE_JOYSTICK_BASE_H
#define CHANGE_JOYSTICK_BASE_H
#include "WPILib.h"
#include "../SmartJoystick.h"
#include <vector>
class ChangeJoystickModeCommand : public Command {
public:
	ChangeJoystickModeCommand(SmartJoystick::JoystickMode mode, SmartJoystick* joystick);
	ChangeJoystickModeCommand(SmartJoystick::JoystickMode mode, vector<SmartJoystick*> joysticks);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	vector<SmartJoystick*> joysticks;
	SmartJoystick::JoystickMode mode;
};
#endif

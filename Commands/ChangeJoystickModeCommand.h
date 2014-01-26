#ifndef CHAGNE_JOYSTICK_BASE_H
#define CHANGE_JOYSTICK_BASE_H
#include "WPILib.h"
#include "../OI/SmartJoystick.h"
#include <vector>
#include <cstdarg>
class ChangeJoystickModeCommand : public Command {
public:
	ChangeJoystickModeCommand(SmartJoystick::JoystickMode mode);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	static void AddSmartJoystickPointers(int num, ...);
private:

	static vector<SmartJoystick*>* joysticks;
	SmartJoystick::JoystickMode mode;
};
#endif

#ifndef SAITEK_X52_THROTTLE_H
#define SAITEK_X52_THROTTLE_H
#include "SmartJoystick.h"
class SaitekX52Throttle : public SmartJoystick {
public:
	SaitekX52Throttle(int port);
	float GetSaitekThrottleControl();
	static int GetEButtonNumber();
	static int GetIButtonNumber();
	static int GetFunctionButtonNumber();
	static int GetStartStopButtonNumber();
	static int GetResetButtonNumber();
	bool GetEButton();
	bool GetIButton();
	bool GetFunctionButton();
	bool GetStartStopButton();
	bool GetResetButton();
};
#endif

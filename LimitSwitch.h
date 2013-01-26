//class to avoid confusion when getting the value from a limit switch.
#ifndef LIMIT_SWITCH_H
#define LIMIT_SWITCH_H
#include "wpilib.h"
class LimitSwitch : public DigitalInput{
public:
	LimitSwitch(int CHANNEL);
	LimitSwitch(int MODULE, int CHANNEL);
	bool IsPressed();
};
#endif

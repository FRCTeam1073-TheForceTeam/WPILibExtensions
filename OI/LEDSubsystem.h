#ifndef LED_SUBSYSTEM_H
#define LED_SUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "../OI/LEDColor.h"
#include "../Hardware/LEDString.h"
class LEDSubsystem : public Subsystem {
public:
	LEDSubsystem(const char* name);
	virtual LEDColor* GetColor() = 0;
	virtual LEDString* GetLEDString() = 0;
};
#endif

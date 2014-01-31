#ifndef LED_SUBSYSTEM_H
#define LED_SUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "LEDColor.h"
#include "LEDString.h"
class LEDSubsystem : public Subsystem {
public:
	LEDSubsystem(const char* name);
	virtual LEDColor* GetLEDColor() = 0;
	virtual LEDString* GetLEDString() = 0;
};
#endif

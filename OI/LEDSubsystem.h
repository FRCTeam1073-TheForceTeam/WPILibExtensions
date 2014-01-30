#ifndef LED_SUBSYSTEM_H
#define LED_SUBSYSTEM_H
#include "Commands/Subsystem.h"
class LEDSubsystem : public Subsystem {
public:
	LEDSubsystem(const char* name);
	LEDColor* GetColor() = 0;
};
#endif

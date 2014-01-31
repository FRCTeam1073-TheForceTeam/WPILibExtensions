#ifndef LED_SUBSYSTEM_MANAGER_H
#define LED_SUBSYSTEM_MANAGER_H
#include "Commands/Subsystem.h"
#include "LEDSubsystem.h"
#include "LEDString.h"
#include <vector>
class LEDSubsystemManager : public Subsystem {
public:
	enum kLightMode{off, solid, blinking};
	LEDSubsystemManager();
	float GetOnTime();
	void SetOnTime(float onTime);
	float GetOffTime();
	void SetOffTime(float offTime);
	void InterfaceLEDSubsystems(); 
	void AddLEDSubsystems(LEDSubsystem* subsystem);
	kLightMode GetMode();
	void SetMode(kLightMode mode);
private:
	
	vector<LEDSubsystem*>* subsystems;
	float onTime;
	float offTime;
	kLightMode mode;
	bool blinkingOn;
};
#endif

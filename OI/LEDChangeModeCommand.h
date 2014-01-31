#ifndef LED_CHANGE_MODE_COMMAND_H
#define LED_CHANGE_MODE_COMMAND_H
#include "Commands/Subsystem.h"
#include "LEDSubsystemManager.h"
class LEDChangeModeCommand : public Command {
public:
	LEDChangeModeCommand(LEDSubsystemManager* manager, LEDSubsystemManager::kLightMode mode);
	virtual void Initialize();
	virtual void Execute(); 
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
private:
	LEDSubsystemManager* manager;
	LEDSubsystemManager::kLightMode mode;
};
#endif

#ifndef LED_UDPATE_COMMAND_H
#define LED_UPDATE_COMMAND_H
#include "WPILib.h"
#include "LEDSubsystemManager.h"
class LEDUpdateCommand : public Command {
public:
	LEDUpdateCommand(LEDSubsystemManager* managerSubsystem);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
private:
	LEDSubsystemManager* managerSubsystem;
};
#endif

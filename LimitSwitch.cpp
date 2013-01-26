#include "LimitSwitch.h"
LimitSwitch::LimitSwitch(int CHANNEL):
	DigitalInput(CHANNEL) {}
LimitSwitch::LimitSwitch(int MODULE, int CHANNEL): 
	DigitalInput(MODULE, CHANNEL){}
bool LimitSwitch::IsPressed(){
	return Get() == 1;
}

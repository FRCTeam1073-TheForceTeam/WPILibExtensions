#include "LEDSubsystemManager.h"

LEDSubsystemManager::LEDSubsystemManager() : Subsystem("LED Subsystem Manager") {
	subsystems = new vector<LEDSubsystem*>();
	mode = solid;
	onTime = 1.0;
	offTime = 1.0;
	blinkingOn = true;
}

void LEDSubsystemManager::AddLEDSubsystems(LEDSubsystem* subsystem) {
	subsystems->push_back(subsystem);
}

void LEDSubsystemManager::InterfaceLEDSubsystems() {
	for(int i = 0; i < (int)subsystems->size(); i++) {
		LEDColor* color = subsystems->at(i)->GetLEDColor();
		LEDString* hardware = subsystems->at(i)->GetLEDString();
		switch(mode) {
		case solid:
			hardware->Set(color);
			break;
		case blinking:
			if (blinkingOn) {
				hardware->Set(color);
			}
			else hardware->Off();
			// TODO probably do some stuff with FGPA timestamps and the two float variables - Keenan :)
			blinkingOn = !blinkingOn;
			break;
		case off:
			hardware->Off(); 
			break;
		}
	}
}

// property manipulators
float LEDSubsystemManager::GetOnTime() { return onTime; }
void LEDSubsystemManager::SetOnTime (float onTime) { this->onTime = onTime; }
float LEDSubsystemManager::GetOffTime() { return offTime; }
void LEDSubsystemManager::SetOffTime (float offTime) { this->offTime = offTime; }
LEDSubsystemManager::kLightMode LEDSubsystemManager::GetMode() { return mode; }
void LEDSubsystemManager::SetMode(kLightMode mode) { this->mode = mode; }

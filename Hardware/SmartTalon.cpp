#include "SmartTalon.h"

SmartTalon::SmartTalon(int module, int channel) : Talon(module, channel) {
	isInverted = false;
}

void SmartTalon::Invert() {
	isInverted = !isInverted;
}

bool SmartTalon::IsInverted() {
	return isInverted;
}

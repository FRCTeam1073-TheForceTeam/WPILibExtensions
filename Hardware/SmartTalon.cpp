#include "SmartTalon.h"

SmartTalon::SmartTalon(int module, int channel) : Talon(module, channel), Invertable() {}
void SmartTalon::Set(float value) {
	if (IsInverted()) value *= -1;
	Talon::Set(value);
}
